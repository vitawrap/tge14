//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "sim/decalManager.h"
#include "dgl/dgl.h"
#include "sceneGraph/sceneGraph.h"
#include "sceneGraph/sceneState.h"
#include "ts/tsShapeInstance.h"
#include "core/bitStream.h"
#include "console/consoleTypes.h"
#include "collision/clippedPolyList.h"

bool DecalManager::smDecalsOn = true;

const U32 DecalManager::csmFreePoolBlockSize = 256;
U32       DecalManager::smMaxNumDecals = 256;
U32       DecalManager::smDecalTimeout = 5000;

DecalManager* gDecalManager = NULL;
IMPLEMENT_CONOBJECT(DecalManager);
IMPLEMENT_CO_DATABLOCK_V1(DecalData);

namespace {

int QSORT_CALLBACK cmpDecalInstance(const void* p1, const void* p2)
{
   const DecalInstance** pd1 = (const DecalInstance**)p1;
   const DecalInstance** pd2 = (const DecalInstance**)p2;

   return int(((char *)(*pd1)->decalData) - ((char *)(*pd2)->decalData));
}

} // namespace {}

//--------------------------------------------------------------------------

// This assumes center was set
void DecalInstance::makeUVsZRotated()
{
    ClippedPolyList::Poly* p;
    ClippedPolyList::VertexList& vertList = polyList.mVertexList;
    ClippedPolyList::IndexList& indexList = polyList.mIndexList;
    ClippedPolyList::PolyList& pList = polyList.mPolyList;
    F32 size = decalData->size;
    F32 hsize = size * .5f;
    F32 isize = 1.f / size;

    uv.clear();
    uv.reserve(vertList.size());

    MatrixF rot(true);
    Point3F vecX, vecY;
    for (p = pList.begin(); p != pList.end(); p++) {
        Point3F& norm = p->plane;
        norm.normalizeSafe();
        F32 dots[] = {
            static_cast<F32>(mAbs(mDot(norm, Point3F(1,0,0)))), 
            static_cast<F32>(mAbs(mDot(norm, Point3F(0,1,0)))), 
            static_cast<F32>(mAbs(mDot(norm, Point3F(0,0,1))))
        };

        S32 x, y;
        if (dots[0] > dots[1] && dots[0] > dots[2])
        { x = 1; y = 2; }
        else if (dots[1] > dots[0] && dots[1] > dots[2])
        { x = 0; y = 2; }
        else
        { x = 0; y = 1; }

        // Create a basis to transform the UV point
        mCross(xdir, norm, &vecX);
        mCross(norm, vecX, &vecY);
        rot.setColumn(0, vecX);
        rot.setColumn(1, -vecY);
        rot.setColumn(2, norm);

        S32 vertEnd = p->vertexStart + p->vertexCount;
        for (S32 i = p->vertexStart; i < vertEnd; ++i)
        {
            Point3F pt = center - vertList[indexList[i]].point;
            rot.mulP(pt);
            uv[indexList[i]] = Point2F(pt[x] + size, pt[y] + size) * isize * .5f;
        }
    }
}

void DecalInstance::makeUVs()
{
    ClippedPolyList::Poly* p;
    ClippedPolyList::VertexList& vertList = polyList.mVertexList;
    ClippedPolyList::IndexList& indexList = polyList.mIndexList;
    ClippedPolyList::PolyList& pList = polyList.mPolyList;
    F32 size = decalData->size;
    F32 hsize = size * .5f;
    F32 isize = 1.f / size;

    uv.clear();
    uv.reserve(vertList.size());

    for (p = pList.begin(); p != pList.end(); p++) {
        Point3F& norm = p->plane;
        norm.normalizeSafe();
        F32 dots[] = {
            static_cast<F32>(mAbs(mDot(norm, Point3F(1,0,0)))),
            static_cast<F32>(mAbs(mDot(norm, Point3F(0,1,0)))),
            static_cast<F32>(mAbs(mDot(norm, Point3F(0,0,1))))
        };

        S32 x, y;
        if (dots[0] > dots[1] && dots[0] > dots[2])
        { x = 1; y = 2; }
        else if (dots[1] > dots[0] && dots[1] > dots[2])
        { x = 0; y = 2; }
        else
        { x = 0; y = 1; }

        S32 vertEnd = p->vertexStart + p->vertexCount;
        for (S32 i = p->vertexStart; i < vertEnd; ++i)
        {
            Point3F pt = center - vertList[indexList[i]].point;
            uv[indexList[i]] = Point2F(pt[x] + size, pt[y] + size) * isize * .5f;
        }
    }
}

//--------------------------------------------------------------------------
DecalData::DecalData()
{
   size = 1;
   textureName = "";
}

DecalData::~DecalData()
{
   if(gDecalManager)
      gDecalManager->dataDeleted(this);
}


void DecalData::packData(BitStream* stream)
{
   Parent::packData(stream);

   stream->write(size);
   stream->writeString(textureName);
}

void DecalData::unpackData(BitStream* stream)
{
   Parent::unpackData(stream);

   stream->read(&size);
   textureName = stream->readSTString();
}

bool DecalData::preload(bool server, char errorBuffer[ErrorBufferSize])
{
   if (Parent::preload(server, errorBuffer) == false)
      return false;

   if (size < 0.0) {
      Con::warnf("DecalData::preload: size < 0");
      size = 0;
   }
   if (textureName == NULL || textureName[0] == '\0') {
      Con::errorf("No texture name for decal!");
      return false;
   }

   if (!server) {
      textureHandle = TextureHandle(textureName, MeshTexture);
      if (textureHandle.getGLName() == 0) {
         Con::errorf("Unable to load texture: %s for decal!", textureName);
         return false;
      }
   }

   return true;
}

IMPLEMENT_CONSOLETYPE(DecalData)
IMPLEMENT_SETDATATYPE(DecalData)
IMPLEMENT_GETDATATYPE(DecalData)

void DecalData::initPersistFields()
{
   addField("size", TypeF32, Offset(size, DecalData));
   addField("sizeX", TypeF32, Offset(size, DecalData)); // Alias for compatibility
   addField("textureName", TypeFilename,  Offset(textureName, DecalData));
}

DecalManager::DecalManager()
{
   mTypeMask |= DecalManagerObjectType;

   mObjBox.min.set(-1e7, -1e7, -1e7);
   mObjBox.max.set( 1e7,  1e7,  1e7);
   mWorldBox.min.set(-1e7, -1e7, -1e7);
   mWorldBox.max.set( 1e7,  1e7,  1e7);

   mFreePool = NULL;
   VECTOR_SET_ASSOCIATION(mDecalQueue);
   VECTOR_SET_ASSOCIATION(mFreePoolBlocks);
}


DecalManager::~DecalManager()
{
   mFreePool = NULL;
   for (S32 i = 0; i < mFreePoolBlocks.size(); i++)
   {
      delete [] mFreePoolBlocks[i];
   }
   mDecalQueue.clear();
}


DecalInstance* DecalManager::allocateDecalInstance()
{
   if (mFreePool == NULL)
   {
      // Allocate a new block of decals
      mFreePoolBlocks.push_back(new DecalInstance[csmFreePoolBlockSize]);

      // Init them onto the free pool chain
      DecalInstance* pNewInstances = mFreePoolBlocks.last();
      for (U32 i = 0; i < csmFreePoolBlockSize - 1; i++)
         pNewInstances[i].next = &pNewInstances[i + 1];
      pNewInstances[csmFreePoolBlockSize - 1].next = NULL;
      mFreePool = pNewInstances;
   }
   AssertFatal(mFreePool != NULL, "Error, should always have a free pool available here!");

   DecalInstance* pRet = mFreePool;
   pRet->polyList.mPlaneList.setSize(6);
   mFreePool = pRet->next;
   pRet->next = NULL;
   return pRet;
}


void DecalManager::freeDecalInstance(DecalInstance* trash)
{
   AssertFatal(trash != NULL, "Error, no trash pointer to free!");

   trash->polyList.clear();
   trash->polyList.mPlaneList.clear();  // Size of 6 is still kept
   trash->next = mFreePool;
   mFreePool = trash;
}


void DecalManager::dataDeleted(DecalData *data)
{
   for(S32 i = mDecalQueue.size() - 1; i >= 0; i--)
   {
      DecalInstance *inst = mDecalQueue[i];
      if(inst->decalData == data)
      {
         freeDecalInstance(inst);
         mDecalQueue.erase(U32(i));
      }
   }
}

void DecalManager::consoleInit()
{
   Con::addVariable("$pref::decalsOn",     TypeBool, &smDecalsOn);
   Con::addVariable("$pref::Decal::maxNumDecals", TypeS32, &smMaxNumDecals);
   Con::addVariable("$pref::Decal::decalTimeout", TypeS32, &smDecalTimeout);
}

void DecalManager::addDecal(const Point3F& pos,
                            Point3F normal,
                            DecalData* decalData)
{
   if (smMaxNumDecals == 0)
      return;

   // DMM: Rework this, should be based on time
   if(mDecalQueue.size() >= smMaxNumDecals)
   {
      DecalInstance* holder = mDecalQueue.front();
      mDecalQueue.pop_front();
      freeDecalInstance(holder);
   }

   normal.normalizeSafe();
   Point3F position = pos;
   Point3F ext(decalData->size, decalData->size, decalData->size);

   DecalInstance* newDecal = allocateDecalInstance();
   newDecal->decalData = decalData;
   newDecal->allocTime = Platform::getVirtualMilliseconds();
   Box3F B(position - ext, position + ext, true);
   newDecal->center = position;
   newDecal->xdir = Point3F(1,0,0);

   ClippedPolyList* polyList = &newDecal->polyList;
   polyList->mPlaneList[0].set(position - ext, VectorF(-1, 0, 0));
   polyList->mPlaneList[1].set(position - ext, VectorF(0, -1, 0));
   polyList->mPlaneList[2].set(position - ext, VectorF(0, 0, -1));
   polyList->mPlaneList[3].set(position + ext, VectorF(1, 0, 0));
   polyList->mPlaneList[4].set(position + ext, VectorF(0, 1, 0));
   polyList->mPlaneList[5].set(position + ext, VectorF(0, 0, 1));
   if (gClientContainer.buildPolyList(B, STATIC_COLLISION_MASK, polyList))
   {
       newDecal->makeUVs();
       mDecalQueue.push_back(newDecal);
       mQueueDirty = true;
   }
}

void DecalManager::addDecal(const Point3F& pos,
                            const Point3F& rot,
                            Point3F normal,
                            DecalData* decalData)
{
   if (smMaxNumDecals == 0)
      return;

    addDecal( pos, rot, normal, Point3F( 1, 1, 1 ), decalData );
}

void DecalManager::addDecal(const Point3F& pos,
                            const Point3F& rot, // dir vector, natural cross of normal
                            Point3F normal,
                            const Point3F& scale,
                            DecalData* decalData)
{
   if (smMaxNumDecals == 0)
      return;

   if(mDot(rot, normal) < 0.98)
   {
      // DMM: Rework this, should be based on time
      if(mDecalQueue.size() >= smMaxNumDecals)
      {
         DecalInstance* holder = mDecalQueue.front();
         mDecalQueue.pop_front();
         freeDecalInstance(holder);
      }

      normal.normalize();
      Point3F position = pos;
      Point3F ext(decalData->size, decalData->size, decalData->size);

      ext *= scale;
      DecalInstance* newDecal = allocateDecalInstance();
      newDecal->decalData = decalData;
      newDecal->allocTime = Platform::getVirtualMilliseconds();
      Box3F B(position - ext, position + ext, true);
      newDecal->center = position;
      newDecal->xdir = rot;

      ClippedPolyList* polyList = &newDecal->polyList;
      polyList->clear();
      polyList->mPlaneList.clear();
      polyList->mPlaneList.setSize(6);
      polyList->mPlaneList[0].set(position - ext, VectorF(-1, 0, 0));
      polyList->mPlaneList[1].set(position - ext, VectorF(0, -1, 0));
      polyList->mPlaneList[2].set(position - ext, VectorF(0, 0, -1));
      polyList->mPlaneList[3].set(position + ext, VectorF(1, 0, 0));
      polyList->mPlaneList[4].set(position + ext, VectorF(0, 1, 0));
      polyList->mPlaneList[5].set(position + ext, VectorF(0, 0, 1));
      if (gClientContainer.buildPolyList(B, STATIC_COLLISION_MASK, polyList))
      {
          newDecal->makeUVsZRotated();
          mDecalQueue.push_back(newDecal);
          mQueueDirty = true;
      }
   }
}

bool DecalManager::prepRenderImage(SceneState* state, const U32 stateKey,
                                   const U32 /*startZone*/, const bool /*modifyBaseState*/)
{
   if (!smDecalsOn) return false;

   if (isLastState(state, stateKey))
      return false;
   setLastState(state, stateKey);

   if (mDecalQueue.size() == 0)
      return false;

   // This should be sufficient for most objects that don't manage zones, and
   //  don't need to return a specialized RenderImage...
   SceneRenderImage* image = new SceneRenderImage;
   image->obj = this;
   image->isTranslucent = true;
   image->sortType      = SceneRenderImage::BeginSort;
   state->insertRenderImage(image);

   U32 currMs = Platform::getVirtualMilliseconds();
   for (S32 i = mDecalQueue.size() - 1; i >= 0; i--)
   {
      U32 age = currMs - mDecalQueue[i]->allocTime;
      if (age > smDecalTimeout)
      {
         freeDecalInstance(mDecalQueue[i]);
         mDecalQueue.erase(i);
      }
      else if (age > ((3 * smDecalTimeout) / 4))
      {
         mDecalQueue[i]->fade = 1.0f - (F32(age - ((3 * smDecalTimeout) / 4)) / F32(smDecalTimeout / 4));
      }
      else
      {
         mDecalQueue[i]->fade = 1.0f;
      }
   }

   if (mQueueDirty == true)
   {
      // Sort the decals based on the data pointers...
      dQsort(mDecalQueue.address(),
             mDecalQueue.size(),
             sizeof(DecalInstance*),
             cmpDecalInstance);
      mQueueDirty = false;
   }

   return false;
}

void DecalManager::renderObject(SceneState* state, SceneRenderImage*)
{
   AssertFatal(dglIsInCanonicalState(), "Error, GL not in canonical state on entry");

   RectI viewport;
   glMatrixMode(GL_PROJECTION);
   glPushMatrix();
   dglGetViewport(&viewport);

   state->setupBaseProjection();

   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();

   renderDecal();

   glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

   glMatrixMode(GL_MODELVIEW);
   glPopMatrix();

   glMatrixMode(GL_PROJECTION);
   glPopMatrix();
   glMatrixMode(GL_MODELVIEW);
   dglSetViewport(viewport);

   AssertFatal(dglIsInCanonicalState(), "Error, GL not in canonical state on exit");
}

void DecalManager::renderDecal()
{
   glEnable(GL_TEXTURE_2D);
   glEnable(GL_BLEND);
   glEnable(GL_ALPHA_TEST);
   glDepthMask(GL_FALSE);
   glAlphaFunc(GL_GREATER, 0.1f);
   glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   glEnableClientState(GL_VERTEX_ARRAY);
   glEnableClientState(GL_TEXTURE_COORD_ARRAY);
   glEnable(GL_POLYGON_OFFSET_FILL);
   glPolygonOffset(-1.1f, -1.1f);

   DecalData* pLastData = NULL;
   for (S32 x = 0; x < mDecalQueue.size(); x++)
   {
      DecalInstance* di = mDecalQueue[x];

      if (di->decalData != pLastData)
      {
         glBindTexture(GL_TEXTURE_2D, di->decalData->textureHandle.getGLName());
         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
         pLastData = di->decalData;
      }

      glColor4f(1, 1, 1, di->fade);

      ClippedPolyList::Poly* p;
      ClippedPolyList::VertexList& vertList = di->polyList.mVertexList;
      ClippedPolyList::PolyList& polyList = di->polyList.mPolyList;
      ClippedPolyList::IndexList& indexList = di->polyList.mIndexList;
      glVertexPointer(3, GL_FLOAT, sizeof(ClippedPolyList::Vertex), vertList.address());
      glTexCoordPointer(2, GL_FLOAT, sizeof(Point2F), di->uv.address());
      for (p = polyList.begin(); p < polyList.end(); p++) {
          glDrawElements(GL_POLYGON, p->vertexCount,
              GL_UNSIGNED_INT, &indexList[p->vertexStart]);
      }
   }

   glDisableClientState(GL_TEXTURE_COORD_ARRAY);
   glDisableClientState(GL_VERTEX_ARRAY);
   glDisable(GL_POLYGON_OFFSET_FILL);
   glDepthMask(GL_TRUE);
   glDisable(GL_BLEND);
   glDisable(GL_TEXTURE_2D);
   glDisable(GL_ALPHA_TEST);
}


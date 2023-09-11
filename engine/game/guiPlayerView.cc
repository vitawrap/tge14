//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "gui/core/guiCanvas.h"
#include "game/guiPlayerView.h"
#include "console/consoleTypes.h"

static const F32 MaxOrbitDist = 5.0f;
static const S32 MaxAnimations = 6;

IMPLEMENT_CONOBJECT( GuiPlayerView );

//------------------------------------------------------------------------------
GuiPlayerView::GuiPlayerView() : GuiTSCtrl()
{
   mbUnlit = false;
   mActive = true;
   mMouseState = None;
   mModel = NULL;
   mLastMousePoint.set( 0, 0 );
   lastRenderTime = 0;
   runThread = 0;
   mAnimationSeq = 0;
}


//------------------------------------------------------------------------------
GuiPlayerView::~GuiPlayerView()
{
   if ( mModel )
   {
      delete mModel;
      mModel = NULL;
   }
}

void GuiPlayerView::initPersistFields()
{
    Parent::initPersistFields();

    addGroup("Display");
    addField("unlit", TypeBool, Offset(mbUnlit, GuiPlayerView));
    endGroup("Display");
}

//------------------------------------------------------------------------------
ConsoleMethod( GuiPlayerView, setModel, void, 4, 4, "playerView.setModel( playermodel, skin )" )
{
   object->setPlayerModel( argv[2], argv[3] );
}

ConsoleMethod(GuiPlayerView, setImage, void, 4, 5, "playerView.setImage( playermodel, skin, mountN = 0 )")
{
    object->setImage( argv[2], argv[3], argc == 4? 0 : dAtoi(argv[4]) );
}

ConsoleMethod( GuiPlayerView, setSeq, void, 3, 3, "playerView.setSeq( index )" )
{
   argc;
   object->setPlayerSeq( dAtoi(argv[2]) );
}

//------------------------------------------------------------------------------
bool GuiPlayerView::onWake()
{
   if ( !Parent::onWake() )
      return( false );

   mCameraMatrix.identity();
   mCameraRot.set( 0, 0, 3.9 );
   mCameraPos.set( 0, 1.75, 1.25 );
   mCameraMatrix.setColumn( 3, mCameraPos );
   mOrbitPos.set( 0, 0, 0 );
   mOrbitDist = 3.5f;

   return( true );
}

//------------------------------------------------------------------------------
void GuiPlayerView::onMouseDown( const GuiEvent &event )
{
   if ( !mActive || !mVisible || !mAwake )
      return;

   mMouseState = Rotating;
   mLastMousePoint = event.mousePoint;
   mouseLock();
}


//------------------------------------------------------------------------------
void GuiPlayerView::onMouseUp( const GuiEvent &/*event*/ )
{
   mouseUnlock();
   mMouseState = None;
}


//------------------------------------------------------------------------------
void GuiPlayerView::onMouseDragged( const GuiEvent &event )
{
   if ( mMouseState != Rotating )
      return;

   Point2I delta = event.mousePoint - mLastMousePoint;
   mLastMousePoint = event.mousePoint;

   mCameraRot.x += ( delta.y * 0.01 );
   mCameraRot.z += ( delta.x * 0.01 );
}


//------------------------------------------------------------------------------
void GuiPlayerView::onRightMouseDown( const GuiEvent &event )
{
   mMouseState = Zooming;
   mLastMousePoint = event.mousePoint;
   mouseLock();
}


//------------------------------------------------------------------------------
void GuiPlayerView::onRightMouseUp( const GuiEvent &/*event*/ )
{
   mouseUnlock();
   mMouseState = None;
}


//------------------------------------------------------------------------------
void GuiPlayerView::onRightMouseDragged( const GuiEvent &event )
{
   if ( mMouseState != Zooming )
      return;

   S32 delta = event.mousePoint.y - mLastMousePoint.y;
   mLastMousePoint = event.mousePoint;

   mOrbitDist += ( delta * 0.01 );
}

void GuiPlayerView::setPlayerSeq( S32 index )
{
   if( index > MaxAnimations || index < 0 )
      return;

   mAnimationSeq = index;
}

//------------------------------------------------------------------------------
void GuiPlayerView::clearImages()
{
    for (PreviewImage const& img : mImages)
        if (img.shape)
            delete img.shape;
    mImages.clear();
}

void GuiPlayerView::setPlayerModel(const char* shape, const char* skin)
{
   // Stuff random rotation values in...
   mCameraRot.z = gRandGen.randF(-4.14, -1);

   if ( mModel )
   {
      delete mModel;
      mModel = NULL;
   }

   // Clear images (their shapes and consequently their mounting data)
   clearImages();

   runThread = 0;

   Resource<TSShape> hShape = ResourceManager->load(shape);
   if ( !bool( hShape ) )
      return;

   mModel = new TSShapeInstance( hShape, true );
   AssertFatal( mModel, "ERROR!  Failed to load warrior model!" );

   // Set the skin:
   if ( !mModel->ownMaterialList() )
      mModel->cloneMaterialList();

   StringHandle shSkin = StringHandle(skin);
   mModel->reSkin(shSkin);

   // Initialize camera values:
   mOrbitPos = mModel->getShape()->center;
   mMinOrbitDist = mModel->getShape()->radius;

//   // initialize run thread
//   S32 sequence = hShape->findSequence("dummyRun");
//
//   if( sequence != -1 )
//   {
//      runThread = mModel->addThread();
//      mModel->setPos( runThread, 0 );
//      mModel->setTimeScale( runThread, 1 );
//      mModel->setSequence( runThread, sequence, 0 );
//   }

   // the first time recording
   lastRenderTime = Platform::getVirtualMilliseconds();
}

void GuiPlayerView::setImage( char const* image, const char* skin, S32 shapeNode )
{
    if (!mModel || !mModel->getShape()) // Not sure if this is possible, whatever!
        return;

    char shapeMount[128]{};

    // create an image here, populating a new PreviewImage all at once if it is found.
    Resource<TSShape> imShape;
    if (image && image[0])
        imShape = ResourceManager->load(image);
    // they're trying to take an image away from the model...
    else
    {
        dSprintf(shapeMount, 127, "mount%d", shapeNode);
        S32 actualShapeNode = mModel->getShape()->findNode(shapeMount);
        if (actualShapeNode != -1)
        {
            for (U32 i = 0; i < mImages.size(); ++i)
            {
                PreviewImage& img = mImages[i];
                if (img.shapeNode == actualShapeNode)
                {
                    if (img.shape)
                        delete img.shape;
                    mImages.erase_fast(i);
                    break;
                }
            }
        }
    }

    if (!bool(imShape))
        return;

    mImages.increment();
    PreviewImage& img = mImages.last();

    dSprintf(shapeMount, 127, "mount%d", shapeNode);
    img.shapeNode = mModel->getShape()->findNode(shapeMount);
    img.imageNode = imShape->findNode("mountPoint");

    if (img.shapeNode == -1 || img.imageNode == -1)
    {
        mImages.decrement();
        return;
    }

    img.shape = new TSShapeInstance(imShape, true);
    // Set the skin:
    if ( !img.shape->ownMaterialList() )
       img.shape->cloneMaterialList();

    StringHandle shSkin = StringHandle(skin);
    img.shape->reSkin(shSkin);

    AssertFatal(img.shape, "ERROR!  Failed to load Weapon Model!");
}

void GuiPlayerView::getImageTransform( PreviewImage const& image, MatrixF *mat )
{
   MatrixF weapTrans = image.shape->mNodeTransforms[image.imageNode];
   Point3F weapOffset = -weapTrans.getPosition();
   MatrixF modelTrans = mModel->mNodeTransforms[image.shapeNode];
   modelTrans.mulP( weapOffset );
   modelTrans.setPosition( weapOffset );
   *mat = modelTrans;
}

//------------------------------------------------------------------------------
bool GuiPlayerView::processCameraQuery( CameraQuery* query )
{
   // Make sure the orbit distance is within the acceptable range:
   mOrbitDist = ( mOrbitDist < mMinOrbitDist ) ? mMinOrbitDist : ( ( mOrbitDist > MaxOrbitDist ) ? MaxOrbitDist : mOrbitDist );

   // Adjust the camera so that we are still facing the model:
   Point3F vec;
   MatrixF xRot, zRot;
   xRot.set( EulerF( mCameraRot.x, 0, 0 ) );
   zRot.set( EulerF( 0, 0, mCameraRot.z ) );

   mCameraMatrix.mul( zRot, xRot );
   mCameraMatrix.getColumn( 1, &vec );
   vec *= mOrbitDist;
   mCameraPos = mOrbitPos - vec;

   query->nearPlane = 0.1;
   query->farPlane = 2100.0;
   query->fov = 3.1415 / 3.5;
   mCameraMatrix.setColumn( 3, mCameraPos );
   query->cameraMatrix = mCameraMatrix;

   return( true );
}


//------------------------------------------------------------------------------
void GuiPlayerView::renderWorld( const RectI &updateRect )
{
   if ( !(bool)mModel /* || !(bool)mWeapon */)
      return;

   S32 time = Platform::getVirtualMilliseconds();
   S32 dt = time - lastRenderTime;
   lastRenderTime = time;

   glClear( GL_DEPTH_BUFFER_BIT );
   glMatrixMode( GL_MODELVIEW );

   glEnable( GL_DEPTH_TEST );
   glDepthFunc( GL_LEQUAL );

   if (!mbUnlit)
   {
       glEnable(GL_LIGHTING);
       glEnable(GL_LIGHT0);
       
       F32 diff[]{ 1.f, 1.f, 1.f, 1.f };
       F32 amb[]{ .6f, .6f, .6f, 1.f };
       F32 dir[]{ 0.f, 0.f, 1.f, 0.f };
       glLightfv(GL_LIGHT0, GL_DIFFUSE, diff);
       glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
       glLightfv(GL_LIGHT0, GL_POSITION, dir);
   }

   // animate and render in a run pose
   F32 fdt = dt;
//   mModel->advanceTime( fdt/1000.f, runThread );
   mModel->animate();
   mModel->render();

   // render images, if we have any
   for (PreviewImage const& image : mImages)
   {
      MatrixF mat;
      getImageTransform( image, &mat );
      glPushMatrix();
      dglMultMatrix( &mat );

      image.shape->animate();
      image.shape->render();

      glPopMatrix();
   }

   if (!mbUnlit)
   {
       glDisable(GL_LIGHT0);
       glDisable(GL_LIGHTING);
   }

   glDisable( GL_DEPTH_TEST );
   dglSetClipRect( updateRect );
   dglSetCanonicalState();
}

void GuiPlayerView::onMouseEnter(const GuiEvent & event)
{
   Con::executef(this, 1, "onMouseEnter");
}

void GuiPlayerView::onMouseLeave(const GuiEvent & event)
{
   Con::executef(this, 1, "onMouseLeave");
}

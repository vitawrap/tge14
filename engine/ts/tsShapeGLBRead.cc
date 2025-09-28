//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "ts/tsShape.h"
#include "util/safeDelete.h"

// Only include tiny_gltf here
#define TINYGLTF_IMPLEMENTATION
#define TINYGLTF_NO_STB_IMAGE
#define TINYGLTF_NO_STB_IMAGE_WRITE
#include "tiny_gltf.h"

// tiny_gltf and DTS SDK operate with std, so we have to use it too...
#include <string>

// Steal DTS SDK for our purposes
#include "../lib/dtsSDK/DTSShape.h"

namespace DTS {

    struct GLTFPrimitive : public Primitive {
        GLTFPrimitive(tinygltf::Model* model, tinygltf::Primitive* primitive) : Primitive() {
            int drawMode = primitive->mode == TINYGLTF_MODE_TRIANGLE_STRIP? Strip : Triangles;
            if (primitive->material == -1) type = drawMode | Indexed | NoMaterial;
            else type = drawMode | Indexed | (primitive->material & MaterialMask);
        }
    };

    struct GLTFMaterial : public Material {
        GLTFMaterial(tinygltf::Model* model, tinygltf::Material* material) : Material() {
            bump = detail = reflectance = -1; // Future? (map name ids)
            name = material->name;
            flags = NeverEnvMap;
            const auto& pbr = material->pbrMetallicRoughness;
            if (pbr.metallicFactor > 0.f) {
                flags &= ~NeverEnvMap;
                reflection = pbr.metallicFactor;
            }
        }
    };

    class GLTFMesh : public Mesh {
    public:
        GLTFMesh(tinygltf::Model* model, tinygltf::Mesh* mesh) : Mesh(Mesh::T_Standard) {
            // Mesh Primitives in GLTF are "submeshes" almost exactly like DTS primitives!
            // Each submesh, for example, has a material id, a draw mode, and references to indices.
            for (const auto& prim : mesh->primitives) {
                const auto& accessor = model->accessors[prim.attributes.at("POSITION")];
                const auto& buffview = model->bufferViews[accessor.bufferView];
                const auto& buffer = model->buffers[buffview.buffer];

                const auto* positions = reinterpret_cast<const float*>(&buffer.data[buffview.byteOffset + accessor.byteOffset]);


            }
        }
    };
}

static bool glbOpenImage(
    tinygltf::Image* image, const int image_idx, std::string* err,
    std::string* warn, int req_width, int req_height,
    const unsigned char* bytes, int size, void* user_data)
{

}

//-----------------------------------------------------------------------------
// Preface:
// 
// Given that torque is... what it is, the conversion isn't fancy and will
// obviously not support all of the GLTF spec, you cannot have most features.
// Coordinate systems are largely kept intact thanks to OpenGL being at work
// in Torque as well.
// 
// The goal is also first and foremost to support
// the base featureset of GLTF 2.0 without extensions.
// 
// When possible, some Torque-specific behaviors will apply:
// * Scenes are turned into detail/col/loscol groups
// * Material Metalness will set EnvMap flag and translate to EnvMap factor
//-----------------------------------------------------------------------------
static bool convertGLBtoDTS(Stream& stream, void* some_output_todo) {
    tinygltf::Model model;
    tinygltf::TinyGLTF gltf;
    gltf.SetImageLoader(glbOpenImage, NULL);

    // Read all of glb in memory to feed to tiny_gltf
    U64 glbSize = stream.getStreamSize();
    unsigned char* glbMemory = (unsigned char*) dMalloc(glbSize);
    stream.read(glbSize, glbMemory);

    char assetBase[1024]{};

    // This needs to be a file (physical or zip) stream to work with dependencies
    FileStream* fs = NULL;
    if (fs = dynamic_cast<FileStream*>(&stream)) {
        char const* path = fs->getFilename();
        char const* dir = dStrrchr(path, '/');
        if (dir)
            dSprintf(assetBase, dir - path, "%s", path);
        else {
            Con::errorf("GLTF ERROR: Model must be loaded from disk or archive.");
            goto fail;
        }
    }
    else goto fail;

    std::string error, warning;
    if (gltf.LoadBinaryFromMemory(&model, &error, &warning, glbMemory, glbSize, assetBase))
    {
        // eagerly free up memory from raw glb stream (could be big)
        dFree(glbMemory);
        glbMemory = NULL;

        // send messages in the console if we need to
        if (warning.size())
            Con::warnf("GLTF warning: %s (file \"%s\")", warning.c_str(), fs->getFilename());

        DTS::Shape shape;

    }
    else {
        if (error.size())
            Con::errorf("GLTF ERROR: %s (file \"%s\")", error.c_str(), fs->getFilename());
        goto fail;
    }

fail:
    if (glbMemory)
        dFree(glbMemory);
    return false;
}

ResourceInstance* constructGLBTSShape(Stream& stream)
{
    TSShape* ret = new TSShape;

    if (!ret->read(&stream))
    {
        // Failed, so clean up and set to NULL so we'll return NULL.
        SAFE_DELETE(ret);
    }

    return ret;
}

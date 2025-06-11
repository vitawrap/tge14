//-----------------------------------------------------------------------------
// Torque Game Engine
//
// Copyright (c) 2001 GarageGames.Com
//-----------------------------------------------------------------------------

#include "console/console.h"
#include "console/consoleTypes.h"
#include "dgl/dgl.h"
#include "dgl/gDynamicTexture.h"

#include "gui/controls/guiBitmapCtrl.h"

#define DGL_GENERATE_MIPMAPS 0x8191
#define DGL_TEXTURE_FILTER_CONTROL 0x8500
#define DGL_TEXTURE_LOD_BIAS 0x8501

// One LOD of the complete liquid glass rectangle
static void drawFullLiquidGlassRect(TextureObject* tex, const RectI& rect, S32 bevel, S32 depth, S32 alpha, F32 lodBias) {
    glTexEnvf(DGL_TEXTURE_FILTER_CONTROL, DGL_TEXTURE_LOD_BIAS, lodBias);
    S32 bevel2   = bevel << 1;
    RectI slices[9] = {
        RectI(rect.point.x,                             rect.point.y,       bevel,                  bevel),     // Top left
        RectI(rect.point.x + bevel,                     rect.point.y,       rect.extent.x - bevel2, bevel),     // Top
        RectI((rect.point.x + rect.extent.x) - bevel,   rect.point.y,       bevel,                  bevel),     // Top right
        RectI(rect.point.x,                     rect.point.y + bevel,       bevel,  rect.extent.y - bevel2),    // Left
        RectI(rect.point.x + bevel, rect.point.y + bevel, rect.extent.x - bevel2, rect.extent.y - bevel2),      // CENTER
        RectI((rect.point.x + rect.extent.x) - bevel, rect.point.y + bevel, bevel, rect.extent.y - bevel2),     // Right
        RectI(rect.point.x, (rect.point.y + rect.extent.y) - bevel, bevel, bevel),    // Btm left
        RectI(rect.point.x + bevel, (rect.point.y + rect.extent.y) - bevel, rect.extent.x - bevel2, bevel),    // Btm
        RectI((rect.point.x + rect.extent.x) - bevel, (rect.point.y + rect.extent.y) - bevel, bevel, bevel) // Btm right
    };

#define RECT_INSET_SLICE(n, rx, ry, rw, rh) \
    RectI(depth + ((slices[n].point.x - rect.point.x) + (rx)), depth + ((slices[n].point.y - rect.point.y) + (ry)), \
    slices[n].extent.x + (rw), slices[n].extent.y + (rh))

    S32 Ndepth = -depth;
    RectI refract[9] = {
        RECT_INSET_SLICE(6,     Ndepth,     0,     depth,      depth),
        RECT_INSET_SLICE(7,     0,          0,     0,          depth),
        RECT_INSET_SLICE(8,     0,          0,     depth,      depth),

        RECT_INSET_SLICE(3,     Ndepth,     0,          depth,      0),
        RECT_INSET_SLICE(4,     0,          0,          0,          0),
        RECT_INSET_SLICE(5,     0,          0,          depth,      0),

        RECT_INSET_SLICE(0,     Ndepth,     Ndepth,          depth,      depth),
        RECT_INSET_SLICE(1,     0,          Ndepth,          0,          depth),
        RECT_INSET_SLICE(2,     0,          Ndepth,          depth,      depth),
    };

    ColorI color(255, 255, 255, alpha);
    dglSetBitmapModulation(color);

    for (S32 i = 0; i < 9; ++i)
        dglDrawBitmapStretchSR(tex, slices[i], refract[i], GFlip_Y);
}

// This is a "joke" class, intended as a proof of concept.
// I am aware that it is very terribly coded.
class GuiLiquidGlass : public GuiBitmapCtrl
{
    typedef GuiBitmapCtrl Parent;
    DynamicTexture mFramebufferTexture;

public:
    TextureHandle alphaMask;
    ColorI overlayColor;
    S32 bevel;  // bevel size
    S32 depth;  // glass refraction factor

    GuiLiquidGlass()
        : mFramebufferTexture(RectI(getPosition(), getExtent()))
    {
        overlayColor.set(255, 255, 255, 32);
        bevel = 16;
        depth = 16;
    }
    virtual void resize(const Point2I& newPosition, const Point2I& newExtent)
    {
        Parent::resize(newPosition, newExtent);
        mFramebufferTexture.setMustScale(true);
        mFramebufferTexture.setUpdateRect(RectI(
            newPosition - Point2I(depth, depth),
            newExtent + Point2I(depth << 1, depth << 1)));

        // This is an extremely ugly way to bypass standard texture management.
        U32 name = mFramebufferTexture.getTextureHandle().getGLName();
        if (name != 0) {
            glBindTexture(GL_TEXTURE_2D, name);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, DGL_GENERATE_MIPMAPS, GL_TRUE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        }
    }
    void onPreRender()
    {
        Parent::onPreRender();
        setUpdate();
    }
    void onMouseDown(const GuiEvent&)
    {
        Con::executef(this, 1, "click");
    }
    bool onKeyDown(const GuiEvent&)
    {
        Con::executef(this, 1, "click");
        return true;
    }
    DECLARE_CONOBJECT(GuiLiquidGlass);
    bool onWake()
    {
        if (!Parent::onWake())
            return false;
        return true;
    }
    void onRender(Point2I offset, const RectI& updateRect)
    {
        ColorI oldMod;
        dglGetBitmapModulation(&oldMod);

        // This should fill the mip levels as well
        mFramebufferTexture.update();

        // Draw layers, first mip layer gets drawn at full alpha
        dglSetClipRect(updateRect);

        // Prepare alpha masking with stencil buffer
        if (alphaMask.getGLName() != 0) {
            glClearStencil(0);
            glClear(GL_STENCIL_BUFFER_BIT);
            glStencilMask(~0u);
            glEnable(GL_STENCIL_TEST);
            glStencilFunc(GL_ALWAYS, 1, 0xffffffff);
            glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
            glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);

            glEnable(GL_ALPHA_TEST);
            glAlphaFunc(GL_LEQUAL, 0.5f);

            dglDrawBitmap(alphaMask, updateRect.point);
            dglDrawBitmap(alphaMask, updateRect.point + Point2I(updateRect.extent.x - alphaMask.getWidth(), 0), GFlip_X);
            dglDrawBitmap(alphaMask, updateRect.point + Point2I(0, updateRect.extent.y - alphaMask.getHeight()), GFlip_Y);
            dglDrawBitmap(alphaMask, updateRect.point + Point2I(updateRect.extent.x - alphaMask.getWidth(), updateRect.extent.y - alphaMask.getHeight()), GFlip_XY);

            glDisable(GL_ALPHA_TEST);
            glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
            glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
            glStencilFunc(GL_NOTEQUAL, 1, 0xffffffff);
        }

        TextureHandle th = mFramebufferTexture.getTextureHandle();
        drawFullLiquidGlassRect(th, updateRect, bevel, depth, 255,  1.f);
        drawFullLiquidGlassRect(th, updateRect, bevel, depth, 128,  2.f);
        drawFullLiquidGlassRect(th, updateRect, bevel, depth, 64,   3.f);
        drawFullLiquidGlassRect(th, updateRect, bevel, depth, 32,   4.f);

        // Draw glass effect overlay color
        dglDrawRectFill(updateRect, overlayColor);

        // Reset GL state
        if (alphaMask.getGLName() != 0)
            glDisable(GL_STENCIL_TEST);
        glTexEnvf(DGL_TEXTURE_FILTER_CONTROL, DGL_TEXTURE_LOD_BIAS, 0.f);

        // Finally, draw bitmap and children
        dglSetBitmapModulation(oldMod);
        Parent::onRender(offset, updateRect);
    }
    static void initPersistFields()
    {
        Parent::initPersistFields();
        addField("overlayColor", TypeColorI, Offset(overlayColor, GuiLiquidGlass)); // slightly white by default
        addField("bevel", TypeS32, Offset(bevel, GuiLiquidGlass));
        addField("depth", TypeS32, Offset(depth, GuiLiquidGlass));
        addField("alphaMask", TypeBitmapFilename, Offset(alphaMask, GuiLiquidGlass));

        // alphaMask is intended to be a top-left corner with the outside in alpha.
    }
};

IMPLEMENT_CONOBJECT(GuiLiquidGlass);

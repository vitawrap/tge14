//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "console/console.h"
#include "console/consoleTypes.h"
#include "dgl/dgl.h"
#include "gui/core/guiControl.h"

class GuiLetterboxCtrl : public GuiControl
{
private:
    typedef GuiControl Parent;

protected:
    SimTime mLastAwakeTime;
    S32 mTransitionTime;

public:
    static Point2F smGlobalAspect;

    //creation methods
    DECLARE_CONOBJECT(GuiLetterboxCtrl);
    GuiLetterboxCtrl();
    static void initPersistFields();
    static void consoleInit();

    //Parental methods
    bool onWake();
    void onSleep();

    void onRender(Point2I offset, const RectI& updateRect);
};

Point2F GuiLetterboxCtrl::smGlobalAspect = Point2F(16.f, 9.f);

IMPLEMENT_CONOBJECT(GuiLetterboxCtrl);

void GuiLetterboxCtrl::initPersistFields()
{
    Parent::initPersistFields();
    addGroup("Misc");
    addField("transitionTime", TypeS32, Offset( mTransitionTime, GuiLetterboxCtrl ));
    endGroup("Misc");
}

void GuiLetterboxCtrl::consoleInit()
{
    // Point2I so I can spare myself of the insanity of making a specific console type.
    Con::addVariable("Letterbox::GlobalAspect", TypePoint2F, &smGlobalAspect);
}

GuiLetterboxCtrl::GuiLetterboxCtrl()
{
    mTransitionTime = 1000;
}

bool GuiLetterboxCtrl::onWake()
{
    if (!Parent::onWake())
        return false;

    mLastAwakeTime = Sim::getCurrentTime();
    return true;
}

void GuiLetterboxCtrl::onSleep()
{
    Parent::onSleep();
}

void GuiLetterboxCtrl::onRender(Point2I offset, const RectI& updateRect)
{
    Point2F aspect = smGlobalAspect;

    SimTime now = Sim::getCurrentTime();
    if ((mLastAwakeTime + mTransitionTime) > now)
    {
        // Interpolation is very abrupt if the global aspect is a correct value like "16 9"... so we assume such a value can simply
        // be multiplied by 100 to match a closer screen resolution to the bounds.
        Point2I origExt = mBounds.extent;
        Point2F plerp;
        plerp.interpolate(Point2F(origExt.x, origExt.y), smGlobalAspect * 100.f, ((F32)now - mLastAwakeTime) / (F32)mTransitionTime);
        aspect = plerp;
    }

    Point2I imgOffset = offset;
    RectI imgRect = mBounds;

    F32 bitmapDims = aspect.x / aspect.y;
    F32 screenDims = (F32)mBounds.len_x() / mBounds.len_y();
    bool xovery = screenDims > bitmapDims;

    Point2I afterOffset;

    if (xovery)
    {
        F32 width = aspect.x * ((F32)mBounds.len_y() / aspect.y);
        imgOffset.x += (mBounds.len_x() - width) * .5f;
        imgRect.extent.x = width;
    }
    else
    {
        F32 height = aspect.y * ((F32)mBounds.len_x() / aspect.x);
        imgOffset.y += (mBounds.len_y() - height) * .5f;
        imgRect.extent.y = height;
    }

    Point2I safeExt = xovery ? Point2I(imgRect.extent.x, 0) : Point2I(0, imgRect.extent.y);
    Point2I fullExt = (mBounds.extent - safeExt);
    Point2I halfExt = Point2I(fullExt.x >> xovery, fullExt.y >> (1 - xovery));
    
    dglDrawRectFill(RectI(offset, halfExt), ColorI(0, 0, 0));
    dglDrawRectFill(RectI(offset + (mBounds.extent - halfExt), halfExt), ColorI(0, 0, 0));

    renderChildControls(offset, updateRect);
}

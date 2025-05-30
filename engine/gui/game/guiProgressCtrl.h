//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#ifndef _GUIPROGRESSCTRL_H_
#define _GUIPROGRESSCTRL_H_

#ifndef _GUICONTROL_H_
#include "gui/core/guiControl.h"
#endif

class GuiProgressCtrl : public GuiControl
{
private:
   typedef GuiControl Parent;

   F32 mProgress;

public:
   //creation methods
   DECLARE_CONOBJECT(GuiProgressCtrl);
   GuiProgressCtrl();

   //console related methods
   ConsoleValue getScriptValue() override;
   void setScriptValue(ConsoleValue &value) override;

   void onPreRender();
   void onRender(Point2I offset, const RectI &updateRect);
};

#endif

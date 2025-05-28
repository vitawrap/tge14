//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#include "console/consoleTypes.h"
#include "console/console.h"
#include "core/color.h"
#include "gui/controls/guiConsoleTextCtrl.h"
#include "dgl/dgl.h"

IMPLEMENT_CONOBJECT(GuiConsoleTextCtrl);

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

GuiConsoleTextCtrl::GuiConsoleTextCtrl()
{
   //default fonts
   mConsoleExpression = NULL;
}

void GuiConsoleTextCtrl::initPersistFields()
{
   Parent::initPersistFields();
   addGroup("Misc");		
   addField("expression",  TypeCaseString,  Offset(mConsoleExpression, GuiConsoleTextCtrl));
   endGroup("Misc");		
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

bool GuiConsoleTextCtrl::onWake()
{
   if (! Parent::onWake())
      return false;

   mFont = mProfile->mFont;
   return true;
}

void GuiConsoleTextCtrl::onSleep()
{
   Parent::onSleep();
   mFont = NULL;
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

void GuiConsoleTextCtrl::setText(const char *txt)
{
   //make sure we don't call this before onAdd();
   AssertFatal(mProfile, "Can't call setText() until setProfile() has been called.");

   if (txt)
      mConsoleExpression = StringTable->insert(txt);
   else
      mConsoleExpression = NULL;

   //Make sure we have a font
   mProfile->incRefCount();
   mFont = mProfile->mFont;

   setUpdate();

   //decrement the profile referrence
   mProfile->decRefCount();
}

void GuiConsoleTextCtrl::calcResize()
{
   if (mResult.isNullString())
      return;

   //resize
   if (mProfile->mAutoSizeWidth)
   {
      char const* result = mResult.toString();
      if (mProfile->mAutoSizeHeight)
         resize(mBounds.point, Point2I(mFont->getStrWidth((const UTF8 *) result) + 4, mFont->getHeight() + 4));
      else
         resize(mBounds.point, Point2I(mFont->getStrWidth((const UTF8 *) result) + 4, mBounds.extent.y));
   }
   else if (mProfile->mAutoSizeHeight)
   {
      resize(mBounds.point, Point2I(mBounds.extent.x, mFont->getHeight() + 4));
   }
}


void GuiConsoleTextCtrl::onPreRender()
{
   if (mConsoleExpression) {
      // Explicit return is needed with consolevalue stack.
      mResult = Con::evaluatef("return $temp = %s;", mConsoleExpression);
   }
   calcResize();
}


// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

void GuiConsoleTextCtrl::onRender(Point2I offset, const RectI &updateRect)
{
   // draw the background rectangle
   RectI r(offset, mBounds.extent);
   dglDrawRectFill(r, ColorI(255,255,255));

   // draw the border
   r.extent += r.point;
   glColor4ub(0, 0, 0, 0);
   glBegin(GL_LINE_LOOP);
   glVertex2i(r.point.x,  r.point.y);
   glVertex2i(r.extent.x-1, r.point.y);
   glVertex2i(r.extent.x-1, r.extent.y-1);
   glVertex2i(r.point.x,  r.extent.y-1);
   glEnd();

   if (!mResult.isNullString())
   {
      char const* result = mResult.toString();
      S32 txt_w = mFont->getStrWidth((const UTF8 *)result);
      Point2I localStart;
      switch (mProfile->mAlignment)
      {
         case GuiControlProfile::RightJustify:
            localStart.set(mBounds.extent.x - txt_w-2, 0);
            break;
         case GuiControlProfile::CenterJustify:
            localStart.set((mBounds.extent.x - txt_w) / 2, 0);
            break;
         default:
            // GuiControlProfile::LeftJustify
            localStart.set(2,0);
            break;
      }

      Point2I globalStart = localToGlobalCoord(localStart);

      //draw the text
      dglSetBitmapModulation(mProfile->mFontColor);
      dglDrawText(mFont, globalStart, result, mProfile->mFontColors);
   }

   //render the child controls
   renderChildControls(offset, updateRect);
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

ConsoleValue GuiConsoleTextCtrl::getScriptValue()
{
   return getText();
}

void GuiConsoleTextCtrl::setScriptValue(ConsoleValue& val)
{
   setText(val.toString());
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// EOF //

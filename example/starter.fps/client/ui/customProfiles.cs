//-----------------------------------------------------------------------------
// Torque Game Engine 
// Copyright (c) 2002 GarageGames.Com
//-----------------------------------------------------------------------------

// TangoSans CC0 font by Sandylukee
registerFont("~/client/fonts/TangoSans.ttf");

new GuiControlProfile (GuiDefaultProfile)
{
   tab = false;
   canKeyFocus = false;
   hasBitmapArray = false;
   mouseOverSelected = false;

   // fill color
   opaque = false;
   fillColor = "201 182 153";
   fillColorHL = "221 202 173";
   fillColorNA = "221 202 173";

   // border color
   border = false;
   borderColor   = "0 0 0"; 
   borderColorHL = "179 134 94";
   borderColorNA = "126 79 37";
   
   // bevel color
   bevelColorHL = "255 255 255";
   bevelColorLL = "0 0 0";

   // font
   fontType = "TangoSans";
   fontSize = 15;
   fontCharset = CHINESEBIG5;

   fontColor = "0 0 0";
   fontColorHL = "32 100 100";
   fontColorNA = "0 0 0";
   fontColorSEL= "200 200 200";

   // bitmap information
   bitmap = "./demoWindow";
   bitmapBase = "";
   textOffset = "0 0";

   // used by guiTextControl
   modal = true;
   justify = "left";
   autoSizeWidth = false;
   autoSizeHeight = false;
   returnTab = false;
   numbersOnly = false;
   cursorColor = "0 0 0 255";

   // sounds
   soundButtonDown = "";
   soundButtonOver = "";
};

new GuiControlProfile (GuiTextProfile) // Override
{
   fontSize = 24;
   fontColor = "240 240 240";
   fontColorLink = "192 192 192";
   fontColorLinkHL = "219 160 52";
   autoSizeWidth = true;
   autoSizeHeight = true;
};

new GuiControlProfile (GuiWindowProfile)
{
   fontType = "BuiltTitlingRg-Bold";
   fontSize = 48;

   opaque = true;
   border = 2;
   fillColor = "44 43 42";
   fillColorHL = "44 43 42";
   fillColorNA = "44 43 42";
   fontColor = "255 255 255";
   fontColorHL = "255 255 255";
   text = "GuiWindowCtrl test";
   bitmap = "./guiWindow";
   textOffset = "18 18";
   hasBitmapArray = true;
   justify = "center";
};

new GuiControlProfile (GuiBitmapButtonProfile)
{
   fontType = "BuiltTitlingRg-Bold";
   fontSize = 48;
   fontColor = "255 255 255";
   fontColorHL = "255 255 255";
   
   bitmap = "./guiBtn";
   justify = "center";
};

new GuiControlProfile (GuiScrollProfile)
{
   opaque = true;
   fillColor = "255 255 255";
   border = 3;
   borderThickness = 2;
   borderColor = "0 0 0";
   bitmap = "./demoScroll";
   hasBitmapArray = true;
};

new GuiControlProfile (GuiCheckBoxProfile)
{
   opaque = false;
   fillColor = "232 232 232";
   border = false;
   borderColor = "0 0 0";
   fontSize = 14;
   fontColor = "0 0 0";
   fontColorHL = "32 100 100";
   fixedExtent = true;
   justify = "left";
   bitmap = "./demoCheck";
   hasBitmapArray = true;
};

new GuiControlProfile (GuiRadioProfile)
{
   fontSize = 14;
   fillColor = "232 232 232";
   fontColorHL = "32 100 100";
   fixedExtent = true;
   bitmap = "./demoRadio";
   hasBitmapArray = true;
};


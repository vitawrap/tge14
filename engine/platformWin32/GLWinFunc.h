//-----------------------------------------------------------------------------
// Torque Game Engine
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------


WGL_FUNCTION( BOOL,  wglCopyContext, (HGLRC, HGLRC, UINT), return false; )
WGL_FUNCTION( HGLRC, wglCreateContext, (HDC), return NULL; )
//WGL_FUNCTION( HGLRC, wglCreateLayerContext, (HDC, S32), return NULL; )
WGL_FUNCTION( BOOL,  wglDeleteContext, (HGLRC), return false; )
WGL_FUNCTION( HGLRC, wglGetCurrentContext, (VOID), return NULL; )
WGL_FUNCTION( HDC,   wglGetCurrentDC, (VOID), return NULL; )
WGL_FUNCTION( PROC,  wglGetProcAddress, (LPCSTR), return NULL; )
WGL_FUNCTION( BOOL,  wglMakeCurrent, (HDC, HGLRC), return false; )
WGL_FUNCTION( BOOL,  wglShareLists, (HGLRC, HGLRC), return false; )
//WGL_FUNCTION( BOOL,  wglUseFontBitmaps, (HDC, DWORD, DWORD, DWORD), return false; )
//WGL_FUNCTION( BOOL,  wglUseFontOutlines, (HDC, DWORD, DWORD, DWORD, FLOAT, FLOAT, S32, LPGLYPHMETRICSFLOAT), return false; )
WGL_FUNCTION( BOOL,  wglDescribeLayerPlane, (HDC, S32, S32, UINT, LPLAYERPLANEDESCRIPTOR), return false; )
//WGL_FUNCTION( S32,   wglSetLayerPaletteEntries, (HDC, S32, S32, S32, CONST COLORREF *), return 0; )
//WGL_FUNCTION( S32,   wglGetLayerPaletteEntries, (HDC, S32, S32, S32, COLORREF *), return 0; )
//WGL_FUNCTION( BOOL,  wglRealizeLayerPalette, (HDC, S32, BOOL), return false; )
//WGL_FUNCTION( BOOL,  wglSwapLayerBuffers, (HDC, UINT), return false; )

WGL_FUNCTION( S32,   wglChoosePixelFormat,(HDC, CONST PIXELFORMATDESCRIPTOR *), return 0; )
WGL_FUNCTION( S32,   wglDescribePixelFormat, (HDC, S32, UINT, LPPIXELFORMATDESCRIPTOR), return 0; )
WGL_FUNCTION( S32,   wglGetPixelFormat, (HDC), return 0; )
WGL_FUNCTION( BOOL,  wglSetPixelFormat, (HDC, S32, CONST PIXELFORMATDESCRIPTOR *), return false; )
WGL_FUNCTION( BOOL,  wglSwapBuffers, (HDC), return false; )

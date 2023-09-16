#include "itf.h"

//#ifndef TORQUE_SUPPORTS_VC_INLINE_X86_ASM
#if 1

// Process Globals

// Process Functions
void processTriFan(OutputPoint* dst,
    const ItrPaddedPoint* srcPoints,
    const U32* srcIndices,
    const U32 numIndices)
{
    F32 st3, st2, st1, st0;
    for (int i = 0; i < numIndices; ++i)
    {
        U32 idx = srcIndices[i];
        ItrPaddedPoint const& pt = srcPoints[idx];
        dst->point = pt.point;
        dst->fogCoord = pt.fogCoord;

        st3 = (pt.point.x * texGen0[0]);
        st2 = (pt.point.y * texGen0[1]);
        st1 = (pt.point.z * texGen0[2]);
        st0 = st3 + st2 + st1 + texGen0[3];
        dst->texCoord.x = st0;

        st3 = (pt.point.x * texGen0[4]);
        st2 = (pt.point.y * texGen0[5]);
        st1 = (pt.point.z * texGen0[6]);
        st0 = st3 + st2 + st1 + texGen0[7];
        dst->texCoord.y = st0;

        st3 = (pt.point.x * texGen1[0]);
        st2 = (pt.point.y * texGen1[1]);
        st1 = (pt.point.z * texGen1[2]);
        st0 = st3 + st2 + st1 + texGen1[3];
        dst->lmCoord.x = st0;

        st3 = (pt.point.x * texGen1[4]);
        st2 = (pt.point.y * texGen1[5]);
        st1 = (pt.point.z * texGen1[6]);
        st0 = st3 + st2 + st1 + texGen1[7];
        dst->lmCoord.y = st0;

        ++dst;
    }
}

void processTriFanSP(OutputPoint* dst,
    const ItrPaddedPoint* srcPoints,
    const U32* srcIndices,
    const U32 numIndices,
    const ColorI* srcColors)
{
    F32 st3, st2, st1, st0;
    for (int i = 0; i < numIndices; ++i)
    {
        U32 idx = srcIndices[i];
        ItrPaddedPoint const& pt = srcPoints[idx];
        dst->point = pt.point;
        dst->fogColors = *&(srcColors[idx].red);

        st3 = (pt.point.x * texGen0[0]);
        st2 = (pt.point.y * texGen0[1]);
        st1 = (pt.point.z * texGen0[2]);
        st0 = st3 + st2 + st1 + texGen0[3];
        dst->texCoord.x = st0;

        st3 = (pt.point.x * texGen0[4]);
        st2 = (pt.point.y * texGen0[5]);
        st1 = (pt.point.z * texGen0[6]);
        st0 = st3 + st2 + st1 + texGen0[7];
        dst->texCoord.y = st0;

        ++dst;
    }
}

void processTriFanVC_TF(OutputPoint* dst,
    const ItrPaddedPoint* srcPoints,
    const U32* srcIndices,
    const U32 numIndices,
    const ColorI* srcColors)
{
    F32 st3, st2, st1, st0;
    for (int i = 0; i < numIndices; ++i)
    {
        U32 idx = srcIndices[i];
        ItrPaddedPoint const& pt = srcPoints[idx];
        dst->point = pt.point;
        dst->texCoord = fogCoordinatePointer[idx];
        dst->fogColors = *&(srcColors[idx].red);

        st3 = (pt.point.x * texGen0[0]);
        st2 = (pt.point.y * texGen0[1]);
        st1 = (pt.point.z * texGen0[2]);
        st0 = st3 + st2 + st1 + texGen0[3];
        dst->texCoord.x = st0;

        st3 = (pt.point.x * texGen0[4]);
        st2 = (pt.point.y * texGen0[5]);
        st1 = (pt.point.z * texGen0[6]);
        st0 = st3 + st2 + st1 + texGen0[7];
        dst->texCoord.y = st0;

        ++dst;
    }
}

void processTriFanSP_FC(OutputPoint* dst,
    const ItrPaddedPoint* srcPoints,
    const U32* srcIndices,
    const U32 numIndices,
    const ColorI* srcColors)
{
    F32 st3, st2, st1, st0;
    for (int i = 0; i < numIndices; ++i)
    {
        U32 idx = srcIndices[i];
        ItrPaddedPoint const& pt = srcPoints[idx];
        dst->point = pt.point;
        dst->fogCoord = pt.fogCoord;
        dst->fogColors = *&(srcColors[idx].red);

        st3 = (pt.point.x * texGen0[0]);
        st2 = (pt.point.y * texGen0[1]);
        st1 = (pt.point.z * texGen0[2]);
        st0 = st3 + st2 + st1 + texGen0[3];
        dst->texCoord.x = st0;

        st3 = (pt.point.x * texGen0[4]);
        st2 = (pt.point.y * texGen0[5]);
        st1 = (pt.point.z * texGen0[6]);
        st0 = st3 + st2 + st1 + texGen0[7];
        dst->texCoord.y = st0;

        ++dst;
    }
}

void processTriFanFC_VB(OutputPointFC_VB* dst,
    const ItrPaddedPoint* srcPoints,
    const U32* srcIndices,
    const U32 numIndices)
{
    U32 alpha;
    F32 st3, st2, st1, st0;
    for (int i = 0; i < numIndices; ++i)
    {
        U32 idx = srcIndices[i];
        ItrPaddedPoint const& pt = srcPoints[idx];
        dst->point = pt.point;
        dst->currentColors = 0xFFFFFFFF;
        alpha = pt.fogCoord * 48896.f;
        alpha = 255 - alpha;
        dst->fogColors = alpha << 24;

        st3 = (pt.point.x * texGen0[0]);
        st2 = (pt.point.y * texGen0[1]);
        st1 = (pt.point.z * texGen0[2]);
        st0 = st3 + st2 + st1 + texGen0[3];
        dst->texCoord.x = st0;

        st3 = (pt.point.x * texGen0[4]);
        st2 = (pt.point.y * texGen0[5]);
        st1 = (pt.point.z * texGen0[6]);
        st0 = st3 + st2 + st1 + texGen0[7];
        dst->texCoord.y = st0;

        ++dst;
    }
}

void processTriFanSP_FC_VB(OutputPointSP_FC_VB* dst,
    const ItrPaddedPoint* srcPoints,
    const U32* srcIndices,
    const U32 numIndices,
    const ColorI* srcColors)
{
    U32 alpha;
    F32 st3, st2, st1, st0;
    for (int i = 0; i < numIndices; ++i)
    {
        U32 idx = srcIndices[i];
        ItrPaddedPoint const& pt = srcPoints[idx];
        dst->point = pt.point;
        alpha = pt.fogCoord * 48896.f;  // two55
        alpha = 255 - alpha;
        dst->fogColors = alpha << 24;
        U32 color = *&(srcColors[idx].red);
        U32 rol = ((color & 0x00FF00FF) << 16) & ((color & 0x00FF00FF) >> 16);
        dst->lmColors = (color & 0xFF00FF00) | rol;

        st3 = (pt.point.x * texGen0[0]);
        st2 = (pt.point.y * texGen0[1]);
        st1 = (pt.point.z * texGen0[2]);
        st0 = st3 + st2 + st1 + texGen0[3];
        dst->texCoord.x = st0;

        st3 = (pt.point.x * texGen0[4]);
        st2 = (pt.point.y * texGen0[5]);
        st1 = (pt.point.z * texGen0[6]);
        st0 = st3 + st2 + st1 + texGen0[7];
        dst->texCoord.y = st0;

        ++dst;
    }
}

#endif // !TORQUE_SUPPORTS_VC_INLINE_X86_ASM

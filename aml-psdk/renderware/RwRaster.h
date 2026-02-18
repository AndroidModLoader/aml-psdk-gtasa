#ifndef __AML_PSDK_RWRASTER_H
#define __AML_PSDK_RWRASTER_H

#include <aml-psdk/sdk_base.h>
#include "RwBase.h"
#include "RwLinks.h"
#include "RwRGBA.h"

struct TextureDatabaseEntry;
struct RwImage;

struct RwRaster
{
    RwRaster             *parent; /* Top level raster if a sub raster */
    RwUInt8              *cpPixels; /* Pixel pointer when locked */
    RwUInt8              *palette; /* Raster palette */
    RwInt32               width, height, depth; /* Dimensions of raster */
    RwInt32               stride; /* Lines bytes of raster */
    RwInt16               nOffsetX, nOffsetY; /* Sub raster offset */
    RwUInt8               cType;  /* Type of raster */
    RwUInt8               cFlags; /* Raster flags */
    RwUInt8               cFormat; /* Raster format */

    RwInt32               originalWidth;
    RwInt32               originalHeight;
    TextureDatabaseEntry *dbEntry;
    RwUInt16              privateFlags; /* Raster private flags */
};

DECL_FASTCALL_SIMPLE_GLO(RwRasterSetKeepCPU, _Z18RwRasterSetKeepCPUb, void, bool keep);
DECL_FASTCALL_SIMPLE_GLO(RwRasterSetFromImage, _Z20RwRasterSetFromImageP8RwRasterP7RwImage, RwRaster*, RwRaster *raster, RwImage *image);
DECL_FASTCALL_SIMPLE_GLO(RwRGBAGetRasterPixel, _Z20RwRGBAGetRasterPixelP6RwRGBAP8RwRasterii, RwRGBA*, RwRGBA *rgbOut, RwRaster *raster, RwInt32 x, RwInt32 y);
DECL_FASTCALL_SIMPLE_GLO(RwRasterRead, _Z12RwRasterReadPKc, RwRaster*, const RwChar *filename);
DECL_FASTCALL_SIMPLE_GLO(RwRasterReadMaskedRaster, _Z24RwRasterReadMaskedRasterPKcS0_, RwRaster*, const RwChar *filename, const RwChar *maskname);
DECL_FASTCALL_SIMPLE_GLO(RwRasterGetPluginOffset, _Z23RwRasterGetPluginOffsetj, RwInt32, RwUInt32 pluginID);
DECL_FASTCALL_SIMPLE_GLO(RwRasterGetCurrentContext, _Z25RwRasterGetCurrentContextv, RwRaster*);
DECL_FASTCALL_SIMPLE_GLO(RwRasterRenderScaled, _Z20RwRasterRenderScaledP8RwRasterP6RwRect, RwRaster*, RwRaster *raster, RwRect *rect);
DECL_FASTCALL_SIMPLE_GLO(RwRasterGetOffset, _Z17RwRasterGetOffsetP8RwRasterPsS1_, RwRaster*, RwRaster *raster, RwInt16 *xOffset, RwInt16 *yOffset);
DECL_FASTCALL_SIMPLE_GLO(RwRasterUnlock, _Z14RwRasterUnlockP8RwRaster, RwRaster*, RwRaster *raster);
DECL_FASTCALL_SIMPLE_GLO(RwRasterClear, _Z13RwRasterCleari, RwBool, RwInt32 pixelValue);
DECL_FASTCALL_SIMPLE_GLO(RwRasterValidatePlugins, _Z23RwRasterValidatePluginsPK8RwRaster, RwBool, const RwRaster *raster);
DECL_FASTCALL_SIMPLE_GLO(RwRasterRenderFast, _Z18RwRasterRenderFastP8RwRasterii, RwRaster*, RwRaster *raster, RwInt32 x, RwInt32 y);
DECL_FASTCALL_SIMPLE_GLO(RwRasterClearRect, _Z17RwRasterClearRectP6RwRecti, RwBool, RwRect *rect, RwInt32 pixelValue);
DECL_FASTCALL_SIMPLE_GLO(RwRasterRender, _Z14RwRasterRenderP8RwRasterii, RwRaster*, RwRaster *raster, RwInt32 x, RwInt32 y);
DECL_FASTCALL_SIMPLE_GLO(RwRasterUnlockPalette, _Z21RwRasterUnlockPaletteP8RwRaster, RwRaster*, RwRaster* raster);
DECL_FASTCALL_SIMPLE_GLO(RwRasterDestroy, _Z15RwRasterDestroyP8RwRaster, RwBool, RwRaster *raster);
DECL_FASTCALL_SIMPLE_GLO(RwRasterPushContext, _Z19RwRasterPushContextP8RwRaster, RwRaster*, RwRaster *raster);
DECL_FASTCALL_SIMPLE_GLO(RwRasterRegisterPlugin, _Z22RwRasterRegisterPluginijPFPvS_iiES1_PFS_S_PKviiE, RwInt32,
    RwInt32 size, RwUInt32 pluginID, RwPluginObjectConstructor constructCB, RwPluginObjectDestructor destructCB, RwPluginObjectCopy copyCB);
DECL_FASTCALL_SIMPLE_GLO(RwRasterLockPalette, _Z19RwRasterLockPaletteP8RwRasteri, RwUInt8*, RwRaster *raster, RwInt32 lockMode);
DECL_FASTCALL_SIMPLE_GLO(RwRasterPopContext, _Z18RwRasterPopContextv, RwRaster*);
DECL_FASTCALL_SIMPLE_GLO(RwRasterGetNumLevels, _Z20RwRasterGetNumLevelsP8RwRaster, RwInt32);
DECL_FASTCALL_SIMPLE_GLO(RwRasterShowRaster, _Z18RwRasterShowRasterP8RwRasterPvj, RwRaster*, RwRaster *raster, void *dev, RwUInt32 flags);
DECL_FASTCALL_SIMPLE_GLO(RwRasterSubRaster, _Z17RwRasterSubRasterP8RwRasterS0_P6RwRect, RwRaster*, RwRaster *subRaster, RwRaster *raster, RwRect *rect);
DECL_FASTCALL_SIMPLE_GLO(RwRasterCreate, _Z14RwRasterCreateiiii, RwRaster*, RwInt32 width, RwInt32 height, RwInt32 depth, RwInt32 flags);
DECL_FASTCALL_SIMPLE_GLO(RwRasterLock, _Z12RwRasterLockP8RwRasterhi, RwUInt8*, RwRaster *raster, RwUInt8 level, RwInt32 lockMode);
DECL_FASTCALL_SIMPLE_GLO(RwRasterSetFreeListCreateParams, _Z31RwRasterSetFreeListCreateParamsii, void, RwInt32 blockSize, RwInt32 numBlocksToPrealloc);

#endif // __AML_PSDK_RWRASTER_H
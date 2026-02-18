#ifndef __AML_PSDK_RWIMAGE_H
#define __AML_PSDK_RWIMAGE_H

#include <aml-psdk/sdk_base.h>
#include "RwBase.h"
#include "RwLinks.h"
#include "RwRGBA.h"

struct RwStream;
struct RwRaster;

struct RwImage
{
    RwInt32             flags;

    RwInt32             width;  /* Device may have different ideas */
    RwInt32             height; /* internally !! */

    RwInt32             depth;  /* Of referenced image */
    RwInt32             stride;

    RwUInt8            *cpPixels;
    RwRGBA             *palette;
};

typedef RwImage *(*RwImageCallBackRead)(const RwChar *);
typedef RwImage *(*RwImageCallBackWrite)(RwImage *, const RwChar *);

DECL_FASTCALL_SIMPLE_GLO(RwImageSetFreeListCreateParams, _Z30RwImageSetFreeListCreateParamsii, void, RwInt32 blockSize, RwInt32 numBlocksToPrealloc);
DECL_FASTCALL_SIMPLE_GLO(RwImageFormatSetFreeListCreateParams, _Z36RwImageFormatSetFreeListCreateParamsii, void, RwInt32 blockSize, RwInt32 numBlocksToPrealloc);
DECL_FASTCALL_SIMPLE_GLO(RwImageSetGamma, _Z15RwImageSetGammaf, RwBool, RwReal gammaValue);
DECL_FASTCALL_SIMPLE_GLO(RwImageCreate, _Z13RwImageCreateiii, RwImage*, RwInt32 width, RwInt32 height, RwInt32 depth);
DECL_FASTCALL_SIMPLE_GLO(RwImageDestroy, _Z14RwImageDestroyP7RwImage, RwBool, RwImage *image);
DECL_FASTCALL_SIMPLE_GLO(RwImageFreePixels, _Z17RwImageFreePixelsP7RwImage, RwImage*, RwImage *image);
DECL_FASTCALL_SIMPLE_GLO(RwImageAllocatePixels, _Z21RwImageAllocatePixelsP7RwImage, RwImage*, RwImage *image);
DECL_FASTCALL_SIMPLE_GLO(RwImageResize, _Z13RwImageResizeP7RwImageii, RwImage*, RwImage *image, RwInt32 width, RwInt32 height);
DECL_FASTCALL_SIMPLE_GLO(RwImageMakeMask, _Z15RwImageMakeMaskP7RwImage, RwImage*, RwImage *image);
DECL_FASTCALL_SIMPLE_GLO(RwImageApplyMask, _Z16RwImageApplyMaskP7RwImagePKS_, RwImage*, RwImage *image, RwImage const *mask);
DECL_FASTCALL_SIMPLE_GLO(RwImageCopy, _Z11RwImageCopyP7RwImagePKS_, RwImage*, RwImage *destImage, const RwImage *sourceImage);
DECL_FASTCALL_SIMPLE_GLO(RwImageSetPath, _Z14RwImageSetPathPKc, const RwChar*, const RwChar *path);
DECL_FASTCALL_SIMPLE_GLO(RwImageGetPath, _Z14RwImageGetPathv, RwChar*);
DECL_FASTCALL_SIMPLE_GLO(RwImageRead, _Z11RwImageReadPKc, RwImage*, const RwChar *imageName);
DECL_FASTCALL_SIMPLE_GLO(RwImageFindFileType, _Z19RwImageFindFileTypePKc, const RwChar*, const RwChar *imageName);
DECL_FASTCALL_SIMPLE_GLO(RwImageRegisterImageFormat, _Z26RwImageRegisterImageFormatPKcPFP7RwImageS0_EPFS2_S2_S0_E, RwBool,
    const RwChar *extension, RwImageCallBackRead imageRead, RwImageCallBackWrite imageWrite);
DECL_FASTCALL_SIMPLE_GLO(RwImageWrite, _Z12RwImageWriteP7RwImagePKc, RwImage*, RwImage *image, const RwChar *imageName);
DECL_FASTCALL_SIMPLE_GLO(RwImageReadMaskedImage, _Z22RwImageReadMaskedImagePKcS0_, RwImage*, const RwChar *imageName, const RwChar *maskName);
DECL_FASTCALL_SIMPLE_GLO(RwImageRegisterPlugin, _Z21RwImageRegisterPluginijPFPvS_iiES1_PFS_S_PKviiE, void,
    RwInt32 size, RwUInt32 pluginID, RwPluginObjectConstructor constructCB, RwPluginObjectDestructor destructCB, RwPluginObjectCopy copyCB);
DECL_FASTCALL_SIMPLE_GLO(RwImageGetPluginOffset, _Z22RwImageGetPluginOffsetj, RwInt32, RwUInt32 pluginID);
DECL_FASTCALL_SIMPLE_GLO(RwImageValidatePlugins, _Z22RwImageValidatePluginsPK7RwImage, RwBool, const RwImage *image);
DECL_FASTCALL_SIMPLE_GLO(RwImageStreamGetSize, _Z20RwImageStreamGetSizePK7RwImage, RwInt32, const RwImage *image);
DECL_FASTCALL_SIMPLE_GLO(RwImageStreamRead, _Z17RwImageStreamReadP8RwStream, RwImage*, RwStream *stream);
DECL_FASTCALL_SIMPLE_GLO(RwImageStreamWrite, _Z18RwImageStreamWritePK7RwImageP8RwStream, const RwImage*, const RwImage *image, RwStream *stream);
DECL_FASTCALL_SIMPLE_GLO(RwImageGammaCorrect, _Z19RwImageGammaCorrectP7RwImage, RwImage*, RwImage *image);
DECL_FASTCALL_SIMPLE_GLO(RwImageGetGamma, _Z15RwImageGetGammav, RwReal);
DECL_FASTCALL_SIMPLE_GLO(RwImageSetFromRaster, _Z20RwImageSetFromRasterP7RwImageP8RwRaster, RwImage*, RwImage *image, RwRaster *raster);
DECL_FASTCALL_SIMPLE_GLO(RwImageFindRasterFormat, _Z23RwImageFindRasterFormatP7RwImageiPiS1_S1_S1_, RwImage*,
    RwImage *ipImage, RwInt32 nRasterType, RwInt32 *npWidth, RwInt32 *npHeight, RwInt32 *npDepth, RwInt32 *npFormat);
DECL_FASTCALL_SIMPLE_GLO(RwImageResample, _Z15RwImageResampleP7RwImagePKS_, RwImage*, RwImage *dstImage, const RwImage *srcImage);
DECL_FASTCALL_SIMPLE_GLO(RwImageCreateResample, _Z21RwImageCreateResamplePK7RwImageii, RwImage*, const RwImage *srcImage, RwInt32 width, RwInt32 height);

DECL_FASTCALL_SIMPLE_GLO(RtBMPImageWrite, _Z15RtBMPImageWriteP7RwImagePKc, RwImage*, RwImage *image, const RwChar *imageName);
DECL_FASTCALL_SIMPLE_GLO(RtPNGImageWrite, _Z15RtPNGImageWriteP7RwImagePKc, RwImage*, RwImage *image, const RwChar *imageName);
DECL_FASTCALL_SIMPLE_GLO(RtBMPImageRead, _Z14RtBMPImageReadPKc, RwImage*, const RwChar *imageName);
DECL_FASTCALL_SIMPLE_GLO(RtPNGImageRead, _Z14RtPNGImageReadPKc, RwImage*, const RwChar *imageName);

#endif // __AML_PSDK_RWIMAGE_H
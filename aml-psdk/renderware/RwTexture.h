#ifndef __AML_PSDK_RWTEXTURE_H
#define __AML_PSDK_RWTEXTURE_H

#include <aml-psdk/sdk_base.h>
#include "RwBase.h"
#include "RwLinks.h"

#define rwTEXTUREBASENAMELENGTH 32

struct RwRaster;
struct RwTexDictionary;
struct RwStream;
struct RwImage;

struct RwTexture
{
    RwRaster           *raster; /** pointer to RwRaster with data */
    RwTexDictionary    *dict;   /* Dictionary this texture is in */
    RwLLLink            lInDictionary; /* List of textures in this dictionary */

    char                name[rwTEXTUREBASENAMELENGTH];  /* Name of the texture */
    char                mask[rwTEXTUREBASENAMELENGTH];  /* Name of the textures mask */

    /* 31 [xxxxxxxx xxxxxxxx vvvvuuuu ffffffff] 0 */
    RwUInt32            filterAddressing; /* Filtering & addressing mode flags */

    RwInt32             refCount; /* Reference count, surprisingly enough */
};

typedef RwTexture *(*RwTextureCallBackFind)(const char *);
typedef RwRaster *(*RwTextureCallBackMipmapGeneration)(RwRaster *, RwImage *);
typedef RwBool (*RwTextureCallBackMipmapName)(RwChar *, RwChar *, RwUInt8, RwInt32);
typedef RwTexture *(*RwTextureCallBackRead)(const char *, const char *);

DECL_FASTCALL_SIMPLE_GLO(RwTextureCreate, _Z15RwTextureCreateP8RwRaster, RwTexture*, RwRaster *);
DECL_FASTCALL_SIMPLE_GLO(RwTextureDestroy, _Z16RwTextureDestroyP9RwTexture, RwBool, RwTexture *);
DECL_FASTCALL_SIMPLE_GLO(RwTextureGenerateMipmapName, _Z27RwTextureGenerateMipmapNamePcS_hi, RwBool, char *,char *,u8,int);
DECL_FASTCALL_SIMPLE_GLO(RwTextureGetAutoMipmapping, _Z26RwTextureGetAutoMipmappingv, RwBool);
DECL_FASTCALL_SIMPLE_GLO(RwTextureGetFindCallBack, _Z24RwTextureGetFindCallBackv, RwTextureCallBackFind);
DECL_FASTCALL_SIMPLE_GLO(RwTextureGetMipmapGenerationCallBack, _Z36RwTextureGetMipmapGenerationCallBackv, RwTextureCallBackMipmapGeneration);
DECL_FASTCALL_SIMPLE_GLO(RwTextureGetMipmapNameCallBack, _Z30RwTextureGetMipmapNameCallBackv, void);
DECL_FASTCALL_SIMPLE_GLO(RwTextureGetMipmapping, _Z22RwTextureGetMipmappingv, RwBool);
DECL_FASTCALL_SIMPLE_GLO(RwTextureGetPluginOffset, _Z24RwTextureGetPluginOffsetj, RwInt32, uint);
DECL_FASTCALL_SIMPLE_GLO(RwTextureGetReadCallBack, _Z24RwTextureGetReadCallBackv, RwTextureCallBackRead);
DECL_FASTCALL_SIMPLE_GLO(RwTextureGtaStreamRead, _Z22RwTextureGtaStreamReadP8RwStream, RwTexture*, RwStream *);
DECL_FASTCALL_SIMPLE_GLO(RwTextureRasterGenerateMipmaps, _Z30RwTextureRasterGenerateMipmapsP8RwRasterP7RwImage, RwBool, RwRaster *,RwImage *);
DECL_FASTCALL_SIMPLE_GLO(RwTextureRead, _Z13RwTextureReadPKcS0_, RwTexture*, char const*, char const*);
DECL_FASTCALL_SIMPLE_GLO(RwTextureRegisterPlugin, _Z23RwTextureRegisterPluginijPFPvS_iiES1_PFS_S_PKviiE, RwInt32,
    int, uint, RwPluginObjectConstructor, RwPluginObjectDestructor, RwPluginObjectCopy);
DECL_FASTCALL_SIMPLE_GLO(RwTextureRegisterPluginStream, _Z29RwTextureRegisterPluginStreamjPFP8RwStreamS0_iPviiEPFS0_S0_iPKviiEPFiS5_iiE, void,
    uint, RwPluginDataChunkReadCallBack, RwPluginDataChunkWriteCallBack, RwPluginDataChunkGetSizeCallBack);
DECL_FASTCALL_SIMPLE_GLO(RwTextureSetAutoMipmapping, _Z26RwTextureSetAutoMipmappingi, RwBool, int);
DECL_FASTCALL_SIMPLE_GLO(RwTextureSetFindCallBack, _Z24RwTextureSetFindCallBackPFP9RwTexturePKcE, void, RwTextureCallBackFind);
DECL_FASTCALL_SIMPLE_GLO(RwTextureSetFreeListCreateParams, _Z32RwTextureSetFreeListCreateParamsii, void, int,int);
DECL_FASTCALL_SIMPLE_GLO(RwTextureSetMaskName, _Z20RwTextureSetMaskNameP9RwTexturePKc, RwTexture*, RwTexture *,char const*);
DECL_FASTCALL_SIMPLE_GLO(RwTextureSetMipmapGenerationCallBack, _Z36RwTextureSetMipmapGenerationCallBackPFP8RwRasterS0_P7RwImageE, RwBool, RwTextureCallBackMipmapGeneration);
DECL_FASTCALL_SIMPLE_GLO(RwTextureSetMipmapNameCallBack, _Z30RwTextureSetMipmapNameCallBackPFiPcS_hiE, RwBool, RwTextureCallBackMipmapName);
DECL_FASTCALL_SIMPLE_GLO(RwTextureSetMipmapping, _Z22RwTextureSetMipmappingi, RwBool, int);
DECL_FASTCALL_SIMPLE_GLO(RwTextureSetName, _Z16RwTextureSetNameP9RwTexturePKc, RwTexture*, RwTexture *,char const*);
DECL_FASTCALL_SIMPLE_GLO(RwTextureSetRaster, _Z18RwTextureSetRasterP9RwTextureP8RwRaster, RwTexture*, RwTexture *,RwRaster *);
DECL_FASTCALL_SIMPLE_GLO(RwTextureSetReadCallBack, _Z24RwTextureSetReadCallBackPFP9RwTexturePKcS2_E, RwBool, RwTextureCallBackRead);
DECL_FASTCALL_SIMPLE_GLO(RwTextureSetStreamAlwaysCallBack, _Z32RwTextureSetStreamAlwaysCallBackjPFiPviiE, RwInt32, uint, RwPluginDataChunkAlwaysCallBack);
DECL_FASTCALL_SIMPLE_GLO(RwTextureStreamGetSize, _Z22RwTextureStreamGetSizePK9RwTexture, RwUInt32, RwTexture const*);
DECL_FASTCALL_SIMPLE_GLO(RwTextureStreamRead, _Z19RwTextureStreamReadP8RwStream, RwTexture*, RwStream *);
DECL_FASTCALL_SIMPLE_GLO(RwTextureStreamWrite, _Z20RwTextureStreamWritePK9RwTextureP8RwStream, const RwTexture*, RwTexture const*,RwStream *);
DECL_FASTCALL_SIMPLE_GLO(RwTextureValidatePlugins, _Z24RwTextureValidatePluginsPK9RwTexture, RwBool, RwTexture const*);

#endif // __AML_PSDK_RWTEXTURE_H
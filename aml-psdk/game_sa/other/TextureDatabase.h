#ifndef __AML_PSDK_SATEXTUREDATABASE_H
#define __AML_PSDK_SATEXTUREDATABASE_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/base/Lists.h>

struct RwTexture;
struct TextureListingContainer;

enum TextureDatabaseFormat : int32_t
{
    DF_UNC = 0x0,
    DF_DXT = 0x1,
    DF_360 = 0x2,
    DF_PS3 = 0x3,
    DF_PVR = 0x4,
    DF_ETC = 0x5,
    DF_Default = 0x6,
    DF_ALL = 0x7,
};

DECL_CLASS(TextureCategory)
    const char   *name;
    unsigned int  onFootPriority;
    unsigned int  slowCarPriority;
    unsigned int  fastCarPriority;
    u16           defaultFormat;
    u16           defaultStreamMode;
DECL_CLASS_END()

DECL_CLASS(TextureDatabaseEntry)
    // Member functions
    DECL_THISCALL_HEAD(LoadInstance, _ZN20TextureDatabaseEntry12LoadInstanceERK23TextureListingContainer, RwTexture*, TextureListingContainer const& container)
    DECL_THISCALL_TAIL(LoadInstance, container)
    
    DECL_THISCALL_HEAD(LoadPNG, _ZN20TextureDatabaseEntry7LoadPNGEPKc, RwTexture*, const char *filename)
    DECL_THISCALL_TAIL(LoadPNG, filename)
    
    DECL_THISCALL_SIMPLE(Delete, _ZN20TextureDatabaseEntry6DeleteEv, u32);

    // Member values
    const char   *name;
    unsigned int  nameHash;
    u16           format : 4;
    u16           alphaFormat : 4;
    u16           streamMode : 4;
    u16           status : 4;
    u16           flags;
    u8            category;
    u8            detailTexture;
    u8            detailTiling;
    u16           width;
    u16           height;
    RwTexture    *instance;
DECL_CLASS_END()

DECL_CLASS(TextureListing)
    // Member functions
    DECL_THISCALL_SIMPLE(GetTotalSize, _ZNK14TextureListing12GetTotalSizeEv, u32);
    DECL_THISCALL_SIMPLE(GetMipCount, _ZNK14TextureListing11GetMipCountEv, u32);
    DECL_THISCALL_SIMPLE(GetRLESegSize, _ZNK14TextureListing13GetRLESegSizeEv, u32);
    DECL_THISCALL_SIMPLE(GetRQFormat, _ZNK14TextureListing11GetRQFormatEv, int);
    
    DECL_THISCALL_HEAD(GetMipSize, _ZNK14TextureListing10GetMipSizeEj, u32, unsigned int mip)
    DECL_THISCALL_TAIL(GetMipSize, mip)

    // Member values
    u16           nameHash;
    u16           format;
    u16           width;
    u16           height : 15;
    u16           hasMipChain : 1;
DECL_CLASS_END()

DECL_CLASS(TextureListingContainer)
    TextureListing  listing;
    void           *data;
    unsigned int    dataSize;
    bool            ownsData;
DECL_CLASS_END()

DECL_CLASS_VTABLE(TextureDatabase)
    // Member functions
    DECL_THISCALL_HEAD(LoadEntry, _ZN15TextureDatabase9LoadEntryEPcb, void, char *line, bool hashName)
    DECL_THISCALL_TAIL(LoadEntry, line, hashName)

    DECL_THISCALL_HEAD(LoadEntries, _ZN15TextureDatabase11LoadEntriesEbb, bool, bool hashNames, bool fromBackup)
    DECL_THISCALL_TAIL(LoadEntries, hashNames, fromBackup)

    DECL_THISCALL_HEAD(LoadDataFile, _ZN15TextureDatabase12LoadDataFileEPKcR8TDBArrayI23TextureListingContainerE, bool,
        const char *filename, TDBArray<TextureListingContainer> &intoArray)
    DECL_THISCALL_TAIL(LoadDataFile, filename, intoArray)

    DECL_THISCALL_HEAD(LoadThumbs, _ZN15TextureDatabase10LoadThumbsE21TextureDatabaseFormatb, bool, TextureDatabaseFormat forFormat, bool setEntries)
    DECL_THISCALL_TAIL(LoadThumbs, forFormat, setEntries)

    DECL_THISCALL_HEAD(GetPNGFilename, _ZN15TextureDatabase14GetPNGFilenameEPcPKc, void, char *pngBuffer, const char *entryName)
    DECL_THISCALL_TAIL(GetPNGFilename, pngBuffer, entryName)

    DECL_THISCALL_HEAD(LoadDataOffsets, _ZN15TextureDatabase15LoadDataOffsetsE21TextureDatabaseFormatR8TDBArrayIjERPvb, bool,
        TextureDatabaseFormat forFormat, TDBArray<unsigned int> &offsets, void* &filePointer, bool createTOC)
    DECL_THISCALL_TAIL(LoadDataOffsets, forFormat, offsets, filePointer, createTOC)

    // Member values
    const char                       *name;
    TDBArray<TextureCategory>         categories;
    TDBArray<TextureDatabaseEntry>    entries;
    TDBArray<TextureListingContainer> thumbs[6];
    TDBArray<void *>                  toFree;
    TextureDatabaseFormat             loadedFormat;
DECL_CLASS_END()

DECL_CLASS_BASED(TextureDatabaseRuntime, TextureDatabase)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(UpdateStreaming, _ZN22TextureDatabaseRuntime15UpdateStreamingEfb, void, float deltaTime, bool flush);
    DECL_FASTCALL_SIMPLE(Register, _ZN22TextureDatabaseRuntime8RegisterEPS_, void, TextureDatabaseRuntime *toRegister);
    DECL_FASTCALL_SIMPLE(Unregister, _ZN22TextureDatabaseRuntime10UnregisterEPS_, void, TextureDatabaseRuntime *toUnregister);
    DECL_FASTCALL_SIMPLE(GetTexture, _ZN22TextureDatabaseRuntime10GetTextureEPKc, RwTexture*, const char *name);
    DECL_FASTCALL_SIMPLE(GetDatabaseFor, _ZN22TextureDatabaseRuntime14GetDatabaseForEP20TextureDatabaseEntryPj, TextureDatabaseRuntime*,
        TextureDatabaseEntry *entry, unsigned int *intoIndex);
    DECL_FASTCALL_SIMPLE(RenderingTextureEntry, _ZN22TextureDatabaseRuntime21RenderingTextureEntryEP20TextureDatabaseEntry, void, TextureDatabaseEntry *entry);
    DECL_FASTCALL_SIMPLE(CanUnloadTextureEntry, _ZN22TextureDatabaseRuntime21CanUnloadTextureEntryEP20TextureDatabaseEntry, void, TextureDatabaseEntry *entry);
    DECL_FASTCALL_SIMPLE(SetWriteMode, _ZN22TextureDatabaseRuntime12SetWriteModeEb, void, bool withValue);
    DECL_FASTCALL_SIMPLE(Load, _ZN22TextureDatabaseRuntime4LoadEPKcb21TextureDatabaseFormat, TextureDatabaseRuntime*,
        const char *withName, bool fullyLoad, TextureDatabaseFormat forcedFormat);
    DECL_FASTCALL_SIMPLE(GetDatabase, _ZN22TextureDatabaseRuntime11GetDatabaseEPKc, TextureDatabaseRuntime*, const char *withName);
    DECL_FASTCALL_SIMPLE(ListOverrun, _ZN22TextureDatabaseRuntime11ListOverrunEv, void);

    // Member functions
    DECL_THISCALL_HEAD(GetEntry, _ZN22TextureDatabaseRuntime8GetEntryEPKcRb, int, const char *name, bool *hasSibling)
    DECL_THISCALL_TAIL(GetEntry, name, hasSibling)

    DECL_THISCALL_HEAD(GetRWTexture, _ZN22TextureDatabaseRuntime12GetRWTextureEi, RwTexture*, int entryNum)
    DECL_THISCALL_TAIL(GetRWTexture, entryNum)
    
    DECL_THISCALL_HEAD(LoadFullTexture, _ZN22TextureDatabaseRuntime15LoadFullTextureEj, u32, unsigned int entryIndex)
    DECL_THISCALL_TAIL(LoadFullTexture, entryIndex)
    
    DECL_THISCALL_HEAD(StreamFullTexture, _ZN22TextureDatabaseRuntime17StreamFullTextureEj, void, unsigned int entryIndex)
    DECL_THISCALL_TAIL(StreamFullTexture, entryIndex)
    
    DECL_THISCALL_HEAD(CancelDeletion, _ZN22TextureDatabaseRuntime14CancelDeletionEj, void, unsigned int index)
    DECL_THISCALL_TAIL(CancelDeletion, index)
    
    DECL_THISCALL_SIMPLE(FullyLoad, _ZN22TextureDatabaseRuntime9FullyLoadEv, void);
    
    DECL_THISCALL_HEAD(DeleteTextures, _ZN22TextureDatabaseRuntime14DeleteTexturesEj, void, unsigned int toDelete)
    DECL_THISCALL_TAIL(DeleteTextures, toDelete)
    
    DECL_THISCALL_HEAD(UpdateTextureStreaming, _ZN22TextureDatabaseRuntime22UpdateTextureStreamingEjj, u32, unsigned int toStream, unsigned int priorityClass)
    DECL_THISCALL_TAIL(UpdateTextureStreaming, toStream, priorityClass)
    
    DECL_THISCALL_SIMPLE(MarkTexturesAsUnrendered, _ZN22TextureDatabaseRuntime24MarkTexturesAsUnrenderedEv, void);
    
    DECL_THISCALL_HEAD(SetAsRendered, _ZN22TextureDatabaseRuntime13SetAsRenderedEj, void, unsigned int index)
    DECL_THISCALL_TAIL(SetAsRendered, index)

    DECL_THISCALL_HEAD(StopStreaming, _ZN22TextureDatabaseRuntime13StopStreamingEj, void, unsigned int index)
    DECL_THISCALL_TAIL(StopStreaming, index)

    DECL_THISCALL_HEAD(QueueForDeletion, _ZN22TextureDatabaseRuntime16QueueForDeletionEj, void, unsigned int index)
    DECL_THISCALL_TAIL(QueueForDeletion, index)
    
    DECL_THISCALL_HEAD(SortEntries, _ZN22TextureDatabaseRuntime11SortEntriesEb, void, bool justEntries)
    DECL_THISCALL_TAIL(SortEntries, justEntries)
    
    DECL_THISCALL_SIMPLE(ReloadEntries, _ZN22TextureDatabaseRuntime13ReloadEntriesEv, void);
    DECL_THISCALL_SIMPLE(Unload, _ZN22TextureDatabaseRuntime6UnloadEv, void);

    // Member values
    TDBArray<unsigned int> priorityStreamingQueue;
    TDBArray<unsigned int> renderedStreamingQueue;
    TDBArray<unsigned int> unrenderedStreamingQueue;
    TDBArray<unsigned int> deletionQueue;
    void                  *streamFile; // OSFile
    TDBArray<unsigned int> fullDataOffsets;
    TDBArray<unsigned int> hashOffsets;
    unsigned int           numHashes;
DECL_CLASS_END()
CHECKSIZE(TextureDatabaseRuntime, 0xC8, 0x118);

#endif // __AML_PSDK_SATEXTUREDATABASE_H
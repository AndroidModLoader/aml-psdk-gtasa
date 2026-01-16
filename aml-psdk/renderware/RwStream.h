#ifndef __AML_PSDK_RWSTREAM_H
#define __AML_PSDK_RWSTREAM_H

#include "RwVector.h"

enum RwStreamType : RwInt32
{
    rwNASTREAM = 0x0,
    rwSTREAMFILE = 0x1,
    rwSTREAMFILENAME = 0x2,
    rwSTREAMMEMORY = 0x3,
    rwSTREAMCUSTOM = 0x4,
};

enum RwStreamAccessType : RwInt32
{
    rwNASTREAMACCESS = 0x0,
    rwSTREAMREAD = 0x1,
    rwSTREAMWRITE = 0x2,
    rwSTREAMAPPEND = 0x3,
};

typedef RwBool (*rwCustomStreamFnClose)(void *);
typedef RwUInt32 (*rwCustomStreamFnRead)(void *, void *, RwUInt32);
typedef RwBool (*rwCustomStreamFnWrite)(void *, const void *, RwUInt32);
typedef RwBool (*rwCustomStreamFnSkip)(void *, RwUInt32);
struct RwStreamMemory
{
    RwUInt32 position;
    RwUInt32 nSize;
    RwUInt8 *memBlock;
};
union RwStreamFile
{
    void *fpFile;
    const void *constfpFile;
};
struct RwStreamCustom
{
    rwCustomStreamFnClose sfnclose;
    rwCustomStreamFnRead sfnread;
    rwCustomStreamFnWrite sfnwrite;
    rwCustomStreamFnSkip sfnskip;
    void *data;
};
union RwStreamUnion
{
    RwStreamMemory memory;
    RwStreamFile file;
    RwStreamCustom custom;
};

struct RwChunkHeaderInfo
{
    RwUInt32 type;
    RwUInt32 length;
    RwUInt32 version;
    RwUInt32 buildNum;
    RwBool isComplex;
};



struct RwStream
{
    RwStreamType type;
    RwStreamAccessType accessType;
    RwInt32 position;
    RwStreamUnion Type;
    RwBool rwOwned;
};



inline auto RwStreamClose = GetMainLibrarySymbol<RwBool(*)(RwStream *stream, void *pData)>("_Z13RwStreamCloseP8RwStreamPv");
inline auto RwStreamFindChunk = GetMainLibrarySymbol<RwBool(*)(RwStream *stream, RwUInt32 type, RwUInt32 *lengthOut, RwUInt32 *versionOut)>("_Z17RwStreamFindChunkP8RwStreamjPjS1_");
inline auto RwStreamOpen = GetMainLibrarySymbol<RwStream*(*)(RwStreamType type, RwStreamAccessType accessType, const void *pData)>("_Z12RwStreamOpen12RwStreamType18RwStreamAccessTypePKv");
inline auto RwStreamRead = GetMainLibrarySymbol<RwUInt32(*)(RwStream *stream, void *buffer, RwUInt32 length)>("_Z12RwStreamReadP8RwStreamPvj");
inline auto RwStreamReadChunkHeaderInfo = GetMainLibrarySymbol<RwStream*(*)(RwStream *stream, RwChunkHeaderInfo *chunkHeaderInfo)>("_Z27RwStreamReadChunkHeaderInfoP8RwStreamP17RwChunkHeaderInfo");
inline auto RwStreamReadInt16 = GetMainLibrarySymbol<RwStream*(*)(RwStream *stream, RwInt16 *ints, RwUInt32 numBytes)>("_Z17RwStreamReadInt16P8RwStreamPsj");
inline auto RwStreamReadInt32 = GetMainLibrarySymbol<RwStream*(*)(RwStream *stream, RwInt32 *ints, RwUInt32 numBytes)>("_Z17RwStreamReadInt32P8RwStreamPij");
inline auto RwStreamReadReal = GetMainLibrarySymbol<RwStream*(*)(RwStream *stream, RwReal *reals, RwUInt32 numBytes)>("_Z16RwStreamReadRealP8RwStreamPfj");
inline auto RwStreamSetFreeListCreateParams = GetMainLibrarySymbol<void(*)(RwInt32 blockSize, RwInt32 numBlocksToPrealloc)>("_Z31RwStreamSetFreeListCreateParamsii");
inline auto RwStreamSkip = GetMainLibrarySymbol<void(*)(RwStream *stream, RwUInt32 offset)>("_Z12RwStreamSkipP8RwStreamj");
inline auto RwStreamWrite = GetMainLibrarySymbol<RwStream*(*)(RwStream *stream, const void *buffer, RwUInt32 length)>("_Z13RwStreamWriteP8RwStreamPKvj");
inline auto RwStreamWriteInt16 = GetMainLibrarySymbol<RwStream*(*)(RwStream *stream, const RwInt16 *ints, RwUInt32 numBytes)>("_Z18RwStreamWriteInt16P8RwStreamPKsj");
inline auto RwStreamWriteInt32 = GetMainLibrarySymbol<RwStream*(*)(RwStream *stream, const RwInt32 *ints, RwUInt32 numBytes)>("_Z18RwStreamWriteInt32P8RwStreamPKij");
inline auto RwStreamWriteReal = GetMainLibrarySymbol<RwStream*(*)(RwStream *stream, const RwReal *reals, RwUInt32 numBytes)>("_Z17RwStreamWriteRealP8RwStreamPKfj");

#endif // __AML_PSDK_RWSTREAM_H
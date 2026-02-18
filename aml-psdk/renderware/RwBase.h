#ifndef __AML_PSDK_RWBASE_H
#define __AML_PSDK_RWBASE_H

#define RwInt32 i32
#define RwUInt32 u32
#define RwInt16 i16
#define RwUInt16 u16
#define RwInt8 i8
#define RwUInt8 u8
#define RwBool i32
#define RwReal float
#define RwChar char

struct RwRect
{
    RwInt32 x;
    RwInt32 y;
    RwInt32 w;
    RwInt32 h;
};


struct RwStream;

typedef void *(*RwPluginObjectConstructor)(void *, RwInt32, RwInt32);
typedef void *(*RwPluginObjectDestructor)(void *, RwInt32, RwInt32);
typedef void *(*RwPluginObjectCopy)(void *, const void *, RwInt32, RwInt32);
typedef void *(*RwPluginErrorStrCallBack)(void *);
typedef RwBool (*RwPluginDataChunkRightsCallBack)(void *, RwInt32, RwInt32, RwUInt32);
typedef RwBool (*RwPluginDataChunkAlwaysCallBack)(void *, RwInt32, RwInt32);
typedef RwInt32 (*RwPluginDataChunkGetSizeCallBack)(const void *, RwInt32, RwInt32);
typedef RwStream *(*RwPluginDataChunkWriteCallBack)(RwStream *, RwInt32, const void *, RwInt32, RwInt32);
typedef RwStream *(*RwPluginDataChunkReadCallBack)(RwStream *, RwInt32, void *, RwInt32, RwInt32);

#endif // __AML_PSDK_RWBASE_H
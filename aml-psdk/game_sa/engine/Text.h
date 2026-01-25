#ifndef __AML_PSDK_SATEXT_H
#define __AML_PSDK_SATEXT_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/GxtChar.h>

struct ChunkHeader
{
    char Type[4];
    u32  Size;
};

struct CText__TDat
{
    char* data;
    int size;
};
struct CText__TablEntry
{
    char name[8];
    int offset;
};
struct CText__Tabl
{
    CText__TablEntry data[200];
    short size;
    short __pad;
};
struct tGXT_VERSION_2_TKEY_item
{
    unsigned long int Position;		// TDAT + 8 offset
    unsigned long int KeyHash;
};
struct CText__TKey
{
    tGXT_VERSION_2_TKEY_item* data;
    short size;
};

DECL_CLASS(CText)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CText, _ZN5CTextC2Ev);
    DECL_DTORCALL(CText, _ZN5CTextD2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(LoadMissionPackText, _ZN5CText19LoadMissionPackTextEv, void);

    DECL_THISCALL_HEAD(GetUpperCase, _ZN5CText12GetUpperCaseEt, GxtChar, const GxtChar C)
    DECL_THISCALL_TAIL(GetUpperCase, C)

    DECL_THISCALL_HEAD(ReadChunkHeader, BYBIT(_ZN5CText15ReadChunkHeaderEP11ChunkHeaderjPjh, _ZN5CText15ReadChunkHeaderEP11ChunkHeaderyPjh), u8, ChunkHeader *pHead, uintptr_t FileId, u32 *pNumCharsRead, u8 LoadFromMemoryCard)
    DECL_THISCALL_TAIL(ReadChunkHeader, pHead, FileId, pNumCharsRead, LoadFromMemoryCard)

    DECL_THISCALL_HEAD(Load, _ZN5CText4LoadEh, void, u8 bKeepMissionText)
    DECL_THISCALL_TAIL(Load, bKeepMissionText)

    DECL_THISCALL_HEAD(Unload, _ZN5CText6UnloadEh, void, u8 bKeepMissionText)
    DECL_THISCALL_TAIL(Unload, bKeepMissionText)

    DECL_THISCALL_HEAD(Get, _ZN5CText3GetEPKc, GxtChar*, const char *Ident)
    DECL_THISCALL_TAIL(Get, Ident)

    DECL_THISCALL_HEAD(GetNameOfLoadedMissionText, _ZN5CText26GetNameOfLoadedMissionTextEPc, void, char *pStringToFill)
    DECL_THISCALL_TAIL(GetNameOfLoadedMissionText, pStringToFill)

    DECL_THISCALL_HEAD(LoadMissionText, _ZN5CText15LoadMissionTextEPc, void, char *pMissionTextStem)
    DECL_THISCALL_TAIL(LoadMissionText, pMissionTextStem)

    // Member values
    CText__TKey tkeyMain;
    CText__TDat tdatMain;
    CText__TKey tkeyMission;
    CText__TDat tdatMission;
    char        encoding;
    char        haveTabl;
    char        cderrorInitialized;
    char        missionTableLoaded;
    char        missionTableName[8];
    char        cderrorText[256];
    CText__Tabl tabl;
DECL_CLASS_END()
CHECKSIZE(CText, 0xA90, 0xAB0);

DECL_OBJECT_PLT_GLOBAL(CText, TheText, BYBIT(0x6770B4, 0x84C1A0) );
#define TheText TheText()

#endif // __AML_PSDK_SATEXT_H
#ifndef __AML_PSDK_SAFILEMGR_H
#define __AML_PSDK_SAFILEMGR_H

#include <aml-psdk/game_sa/plugin.h>

#define DIRNAMELENGTH 128

DECL_CLASS(CFileMgr)
    // Functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN8CFileMgr10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(ChangeDir, _ZN8CFileMgr9ChangeDirEPKc, void, const char *pDirName);
    DECL_FASTCALL_SIMPLE(SetDir, _ZN8CFileMgr6SetDirEPKc, void, const char *pDirName);
    DECL_FASTCALL_SIMPLE(SetDirMyDocuments, _ZN8CFileMgr17SetDirMyDocumentsEv, void);
    DECL_FASTCALL_SIMPLE(LoadFile, _ZN8CFileMgr8LoadFileEPKcPhiS1_, FILESTREAM, const char *pFilename, u8 *pBuffer, i32 bufferSize, const char *pReadString);
    DECL_FASTCALL_SIMPLE(OpenFile, _ZN8CFileMgr8OpenFileEPKcS1_, FILESTREAM, const char *pFilename, const char *pReadString);
    DECL_FASTCALL_SIMPLE(OpenFileForWriting, _ZN8CFileMgr18OpenFileForWritingEPKc, FILESTREAM, const char *pFilename);
    DECL_FASTCALL_SIMPLE(OpenFileForAppending, _ZN8CFileMgr20OpenFileForAppendingEPKc, FILESTREAM, const char *pFilename);
    #ifdef AML64
        DECL_FASTCALL_SIMPLE(Read_old, _ZN8CFileMgr8Read_oldEyPci, i32, FILESTREAM id, char *pData, i32 size);
        DECL_FASTCALL_SIMPLE(ReadBytes, _ZN8CFileMgr9ReadBytesEyPci, i32, FILESTREAM id, char *pData, i32 size);
        DECL_FASTCALL_SIMPLE(Write, _ZN8CFileMgr5WriteEyPci, i32, FILESTREAM id, char *pData, i32 size);
        DECL_FASTCALL_SIMPLE(Seek, _ZN8CFileMgr4SeekEyii, bool, FILESTREAM id, i32 offset, i32 origin);
        DECL_FASTCALL_SIMPLE(ReadLine, _ZN8CFileMgr8ReadLineEyPci, bool, FILESTREAM id, char *pLine, i32 maxLen);
        DECL_FASTCALL_SIMPLE(CloseFile, _ZN8CFileMgr9CloseFileEy, i32, FILESTREAM id);
        DECL_FASTCALL_SIMPLE(GetTotalSize, _ZN8CFileMgr12GetTotalSizeEy, i32, FILESTREAM id);
        DECL_FASTCALL_SIMPLE(Tell, _ZN8CFileMgr4TellEy, i32, FILESTREAM id);
        DECL_FASTCALL_SIMPLE(GetErrorReadWrite, _ZN8CFileMgr17GetErrorReadWriteEy, i32, FILESTREAM id);
    #else
        DECL_FASTCALL_SIMPLE(Read_old, _ZN8CFileMgr8Read_oldEjPci, i32, FILESTREAM id, char *pData, i32 size);
        DECL_FASTCALL_SIMPLE(ReadBytes, _ZN8CFileMgr9ReadBytesEjPci, i32, FILESTREAM id, char *pData, i32 size);
        DECL_FASTCALL_SIMPLE(Write, _ZN8CFileMgr5WriteEjPci, i32, FILESTREAM id, char *pData, i32 size);
        DECL_FASTCALL_SIMPLE(Seek, _ZN8CFileMgr4SeekEjii, bool, FILESTREAM id, i32 offset, i32 origin);
        DECL_FASTCALL_SIMPLE(ReadLine, _ZN8CFileMgr8ReadLineEjPci, bool, FILESTREAM id, char *pLine, i32 maxLen);
        DECL_FASTCALL_SIMPLE(CloseFile, _ZN8CFileMgr9CloseFileEj, i32, FILESTREAM id);
        DECL_FASTCALL_SIMPLE(GetTotalSize, _ZN8CFileMgr12GetTotalSizeEj, i32, FILESTREAM id);
        DECL_FASTCALL_SIMPLE(Tell, _ZN8CFileMgr4TellEj, i32, FILESTREAM id);
        DECL_FASTCALL_SIMPLE(GetErrorReadWrite, _ZN8CFileMgr17GetErrorReadWriteEj, i32, FILESTREAM id);
    #endif

    // STATIC Values
    DECL_VALUE_PLT_I32(fileDataArea, BYBIT(0x676918, 0x84B280));
    DECL_VALUE_PLT_CHAR(ms_rootDirName, BYBIT(0x675F54, 0x849F18));
    DECL_VALUE_PLT_CHAR(ms_dirName, BYBIT(0x677C90, 0x84D940));
    DECL_VALUE_PLT_I32(ms_dualLayer, BYBIT(0x6790DC, 0x8501E0));
    DECL_VALUE_PLT_U32(ms_layerStart, BYBIT(0x679F0C, 0x851E28));
DECL_CLASS_END()
DECL_OBJECT_ARRAY_PLT_GLOBAL(char, StorageRootBuffer, BYBIT(0x6796A0, 0x850D50) );

#define fileDataArea fileDataArea()
#define ms_rootDirName ms_rootDirName()
#define ms_dirName ms_dirName()
#define ms_dualLayer ms_dualLayer()
#define ms_layerStart ms_layerStart()
#define StorageRootBuffer StorageRootBuffer()

#endif // __AML_PSDK_SAFILEMGR_H
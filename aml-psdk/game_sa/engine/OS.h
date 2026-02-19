#ifndef __AML_PSDK_SAOPERATINGSYSTEM_H
#define __AML_PSDK_SAOPERATINGSYSTEM_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/base/Lists.h>
#include <jni.h>

#define TOUCH_UNPRESS 1
#define TOUCH_PRESS 2
#define TOUCH_MOVE 3

enum OSFileArchive : i32
{
    OSFA_Application = 0x0,
    OSFA_DataMain = 0x1,
    OSFA_DataPatch = 0x2,
};
enum OSFileDataArea : i32
{
    OSFDA_Storage = 0x0,
    OSFDA_User = 0x1,
    OSFDA_MAX = 0x2,
};

enum OSKeyboardKey : i32
{
    KK_ESCAPE = 0x0,
    KK_F1 = 0x1,
    KK_F2 = 0x2,
    KK_F3 = 0x3,
    KK_F4 = 0x4,
    KK_F5 = 0x5,
    KK_F6 = 0x6,
    KK_F7 = 0x7,
    KK_F8 = 0x8,
    KK_F9 = 0x9,
    KK_F10 = 0xA,
    KK_F11 = 0xB,
    KK_F12 = 0xC,
    KK_TILDE = 0xD,
    KK_0 = 0xE,
    KK_1 = 0xF,
    KK_2 = 0x10,
    KK_3 = 0x11,
    KK_4 = 0x12,
    KK_5 = 0x13,
    KK_6 = 0x14,
    KK_7 = 0x15,
    KK_8 = 0x16,
    KK_9 = 0x17,
    KK_MINUS = 0x18,
    KK_EQUALS = 0x19,
    KK_BACKSPACE = 0x1A,
    KK_TAB = 0x1B,
    KK_Q = 0x1C,
    KK_W = 0x1D,
    KK_E = 0x1E,
    KK_R = 0x1F,
    KK_T = 0x20,
    KK_Y = 0x21,
    KK_U = 0x22,
    KK_I = 0x23,
    KK_O = 0x24,
    KK_P = 0x25,
    KK_LEFTBRACKET = 0x26,
    KK_RIGHTBRACKET = 0x27,
    KK_BACKSLASH = 0x28,
    KK_CAPSLOCK = 0x29,
    KK_A = 0x2A,
    KK_S = 0x2B,
    KK_D = 0x2C,
    KK_F = 0x2D,
    KK_G = 0x2E,
    KK_H = 0x2F,
    KK_J = 0x30,
    KK_K = 0x31,
    KK_L = 0x32,
    KK_SEMICOLON = 0x33,
    KK_APOSTROPHE = 0x34,
    KK_ENTER = 0x35,
    KK_LEFTSHIFT = 0x36,
    KK_Z = 0x37,
    KK_X = 0x38,
    KK_C = 0x39,
    KK_V = 0x3A,
    KK_B = 0x3B,
    KK_N = 0x3C,
    KK_M = 0x3D,
    KK_COMMA = 0x3E,
    KK_PERIOD = 0x3F,
    KK_FORWARDSLASH = 0x40,
    KK_RIGHTSHIFT = 0x41,
    KK_LEFTCONTROL = 0x42,
    KK_LEFTALT = 0x43,
    KK_SPACE = 0x44,
    KK_RIGHTALT = 0x45,
    KK_RIGHTCONTROL = 0x46,
    KK_PRINTSCREEN = 0x47,
    KK_PAUSE = 0x48,
    KK_INSERT = 0x49,
    KK_DELETE = 0x4A,
    KK_HOME = 0x4B,
    KK_END = 0x4C,
    KK_PAGEUP = 0x4D,
    KK_PAGEDOWN = 0x4E,
    KK_ARROWUP = 0x4F,
    KK_ARROWDOWN = 0x50,
    KK_ARROWLEFT = 0x51,
    KK_ARROWRIGHT = 0x52,
    KK_NPDIVIDE = 0x53,
    KK_NPMULTIPLY = 0x54,
    KK_NPMINUS = 0x55,
    KK_NP7 = 0x56,
    KK_NP8 = 0x57,
    KK_NP9 = 0x58,
    KK_PLUS = 0x59,
    KK_NP4 = 0x5A,
    KK_NP5 = 0x5B,
    KK_NP6 = 0x5C,
    KK_NP1 = 0x5D,
    KK_NP2 = 0x5E,
    KK_NP3 = 0x5F,
    KK_NP0 = 0x60,
    KK_NPPERIOD = 0x61,
    KK_AT = 0x62,
    KK_BACKSPACE1 = 0x63,
    KK_MAX = 0x64,
};

enum OSEventType : i32
{
    OSET_RequestExit = 0x0,
    OSET_KeyboardDown = 0x1,
    OSET_KeyboardUp = 0x2,
    OSET_PointerMove = 0x3,
    OSET_PointerButton = 0x4,
    OSET_GamepadConnection = 0x5,
    OSET_GamepadButtonDown = 0x6,
    OSET_GamepadButtonUp = 0x7,
    OSET_Pause = 0x8,
    OSET_Resume = 0x9,
    OSET_KeyboardSoft = 0xA,
    OSET_BillingChange = 0xB,
    OSET_GameServiceChange = 0xC,
    OSET_GameServiceSignInFailed = 0xD,
    OSET_GameServiceAchievementsReady = 0xE,
    OSET_GameServiceCloudLoadReady = 0xF,
    OSET_GameServiceCloudSaveReady = 0x10,
    OSET_GameServiceSnapshotCountLoaded = 0x11,
    OSET_GameServiceSnapshotLoading = 0x12,
    OSET_GameServiceSnapshotSelected = 0x13,
    OSET_LowMemory = 0x14,
    OSET_Notification = 0x15,
    OSET_Crash = 0x16,
    OSET_PointerWheel = 0x17,
    OSET_DragFile = 0x18,
    OSET_NetworkChanged = 0x19,
    OSET_HandoffOccurred = 0x1A,
    OSET_HandoffReceived = 0x1B,
    OSET_Headphones = 0x1C,
    OSET_SystemUIShowing = 0x1D,
    OSET_SystemUIClosed = 0x1E,
    OSET_MAX = 0x1F,
};

enum OSFileError : i32
{
    OSFE_NoError = 0x0,
    OSFE_FileNotFound = 0x1,
    OSFE_EndOfFile = 0x2,
    OSFE_UnknownError = 0x3,
    OSFE_IOPending = 0x4,
    OSFE_IOStillInProgress = 0x5,
    OSFE_MAX = 0x6,
};

enum OSFileAccessType : i32
{
    OSFAT_Read = 0x0,
    OSFAT_Write = 0x1,
    OSFAT_ReadWrite = 0x2,
    OSFAT_ReadAsync = 0x3,
    OSFAT_MAX = 0x4,
};

enum OSGamepadType : i32
{
    OSGT_Xbox360 = 0x0,
    OSGT_XperiaPlay = 0x1,
    OSGT_60beat = 0x2,
    OSGT_Gamestop = 0x3,
    OSGT_Moga = 0x4,
    OSGT_Generic = 0x5,
    OSGT_Nyko = 0x6,
    OSGT_MogaPro = 0x7,
    OSGT_PS3 = 0x8,
    OSGT_IOSExtended = 0x9,
    OSGT_IOSSimple = 0xA,
    OSGT_IOSMicro = 0xB,
    OSGT_AmazonRemote = 0xC,
    OSGT_AmazonGamepad = 0xD,
    OSGT_AndroidTV = 0xE,
};

enum OSLanguageCode : i32
{
    OSLC_English_US = 0x0,
    OSLC_English_UK = 0x1,
    OSLC_English_Australia = 0x2,
    OSLC_English_Other = 0x3,
    OSLC_Spanish_LatAm = 0x4,
    OSLC_Spanish_Spain = 0x5,
    OSLC_French_Canada = 0x6,
    OSLC_French_France = 0x7,
    OSLC_German = 0x8,
    OSLC_Portuguese = 0x9,
    OSLC_Italian = 0xA,
    OSLC_Russian = 0xB,
    OSLC_Chinese = 0xC,
    OSLC_Arabic = 0xD,
    OSLC_Japanese = 0xE,
    OSLC_Korean = 0xF,
    OSLC_Polish = 0x10,
    OSLC_Cyrillic = 0x11,
    OSLC_Swedish = 0x12,
    OSLC_Norwegian = 0x13,
    OSLC_Unknown = 0x14,
};

enum OSPointingDevice : i32
{
    OSPD_Invalid = -0x1,
    OSPD_Mouse = 0x1,
    OSPD_TouchScreen = 0x2,
};

enum OSDeviceChip : i32
{
    OSDC_A3 = 0x0,
    OSDC_A4 = 0x1,
    OSDC_A5 = 0x2,
    OSDC_A5X = 0x3,
    OSDC_A6 = 0x4,
    OSDC_A6X = 0x5,
    OSDC_A7 = 0x6,
    OSDC_A8 = 0x7,
    OSDC_A8X = 0x8,
    OSDC_A9 = 0x9,
    OSDC_A9X = 0xA,
    OSDC_A10 = 0xB,
    OSDC_Tegra2 = 0xC,
    OSDC_Tegra3 = 0xD,
    OSDC_Tegra4 = 0xE,
    OSDC_TegraK1 = 0xF,
    OSDC_TegraX1 = 0x10,
    OSDC_AmazonFire = 0x11,
    OSDC_UnknownApple = 0x12,
    OSDC_UnknownAndroid = 0x13,
};

enum OSDefinedDevice : i32
{
    OSDD_iPhone3GS = 0x0,
    OSDD_iPhone4 = 0x1,
    OSDD_iPhone4S = 0x2,
    OSDD_iPhone5 = 0x3,
    OSDD_iPhone5S = 0x4,
    OSDD_iPhone6 = 0x5,
    OSDD_iPhone6S = 0x6,
    OSDD_iPhone7 = 0x7,
    OSDD_iPod4 = 0x8,
    OSDD_iPod5 = 0x9,
    OSDD_iPod6 = 0xA,
    OSDD_iPadGen1 = 0xB,
    OSDD_iPadGen2 = 0xC,
    OSDD_iPadGen3 = 0xD,
    OSDD_iPadGen4 = 0xE,
    OSDD_iPadAir = 0xF,
    OSDD_iPadAir2 = 0x10,
    OSDD_iPadMini2 = 0x11,
    OSDD_iPadMini3 = 0x12,
    OSDD_iPadMini4 = 0x13,
    OSDD_iPadProBig = 0x14,
    OSDD_iPadProSmall = 0x15,
    OSDD_xPeriaPlay = 0x16,
    OSDD_KindleFire = 0x17,
    OSDD_FireTV = 0x18,
    OSDD_FirePhone = 0x19,
    OSDD_UndefinedIOS = 0x1A,
    OSDD_UndefinedAndroid = 0x1B,
};

enum OSDeviceForm : i32
{
    OSDF_Tablet = 0x0,
    OSDF_Phone = 0x1,
    OSDF_MAX = 0x2,
};

enum OSThreadPriority : i32
{
    OSTP_LOW = 0x0,
    OSTP_NORMAL = 0x1,
    OSTP_HIGH = 0x2,
    OSTP_MAX = 0x3,
};

enum OSPointerState : i32
{
    OSPS_ButtonInvalid = -0x1,
    OSPS_ButtonReleased = 0x0,
    OSPS_ButtonUp = 0x1,
    OSPS_ButtonPressed = 0x2,
    OSPS_ButtonDown = 0x3,
};

struct ButtonStateChange
{
    int            buttonIndex;
    OSPointerState state;
    int            x;
    int            y;
    double         timeStamp;
    float          force;
};


template<unsigned int num>
struct ButtonContainer
{
    OSPointerState curState[num];
    int curX;
    int curY;
    float curForce;
    int systemX;
    int systemY;
    float systemForce;
    OSArray<ButtonStateChange> pendingChanges;
    float doubleClickDelay;
    bool doubleClicked[num];
    double lastUp[num];
    int lastUpX[num];
    int lastUpY[num];
    float AccumulatedWheelDelta;
    float WheelDelta;
};

struct DateTime
{
    int month, day, year, hour, minute, second, centisecond;
};

struct AND_TouchPoint
{
    int x;
    int y;
    OSPointerState state;
    int clickIndex;
    float clickTime[2];
    int currentUpdateCount;
};


typedef void *OSFile;
typedef i64 OSDate;
typedef void *OSMutex;
typedef void *OSSemaphore;
typedef void *OSThreadHandle;
typedef unsigned int (*OSThreadFunction)(void *);



DECL_FASTCALL_SIMPLE_GLO(AND_DeviceIsTV, _Z14AND_DeviceIsTVv, bool);
DECL_FASTCALL_SIMPLE_GLO(AND_DeviceLocale, _Z16AND_DeviceLocalev, int);
DECL_FASTCALL_SIMPLE_GLO(AND_DeviceType, _Z14AND_DeviceTypev, int);
DECL_FASTCALL_SIMPLE_GLO(AND_FileCleanup, _Z15AND_FileCleanupv, void);
DECL_FASTCALL_SIMPLE_GLO(AND_FileDelete, _Z14AND_FileDeletePKc, int, const char *filename);
DECL_FASTCALL_SIMPLE_GLO(AND_FileGetArchiveName, _Z22AND_FileGetArchiveName13OSFileArchive, char*, OSFileArchive type);
DECL_FASTCALL_SIMPLE_GLO(AND_FileInitialize, _Z18AND_FileInitializev, void);
DECL_FASTCALL_SIMPLE_GLO(AND_FileRename, _Z14AND_FileRenamePKcS0_i, int, const char *oldFilename, const char *newFilename, int overWrite);
DECL_FASTCALL_SIMPLE_GLO(AND_FileUpdate, _Z14AND_FileUpdated, void, double deltaTime);
DECL_FASTCALL_SIMPLE_GLO(AND_GamepadUpdateAccelerometer, _Z30AND_GamepadUpdateAccelerometerfff, void, float x, float y, float z);
DECL_FASTCALL_SIMPLE_GLO(AND_GetAndroidBuildinfo, _Z23AND_GetAndroidBuildinfoi, const char*, int index);
DECL_FASTCALL_SIMPLE_GLO(AND_GetAppId, _Z12AND_GetAppIdv, const char*);
DECL_FASTCALL_SIMPLE_GLO(AND_GetDeviceID, _Z15AND_GetDeviceIDv, const char*);
DECL_FASTCALL_SIMPLE_GLO(AND_GetDeviceInfo, _Z17AND_GetDeviceInfoi, int, int index);
DECL_FASTCALL_SIMPLE_GLO(AND_GetJNI, _Z10AND_GetJNIv, void*);
DECL_FASTCALL_SIMPLE_GLO(AND_GetJNIFunc, _Z14AND_GetJNIFuncv, void*);
DECL_FASTCALL_SIMPLE_GLO(AND_GetObj, _Z10AND_GetObjv, void*);
DECL_FASTCALL_SIMPLE_GLO(AND_GetSpecialBuildType, _Z23AND_GetSpecialBuildTypev, int);
DECL_FASTCALL_SIMPLE_GLO(AND_IsAppInstalled, _Z18AND_IsAppInstalledPKc, bool, const char *app);
DECL_FASTCALL_SIMPLE_GLO(AND_KeyboardEvent, _Z17AND_KeyboardEventbiib, void, bool pressed, int keyCode, int metaState, bool forceHandle);
DECL_FASTCALL_SIMPLE_GLO(AND_KeyboardGetChar, _Z19AND_KeyboardGetChar13OSKeyboardKeyi, u32, OSKeyboardKey key, int setUpper);
DECL_FASTCALL_SIMPLE_GLO(AND_KeyboardSoftClosed, _Z22AND_KeyboardSoftClosedv, void);
DECL_FASTCALL_SIMPLE_GLO(AND_OpenLink, _Z12AND_OpenLinkPKc, void, const char *link);
DECL_FASTCALL_SIMPLE_GLO(AND_ScreenSetWakeLock, _Z21AND_ScreenSetWakeLockb, void, bool enabled);
DECL_FASTCALL_SIMPLE_GLO(AND_TouchEvent, _Z14AND_TouchEventiiii, void, int actionType, int trackNum, int x, int y);
DECL_FASTCALL_SIMPLE_GLO(AND_VibratePhoneEffect, _Z22AND_VibratePhoneEffecti, void, int effect);

DECL_FASTCALL_SIMPLE_GLO(OS_ApplicationEvent, _Z19OS_ApplicationEvent11OSEventTypePv, void, OSEventType type, void *data);
DECL_FASTCALL_SIMPLE_GLO(OS_ApplicationInitialize, _Z24OS_ApplicationInitializeiPPKc, bool, int argc, const char **argv);
DECL_FASTCALL_SIMPLE_GLO(OS_ApplicationPreinit, _Z21OS_ApplicationPreinitv, void);
DECL_FASTCALL_SIMPLE_GLO(OS_ApplicationStartup, _Z21OS_ApplicationStartupiiiPPKc, bool, int width, int height, int argc, const char **argv);
DECL_FASTCALL_SIMPLE_GLO(OS_ApplicationTick, _Z18OS_ApplicationTickf, bool, float delta);
DECL_FASTCALL_SIMPLE_GLO(OS_ConvertUTF16toUTF8, _Z21OS_ConvertUTF16toUTF8PtPhi, int, u16 *utf16, u8 *utf8, int bufferLen);
DECL_FASTCALL_SIMPLE_GLO(OS_DebugBreak, _Z13OS_DebugBreakv, void);
DECL_FASTCALL_SIMPLE_GLO(OS_DebugOut, _Z11OS_DebugOutPKc, void, const char *str);
DECL_FASTCALL_SIMPLE_GLO(OS_DeviceIsTV, _Z13OS_DeviceIsTVv, bool);
DECL_FASTCALL_SIMPLE_GLO(OS_FileClose, _Z12OS_FileClosePv, OSFileError, OSFile file);
DECL_FASTCALL_SIMPLE_GLO(OS_FileDelete, _Z13OS_FileDelete14OSFileDataAreaPKc, OSFileError, OSFileDataArea area, const char *filename);
DECL_FASTCALL_SIMPLE_GLO(OS_FileFlush, _Z12OS_FileFlushPv, OSFileError, OSFile file);
DECL_FASTCALL_SIMPLE_GLO(OS_FileGetArchiveName, _Z21OS_FileGetArchiveName13OSFileArchive, char*, OSFileArchive type);
DECL_FASTCALL_SIMPLE_GLO(OS_FileGetDate, _Z14OS_FileGetDate14OSFileDataAreaPKc, OSDate, OSFileDataArea area, const char *filename);
DECL_FASTCALL_SIMPLE_GLO(OS_FileGetPosition, _Z18OS_FileGetPositionPv, int, OSFile file);
DECL_FASTCALL_SIMPLE_GLO(OS_FileGetState, _Z15OS_FileGetStatePv, OSFileError, OSFile file);
DECL_FASTCALL_SIMPLE_GLO(OS_FileListUserFiles, _Z20OS_FileListUserFilesv, const char**);
DECL_FASTCALL_SIMPLE_GLO(OS_FileOpen, _Z11OS_FileOpen14OSFileDataAreaPPvPKc16OSFileAccessType, OSFileError,
    OSFileDataArea area, OSFile *intoFile, const char *filename, OSFileAccessType access);
DECL_FASTCALL_SIMPLE_GLO(OS_FileRead, _Z11OS_FileReadPvS_i, OSFileError, OSFile file, void *buffer, int numBytes);
DECL_FASTCALL_SIMPLE_GLO(OS_FileRename, _Z13OS_FileRename14OSFileDataAreaPKcS1_b, OSFileError,
    OSFileDataArea area, const char *oldFilename, const char *newFilename, bool overWrite);
DECL_FASTCALL_SIMPLE_GLO(OS_FileSetAsyncReadMultiple, _Z27OS_FileSetAsyncReadMultiplei, void, int val);
DECL_FASTCALL_SIMPLE_GLO(OS_FileSetPosition, _Z18OS_FileSetPositionPvi, OSFileError, OSFile file, int position);
DECL_FASTCALL_SIMPLE_GLO(OS_FileSize, _Z11OS_FileSizePv, int, OSFile file);
DECL_FASTCALL_SIMPLE_GLO(OS_FileSubHandle, _Z16OS_FileSubHandlePvii, void, OSFile file, int offset, int length);
DECL_FASTCALL_SIMPLE_GLO(OS_FileWrite, _Z12OS_FileWritePvPKvi, OSFileError, OSFile file, const void *buffer, int numBytes);
DECL_FASTCALL_SIMPLE_GLO(OS_GamepadAccelerometer, _Z23OS_GamepadAccelerometerPfS_S_, void, float *x, float *y, float *z);
DECL_FASTCALL_SIMPLE_GLO(OS_GamepadAxis, _Z14OS_GamepadAxisjj, float, unsigned int padId, unsigned int axisId);
DECL_FASTCALL_SIMPLE_GLO(OS_GamepadButton, _Z16OS_GamepadButtonjj, bool, unsigned int padId, unsigned int buttonId);
DECL_FASTCALL_SIMPLE_GLO(OS_GamepadIsConnected, _Z21OS_GamepadIsConnectedjP13OSGamepadType, bool, unsigned int padId, OSGamepadType *setType);
DECL_FASTCALL_SIMPLE_GLO(OS_GamepadTouchpad, _Z18OS_GamepadTouchpadjjPfS_, bool, unsigned int padId, unsigned int touchId, float *x, float *y);
DECL_FASTCALL_SIMPLE_GLO(OS_GetDateTime, _Z14OS_GetDateTimeP8DateTime, void, DateTime *ret);
DECL_FASTCALL_SIMPLE_GLO(OS_GetDeviceInfo, _Z16OS_GetDeviceInfoi, int, int index);
DECL_FASTCALL_SIMPLE_GLO(OS_HTTPGet, _Z10OS_HTTPGetPKc, const char*, const char *url);
DECL_FASTCALL_SIMPLE_GLO(OS_HTTPGetData, _Z14OS_HTTPGetDataPKcPPc, u32, const char *url, char **intoData);
DECL_FASTCALL_SIMPLE_GLO(OS_HTTPPost, _Z11OS_HTTPPostPKc, const char*, const char *url);
DECL_FASTCALL_SIMPLE_GLO(OS_KeyboardIsSoftVisible, _Z24OS_KeyboardIsSoftVisiblev, bool);
DECL_FASTCALL_SIMPLE_GLO(OS_KeyboardRequest, _Z18OS_KeyboardRequesti, void, int show);
DECL_FASTCALL_SIMPLE_GLO(OS_LanguageDeviceRegion, _Z23OS_LanguageDeviceRegionv, OSLanguageCode);
DECL_FASTCALL_SIMPLE_GLO(OS_LanguageUserSelected, _Z23OS_LanguageUserSelectedv, OSLanguageCode);
DECL_FASTCALL_SIMPLE_GLO(OS_MutexCreate, _Z14OS_MutexCreatePKc, OSMutex, const char *name);
DECL_FASTCALL_SIMPLE_GLO(OS_MutexDelete, _Z14OS_MutexDeletePv, void, OSMutex toDelete);
DECL_FASTCALL_SIMPLE_GLO(OS_MutexObtain, _Z14OS_MutexObtainPv, void, OSMutex onMutex);
DECL_FASTCALL_SIMPLE_GLO(OS_MutexRelease, _Z15OS_MutexReleasePv, void, OSMutex fromMutex);
DECL_FASTCALL_SIMPLE_GLO(OS_PointerGetNumber, _Z19OS_PointerGetNumberv, int);
DECL_FASTCALL_SIMPLE_GLO(OS_PointerGetType, _Z17OS_PointerGetTypei, OSPointingDevice, int deviceIndex);
DECL_FASTCALL_SIMPLE_GLO(OS_ScreenGetHeight, _Z18OS_ScreenGetHeightv, u32);
DECL_FASTCALL_SIMPLE_GLO(OS_ScreenGetInches, _Z18OS_ScreenGetInchesv, float);
DECL_FASTCALL_SIMPLE_GLO(OS_ScreenGetWidth, _Z17OS_ScreenGetWidthv, u32);
DECL_FASTCALL_SIMPLE_GLO(OS_ScreenSetWakeLock, _Z20OS_ScreenSetWakeLockb, void, bool enabled);
DECL_FASTCALL_SIMPLE_GLO(OS_ScreenSwapBuffers, _Z20OS_ScreenSwapBuffersv, void);
DECL_FASTCALL_SIMPLE_GLO(OS_SemaphoreCreate, _Z18OS_SemaphoreCreatev, OSSemaphore);
DECL_FASTCALL_SIMPLE_GLO(OS_SemaphoreDelete, _Z18OS_SemaphoreDeletePv, void, OSSemaphore toDelete);
DECL_FASTCALL_SIMPLE_GLO(OS_SemaphoreGet, _Z15OS_SemaphoreGetPv, int, OSSemaphore fromSem);
DECL_FASTCALL_SIMPLE_GLO(OS_SemaphorePost, _Z16OS_SemaphorePostPv, void, OSSemaphore onSem);
DECL_FASTCALL_SIMPLE_GLO(OS_SemaphoreTryWait, _Z19OS_SemaphoreTryWaitPv, bool, OSSemaphore forSem);
DECL_FASTCALL_SIMPLE_GLO(OS_SemaphoreWait, _Z16OS_SemaphoreWaitPv, void, OSSemaphore forSem);
DECL_FASTCALL_SIMPLE_GLO(OS_ServiceAppCommand, _Z20OS_ServiceAppCommandPKcS0_, bool, const char *cmd, const char *args);
DECL_FASTCALL_SIMPLE_GLO(OS_ServiceAppCommandValue, _Z25OS_ServiceAppCommandValuePKcS0_, int, const char *cmd, const char *args);
DECL_FASTCALL_SIMPLE_GLO(OS_ServiceIsAppInstalled, _Z24OS_ServiceIsAppInstalledPKc, bool, const char *appName);
DECL_FASTCALL_SIMPLE_GLO(OS_ServiceIsNetworkAvailable, _Z28OS_ServiceIsNetworkAvailablev, bool);
DECL_FASTCALL_SIMPLE_GLO(OS_ServiceIsWifiAvailable, _Z25OS_ServiceIsWifiAvailablev, bool);
DECL_FASTCALL_SIMPLE_GLO(OS_ServiceLocalNotification, _Z27OS_ServiceLocalNotificationiPKcS0_, void, int secondsToFire, const char *title, const char *message);
DECL_FASTCALL_SIMPLE_GLO(OS_ServiceLocalNotificationCancel, _Z33OS_ServiceLocalNotificationCancelv, void);
DECL_FASTCALL_SIMPLE_GLO(OS_ServiceOpenLink, _Z18OS_ServiceOpenLinkPKc, void, const char *link);
DECL_FASTCALL_SIMPLE_GLO(OS_SetFilePathOffset, _Z20OS_SetFilePathOffsetPKc, void, const char *offset);
DECL_FASTCALL_SIMPLE_GLO(OS_SystemCheckPause, _Z19OS_SystemCheckPausei, bool, int sleepTime);
DECL_FASTCALL_SIMPLE_GLO(OS_SystemChip, _Z13OS_SystemChipv, OSDeviceChip);
DECL_FASTCALL_SIMPLE_GLO(OS_SystemDevice, _Z15OS_SystemDevicev, OSDefinedDevice);
DECL_FASTCALL_SIMPLE_GLO(OS_SystemForm, _Z13OS_SystemFormv, OSDeviceForm);
DECL_FASTCALL_SIMPLE_GLO(OS_ThreadClose, _Z14OS_ThreadClosePv, void, OSThreadHandle thread);
DECL_FASTCALL_SIMPLE_GLO(OS_ThreadGetValue, _Z17OS_ThreadGetValuev, void*);
DECL_FASTCALL_SIMPLE_GLO(OS_ThreadIsRunning, _Z18OS_ThreadIsRunningPv, bool, OSThreadHandle thread);
DECL_FASTCALL_SIMPLE_GLO(OS_ThreadLaunch, _Z15OS_ThreadLaunchPFjPvES_jPKci16OSThreadPriority, OSThreadHandle,
    OSThreadFunction function, void *functionData, unsigned int processorAffinity, const char *threadName, int joinable, OSThreadPriority priority);
DECL_FASTCALL_SIMPLE_GLO(OS_ThreadMakeCurrent, _Z20OS_ThreadMakeCurrentv, void);
DECL_FASTCALL_SIMPLE_GLO(OS_ThreadSetValue, _Z17OS_ThreadSetValuePv, void, void *withValue);
DECL_FASTCALL_SIMPLE_GLO(OS_ThreadSleep, _Z14OS_ThreadSleepi, void, int uS);
DECL_FASTCALL_SIMPLE_GLO(OS_ThreadUnmakeCurrent, _Z22OS_ThreadUnmakeCurrentv, void);
DECL_FASTCALL_SIMPLE_GLO(OS_ThreadWait, _Z13OS_ThreadWaitPv, void, OSThreadHandle untilFinished);
DECL_FASTCALL_SIMPLE_GLO(OS_TimeAccurate, _Z15OS_TimeAccuratev, double);
DECL_FASTCALL_SIMPLE_GLO(OS_TimeMS, _Z9OS_TimeMSv, u32);

DECL_FASTCALL_SIMPLE_GLO(GetJavaVM, GetJavaVM, JavaVM*);

DECL_OBJECT_ARRAY_PLT_GLOBAL(ButtonContainer<3>, pointers, BYBIT(0x676D24, 0x84BA90) );
DECL_OBJECT_PLT_GLOBAL(ButtonContainer<KK_MAX>, keys, BYBIT(0x676F10, 0x84BE60) );
DECL_OBJECT_ARRAY_PLT_GLOBAL(ButtonContainer<16>, gamepads, BYBIT(0x678160, 0x84E2D8) );
DECL_OBJECT_ARRAY_PLT_GLOBAL(AND_TouchPoint, Points, BYBIT(0x679E94, 0x851D38) );

//#define pointers pointers() // ugh... popular name.
//#define keys keys() // same.
//#define gamepads gamepads() // same. yup...
//#define Points Points() // bruh.

#endif // __AML_PSDK_SAOPERATINGSYSTEM_H
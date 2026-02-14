LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_CPP_EXTENSION := .cpp .cc
ifeq ($(TARGET_ARCH_ABI), armeabi-v7a)
    LOCAL_MODULE := PSDK_CoronaExt
else
    LOCAL_MODULE := PSDK_CoronaExt64
endif
LOCAL_SRC_FILES := main.cpp
LOCAL_CXXFLAGS += -O2 -mfloat-abi=softfp -DNDEBUG -std=c++17
LOCAL_LDLIBS += -llog

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../..

include $(BUILD_SHARED_LIBRARY)
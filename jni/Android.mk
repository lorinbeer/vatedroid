LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE    := v8_base
LOCAL_SRC_FILES := ../libs/libv8_base.arm.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := v8_nosnapshot
LOCAL_SRC_FILES :=  ../libs/libv8_nosnapshot.arm.a
include $(PREBUILT_STATIC_LIBRARY)


include $(CLEAR_VARS)
LOCAL_MODULE    := vatedroid
LOCAL_SRC_FILES := vatedroid.cpp
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../include
LOCAL_LDLIBS    := -llog -landroid
LOCAL_STATIC_LIBRARIES := v8_base v8_nosnapshot
include $(BUILD_SHARED_LIBRARY)

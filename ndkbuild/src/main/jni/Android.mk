LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := AndroidClass
LOCAL_SRC_FILES := AndroidClass.cpp myMeanSum.cpp

include $(BUILD_SHARED_LIBRARY)

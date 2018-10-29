LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_LDLIBS += -L($SYSROOT)/usr/lib -llog

LOCAL_MODULE    := swigprj
LOCAL_SRC_FILES := \
TransmissionPerson.c \
TransmissionString.c

include $(BUILD_SHARED_LIBRARY)

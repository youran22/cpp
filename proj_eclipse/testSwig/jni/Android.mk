#Android.mk NDK必选构建文件

LOCAL_PATH := $(call my-dir)

#本身模块
include $(CLEAR_VARS)
LOCAL_MODULE    := testSwig
LOCAL_LDLIBS 	+= -L$(SYSROOT)/usr/lib -llog
LOCAL_SRC_FILES := Unix_wrap.cxx
#LOCAL_CPP_FEATURES += rtti
include $(BUILD_SHARED_LIBRARY)
# $(BUILD_STATIC_LIBRARY) include $(BUILD_EXECUTABLE)
#BUILD_EXECUTABLE变量指向build-executable.mk Makefile片段

#模块1
#第三方库
#include $(CLEAR_VARS)
#LOCAL_MODULE  := jsoncpp
#LOCAL_SRC_FILES  := libjsoncpp.so
#include $(PREBUILT_SHARED_LIBRARY)
#Prebuilt库定义中不包含任何关于该库所构建的实际机器体系结构的信息，
#开发人员要确保Prebuilt库是为了与NDK项目相同的机器体系构建的
#https://www.jianshu.com/p/f23df3aa342c
LOCAL_PATH := $(call my-dir)

#模块一
include $(CLEAR_VARS)

#添加要用到的共享动态库
#LOCAL_SHARED_LIBRARIES := \
#	libcutils \
#	libutils \
#    liblog  \

#添加要用到的静态库
LOCAL_LDLIBS := -llog

LOCAL_MODULE    := JniPrj

#多个cpp文件_OK 1、添加(LOCAL_PATH)，不添加，没法搜索；2、添加完后要去掉(LOCAL_PATH)（此时有两个jni目录），不去掉会编译错误；
#MY_CPP_LIST := $(wildcard $(LOCAL_PATH)/*.cpp) 
#MY_CPP_LIST := $(MY_CPP_LIST:$(LOCAL_PATH)/%=%)
#LOCAL_SRC_FILES :=  $(MY_CPP_LIST)
 
LOCAL_SRC_FILES := JniPrj.cpp

#swig_begin shielding(屏蔽) these code you can didn't need swig comply;
#from *.i *.c(or cpp) generate _wrap.cxx(_wrap.c) and *.java *JNI.java file;
#MY_SWIG_PACKAGE := com.apress.swig
#MY_SWIG_INTERFACES := Unix.i
#MY_SWIG_TYPE := cxx
#include $(LOCAL_PATH)/my-swig-generate.mk
#swig_end

include $(BUILD_SHARED_LIBRARY)

#模块二
# 包含PREBUILT_SHARED_LIBRARY文件夹
#include $(PREBUILT_SHARED_LIBRARY)
#$(info, $(PREBUILT_SHARED_LIBRARY))

include $(CLEAR_VARS)
LOCAL_MODULE    := main
LOCAL_SRC_FILES := main.c
LOCAL_LDLIBS    := -llog -landroid -lEGL -lGLESv1_CM
LOCAL_STATIC_LIBRARIES := android_native_app_glue
LOCAL_SHARED_LIBRARIES := fkAdd
include $(BUILD_SHARED_LIBRARY)

#模块三
include $(CLEAR_VARS)
LOCAL_MODULE    := native-activity
LOCAL_SRC_FILES := NativeActivity.c
LOCAL_LDLIBS    := -llog -landroid
LOCAL_STATIC_LIBRARIES := android_native_app_glue
include $(BUILD_SHARED_LIBRARY)
$(call import-module,android/native_app_glue)

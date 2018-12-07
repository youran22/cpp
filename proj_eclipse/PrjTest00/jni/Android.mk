LOCAL_PATH := $(call my-dir)

#ģ��һ
include $(CLEAR_VARS)

#���Ҫ�õ��Ĺ���̬��
#LOCAL_SHARED_LIBRARIES := \
#	libcutils \
#	libutils \
#    liblog  \

#���Ҫ�õ��ľ�̬��
LOCAL_LDLIBS := -llog

LOCAL_MODULE    := JniPrj

#���cpp�ļ�_OK 1�����(LOCAL_PATH)������ӣ�û��������2��������Ҫȥ��(LOCAL_PATH)����ʱ������jniĿ¼������ȥ����������
#MY_CPP_LIST := $(wildcard $(LOCAL_PATH)/*.cpp) 
#MY_CPP_LIST := $(MY_CPP_LIST:$(LOCAL_PATH)/%=%)
#LOCAL_SRC_FILES :=  $(MY_CPP_LIST)
 
LOCAL_SRC_FILES := JniPrj.cpp

#swig_begin shielding(����) these code you can didn't need swig comply;
#from *.i *.c(or cpp) generate _wrap.cxx(_wrap.c) and *.java *JNI.java file;
#MY_SWIG_PACKAGE := com.apress.swig
#MY_SWIG_INTERFACES := Unix.i
#MY_SWIG_TYPE := cxx
#include $(LOCAL_PATH)/my-swig-generate.mk
#swig_end

include $(BUILD_SHARED_LIBRARY)

#ģ���
# ����PREBUILT_SHARED_LIBRARY�ļ���
#include $(PREBUILT_SHARED_LIBRARY)
#$(info, $(PREBUILT_SHARED_LIBRARY))

include $(CLEAR_VARS)
LOCAL_MODULE    := main
LOCAL_SRC_FILES := main.c
LOCAL_LDLIBS    := -llog -landroid -lEGL -lGLESv1_CM
LOCAL_STATIC_LIBRARIES := android_native_app_glue
LOCAL_SHARED_LIBRARIES := fkAdd
include $(BUILD_SHARED_LIBRARY)

#ģ����
include $(CLEAR_VARS)
LOCAL_MODULE    := native-activity
LOCAL_SRC_FILES := NativeActivity.c
LOCAL_LDLIBS    := -llog -landroid
LOCAL_STATIC_LIBRARIES := android_native_app_glue
include $(BUILD_SHARED_LIBRARY)
$(call import-module,android/native_app_glue)

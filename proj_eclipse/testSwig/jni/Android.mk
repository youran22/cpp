#Android.mk NDK��ѡ�����ļ�

LOCAL_PATH := $(call my-dir)

#����ģ��
include $(CLEAR_VARS)
LOCAL_MODULE    := testSwig
LOCAL_LDLIBS 	+= -L$(SYSROOT)/usr/lib -llog
LOCAL_SRC_FILES := Unix_wrap.cxx
#LOCAL_CPP_FEATURES += rtti
include $(BUILD_SHARED_LIBRARY)
# $(BUILD_STATIC_LIBRARY) include $(BUILD_EXECUTABLE)
#BUILD_EXECUTABLE����ָ��build-executable.mk MakefileƬ��

#ģ��1
#��������
#include $(CLEAR_VARS)
#LOCAL_MODULE  := jsoncpp
#LOCAL_SRC_FILES  := libjsoncpp.so
#include $(PREBUILT_SHARED_LIBRARY)
#Prebuilt�ⶨ���в������κι��ڸÿ���������ʵ�ʻ�����ϵ�ṹ����Ϣ��
#������ԱҪȷ��Prebuilt����Ϊ����NDK��Ŀ��ͬ�Ļ�����ϵ������
#https://www.jianshu.com/p/f23df3aa342c
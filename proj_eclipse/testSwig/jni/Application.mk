#Application.mk ��ѡ�����ļ�

#APP_ABI := armeabi armeabi-v7a x86 mips x64 x86_64
APP_ABI := armeabi
#����汾���Ե����� 
#APP_PLATFORM := android-8
LOCAL_CFLAGS := -fstack-protector-all
APP_CPPFLAGS += -fexceptions
APP_CPPFLAGS +=-std=c++11

#system gabi++_static gabi++_shared stlport_static gnustl_shared
#Ĭ�� system
#APP_STL := stlport_static
APP_STL := gnustl_static


#APP_GNUSTL_FORCE_CPP_FEATURES := exceptions rtti 

#https://blog.csdn.net/roland_sun/article/details/46318893
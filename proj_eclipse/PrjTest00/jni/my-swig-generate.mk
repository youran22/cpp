#@author lhj

#������
ifndef MY_SWIG_PACKAGE
$(error MY_SWIG_PACKAGE is not defined.)
endif

#��б���滻javaĿ¼�е�Բ�㣺���磺com.apress.swig com/apress/swig 
MY_SWIG_OUTDIR := $(NDK_PROJECT_PATH)/src/$(subst .,/,$(MY_SWIG_PACKAGE))

#�����ļ����ͣ�c++ c
ifndef MY_SWIG_TYPE
MY_SWIG_TYPE:= cxx
endif

#����swigģʽ�������в�����-c++ ���� Ĭ��Ϊ-c��
ifeq ($(MY_SWIG_TYPE),cxx)
MY_SWIG_MODE := -c++
else
MY_SWIG_MODE :=
endif

#׷��swig��װԴ�ļ�
LOCAL_SRC_FILES += $(foreach MY_SWIG_INTERFACE, \
$(MY_SWIG_INTERFACES), \
$(basename $(MY_SWIG_INTERFACE)))_wrap.$(MY_SWIG_TYPE)

#���.cxx��Ϊc++�ļ���չ��
LOCAL_CPP_EXTENISON +=.cxx

#����SWIG��װ���� 
%_wrap.$(MY_SWIG_TYPE):%.i
	$(call host-mkdir,$(MY_SWIG_OUTDIR))
	swig -java \
	$(MY_SWIG_MODE) \
	-package $(MY_SWIG_PACKAGE) \
	-outdir $(MY_SWIG_OUTDIR) \
	$<


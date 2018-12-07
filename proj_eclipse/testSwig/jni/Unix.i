%module testSwig

/*
%include "std_string.i"
%include "std_vector.i"
%include "arrays_java.i"
%include "typemaps.i"
%include "enums.swg"
*/
%include <typemaps.i>
%include "arrays_java.i"
%include "enums.swg"

%apply double* OUTPUT {double& result}

%include "various.i"
%apply char *BYTE {char *input}



%{
#include<src\coordtest.cpp>
%}

%include<src\coordtest.h>

/* 
����
%include "std_string.i"
%include "arrays_java.i"
%include "enums.swg"

%apply double& OUTPUT {double& result}

%ignore "";
%rename($ignore, "double*") "";	
%ignore double*;//����

%include "typemaps.i"
bool XYZToBLH(double R,double alfa,double X,double Y,double Z,double* OUTPUT,double* OUTPUT,double* OUTPUT);
	//����������ǲ��ԣ���ֵû��������

%typemap(in) double *{
	$1 = (double *) JCALL2(GetDoubleArrayElements, jenv, $input, 0);
}
	//why?

%typemap(argout) double *{
	JCALL3(ReleaseDoubleArrayElements, jenv, $input, (double*)$1, 0);
	$1=NULL;
}
	//why?

%typemap(jtype) double * "double[]"
	//why?

%apply double& OUTPUT {double& result}
	//OK  ���ǰ�ǰ����Ǹ��滻�ɺ�����Ǹ�//�ǵ���Ӽ���so����--����������unfortunately ��ɫ��

%apply double *OUTPUT {double &result}
	//OK?

%apply signed char *OUTPUT{signed char &output}
	//why?
	
%apply signed char *OUTPUT {char *output}
	//why��

%typemap(jni) unsigned char *NIOBUFFER "jobject"  
%typemap(jtype) unsigned char *NIOBUFFER "java.nio.ByteBuffer"  
%typemap(jstype) unsigned char *NIOBUFFER "java.nio.ByteBuffer"  
%typemap(javain,
  pre="  assert $javainput.isDirect() : \"Buffer must be allocated direct.\";") unsigned char *NIOBUFFER "$javainput"
%typemap(javaout) unsigned char *NIOBUFFER {  
  return $jnicall;  
}  
%typemap(in) unsigned char *NIOBUFFER {  
  $1 = (unsigned char *) JCALL1(GetDirectBufferAddress, jenv, $input); 
  if ($1 == NULL) {  
    SWIG_JavaThrowException(jenv, SWIG_JavaRuntimeException, "Unable to get address of a java.nio.ByteBuffer direct byte buffer. Buffer must be a direct buffer and not a non-direct buffer.");  
  }  
}  
%typemap(memberin) unsigned char *NIOBUFFER {  
  if ($input) {  
    $1 = $input;  
  } else {  
    $1 = 0;  
  }  
}  
%typemap(freearg) unsigned char *NIOBUFFER ""  

%apply unsigned char *NIOBUFFER { unsigned char *data}; 

*/
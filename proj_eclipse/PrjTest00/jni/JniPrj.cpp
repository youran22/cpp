#include "com_example_prjtest00_MainActivity.h"
//#include "../../" 这种格式是可以的； 但是#inlcude "..\..\"这种是不可以的；


#define Log_Tag "PrjTest00-JniPrj.cpp"
#define LogDeb(...) __android_log_print(ANDROID_LOG_DEBUG,Log_Tag, __VA_ARGS__)




JNIEXPORT jstring JNICALL Java_com_example_prjtest00_MainActivity_stringFromJNI(JNIEnv *env, jobject)
{
	LogDeb(Log_Tag, "stringFromJni");//应该还有其他的使用方法？？

#if defined(__arm__)
  #if defined(__ARM_ARCH_7A__)
    #if defined(__ARM_NEON__)
      #if defined(__ARM_PCS_VFP)
        #define ABI "armeabi-v7a/NEON (hard-float)"
      #else
        #define ABI "armeabi-v7a/NEON"
      #endif
    #else
      #if defined(__ARM_PCS_VFP)
        #define ABI "armeabi-v7a (hard-float)"
      #else
        #define ABI "armeabi-v7a"
      #endif
    #endif
  #else
   #define ABI "armeabi"
  #endif
#elif defined(__i386__)
   #define ABI "x86"
#elif defined(__x86_64__)
   #define ABI "x86_64"
#elif defined(__mips64)  /* mips64el-* toolchain defines __mips__ too */
   #define ABI "mips64"
#elif defined(__mips__)
   #define ABI "mips"
#elif defined(__aarch64__)
   #define ABI "arm64-v8a"
#else
   #define ABI "unknown"
#endif

	jstring str = env->NewStringUTF("Hello from JNI ! Compiled with ABI" ABI ".");

	return str;
}

/*

//OK
jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	JNIEnv* env = NULL;
	jint result = -1;
	if (vm->GetEnv((void**) &env, JNI_VERSION_1_4) != JNI_OK) {
		return result;
	}
	return JNI_VERSION_1_4;
}

*/

/*

 JNIEXPORT void JNICALL Java_southgnss_so_coordso_SouthCoordSo_BLToNEOblique
  (JNIEnv *env, jclass, jdouble b, jdouble l, jobject prjo, jobject n, jobject e)
{
	jclass d = env->FindClass("java/lang/Double");
	if(d==0)
	{
		return;
	}
	jfieldID id0 = env->GetFieldID(d, "value", "D");
	if(id0==0)
	{
		return;
	}

	jclass CPrjO = env->GetObjectClass(prjo);
	if(CPrjO == 0)
	{
		return;
	}
	double r, alfa, lon, lat, fac, is_n, is_e, azi, lon1, lat1, lon2, lat2;
	int method;
	jfieldID id = env->GetFieldID(CPrjO, "r", "D");
	if(id==0)
	{
		return;
	}
	r = env->GetDoubleField(prjo, id);

	id = env->GetFieldID(CPrjO, "alfa", "D");
	if(id==0)
	{
		return;
	}
	alfa = env->GetDoubleField(prjo,id);
	//lon, lat,
	id = env->GetFieldID(CPrjO, "lon", "D");
	if(id==0)
	{
		return;
	}
	lon = env->GetDoubleField(prjo, id);
	id = env->GetFieldID(CPrjO, "lat", "D");
	if(id==0)
	{
		return;
	}
	lat = env->GetDoubleField(prjo, id);
	//fac, is_n,
	id = env->GetFieldID(CPrjO, "fac", "D");
	if(id==0)
	{
		return;
	}
	fac = env->GetDoubleField(prjo, id);
	id = env->GetFieldID(CPrjO, "is_n", "D");
	if(id==0)
	{
		return;
	}
	is_n = env->GetDoubleField(prjo, id);
	//is_e, azi,
	id = env->GetFieldID(CPrjO, "is_e", "D");
	if(id==0)
	{
		return;
	}
	is_e = env->GetDoubleField(prjo, id);
	id = env->GetFieldID(CPrjO, "azi", "D");
	if(id==0)
	{
		return;
	}
	azi = env->GetDoubleField(prjo, id);
	//lon1, lat1,
	id = env->GetFieldID(CPrjO, "lon1", "D");
	if(id==0)
	{
		return;
	}
	lon1 = env->GetDoubleField(prjo, id);
	id = env->GetFieldID(CPrjO, "lat1", "D");
	if(id==0)
	{
		return;
	}
	lat1 = env->GetDoubleField(prjo, id);
	//lon2, lat2;
	id = env->GetFieldID(CPrjO, "lon2", "D");
	if(id==0)
	{
		return;
	}
	lon2 = env->GetDoubleField(prjo, id);
	id = env->GetFieldID(CPrjO, "lat2", "D");
	if(id==0)
	{
		return;
	}
	lat2 = env->GetDoubleField(prjo, id);
	id = env->GetFieldID(CPrjO, "method", "I");
	if(id==0)
	{
		return;
	}
	method = env->GetIntField(prjo, id);

	HPRJ hprj = CreateProjectionOblique(r, alfa, lon, lat, method, fac, is_n, is_e, azi, lon1, lat1, lon2, lat2);
	double N, E;
	BLToNEOblique(b, l, hprj, &N, &E);

	env->SetDoubleField(n, id0, N);
	env->SetDoubleField(e, id0, E);

	DeleteProjectionOblique(hprj);
}

JNIEXPORT jint JNICALL Java_southgnss_so_coordso_SouthCoordSo_XYZToBLH
  (JNIEnv *env, jclass, jdouble r, jdouble alfa, jdouble x, jdouble y, jdouble z, jobject b, jobject l, jobject h)
{
	jclass db = env->FindClass("java/lang/Double");
	if(db==0)
	{
		return 0;
	}
	jfieldID id = env->GetFieldID(db, "value", "D");
	if(id==0)
	{
		return 0;
	}

	double B,L,H;
	XYZToBLH(r, alfa, x, y, z, &B, &L, &H);

	env->SetDoubleField(b, id, B);
	env->SetDoubleField(l, id, L);
	env->SetDoubleField(h, id, H);
	return 1;
}

 */

/*


java ������ϰ
android
	eclipse�Ŀ�ݷ�ʽ
	eclipse�Ľ�������
android����so�ļ�
Jni���
cygwin��ʹ��
Swig���

http://blog.csdn.net/hemeinvyiqiluoben/article/details/50370956  ����

java ������ϰ
	http://www.yiibai.com/java/java_object_classes.html
	LOCAL_LDLIBS := -llog
	swig -Java -package com.apress.swig -outdir src/com/apress/swig jni/Unix.i
		//-Java ������ -package �����ɵ����������ĸ������棻 -outdir :  ���ɵ����ļ������ĸ�·���£�  �ӿ��ļ���
		//-java Сд��ʶ�𣬴�дJava��ʶ��
	��ô�鿴���е��ֶκͷ�����ǩ��: ʹ��javap����:
		javap -s -p JNIDemo.class

	java�����﷨��
		���APK ��
			http://blog.csdn.net/luoyin22/article/details/7862742 eclipse
				��������а�װapk��
					http://blog.csdn.net/zouxiongqqq/article/details/50554630
						ûЧ����ô�ҵ���װ��app��
							//����һ�ַ�ʽ��
							�����غõ�apk�ŵ���Android SDK��Tools�ļ����У�APK��emulator.exeͬ�ļ��У�
							ִ��adb install Scan.apk�����ִ�а�װapk
		Activity :
			Activity��������ģʽ  http://blog.csdn.net/shinay/article/details/7898492/
		String���÷���
			//https://wenku.baidu.com/view/1fd047a4dd3383c4bb4cd2b8.html
			String s = "37,78584";
			int ival = Integer.parseInt(s.replace(",", ""));
			double dval = Double.parseDouble(s.replace(",", ""));
			float fval = Float.parseFloat(s.replace(",", ""));
				���ַ���ת��Ϊ���ͣ�
				int i = Integer.parseIn(String str);
				int i = Integer.valueOf().intValue();
				ע��Integer.parseIn �� Integer.valueOf ��ͬ��ǰ�����ɵ������ͣ���������һ����������Ҫͨ��intValue()����ö����ֵ��

			String str = null;
				str = String.format("Hi�� %s", "����");
				System.out.println(str);
					//��Ц��������Ȼ����ɳ��������
					String str="a";//
					str.format("Hi, %s", "����");
					System.out.pirntln(str);
			format��
				http://blueram.iteye.com/blog/441683
				%b ��������  true
				%d �������ͣ�ʮ���ƣ� 99		//��ǳ�ע�⣡����//int,long,byte
				%x �������ͣ�ʮ�����ƣ� FF
				%o �������ͣ��˽��ƣ� 77
				%f �������� 99.99				//��ǳ�ע�⣡����//double
				%a ʮ�����Ƹ������� FF.35AE
				%e ָ������ 9.38e+5
				%g ͨ�ø������ͣ�f��e�����н϶̵ģ�
				%h ɢ����
				%% �ٷֱ����� ��
				%n ���з�
				%tx ������ʱ�����ͣ�x����ͬ��������ʱ��ת����
android
	xuexi ����
	http://www.cnblogs.com/tinyphp/p/3831562.html ����
		http://blog.csdn.net/llping2011/article/details/9992941 ���ʹ�ò����ļ� ��󲼾����
		http://www.cnblogs.com/lwbqqyumidi/p/3776184.html ������Ҫ�����Ľ���
	http://blog.csdn.net/netdxy/article/details/50691915 �����ؼ�
			http://www.cnblogs.com/whoislcj/p/5708778.html �Զ���
			http://limingnihao.iteye.com/blog/851369
			http://blog.csdn.net/j903829182/article/details/40660275
	http://cloudsgarden.lofter.com/  blog
		http://blog.csdn.net/zzhays/article/details/10489629 ţ�˵��Ķ�����

	ѧϰ��վ��
	http://www.csdn.net/article/2015-02-23/2824006 ѧϰ��վ
		����Ӣ�Ķ�
	http://blog.csdn.net/banketree/article/details/24982021    Android Framework ��¼֮��

	eclipse�Ŀ�ݷ�ʽ
		alt+shift+r��������
		Control-Shift-T: �����ͣ�Open type������ctrl+t���г��ӿڵ�ʵ�����б�
		F3: ��������Open declaration����
		�򿪷�����ʵ�֣���סctrl ֮����������ͱ������ɫ������ һ��ͽ�ȥ��
		Ctrl+Shift+/  �����ڴ��봰����������/ *~* /ע��
		�򿪵�ǰ�ļ��������ļ��У�
			1.External Tools Configurations...���
			2.���Program - new - Location������ֵ  C:\WINDOWS\explorer.exe
			3.Arguments����ֵ  /select,${container_loc}\${resource_name}
				//��ǰѡ���ļ��� ������ǰ�ļ����ļ���\�ļ����ƣ�
			4.���apply - ok
			5.ʹ��ʱ��ѡ�е�ǰ�ļ�����openFile�����Զ�������ǰ�ļ������ļ���λ�á�
		F3        ����������������ĵط���
        F5       �����������Խ��뺯���ڲ���
        F6       �����������Բ����뺯���ڲ������װ�˽�ɽ�ʰ�2006��Ҫ�ѡ�ȡ�ʿ��ء��Ŀ�ݼ��ĳ������ġ�
        F7       �����ɺ����ڲ����ص����ô���
        F8       ����һֱִ�е���һ���ϵ㡣



		Control-Q: �ص����һ�α༭�ĵط�
		Control-Shift-G: ��workspace���������ã�reference����
		Control-Shift-F: Code��Java��Preferences�����ݴ������趨���¸�ʽ�����롣
		 Control-/: ��һ��ע�ͻ�ȡ��ע�͡����ڶ���Ҳͬ�����á�
		Ctrl+Alt+H���������֪��һ����ķ������ױ���Щ�����������
		Alt+���ҷ����
			���Ǿ���������������ʱCtrl+����������٣�Ȼ����ʧ�ڴ����е��������ʱֻ��Ҫ����Alt+�����
			���Ϳ����˻ص��ϴ��Ķ���λ�ã�ͬ������Alt+�ҷ��������ǰ�����ղ��˻ص��Ķ�λ�ã������������
			ǰ���ͺ��˰�ťһ����

		eclipse�Ľ�������
			//http://blog.csdn.net/tianlianchao1982/article/details/53463527
				���壺
					����(Window)-��ѡ�Preferences��-���棨General��-���(Appearence)-��ɫ������(Colors And Fonts)��
					���ұߵĶԻ�����ѡ��Java - Java Editor Text Font��������ֵ��޸ģ�Change����ť��
					����������ʾ�����������г���������С��������֮�������½ǵ�Ӧ��(Apply)�������ȷ����OK������
				������ɫ��
					windows->Preferences->General->Editor->Text Editors	�ұ�ѡ��Appearance color options ѡBackground color ѡ�񱳾���ɫ
					������ɫ�����Ƽ���ɫ����85�����Ͷȣ�1 2 3�����ȣ�2 0 5//��Ϊ160��Щ��

android����so�ļ�
		Ϊʲôʹ�ò����أ�
			1������������ʹ�÷�ʽ���ܱ���ͨ�������ӣ��ܽ����̣���ע�ͣ������̣�
				a����Ҫadd native��
					//add native������ʲô��
					//ʲô�����ʹ�ã�
					//�����ʲô���ݣ�
					//���裿
				b������Ӧ��LoadLibrary�Ϳ���ʹ�ú�������
				c��
			2��studio��ʹ�÷�ʽ
			3��
		https://wenku.baidu.com/view/3b19c2ee5901020206409ca2.html �������
		http://www.tuicool.com/articles/fYnmYjI    ʹ��SO��ʱҪע���һЩ����
		http://www.imooc.com/article/17298?block_id=tuijian_wz   //

		http://zwz94.blog.163.com/blog/static/3206039520131111101412959/  //Android��ε��õ�����SO��
			//http://blog.csdn.net/lishaobo211985/article/details/52853167 ��Ҫ���İ�����
			//http://www.docin.com/p-616596698.html
			//http://www.tongleer.com/1263.html
			1.��SO�ļ�ֱ�ӷŵ�libs/armeabi�£�Ȼ�������System.loadLibrary("xxx")��
				��public native static int  xxx_xxx_xxx()��
				�������Ϳ���ֱ�ӵ���xxx_xxx_xxx()������
					//�����У�
					//
			2.�ڶ��ַ����������Լ���SO�ļ���
				���Լ���SO�ļ�����õ�����SO��
				���ڳ����е����Լ���SO�����ֱȽϸ��ӣ���Ҫ��java���ļ�������.h�ļ���
				��дCԴ�ļ�include֮ǰ���ɵ�.h�ļ���ʵ����Ӧ������
				�����android NDK�������е�ndk-build�ű����ɶ�Ӧ��.so����⣻
			1.�������ַ����Ƿ���У������еĻ�����ʲô���⣿
			2.���ַ�����ʲô����Ϊʲô���ϴ󲿶����õĵڶ��ַ�����
			3.ֻ��һ��*.so�ļ������ṩ����ϸ�Ľӿ�˵�����Ƿ����ANDROID��ʹ������
				����Ҫ�����SO�ǲ���JNI�淶��SO��������û�з���JNI��ֱ��֧�ֵ����͡�
				Ҳ����˵���SO�ǲ��ǿ���ֱ�ӵ���JNI�����á�
				������Ƿ񶨵ģ���ֻ��ѡ�ڶ���������

				������ǿ϶��ģ���Ҫ�����ǲ���ϣ�����SO�Ŀ�ֱ�ӱ�¶��JAVA�㣬
				������Ƿ񶨵ģ���ֻ��ѡ�ڶ��������������㱾��Ҳ��һ������ṩ�ߡ�

				��C���õ�����so
					void *handle;
					int (*call_method)(void);
					handle = dlopen(so_path, RTLD_LAZY);
					//����ָ��
					call_method =  dlsym(handle, "method_name(���÷����ĺ�����)");
				����һ�ַ�����Android Studio�ķ�����
					//http://blog.csdn.net/chinawallace/article/details/48026207
				����һ�ַ�����
					//http://blog.csdn.net/guofu8241260/article/details/22274595
		����Ķ����У�
			http://blog.csdn.net/jiuyueguang/article/details/9447245  //��һ��;
			1���½���Ŀ
			2��add native

			3����activity��Ӵ��룺
				����native����������
			4��javah����ͷ�ļ�:
				--�ɼ����Ǹ��ݵ��ñ�����ͺ�����������.h�ļ��ģ�
				Ϊʲôjavah�����ò��ˣ�
					��ʹ�ã�cd src�У���javah -jni  com.example.hello.MainActivity //��������Ǵ�ģ�Ӧ��˵��native���εĺ������ڵ��ࣻ
						--���ֵ����⣺http://blog.csdn.net/z13144099248m/article/details/41775633
						--ע�⣺
							������src�µ�classes����bin�µ�classes��
							�����Ƕ����classes���Ƕ���ģ�--�����飺����ģ�
			5����дjni�ļ����µ�hello.cpp�ļ�
			6.��дjni�ļ����µ�Android.mk�ļ�
				--add native ���Զ���ӣ�
				--��Ҫ����� Application.mk ?
			7.�޸���Ŀ�ı���ѡ���Ŀ�Ҽ�-��Properties-��C/C++ Build-��Build command����д���android-ndk�ĸ�Ŀ¼��
				--һ�����Ĭ�ϣ�
			8.������Ŀ����Ŀ�Ҽ�-��build project���ῴ������̨�����˵�����ǵ�����ȷ�ģ�good��
			9.����android��Ŀ���ῴ����ͼ��˵������ȷ�ģ��������Ǳ�д�Ŀ��ļ��ܹ�����ȷ�ı��Լ��ĳ������
			http://blog.csdn.net/jiuyueguang/article/details/9449737 �ڶ�����
				1���½���Ŀ
					�½���so������һ���İ�����������
				2��

			http://blog.csdn.net/jiuyueguang/article/details/9450597 ��������
	ndk ������cpp�ļ���
		1.��.h .cpp�ļ��ŵ�jniĿ¼�£���eclipse��ˢ�¾Ϳ��Կ����ˣ�
		2.����jniĿ¼����a.h,a.cpp,b.cpp�����ļ�����Android.mk�������������༭LOCAL_SRC_FILES
		LOCAL_SRC_FILES :=a.cpp b.cpp
		�����Ϳ���ͬʱ������Դ�ļ���
		�������Խ�����cpp�ļ�Ƕ�װ���������

		http://blog.csdn.net/meiliangdeng1990/article/details/50784553 	//������Ŀ¼���Լ�д��C��������Android��ʹ�õľ�̬��/��̬��
			http://www.linuxidc.com/Linux/2014-12/110167.htm  ����ndk�����в���
	���log
		http://blog.csdn.net/luoshengyang/article/details/6581828
		http://blog.csdn.net/github_33304260/article/details/54799169
		http://www.2cto.com/kf/201205/132163.html ����
		jni��
			1.���ȣ��� Android.mk�ļ�����Ҫ���룺    LOCAL_LDLIBS := -llog
			2. ��Σ��������¿��ļ�   #include <android/log.h>
			3. ʹ�÷���ʾ��    __android_log_print(ANDROID_LOG_INFO, "CDib::Attach", "--------%d,%d,%d,this->linebytes=%d\n",linebytes,width,height,this->linebytes); //������ʽ��ӡ����    ����������������ʹ�ú궨��    #define LOGI(msg)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, msg)    #define LOGE(msg)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, msg)
				--#include <android/log.h> * һ��Ҫ��<string.h>��<jni.h>֮ǰ��
		����һ�ַ�ʽ��
			http://www.tc5u.com/android/xg-170789.htm

Jni���
	android���������ã�
	�android������
		android������������ʽ��
			Eclipse + ADT + SDK��
				ADT�� (android development tools)��׿��������//�°���Ѿ�������eclipse IDE
			Android Studio + SDK��
		//http://jingyan.baidu.com/article/bea41d437a41b6b4c51be6c1.html  windows�µĴ����
		http://blog.csdn.net/jptiancai/article/details/23678073  Windows��C++�ļ�����.so �ļ� ʵ����c++�����־
		http://www.cnblogs.com/zoupeiyang/p/4034517.html#3 �岽��
		http://blog.csdn.net/smking/article/details/7594019  Android�����������, ADT, JDK, SDK, NDK, Eclipse, CDT
			ADT�� ����Ϊ�˷���Eclipse��дandroid������׼����һ���ؼ�//�������÷�ʽ��
			SDK;
			Eclipse-->Windows-->Android SDK and AVD Manager�£�ȥ�½�һ��AVD�� ���������� ����ɹ������� ���ʾAndroid SDK�Ѿ���װ���
			Java�ǲ���ֱ�ӵ���Cд��dll, ����exe������߿��ļ�����Ҫʹ�õ�NDK�����м�ת����
		//http://www.runoob.com/w3cnote/android-tutorial-eclipse-adt-sdk-app.html  //ʹ��Eclipse + ADT + SDK����Android APP ��������
			//http://www.it165.net/pro/html/201410/24759.html    //windows����ADT����android NDK��������ϸ�̳̣��ӻ���������õ�����ȫ���̣�
				//http://blog.csdn.net/u013149325/article/details/40371873
		//http://www.cnblogs.com/xdp-gacl/p/4322165.html
		1������jdk�ļ�����װ������JAVA_HOME�������������jdk��path�У�
		2������sdk��ndk��
			����һ���ļ��У�AndroidDevelopTool
				��ADT��sdk��eclipse-jee-luna-SR2-win32-x86_64.zip�����ļ��ŵ��ļ����£�
			Eclipse������
				Install New Software...
					��ADT.zip�ļ�·�� ��װ
				Ȼ��sdk������Open Preferences - Androi -
					����ANDROID_SDK_HOME�������������һ�µ�path��
					%ANDROID_SDK_HOME%\tools;%ANDROID_SDK_HOME%\platform-tools��
		1��׼���������android��������������jdk��ADT���°���Ѿ�������eclipse IDE����SDK�ȵ����ذ�װ��
			��������аٶȣ��������̫���ˣ����ڴ˲���׸����
		2���ڹ���������NDK����ַ��http://developer.android.com/tools/sdk/ndk/index.html��
			�����Լ��Ĳ���ϵͳƽ̨��windows32��windows64��Linux��Mac��������Ӧ�汾��NDK��Ȼ��˫����ѹ����Ӧ���ļ��С�
		3���½�һ����ͨ��androidӦ�ó���ע����С֧�ֵ�API�汾Ҫ>=14������������֣��������������԰ٶȡ��ȸ衣
		4����ADT��������������NDK��·����
			���Window�˵���ѡ��Preference�����Androidչ������NDK������NDK·�������Apply��
		5�����Native Support
			�Ҽ����̣�->Android Tools->Add Native Support�����뽫Ҫ���ɵ�.so�ļ������֣���finish��
		6������C/C++��Paths and Symbols �Ҽ����̣�->Properties�����C/C++ Generalչ�������Path and Symbols��
			���ұ�Includes�£����Add����NDK�ļ����µ�   jniͷ�ļ�����Ӧ��C++ͷ�ļ�   ��ӽ�������һ���ǳ���Ҫ������ᱨ��
			��������ҵ���һƪ���£�http://blog.csdn.net/u013149325/article/details/40371873
	swigin��ʹ�÷�����
		��C/C++�Ĵ���Ƕ��Java�����ԵĿ�������
		//http://codingstandards.iteye.com/blog/830342  //Linux�µģ�
		//http://blog.csdn.net/a8572785/article/details/10427521  //window�� python��
	android��ndkʹ�÷�����
	windows�°�C++ dll��Ŀ�����.so�ļ��ķ�ʽ��
		��Ҫ��linux����gcc��������Щ���롣
		����windows����cygwin������Ҳ��
		��windows�»�����gccҲ���ԣ�
		��֪����û����������ĳ־û�����������JNI�ڱ��ص��ã�Ȼ�����ö���ĳ־û����л�����ͨ��TCPͨ�ţ��Ѷ��󴫸�Linux��
		//http://www.2cto.com/kf/201403/286784.html   //Android֮Windows�����ɶ�̬��so�������APK�� //ͨ��jni����
		http://blog.csdn.net/qiuxiaolong007/article/details/7860610   //ʹ��RegisterNatives�������ݺ�ʹ��Java�Զ�����
	android ndk ���õ����������ɶ�̬��Ĳ��裺
		//��c��c++������
			//http://www.diffen.com/difference/C_vs_C%2B%2B
			1����Cָ����C89������C99��׼;
			2��C++�е�Cʵ��������C++Ϊ��׼�ģ�Ҳ����˵��������C����������û�����塣
			�����ô�C��ʱ��û��C++���������ã�������Ƕ��ʽϵͳ����������C����������
			˼�벻ͬ��c ��������̣�c++�������
			C++�෶ʽ�������.
			C++��C�����������C++֧���ࣨclass)��Cû��
		//http://blog.csdn.net/heng615975867/article/details/11904737 �������
		//http://blog.csdn.net/panpen120/article/details/42193003  DLLת��so(NDK����)
			//http://blog.csdn.net/jiangxuchen/article/details/22883575
			//http://blog.csdn.net/heng615975867/article/details/11904737
			�������ɣ�ndk dll
			1��dll��dllAndroid.dll
				copy "$(OutDir)\$(TargetName).dll" "$(GNSS_DIR)\win32bin\"
				copy "$(OutDir)\$(TargetName).lib" "$(GNSS_DIR)\win32lib\"
				copy "$(OutDir)\$(TargetName).pdb" "$(GNSS_DIR)\win32bin\"
				copy *.h "$(GNSS_DIR)\include\$(ProjectName)\"
				API:
				CLASS:
				COM:
			2���½���Ŀ���½�һ���ļ���jni��������ļ������ڴ���һ���ļ���cpp,��������DLL����Щ���е�.cpp��.h���Ž�ȥ
				//����add Native��
			3����jni�ļ��������½��ļ���flie,����ΪAndriod.mk(Ҫд��׺��)
				//�Ѿ�����ˣ�����Ҫ���Application.mk:����androidƽ̨�汾��
				//mk�ļ���д����һ����
			4������NDK
				main��
				Refresh��sp->ֻ��ѡjni�ļ��У�
				Build Option��
			5������so
			6.����������������
				��1��.cpp��.h������StdAfx.h��C��׼��Ķ�����ɾ��
				��2��.�⺯���ĵط�ɾ��__declspec(dllexport)������DLL�Ķ���
				��3��.�����ǽ�ͼ�ˣ�����ָ�븳�յ�NULL���û�Ϊ0
				��4�����õ����������������ǰ�����stdlib.h
					#include<stdlib.h>
					#include<time.h>
				(5)���������C++STL�Ķ������񴴽�Andriod.mk�ķ�ʽ����Application.mk,����д
					��Application.mk�ļ������APP_STL := stlport_static
					��APP_STL := gnustl_static
		http://www.open-open.com/lib/view/open1453265030995.html  NDKʵս��
			//http://blog.csdn.net/yanbober  //ֵ���Ķ�������
		http://www.cnblogs.com/xiaorenwu702/p/5802015.html jniͷ�ļ������ʾ��
		http://www.open-open.com/lib/view/open1453265030995.html ndkʵս  ndk �����̳� ʾ��

	Android.mk �ļ��﷨���
		http://www.cnblogs.com/wainiwann/p/3837936.html
			BUILD_STATIC_LIBRARY������Ϊ��̬�⡣
			BUILD_SHARED_LIBRARY ������Ϊ��̬��
			BUILD_EXECUTABLE������ΪNative C��ִ�г���

			LOCAL_C_INCLUDES
		.hͷ�ļ��޷�ʶ��jni�µ���Ŀ¼
			http://blog.csdn.net/mfcing/article/details/48739629
			http://blog.sina.com.cn/s/blog_4c73bcc801011dfy.html
			http://oknostar.blog.163.com/blog/static/294361862012611111539579/
	http://blog.chinaunix.net/uid-20746260-id-3910616.html  //���� NDK �Ż�������
		Android.mk�﷨��
			http://www.2cto.com/kf/201507/414799.html
			http://blog.csdn.net/wenchao126/article/details/8071526  shell�ű�֮find
			http://blog.csdn.net/zhoujiaxq/article/details/25972743 makefile����
			http://www.cnblogs.com/wainiwann/p/3837936.html
			http://www.cnblogs.com/leaven/archive/2011/01/25/1944688.html
				LOCAL_PATH
					����������ڸ�����ǰ�ļ���·�����������Android.mk�Ŀ�ͷ���壬��������ʹ�ã�
						LOCAL_PATH := $(call my-dir)
						����������ᱻ$(CLEAR_VARS)��������ÿ��Android.mkֻ��Ҫ����һ�Σ���ʹ����һ���ļ��ж����˼���ģ�������£���
							�꺯����my-dir��, �ɱ���ϵͳ�ṩ�����ڷ��ص�ǰ·����������Android.mk file�ļ���Ŀ¼����
								������GNU Make�������ܡ��꣬����ͨ��ʹ��'$(call <function>)'����ֵ�����Ƿ����ı�������Ϣ��

				BUILD_SHARED_LIBRARY
					ָ�����ű����ռ����е�����LOCAL_XXX�������ṩ����Ϣ�����Ҿ�����ΰ����г���Դ�����ļ������һ������⡣
					ע�⣬����������ڰ�������ļ�֮ǰ���� LOCAL_MODULE �� LOCAL_SRC_FILES ��ע���⽫����һ����Ϊlib$(LOCAL_MODULE).so���ļ�
				LOCAL_SRC_FILES
					����Ҫ�����Դ�����ļ��б�ֻҪ�г�Ҫ���ݸ����������ļ�����Ϊ����ϵͳ�Զ�Ϊ�����������
					ע��Դ�����ļ����ƶ��������LOCAL_PATH�ģ������ʹ��·�����֣����磺
						LOCAL_SRC_FILES := foo.c \
							toto/bar.c
						ע�⣺�������ļ��ж�Ҫʹ��UNIX����б��(/).windows���ķ�б�ܲ��ᱻ��ȷ�Ĵ���
				LOCAL_C_INCLUDES
				http://www.cnblogs.com/binxindoudou/articles/3205035.html   wildcard�Ƚ���
					//���뵥��Ŀ¼������cpp�ļ�
						#����һ������MY_CPP_PATH��ʾԴ��Ŀ¼
						MY_CPP_PATH := $(LOCAL_PATH)/
						#��ȡĿ¼�µ������ļ�
						My_All_Files := $(shell find $(MY_CPP_PATH)/.)
						My_All_Files := $(My_All_Files:$(MY_CPP_PATH)/./%=$(MY_CPP_PATH)%)
						#��My_All_Files���ٴ���ȡ���е�cpp�ļ�,����Ҳ����ʹ��filter����
						MY_CPP_LIST := $(foreach c_file,$(My_All_Files), $(wildcard $(c_file)/*.cpp) )
							//c_file�м����
						MY_CPP_LIST := $(MY_CPP_LIST:$(LOCAL_PATH)/%=%)

						LOCAL_SRC_FILES := $(MY_CPP_LIST)
					//���뵥��Ŀ¼cpp��c�ļ�
						#����һ������MY_CPP_PATH��ʾԴ��Ŀ¼
						MY_CPP_PATH  := $(LOCAL_PATH)/
						#��ȡĿ¼�µ������ļ�
						My_All_Files := $(shell find $(MY_CPP_PATH)/.)
						My_All_Files := $(My_All_Files:$(MY_CPP_PATH)/./%=$(MY_CPP_PATH)%)
						#��My_All_Files���ٴ���ȡ���е�cpp�ļ�,����Ҳ����ʹ��filter����
						MY_CPP_LIST  := $(filter %.cpp %.c,$(My_All_Files))
						MY_CPP_LIST  := $(MY_CPP_LIST:$(LOCAL_PATH)/%=%)
						LOCAL_SRC_FILES := $(MY_CPP_LIST)

					//������Ŀ¼�Ķ����׺���ļ���
						MY_FILES_PATH  :=  $(LOCAL_PATH)/ \
							$(LOCAL_PATH)/../src_files/

						MY_FILES_SUFFIX := %.cpp %.c %.cc

						My_All_Files := $(foreach src_path,$(MY_FILES_PATH), $(shell find $(src_path)/.) )
						My_All_Files := $(My_All_Files:$(MY_CPP_PATH)/./%=$(MY_CPP_PATH)%)

						MY_CPP_LIST  := $(filter $(MY_FILES_SUFFIX),$(My_All_Files))
						MY_CPP_LIST  := $(MY_CPP_LIST:$(LOCAL_PATH)/%=%)
							//������˼�Ƕ�MY_CPP_LIST��ÿһ��,Ӧ��ð�ź���Ĺ���,������ʲô��?������$(LOCAL_PATH)/%=%,��˼��,
							��������$(LOCAL_PATH)/��ͷ����,����ȡ���沿��
						LOCAL_SRC_FILES := $(MY_CPP_LIST)

						//���У���
							���ϴ�����,����MY_FILES_PATH����Դ�ļ�����Ŀ¼,MY_FILES_SUFFIX����Դ�ļ��ĺ�׺��
							#MY_CPP_PATH := $(LOCAL_PATH)/
							#My_All_Files := $(shell find $(MY_CPP_PATH) -name '*.*')
							#My_All_Files := $(My_All_Files:$(MY_CPP_PATH)/./% = $(MY_CPP_PATH)%)
							#$(info $(My_All_Files))
							#
							#MY_CPP_LIST := $(filter %.cpp ,$(My_All_Files))
							#MY_CPP_LIST := $(MY_CPP_LIST:$(LOCAL_PATH)/%=%)


							#$(warning 111 $(LOCAL_PATH))
							#$(info $(LOCAL_PATH))
							#MY_CPP_PATH := $(LOCAL_PATH)
							#
							#$(info $(MY_FILES_PATH))
							#MY_FILE_SUFFIX := %.cpp
							#
							#$(info $(My_All_Files))
							#My_All_Files := $(foreach src_path,$(MY_CPP_PATH),$(shell find $(src_path)/.) )
							#My_All_Files := $(My_All_Files:$(MY_CPP_PATH)/./%=$(MY_CPP_PATH)%)
							#
							#MY_CPP_LIST := $(filter $(MY_FILE_SUFFIX),$(My_All_Files))
							#MY_CPP_LIST := $(MY_CPP_LIST:$(LOCAL_PATH)/%=%)

							//���Թ������У�
							#	$(wildcard $(LOCAL_PATH)/../../../SouthCoord/SouthCoord/*.CPP)
							#MY_CPP_LIST += ../../../SouthCoord/SouthCoord/SouthCoordLib.CPP
							#MY_CPP_LIST += $(LOCAL_PATH)/../../../SouthCoord/SouthCoord/SouthCoordLib.cpp
							#'E:/gnss_lib/template/SouthCoord/SouthCoord/SouthCoordLib.cpp'
							#$(info $(MY_CPP_LIST))
							ֱ����Ԥ���뿽�������ˣ�
								//���������һ����Ŀ��Դ�ļ�ֻ����java��
								key��eclipse external tools cinfigurations �����ļ�
									bat ����ֱ������������ļ�λ�õ� Location �Ϳ����ˣ�//ע��windowsֻ��ʶ��\����ʶ��/
										copy ������http://www.2cto.com/kf/201012/79866.html

				http://www.cnblogs.com/liulipeng/p/3524115.html  �߼�д��
					http://blog.csdn.net/asmcvc/article/details/9311573  cygwin�İ�װ
					ѡ���()
						binutils��The GNU assembler��linker and binary utilities
							http://mirrors.163.com/cygwin/x86/
							�����֣� �������£� rename 1.classpath .classpath
							//Ч�����񲻶԰�����
							ѧ��ʹ��objdump�鿴.so�ľ������ݡ�
						http://blog.csdn.net/pz0605/article/details/52193450
						http://blog.csdn.net/yilovexing/article/details/51911252
						http://www.linuxidc.com/Linux/2011-06/37588.htm ��װ��������
						http://www.cnblogs.com/ustccq/archive/2013/06/14/3134908.html ѡ�� ����
						http://blog.chinaunix.net/uid-20558494-id-2803025.html cygwin ����
							Ҫ��cygwin/bin�Ļ���������ӵ�path�У�����Ҫ��������������֮ǰ��//��������windows������unix�������й��ܣ�
							http://blog.sina.com.cn/s/blog_9d30c8430100y6yo.html ��������������
							http://blog.csdn.net/jiubugeinifo/article/details/9357077
							http://blog.csdn.net/duguduchong/article/details/7680650 ����windows����Ŀ¼
		���ݴ���
			//http://www.cnblogs.com/luxiaofeng54/archive/2011/08/20/2147086.html ʾ��
				//String
				( JNIEnv* env,jobject thiz,jstring msg )
					char data[128];
					memset(data, 0, sizeof(data));
					char *c_msg = NULL;
					c_msg = (char *)(*env)->GetStringUTFChars(env, msg, 0);//��ȡJava�㴫������msg��
					//(*env)->ReleaseStringUTFChars(env, msg, c_msg);//������÷��أ�ʹ������Ҫ֪ͨ�����ƽ̨����ͷ���Ӧ�ռ�
					return (*jniEnv)->NewStringUTF(env, "This is send by C JNI");
				//���飺����ڱ��ش����д���һ���ַ������鲢�������ظ�java�����ߣ�
					Java�˴��룺
						int[] array2 = t.getArray(10);//����
						System.out.println("-------");
						for(int i : array2){ System.out.println(i); }
				(JNIEnv *env, jobject jobj, jint len)//���أ�jintArray
					//����һ��ָ����С������
					jintArray jint_arr = (*env)->NewIntArray(env, len);
					jint *elems = (*env)->GetIntArrayElements(env, jint_arr, NULL);//��ȡ����Ŀ�ͷ��ַ��
					int i=0;
					for(; i<len;i+++){ elems[i]=i; }
					//ͬ��
					(*env)->ReleaseIntArrayElements(env, jint_arr, elems, 0);
					return jint_arr;
				// http://www.zhimengzhe.com/Androidkaifa/126901.html //���飻
				double //http://blog.csdn.net/randyleonard/article/details/53707098  jni ���ݽ��� double ��������ֵ
			http://4895268.blog.51cto.com/4885268/1371620 //ָ�� ����ֵ
				�������
						���C++/C��ָ�뺬�д�Java�д��ݵ�������Ϣ�����������´���
						typedef struct _Para_tag
						{
							int x;
							short y;
							char az[100];
							char h;
						}Para_Tag;
						C++/C : void setPara(Para_Tag *pstTag)

						Java:
						public class Para_Tag
						{
							int x;
							short y;
							String z;
							char h;
							long t;
						}
						public void setPara(Para_Tag   tag);

						JNI:
						JNIEXPORT void  JNICALL Java_setPara_ 1native (JNIEnv *env, jclass thiz, jobject obj)
						{
							Para_Tag  tag;

						jclass DataCls = env->FindClass("com/Para_Tag");//��ȡ���������ͣ�
						jfieldID dataId = env->GetFieldID(DataCls, "x", "I");//��ȡ���͵���id�������ͣ����������������ͣ�
						tag.x = env->GetIntField(obj, dataId);

						dataId = env->GetFieldID(DataCls, "y", "S");
						tag.y = env->GetShortField(obj, dataId);

						dataId = env->GetFieldID(DataCls, "z", "Ljava/lang/String;");
						jstring jstr = (jstring)env->GetObjectField(obj, dataId);

						const char* str;
						jboolean isCopye = false;
						if(NULL != jstr)
						{
							str = env->GetStringUTFChars(jstr, &isCopye);
						}
						if(str == NULL)
						{
							return;
						}

						strncpy(tag.az,str,100);
						tag.az[99] = '\0';

						dataId = env->GetFieldID(DataCls, "h", "C");
						tag.h = env->GetCharField(obj, dataId);

						dataId = env->GetFieldID(DataCls, "t", "J");
						tag.t = (jlong)env->GetLongField(obj, dataId);

						setPara(&tag);//��Ҳ����

						}
			//http://blog.csdn.net/wishchin/article/details/46711105  static native�ͷ�static
			//http://blog.csdn.net/bluewindtalker/article/details/54564111  ���õ���
				 // http://blog.csdn.net/android_robot/article/details/6942505 //
				//http://leave001.blog.163.com/blog/static/162691293201242452251332/ ���ض����������Ҫ
					���autoboxing�йء�������Integer p1 = 0���ַ�ʽʱ��javaʹ��autoboxing���ƽ�0��װ��һ��Integer�����У�
					��ʱʹ����Integer���valueOf��������java�����У���һ���ܹ�������󣬶�����-128��127���С���֣�����static pool�з���һ����̬�����������Χ��ģ���newһ��Integer��
					//http://www.cnblogs.com/eddy-he/archive/2012/08/09/2629974.html //�������ͣ�
					//http://blog.chinaunix.net/uid-26524139-id-3181305.html  //��������

			8�л����������ͼ���Ӧ�ķ�װ��
				//���Ƕ�Ӧ�Ļ������͵�����ĸ��д
				//http://blog.csdn.net/feiyudiaoling/article/details/51354413 �໥ת��
					jni�أ�

				//http://www.cnblogs.com/hupp/p/4849656.htmlc
				//http://blog.csdn.net/zhengTornado/article/details/51417268 --ʵ��
				http://dolphin-ygj.iteye.com/blog/519492 --JNI���ݻ�������ת��

cygwin��ʹ��
		http://blog.csdn.net/fengsh998/article/details/8136287 ��windowƽ̨��ģ��Liunxʹ��GCC�������б���C��SO�⡣
			��Liunx�µ��ļ���
				.o,��Ŀ���ļ�,�൱��windows�е�.obj�ļ�
				.so Ϊ�����, ��shared object,���ڶ�̬���ӵ�,��dll���
				.aΪ��̬��, �Ǻö��.o����һ��,���ھ�̬����
				.laΪlibtool�Զ����ɵ�һЩ����⣬ vi�༭�鿴
			���Ƚ�.c�ļ�����Ϊ.o�ļ�����ͨ��o�ļ������Ϊ��̬��(.a)�ļ�
				gcc -c mathunits.c �س���Ȼ�����ʹ��ls����鿴������ļ���

				�ٽ�.o�ļ�����Ϊ.a��̬���ļ���
				ar -crv libunits.a mathunits.o
			gcc  -shared -fPIC -o libdyunits.so mathunits.o
					-shared ��ѡ��ָ�����ɶ�̬���ӿ�
					-fPIC ��ʾ����Ϊλ�ö����Ĵ���
					-L. ��ʾҪ���ӵĿ��ڵ�ǰĿ¼��
			��̬�������ʹ�ø�����ʹ������һ���������̬��Ͷ�̬��ͬʱ���ڣ����ȵ��ö�̬�⡣
			gcc cmain.c libdyunits.so -o testlib
			һ��ͨ�õ� makefile �Ҽ򵽷� http://blog.chinaunix.net/uid-25838286-id-3204219.html
					//���ԣ�
				http://www.cnblogs.com/lidabo/p/4521123.html  ��

Swig��̣�
	swig��ʹ�÷���
		1��swig��������
		1����ӽӿ��ļ�*.i������c/c++�ṩ��Դ�ļ��ṩ�ĺ�����д��
		2���������swig��wrap�ļ���*.mk�ļ���
			������paakage���������ļ��У�
			��mk�ļ�������ԭ����mk�ļ��У�
		3��Ȼ��Ϳ���ֱ�ӵ��ã�
		//���е�ָ�룬�ṹ����������������long�����ͣ��ܲ����������޷�ʹ�ã�
			http://blog.csdn.net/zhoubl668/article/details/6641350 swig�Ľӿ��ļ����﷨��
			http://blog.csdn.net/qq_16064871/article/details/52474335 ��������ת��
		http://blog.csdn.net/fengsh998/article/details/8140587  swig
		http://blog.csdn.net/qingh520/article/details/8955026 swig ��װ������
			����swig�󣬰�exe������path��Ȼ��ͨ��������������
				1��Ҫ��д.i�ӿ��ļ���java����Ȼ������ļ�����Ŀ¼��swig -Java example.i ;
					����Ǳ���c++ ��.i�ļ� swig c++ -java example.i ��
					���JAVA����Ҫָ�����������·������ʹ��һЩ�����磺
						swig -c++  -java -package com.example -outdir ./  -l../include example.i
						-package ��ָ��JAVA�����磺com.example
						-outdir ��ָ�����ɵ��ļ����·�� ./��ʾ��ǰ·���¡�
					//ע�⣺%{%}֮�������Ӧ����ע�ͣ����ǡ�%{ �� %} ֮����������ݻ�ԭ�ⲻ���ظ��Ƶ����ɵİ�װ���ļ���
						http://blog.csdn.net/u012637501/article/details/41278127 �򵥽���
				2������������.java�ļ���wrap�ļ�����example_wrap.c�ļ������SO��
					��CYGWIN
					���뵽sojavaĿ¼
					��example.c ��example_wrap.c�������Ӧ��.o�ļ���
						�����������Ҫjni.h��jni_md.h����Ϊ�ҵ�JDK��1.6�ġ��տ�ʼ��֪����Ҫ������ڱ��ʱ���ϱ���
						//���￪ʼ��ִ�в����ˣ��޷�����example_warp.o�ļ���
						-l ��������.i�ļ����ڵ�·����
		swig��demo��
			http://blog.csdn.net/hai836045106/article/details/39371777  hello-jni demo
				һ������SWIG�������úû�������
				����HelloJniΪ����
					����ndk sample��HelloJni���̡�
			http://blog.csdn.net/koozxcv/article/details/50779806
				//�����в��ִ�����ע�ͣ�
	//*.i���ļ���д��
	%module Unix//ģ������Unix
	%{
	#include <unistd.h>//����ϵͳ��getuid������
	//#include "SouthCoordLib.h"
	%}

	typedef unsigned int uid_t;

	extern uid_t getuid(void);
	//extern int AddNum(int a,int b);
	//extern void XYZToBLH84(HSOUTH hd,double x,double y,double z,double* b,double* l,double* h);

0328:
	�о�Android����c++��̬��ķ�����
		--�������ɣ�jni c++ ����
		1��jni���ã�
			JNI�Ǳ������Ա�̽ӿڡ�������������JVM�е�Java�������C��C++����д�ı��ش����໥������
			������⣺
				//http://www.360doc.com/content/10/1012/06/3822981_60261755.shtml  ����Դ��������Ŀ¼��android-2.2\development\samples\SimpleJNI
				//http://www.cnblogs.com/lijunamneg/archive/2012/12/19/2825496.html  C��C++����ʱ��JNIʹ������
				//http://lib.csdn.net/article/cplusplus/53583	�����JNI��ʹ�ü��е�C/C++�� ��������
			//http://www.2cto.com/kf/201207/143036.html android����JNI����C++�Զ�����
			//http://zzbupt.iteye.com/blog/1876496 ���
			//http://blog.csdn.net/super_level/article/details/21243533  //TestNDK2 �Ƚϸ��ӣ�����һ����ʱ������ε��ÿ⺯����
				1������ADT��NDK
				2����ADT������NDK·��
				3���������б��ش����Android Project
				4����дJava�˴����C++�˴���
					a��Java�ˣ����һ���ࣺ��Ҫ�̳���Android�е���
						Ȼ��javah�������Program �ⲿ���ߣ�
							Location��${system_path:javah}:javah������·����
							Working Directory��${project_loc}:��������Ŀ¼
							Arguments��
								-v -classpath "${project_loc}/bin/classes" -d "${project_loc}/jni" ${java_type_name}
								//-v:���� //-classpath ���·�� //��classesĿ¼�µ�jniĿ¼�¿��� //�ļ����ͣ�
					b��Java�˵���JNI�����Ĵ��룺
						��MainActivity��Ϊ��
					c����дC++���룺
						�򿪸ղ�ϵͳ���ɵ�TestNDK2.cpp���޸ĳ����£�//ԭ��cpp�ļ�����.h�ļ�������һ���ģ�

				5���������ɵ�.so�ļ���Ŀ��ƽ̨
					���Application.mk�ļ�����ӣ�APP_ABI : = armeabi armeabi-v7a mips x86
						�ٱ���ʱ�ᷢ�������˶�Ӧ�����ĸ�ƽ̨��.so�ļ���//libsĿ¼�£�����ò��û�����ɣ�
				6��Java��C++���ϵ���
					ע�⣺
						?C++�ĵ������м�����ӳٲ��������ã�Ҳ���ǳ���������һ����ſ��Կ�ʼ���ԣ�����Ҫ���ԵĴ���һ��Ҫ�Ǽ����Ӻ���ܵ��ԣ�����
						?�ϵ�������C++�в���Ч
					a������c/c++ Build:ndk_build NDK_DEBUG=1
					b���������öϵ㣨ֻ����C++�У��Ϳ������������ˣ�Debug As ->Android Native Application��
						//����???
					C���������ԣ�
						�޸�MainActivity��������
						//���ڿ����ˣ�

			//http://blog.csdn.net/smilefyx/article/details/52416539   //JniStudy	//androidʵ��appͨ��jni����C/C++����
				//�Ƚϼ򵥵ĵ��ã�����û����ʾ���ݣ�
				1.�½�android����
				2.�½�java�ϲ㷽��
					//ֻ�����һ���ࣿ
					//���ฺ�����so�ļ�������so�ļ��ĺ���������so�ļ��ĺ���(������Բ��ã�)
				3.����jniͷ�ļ�//������ӵ��ഴ��.h�ļ����Լ�ʵ��.cpp�ļ���
					//javah -jni ���
						//�����ַ�����cmd ����һ����External Tool��
							//cmd ������һ��.h�ļ���
							//Add Native֮��ͻ���jni�ļ��к�cpp��ͬʱ����һ��jni.h�ļ������ļ����ɵĲ�һ������
				4.�½�jniʵ��
					//����ͷ�ļ����ʵ���ļ���
					�����ǣ����ʵ���ļ������������Щͷ�ļ���ôʶ��
						//ͬʱû��c/c++ѡ�����Ŀ�����У�//��Ȼ��ֻ��Add Native֮��Ż��У�
							//ȡ��Add Native�ķ�����// http://blog.csdn.net/lqhed/article/details/51613925
						//��� �޷����� cygpath ��ʹ������ //ע��·���в��ܺ��пո�
							go to your project right click there.then take properties and select the c/c++ build and
								there you can see the build settings .and in the build settings give the path of ndk in your system like:
									D:\android\android-ndk-r8d\ndk-build.cmd NDK_DEBUG=1
							With NDK r8d, you don't need cygwin. Maybe the project you import was tuned for an older version,
								and maybe it defined ndk-build.sh as the C++ build command. You should use ndk-build.cmd
								or simply ndk-build (utilizing Windows command line conventions)
							You can set an environment variable
								NDK_HOME = [your path to ndk]
							//�޸ģ�ndk-build ��${NDK_HOME} D:\Program Files\android_sdk\android-ndk-r8d\android-ndk-r8d\ndk-build.cmd NDK_DEBUG=1
						//DAndroid NDK: WARNING: APP_PLATFORM android-14 is larger than android:minSdkVersion 8 in ./AndroidManifest.xml	JniStudy		line 128, external location: F:\android\ndk-r8d\android-ndk-r8d\build\core\add-application.mk	C/C++ Problem
							//http://www.cnblogs.com/frydsh/archive/2013/11/21/3435553.html
							//APP_PLATFORM := android-8 ��jni/Application.mk�ļ��У����û������ļ��ʹ�������ļ���
						//ʵ���ļ���ʱ����ʾ�Ҳ���cutils/log.hͷ�ļ�
							//http://www.jb51.net/article/41664.htm  δ�����
							//http://blog.csdn.net/zengraoli/article/details/11644815 ��������ʹ�ã�
				5������jni so��
					//ֱ��ndk����so�⣿

				6������jni�⵽������
					�ڹ���libsĿ¼���½�armeabiĿ¼��armeabi-v7aĿ¼�������ɵ�jni��ŵ���Ŀ¼�¡�

				7������
				8��Դ������
					//�ܽ᣺����so���裺
					1������so�ļ��ĺ�����
					2������so�ļ���
					3������so�ļ��ĺ�����
						Ctrl + Shift + F6 ������ʵ�����л������༭ҳ��༭ҳ֮���л��Ŀ�ݼ�
						java���ں�deBug���Դ����л���ݼ�:   Ctrl + Shift + F8
						�鿴��ݼ��б�Ŀ�ݼ�:   Ctrl + Shift + L
						�ϵ��ݼ���Ctrl+Shift+B

			//http://blog.csdn.net/wwj_748/article/details/28136061   //TestNativeCode  //JNI_��򵥵�Java����C/C++����
				���裺
					1���½�java���̣�TestNativeCode �½�������com.wwj.nativecode �½��ࣺTestNativeCode������һ������;
					2����javah -jni ��������.h�ļ���
					3����vs 2008���½����� console dll �հף�
						a������.h�ļ�������jni.h��jni_mab.h�ļ�����jdk�п�����
						b�����source.cpp�ļ�������ͷ�ļ�ʵ�ֺ�����
						c�����ɣ�Ȼ���dll·���ŵ�path����java����ʶ��
					4������java����
				package com.wwj.nativecode;
				public class TestNativeCode {
					//�������ط���
					public native void sayHello();
					static {
						System.load("nativeCode");
					}
					public static void main(String[] args){
						//���ض�̬��
						TestNativeCode nativeCode = new TestNativeCode();//�½�һ���ࣻ
						nativeCode.sayHello();//������ķ�����
					}

				}
				//ע��㣺
					1��������Ӵ�������java��Ŀ������android��Ŀ��
					2��javah��������ʱ�����н�����ȱ����-jni �Ĳ�����
					3��64��32λ�����𣬼ǵã�

	2. ѡ��һ�ֺ��ʵ�c++�ӿڷ�װ����������Android���á�
		1���麯���ķ�����
			//http://www.cnblogs.com/cbscan/articles/2047269.html
		2������c++�У�dll��ģ����Ⱪ¶�ӿڵļ��ַ�ʽ��
			���ַ�ʽ��a������API�����ķ�ʽ��b��������ķ�ʽ��c��COM��ʽ��
				//http://www.cnblogs.com/weiym/archive/2012/08/29/2662559.html
				��c���Է�װC++�ķ�ʽ��
					//http://blog.csdn.net/caspiansea/article/details/9676153
				c++�ӿڵ�ʵ���ܽ᣺
					//http://qimo601.iteye.com/blog/1393427
			��ƽ̨ע��㣺
				�ṩ�ӿڣ�������������ԭ�����ͣ�������ȫ����ָ�롣
				��Ҫ���Ⱪ¶����������Ҫ�õ������ֹ������ڴ档
				���е������������ȡ�
				���еĺ�������Ӧ���з���ֵ�����еĴ�����������������
				windows�±����pdb��
				�ӿ��б�����һ����ѯ�汾�ŵĽӿڡ�
				������ʷ�ӿ�����չ����������½ӿڡ�
				������дһ���ӿ��ֲᡣ

				��Ҫע�������Ҫ���������⣺�������ͣ��ڴ����
��					���������ڲ�ͬ��ƽ̨�Ͽ��ܻ���ֳ��Ȳ�һ�£���������Ҫ������������������ڴ����
					����Ҫ˭����ľ���˭�ͷţ������Ľӿ��ڲ��������ڴ湩�ⲿʹ����ôһ��Ҫ�ṩ�ӿ����ⲿ����ȥ�ͷ��ڴ棨
					��Ϊ�ڴ����Ŀ����ڲ��죩

		c++ callback �ļ��ַ�ʽ��
			http://www.cnblogs.com/weiym/archive/2012/08/28/2660053.html

*/

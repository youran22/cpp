/*


java 基础练习
android
	eclipse的快捷方式
	eclipse的界面配置
android调用so文件
Jni编程
cygwin的使用
Swig编程

http://blog.csdn.net/hemeinvyiqiluoben/article/details/50370956  拖拉

java 基础练习
	http://www.yiibai.com/java/java_object_classes.html
	LOCAL_LDLIBS := -llog
	swig -Java -package com.apress.swig -outdir src/com/apress/swig jni/Unix.i
		//-Java ：命令 -package ：生成的类名放在哪个包下面； -outdir :  生成的类文件放在哪个路径下？  接口文件；
		//-java 小写才识别，大写Java不识别；
	怎么查看类中的字段和方法的签名: 使用javap命令:
		javap -s -p JNIDemo.class

	java基本语法：
		打包APK ：
			http://blog.csdn.net/luoyin22/article/details/7862742 eclipse
				在虚拟机中安装apk：
					http://blog.csdn.net/zouxiongqqq/article/details/50554630
						没效？怎么找到安装的app？
							//另外一种方式：
							将下载好的apk放到到Android SDK的Tools文件夹中（APK和emulator.exe同文件夹）
							执行adb install Scan.apk命令即可执行安装apk
		Activity :
			Activity四种启动模式  http://blog.csdn.net/shinay/article/details/7898492/
		String的用法：
			//https://wenku.baidu.com/view/1fd047a4dd3383c4bb4cd2b8.html
			String s = "37,78584";
			int ival = Integer.parseInt(s.replace(",", ""));
			double dval = Double.parseDouble(s.replace(",", ""));
			float fval = Float.parseFloat(s.replace(",", ""));
				将字符串转化为整型；
				int i = Integer.parseIn(String str);
				int i = Integer.valueOf().intValue();
				注：Integer.parseIn 和 Integer.valueOf 不同，前者生成的是整型，而后者是一个对象，所以要通过intValue()来获得对象的值；

			String str = null;
				str = String.format("Hi， %s", "王力");
				System.out.println(str);
					//好笑：这样竟然会造成程序崩溃：
					String str="a";//
					str.format("Hi, %s", "王力");
					System.out.pirntln(str);
			format：
				http://blueram.iteye.com/blog/441683
				%b 布尔类型  true
				%d 整数类型（十进制） 99		//请非常注意！！！//int,long,byte
				%x 整数类型（十六进制） FF
				%o 整数类型（八进制） 77
				%f 浮点类型 99.99				//请非常注意！！！//double
				%a 十六进制浮点类型 FF.35AE
				%e 指数类型 9.38e+5
				%g 通用浮点类型（f和e类型中较短的）
				%h 散列码
				%% 百分比类型 ％
				%n 换行符
				%tx 日期与时间类型（x代表不同的日期与时间转换符
android
	xuexi 步骤
	http://www.cnblogs.com/tinyphp/p/3831562.html 布局
		http://blog.csdn.net/llping2011/article/details/9992941 如何使用布局文件 五大布局详解
		http://www.cnblogs.com/lwbqqyumidi/p/3776184.html 几个主要函数的讲解
	http://blog.csdn.net/netdxy/article/details/50691915 基本控件
			http://www.cnblogs.com/whoislcj/p/5708778.html 自定义
			http://limingnihao.iteye.com/blog/851369
			http://blog.csdn.net/j903829182/article/details/40660275
	http://cloudsgarden.lofter.com/  blog
		http://blog.csdn.net/zzhays/article/details/10489629 牛人的阅读代码

	学习网站：
	http://www.csdn.net/article/2015-02-23/2824006 学习网站
		都是英文多
	http://blog.csdn.net/banketree/article/details/24982021    Android Framework 记录之二

	eclipse的快捷方式
		alt+shift+r：重命名
		Control-Shift-T: 打开类型（Open type）。按ctrl+t会列出接口的实现类列表
		F3: 打开申明（Open declaration）。
		打开方法的实现：按住ctrl 之后这个方法就变成了蓝色的连接 一点就进去了
		Ctrl+Shift+/  －－在代码窗口中是这种/ *~* /注释
		打开当前文件的所在文件夹：
			1.External Tools Configurations...点击
			2.左侧Program - new - Location中输入值  C:\WINDOWS\explorer.exe
			3.Arguments输入值  /select,${container_loc}\${resource_name}
				//当前选择文件， 包含当前文件的文件夹\文件名称？
			4.点击apply - ok
			5.使用时，选中当前文件运行openFile，即自动跳到当前文件所在文件夹位置。
		F3        －－跳到声明或定义的地方。
        F5       －－单步调试进入函数内部。
        F6       －－单步调试不进入函数内部，如果装了金山词霸2006则要把“取词开关”的快捷键改成其他的。
        F7       －－由函数内部返回到调用处。
        F8       －－一直执行到下一个断点。



		Control-Q: 回到最后一次编辑的地方
		Control-Shift-G: 在workspace中搜索引用（reference）。
		Control-Shift-F: CodeàJavaàPreferencesà根据代码风格设定重新格式化代码。
		 Control-/: 对一行注释或取消注释。对于多行也同样适用。
		Ctrl+Alt+H：如果你想知道一个类的方法到底被那些其他的类调用
		Alt+左右方向键
			我们经常会遇到看代码时Ctrl+左键，层层跟踪，然后迷失在代码中的情况，这时只需要按“Alt+左方向键
			”就可以退回到上次阅读的位置，同理，按“Alt+右方向键”会前进到刚才退回的阅读位置，就像浏览器的
			前进和后退按钮一样。

		eclipse的界面配置
			//http://blog.csdn.net/tianlianchao1982/article/details/53463527
				字体：
					窗口(Window)-首选项（Preferences）-常规（General）-外观(Appearence)-颜色与字体(Colors And Fonts)，
					在右边的对话框里选择Java - Java Editor Text Font，点击出现的修改（Change）按钮，
					可以设置显示在在主窗体中程序的字体大小，设置完之后点击右下角的应用(Apply)，最后点击确定（OK）即可
				背景颜色：
					windows->Preferences->General->Editor->Text Editors	右边选择Appearance color options 选Background color 选择背景颜色
					背景颜色向你推荐：色调：85。饱和度：1 2 3。亮度：2 0 5//改为160好些？

android调用so文件
		为什么使用不了呢？
			1、看看其他的使用方式，能编译通过的例子，总结流程，加注释，理解过程；
				a、非要add native？
					//add native作用是什么？
					//什么情况下使用？
					//添加了什么内容？
					//步骤？
				b、不是应该LoadLibrary就可以使用函数了吗？
				c、
			2、studio的使用方式
			3、
		https://wenku.baidu.com/view/3b19c2ee5901020206409ca2.html 深入解析
		http://www.tuicool.com/articles/fYnmYjI    使用SO库时要注意的一些问题
		http://www.imooc.com/article/17298?block_id=tuijian_wz   //

		http://zwz94.blog.163.com/blog/static/3206039520131111101412959/  //Android如何调用第三方SO库
			//http://blog.csdn.net/lishaobo211985/article/details/52853167 需要更改包名？
			//http://www.docin.com/p-616596698.html
			//http://www.tongleer.com/1263.html
			1.将SO文件直接放到libs/armeabi下，然后代码中System.loadLibrary("xxx")；
				再public native static int  xxx_xxx_xxx()；
				接下来就可以直接调用xxx_xxx_xxx()方法；
					//好像不行？
					//
			2.第二种方案，创建自己的SO文件，
				在自己的SO文件里调用第三方SO，
				再在程序中调用自己的SO，这种比较复杂，需要建java类文件，生成.h文件，
				编写C源文件include之前生成的.h文件并实现相应方法，
				最后用android NDK开发包中的ndk-build脚本生成对应的.so共享库；
			1.上面两种方案是否可行？不可行的话存在什么问题？
			2.两种方案有什么区别？为什么网上大部都是用的第二种方案？
			3.只有一个*.so文件，并提供了详细的接口说明，是否可在ANDROID中使用它？
				首先要看这个SO是不是JNI规范的SO，比如有没有返回JNI不直接支持的类型。
				也就是说这个SO是不是可以直接当作JNI来调用。
				如果答案是否定的，你只能选第二个方案。

				如果答案是肯定的，还要看你是不是希望这个SO的库直接暴露给JAVA层，
				如果答案是否定的，你只能选第二个方案，比如你本身也是一个库的提供者。

				用C调用第三方so
					void *handle;
					int (*call_method)(void);
					handle = dlopen(so_path, RTLD_LAZY);
					//函数指针
					call_method =  dlsym(handle, "method_name(调用方法的函数名)");
				另外一种方法：Android Studio的方法：
					//http://blog.csdn.net/chinawallace/article/details/48026207
				另外一种方法：
					//http://blog.csdn.net/guofu8241260/article/details/22274595
		上面的都不行？
			http://blog.csdn.net/jiuyueguang/article/details/9447245  //第一步;
			1、新建项目
			2、add native

			3、在activity添加代码：
				定义native函数声明；
			4、javah生成头文件:
				--可见：是根据调用本地类和函数名来生成.h文件的？
				为什么javah工具用不了？
					改使用（cd src中）：javah -jni  com.example.hello.MainActivity //这句命令是错的？应该说有native修饰的函数所在的类；
						--出现的问题：http://blog.csdn.net/z13144099248m/article/details/41775633
						--注意：
							究竟是src下的classes还是bin下的classes？
							究竟是定义的classes还是定义的？--经试验：定义的？
			5、编写jni文件夹下的hello.cpp文件
			6.编写jni文件夹下的Android.mk文件
				--add native 后自动添加；
				--需要再添加 Application.mk ?
			7.修改项目的编译选项：项目右键-》Properties-》C/C++ Build-》Build command中填写你的android-ndk的根目录；
				--一般会有默认？
			8.编译项目，项目右键-》build project，会看到控制台输出，说明我们的是正确的，good！
			9.运行android项目，会看到下图，说明是正确的，至此我们编写的库文件能够被正确的被自己的程序调用
			http://blog.csdn.net/jiuyueguang/article/details/9449737 第二步：
				1、新建项目
					新建跟so函数名一样的包名和类名；
				2、

			http://blog.csdn.net/jiuyueguang/article/details/9450597 第三步：
	ndk 编译多个cpp文件：
		1.将.h .cpp文件放到jni目录下，在eclipse中刷新就可以看到了；
		2.假设jni目录下有a.h,a.cpp,b.cpp三个文件；在Android.mk中像下面这样编辑LOCAL_SRC_FILES
		LOCAL_SRC_FILES :=a.cpp b.cpp
		这样就可以同时编译多个源文件了
		这样可以解决多个cpp文件嵌套包含的问题

		http://blog.csdn.net/meiliangdeng1990/article/details/50784553 	//在任意目录把自己写的C代码编译成Android可使用的静态库/动态库
			http://www.linuxidc.com/Linux/2014-12/110167.htm  常用ndk命令行参数
	添加log
		http://blog.csdn.net/luoshengyang/article/details/6581828
		http://blog.csdn.net/github_33304260/article/details/54799169
		http://www.2cto.com/kf/201205/132163.html 技巧
		jni：
			1.首先，在 Android.mk文件中需要加入：    LOCAL_LDLIBS := -llog
			2. 其次，包含如下库文件   #include <android/log.h>
			3. 使用方法示例    __android_log_print(ANDROID_LOG_INFO, "CDib::Attach", "--------%d,%d,%d,this->linebytes=%d\n",linebytes,width,height,this->linebytes); //按此形式打印变量    方便调用起见，可以使用宏定义    #define LOGI(msg)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, msg)    #define LOGE(msg)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, msg)
				--#include <android/log.h> * 一定要在<string.h>、<jni.h>之前？
		另外一种方式：
			http://www.tc5u.com/android/xg-170789.htm

Jni编程
	android的配置设置：
	搭建android环境：
		android开发的两个方式：
			Eclipse + ADT + SDK：
				ADT： (android development tools)安卓开发工具//新版的已经包含了eclipse IDE
			Android Studio + SDK：
		//http://jingyan.baidu.com/article/bea41d437a41b6b4c51be6c1.html  windows下的搭建步骤
		http://blog.csdn.net/jptiancai/article/details/23678073  Windows下C++文件编译.so 文件 实例：c++输出日志
		http://www.cnblogs.com/zoupeiyang/p/4034517.html#3 五步；
		http://blog.csdn.net/smking/article/details/7594019  Android开发搭环境步骤, ADT, JDK, SDK, NDK, Eclipse, CDT
			ADT， 这是为了方便Eclipse编写android程序所准备的一个控件//两种配置方式；
			SDK;
			Eclipse-->Windows-->Android SDK and AVD Manager下，去新建一个AVD， 并启动它， 如果成功启动， 则表示Android SDK已经安装完成
			Java是不能直接调用C写的dll, 或者exe代码或者库文件。需要使用到NDK进行中间转换。
		//http://www.runoob.com/w3cnote/android-tutorial-eclipse-adt-sdk-app.html  //使用Eclipse + ADT + SDK开发Android APP 基础入门
			//http://www.it165.net/pro/html/201410/24759.html    //windows下用ADT进行android NDK开发的详细教程（从环境搭建、配置到编译全过程）
				//http://blog.csdn.net/u013149325/article/details/40371873
		//http://www.cnblogs.com/xdp-gacl/p/4322165.html
		1、下载jdk文件，安装；配置JAVA_HOME环境变量；添加jdk到path中；
		2、下载sdk、ndk后：
			创建一个文件夹：AndroidDevelopTool
				把ADT、sdk、eclipse-jee-luna-SR2-win32-x86_64.zip三个文件放到文件夹下；
			Eclipse启动后：
				Install New Software...
					把ADT.zip文件路径 安装
				然后sdk关联：Open Preferences - Androi -
					配置ANDROID_SDK_HOME环境变量：添加一下到path：
					%ANDROID_SDK_HOME%\tools;%ANDROID_SDK_HOME%\platform-tools；
		1、准备工作：搭建android开发环境，包括jdk、ADT（新版的已经包含了eclipse IDE）、SDK等的下载安装，
			不会的自行百度，相关文章太多了，我在此不再赘述。
		2、在官网上下载NDK，网址：http://developer.android.com/tools/sdk/ndk/index.html。
			根据自己的操作系统平台（windows32或windows64或Linux或Mac）下载相应版本的NDK，然后双击解压到相应的文件夹。
		3、新建一个普通的android应用程序（注意最小支持的API版本要>=14）。如果是新手，不清楚这个，可以百度、谷歌。
		4、在ADT开发环境中设置NDK的路径：
			点击Window菜单，选择Preference，点击Android展开后点击NDK，设置NDK路径，点击Apply，
		5、添加Native Support
			右键工程，->Android Tools->Add Native Support。输入将要生成的.so文件的名字，点finish；
		6、设置C/C++的Paths and Symbols 右键工程，->Properties，点击C/C++ General展开，点击Path and Symbols，
			在右边Includes下，点击Add，把NDK文件夹下的   jni头文件和相应的C++头文件   添加进来。这一步非常重要，否则会报错，
			详情请见我的另一篇文章：http://blog.csdn.net/u013149325/article/details/40371873
	swigin的使用方法：
		把C/C++的代码嵌入Java等语言的开发工具
		//http://codingstandards.iteye.com/blog/830342  //Linux下的；
		//http://blog.csdn.net/a8572785/article/details/10427521  //window下 python；
	android的ndk使用方法：
	windows下把C++ dll项目编译成.so文件的方式：
		需要在linux下用gcc来编译这些代码。
		或者windows下在cygwin环境下也行
		在windows下或者用gcc也可以？
		不知你有没有做过对象的持久化？建议你用JNI在本地调用，然后利用对象的持久化序列化对象通过TCP通信，把对象传给Linux。
		//http://www.2cto.com/kf/201403/286784.html   //Android之Windows下生成动态库so并打包到APK中 //通过jni？？
		http://blog.csdn.net/qiuxiaolong007/article/details/7860610   //使用RegisterNatives方法传递和使用Java自定义类
	android ndk 调用第三方库生成动态库的步骤：
		//纯c和c++的区别；
			//http://www.diffen.com/difference/C_vs_C%2B%2B
			1、纯C指的是C89或者是C99标准;
			2、C++中的C实际上是以C++为标准的，也就是说把它按照C独立出来是没有意义。
			必须用纯C的时候：没有C++编译器可用（比如有嵌入式系统），但是有C编译器可用
			思想不同，c 是面向过程，c++面向对象
			C++多范式编程语言.
			C++和C最大的区别就是C++支持类（class)而C没有
		//http://blog.csdn.net/heng615975867/article/details/11904737 情况分析
		//http://blog.csdn.net/panpen120/article/details/42193003  DLL转换so(NDK配置)
			//http://blog.csdn.net/jiangxuchen/article/details/22883575
			//http://blog.csdn.net/heng615975867/article/details/11904737
			搜索技巧：ndk dll
			1、dll：dllAndroid.dll
				copy "$(OutDir)\$(TargetName).dll" "$(GNSS_DIR)\win32bin\"
				copy "$(OutDir)\$(TargetName).lib" "$(GNSS_DIR)\win32lib\"
				copy "$(OutDir)\$(TargetName).pdb" "$(GNSS_DIR)\win32bin\"
				copy *.h "$(GNSS_DIR)\include\$(ProjectName)\"
				API:
				CLASS:
				COM:
			2、新建项目，新建一个文件夹jni，在这个文件夹里在创建一个文件夹cpp,将你生成DLL的那些所有的.cpp和.h都放进去
				//就是add Native；
			3、在jni文件夹下面新建文件，flie,命名为Andriod.mk(要写后缀名)
				//已经添加了；但是要添加Application.mk:设置android平台版本；
				//mk文件的写法不一样；
			4、配置NDK
				main：
				Refresh：sp->只勾选jni文件夹；
				Build Option：
			5、生成so
			6.过程中遇到的问题
				（1）.cpp和.h里面有StdAfx.h，C标准库的东西，删掉
				（2）.库函数的地方删掉__declspec(dllexport)，这是DLL的东西
				（3）.我忘记截图了，就是指针赋空的NULL都得换为0
				（4）我用的随机数，不允许，在前面加了stdlib.h
					#include<stdlib.h>
					#include<time.h>
				(5)如果你用了C++STL的东西，像创建Andriod.mk的方式创建Application.mk,里面写
					在Application.mk文件中添加APP_STL := stlport_static
					或APP_STL := gnustl_static
		http://www.open-open.com/lib/view/open1453265030995.html  NDK实战：
			//http://blog.csdn.net/yanbober  //值得阅读的作者
		http://www.cnblogs.com/xiaorenwu702/p/5802015.html jni头文件详解与示例
		http://www.open-open.com/lib/view/open1453265030995.html ndk实战  ndk 开发教程 示例

	Android.mk 文件语法详解
		http://www.cnblogs.com/wainiwann/p/3837936.html
			BUILD_STATIC_LIBRARY：编译为静态库。
			BUILD_SHARED_LIBRARY ：编译为动态库
			BUILD_EXECUTABLE：编译为Native C可执行程序

			LOCAL_C_INCLUDES
		.h头文件无法识别：jni下的子目录
			http://blog.csdn.net/mfcing/article/details/48739629
			http://blog.sina.com.cn/s/blog_4c73bcc801011dfy.html
			http://oknostar.blog.163.com/blog/static/294361862012611111539579/
	http://blog.chinaunix.net/uid-20746260-id-3910616.html  //好文 NDK 优化方法？
		Android.mk语法：
			http://www.2cto.com/kf/201507/414799.html
			http://blog.csdn.net/wenchao126/article/details/8071526  shell脚本之find
			http://blog.csdn.net/zhoujiaxq/article/details/25972743 makefile函数
			http://www.cnblogs.com/wainiwann/p/3837936.html
			http://www.cnblogs.com/leaven/archive/2011/01/25/1944688.html
				LOCAL_PATH
					这个变量用于给出当前文件的路径。你必须在Android.mk的开头定义，可以这样使用：
						LOCAL_PATH := $(call my-dir)
						这个变量不会被$(CLEAR_VARS)清除，因此每个Android.mk只需要定义一次（即使你在一个文件中定义了几个模块的情况下）。
							宏函数’my-dir’, 由编译系统提供，用于返回当前路径（即包含Android.mk file文件的目录）。
								下面是GNU Make　‘功能’宏，必须通过使用'$(call <function>)'来求值，他们返回文本化的信息。

				BUILD_SHARED_LIBRARY
					指向编译脚本，收集所有的你在LOCAL_XXX变量中提供的信息，并且决定如何把你列出的源代码文件编译成一个共享库。
					注意，你必须至少在包含这个文件之前定义 LOCAL_MODULE 和 LOCAL_SRC_FILES ；注意这将生成一个名为lib$(LOCAL_MODULE).so的文件
				LOCAL_SRC_FILES
					这是要编译的源代码文件列表。只要列出要传递给编译器的文件，因为编译系统自动为你计算依赖。
					注意源代码文件名称都是相对于LOCAL_PATH的，你可以使用路径部分，例如：
						LOCAL_SRC_FILES := foo.c \
							toto/bar.c
						注意：在生成文件中都要使用UNIX风格的斜杠(/).windows风格的反斜杠不会被正确的处理。
				LOCAL_C_INCLUDES
				http://www.cnblogs.com/binxindoudou/articles/3205035.html   wildcard等进阶
					//引入单个目录的所有cpp文件
						#声明一个变量MY_CPP_PATH表示源码目录
						MY_CPP_PATH := $(LOCAL_PATH)/
						#获取目录下的所有文件
						My_All_Files := $(shell find $(MY_CPP_PATH)/.)
						My_All_Files := $(My_All_Files:$(MY_CPP_PATH)/./%=$(MY_CPP_PATH)%)
						#从My_All_Files中再次提取所有的cpp文件,这里也可以使用filter函数
						MY_CPP_LIST := $(foreach c_file,$(My_All_Files), $(wildcard $(c_file)/*.cpp) )
							//c_file中间变量
						MY_CPP_LIST := $(MY_CPP_LIST:$(LOCAL_PATH)/%=%)

						LOCAL_SRC_FILES := $(MY_CPP_LIST)
					//引入单个目录cpp和c文件
						#声明一个变量MY_CPP_PATH表示源码目录
						MY_CPP_PATH  := $(LOCAL_PATH)/
						#获取目录下的所有文件
						My_All_Files := $(shell find $(MY_CPP_PATH)/.)
						My_All_Files := $(My_All_Files:$(MY_CPP_PATH)/./%=$(MY_CPP_PATH)%)
						#从My_All_Files中再次提取所有的cpp文件,这里也可以使用filter函数
						MY_CPP_LIST  := $(filter %.cpp %.c,$(My_All_Files))
						MY_CPP_LIST  := $(MY_CPP_LIST:$(LOCAL_PATH)/%=%)
						LOCAL_SRC_FILES := $(MY_CPP_LIST)

					//引入多个目录的多个后缀名文件：
						MY_FILES_PATH  :=  $(LOCAL_PATH)/ \
							$(LOCAL_PATH)/../src_files/

						MY_FILES_SUFFIX := %.cpp %.c %.cc

						My_All_Files := $(foreach src_path,$(MY_FILES_PATH), $(shell find $(src_path)/.) )
						My_All_Files := $(My_All_Files:$(MY_CPP_PATH)/./%=$(MY_CPP_PATH)%)

						MY_CPP_LIST  := $(filter $(MY_FILES_SUFFIX),$(My_All_Files))
						MY_CPP_LIST  := $(MY_CPP_LIST:$(LOCAL_PATH)/%=%)
							//它的意思是对MY_CPP_LIST中每一项,应用冒号后面的规则,规则是什么呢?规则是$(LOCAL_PATH)/%=%,意思是,
							查找所有$(LOCAL_PATH)/开头的项,并截取后面部分
						LOCAL_SRC_FILES := $(MY_CPP_LIST)

						//不行？？
							以上代码中,变量MY_FILES_PATH保存源文件所在目录,MY_FILES_SUFFIX保存源文件的后缀名
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

							//尝试过都不行？
							#	$(wildcard $(LOCAL_PATH)/../../../SouthCoord/SouthCoord/*.CPP)
							#MY_CPP_LIST += ../../../SouthCoord/SouthCoord/SouthCoordLib.CPP
							#MY_CPP_LIST += $(LOCAL_PATH)/../../../SouthCoord/SouthCoord/SouthCoordLib.cpp
							#'E:/gnss_lib/template/SouthCoord/SouthCoord/SouthCoordLib.cpp'
							#$(info $(MY_CPP_LIST))
							直接用预编译拷贝命令了：
								//如何引用另一个项目的源文件只能是java？
								key：eclipse external tools cinfigurations 拷贝文件
									bat 处理：直接添加批处理文件位置到 Location 就可以了；//注意windows只能识别\不能识别/
										copy 参数：http://www.2cto.com/kf/201012/79866.html

				http://www.cnblogs.com/liulipeng/p/3524115.html  高级写法
					http://blog.csdn.net/asmcvc/article/details/9311573  cygwin的安装
					选择项：()
						binutils：The GNU assembler，linker and binary utilities
							http://mirrors.163.com/cygwin/x86/
							改名字： 命令行下： rename 1.classpath .classpath
							//效果好像不对啊？？
							学会使用objdump查看.so的具体内容。
						http://blog.csdn.net/pz0605/article/details/52193450
						http://blog.csdn.net/yilovexing/article/details/51911252
						http://www.linuxidc.com/Linux/2011-06/37588.htm 安装方法步骤
						http://www.cnblogs.com/ustccq/archive/2013/06/14/3134908.html 选择 配置
						http://blog.chinaunix.net/uid-20558494-id-2803025.html cygwin 配置
							要把cygwin/bin的环境变量添加到path中，并且要在其他环境变量之前；//这样才能windows下享受unix的命令行功能；
							http://blog.sina.com.cn/s/blog_9d30c8430100y6yo.html 环境变量的配置
							http://blog.csdn.net/jiubugeinifo/article/details/9357077
							http://blog.csdn.net/duguduchong/article/details/7680650 访问windows磁盘目录
		数据传递
			//http://www.cnblogs.com/luxiaofeng54/archive/2011/08/20/2147086.html 示例
				//String
				( JNIEnv* env,jobject thiz,jstring msg )
					char data[128];
					memset(data, 0, sizeof(data));
					char *c_msg = NULL;
					c_msg = (char *)(*env)->GetStringUTFChars(env, msg, 0);//获取Java层传进来的msg；
					//(*env)->ReleaseStringUTFChars(env, msg, c_msg);//如果不用返回，使用完后就要通知虚拟机平台相关释放相应空间
					return (*jniEnv)->NewStringUTF(env, "This is send by C JNI");
				//数组：如何在本地代码中创建一个字符串数组并将它返回给java调用者；
					Java端代码：
						int[] array2 = t.getArray(10);//调用
						System.out.println("-------");
						for(int i : array2){ System.out.println(i); }
				(JNIEnv *env, jobject jobj, jint len)//返回：jintArray
					//创建一个指定大小的数组
					jintArray jint_arr = (*env)->NewIntArray(env, len);
					jint *elems = (*env)->GetIntArrayElements(env, jint_arr, NULL);//获取数组的开头地址；
					int i=0;
					for(; i<len;i+++){ elems[i]=i; }
					//同步
					(*env)->ReleaseIntArrayElements(env, jint_arr, elems, 0);
					return jint_arr;
				// http://www.zhimengzhe.com/Androidkaifa/126901.html //数组；
				double //http://blog.csdn.net/randyleonard/article/details/53707098  jni 数据交换 double 参数返回值
			http://4895268.blog.51cto.com/4885268/1371620 //指针 带回值
				情况二：
						如果C++/C的指针含有从Java中传递的数据信息，就需做如下处理：
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

						jclass DataCls = env->FindClass("com/Para_Tag");//获取参数的类型；
						jfieldID dataId = env->GetFieldID(DataCls, "x", "I");//获取类型的域id；（类型，变量名，变量类型）
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

						setPara(&tag);//这也可以

						}
			//http://blog.csdn.net/wishchin/article/details/46711105  static native和非static
			//http://blog.csdn.net/bluewindtalker/article/details/54564111  引用调用
				 // http://blog.csdn.net/android_robot/article/details/6942505 //
				//http://leave001.blog.163.com/blog/static/162691293201242452251332/ 返回多个参数：主要
					这跟autoboxing有关。当你用Integer p1 = 0这种方式时，java使用autoboxing机制将0封装在一个Integer对象中，
					这时使用了Integer类的valueOf方法。在java语言中，有一个很诡异的现象，对于在-128～127间的小数字，会在static pool中返回一个静态对象，在这个范围外的，会new一个Integer。
					//http://www.cnblogs.com/eddy-he/archive/2012/08/09/2629974.html //基本类型？
					//http://blog.chinaunix.net/uid-26524139-id-3181305.html  //基本类型

			8中基本数据类型及对应的封装类
				//就是对应的基本类型的首字母大写
				//http://blog.csdn.net/feiyudiaoling/article/details/51354413 相互转换
					jni呢？

				//http://www.cnblogs.com/hupp/p/4849656.htmlc
				//http://blog.csdn.net/zhengTornado/article/details/51417268 --实验
				http://dolphin-ygj.iteye.com/blog/519492 --JNI数据基本类型转换

cygwin的使用
		http://blog.csdn.net/fengsh998/article/details/8136287 在window平台下模拟Liunx使用GCC环境进行编译C的SO库。
			在Liunx下的文件：
				.o,是目标文件,相当于windows中的.obj文件
				.so 为共享库, 是shared object,用于动态连接的,和dll差不多
				.a为静态库, 是好多个.o合在一起,用于静态连接
				.la为libtool自动生成的一些共享库， vi编辑查看
			面先将.c文件编译为.o文件，再通过o文件编译成为静态库(.a)文件
				gcc -c mathunits.c 回车，然后可以使用ls命令查看编译的文件。

				再将.o文件编译为.a静态库文件。
				ar -crv libunits.a mathunits.o
			gcc  -shared -fPIC -o libdyunits.so mathunits.o
					-shared 该选项指定生成动态连接库
					-fPIC 表示编译为位置独立的代码
					-L. 表示要连接的库在当前目录中
			动态库的连接使用跟静库使用命令一样，如果静态库和动态库同时存在，优先调用动态库。
			gcc cmain.c libdyunits.so -o testlib
			一个通用的 makefile 右简到繁 http://blog.chinaunix.net/uid-25838286-id-3204219.html
					//不对？
				http://www.cnblogs.com/lidabo/p/4521123.html  繁

Swig编程：
	swig的使用方法
		1、swig步骤整理：
		1、添加接口文件*.i，根据c/c++提供的源文件提供的函数填写；
		2、添加生成swig的wrap文件的*.mk文件；
			并根据paakage变量创建文件夹；
			把mk文件包含进原来的mk文件中；
		3、然后就可以直接调用？
		//所有的指针，结构体参数，变量都变成long的类型，很不合理？而已无法使用？
			http://blog.csdn.net/zhoubl668/article/details/6641350 swig的接口文件的语法？
			http://blog.csdn.net/qq_16064871/article/details/52474335 基础类型转换
		http://blog.csdn.net/fengsh998/article/details/8140587  swig
		http://blog.csdn.net/qingh520/article/details/8955026 swig 安装和配置
			下载swig后，把exe包含进path，然后，通过命令行启动：
				1、要编写.i接口文件（java），然后进入文件所在目录，swig -Java example.i ;
					如果是编译c++ 的.i文件 swig c++ -java example.i ；
					如果JAVA中需要指出包名和输出路径可以使用一些参数如：
						swig -c++  -java -package com.example -outdir ./  -l../include example.i
						-package 来指定JAVA包名如：com.example
						-outdir 来指定生成的文件存放路径 ./表示当前路径下。
					//注意：%{%}之间的内容应该是注释？不是。%{ 和 %} 之间的所有内容会原封不动地复制到生成的包装器文件中
						http://blog.csdn.net/u012637501/article/details/41278127 简单介绍
				2、编译后输出有.java文件和wrap文件。将example_wrap.c文件打包成SO；
					打开CYGWIN
					进入到sojava目录
					将example.c 和example_wrap.c编译成相应的.o文件。
						在这个过程需要jni.h和jni_md.h。因为我的JDK是1.6的。刚开始不知道需要这个，在编的时候老报错。
						//这里开始就执行不了了？无法生成example_warp.o文件；
						-l 用来连接.i文件所在的路径。
		swig的demo：
			http://blog.csdn.net/hai836045106/article/details/39371777  hello-jni demo
				一，下载SWIG，并设置好环境变量
				二以HelloJni为例子
					导入ndk sample的HelloJni工程。
			http://blog.csdn.net/koozxcv/article/details/50779806
				//不过有部分代码有注释；
	//*.i的文件编写：
	%module Unix//模块名：Unix
	%{
	#include <unistd.h>//包含系统的getuid函数？
	//#include "SouthCoordLib.h"
	%}

	typedef unsigned int uid_t;

	extern uid_t getuid(void);
	//extern int AddNum(int a,int b);
	//extern void XYZToBLH84(HSOUTH hd,double x,double y,double z,double* b,double* l,double* h);

0328:
	研究Android调用c++动态库的方法；
		--搜索技巧：jni c++ 深入
		1、jni调用；
			JNI是本地语言编程接口。它允许运行在JVM中的Java代码和用C、C++或汇编写的本地代码相互操作；
			深入理解：
				//http://www.360doc.com/content/10/1012/06/3822981_60261755.shtml  看看源码包的这个目录：android-2.2\development\samples\SimpleJNI
				//http://www.cnblogs.com/lijunamneg/archive/2012/12/19/2825496.html  C和C++函数时的JNI使用区别
				//http://lib.csdn.net/article/cplusplus/53583	如何在JNI中使用己有的C/C++库 看不懂？
			//http://www.2cto.com/kf/201207/143036.html android利用JNI调用C++自定义类
			//http://zzbupt.iteye.com/blog/1876496 详解
			//http://blog.csdn.net/super_level/article/details/21243533  //TestNDK2 比较复杂：定义一个计时器，多次调用库函数；
				1、下载ADT及NDK
				2、在ADT中配置NDK路径
				3、创建含有本地代码的Android Project
				4、编写Java端代码和C++端代码
					a、Java端：添加一个类：不要继承自Android中的类
						然后javah命令：或者Program 外部工具：
							Location：${system_path:javah}:javah的所在路径；
							Working Directory：${project_loc}:工程所在目录
							Arguments：
								-v -classpath "${project_loc}/bin/classes" -d "${project_loc}/jni" ${java_type_name}
								//-v:复制 //-classpath 类的路径 //从classes目录下到jni目录下拷贝 //文件类型？
					b、Java端调用JNI方法的代码：
						将MainActivity改为：
					c、编写C++代码：
						打开刚才系统生成的TestNDK2.cpp，修改成如下：//原来cpp文件名跟.h文件名不用一样的；

				5、配置生成的.so文件的目标平台
					添加Application.mk文件，添加：APP_ABI : = armeabi armeabi-v7a mips x86
						再编译时会发现生成了对应以上四个平台的.so文件；//libs目录下；但是貌似没有生成？
				6、Java与C++联合调试
					注意：
						?C++的调试器有几秒的延迟才能启动好，也就是程序运行了一会儿才可以开始调试，所以要调试的代码一定要是几秒钟后才能调试！！！
						?断点设置在C++中才有效
					a、设置c/c++ Build:ndk_build NDK_DEBUG=1
					b、完了设置断点（只能在C++中）就可以启动调试了（Debug As ->Android Native Application）
						//不行???
					C、重新试试？
						修改MainActivity代码如下
						//终于可以了；

			//http://blog.csdn.net/smilefyx/article/details/52416539   //JniStudy	//android实现app通过jni调用C/C++方法
				//比较简单的调用，但是没法显示内容；
				1.新建android工程
				2.新建java上层方法
					//只是添加一个类？
					//该类负责加载so文件，声明so文件的函数，调用so文件的函数(这个可以不用？)
				3.创建jni头文件//根据添加的类创建.h文件，以及实现.cpp文件；
					//javah -jni 命令；
						//有两种方法：cmd ，另一种是External Tool；
							//cmd ：产生一个.h文件；
							//Add Native之后就会有jni文件夹和cpp；同时生成一个jni.h文件（此文件生成的不一样？）
				4.新建jni实现
					//根据头文件添加实现文件；
					问题是：这个实现文件里面包含的那些头文件怎么识别？
						//同时没有c/c++选项；（项目属性中）//果然，只有Add Native之后才会有；
							//取消Add Native的方法：// http://blog.csdn.net/lqhed/article/details/51613925
						//解决 无法启动 cygpath 的使用问题 //注意路径中不能含有空格；
							go to your project right click there.then take properties and select the c/c++ build and
								there you can see the build settings .and in the build settings give the path of ndk in your system like:
									D:\android\android-ndk-r8d\ndk-build.cmd NDK_DEBUG=1
							With NDK r8d, you don't need cygwin. Maybe the project you import was tuned for an older version,
								and maybe it defined ndk-build.sh as the C++ build command. You should use ndk-build.cmd
								or simply ndk-build (utilizing Windows command line conventions)
							You can set an environment variable
								NDK_HOME = [your path to ndk]
							//修改：ndk-build ：${NDK_HOME} D:\Program Files\android_sdk\android-ndk-r8d\android-ndk-r8d\ndk-build.cmd NDK_DEBUG=1
						//DAndroid NDK: WARNING: APP_PLATFORM android-14 is larger than android:minSdkVersion 8 in ./AndroidManifest.xml	JniStudy		line 128, external location: F:\android\ndk-r8d\android-ndk-r8d\build\core\add-application.mk	C/C++ Problem
							//http://www.cnblogs.com/frydsh/archive/2013/11/21/3435553.html
							//APP_PLATFORM := android-8 在jni/Application.mk文件中（如果没有这个文件就创建这个文件）
						//实现文件的时候提示找不到cutils/log.h头文件
							//http://www.jb51.net/article/41664.htm  未解决；
							//http://blog.csdn.net/zengraoli/article/details/11644815 可以这样使用；
				5、生成jni so库
					//直接ndk生成so库？

				6、包含jni库到工程中
					在工程libs目录下新建armeabi目录和armeabi-v7a目录，将生成的jni库放到该目录下。

				7、调用
				8、源码下载
					//总结：加载so步骤：
					1、声明so文件的函数；
					2、加载so文件；
					3、调用so文件的函数；
						Ctrl + Shift + F6 （轻松实现了切换）：编辑页面编辑页之间切换的快捷键
						java窗口和deBug调试窗口切换快捷键:   Ctrl + Shift + F8
						查看快捷键列表的快捷键:   Ctrl + Shift + L
						断点快捷键：Ctrl+Shift+B

			//http://blog.csdn.net/wwj_748/article/details/28136061   //TestNativeCode  //JNI_最简单的Java调用C/C++代码
				步骤：
					1、新建java工程：TestNativeCode 新建包名：com.wwj.nativecode 新建类：TestNativeCode：定义一个函数;
					2、用javah -jni 命令生成.h文件；
					3、在vs 2008：新建工程 console dll 空白；
						a、拷贝.h文件；拷贝jni.h和jni_mab.h文件（从jdk中拷贝）
						b、添加source.cpp文件，根据头文件实现函数；
						c、生成，然后把dll路径放到path中让java程序识别；
					4、运行java程序；
				package com.wwj.nativecode;
				public class TestNativeCode {
					//声明本地方法
					public native void sayHello();
					static {
						System.load("nativeCode");
					}
					public static void main(String[] args){
						//加载动态库
						TestNativeCode nativeCode = new TestNativeCode();//新建一个类；
						nativeCode.sayHello();//调用类的方法；
					}

				}
				//注意点：
					1、这个例子创建的是java项目而不是android项目；
					2、javah这个命令的时候，文中介绍中缺少了-jni 的参数；
					3、64和32位的区别，记得；

	2. 选择一种合适的c++接口封装方法，方便Android调用。
		1、虚函数的方法：
			//http://www.cnblogs.com/cbscan/articles/2047269.html
		2、关于c++中（dll）模块对外暴露接口的几种方式：
			三种方式：a、导出API函数的方式；b、导出类的方式；c、COM方式；
				//http://www.cnblogs.com/weiym/archive/2012/08/29/2662559.html
				用c语言封装C++的方式：
					//http://blog.csdn.net/caspiansea/article/details/9676153
				c++接口的实现总结：
					//http://qimo601.iteye.com/blog/1393427
			跨平台注意点：
				提供接口，函数参数除了原生类型，其它的全部传指针。
				不要对外暴露锁，尽量不要让调用者手工分配内存。
				所有的数组必须带长度。
				所有的函数调用应该有返回值，所有的错误有清晰的描述。
				windows下保存好pdb。
				接口中必须有一个查询版本号的接口。
				不对历史接口做扩展，而是添加新接口。
				最后就是写一个接口手册。

				需要注意的最重要的两个问题：数据类型，内存管理
　					数据类型在不同的平台上可能会出现长度不一致，所以你需要处理这种情况，至于内存管理，
					就需要谁申请的就让谁释放，如果你的接口内部申请了内存供外部使用那么一定要提供接口让外部调用去释放内存（
					因为内存管理的库会存在差异）

		c++ callback 的几种方式：
			http://www.cnblogs.com/weiym/archive/2012/08/28/2660053.html

*/

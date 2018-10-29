/*

模块的修改提示：
主要函数的使用：
dlg文件的书写规则：
对话框修改流程：
函数的理解：
向量的使用：



模块的修改提示：
		工具软件放置于\\192.168.10.115\software\pc_tools目录
	还是要熟练掌握格式化输出函数：
		printf("%15E", PI)    输出"3.14159265E+000"
		printf("%.15E", PI)   输出"3.141592653589793E+000"
		printf("%.15G", PI)   输出？
		printf("%15G", PI)    输出？
		
	计算机组成原理→DOS命令→汇编语言→C语言（不包括C++）、代码书写规范→数据结构、编译原理、操作系统→计算机网络、数据库原理、正则表达式→其它语言（包括C++）、架构……

	对学习编程者的忠告：
		多用小脑和手，少用大脑、眼睛和嘴，会更快地学会编程！
		眼过千遍不如手过一遍！
		书看千行不如手敲一行！
		手敲千行不如单步一行！
		单步源代码千行不如单步Debug版对应汇编一行！
		单步Debug版对应汇编千行不如单步Release版对应汇编一行！
		不会单步Release版对应汇编？在你想单步Release版C/C++代码片断的前面临时加一句DebugBreak();重建所有，然后在IDE中运行。（一般人我不告诉他！）
		
		VC调试时按Alt+8、Alt+7、Alt+6和Alt+5,打开汇编窗口、堆栈窗口、内存窗口和寄存器窗口看每句C对应的汇编、单步执行并观察相应堆栈、内存和寄存器变化，这样过一遍不就啥都明白了吗。
		对VC来说，所谓‘调试时’就是编译连接通过以后，按F10或F11键单步执行一步以后的时候，或者在某行按F9设了断点后按F5执行停在该断点处的时候。

	万湘黔 2017-01-05 20:57:18
		@ALL：关于日志分级体制
		* 请认真体会wlog2()的设计理念和用法，在该用的地方用好它；
		* 新增warn_log()、info_log()、debug_log()、verbose_log()以便改造原有代码；
		
		另外，目前环境变量WLOG_LEVEL_THRESHOLD的默认值似乎错误，需要解决；
	万湘黔 2017-01-05 21:03:29
		@敖智博：注意gnss02_transform_test有部分测试用例已经失效
		——似乎之前没有初始化nMethod成员的场景，现在予以初始化后，结果有点意外
	万湘黔 2017-01-05 17:17:39
		wlog()机制增强：
		* 应个用wlog2()函数取代wlog()函数，以便指定level值；
		* level指定日志级别，定义域{0:错误,1:警告,2:信息,3:调试,4:详细}//最严重为0：错误，依次严重程度下降；
		* 用环境变量WLOG_LEVEL_THRESHOLD来控制日志输出详细程度；
		* 例如，设定WLOG_LEVEL_THRESHOLD为2，则只有level值为{0,1,2}的wlog2()调用语句产生日志；依此类推；
		* WLOG_LEVEL_THRESHOLD默认值为2；
		* wlog()已退化为wlog2()的一个调用，其中level值为2；
		万湘黔 2017-01-05 17:27:17
		也就是说：
		* 大家新写程序应该用wlog2()，不要再用wlog()
		* 之前旧的wlog()，大家在重构、调整性能时，应改为调用wlog2()，并指定恰当的level值；
		* 凡调用频率非常高的地方，应该给比较高的level值，以免造成性能瓶颈。//调用频率比较高的地方，应该要给比较高的level值；
			
	【万湘黔】  2017-01-04  09:37:42
		gnss01_test_utils添加了TestFunction类型：
		* 用法如gnss02_transform_test/TranParm7CalcTest.cpp所示；
		* 请大家推而广之；
	【万湘黔】  2017-01-03  15:32:58
		gnss05_test_tools已改回southgnss。
		
		做以下几个方面的调整前，与我商量下。
		* 模块命名；
		* 模块放哪个仓库去管理；
		* 使用广泛的全局函数和类型定义；
	麦耀 2017-01-09 11:23:08
		我对工程之星对话框基类DialogExtBase做了一个比较大的调整：
		调整：提出接口IBasicDialog,该接口只有一个函数叫pop，以后再扩展，由DialogExtBase直接继承
		目的：所有从DialogExtBase继承的对话框（目前是系统所有对话框）都拥有动态注册的能力，所有可测试逻辑不再怕直接依赖对话框导致不可测试。
		
		麦耀 2017-01-09 11:31:53
		大家以后做模态对话框对话框，哪怕不可复用，尽量用ExtensibleFactory登记机制做，这样子可以脱离对对话框具体类型的直接强耦合。
		具体参见StakeLineSettingsDialog.cpp的修改，
	讲一下buildbot怎么force build 
		buildbot 右上角登录
		账号 gnss
		密码 1234567a
		
		登录后点builder
		然后看到如下东西
		
	【麦耀】  2017-01-11  09:02:27
		注意不登录没有force build 栏目
	【吴皆强】  2017-01-11  11:20:40
		大家注意一下，现在把wlog的级别调整为WLOG_DEBUG，值为3。默认打出log的级别为WLOG_INFO，值为2。
		即现在软件的大部分的log，将不会被打出。调整理由，软件性能提高，卡顿的感觉减少明显。
	【吴皆强】  2017-01-11  11:22:20
		如需打出WLOG_DEBUG级别的log，修改../etc/gnss00_utilities/gnss_environment_variables.cfg该文件中
		的WLOG_LEVEL_THRESHOLD值为3即可。
	【吴皆强】  2017-01-11  11:22:43
		该调整影响较大，请大家更新代码以及sdk
	【吴皆强】  2017-01-11  11:23:39
		以后需要打log时，也请大家仔细斟酌一下log级别
	【吴皆强】  2017-01-11  15:29:24
		更正：wlog默认级别调回WLOG_INFO。鼓励大家使用指定级别的方法，如error_log、info_log和debug_log等，少使用wlog方法。
	【吴皆强】  2017-01-11  15:30:15
		简易规范：
		*   错误，使用error_log
		*   可稳定复现的，使用verbose_log
		*   不能稳定复现的，使用info_wlog
	【万湘黔】  2017-01-11  15:35:23
		== 关于wlog()函数族的规则 ==
		1. wlog()等价于wlog2(WLOG_LEVEL_INFO)
		2. error_log()总是写出WLOG_LEVEL_ERROR(0)级别的日志；
		3. 如“连接仪器对话框”这种用户特定动作上下文内的日志，应该用info_log()（等于wlog()）；
		4. 容易复现的场景，为研究用途而写的日志，应该用verbose_log()；
	【麦耀】  2017-01-11  16:43:49
		wlog系列函数语义做出增强。凡是WARNING或者更严重级别都加上！语义。
	吴皆强 2017-01-18 17:14:06
		各位，重要修改，IResourceManager提供播放声音接口，声音资源由SurvStarUI提供而不是SurvStar工程。
		提示音亦是资源的一种
	骆培生：
		else if(!csz_stricmp("ask_transform", callback_type))
		{
		//_changeAllLable(dicUI);
		// 转换
		_calcCoordTrans(dicUI);
		}
		else if (!csz_stricmp("ask_tra_rev", callback_type))
		{
		//_changeAllLable(dicUI);
		//逆转换
		_calcCoordTrans(dicUI, 1);
		}
		
		工具中 坐标转换 的_changeAllLable(dicUI)函数能不能去掉，感觉没用的样子?
	
	麦耀：
		各位注意：warn_log跟error_log不可互相取代。要改必要想清楚。后者表明代码已经无法再执行下去而异常，前者只是写出log，对软件没有任何影响。
	万湘黔 2017-02-06 15:02:45
		一定要注意error_log()与warn_log()的区别。
		
		如果只想按WLOG_ERROR级别写日志、不想抛异常，则应调用wlog2()而不是error_log()
		——应该不必要这么做吧……

主要函数的使用：
	文件的读取：
	配置的处理：
		ISystemSettings &settings;
		m_dlgMgr(*settings.getUiManager().getDialogManager());
		南方工具集如果要添加其他exe文件：
			E:\gnss\southgnss_sdk\win32bin\res\config.ini:需要在此ini文件下的：[enable_tools]节点按顺序添加exe名字；
			E:\gnss\southgnss_sdk\win32bin\res\string.txt：同时需要在此ini文件下的：<!-- 关于软件所用字段 -->和<!-- 工具箱主界面控件所用字段 -->下添加相应的信息；
		
	字符串的c处理：
		next_word3：
			//从一个字符串中按指定分隔符截取一个单词到第一个参数的buf中（也就是指定字符的前面部分）
			//返回的是截取的字节数；直接指针+就可以获取截取后，后面的剩余部分；
			example：
				const char *p = csvEscapes;
				p += next_word3(word, p, ',', sizeof(word));
		next_word4：
		
		TextConverter;
			对接口ITextConverter的操作封装；
				ITextConverter
					接口类；
					子类1：
					class TextConverterImp:public ITextConverter//在此空间里：namespace TextConverterImp_NS
						wchar_t wc = 1;//unsigned short 
						const char *p = (const char*)&wc;//const char * = 强转地址；
						const int flag = sizeof(wc)+p[0];//wc的大小+第一个字节数？
				系统在利用 源代码文件 携带的 字符串常量 构造 文件路径时，应使用gbk_locale转换器：
					TextConverter gbk_locale("GBK", "char");
				sqlite3_open(wsp, &db)要求wsp采用UTF-8编码，所以需要使用locale_utf8转换器：
					TextConverter locale_utf8("char", "UTF-8");
			（const char *srcEncoding, const char *destEncoding）//如果为空则是系统编码的参数；(受国家标准（GB/T2312-1980,GB/T18030-2000）的影响，windows中文用户一般设定locale为GBK编码)
			//源字符串所用字符编码，比如"GBK"，目标字符串所用字符编码，比如"UTF-8"
			//文本转换类，支持将"GBK"编码的字符串转换为"UTF-8"编码的字符串，
			TextConverter convW("wchar_t", "");
			ITextConverter &conv = convW.getInnerObject();
			csz_strncpy(buf, conv.convert((const char*)m_strKey.GetString()), buf_size);//字符串的拷贝；
				//把wchar_t的字符串强转const char*使用；//输入要转换的字符串；返回转换后的字符串；
			
			//这样使用：
			TextConverter _conv("UCS-2-INTERNAL", "");
			ITextConverter &conv(_conv.getInnerObject());
			while(a < 200)
			{
				wchar_t *w=L"由于连接方在一段时间后没有正确答复或连接的主机没有反应，连接尝试失败。\n";
				const char *v = conv.convert((const char*)w);
				//thread_sleep(500);
				a++;
			}
			
			//基本用法：
				char utf8[100];
				TextConverter _utf2gbk("UTF-8", "GBK");				
				ITextConverter &utf2gbk(_utf2gbk.getInnerObject());
				
				TextConverter _gbk2utf("GBK", "UTF-8");
				ITextConverter &gbk2utf(_gbk2utf.getInnerObject());
		
				csz_strncpy(utf8, gbk2utf.convert("shp_files/椭球参数.sqlite"), 100);
				CPPUNIT_ASSERT_EQUAL(25, gbk2utf.getSrcLength());
				CPPUNIT_ASSERT_EQUAL(29, gbk2utf.getResultLength());
		
				AUTO_TEST_ASSERT_STR_EQUAL("shp_files/椭球参数.sqlite", utf2gbk.convert(utf8));
				CPPUNIT_ASSERT_EQUAL(29, utf2gbk.getSrcLength());
				CPPUNIT_ASSERT_EQUAL(25, utf2gbk.getResultLength());
		
				csz_strncpy(utf8, gbk2utf.convert("南方PK"), 100);
				CPPUNIT_ASSERT_EQUAL(6, gbk2utf.getSrcLength());
				CPPUNIT_ASSERT_EQUAL(8, gbk2utf.getResultLength());
		
				AUTO_TEST_ASSERT_STR_EQUAL("南方PK", utf2gbk.convert(utf8));
				CPPUNIT_ASSERT_EQUAL(8, utf2gbk.getSrcLength());
				CPPUNIT_ASSERT_EQUAL(6, utf2gbk.getResultLength());
				不明白：
						StreamFormatter fmtFile;
						os_printf(fmtFile, "GPS-RTK中线控制桩表%02d%02d.xls", time.wHour,time.wMinute);
						TextConverter _conv("GBK","wchar_t");//创建一个gbk到wchar_t转换的对象；
						ITextConverter &conv(_conv.getInnerObject());
						char buf[128]={0};
						//调用convert函数（要转的字符串，长度）转换；
						//csz_strncpy(buf, conv.convert(fmtFile.getBuffer()), sizeof(buf));
						int nSize = sizeof(buf);
						const char *pchFile = fmtFile.getBuffer();
						const char *pFile = conv.convert(pchFile);
						csz_strncpy(buf, pFile, sizeof(buf));
						//这段代码怎么转换不了？
		Dictionary用法：
			dictionary_merge：				
				Dictionary dicMid;
				dictionary_merge(dicMid.getInnerObject(), dicIn, 1);
				dictionary_merge(dicMid.getInnerObject(), dicNew, 1);	
			一般的用法是这样：
				Dictionary _dic;
				IDictionary &dic = _dic.getInnerObject();//注意&符号；
			
			IDictionary的用法：
				先set后get使用，问题是为什么要这样用呢？
				StreamFormatter fmt;
				dictionary_to_csa(fmt, dic);//转换成逗号分隔字符串
			dictionary_copy_spec
				Dictionary _dic1(0, "key1=1, b=2, c=3, key4=4");
				IDictionary &dic1(_dic1.getInnerObject());
				Dictionary _dic2;
				IDictionary &dic2(_dic2.getInnerObject());
				
				//按"a=key1,b,d=key4"拷贝字典：从该字典中的value中获取dic1对应的key的value然后赋值；
				dictionary_copy_spec(dic2, dic1, "a=key1,b,d=%s", "key4");
			dic_get_r8
				dic_get_r8(initUI,"edit_lat","0.0");//若不给默认值，则当找不到键时抛出异常
			从字典中获取值：
			dic_get_csz
				array_strncpy(gcp.name, dic_get_csz(dicLine, "name", ""));//要注意最后参数不要写成"0"
				parse_dot_dms(dic_get_csz(dicLine, "lat1", "0"));
			//打印dic的方法：
			dictionary_get_keys：
				//quote_if_contains_seperator				
				StreamFormatter fmtkeyList;
				dictionary_get_keys(fmtkeyList, rowData);
				const char *csvKeys = fmtkeyList.getBuffer();
				const char *p = csvKeys;
				TRACE("%s\n", csvKeys);
				char tok[2]={0};
				char key[100]={0};
				while(*p)
				{
					p += next_word3(key, p, ',', sizeof(key));
					const char *val = dic_get_csz(rowData, key, "");
					TRACE("%s     : %s\n", key, val);
				}
				//常用：
				const char * dicKeys = 0;
				StreamFormatter formatkeys;
				dictionary_get_keys(formatkeys, record);
				dicKeys = formatkeys.getBuffer();
				const char *p = dicKeys;
				char key[50]={0};
				while(*p)
				{
					p += next_word3(key, p, ',', sizeof(key));
					const char *key_val = dic_get_csz(record, key, "0");
					//TRACE("%s=%s\n\n", key, val);
				}
				//常用：
				#include "afx.h"
				static void print_dic(char *pDicName, IDictionary &dic)
				{
					StreamFormatter fmtKeyList;
					dictionary_get_keys(fmtKeyList, dic);
					const char *pKey = fmtKeyList.getBuffer();
					char chKey[100] = {0};
					const char *p = pKey;
					if(pDicName)
						TRACE("%s:%s\n", pDicName, pKey);
					else
						TRACE("%s\n", pKey);
					while(*p)
					{
						p += next_word3(chKey, p, ',', sizeof(chKey));
						const char *pValue = dic_get_csz(dic, chKey, "");
						TRACE("%s		:%s\n", chKey, pValue);
					}
				}
				//常用：
				static void print_dic_2(IDictionary &dic, char *pDicName = 0)
				{
					StreamFormatter fmtKeyList;
					dictionary_get_keys(fmtKeyList, dic);
					const char *pKey = fmtKeyList.getBuffer();
					char chKey[100] = {0};
					const char *p = pKey;
					if(pDicName)
						wlog("%s:%s\n", pDicName, pKey);
					else
						wlog("%s\n", pKey);
					while(*p)
					{
						p += next_word3(chKey, p, ',', sizeof(chKey));
						const char *pValue = dic_get_csz(dic, chKey, "");
						wlog("%s		:%s\n", chKey, pValue);
					}
				}
		char *：
			const char *fn
			if (fn && fn[0])
			{
				parsePath(fn);
			}
			
			array_strncpy(gcp.name, dic_get_csz(data, "szName", ""));
		IOutputStream
			//字节流写接口
			class IOutputStream: public IStreamBase
		StreamFormatter
			//为什么os_print可以直接使用？应为使用了强转。
			//此接口只负责创建和释放对象；使用的时候尽量使用IStreamFormatter；那么参数应该使用哪呢？//使用IStreamFormatter！；
			//格式化输出到字符缓冲区；StreamFormatter与IOutputStream适配；
			//IStreamFormatter接口的创建与释放封装类；
			默认的话如果
			IStreamFormatter
				class IStreamFormatter:public IOutputStream
				接口类；
				子类1：
				class StreamFormatterImp:public IStreamFormatter
				
			StreamFormatter fmt;
			os_printf(fmt, "%s", key);
			const char *chi = fmt.getBuffer();			
					
			StreamFormatter fmtKeys;
			dictionary_get_keys(fmtKeys, dicNew);		
			const char *csvKeys = fmtKeys.getBuffer();
			
			StreamFormatter m_fmtName;//定义一个StreamFormatter的对象；
			m_fmtName.clear();
			if (task)
			{
				os_printf(m_fmtName, "loop[%s]", task->getName());
			}
			os_printf(m_fmtName, "seq[");
			const char *tag = "";
			for (size_t i=0; i<m_vecTasks.size(); ++i)
			{
				IThreadTask *task = m_vecTasks[i];
				os_printf(m_fmtName, "%s%s", tag, task->getName());
				tag = ",";
			}
			os_printf(m_fmtName, "]");
			const char *name = m_fmtName.getBuffer();
			
			//上面的可以直接使用？这里为什么要中间ISteamFormatter？
			StreamFormatter _fmtFile;//应该是获取内存空间？
			IStreamFormatter &fmtFile(_fmtFile.getInnerObject());//要添加&
			os_printf(fmtFile, "os_file:path=%s", chFileName);
			const char *pFilePath = fmtFile.getBuffer();
				//结论：大部分使用都是直接使用的；
			//测试是否可以直接使用StreamFormatter?//是否可以直接使用=号？//结论：不可以；
			void test_StreamFormat1()
			{
				StreamFormatter fmt1, fmt2;
				os_printf(fmt1, "%s", "你好！");//为什么可以直接使用的？
				const char *p1 = fmt1.getBuffer();
				AUTO_TEST_ASSERT_STR_EQUAL("你好！", p1);
		
				os_printf(fmt2, "%s", "日月潭！");
				fmt2 = fmt1;
				const char *p2 = fmt2.getBuffer();
				AUTO_TEST_ASSERT_STR_EQUAL("你好！", p2);
			}
	
	文件类：
		StreamContainerW
			封装IStreamContainer类的创建和释放；
				IStreamContainer
					接口类：//获取输入流、输出流两个函数；
					//？？没有子类继承？？
				class InputFileStream : public IInputStream
					class IInputStream: public IStreamBase
				class OutputFileStream: public IOutputStream
					class IOutputStream: public IStreamBase
			//打开文件，读取文件内容；
				StreamContainerW _c1(csa1, 0);//csa1是文件路径？ 0为倍数增长；1为加法增长；
				IStreamContainer &c1 = _c1.getInnerObject();
				IInputStream &is1 = c1.getInputStream();
				char buf1[1000]={0};
				while(!is1.eof())
				{
					is_get_line(buf1, sizeof(buf1), is1);
				}
			//打开文件写入文件
				StreamContainerW _mapContainer(schema, 0);
				IStreamContainer &mapContainer = _mapContainer.getInnerObject();
				IOutputStream &os = mapContainer.getOutputStream();
				os.writeBytes(c1, strlen(c1), 1);
				os.fseek(4 * 1024 * 1024 - 10, SEEK_DATUM_SET);
				
				os.writeBytes(c2, strlen(c2), 1);
				os.writeBytes(" normal again!", 14, 1);
			//检查文件是否存在：
				file_system_check_file（path）；
			//删除
				file_system_delete_file(fn2);
			//拷贝
				file_system_copy_file(fn1, fn3);;
			
				
		IFileGroup
			接口类：//用于分解文件路径为目录、文件名、扩展名三个部分。同时提供在原有文件路径基础上组合生成新文件路径的方法。
			子类1：
			class FileGroupImp: public IFileGroup
			FileGroupW
				封装IFileGroup的创建和释放接口类；
			使用：
				const char *baseFilePath；
				FileGroupW _grp(baseFilePath);//1、可以用文件路径直接构造；2、也可以直接调用parsePath函数转换路径；
				IFileGroup &grp(_grp.getInnerObject());
				
				FileGroupW _m_grp;
				IFileGroup &m_grp;
				m_grp.parsePath("d:\\test\\for\\good.txt");
				AUTO_TEST_ASSERT_STR_EQUAL(".txt", m_grp.getExt());
				AUTO_TEST_ASSERT_STR_EQUAL("good", m_grp.getBase());
				AUTO_TEST_ASSERT_STR_EQUAL("d:/test/for/good.bat", m_grp.compositeFileName(".bat"));//重新组合路径名；
				AUTO_TEST_ASSERT_STR_EQUAL("d:/test/for/bad.bat", m_grp.compositeFileName("bad", ".bat"));
				
			文件路径标准化：
				char buf[1000];
				file_system_path_standardization(buf, sizeof(buf), "d:\\dir1\\/dir2\\\\dir3\\////dir4")；
				AUTO_TEST_ASSERT_STR_EQUAL("d:/dir1/dir2/dir3/dir4", buf);
			枚举文件夹下的指定文件：
				char fn[500];
				process_resolve_path(fn, sizeof(fn), "$(GNSS_TEST_DATA_DIR)/file_system_test_data/");
				
				StreamFormatter	_fmtJobFiles, _fmt2;
				IStreamFormatter &fmtJobFiles(_fmtJobFiles.getInnerObject());
				IStreamFormatter &fmt2(_fmt2.getInnerObject());
				const char *csv1 = 0, *csv2 = 0;

				file_system_enumerate_files(fmtJobFiles, fn, "*.txt", -1);//结果保存在fmtJobFiles；
				csv1 = fmtJobFiles.getBuffer();//该结果是以，号分隔；
				
				_path_list_abs_to_rel(fmt2, fn, csv1);
					
				csv2 = fmt2.getBuffer();
				
				AUTO_TEST_ASSERT_STR_EQUAL(
					"b.txt,"
					"c.txt,"
					"dir2/dir3/dir3a.txt,"
					"dir2/dir3/dir3b.txt,"
					"dir2/dir3/dir4/dir4a.txt,"
					"dir2/dir3_2/dir3_2a.txt"
					, csv2);
			
			
		SurvStar
			initUI.setValue("dialog_title", m_rcMgr.loadString2("tool_trans_params_edit", dialog_title_key));//dialog_title_key = "dialog_edit_name";
				//m_rcMgr.loadString2("tool_trans_params_edit", dialog_title_key)
					//加载E:\gnss\southgnss_sdk\etc\SurvStar\cn\surv_star_strings2.ini该文件中的tool_trans_params_edit的title的以dialog_title_key为key的数据；返回该值；
		解析点度字符串：//点度字符串，例如"-78.5959999"表示-78°59′59.999″
			double parse_dot_dms(const char *ddms);//返回十进制：例如点度字符串"78.3000000"对应十进制度78.5
		
		wch_to_mb??	

	*编码习惯，如不公开成员变量，尽力减少公开的成员函数，不用cstring做接口，通过分析对话框行为确定需要的参数等。
	*可复用对话框的理念，要使用可复用对话框的机制合并南方工具集和SurvStar中的相同功能对话框。

dlg文件的书写规则：
	逻辑：
		需要在调用代码中添加回调函数以及回调函数的实现：
	配置文件关联：
		$：从字典里面取值；
		#:暂时只有两个是使用这个取值的；
		&:
		@:从配置文件里面取值；
			//@label1是从配置文件中获取的值：E:\gnss\southgnss_sdk\etc\SurvStar\cn\surv_star_strings2.ini中的[broken_chains]的字段的值；
			//有中文版和英文版的要一一对应吗？修改不会很麻烦？
		
		如果是SurvStar模块，添加dlg文件之后，需要在debug和release两个版本的地方都要添加：
			该项目属性中的：Deployment->Additional Files:按字母顺序添加该dlg文件；	
	第一步：开头
		dialog_title:@dialog_name;//传入对话框名字；
		title_name:broken_chains;//E:\gnss\southgnss_sdk\etc\SurvStar\cn\surv_star_strings2.ini的节名；
		dialog_width:200;//对话框宽度和高度
		dialog_height:200;
	第二步：布局
		group:v;//列//纵向
		{	
			group//行
			{
				control:label;fldname:label1;defaultValue:@label1;//control：类型；fldname：变量名；默认值：传入的变量名值；
				control:textedit;fldname:bMileage;							
			}
			group//行
			{
				control:label;fldname:label2;defaultValue:@label2;
				control:textedit;fldname:aMileage;
			}
		}
		group//行？
		{
			control:pushbutton;fldname:ok;on_click:accept;showname:@ok;	//类型：pushbutton；fldname：变量名；on_click：accept（点击事件：可接受？）显示名字：变量名的值；					
			control:pushbutton;fldname:cancel;on_click:reject;showname:@cancel;
		}		
	第三步：在配置文件增加相应的字段数值：E:\gnss\southgnss_sdk\etc\SurvStar\cn\surv_star_strings2.ini
		例如：
			[south_tools_import_matching_file]
			dialog_name = "文件匹配导入"
			knowed_plane_coord_data_label = "已知平面坐标数据"
			plane_coord_open_file_btn_label = "打开"
			wgs_data_label = "WGS84数据"
			wgs_open_file_btn_label = "打开"
			import_btn = "导入"
			cancel_btn	= "取消"
		
	常用控件：
		label：
			example:
				control:label;fldname:time_zone_label;defaultValue:@time_zone_label;//survstar_config_general_set.dlg
				//注意：这个控件一定要fldname；因为没有变量名的话，它会和其他的checkbox公用控件变量名，导致无法显示；
				//而且这里不能用showname这个关键字，只能用defaultValue；
				//这个与其他的有点不一样；
		textedit：
			example：
				control:textedit;fldname:ElevationMask;defaultValue:0;keyboard:#KeyBoardUsage;numberflag:0;
				control:textedit;fldname:IncrementStep;defaultValue:0;keyboard:#KeyBoardUsage;numberflag:0;
			//textedit:是没有showname这个关键字的吧？？因为不会显示？
		pushbutton：
			example:
				control:pushbutton;fldname:ok;showname:@ok;on_click:accept,call_back;call_back:ok;
				control:pushbutton;fldname:cancel;showname:@cancel;on_click:reject;
				control:lineedit;fldname:A2;showname:@label_A2;keyboard:#KeyBoardUsage;numberflag:0;regex:.+;notice:@note_A0;height:45;label_size:60;visiable:$nMode&3;
				//注意：这个控件不能用$符号修改按钮的名称？？
				
		checkbox:
			example:
				control:checkbox; fldname:UseVoicePrompt; showname:@prompt_checkbox;height:50;//survstar_config_general_set.dlg
				//注意：一定要定义fldname：变量名，否则会与其他控件乱关联；
		combobox:
			example: //没有showname这个选项？
				control:combobox;fldname:TimeZone;fill_pairs:@time_zone_all;//survstar_config_general_set.dlg
					//fill_pairs:@time_zone_all;配置文件里面设置缺省值：
						如：time_zone_all = "0=-12,1=-11,2=-10,3=-9,4=-8,5=-7,6=-6,7=-5,8=-4,9=-3,10=-2,11=-1,12=0,13=1,14=2,15=3,16=4,17=5,18=6,19=7,20=8,21=9,22=10,23=11,24=12"//surv_star_strings2.ini
				control:combobox;fldname:tool_calcute_triangle_method_select;fill_pairs:@tool_calcute_triangle_method_select;on_click:call_back;call_back:select;
		linectrle：	
		lineedit:
			example：//transform
					control:lineedit;fldname:cogo_calc_coord_pointname_edit;height:50;showname:@pointname_text_showname;keyboard:#KeyBoardUsage;numberflag:1;defaultValue:POINT;label_size:150;
					control:lineedit;fldname:cogo_calc_coord_north_edit;height:50;regex:^(-)?[0-9]+(\.[0-9]+)?$;notice:@north_edit_notice;showname:@north_edit_showname;keyboard:#KeyBoardUsage;numberflag:0;label_size:150;defaultValue:0;
			showname是指标签名？：如：名字：xxxxxx??
		radios: //
			example:
				control:radios;fldname:radios_select;fill_pairs:@import_file_type_selcet;on_click:call_back;call_back:select;height:120;groupby:h;
				//fldname:radios_select;//该控件的变量名：initDic.setValue("radios_select", "0");默认选择第一项；
				//fill_pairs:@import_file_type_selcet:填充选择项格式："0=线段,1=元曲,2=缓曲"
		tablewidget: //fldname:注意不能重复；重复的话会有问题；
			example:
				control:tablewidget;width:480;fldname:ctrl_point_list;fill_pairs:$ctrl_point_list_fill_pairs;headers:$ctrl_point_list_headers;
					//$应该是从程序中的变量中获取值得；
		on_click:(如果是两个Behaviour对象名一样的话，会导致对话框的点击按钮响应不了，特别是变量名相同的点击按钮)
			control:pushbutton;fldname:ok;showname:@ok;on_click:accept,call_back;call_back:ok;
				//添加accept的区别是：会结束这个对话框；
		修改对话框名：
			dic_set_value(m_dicUi, "dialog_title", "%s", "添加竖曲线");
	其他语法：
		正则表达式：regex:^(-)?[0-9]+(\.[0-9]+)?$;
			regex:.+;
			//http://www.cnblogs.com/light169/archive/2006/10/18/532347.html
		showname:@point_north;
		fldname:line1_start_label;
			//理解错误：fldname是字典中约定的key名；//也可以当做变量名，以此来保存传送数值；
			//@label1是从配置文件中获取的值：E:\gnss\southgnss_sdk\etc\SurvStar\cn\surv_star_strings2.ini中的[broken_chains]的字段的值；
		on_click:call_back;
			on_click:accept,call_back;call_back:ok;
		call_back:askline1start;
		height:40;
		width:40;
			//2个字按钮一般width=20既可以了，height=
			//textedit的宽度一般为：60即可；
		label_size:60;
		icon:point_db.ico;
		notice:@line1_end_northing_notice;
		numberflag:0;
		defaultValue:0;@line2_start_label
		control:
			lineedit;
				groupby:v;
			label;
			pushbutton:

		group:v;height:200
		enable:0;	
		visiable:$nMode&3;
			//隐藏控件；&2：也是隐藏？？
			//&0;
			//-1:是显示的？
			//好像跟&的值无关，如果有传入值，则1为显示，其他为隐藏？
			//$nMode=2;
				//nmode==2的值得时候是显示，其余的是隐藏；
		defaultValue:
			//是指该控件的对应变量的值还是显示的标签名字？
		import_file_type_selcet = "0=@file_format_desc/rtk4_fmt_desc,1=@file_format_desc/dat_fmt_desc,2=@file_format_desc/cot_fmt_desc"
			//0=@file_format_desc/rtk4_fmt_desc：是ini文件下的file_format_desc节点下的key为：rtk4_fmt_desc的值；
		space:26;	
对话框修改流程：
		1、dlg编写；
		2、添加回调函数；
			IDialogBehaviour：对话框行为接口（你可以理解为对话框的事件处理？）
			关于回调函数的数值返回流程：
				1、对于传进去的dicUi的初始值，用于显示对话框的相关控件初始参数；
				2、一旦改变控件变量的值，在callback中有个params，它会跟dicUi合并，并覆盖dicUi相同关键字的值；
					//这里要注意一点的是：是params覆盖dicUi，两者的先后关系要搞清楚；
		3、显示对话框；
		
	原理：

		程序的执行流程：
			大概-待完善；			
			加载资源，图片等等：E:\gnss\SurvStar\SurvStarUI\res\240_320
				{APPDIR}/Program Files/SurvStar "/Program Files/SurvStar/etc/gnss04_dialogs/"
				"/Program Files/SurvStar/etc/cn/surv_star_menus.xml"
				",bmpDown=job_down.jpg ,bmpUp=job_up.jpg ,caption=工程 ,menu=sys_job_man ,rowID=0 ,style=menu_window; 
				,bmpDown=config_down.jpg ,bmpUp=config_up.jpg ,caption=设置 ,menu=sys_equip_settings ,rowID=0 ,style=menu_window;
				,bmpDown=survey_down.jpg ,bmpUp=survey_up.jpg ,caption=测量 ,menu=sys_surv_menu ,productMask=11/ ,rowID=1 ,style=menu_window;
				,bmpDown=road_down.jpg ,bmpUp=road_up.jpg ,caption=道路 ,menu=sys_road_menu ,productMask=11/ ,rowID=1 ,style=menu_window; 
				,bmpDown=tool_down.jpg ,bmpUp=tool_up.jpg ,caption=工具 ,menu=sys_tools_menu ,rowID=2 ,style=menu_window; 
				,bmpDown=cogo_down.jpg ,bmpUp=cogo_up.jpg ,caption=COGO ,menu=sys_cogo_menu ,rowID=2 ,style=menu_window;
				,bmpDown=exit_down.jpg ,bmpUp=exit_up.jpg ,caption=退出 ,cmd_id=2060 ,rowID=2"
			
			通过e:\gnss\southgnss_gui\gnss04_mfc_dialogs\DialogManager.cpp的doModal函数响应“工具”点击：
					int ask_by_named_dialog：else if (0 == strcmp(dialog_name, "menu_window"))
					然后就是e:\gnss\southgnss_gui\gnss04_mfc_dialogs\MenuWindow.cpp的show_window_menu函数显示菜单；
						dicOut："menu_items,resourceDllName"
				
				通过e:\gnss\SurvStar\SurvStar\MainFrm.cpp的void CMainFrame::processEvent的else if(strcmp(eventName, "MENU_COMMAND") == 0)分析何种事件；
				通过
				e:\gnss\southgnss\gnss04_survstar\surv_star_command_trigger.h
					surv_star_command_trigger
			e:\gnss\southgnss\gnss04_survstar\ConfigManager.cpp：
				//读取配置文件：
					var/Configure.ini  var/SurvStar/Configure.ini //不知道什么？
					etc/surv_star_init_params.ini 或者etc/SurvStar/surv_star_init_params.ini //
			gnss04_mfc_dialogs_debug.dll!ask_by_named_dialog(IDictionary& dicOut = {...}, IDictionary& dicIn = {...}, const char* dialog_name = 0x0028a0f4, IGuiManager& uiMgr = {...}, IDialogBehaviour* callBack = 0x01c64770) Line: 44, Byte Offsets: 00	C++
			gnss04_mfc_dialogs_debug.dll!MFCDialogManagerImp::doModal(IDictionary& params = {...}, const char* dialog_name = 0x0028a0f4, IDialogBehaviour* callBack = 0x01c64770) Line: 185, Byte Offsets: 0x48	C++
			SurvStar_d.exe!tool_calculate_trans_param_config(HWND__* p = 0x7c0837b0) Line: 22, Byte Offsets: 0x1b4	C++
			SurvStar_d.exe!CToolComputeTransParam::OnBnClickedButtonCalc(void) Line: 366, Byte Offsets: 0xa8	C++
			mfc90ud.dll!_AfxDispatchCmdMsg(CCmdTarget* pTarget = 0x1fb2ccbc, unsigned int nID = 1358, int nCode = 0, void (void)* pfn = 0x0009ce4c, void* pExtra = 0x00000000, unsigned int nSig = 53, AFX_CMDHANDLERINFO* pHandlerInfo = 0x00000000) Line: 82, Byte Offsets: 0x144	C++
			mfc90ud.dll!CCmdTarget::OnCmdMsg(unsigned int nID = 1358, int nCode = 0, void* pExtra = 0x00000000, AFX_CMDHANDLERINFO* pHandlerInfo = 0x00000000) Line: 381, Byte Offsets: 0x33c	C++
			mfc90ud.dll!CDialog::OnCmdMsg(unsigned int nID = 1358, int nCode = 0, void* pExtra = 0x00000000, AFX_CMDHANDLERINFO* pHandlerInfo = 0x00000000) Line: 199, Byte Offsets: 0x2c	C++
			mfc90ud.dll!CWnd::OnCommand(unsigned int wParam = 1358, long int lParam = 2080915808) Line: 2713, Byte Offsets: 0x24c	C++
			mfc90ud.dll!CWnd::OnWndMsg(unsigned int message = 273, unsigned int wParam = 1358, long int lParam = 2080915808, long int* pResult = 0x1fb2b9b4) Line: 2103, Byte Offsets: 0x6c	C++
			mfc90ud.dll!CWnd::WindowProc(unsigned int message = 273, unsigned int wParam = 1358, long int lParam = 2080915808) Line: 2089, Byte Offsets: 0x48	C++
			?WindowProc@DialogExtBase@@UAAJIIJ@Z	
			mfc90ud.dll!AfxCallWndProc(CWnd* pWnd = 0x1fb2ccbc, HWND__* hWnd = 0x7c0837b0, unsigned int nMsg = 273, unsigned int wParam = 1358, long int lParam = 2080915808) Line: 284, Byte Offsets: 0x25c	C++
			mfc90ud.dll!AfxWndProc(HWND__* hWnd = 0x7c0837b0, unsigned int nMsg = 273, unsigned int wParam = 1358, long int lParam = 2080915808) Line: 472, Byte Offsets: 0xe8	C++
			mfc90ud.dll!AfxWndProcBase(HWND__* hWnd = 0x7c0837b0, unsigned int nMsg = 273, unsigned int wParam = 1358, long int lParam = 2080915808) Line: 462, Byte Offsets: 0x48	C++
			SurvStar_d.exe!_try_handle_cpp_exception(bool& isHandle = false, HWND__* hwnd = 0x7c0837b0, unsigned int uMsg = 273, unsigned int wParam = 1358, long int lParam = 2080915808) Line: 52, Byte Offsets: 0x4c	C++
			SurvStar_d.exe!_my_wnd_proc(HWND__* hwnd = 0x7c0837b0, unsigned int uMsg = 273, unsigned int wParam = 1358, long int lParam = 2080915808) Line: 79, Byte Offsets: 0x30	C++
		
			SurvStar_d.exe!CMainFrame::processEvent(const char* eventName = 0x0023d330, const char* csaParams = 0x01c7a730, const void* binParams = 0x01c57aa0) Line: 674, Byte Offsets: 0x1450	C++
			gnss00_utilities_debug.dll!EventManagerImp::notify(const char* eventName = 0x0023d330, const char* csaParams = 0x01c7a730, const void* binParams = 0x01c57aa0) Line: 159, Byte Offsets: 0x300	C++
			gnss04_survstar_debug.dll!EventManagerOnWin32::notify(const char* eventName = 0x0023d330, const char* csaParams = 0x01c7a730, const void* binParams = 0x01c57aa0) Line: 150, Byte Offsets: 0x8c	C++
			SurvStar_d.exe!CMainFrame::processEvent(const char* eventName = 0x0034dccc, const char* csaParams = 0x01c7c5b4, const void* binParams = 0x01c57aa0) Line: 503, Byte Offsets: 0x7a4	C++
			gnss00_utilities_debug.dll!EventManagerImp::notify(const char* eventName = 0x0034dccc, const char* csaParams = 0x01c7c5b4, const void* binParams = 0x01c57aa0) Line: 159, Byte Offsets: 0x300	C++
			gnss04_survstar_debug.dll!EventManagerOnWin32::notify(const char* eventName = 0x0034dccc, const char* csaParams = 0x01c7c5b4, const void* binParams = 0x01c57aa0) Line: 150, Byte Offsets: 0x8c	C++
			?callBack@MenuBehaviour@@UAAHPBDAAVIDictionary@@@Z	
			gnss04_mfc_dialogs_debug.dll!show_window_menu(IDictionary& dicOut = {...}, IDictionary& dicMenu = {...}, HWND__* parent = 0x7c082940, IDialogBehaviour* bav = 0x01b4be30, IGuiManager& uiMgr = {...}) Line: 232, Byte Offsets: 0x130	C++
			gnss04_mfc_dialogs_debug.dll!ask_by_named_dialog(IDictionary& dicOut = {...}, IDictionary& dicIn = {...}, const char* dialog_name = 0x01c67f24, IGuiManager& uiMgr = {...}, IDialogBehaviour* callBack = 0x01b4be30) Line: 74, Byte Offsets: 0x1dc	C++

函数的理解：
	//StakeManage.cpp
		//计算三种折线的所有点和添加点名进字典；//根据所有曲线元素进行计算；
		eFileError CStakeManage::CalcNodePLine(IPLine &plHor, IPLine &plVer, IPLine &plOver, IDictionary &dicName);
			//返回：道路放样模式类型：普通道路放样、横断面放样、点放样、斜断面放样
			//（水平折线，垂直折线，超高折线？,名字字典）；//这些参数都是返回值；
				水平折线、垂直折线清空；
				精度：0.01；//这个为什么去0.01？？
				水平点集、垂直点集变量；
				
				// 不确定标示点ID是否与交点号ID是否一致，维持与之前逻辑一致。初稿。
				//不明白？？（标识点ID与交点号ID）
				名字；
				变量？
				
				曲线元素变量；
				对所有元素进行循环：					
					//处理第几个元素,不处理第一个元素“点”--??
					获取元素；
					元素类型是线：
						把元素里程添加进水平点集；
						判断前一个元素的类型：//根据前一个元素的类型设置名字？
							点：
								设置名字为"QD";
							线：
								"Z"
							缓曲：
								"YZ"
							圆曲：
								"HZ"
					元素类型是缓和曲线：
						根据前一个元素的类型设置名字：
							点：
								"QD"
							线：
								"ZH"
							缓曲：
								"YH"
							圆曲：
								"HH"
						//计算里程间隔；
						获取半径：如果终点半径比起点半径大，则用终点半径；
						获取间隔 = 2*开平方（2*半径*精度-精度的平方）；//那么小？
						获取里程 = 元素的里程；
						循环判断（如果元素里程+长度大于里程）
							把里程添加进水平点集；
							里程 += 间隔；
					元素类型是圆曲线；
						根据前一个元素类型设置名字；"QD","ZY","YY","HY"
						//计算里程间隔；
						//插入圆曲中心点
						设置名字为：QZ+nQZCount;
						以这个名字为key，value为：元素里程+长度的一般；
						把这个value添加到水平点集
						循环判断（如果元素里程+长度大于里程）//这部分什么情况下会
							把里程添加进水平点集；
							里程 += 间隔；
				//终点
				设置名字:"ZD"
				以名字为key，value设置为元素里程+元素长度；//终点的值=元素里程+元素长度；
				（元素里程+元素长度)添加进水平点集；

				竖曲线结构变量；
				对所有竖曲线进行循环：
					取竖曲线；

					获取半径；
					获取间隔值=2*开平方（2*半径*精度-精度*精度）；//什么公式？2*R*D-pow（I/2，2）=D*D；

					里程= 起点里程；
					循环：（如果里程<竖曲线里程）
						把这个里程添加到垂直点集；
						里程+=间隔；
					把最后的里程值添加进垂直点集；

					循环：（如果里程<=竖曲线终点里程）
						把这个里程添加到垂直点集；
						里程 += 间隔；
				//平曲线里程，竖曲线里程交叉计算PLINE
				获取垂直点集、水平点集个数；

				如果垂直点集个数大于0，mV=第一个垂直点集的点；

				对所有水平点集的点循环：
					获取水平点集的点；
					如果（水平点<=垂直点 或者 j>垂直点数-1）
						AddNodePLine(mV, plHor, plVer, plOver);//（垂直点，水平折线，垂直折线，超高折线）进行检验
						continue；

					循环（如果水平点>垂直点 并且 j<=垂直点数-1）
						垂直点= 垂直点集的j个；
						AddNodePLine(mV, plHor, plVer, plOver);
						++j；
			返回成功；

		void CStakeManage::AddNodePLine(const double mileage, IPLine &plHor, IPLine &plVer, IPLine &plOver)
		{						
			unsigned short		overHgt;
			double				height = 0.0;
			
			tagVtcSectionItem	temVElementItem;
			hcurve_moffset_to_posa(pntNE, angle, tempElement, mileage-tempElement.mileage, 0.0);
			for (int k=0; k<m_nVtcSectionCount; k++)
			{
				temVElementItem = m_pVtcSectionList[k];
				
				if (mileage <= temVElementItem.endMileage || 
					k == m_nVtcSectionCount-1)
				{
					vcurve_mileage_to_hgt(temVElementItem, mileage, height);
					break;
				}
			}		
						
			Point2d pt;
			pt.x = mileage;
			pt.y = height;
			plVer.vertexAdd(pt);
		
			// 遍历平曲线元素节点
			Point2d pntNE;
			double		angle;
			tagElementItem tempElement;
		
			for (int nIndex = 1; nIndex < m_nElementCount; nIndex++)
			{
				tempElement = m_pElementList[nIndex];				
				if (tempElement.mileage <= mileage && tempElement.mileage+tempElement.length >= mileage)
				{
					
					hcurve_moffset_to_posa(pntNE, angle, tempElement, mileage-tempElement.mileage, 0.0);
					Point2d pt;
					pt.x = pntNE.y;
					pt.y = pntNE.x;
					plHor.vertexAdd(pt);
					
					over_height_to_posa(tempElement, mileage-tempElement.mileage, overHgt);
					pt.x = mileage;
					pt.y = overHgt;
					plOver.vertexAdd(pt);
					break;
				}
			}
		}
			//根据指定里程，计算高程，然后分别添加三种折线的一个点？？
			void CStakeManage::AddNodePLine(const double mileage, IPLine &plHor, IPLine &plVer, IPLine &plOver)
			//（里程，水平折线，垂直折线，超高折线？）//只是检查道路放样计算结果是否正确？
			//原本是打算把模拟数据添加进折线，因精度达不到放弃；
				
			//超高变量；
			//高程变量；
			//竖曲线结构体；//类型，模式，起点里程、高程，终点，变坡点里程、高程，坡比1，坡比2，圆心，半径;

			//对所有竖曲线个数进行循环：//计算高程
				//获取竖曲线元素；
				//如果指定里程小于该竖曲线的终点里程 || 序号不超过最后一个竖曲线序号；
					vcurve_mileage_to_hgt//(竖曲线，里程，高程);// 输入里程，计算里程的高程
					break；//意思是只要一个就可以了？

			以指定里程为x，高程为y作为一个点；
			添加进竖折线点集中；

			//曲线元素结构体变量：元素类型，基本元素类型，方向，超高，里程，
			//对所有元素个数进行循环；// 遍历平曲线元素节点//求水平折线的点和超高折线的点？
				//获取曲线元素；
				//如果曲线的里程小于=指定里程 并且 曲线的里程+长度大于等于指定里程；				
					hcurve_moffset_to_posa// 获取元素内指定 里程和偏距(右为正，左为负) 对应的  坐标和方位角//指定里程为：指定里程-元素里程，偏距为0.0；
					获取该坐标
					把该坐标点添加进水平折线；
					
					over_height_to_posa//(曲线元素，里程，超高)//获取元素内指定里程对应的超高值(单位:0.1mm)//指定里程为：指定里程-元素里程
					把指定里程和计算的超高作为x，y添加进超高折线；
					break；
			//意思是只要达到有一个就可以了？
CRoadManage
	// 通过指定 里程和斜线长度 以及 对应偏角，获取对应的 斜线两端点坐标，用于横/斜断面放样画图，将会取代GetTransectNodeList
	//（里程，斜线长度，偏角， 获取斜线两端点坐标）
	bool CRoadManage::GetSkewBridgeNodeList(const double& dL, const double &dLength, const double &dOffsetAngle, std::vector<Point2d> *nodeList)
	{
		if (nodeList == NULL || m_nElementCount <= 0)
		{
			return false;
		}
		nodeList->clear();
	
		double dA;
		Point2d pntNE;
		unsigned short overHgt = 0;
		Point2d pntNode;
		//指定里程为dL，偏距为0；
		if (!GetXYandAngle(dL, 0, pntNE, dA, overHgt))//获取指定 里程 和 偏距 的坐标，偏角，超高；
		{
			return false;
		}
		double temAngle = deg2rad(dA+dOffsetAngle-90);//转换为弧度；//偏角+指定偏角-90：为什么要减去90度？
	
		pntNode.x = pntNE.x + sin(temAngle)*dLength;//斜线两端的坐标的x+sin弧度*长度；（因为是x指北顺时针为正，所以是sin）；
		pntNode.y = pntNE.y - cos(temAngle)*dLength;
		nodeList->push_back(pntNode);
	
		pntNode.x = pntNE.x - sin(temAngle)*dLength;
		pntNode.y = pntNE.y + cos(temAngle)*dLength;
		nodeList->push_back(pntNode);
	
		return true;
	}



CurveFuntion.h
	bool over_height_to_posa(const tagElementItem& element, const double &length, unsigned short &overHgt)
	// 获取元素内指定 里程对应的 超高值(单位:0.1mm) //计算超高[0,65535]//指定元素（曲线）， 里程， 获取的超高；
		元素的（长度？）小于 指定里程（差值 < -0.0000001 (前者小) 或者 指定里程接近于0 并且类型不为点；
			如果不等于线
				则返回成功//这点不是很理解？？

		//也就是说如果元素的长度大于指定里程 或者 指定里程接近0并且类型为点的时候才进行往下计算？

		临时角度变量；
		根据元素类型判断：
			点：
				超高=0；
				ture；
			线：
				超高=0；
				返回true；
			圆弧：
				超高=元素的超高；
				返回true；
			圆曲：
				如果元素的起点半径<=终点半径
					超高=unsigned short（强转）（元素的超高/元素的长度 * 指定里程）
				否则
					=元素的超高/元素的长度*（元素的长度-指定里程）；
				true；
	//超高的概念是什么意思？：

		
	//指定 里程 和 偏距 求坐标、偏角、超高；
	bool CRoadManage::GetXYandAngle(const double& dL, const double& dOffset, Point2d &pntXY, double &angle, unsigned short &overHgt)
	(dL, 0, pntNE, dA, overHgt)//（里程，偏距，获取的坐标，偏角，超高）
		曲线结构定义
		遍历所有元素：
			三种情况：
			元素的里程<=指定长度 并且 里程+长度 > 指定长度
			元素的里程大于长度 并且 为第一个元素；
			元素的里程小于指定长度 并且 为倒数第一个元素？
				//求超高；
				over_height_to_posa(tempElement, dL-tempElement.mileage, overHgt);（元素，里程-元素的里程，要求得超高）；
				//求坐标和方位角；
				return hcurve_moffset_to_posa(pntXY, angle, tempElement, dL-tempElement.mileage, dOffset);
					//// 获取元素内指定里程和偏距(右为正，左为负)对应的坐标和方位角
					//（
		return false；
CurveFuntion.h
	bool hcurve_moffset_to_posa(Point2d &pntOut, double &angle, const tagElementItem &element, const double dL, const double dOffset)
	{
		double dA;
		Point2d pnt1;
		if (!_hcurve_mileage_to_relative_posa( pnt1, dA, element, dL))
		{
			return false;
		}
		{
			const double rA = deg2rad(dA);
			pnt1.x -= dOffset*sin(rA);
			pnt1.y += dOffset*cos(rA);
		}
	
		const double temAngle = deg2rad(element.azimuth);
		const Vector2d vec(cos(temAngle), sin(temAngle));
		LocalCoordSystem2d lcs(element.coord, vec);
		const Point2d pnt2 = lcs.trans_b(pnt1);
		pntOut = pnt2;
		angle = element.azimuth + dA;
	
		return true;
	}
	// 获取元素内指定里程和偏距(右为正，左为负)对应的坐标和方位角//
	bool hcurve_moffset_to_posa(Point2d &pntOut, double &angle, const tagElementItem &element, const double dL, const double dOffset)
		//（坐标，方位角，元素，里程，偏距）；
		例如：hcurve_moffset_to_posa（&n,&e, &angle, 元素tagElementItem, dL里程，doffset偏距）

		定义角度变量dA；
		点变量pnt1；
		如果（！_hcurve_mileage_to_relative_posa( pnt1, dA, element, dL)
			////获取元素在指定里程的相对位置、方位角；//相对于谁的位置；
			返回false；
		角度转化为弧度；
		点的x-偏距*sin（弧度）；
		y+偏距*cos（弧度）；
		
		元素的方位角转弧度；
		以（cos弧度，sin弧度）为向量；
		以元素的坐标和该方位角向量建立本地坐标系类；
		pnt2 = lcs.trans_b(pnt1);/// 从本地坐标系坐标求出原来(世界)的坐标系的坐标
		角度= 元素的角度+偏角；
			//元素的坐标：在元素的坐标系中；
			//方位角向量：本地坐标系；
		
		true；

	//里程究竟是什么？
	//获取直线、圆曲线、缓和曲线在一定曲线里程的相对位置、角度；//获取曲线元素在指定里程的相对位置和角度；//它原来有坐标，和角度；
	static bool _hcurve_mileage_to_relative_posa(Point2d &pnt, double &angle, const tagElementItem &element, const double length)
		//（位置，角度，元素，里程）
		点置0；
		角度置0；
		如果：元素长度-指定里程<-0.00001 (小于指定里程） || 指定里程小于0 并且 类型！=点）
			如果类型！=线//难道说元素长度=里程的时候就是直线了？？
				返回false；

		角度=0.0；
		根据元素的类型：
			线：
				点的x = 指定里程；
				返回true；//线是没有角度的？
			圆曲：
				起点半径必须大于0；
				角度=指定里程/元素的起点半径；
				x = 起点半径*sin角度；
				y = 起点半径*（1-cos角度）//
				true；
			缓曲：
				必须：起点半径和终点半径都大于0；
				必须：起点半径小于终点半径；//这是？？
				获取起点、终点半径；

				//0点到起点和终点的曲线长？//0点是指（0,0）位置？曲线长怎么理解？0到当前位置；
				L1，L2，L3；
			分为：起点曲率无穷大的曲线：
				如果起点半径小于=0.000001（起点曲率半径为无穷大的曲线）
					L2 = 曲线长度；//0到终点 = 曲线长度；
					L3 = 指定里程；//0到当前点 = 指定里程；
					double C2=R2*R2*L2*L2；（终点半径的平方*（0点到终点的曲线长）的平方）；
					_hcurve_moffset_to_pos(pnt.x, pnt.y, 0.0, L2, L3, R1, R2);//以L1=0求x，y；
					旋转角度=L3*L3/2*R2*L2;//0点到当前点位置平方/2*终点半径*0到终点曲先长；
				否则：起点曲率半径不为无穷大；
					如果终点半径 < 0.000001；
						0点到起点的曲线长 = 负的元素长度；
					否则
						0点到起点的曲线成 = 元素长度*终点半径/（起点半径-终点半径）；
					0点到终点的曲线长 = L1 + 元素的长度；
					0点到当前位置 = L1 + 指定里程；

					获取临时坐标位置：
					_hcurve_moffset_to_pos(dxTem, dyTem, L1, L2, L3, R1, R2);

					旋转角度 = L3*L3-L1*L1）/2*R1*L1；//0到当前位置平方减去0到起点平方 /2*起点半径*0到起点；

					//将相对坐标投影到起点方向为0的坐标系中
					double angle = （L1*L1）/(2*R1*L1);//起点方向角度；//0到起点的曲线长平方/2*起点半径*0到起点的曲线长；

					x = cos（angle）*dxTemp + sin（angle）*dyTemp；
					y = cos（angle） *dyTemp - sin（angle）*dxTemgp；

				true；
			跳出循环；
		如果是点：
			true；
		angle = 度转弧度（temAngle）；
		如果（元素向右）
			y的值取负值；
			agnle取负值；
		true；

	static int _hcurve_moffset_to_pos(double &north, double &east, double L1, double L2, double L3, double R1,double R2)
		
	hcurve_relative_mileage_to_posa(&n,&e, &angle, 元素tagElementItem, dL里程，length偏距)//获取直线、圆曲线、缓和曲线在一定曲线里程的相对位置
			
		
	//缓曲类：求得的里程（相对于起点）和偏距（缓和曲线的反算里程偏距的算法）
		（根据指定坐标计算 该坐标 相对于 曲线的 里程差和偏距？）
	_ease_pos_to_moffset（曲线， n，e， l里程，doffset偏距）
			起点到给定点的向量，起点处的方位角向量，以及两个向量之间的夹角；
			终点到给定点的向量， 终点处的方位角向量，以及两个想想之间的夹角；
			中点到给定点的向量， 中点处的方位角向量，以及两个向量之间的夹角；
			
			放样点坐标；（给定点坐标）；
			起点坐标（就是曲线内的起点坐标）；
			曲线内的方向角；（起点的切线方向？）
			
			放样点与起点距离过小，则里程为0，偏距也为0；
			
			终点坐标；
			终点方位角；
			中间点坐标；
			中间点方位角；
			判断左偏右偏；
			
			dL1=0.0；			起点的曲线长度；
			dL2=曲线的线长；	终点的曲线长度；
			dL0；				中点距“起始点”的曲线长度；？？
			
			//第一步：计算终点坐标和终点方位角；
				通过终点里程和设置偏距0来正算终点的坐标(x2,y2)
				hcurve_moffset_to_posa（）// 获取元素内指定里程和偏距(右为正，左为负)对应的坐标和方位角
					把方位角转换为度；
					100次迭代：
						起点处的方位角向量；（sin（angle1),cos(angle1));
						起点到给定点的向量（两者相减）；
						方位角向量的长度*向量的长度；
						两向量的夹角 = acos（点积/上面的值）；
						
						终点方位角向量（）；
						终点到给定点向量；
						同上；
						同上；
						
						中点的线长dL0 = (0+曲线线长)/2;
						如果：长度积1、2绝对值都很小，（夹角1-pi）/2 * （夹角2-pi）/2 < 0
							如果：长度积1的绝对值<0.0(7)1 或者 （夹角1-pi）/2 < 1E-8（向量夹角与90的差值百万分之一）
								里程 = 0.0；
								偏距 = 起点到给定点的向量的长度；
								r1 = 起点到给点向量的x*cos（两向量夹角） - 起点到给定点向量的y*sin（两向量的夹角）；
									r1<0 偏距取反；
								返回true；
							如果： 长度积2的绝对值<0.0(7)1 或者 （夹角2-pi）/2 < 1E-8（向量夹角与90的差值百万分之一）
								里程 = 线长；
								偏距 = 终点到给定点向量的长度；
								r1 = 
							如果： 夹角1 < 夹角2 
								//获取元素内指定 里程 和 偏距(右为正，左为负) 对应 的 坐标和方位角
								如果hcurve_moffset_to_posa（中间点x，中间点y， 方向角，曲线，里程，偏距设为0）// 获取元素内指定里程和偏距(右为正，左为负)   对应的坐标和方位角
									方向角转为度；
									中间点方向角向量；
									中间点到指定点的向量；//中向量
									两向量的长度相乘；
									偏距 = 中间点到给定点的长度；
									r1 = 中向量的x*cos（方向角）-中向量的y*sin（方向角）；
									如果r1<0://偏距*-1；//左偏为负，右偏为正；
									
									
							
							否则：
							
						否则：
						
					迭代结束：
					
					里程 = 0.0；
					偏距 = 
					返回true；
					
				返回 false；			
			
	//圆曲类：根据指定坐标计算 该坐标 相对于 曲线的 里程差和偏距？
	_circle_pos_to_moffset（曲线，n，e，l里程差，doffset偏距）
			（n，e）为当前点；（指定点、放样点）
			起点为曲线里面的起点坐标；
			第一步：计算圆心坐标
				cen；
				Vector2d vec（0，起点半径）；//这个向量是y轴而已？
				vec_rotate（vec， azimuth）；//旋转角，度，x指东y指北时逆时针为正，x指北y指东时顺时针为正
				cen = pnt0-vec;//这就是圆心坐标了；
			第二步：圆心到起点的方位角，圆心到放样点的方位角，到终点的方位角；
				到起点的方位角；
				到放样点的方位角；
				求方位角增量：
					如果是向右的：
						圆心到放样点的方位角 - 到起点的方位角；
					否则：
						反过来；
			第三步：求终点和终点方向角；//用指定里程和偏差求相对坐标和方位角的方法求；
				Point2d pnt1；
				如果（hcurve_moffset_to_posa（x，y， 方位角，曲线，曲线的线长作为里程，偏距为0）就可以求出终点？// 获取元素内指定里程和偏距(右为正，左为负)对应的坐标和方位角
					求圆心到终点的方位角；
					（圆心到起点的方位角 - 圆心到终点的方位角）--方位角增量；
						如果是向右：则取反；
					如果前面的方位角增量大于此，则返回false；
			第四步：求里程差和偏距：
				起点半径*方位角增量（圆心到放样点-圆心到起点）
				偏距：放样点到圆心的距离 - 起点半径长度；					
			
	//直线类：根据指定坐标计算 该坐标 相对于 曲线的 里程差和偏距？
	//line_pos_to_moffset（曲线基本元素结构，n，e，L里程差，dOffset）
			n,e就是指定的坐标；
			element里面有曲线的起点坐标；
			//第一步：获取终点坐标：
				//首先：获取元素内指定里程和偏距(右为正，左为负)对应的坐标和方位角：
				hcurve_moffset_to_posa（终点坐标的.x,终点坐标的y，方位角ea，元素，元素的里程，指定偏距为0）；// 获取元素内指定里程和偏距(右为正，左为负)对应的坐标和方位角
				//获取起点到终点的方位角；
				//获取起点到当前点的方位角；
				//获取当前点到终点的夹角？
			//第二步：起点到当前点的距离//主要是这个；
			//第三步：平距、垂距（里程差、偏移量）；平距就是当前点在曲线上的投影点到起点的距离；
			
	//根据指定坐标计算 该坐标 相对于 曲线的 里程和偏距//注意一个是里程差和偏距，一个是里程和偏距；
	//hcurve_pos_to_moffset(曲线元素结构，n，e，dMileage里程，doffset偏距)
			//根据该曲线的类型分：线，圆曲，缓曲三类；
			线：
				//根据指定坐标计算里程差和偏距
				//line_pos_to_moffset(曲线，n，e， 里程差， 偏距)
				里程= 里程差+曲线元素的里程
			圆曲：_circle_pos_to_moffset（曲线，n，e，里程差， 偏距）
				里程= 里程差+曲线元素的里程
			缓曲：_ease_pos_to_moffset（曲线， n， e， 里程差， 偏距）//缓和曲线的反算里程偏距的算法
				里程= 里程差+曲线元素的里程
	圆曲？
		//偏向角怎么定义？//其实是后一个交点与当前交点的坐标的角度差？
		//里程怎么定义？//里程其实是里程号*里程间隔+起点里程数；
		//偏距怎么定义？//
		//长度怎么定义？//长度要区分缓曲还是圆曲：缓曲就是直线的长度；圆曲的话就是曲线的长度；
		//向右向左是怎么定义的？//要看前进方向才能判断出偏左还是偏右；//一般来说是由两个前进方向，从左到由则是向右，从右到左则是向左；


//RoadPLine_test.cpp
	calc_max_dist(rgMgr, plHor, plVer, 0, 72529)
		a、这个函数的作用：（roadMgr，水平折线对象1，垂直折线对象2，起点里程，终点里程，偏距）
			locate_with_mileage_offset_pline（长度， 偏距，逐桩坐标结构， 水平折线， 垂直折线）
				对所有垂直折线上的点进行循环：//只要找到一个点大于长度就可以了；
					取垂直折线上的点（依次获取）
					如果北坐标大于长度
						获取垂直折线前一点的坐标；
						前一点北坐标与长度差；
						以长度作为逐桩坐标的里程；
						
						获取水平折线的前一点和当前点；
						获取两点的向量，并把之前的北坐标与长度差设为该向量的模；
						获取该向量的夹角；
						取正值后赋值给逐桩结构的向量角；
						水平折线的前一点+向量值 赋值给逐桩坐标；
						
						计算道路偏离坐标：
							如果偏离值绝对值大于0.0001；
							 如果偏离值为负、正？
							 向量逆时针旋转90度（）
							 设置模值；
							 计算偏离坐标；

向量的使用：

	3、RoadManage.cpp第666-674行
		{{{
			double temAngle = deg2rad(dA+dOffsetAngle-90);//度转弧度：（通过指定里程和偏距求得的元素偏向角+偏角-90度）；

			pntNode.x = pntNE.x + sin(temAngle)*dLength;//通过制定里程和偏距求得的坐标+sin角度*长度；
			pntNode.y = pntNE.y - cos(temAngle)*dLength;
			nodeList->push_back(pntNode);
		
			pntNode.x = pntNE.x - sin(temAngle)*dLength;
			pntNode.y = pntNE.y + cos(temAngle)*dLength;
			nodeList->push_back(pntNode);
		}}}
		{{{
			Vector2d vec(dLength, 0);//vec(x，y)//长度为指定，平行于x轴的向量；
			//向量按正方向翻转？
			vec_rotate(vec, dA+dOffsetAngle+90);//直接向量翻转角度；就变成上面的pntNode的向量（-、+方向相反;
*				//这个不是很理解的：
					//不是应该为：x+cos(temAngle);y+sin(temAngle);吗？
					//如果角度为负值呢？也不对啊：x+cos(temAngle);y-sin(temAngle);
					//如果x轴指北呢？就是x，y轴调换过来：x-sin（temAngle);y+cos(temAngle);
					//但是为什么pntNE-vec就等于？？
			nodeList->push_back(pntNE-vec);
			nodeList->push_back(pntNE+vec);
		}}}
		//圆心坐标的计算：
		//在右边不是要x0 = element.north + element.startRadius*sin(temAngle);吗？
		if(element.directionR)//这个方向是指内凹方向？假设是内凹方向：0为凹向左，1为凹向右；
		{//计算圆心坐标
			x0 = element.north - element.startRadius*sin(temAngle);//元素的北坐标-元素的起点半径*sin方向角？（这个角度是元素的偏向角转弧度来的？）//当凹向左的时候成立；
			y0 = element.east + element.startRadius*cos(temAngle);//元素的东坐标+元素的起点半径*cos偏向角？（不是应该-去吗？）
		}
		else
		{
			x0 = element.north + element.startRadius*sin(temAngle);//北坐标 + 半径*sin偏向角；
			y0 = element.east - element.startRadius*cos(temAngle);
		}
		等价于：
		//计算圆心坐标
		Point2d cen;
		Vector2d vec(0, element.startRadius);//以起点的半径为长度，建立平行于y轴的向量；
		vec_rotate(vec, element.azimuth);//该向量旋转偏向角度；
		if (element.directionR)//
		{
			// 向右
			vec = -vec;
		}
		cen = pnt0-vec;//圆心坐标等于元素的坐标点 减去 建立的平行于y轴的向量旋转偏向角后的向量
	//起点到终点的方位角；
		calc_azimuth(n1,e1,n2,e2)
		等价于：
		azimuth_normalize(vec_angle(pnt1-pnt0))
			azimuth_normalize(rad2deg(atan2(y, x));
	//两点的距离：
		double length = sqrt(
		等价于：
		vec_length(pntx-pnt0);

	向量：
		P11x = sin(angle1);
		P11y = cos(angle1);
		等价于：
		const Vector2d vec11(sin(angle1), cos(agnle1));
		
		P12x = pntX.y-pnt0.y;
		P12y = pntX.x-pnt0.x;
		等价于：//这个是不等价？
		const Vector2d vec12(pntX-pnt1);
		
		const Vect2d vec12(pntX-pnt1);
		等价于：
		const vect2d vec12(pntX.y-pnt1.y, pntX.x-pnt1.x);
		
		flagLR=P12y*cos(angle1)-P12x*sin(angle1);
		等价于：
		_cross_product2d(vec12, vec11);
		
		const Vector2d vec11(sin(angle1), cos(angle1));
		等价于：
		const Vector2d vec11(cos(angle1), sin(angle1));
x指东，y指北：逆时针为正；//正常情况下；x指北，y指东：顺时针为正；//特殊情况下；		

	2、
		RoadPLine_test.cpp:
			原来：
			node.coord.x = pt1.y+vec.y;//Line:86
			node.coord.y =  pt1.x+vec.x;
			node.coord.x	= node.coord.x + vec.y;//103
			node.coord.y	= node.coord.y + vec.x;
			现在：
			node.coord.x = pt1.x+vec.x;
			node.coord.y =  pt1.y+vec.y;
			node.coord.x	= node.coord.x + vec.x;
			node.coord.y	= node.coord.y + vec.y;
			
			原来：line:167
			const double dist	= sqrt((plNode.coord.x-north)*(plNode.coord.x-north)+(plNode.coord.y-east)*(plNode.coord.y-east));
			现在：
			const double dist	= sqrt((plNode.coord.y-north)*(plNode.coord.y-north)+(plNode.coord.x-east)*(plNode.coord.x-east));
			
			原来：line：334：
			plNode.coord.x
			现在：
			plNode.coord.y
			
			原来：282关闭；124打开；
			现在：打开     124关闭；

		StakeManage.cpp：
			原来：1166
			pt = pntNE;//错误：
		DK209200－DK282.hor：
			420：419:X=515316.375528,Y=2732489.634713
			1474：1473:X=483941.901974,Y=2714220.431340
			1499:X=483491.442313,Y=2713723.434224
			1713:X=475579.410049,Y=2708495.384701
	CLanguageManage
			//$(APP_DIR)/res/%s,  "string.txt" :"E:/gnss/southgnss_sdk/win32bin/res/string.txt"
				//该文件的内容：为所有的中文按模块进行编号？？
			//加载资源文件语言数据
			bool CLanguageManage::loadLanguageRes(const char *path)
			{
				if (!file_system_check_file(path))
				{
					return false;
				}
				m_StringMap.RemoveAll(); 
				
				InputFileStream is(path);
			
				char chRead[128]={0};
				int nLineSize=0;
				while((nLineSize=is_get_line(chRead, SIZEOF_ARRAY(chRead), is, TEXT_EOL_STYLE_DOS)))
				{
					const char *p=chRead;
					char chReadL[128]={0};
					char chReadR[128]={0};
					int nLeftSize=0;
					nLeftSize=next_word3(chReadL, p, ',', 100);
					if(nLeftSize>0 && nLeftSize<nLineSize)
					{
						next_word3(chReadR, p+nLeftSize, ',', 100);
						m_StringMap.SetAt(atoi(chReadL), CString(chReadR));
					}
					nLineSize=0;
				}
		
				return true;
			}

		//#include <wgis04_raster/wgis_raster.h>
		//#include <gnss01_kernel/string_ids.h>
		#include "stdafx.h"
		#include <gnss05_behaviours/behaviour_method.h>//edit_coord_system_proj
		#include <gnss04_survstar/coord_system_low_adapter.h>//tagCoordSystemPara
		#include <gnss04_survstar/ImportExport.h>//export_gis_sys_from_file
		#include <gnss04_survstar/SystemSettings.h>//ISystemSettings
		
		#include <gnss02_transform/gnss02_transform.h>//IRtkTransform
		#include <gnss01_gui/GuiManager.h>
		#include <gnss01_gui/DialogManager.h>//IDialogBehaviour
		#include <gnss01_kernel/General.h>//format_dot_dms
		#include <gnss00_utilities/gnss00_utilities.h>//FileGroupW
		#include "coord_transform_dialogs.h"//input_password


	桌面的导入数据点逻辑：
			void _load_control_point_par(CString strFileName)
				std::vector<ControlCoordPar>	m_vGcps;//
				清空数据；
				gcps_from_file(m_vGcps, chFileName);//从文件中获取数据；
				_view_control_point_list();//更新控件；
			int gcps_from_file(std::vector<ControlCoordPar> &gcps, const char *fnGcp)
				class GcpFileReader: public IDictionaryCallback；//定义一个类？？
				GcpFileReader reader(gcps);//构造该类的对象；
				return reader.loadGcps(fnGcp);//调用该类的方法然后返回；
			class GcpFileReader: public IDictionaryCallback
				父类：只有纯虚函数；
				成员：
				函数：
					int loadGcps(const char *fnGcps)
						return read_csv_with_head_file(*this, fnGcps, ',', cot_fldns);
			int read_csv_with_head_file(IDictionaryCallback &callBack, const char *fn, const char TOK, const char *_csvFldns)
				
			_view_control_point_list()
				清空数据；
	导入控制点的逻辑理解：
			import_ctrl_pnts_std(IDictionary &importInfo, IDbManager &dbMgr, const char *fnSrc文件名, const char *csvFldns, IProgress *tipAgent, const char *tipText)
				//（导入信息dic， DBManager， fnSrc？？文件名， csvFldns？？文件内容格式， 进度条指针， 提示信息字符串）
				CtrlPointCallBack ctrlPoint(dbMgr, csvFldns);//定义一个对象：
				int rc = ctrlPoint.readData(fnSrc, tipAgent, tipText);//调用读取函数方法；
					
			class CtrlPointImport : public IDialogBehaviour
				父类：
				成员：
				函数：
					void getExtName(char *ext, size_t sz, const IDictionary &dic)
						//获取选择的模式；
						//文件格式数组
						//根据模式选择扩展名，然后复制到ext中；
					int _importPoint(IDictionary &dicUI)
						
					_getCurFormat(dicUI, csvFldns)
						static char *allExt[] = {"RTK","dat", "cot"};//所有的扩展名//,"cot"//,"szName,dNorth,dEast,dElev,dLat,dLon,dEllipHgt"
						static char *nStdFormat[] = {"szName, dLat, dLon, dEllipHgt","szName, dNorth, dEast, dElev","szName,dNorth,dEast,dElev, dLat,dLon,dEllipHgt"};
						int mode = //获取选择的模式；
						csvFldns = nStdFormat[mode];//获取相应的文件内容格式；
					int _selectFolder(IDictionary &dicUI, int nType)
						char *csvFldns = NULL;
						const char *curExt = _getCurFormat(dicUI, csvfldns);//获取文件名后缀和文件内容格式；
						打开对话框
						保存路径
			class CtrlPointCallBack:public IDictionaryCallback
				父类：
					**
					* 读取带#! csvFldns头行的csv文件
					* @remarks 通过feedData()以字典形式反馈每一行数据；
					* @remarks 通过feedHeader()方法反馈其他#!信息
					*
					class IDictionaryCallback
					{
					public:
						virtual int feedHeader(int lineID, const char *sLine)=0;
						virtual int feedData(int lineID, const IDictionary &data)=0;
					};
				成员：
					IDbManager &m_dbMgr;;数据库管理类；
					ISurvStarTable &m_table;//都是一些纯需函数；
					int m_ctrlType;//当前导入的文件的类型，csvFldns确定？（怎么确定？）
					
					//统计数据
					int  m_ncount;//计数？什么的计数？
					int	 m_upNum；//更新的个数；就是同名合并的个数；
					int  m_addNum；//添加的个数
				函数：
					构造函数：
						CtrlPointCallBack(IDbManager &dbMgr, const char *csvFldns)
							: m_dbMgr(dbMgr)
							, m_table(dbMgr.getPointDatabase().getSurvStarTable(TABLE_CTRLPNT_DATA))
							, m_csvFldns(csvFldns)
							, m_count(0)
							, m_updNum(0)
							, m_addNum(0)
						{
							_setCtrlType(csvFldns);
							_setCommitSize(1000);
						}
					_setCtrlType(const char *csvFldns)
						cosnt char *csvNEH = "dNorth, dEast, dElev";//北坐标，东坐标，高程；//平面坐标
						const char *csvBLH = "dLat, dLon, dEllipHgt";//维度latitude，经度longitude，椭球高；
						
						m_ctrlType = 0;
						if(_checkCsvFlnds(csvNEH, csvFldns)>2)
						{
							m_ctrlType |= CTRL_TYPE_NE;//1;BL:2;H_NE:4;H_BL:8;
							m_ctrlType |= CTRL_TYPE_H_NE;
						}
						if(...)//BL;H_BL;
						{
						}
					_checkCsvFlnds(const char *allFlnds, const char *chkFlnds)
						int countFlnds = 0;
						const char *p = chkFlnds;//
						char chkKey[256];
						char allKey[256];
						while(*p)
						{
							按逗号分隔获取逗号前面的单词并下移；
							const char *q = allFlnds;
							while(*q)
							{
								按逗号分隔获取逗号前面的单词并下移；
								判断是否相等
									是则++countFlnds；
							}
						}
					void _setCommitSize(const int size)
						m_dbMgr.setCommitSize(size);
					int feedHeader(int lineID, const char *sLine)
						return 0；
					int feedData(int lineID, const IDictionary &rowData)
						首先把rowData转换成csa格式字符串(comma seperate quote)
						判断是何类型，获取数据；
						m_dbMgr.getLastCtrlIdByName();
					int readData(const char *fnSrc, IProgress *tipAgent, const char *tipText)
					{
						CallbackFile callback(this, tipAgent, tipText);//定义一个对象
						return read_import_rtk_file(callback, fnSrc, ',', m_csvFldns);//调用该方法；
					}
				class CallbackFile : public IDictionaryCallback
					
				int read_import_rtk_file(IDictionaryCallback &callBack, const char *fn文件名, const char TOK分隔符, 
					const char *_csvFldns 文件内容格式)
					//这个函数做了什么事情？解析文件数据，每解析完一行数据，就回调一个函数进行处理；
					char line[1000],csvFldns[2000],word[100], key[100], val[100];
					Dictionary  _dicLine;
					IDictionary &dicLine = _dicLine.getInnerObject();
					array_strncpy(csvFldns, _csvFldns);
					wlog("!%s", fn);
					InputFileStream is(fn, "rb");//读取文件内容：
					int count = 0, lineID = 0;
					while(!is.eof())
					{
						Timmer tm("while");
					
						++lineID;
						is_get_line(line, sizeof(line), is);
						csz_trim(line, line, CSZ_TRIM_ALL, "\n\r \t");
					
						if (!line[0])
						{
							continue;
						}
					
						if ('R'==line[0])//以R开头的
						{
							if (0==strncmp("Rem ", line, 4))
							{
								continue;
							}
						}
						if ('#'==line[0])//以#开头的
						{
							if ('!'==line[1])
							{
								const char *p = line+2;
								p += next_word3(word, p, '=', sizeof(word));
								if (0==strncmp("csvField", word, 6) || 0==strcmp("csvFldns", word))
								{
									char tmpFldns[2000];
									csz_trim(tmpFldns, p);
									csz_unquote(csvFldns,tmpFldns);
								}
								else
								{
									callBack.feedHeader(lineID, line+2);//直接调用函数存储点的数据；
								}
							}
							continue;
						}
						
						//以下是除了R和#开头的；
						const char *p = csvFldns;	// 字段域
						const char *q = line;		// 数据域
						while (*p)
						{
							p += next_word3(key, p, ',', sizeof(key));
							val[0] = 0;
							if(*q)
							{
								q += next_word3(val, q, TOK, sizeof(val));
							}
							dicLine.setValue(key, val);
						}
						callBack.feedData(lineID, dicLine);
						++count;
					}
					return count;
		数据库：
				class CDBManager : public IDbManager
					父类：
						class IDbManager
							只有虚函数；关于数据库的操作；
					成员：
						IConfigSections		*m_cfgMgr;
						IPointDatabase		*m_pointDB;//
						IPageOfPoints		*m_pagePoints;
						IDBRtkSettings		*m_rtkPar;
						IGnssBuffer			*m_gnssBuf;						
						int		m_openFlag;					//数据库文件是否已经打开
						int		m_updataFlag;				//数据库文件是否已经升级
					函数：
						构造函数：
							
						int getLastCtrlIdByName(int &rePntId, int &reType, const char *name)
							return m_pointDB->getLastCtrlIdByName(rePntId, reType, name);
				class IPointDatabase
					只有虚函数
				class CPointDatabase : public IPointDatabase
					成员：
						SurvStarDatabase m_db;
						ITextConverter &m_toUtf8;
						ITextConverter &m_fromUtf8;
						int m_openCount;			// 记录数据库打开次数
					
						sqlite3 *&m_conn;
					
						DbMetadataTable			*m_mdTable;
						IGnssTable				*m_pGnssTable;
						ISurvStarTable			*m_pStakePtTable;
						ISurvStarTable			*m_pStakeLineTable;
						ISurvStarTable			*m_pSurveyRangeTable;
						ISurvStarTable			*m_pSectionTable;
						ISurvStarTable			*m_pRtkSettingsTable;
						ISurvStarTable			*m_pCtrlPtTable;
						ISurvStarTable			*m_pRoadStationsTable;
					函数：
						构造函数：
			ConfigManager.cpp：
				都是一些函数？
				.h文件：都是一些命名空间和字符串定义；
				函数：	
					IConfigSections *surv_star_get_config_manager()
						char *iniFile = 
							$(APP_DIR)/../etc/SurvStar/surv_star_init_params.ini
							$(APP_DIR)/../etc/SurvStar/surv_star_init_params_gen.ini
						char *cfgFile = "$(APP_DIR)/../var/SurvStar/Configure.ini"
						// 用封装类对象来负责单例对象的分配和释放
						class Wrapper；
						static Wrapper w(cfgFile, iniFile, 0);
						return w.getConfigManager();
		调试过程：
				 	SurvStar_d.exe!CoordSystemEditMode::callBack(const char* msg = 0x1bb2a3c4, IDictionary& params = {...}) Line: 330, Byte Offsets: 0xf20	C++
					gnss04_mfc_dialogs_debug.dll!ReusableDialogBase::_triggerCallback(const char* schema = 0x01c87384, IDictionary& params = {...}) Line: 93, Byte Offsets: 0xf8	C++
					gnss04_mfc_dialogs_debug.dll!ReusableDialogBase::_controlClickedOrChanged(IControlLine* ctrl = 0x01c86d14) Line: 181, Byte Offsets: 0x434	C++
					gnss04_mfc_dialogs_debug.dll!ReusableDialogBase::_onClicked(const char* fldname = 0x01c997a4) Line: 235, Byte Offsets: 0xfc	C++
					gnss04_mfc_dialogs_debug.dll!ReusableDialogBase::slot(IDictionary& dicSlot = {...}) Line: 391, Byte Offsets: 0x81c	C++
					gnss04_mfc_dialogs_debug.dll!LineControl::callSlot(void) Line: 126, Byte Offsets: 0x180	C++
					gnss04_mfc_dialogs_debug.dll!CheckControl::OnLButtonUp(unsigned int nFlags = 0, CPoint point = {...}) Line: 820, Byte Offsets: 0x80	C++
					mfc90ud.dll!CWnd::OnWndMsg(unsigned int message = 514, unsigned int wParam = 0, long int lParam = 2686989, long int* pResult = 0x1bb2aaf4) Line: 2523, Byte Offsets: 0x1210	C++
					mfc90ud.dll!CWnd::WindowProc(unsigned int message = 514, unsigned int wParam = 0, long int lParam = 2686989) Line: 2089, Byte Offsets: 0x48	C++
					mfc90ud.dll!AfxCallWndProc(CWnd* pWnd = 0x01c86cd0, HWND__* hWnd = 0x7c082630, unsigned int nMsg = 514, unsigned int wParam = 0, long int lParam = 2686989) Line: 284, Byte Offsets: 0x25c	C++
					mfc90ud.dll!AfxWndProc(HWND__* hWnd = 0x7c082630, unsigned int nMsg = 514, unsigned int wParam = 0, long int lParam = 2686989) Line: 472, Byte Offsets: 0xe8	C++
					mfc90ud.dll!AfxWndProcBase(HWND__* hWnd = 0x7c082630, unsigned int nMsg = 514, unsigned int wParam = 0, long int lParam = 2686989) Line: 462, Byte Offsets: 0x48	C++
					SurvStar_d.exe!_try_handle_cpp_exception(bool& isHandle = false, HWND__* hwnd = 0x7c082630, unsigned int uMsg = 514, unsigned int wParam = 0, long int lParam = 2686989) Line: 52, Byte Offsets: 0x4c	C++
					SurvStar_d.exe!_my_wnd_proc(HWND__* hwnd = 0x7c082630, unsigned int uMsg = 514, unsigned int wParam = 0, long int lParam = 2686989) Line: 79, Byte Offsets: 0x30	C++
			SurvStart的主要调试过程：
				C:\Program Files (x86)\Microsoft Visual Studio 9.0\VC\ce\atlmfc\src\mfc\winmain.cpp
				int InitApplication()
				gnss00_utilities_debug.dll!ConfigSectionsImp::getConfiguration(const char* sectionName = 0x21b2fad0) Line: 216, Byte Offsets: 00	C++
					e:\gnss\southgnss_gui\gnss03_mfc_utilities\GuiManager.cpp
				SurvStar_d.exe!CSurvStarApp::InitInstance(void) Line: 206, Byte Offsets: 0x14c	C++
				c:\Program Files (x86)\Windows CE Tools\wce500\STANDARDSDK_500\Include\Armv4i\shellapi.h
					SHGetSpecialFolderPath
				void _createShortCut(const wchar_t *szPath)
			//CMainFrame：
				SurvStar_d.exe!CMainFrame::processEvent(const char* eventName = 0x78b1f1d4, const char* csaParams = 0x01c69c60, const void* binParams = 0x00000000) Line: 433, Byte Offsets: 0x24	C++
				gnss00_utilities_debug.dll!EventManagerImp::notify(const char* eventName = 0x78b1f1d4, const char* csaParams = 0x01c69c60, const void* binParams = 0x00000000) Line: 159, Byte Offsets: 0x300	C++
				gnss04_survstar_debug.dll!EventManagerOnWin32::notify(const char* eventName = 0x78b1f1d4, const char* csaParams = 0x01c69c60, const void* binParams = 0x00000000) Line: 150, Byte Offsets: 0x8c	C++
				gnss04_survstar_debug.dll!surv_star_command_trigger(IEventManager& evm = {...}, int cmd_id = 552, const void* binParams = 0x00000000) Line: 11, Byte Offsets: 0x78	C++
				SurvStar_d.exe!CMainFrame::_openJob(const char* jobFile = 0x01b3eaf0) Line: 358, Byte Offsets: 0x3ac	C++
				SurvStar_d.exe!CMainFrame::_openLastJob(void) Line: 428, Byte Offsets: 0x9c	C++
				SurvStar_d.exe!CMainFrame::OnCreate(tagCREATESTRUCTW* lpCreateStruct = 0x21b2ecf0) Line: 107, Byte Offsets: 0x108	C++
				mfc90ud.dll!CWnd::OnWndMsg(unsigned int message = 1, unsigned int wParam = 0, long int lParam = 565374192, long int* pResult = 0x21b2e604) Line: 2350, Byte Offsets: 0xc30	C++
				mfc90ud.dll!CWnd::WindowProc(unsigned int message = 1, unsigned int wParam = 0, long int lParam = 565374192) Line: 2089, Byte Offsets: 0x48	C++
				SurvStar_d.exe!CMainFrame::WindowProc(unsigned int message = 1, unsigned int wParam = 0, long int lParam = 565374192) Line: 144, Byte Offsets: 0x98	C++
				mfc90ud.dll!AfxCallWndProc(CWnd* pWnd = 0x01c59c10, HWND__* hWnd = 0x7c0815f0, unsigned int nMsg = 1, unsigned int wParam = 0, long int lParam = 565374192) Line: 284, Byte Offsets: 0x25c	C++
				mfc90ud.dll!AfxWndProc(HWND__* hWnd = 0x7c0815f0, unsigned int nMsg = 1, unsigned int wParam = 0, long int lParam = 565374192) Line: 472, Byte Offsets: 0xe8	C++
				mfc90ud.dll!AfxWndProcBase(HWND__* hWnd = 0x7c0815f0, unsigned int nMsg = 1, unsigned int wParam = 0, long int lParam = 565374192) Line: 462, Byte Offsets: 0x48	C++
				SurvStar_d.exe!_try_handle_cpp_exception(bool& isHandle = false, HWND__* hwnd = 0x7c0815f0, unsigned int uMsg = 1, unsigned int wParam = 0, long int lParam = 565374192) Line: 52, Byte Offsets: 0x4c	C++
				SurvStar_d.exe!_my_wnd_proc(HWND__* hwnd = 0x7c0815f0, unsigned int uMsg = 1, unsigned int wParam = 0, long int lParam = 565374192) Line: 79, Byte Offsets: 0x30	C++
				mfc90ud.dll!DefWindowProcEx(HWND__* hWnd = 0x7c0815f0, unsigned int nMsg = 1, unsigned int wParam = 0, long int lParam = 565374192) Line: 973, Byte Offsets: 0xcc	C++
			//坐标转换	
				SurvStar_d.exe!CMainFrame::processEvent(const char* eventName = 0x0023d330, const char* csaParams = 0x01c7f730, const void* binParams = 0x01c69ca0) Line: 678, Byte Offsets: 0x1478	C++
				gnss00_utilities_debug.dll!EventManagerImp::notify(const char* eventName = 0x0023d330, const char* csaParams = 0x01c7f730, const void* binParams = 0x01c69ca0) Line: 159, Byte Offsets: 0x300	C++
				gnss04_survstar_debug.dll!EventManagerOnWin32::notify(const char* eventName = 0x0023d330, const char* csaParams = 0x01c7f730, const void* binParams = 0x01c69ca0) Line: 150, Byte Offsets: 0x8c	C++
				SurvStar_d.exe!CMainFrame::processEvent(const char* eventName = 0x0034dda4, const char* csaParams = 0x01c80f94, const void* binParams = 0x01c69ca0) Line: 503, Byte Offsets: 0x7a4	C++
				gnss00_utilities_debug.dll!EventManagerImp::notify(const char* eventName = 0x0034dda4, const char* csaParams = 0x01c80f94, const void* binParams = 0x01c69ca0) Line: 159, Byte Offsets: 0x300	C++
				gnss04_survstar_debug.dll!EventManagerOnWin32::notify(const char* eventName = 0x0034dda4, const char* csaParams = 0x01c80f94, const void* binParams = 0x01c69ca0) Line: 150, Byte Offsets: 0x8c	C++
				?callBack@MenuBehaviour@@UAAHPBDAAVIDictionary@@@Z	
				gnss04_mfc_dialogs_debug.dll!show_window_menu(IDictionary& dicOut = {...}, IDictionary& dicMenu = {...}, HWND__* parent = 0x7c07f490, IDialogBehaviour* bav = 0x01b48b30, IGuiManager& uiMgr = {...}) Line: 232, Byte Offsets: 0x130	C++
				gnss04_mfc_dialogs_debug.dll!ask_by_named_dialog(IDictionary& dicOut = {...}, IDictionary& dicIn = {...}, const char* dialog_name = 0x01c63fc4, IGuiManager& uiMgr = {...}, IDialogBehaviour* callBack = 0x01b48b30) Line: 74, Byte Offsets: 0x1dc	C++
				gnss04_mfc_dialogs_debug.dll!MFCDialogManagerImp::doModal(IDictionary& params = {...}, const char* dialog_name = 0x01c63fc4, IDialogBehaviour* callBack = 0x01b48b30) Line: 185, Byte Offsets: 0x48	C++
				?showMenu@CMainUiManager@@UAAHPBD0PBVIDictionary@@@Z	
				?callBack@MenuBehaviour@@UAAHPBDAAVIDictionary@@@Z	
				?WindowProc@CWndUiContainer@@EAAJIIJ@Z	
				mfc90ud.dll!AfxCallWndProc(CWnd* pWnd = 0x01c637d0, HWND__* hWnd = 0x7c07fc30, unsigned int nMsg = 273, unsigned int wParam = 5, long int lParam = 0) Line: 284, Byte Offsets: 0x25c	C++
				mfc90ud.dll!AfxWndProc(HWND__* hWnd = 0x7c07fc30, unsigned int nMsg = 273, unsigned int wParam = 5, long int lParam = 0) Line: 472, Byte Offsets: 0xe8	C++
				mfc90ud.dll!AfxWndProcBase(HWND__* hWnd = 0x7c07fc30, unsigned int nMsg = 273, unsigned int wParam = 5, long int lParam = 0) Line: 462, Byte Offsets: 0x48	C++
				SurvStar_d.exe!_try_handle_cpp_exception(bool& isHandle = false, HWND__* hwnd = 0x7c07fc30, unsigned int uMsg = 273, unsigned int wParam = 5, long int lParam = 0) Line: 52, Byte Offsets: 0x4c	C++
				SurvStar_d.exe!_my_wnd_proc(HWND__* hwnd = 0x7c07fc30, unsigned int uMsg = 273, unsigned int wParam = 5, long int lParam = 0) Line: 79, Byte Offsets: 0x30	C++

	1027.1：对话框的修改：1028.1 1101.3
		a、要达成的效果：
			e:\gnss\south_tools\CoordSystemTool\SettingConvertConfigDlg.cpp
			e:\gnss\SurvStar\SurvStar\ToolComputeTransParamConfig.cpp
			e:\gnss\south_tools\RoadDesign\AddBrokenChainDlg.cpp  ？？
			
			e:\gnss\SurvStar\SurvStar\CoordSysEdit.cpp
		b、修改步骤；
			1、删除原来的内容，添加头文件：
				#include <gnss00_utilities/dictionary_utils.h>
				#include <gnss01_gui/DialogManager.h>
				
			2、增加对话框布局文件：dlg文件				
						
			3、分析实现原理：				
				1、定义三个对象：添加头文件：
					class IDialogBehaviour
					class ICallbackDialog
					class IDialogManager
				2、EXTENSIBLE_FACTORY_DECLARE(IDialogManager, API01);
					*
					* 可扩展工厂的声明
					*
					* @remarks csvTypeString允许指定多个类型字符串(以半角逗号分开)
					*     如果extensible_factory_register_IMapProjection("gauss,tmerc2", "", ctor1, dtor1);
					*     则下面两种调用将返回同一类型的实例：
					*     extensible_factory_get_IMapProjection("gauss:ellps=iau76,lon_0=111,x_0=500000",0);
					*     extensible_factory_get_IMapProjection("tmerc2:ellps=iau76,lon_0=111,x_0=500000",0);
					*
					#define EXTENSIBLE_FACTORY_DECLARE(InterfaceType, DLL_API_SPEC) \
						C_API DLL_API_SPEC InterfaceType *extensible_factory_get_##InterfaceType(const char *schema, const void *binParams);\
						C_API DLL_API_SPEC void extensible_factory_release_##InterfaceType(InterfaceType *&p);\
						C_API DLL_API_SPEC void extensible_factory_register_##InterfaceType(const char *csvTypeStrings, const char *descrpitionString, InterfaceType* (*ctor)(const char *csaParams, const void *binParams), void (*dtor)(InterfaceType*&));\
						C_API DLL_API_SPEC int extensible_factory_list_##InterfaceType##_type_strings(IOutputStream &os);\
						C_API DLL_API_SPEC const char *extensible_factory_get_##InterfaceType##_description(const char *distinction_tag);
				3、EXTENSIBLE_FACTORY_DEFINE
				4、EXTENSIBLE_FACTORY_REGISTER
				class QtDialogManagerImp: public IDialogManager
					//怎样查看宏定义的值？
						//VC的话 /P输出预处理之后的代码 
						//用VA就可以了。鼠标往宏或枚举上一放，值就显示出来了，是显示直接定义还是最终值，请在VA选项里配置
							//http://www.cnblogs.com/gaojun/archive/2010/03/16/1687304.html
						#define PRINT1(f, ...)                                
						{                                                     
							TCHAR buf[256];                                   
							wsprintf(buf, f, __VA_ARGS__);                    
							MessageBox(NULL, buf, TEXT("DEBUG"), MB_OK);      
						}
						#define PRINT2(f, v)                                  
						{                                                     
							TCHAR buf[256];                                   
							wsprintf(buf, TEXT(#v) TEXT(" = ") TEXT(#f), v);  
							MessageBox(NULL, buf, TEXT("DEBUG"), MB_OK);      
						}
						
						void func()
						{
							int a = 1;
							TCHAR b[] = TEXT("string");
							PRINT1(TEXT("a = %d, b= %s."), a, b);
							PRINT2(%d, a);
							PRINT2(%s, b);
						}
			其他修改例子：转换设置
				坐标系统:求转换参数：设置：
					对应SurvStar：工具：计算转换参数：计算：
					E:\gnss\southgnss_sdk\etc\gnss04_dialogs\survstar_tool_convert_config.dlg
						里面的值从E:\gnss\southgnss_sdk\etc\SurvStar\cn\surv_star_strings2.ini的tool_convert_config字段获取；
					对应的也是这个文件；
				其他的都一样；				
					fldname是字典中约定的key名：通常是源代码中的变量名；
					但是#得文件在哪呢？#KeyBoardUsage
				
					tool_calculate_trans_param_config：打开对话框函数：	
						获取全局的配置文件管理对象；IConfigSections；
						获取对话框配置管理对象：IDialogManger；
						获取对话框中的转换参数配置内容：key ："TransformConfig"
							"FittingMode,HorLimit,RmsAssignMode,TransformMethod,UseRmsAssign,VtcLimit,
							mode,parent_hwnd"
						然后创建一个回调函数对象（这个是要自己写的）：里面是一个回调函数
						doModal
							ask_by_named_dialog
								如果是打开文件
									结果视图
									虚拟键盘数字
									菜单列表
									菜单窗口
									虚拟键文本
									这些对话框类型的话就另外处理；
								否则
								获取对话框文件路径：
									uiMgr.getDlgFilePath()：
										"/Program Files/SurvStar/etc/gnss04_dialogs/"
									resolve_dlg_file：根据解析的参数，查看是否需要获取环境变量的值来替换；
										"/Program Files/SurvStar/etc/gnss04_dialogs/survstar_tool_convert_config.dlg"
									
									huoqu 点的坐标:Point：x=330；y=628；
										"$form_top_left_x,$form_top_left_y,
										FittingMode,HorLimit,RmsAssignMode,TransformMethod,UseRmsAssign,VtcLimit,
										mode,parent_hwnd"
									cfgMgr->getConfiguration(g_cm_transform_config)：
										"$form_top_left_x,$form_top_left_y,
										FittingMode,HorLimit,KeyBoardUsage,RmsAssignMode,TransformMethod,UseRmsAssign,VtcLimit,
										_productMask,_splash,_title_bar,()
										label1,label2,label3,label4,label5,label6,label7,()
										mode,parent_hwnd"
										
									resuable_dialog_show_modal()
										设置父进程
										设置监听对话框事件
										doModal
										获取输出参数
							
						然后释放回调函数
				对于该对话框的消息处理函数：
					gnss04_mfc_dialogs_debug.dll!LineControl::set_readonly_and_keyboard(IDictionary& record = {...}, IDictionary& dicCfg = {...}, ReusableEditEx* wnd = 0x01c82a20) Line: 180, Byte Offsets: 0x10	C++
					gnss04_mfc_dialogs_debug.dll!EditBaseControl::initEdit(IDictionary& dic = {...}, ILayoutBox* box = 0x01c81d10) Line: 1088, Byte Offsets: 0x118	C++
					gnss04_mfc_dialogs_debug.dll!SingleEditControl::SingleEditControl(ILayoutBox* box = 0x01c81d10, IDictionary& dic = {...}, ISlotWindow* slot = 0x1fb2aef0, IGuiManager& uiMgr = {...}) Line: 1107, Byte Offsets: 0xbc	C++
					gnss04_mfc_dialogs_debug.dll!control_line_get_instance(ILayoutBox* box = 0x01c81d10, IDictionary& dic = {...}, ISlotWindow* slot = 0x1fb2aef0, IGuiManager& uiMgr = {...}) Line: 1653, Byte Offsets: 0x20c	C++
					gnss04_mfc_dialogs_debug.dll!parse_controls(const char* fnCfg = 0x1fb2af70, IDictionary& params = {...}, std::map<int,IControlLine *,std::less<int>,std::allocator<std::pair<int const ,IControlLine *> > >& name2ctrl = {...}, ILayoutBox* vLayout = 0x01c7b4f0, ISlotWindow* slotWindow = 0x1fb2aef0, IGuiManager& uiMgr = {...}) Line: 603, Byte Offsets: 0x104c	C++
					gnss04_mfc_dialogs_debug.dll!ReusableDialog::_generateForm(void) Line: 20, Byte Offsets: 0x8c	C++
					gnss04_mfc_dialogs_debug.dll!ReusableDialog::OnInitDialog(void) Line: 78, Byte Offsets: 0x40	C++
					当点击对话框的lineedit内的编辑框后：
						 	gnss04_mfc_dialogs_debug.dll!ask_by_named_dialog(IDictionary& dicOut = {...}, IDictionary& dicIn = {...}, const char* dialog_name = 0x79014c1c, IGuiManager& uiMgr = {...}, IDialogBehaviour* callBack = 0x00000000) Line: 64, Byte Offsets: 0xfc	C++
							gnss04_mfc_dialogs_debug.dll!ReusableDialogBase::slot(IDictionary& dicSlot = {...}) Line: 345, Byte Offsets: 0x698	C++
							gnss04_mfc_dialogs_debug.dll!LineControl::callSlot(void) Line: 119, Byte Offsets: 0x174	C++
							gnss04_mfc_dialogs_debug.dll!EditBaseControl::OnLButtonUp(unsigned int nFlags = 0, CPoint point = {...}) Line: 1044, Byte Offsets: 0x64	C++
							mfc90ud.dll!CWnd::OnWndMsg(unsigned int message = 514, unsigned int wParam = 0, long int lParam = 3407938, long int* pResult = 0x1fb2a568) Line: 2523, Byte Offsets: 0x1210	C++
							mfc90ud.dll!CWnd::WindowProc(unsigned int message = 514, unsigned int wParam = 0, long int lParam = 3407938) Line: 2089, Byte Offsets: 0x48	C++
							gnss04_mfc_dialogs_debug.dll!ReusableEditEx::WindowProc(unsigned int message = 514, unsigned int wParam = 0, long int lParam = 3407938) Line: 252, Byte Offsets: 0x28	C++
							mfc90ud.dll!AfxCallWndProc(CWnd* pWnd = 0x01c82a20, HWND__* hWnd = 0x7c0845a0, unsigned int nMsg = 514, unsigned int wParam = 0, long int lParam = 3407938) Line: 284, Byte Offsets: 0x25c	C++
							mfc90ud.dll!AfxWndProc(HWND__* hWnd = 0x7c0845a0, unsigned int nMsg = 514, unsigned int wParam = 0, long int lParam = 3407938) Line: 472, Byte Offsets: 0xe8	C++
							mfc90ud.dll!AfxWndProcBase(HWND__* hWnd = 0x7c0845a0, unsigned int nMsg = 514, unsigned int wParam = 0, long int lParam = 3407938) Line: 462, Byte Offsets: 0x48	C++
							SurvStar_d.exe!_try_handle_cpp_exception(bool& isHandle = false, HWND__* hwnd = 0x7c0845a0, unsigned int uMsg = 514, unsigned int wParam = 0, long int lParam = 3407938) Line: 52, Byte Offsets: 0x4c	C++
							SurvStar_d.exe!_my_wnd_proc(HWND__* hwnd = 0x7c0845a0, unsigned int uMsg = 514, unsigned int wParam = 0, long int lParam = 3407938) Line: 79, Byte Offsets: 0x30	C++
				回调函数的编写：
					先修改：
						
				常用的查看字典内的信息函数；
						{
							StreamFormatter fmt;
							dictionary_get_keys(fmt, dic);
							const char *csvkeys = fmt.getBuffer();
						
							char key[100]={0};
							const char *p = csvkeys;
							while(*p)
							{
								p += next_word3(key, p, ',', sizeof(key));
								const char *val = dic.getValue(key);
							}
						}
						{
							StreamFormatter fmt;
							dictionary_get_keys(fmt, dicOut);
							const char *csvkeys = fmt.getBuffer();
						}			
				查看mfc下的流程是怎样的？
					
			其他修改例子：四参设置
				坐标转换：四参设置：
					对应的SurvStar：工程：工程属性：坐标系：
						E:\gnss\southgnss_sdk\etc\gnss04_dialogs\survstar_coord_system_edit_four_setting.dlg//这里有这个coord_system_four_setting键值；
							里面的值从E:\gnss\southgnss_sdk\etc\SurvStar\cn\surv_star_strings2.ini文件的coord_system_four_setting字段获取；
					
				自己的修改：
					1、添加dlg文件：south_tools_coord_edit_four_param.dlg
						//Deployment->AdditionalFiles：
						//只是换个名字而已的话，内容不变也是可以的？
						dialog_title:@dialog_name
						title_name:coord_system_four_setting
						dialog_width:320;
						dialog_height:412;
						
						space:26;
						goup:v
						{
							group:h;height:33;
							{	//control:lineedit;fldname:dN2;showname:@dN2_label;keyboard:#KeyBoardUsage;numberflag:0;regex:.+;notice:@dN2_notice;label_size:150;
								control:label;:101;fldname:dN2_label;defaultValue:@dN2_label;width:145;
								control:textedit;:201;fldname:dN2;keyboard:#KeyBoardUsage;numberflag:0.0;width:320;
								//这样替换是成功的，只要确保fldname：是一样的，并且有值；如果不存在，则数值无法保存；
								//问题是dN2是哪里来的？
							}
							
							group:h;height:33;
							{
								control:label;:102;fldname:label2;defaultValue:@dE2_label;width:120;
								control:textedit;:202;fldname:dE2;showname:@dE2;keyboard:#KeyBoardUsage;numberflag:0.0;width:150;
							}
							group:h;height:33;
							{
								control:label;:103;fldname:label3;defaultValue:@rot_label;width:120;
								control:textedit;:203;fldname:rot;showname:@rot;keyboard:#KeyBoardUsage;numberflag:0.0;width:150;
							}
							group:h;height:33;
							{
								control:label;:104;fldname:label4;defaultValue:@scl_label;width:120;
								control:textedit;:204;fldname:scl;keyboard:#KeyBoardUsage;numberflag:0.0;width:150;
							}
						}
						
						group:h;height:43;
						{
							control:pushbutton;:301;fldname:ok;showname:@ok;on_click:accept;
							control:pushbutton;:302;fldname:cancel;showname:@cancel;on_click:reject;
						}
		其他修改例子：空间距离：
			SurvStar：工具：空间距离：
				dialog_title:"空间距离"
				title_name:tool_space_dist_edit
				dialog_width:480;
				dialog_height:640;
				
				group:v;height:225
				{
					group;height:42;
					{
						control:label;		width:150;defaultValue:@start_blh;
					}
				
					group;height:42;
					{
						control:label;		width:150;defaultValue:@pnt_name;
						control:textedit;	fldname:start_name;keyboard:#KeyBoardUsage;numberflag:1;readonly:0;
						control:pushbutton;	width:050;fldname:btn_select_neh;on_click:call_back;call_back:ask_sel_start_blh;icon:point_db.ico;	
					}	
				
					group;height:42;
					{
						control:label;		width:150;defaultValue:@lat;
						control:textedit;	fldname:start_lat;keyboard:#KeyBoardUsage;numberflag:0;readonly:0;
						control:label;		width:050;fldname:lab_black;
					}
				
					group;height:42;
					{
						control:label;		width:150;defaultValue:@lon;
						control:textedit;	fldname:start_lon;keyboard:#KeyBoardUsage;numberflag:0;readonly:0;
						control:label;		width:050;fldname:lab_black;
					}
					
					group;height:42;
					{
						control:label;		width:150;defaultValue:@elliphgt;
						control:textedit;	fldname:start_elliphgt;keyboard:#KeyBoardUsage;numberflag:0;readonly:0;
						control:label;		width:050;fldname:lab_black;
					}
				}
				
				group:v;height:225
				{
					group;height:42;
					{
						control:label;		width:150;defaultValue:@end_blh;
					}
				
					group;height:42;
					{
						control:label;		width:150;defaultValue:@pnt_name;
						control:textedit;	fldname:end_name;keyboard:#KeyBoardUsage;numberflag:1;readonly:0;
						control:pushbutton;	width:050;fldname:btn_select_neh;on_click:call_back;call_back:ask_sel_end_blh;icon:point_db.ico;	
					}	
				
					group;height:42;
					{
						control:label;		width:150;defaultValue:@lat;
						control:textedit;	fldname:end_lat;keyboard:#KeyBoardUsage;numberflag:0;readonly:0;
						control:label;		width:050;fldname:lab_black;
					}
				
					group;height:42;
					{
						control:label;		width:150;defaultValue:@lon;
						control:textedit;	fldname:end_lon;keyboard:#KeyBoardUsage;numberflag:0;readonly:0;
						control:label;		width:050;fldname:lab_black;
					}
					
					group;height:42;
					{
						control:label;		width:150;defaultValue:@elliphgt;
						control:textedit;	fldname:end_elliphgt;keyboard:#KeyBoardUsage;numberflag:0;readonly:0;
						control:label;		width:050;fldname:lab_black;
					}
				}
				
				group:h;height:42
				{
					control:label;		width:150;defaultValue:@base_len;
					control:textedit;	fldname:base_length;keyboard:#KeyBoardUsage;numberflag:0;readonly:0;
					control:label;		width:050;fldname:lab_black;
				}
				
				group;height:50
				{
					control:pushbutton;fldname:btn_ok;showname:@calc;on_click:call_back;call_back:ask_calc;
					control:label;		width:050;fldname:lab_black;width:100;
					control:pushbutton;fldname:btn_cannel;showname:@cancel;on_click:reject;
				}
			其他修改例子：
				常规设置->常规：下拉列表框
					参考：survstar_config_set_short_cut.dlg
				survstar_config_general_set.dlg
					0x78e8f444 "$(APP_DIR)/../var/Configure.ini"
					0x78e8f418 "$(APP_DIR)/../etc/surv_star_init_params.ini"
					0x23b2f5b0 "/Program Files/SurvStar/etc/surv_star_rtk_commands.ini"
					urv_star_strings2.ini
					//根据配置文件信息创建事件对象
					//获取配置文件信息
					return 1；表示取消，还在原来的对话框；
					return 0；表示确定，退出对话框；
					
				group:v;height:50;
				{
					group:h;
					{
						control:label;201;showname:@time_zone_label;
						control:combobox;301;fldname:TimeZone;fill_pairs:@time_zone;enable;$mode&2;height:200;
					}
				}
				
				group:v;height:50;
				{
					group:h;
					{
						control:label;202;showname:@tilt_angle_label;
						control:textedit;401;fldname:TiltAngle;
					}
				}
				//回调函数的编写：
					elevation 海拔高度  antenna 天线  radius 半径范围
				namespace
				{
					//常规设置
					const char *g_cm_generalset_set			= "GeneralSet";
					const char *g_gs_use_voice_promt		= "UseVoicePrompt";
					const char *g_gs_use_store_tolerance	= "UseStoreTolerance";
					const char *g_gs_use_elec_bubble		= "UseElecBubble";
					const char *g_gs_use_base_tolerance		= "UseBaseTolerance";
					const char *g_gs_time_zone				= "TimeZone";
					const char *g_gs_tilt_angle				= "TiltAngle";
					const char *g_gs_increment_step			= "IncrementStep";
					const char *g_gs_base_dist				= "BaseDist";
					const char *g_gs_tilt_limit				= "TiltLimit";
					const char *g_gs_time_zone_all			= "TimeZoneAll";
				}
				//虚拟键盘的调出有问题：
				
				
				//原来的对话框逻辑：
					#include "stdafx.h"
					#include <gnss00_utilities/gnss00_utilities.h>
					#include <gnss01_gui/DialogManager.h>
					#include <gnss03_mfc_utilities/GuiManager.h>
					#include <gnss04_survstar/ConfigManager.h>
					#include "SurvStar.h"
					
					// CSetupGeneral 对话框
					
					class GeneralSettingBehaviour : public IDialogBehaviour
					{
						Dictionary _m_dic;
						IDictionary &m_dic;
						IConfigSections &m_cfgMgr;
						const char *m_generalset;
					public:
						GeneralSettingBehaviour(IConfigSections &cfgMgr) 
							: m_dic(_m_dic.getInnerObject())
							, m_cfgMgr(cfgMgr)
						{
							const IDictionary &dicProduct = *(cfgMgr.getConfiguration(g_cm_gui_config));
							int productMask = dic_get_i4(dicProduct, g_gui_product_mask, "1");
							m_generalset = g_cm_general_config;
					
							const IDictionary &dic = *(cfgMgr.getConfiguration(m_generalset));
							int nTemp = dic_get_i4(dic, g_gc_use_voice_prompt, "");
							dic_set_value(m_dic, g_gc_use_voice_prompt, "%d", nTemp);
							nTemp = dic_get_i4(dic, g_gc_use_store_tolerance, "");
							dic_set_value(m_dic, g_gc_use_store_tolerance, "%d", nTemp);
							nTemp = dic_get_i4(dic, g_gc_use_elec_bubble, "");
							dic_set_value(m_dic, g_gc_use_elec_bubble, "%d", nTemp);
							nTemp = dic_get_i4(m_dic, g_gc_use_base_tolerance, "");
							dic_set_value(m_dic, g_gc_use_base_tolerance, "%d", nTemp);
					
							nTemp = dic_get_i4(dic, g_gc_time_zone, "8");
							nTemp += 12;
							dic_set_value(m_dic, g_gc_time_zone, "%d", nTemp);
					
							double dTemp = dic_get_r8(dic, g_gc_elevation_mask, "10");
							dic_set_value(m_dic, g_gc_elevation_mask, "%.1f", dTemp);
					
							nTemp = dic_get_i4(dic, g_gc_increment_step, "1");
							dic_set_value(m_dic, g_gc_increment_step, "%d", nTemp);
					
							dTemp = dic_get_r8(dic, g_gc_base_tolerance, "5000");
							dic_set_value(m_dic, g_gc_base_tolerance, "%.3f", dTemp);
					
							dTemp = dic_get_r8(dic, g_gc_tilt_limit, "0.02");
							dic_set_value(m_dic, g_gc_tilt_limit, "%.2f", dTemp);
					
						}
						IDictionary &getDictionary()
						{
							return m_dic;
						}
						int callBack(const char *msg, IDictionary &params)
						{
							char call_back[20];
							next_word3(call_back, msg, ':', sizeof(call_back));
							if (0 == csz_stricmp(call_back, "ok"))
							{
								int nUseVoicePrompt = dic_get_i4(params, g_gc_use_voice_prompt, "");
								int nUseStoreTolerance = dic_get_i4(params, g_gc_use_store_tolerance, "");
								int nUseElecBubble = dic_get_i4(params, g_gc_use_elec_bubble, "");
								int nUseBaseDistTolerance = dic_get_i4(params, g_gc_use_base_tolerance, "");
					
								int nTimeZone = dic_get_i4(params, g_gc_time_zone, "");
								nTimeZone -= 12;
								double dElevationMask = dic_get_r8(params, g_gc_elevation_mask, "");
								int nIncrementStep = dic_get_i4(params, g_gc_increment_step, "");
								//卫星截止角设置不合理
								if ( dElevationMask<0 || 90<=dElevationMask || nIncrementStep<=0)
								{
									HWND hwnd = (HWND)dic_get_i4(params, "hwnd");
									message_box(hwnd, IDS_SET_MSGBOX_INPUT_VALID_VALUE, IDS_PUBLIC_MSGBOX_WARNNING, MB_ICONINFORMATION);
									return 1;
								}
								double dBaseDistTolerance = dic_get_r8(params, g_gc_base_tolerance, "");
								double dTiltLimit = dic_get_r8(params, g_gc_tilt_limit, "");
								//基站距离阈值、倾斜限差设置不合理
								if (dBaseDistTolerance<0 || dTiltLimit<0)
								{
									HWND hwnd = (HWND)dic_get_i4(params, "hwnd");
									message_box(hwnd, IDS_SET_MSGBOX_INPUT_VALID_VALUE, IDS_PUBLIC_MSGBOX_WARNNING, MB_ICONINFORMATION);
									return 1;
								}
								Dictionary _dic;
								IDictionary &dic = _dic.getInnerObject();
								dic_set_value(dic, g_gc_use_voice_prompt, "%d", nUseVoicePrompt);
								dic_set_value(dic, g_gc_use_store_tolerance, "%d", nUseStoreTolerance);
								dic_set_value(dic, g_gc_use_elec_bubble, "%d", nUseElecBubble);
								dic_set_value(dic, g_gc_use_base_tolerance, "%d", nUseBaseDistTolerance);
					
								dic_set_value(dic, g_gc_time_zone, "%d", nTimeZone);
					
								dic_set_value(dic, g_gc_elevation_mask, "%.1f", dElevationMask);
								dic_set_value(dic, g_gc_increment_step, "%d", nIncrementStep);
								dic_set_value(dic, g_gc_base_tolerance, "%.3f", dBaseDistTolerance);
								dic_set_value(dic, g_gc_tilt_limit, "%.2f", dTiltLimit);
								m_cfgMgr.setConfiguration(m_generalset, &dic, 1);
							}
							return 0;
						}
					};
					
					int setup_general(ISurvStar &settings, HWND p)
					{
						IGuiManager &uiMgr = settings.getUiManager();
						IDialogManager *dlgMgr = uiMgr.getDialogManager();
					
						IConfigSections &cfgMgr = settings.getConfigSections();
						GeneralSettingBehaviour behav(cfgMgr);
						IDictionary &dic = behav.getDictionary();
						if (p)
						{
							dic_set_value(dic, "parent_hwnd", "%d", p);
						}
						return dlgMgr->doModal(dic, "survstar_config_general_set.dlg", &behav);
					}
					
				//设置基站阈值限制获取不到值得问题：
					e:\gnss\SurvStar\SurvStar\SetupGeneral.cpp //不知道什么原因？？
				//设置断点：
					e:\gnss\SurvStar\SurvStar\SettingShortcut.cpp
						int callBack(const char *msg, IDictionary &params)
					e:\gnss\SurvStar\SurvStar\SetupGeneral.cpp 
						int callBack(const char *msg, IDictionary &params)
						GeneralSettingBehaviour(IConfigSections &cfgMgr)
						int setup_general(ISurvStar &settings, HWND p)
					e:\gnss\SurvStar\SurvStar\CommonCommands.cpp
						virtual void execute(const char *csaParam, void *binParam)
					e:\gnss\southgnss\gnss00_utilities\ConfigSections.cpp
			 其他修改例子：添加控制点参数和编辑控制点参数：
				E:\gnss\southgnss_sdk\etc\SurvStar\cn\surv_star_strings2.ini
				latitude 纬度  longitude 经度
				
				//fldname：key名


	1017.2:文件读取的转换：
		原模块的文件读取函数的使用：
		bool CLanguageManage::LoadConfig()：
		    CString strFilePath;
			strFilePath.Format(_T("%s\\res\\config.ini"), strTemName);
			CSouthReadFile ResFile;
			if (ResFile.Open(strFilePath))//打开文件成功
			{
				char cRead[MAX_READ_LINE];
				CString strLine;
				while(ResFile.GetLine(cRead))//循环读取一行数据
				{            
					strLine = CString(cRead);//
					if (strLine.Find(',') > 0)//如果能够查找到逗号
					{
						strLine = strLine.Left(strLine.Find(','));//找到的话就获取左边的字段
					}
					return switchLanguage(_wtoi(strLine));//返回转换为整数的值；
				}
			}
		库的文件函数操作步骤：
			void zip_test()
			{
				char wsp1[255] = {0};
				get_sample_data(wsp1, "surv_star_etc/surv_star_init_params.ini");
				char wsp2[255] = {0};
				get_sample_data(wsp2, "surv_star_etc/etc.zip");
		
				StreamFormatter _fmt1;
				IStreamFormatter &fmt1(_fmt1.getInnerObject());//定义一个流对象
				os_printf(fmt1, "os_file:path=%s", wsp1);//格式化文件路径，传入流对象，就打开文件了？不是，只是构造文件路径而已
				const char *csa1 = fmt1.getBuffer();//获取文件内容//获取文件路径
				char buf1[1000]={0};
				StreamContainer c1(csa1, 0);//定义一个container对象
				IInputStream &is1 = c1.getInputStream();//获取一个输入流对象
		
				StreamFormatter _fmt2;
				IStreamFormatter &fmt2(_fmt2.getInnerObject());
				os_printf(fmt2, "zip_file:path=%s,subPath=SurvStar/surv_star_init_params.ini", wsp2);
				const char *csa2 = fmt2.getBuffer();
		
				char buf2[1000]={0};
				StreamContainer c2(csa2, 0);
				IInputStream &is2 = c2.getInputStream();
		
				while(!is1.eof())
				{
					is_get_line(buf1, sizeof(buf1), is1);
					is_get_line(buf2, sizeof(buf2), is2);
					AUTO_TEST_ASSERT_STR_EQUAL(buf1, buf2);
				}
			}
		bool CLanguageManage::loadLanguageRes(CString strResPathFile):		
			CSouthReadFile ResFile;
			if (ResFile.Open(strResPathFile))//打开文件
			{
				char cRead[MAX_READ_LINE];
				CString strLine;
				CString strID, strString;
				while(ResFile.GetLine(cRead))//读取一行文件
				{            
					strLine = CString(cRead);
					if (strLine.Find(',') > 0)//分隔文件内容
					{
						strID = strLine.Left(strLine.Find(','));
						strString = strLine.Mid(strLine.Find(',')+1);
						mResStringList.SetAt(_wtoi(strID), strString);
					}
				}//读取资源文件内容
			}
			
			// 获取当前运行程序的目录
			char chfilepath[255]={0};
			int nsize = 0;
			nsize = GetModuleFileName(NULL, chfilepath, SIZEOF_ARRAY(chfilepath)-1);
			chfilepath[nsize]=0;
			
			StreamFormatter _fmtFile;
			IStreamFormatter fmtFile(&_fmtFile.getInnerObject());
			os_printf(fmtFile, "os_file:path=|%s\\res\\config.ini", chfilepath);//读取文件
			const char* pFile = fmtFile.getBuffer();//获取文件内容
			StreamContainer fileContain(pFile, 0);//定义一个container对象
			IInputStream isFile=fileContain.getInputStream();//获取输入流对象
		
			char chRead[128]={0};
			int nLineSize=0;
			while((nLineSize=is_get_line(chRead, SIZEOF_ARRAY(chRead), isFile, TEXT_EOL_STYLE_DOS)))
			{
				const char *p=chRead;
				char chReadPer[128]={0};
				int nWordSize = 0;
				nWordSize=next_word3(chReadPer, p, ',', 100);//按100字节字符获取分隔符
				if(nWordSize>0 && nWordSize<nLineSize)
				{
					return switchLanguage(_wtoi(CString(chReadPer)));
				}
				else
				{
					return switchLanguage(_wtoi(CString(chRead)));
				}
		
			}
		void CSouthToolsDlg::InitDialogLanguage()
			 CString strTemName;
			// 获取当前运行程序的目录
			GetModuleFileName(NULL,strTemName.GetBufferSetLength (MAX_PATH+1),MAX_PATH);
			strTemName.ReleaseBuffer ();
			strTemName=strTemName.Left(strTemName.ReverseFind ('\\'));
			CString strConfigFilePath;
			strConfigFilePath.Format(_T("%s\\config.dll"), strTemName);
			CSouthReadFile ResFile;
			if (ResFile.Open(strConfigFilePath))//读取文件
			{
				char cRead[MAX_READ_LINE];
				CString strLine;
				int resID, appID = 931;
				while(ResFile.GetLine(cRead))//读取一行数据
				{            
					strLine = CString(cRead);
					if (strLine.Find(',') > 0)
					{
						resID = _wtoi(strLine.Left(strLine.Find(',')));//获取左边的值
						if (resID >= 931 && resID <= 946)
						{
							if (ExistExecuteApp(strLine.Mid(strLine.Find(',')+1)))//获取右值
							{
								CString strTem = pLanguage->getString(resID, _T(""));
								strTem.Replace(_T("\\r\\n"), _T("\r\n"));
								GetDlgItem(appID)->SetWindowText(strTem);
								mExecuteAppList.Add(strLine.Mid(strLine.Find(',')+1));
								GetDlgItem(appID++)->ShowWindow(TRUE);
							}
						}
					}
				}//读取资源文件内容
			}
		//加载控制点数据
		BOOL CDataProcessDlg::LoadTransformParameter(CString strFileName)
			CSouthReadFile temReadFile;
			if (!temReadFile.Open(strFileName))
				return FALSE;
		class CCalcTransformParameterDlg : public CDialog
			void LoadControlPointPar(CString strFileName)
						CSouthReadFile temReadFile;
			if (!temReadFile.Open(strFileName))
				return;
	RoadDesignTool例子：
			属性：
				c/c++->general:Addi:..;"$(GNSS_DIR)/include"(原来：..)
				link->Input:Additional ：gnss03_curve_debug.lib
				link->general:Add:"$(GNSS_DIR)/win32lib" (原来：无)
				Build Events->Post-Build Event->Command:copy "$(OutDir)\$(TargetName).exe" "$(GNSS_DIR)\win32bin\" (原来：无)
				OutputFile="$(OutDir)\$(ProjectName)_debug.exe"
				Debugging->Command:$(GNSS_DIR)/win32bin/$(TargetFileName)
				把以下内容去掉：			
			// RoadDesignDlg.h :
				#include "include/gnss03_curve/RoadManage.h"
				改成：#include <gnss03_curve/RoadManage.h>
			//RoadDesignDlg.cpp:
				//获取交点：
				m_RoadManage.GetCurveNodeItem(i, item);改成：item = m_RoadManage.GetCurveNodeItem(i);
			
			//编译问题：
			.\GeneratedFiles\Debug\moc_ReusableDialogBase.cpp : warning C4819: The file contains a character that cannot be represented in the current code page (936). Save the file in Unicode format to prevent data loss
				什么环境问题呢？qt？
				
			修改：Common部分：
				GetStrDegreeFromDecimalDegree(dangle,nFormatFlag(0-度，1-度o分‘秒’‘，2-度：分：秒，3-度.分秒),ndigit=8 );
					format_angle(char* buf, buf_size, dangle, LatLongFormatEnum, dec);
				GetDecimalDegreeFromStrDegree（CString &strAngle, int nFormatFlag=0);
					parse_angle(char* val,LatLongFromatEnum flag(LL_DEC=0-度，LL_DMS-度o分‘秒’‘,LL_HMS-度：分：秒,LL_DOT-点度，LL-AZI-方位角，航向))
				toMulChar(CString , int nCodePage=CP_ACP);					
				toCString(char* value, int nCodePage=CP_ACP);
				
				//error C2664: 'void ATL::CStringT<BaseType,StringTraits>::Format(const wchar_t *,...)' : cannot convert parameter 1 from 'const char [3]' to 'const wchar_t *'
					mstrAzimuth.Format("%s", buf);//mstrAzimuth = CommonFunction::toCString(buf);
				原来调用：CommonFunction::GetStrDegreeFromDecimalDegree(mElementItem.azimuth, 1, 9);
				
				    //功能：将十进制度转换为度分秒形式字符串
					//输入：dangle——十进制度
					//		bShowFlag——显示度格式标志；0-度，1-度°分′秒″，2-度:分:秒， 3-度.分秒
					//输出：无
					//返回：度分秒形式字符串
					//日期：2013.05.09
					//////////////////////////////////////////////////////////////////////////
					CString GetStrDegreeFromDecimalDegree(double dangle, int nFormatFlag = 0, int nDigit = 8);
				
					//功能：将度分秒形式字符串转换为十进制度
					//输入：strAngle——相应格式的字符串
					//		nFormatFlag——显示度格式标志；0-度，1-度°分′秒″，2-度:分:秒， 3-度.分秒
					//返回：十进制度
					double GetDecimalDegreeFromStrDegree(const CString &strAngle, int nFormatFlag = 0);
					
					
					//功能：将十进制度转换为度分秒形式字符串
					//输入：dangle——十进制度
					//		bShowFlag——显示度格式标志；0-度，1-度°分′秒″，2-度:分:秒， 3-度.分秒
					//输出：无
					//返回：度分秒形式字符串
					//日期：2013.05.09
					//////////////////////////////////////////////////////////////////////////
					CString GetStrDegreeFromDecimalDegree(double dangle, int nFormatFlag = 0, int nDigit = 8)
					{
						//如果是负数，就应该加上负号 [6/26/2009 HuangKun]
						BOOL bNegative = FALSE;
						if (dangle < 0)
						{
							bNegative = TRUE;
						}
				
						if (nDigit < 4)
							nDigit = 8;
						
						CString strTem;
						CString strAngle = _T("0");
						switch (nFormatFlag)
						{
						case 0:
							{
								double du, fen;
								fen = modf(fabs(dangle), &du);     
				
								strTem.Format(_T("%d"), nDigit);
								strTem = _T("%03d%.") + strTem + _T("f");
				
								strAngle.Format(strTem,(int)du, fen);
								strAngle.Delete(3, 1);
							}
							break;
				
						case 1:
						case 2:
						case 3:
							{
								//转化为度分秒
								double du, fen, miao;
								fen = modf(fabs(dangle), &du);     
								fen = fen*60;
								miao = modf(fen, &fen);
								miao = miao*60;
				
								//秒调整——等于60处理
								if (fabs(miao-60.0)<1E-5)
								{
									miao = 0;
									fen++;
								}
								//分调整——等于60处理
								if (fabs(fen-60)<1E-5)
								{
									fen = 0;
									du++;
								}
				
								CString strmiao;
								strTem.Format(_T("%d"), nDigit-4);
								strTem = _T("%.") + strTem + _T("f");
				
								strmiao.Format(strTem, miao);
								if (strmiao.Find('.') == 1)
								{
									strmiao.Insert(0, '0');
								}
				
								if (3 == nFormatFlag)
								{
									strmiao.Remove('.');
									strAngle.Format(L"%03d.%02d%s", (int)(du), (int)(fen), strmiao);
								}
								else
								{
									CString strDegree, strMinute, strSecond;
									if (2 == nFormatFlag)
									{
										strDegree = strMinute = _T(":");
										strSecond = _T("");
									}
									else
									{
										strDegree = CString(IDS_GLOBAL_DEGREE);
										strMinute = CString(IDS_GLOBAL_MINUTE);
										strSecond = CString(IDS_GLOBAL_SECOND);
									}
				
									strAngle.Format(_T("%03d%s%02d%s%s%s"), (int)(du), strDegree, 
										(int)(fen), strMinute, strmiao, strSecond);
								}
							}
				
							break;
				
						default:
							strAngle.Format(_T("%03.8f"), fabs(dangle));
							break;
						}
				
						//如果是负数，就应该加上负号 
						if (bNegative)
						{
							strAngle.Insert(0, '-');
						}
				
						return strAngle;
					}
				
					//功能：将度分秒形式字符串转换为十进制度
					//输入：strAngle——相应格式的字符串
					//		nFormatFlag——显示度格式标志；0-度，1-度°分′秒″，2-度:分:秒， 3-度.分秒
					//返回：十进制度
					double GetDecimalDegreeFromStrDegree(const CString &strAngle, int nFormatFlag = 0)
					{
						double dAngle = 0;
						CString strTemAngle = strAngle;
				
						if (strTemAngle.GetLength() <= 0)
						{
							return dAngle;
						}
				
						BOOL bNegative = FALSE;
						if (strTemAngle.GetAt(0) == '-')
						{
							bNegative = TRUE;
							strTemAngle.Delete(0);
						}
				
						wchar_t *endptr;
						switch (nFormatFlag)
						{
						case 0:
							{
								dAngle = wcstod(strTemAngle, &endptr);
							}
							break;
				
						case 1:
							{
								//先转化成ddd:mm:ss.ssss格式
								strTemAngle.Replace(CString(IDS_GLOBAL_DEGREE), _T(":"));
								strTemAngle.Replace(CString(IDS_GLOBAL_MINUTE), _T(":"));
								strTemAngle.Replace(CString(IDS_GLOBAL_SECOND), _T(""));
							}
						case 2:
						case 3:
							{
								CString strTem;
								CString strDegree, strMinute, strSecond;
								//自动转换成度.分秒来转换
								if (nFormatFlag != 3 && strTemAngle.Find(':') <= 0)
								{
									nFormatFlag = 3;
								}
				
								if (3 == nFormatFlag)
								{
									if (strTemAngle.Find('.') < 0)
									{
										strTemAngle += _T(".");
									}
									strDegree = strTemAngle.Left(strTemAngle.Find('.'));
									strTem = strTemAngle.Right(strTemAngle.GetLength() - strTemAngle.Find('.') - 1);
									strMinute = strTem.Left(2);
									strSecond = strTem.Right(strTem.GetLength() - 2);
									if (strSecond.GetLength()>2)
									{
										strSecond.Insert(2, '.');
									}
								}
								else
								{
									if (strTemAngle.Find(':') < 0)
									{
										strTemAngle += _T(":");
									}
									strDegree = strTemAngle.Left(strTemAngle.Find(':'));
									strTem = strTemAngle.Right(strTemAngle.GetLength() - strTemAngle.Find(':') - 1);
									if (strTem.Find(':') < 0)
									{
										strTem += _T(":");
									}                    
									strMinute = strTem.Left(strTem.Find(':'));
									strSecond = strTem.Right(strTem.GetLength() - strTem.Find(':') - 1);
								}
				
								//调整角度大小
								int nMinute = _wtol(strMinute);
								double dSecond = wcstod(strSecond, &endptr);
								while (nMinute < 0)
								{
									nMinute += 60;
								}
								while (nMinute >= 60)
								{
									nMinute -= 60;
								}
								while (dSecond < 0.0)
								{
									dSecond += 60.0;
								}
								while (dSecond >= 60.0)
								{
									dSecond -= 60.0;
								}
				
								dAngle = _wtol(strDegree) + nMinute/60.0 + dSecond/3600.0;
							}
							break;
				
						default:
							{
								dAngle = wcstod(strTemAngle, &endptr);
							}
							break;
						}
				
						//如果是负数，就应该加上负号 
						if (bNegative)
						{
							dAngle = -dAngle;
						}
				
						return dAngle;
					}
				1010.2.13:	
				//CString到char* 的类型转换,与下一个函数结合可支持中文；	
				toMulChar(CString, int nCodePage=CP_ACP)
					//WideCharToMultiByte//数映射一个unicode字符串到一个多字节字符串
					
					**
					* 取当前运行环境的文字编码字符串
					*
					* @param buf 输出缓冲区
					* @param bufSize 输出缓冲区的大小
					* @return 若成功，为buf的起始地址；若失败，为0
					*
					* @remarks
					* (1) 要求50<=bufSize;
					* (2) 编码字符串举例："UTF-8", "CP936";
					* (3) 返回值按LIBICONV要求调整好格式，比如"936"调整成"CP936"
					*
					wcs_to_mbs(char* buf, int buf_size, const wchar_t *wcs);
					
				//char* 到CString的转换
				toCString(char*, int nCodePage)
					//MultiByteToWideChar//多字节转宽字符unicode
					
					mbs_to_wcs(wchar_t * buf, int buf_size, const char *mbs);
					
					
					    //增加CString到char *的类型转换,与下一个函数结合可支持中文 [9/14/2010 yongchang]
						// 修改 [11/23/2010 liyongchang]
						char* toMulChar(const CString value, int nCodePage = CP_ACP)
						{
							int len;
							char *chbuf;
					
							//把Unicode转换成GB2312  如果是UTF-8转换成Unicode则使用CP_UTF8
							len = WideCharToMultiByte(nCodePage, 0, value, -1, NULL, 0, NULL, NULL);
							if (len<1)
							{
								return NULL;
							}
							chbuf = new char[len+1];
							if (!chbuf)
							{
								return NULL;
							}
							if (WideCharToMultiByte (nCodePage, 0, value, -1, chbuf, len, NULL, NULL) < 1)
							{
								delete chbuf;
								return NULL;
							}
							return chbuf;
						}
					
						//增加char *到CString的类型转换 [9/14/2010 yongchang]
						CString toCString(const char* value, int nCodePage = CP_ACP)
						{
							int len;
							CString strbuf;
							wchar_t *wchbuf = NULL;
							//把GB2312转换成Unicode  //如果是UTF-8转换成Unicode则使用CP_UTF8
							len = MultiByteToWideChar(nCodePage, 0, value, -1, NULL, 0);
							if (len <1)
							{
								return L"";
							}
							wchbuf = new wchar_t[len+1];
							if (!wchbuf)
							{
								return L"";
							}
							if (MultiByteToWideChar(nCodePage, 0, value, -1, wchbuf, len) < 1)
							{
								delete wchbuf;
								wchbuf = NULL;
								return L"";
							}
							strbuf = wchbuf;
							delete wchbuf;
							wchbuf = NULL;
							return strbuf;
						}//strTem = CommonFunction::toCString(nodeData.name);
					加头文件
						#include <gnss00_utilities/rism_utils.h>//SIEZE_ARRAY
						#include <gnss00_utilities/TextConverter.h>//wcs_to_mbs

				    //功能：将度分秒形式字符串转换为十进制度
					//输入：strAngle——相应格式的字符串
					//		nFormatFlag——显示度格式标志；0-度，1-度°分′秒″，2-度:分:秒， 3-度.分秒
					//返回：十进制度
					double GetDecimalDegreeFromStrDegree(const CString &strAngle, int nFormatFlag = 0)
					{
						double dAngle = 0;
						CString strTemAngle = strAngle;
						if (strTemAngle.GetLength() <= 0)
						{
							return dAngle;
						}
						
						LatLongFormatEnum e_Format;
						switch(nFormatFlag)
						{
						case 0:
							e_Format=LL_DEC;
							break;
						case 1:
							e_Format=LL_DMS;
							break;
						case 2:
							e_Format=LL_HMS;
							break;
						case 3:
							e_Format=LL_DOT;
							break;
						case 4:
							e_Format=LL_AZI;
							break;
						default:
							e_Format=LL_DEC;
							break;
						}
						char chAngle[100]={0};
						wcs_to_mbs(chAngle, SIZEOF_ARRAY(chAngle), strTemAngle.GetBuffer());
						strTemAngle.ReleaseBuffer();
						CString strAng(chAngle);
						if(strAng.GetLength()==0)
						{
							return 0.0;
						}
						dAngle = parse_angle(chAngle, e_Format);
				
						return dAngle;
					}
					
					//功能：将十进制度转换为度分秒形式字符串
					//输入：dangle——十进制度
					//		bShowFlag——显示度格式标志；0-度，1-度°分′秒″，2-度:分:秒， 3-度.分秒
					//输出：无
					//返回：度分秒形式字符串
					//日期：2013.05.09
					//////////////////////////////////////////////////////////////////////////
					CString GetStrDegreeFromDecimalDegree(double dangle, int nFormatFlag = 0, int nDigit = 8)
					{
						if (nDigit < 4)
							nDigit = 8;
						CString strAngle = _T("0");
				
						char buf[100]={0};
						LatLongFormatEnum e_Format;
						switch(nFormatFlag)
						{
						case 0:
							e_Format=LL_DEC;
							break;
						case 1:
							e_Format=LL_DMS;
							break;
						case 2:
							e_Format=LL_HMS;
							break;
						case 3:
							e_Format=LL_DOT;
							break;
						case 4:
							e_Format=LL_AZI;
							break;
						default:
							e_Format=LL_DEC;
							break;
						}
						format_angle(buf, sizeof(buf), dangle, e_Format, nDigit);
						strAngle = CString(buf);
				
						return strAngle;
					}					
			
		DataProcessTool：
			General->OutputDirectory:$(SolutionDir)$(ConfigurationName) （原来：$(SolutionDir)$(PlatformName)_$(ConfigurationName)）
			General->IntermediateDirectory： $(ConfigurationName)(原来：$(OutDir)\$(ProjectName)\)
			AdditionalIncludeDirectories=".." （原来：$(GNSS_DIR)/include）
			link：AdditionalDependencies="../lib/Win32/gnss02_transform_debug.lib ../lib/Win32/gnss02_gis_dic_debug.lib ../lib/Win32/gnss03_svg_debug.lib ../lib/Win32/gnss03_curve_debug.lib"
				原来：AdditionalDependencies="gnss02_transform_debug.lib gnss02_gis_dic_debug.lib gnss03_svg_debug.lib gnss03_curve_debug.lib"
					原来：AdditionalLibraryDirectories="$(GNSS_DIR)/win32lib" （去掉）
			
			修改：
				c/c++->Additional:..;"$(GNSS_DIR)/include"(原来：..)
				link->Input->Additional :(原来：都添加：../lib/Win32/)
				link->general:Add:"$(GNSS_DIR)/win32lib" (原来：无)


		更改的代码：除了main.cpp,feature_class_test_routines.cpp,feature_class_test_routines.hpp
		没有改其余都注释掉了前面的添加；
				wgis_test：FeatureClass_Test.cpp：
				CPPUNIT_TEST( read_attribute_table_end );
					void read_attribute_table_end()
					{
						//undo_redo_pgns_test04_shp
						//////////////////////////////////////////////////////////////////////////
						//TestFunction tm(__FUNCTION__);
				
						//char fn[255];
						//get_sample_data(fn, "shp/tdly441323/dltb.shp");//sample_polygon_shp/dltb220724select01.shp
						//
						//const char *tbn = "dltb";
				
						//WorkspaceW _ws(fn);
						//IBasicWorkspace &ws(dynamic_cast<IBasicWorkspace&>(_ws.getInnerObject()));
						//BasicTableW _fc(ws.openTable(tbn, "rw"));
						//IRevisionTable &fc = dynamic_cast<IRevisionTable&>(_fc.getInnerObject());
						//fc.rollbackTransaction();
						//SpatialQuery sq2(&fc, 0.001);
						//ISpatialQuery *sq = &sq2.getInnerObject();
						//PLineW _pl;
						//IPLine &pl(_pl.getInnerObject());
						//GisPolygonW _pgn;
						//IGisPolygon &pgn(_pgn.getInnerObject());
						//GeometryData gd;
						//gd.geom = &pgn;		
				
						//FieldBindingsW _bindings(fc.getAttStruct());
						//IFieldBindings &bindings(_bindings.getInnerObject());
				
						//bindings.setFieldBuffer(&gd, sizeof(gd), "$geom");
				
						//pgn.beginBuild();
						//{
						//	pl.clear();
						//	pl.vertexAdd(Point2d(42422549.165,5017855.078));
						//	pl.vertexAdd(Point2d(42422131.956,5018235.474));
						//	pl.vertexAdd(Point2d(42422263.868,5018410.334));
						//	pgn.appendLoop(pl);
						//}
						//pgn.commitBuild();
						//fc.addRecord(bindings);
				
						//pgn.beginBuild();
						//{
						//	pl.clear();
						//	pl.vertexAdd(Point2d(42422816.055,5016842.735));
						//	pl.vertexAdd(Point2d(42422291.477,5016925.563));
						//	pl.vertexAdd(Point2d(42422380.441,5017253.808));
						//	pgn.appendLoop(pl);
						//}
						//pgn.commitBuild();
						//fc.addRecord(bindings);
				
						//fc.undo();
						//fc.redo();
						//fc.undo();
				
						//pgn.beginBuild();
						//{
						//	pl.clear();
						//	pl.vertexAdd(Point2d(42425168.988,5017253.808));
						//	pl.vertexAdd(Point2d(42424803.930,5017462.412));
						//	pl.vertexAdd(Point2d(42425055.482,5017652.610));
						//	pgn.appendLoop(pl);
						//}
						//pgn.commitBuild();
						//fc.addRecord(bindings);
				
						//fc.undo();
						//fc.redo();
				
						//fc.rollbackTransaction();
				
				
						
						//read_attribute_table
						//////////////////////////////////////////////////////////////////////////
						TestFunction tm(__FUNCTION__);
						char fn[1000];
						get_sample_data(fn, "shp/tdly441323/dltb.shp");
						CPPUNIT_ASSERT_MESSAGE(fn, file_system_check_file(fn));
				
						FileGroupW _grp(fn);
						IFileGroup &grp(_grp.getInnerObject());
				
						WorkspaceW _wsShp(fn);
						IBasicWorkspace &wsShp(_wsShp.getInnerObject());
						BasicTableW _fcshp(wsShp.openTable(grp.getBase(), "rw"));
						IRevisionTable &fcshp = dynamic_cast<IRevisionTable&>(_fcshp.getInnerObject());
				
						//WorkspaceW _ws(grp.compositeFileName(".sqlite"));
						//IBasicWorkspace &ws(_ws.getInnerObject());
						//BasicTableW _att(ws.openTable("xiangxiang_select","rw"));
						//IRevisionTable &fcSqlite = dynamic_cast<IRevisionTable&>(att.getInnerObject());
				
						fcshp.rollbackTransaction();
				
						////CPPUNIT_ASSERT_NO_THROW(read_attribute_table1(fcshp));
						const int N_RECORDS = fcshp.getNumRecords();
						for (int k=0; k<10; ++k)
						{
							IRevisionTable &att = fcshp;
							const IAttStruct *stru = att.getAttStruct();
							const int N_FLDS = stru->getNumFields();
				
							FieldBuffers fb(&fcshp);
							IFieldBindings &bindings = fb.getBindings();	
				
							att.getRecord(0, bindings);
				
							{
								for (int i=0; i<N_RECORDS; ++i)
								{
									att.getRecord(i, bindings);
								}
							}
						}
					}

	b、getLine的对比：IOStream.h和NormalFile，FileStream.h
			*要能够统一使用rb和r的文件打开格式；（区别：r:把\r\n读成\r\n;rb:把\r\n读成\n）；
				NormalFile.cpp：//不保存\n
					如果是结尾则返回0；
					*循环所有字符：
						getByte读取字符；
						如果是-1置0返回；
						如果是\n或者\r：
							置0，跳过这两个字符，获取最后一个字符，返回；
					保存字符；
				FileStream.cpp：//保存\r\n,但最后一个\n不保存；
					判空；
					如果是rb格式
						循环读取字节：getByte()
							如果读到末尾，置0返回；
							保存；
							如果恒等于\n或末尾
								如果倒数第二个，置0；
								否则+1置0；
								返回
							++；
						置0；
					
					fgets直接读取（不加也不丢\n）
				StreamFormatter.h://保存\r\n
					获取剩余字节数；
					要读取的字节数边界设定；
					循环读取：
						如果字符是\n（不是直接保存）；
							i+1置0；返回；
					如果长度小于当前位置，置0返回；
					//多余？
				ZipFileReader.cpp://只有连续的\r\n中断读取丢弃\r\n，如果单个\n则会继续读取；
					循环读取：
						如果字符是\n：
							如果i>1，前一个是\r，则i-1置0；跳出读取；
						否则
							保存字符；
			*能把所有不同-细微不同的getLine合并成一个全局函数；
				//读取文件到buf中，buf的大小为buf_size；
				int is_get_line(char *buf, size_t buf_size, IInputStream &is)
				{
					if (is.eof())
					{
						return 0;
					}
					for (size_t i=0; i<buf_size; ++i)
					{
						int ch = is.getByte();
						if (-1==ch)
						{
							buf[i] = 0;
							return i-1;
						}
				
						if ('\n'==ch)
						{
							if( (i+1)>=buf_size )
							{
								buf[i]=0;
								return i-1;
							}
							else
							{
								buf[i] = '\n';
								buf[i+1] = 0;
								return i;
							}
						}
						else if('\r'==ch)
						{
							ch = is.getByte();
							if('\n' == ch)
							{
								if( (i+1)>=buf_size )
								{
									buf[i]=0;
									return i-1;
								}
								else
								{
									buf[i] = '\n';
									buf[i+1] = 0;
									return i;
								}								
							}
							else
							{
								is.fseek(-1, SEEK_CUR);
								if( (i+1)>=buf_size )
								{
									buf[i]=0;
									return i-1;
								}
								else
								{
									buf[i] = '\n';
									buf[i+1] = 0;
									return i;
								}
							}
						}
						
						buf[i] = ch;
					}
					return 0;
				}
				
				//优化：
				int is_get_line(char *buf, size_t buf_size, IInputStream &is)
				{
					if (is.eof())
					{
						return 0;
					}
					for (size_t i=0; i<buf_size; ++i)
					{
						int ch = is.getByte();
						if (-1==ch)
						{
							buf[i] = 0;
							return i-1;
						}			

						if( '\r'==ch || '\n'==ch )
						{
							if('\r'==ch)//如果是等于\r
							{
								ch = is.getByte();
								if( !('\n' == ch) )//如果后面的是\n，则退一格；
								{
									is.fseek(-1, SEEK_CUR);
								}
							}
							
							if( (i+1)>=buf_size )
							{
								buf[i]=0;
								return i-1;
							}
							else
							{
								buf[i] = '\n';
								buf[i+1] = 0;
								return i;
							}
						}
						
						buf[i] = ch;
					}
					return 0;
				}
				//再次优化
				int is_get_line(char *buf, size_t buf_size, IInputStream &is)
				{
					//如果小于2的话，即使是1也放不了一个0；不对，应该可以读取一个字符；
					if (is.eof() || buf_size<1)
					{
						return 0;
					}
					for (size_t i=0; i<buf_size; ++i)
					{
						int ch = is.getByte();//获取字符
						if (-1==ch)//如果是文件结尾
						{
							buf[i] = 0;
							return i-1;
						}
						//如果遇到\r\n分几种情况：
						a、\r的时候
							后面跟\n和不跟；
						b、\n的时候
						if ('\n'==ch || '\r'==ch)
						{		
							//while(ch=='\r' || ch=='\n')//后面不管跟多少\r\n都应该忽略
							//{
							//	ch = is.getByte();
							//}
							//int npoint = 0;
							if(ch=='\r')
							{
								ch = is.getByte();
							}
							//while(ch=='\r' || ch=='\n')
							//{
							//	npoint = is.ftell();
							//	ch = is.getByte();				
							//}
							//if(!is.eof())
							//{
							//	int nRet = -1;
							//	nRet = is.fseek(npoint,SEEK_SET);
							//}
				
							if(i==0)
							{
								buf[i]='\n';
								return i+1;
							}
				
							if( (i+1)>=buf_size )//不可以放\n
							{
								buf[i]=0;
								is.fseek(-1,SEEK_CUR);
								return i;
							}
							else//可以放\n
							{
								buf[i]='\n';
								buf[i+1]=0;
								return i+1;
							}
						}
						buf[i] = ch;
					}
					is.fseek(-1,SEEK_CUR);
					buf[buf_size-1]=0;
					return buf_size-1;
				}
				
				//最终版本
				int is_get_line(char *buf, size_t buf_size, IInputStream &is)
				{
					if (is.eof() || buf_size<1)
					{
						return 0;
					}
				
					for (size_t i=0; i<buf_size; i++)
					{
						int ch = is.getByte();
						if (-1==ch)
						{
							buf[i] = 0;
							return i-1;
						}
				
						if ('\n'==ch || '\r'==ch)
						{
							//while(ch=='\r' || ch=='\n')
							//{
							//	ch = is.getByte();
							//}
							//if(!is.eof())
							//{
							//	is.fseek(-1,SEEK_CUR);
							//}
							if(ch=='\r')
							{
								ch = is.getByte();
							}
				
							if(i==0)
							{
								buf[i]='\n';
								return i+1;
							}
				
							if( (i+1)>=buf_size )
							{
								buf[i]=0;
								is.fseek(-1,SEEK_CUR);
								return i;
							}
							else
							{
								buf[i]='\n';
								buf[i+1]=0;
								return i+1;
							}
						}
						buf[i] = ch;
					}
				
					if(buf_size==1)
					{
						return 1;
					}
					is.fseek(-1,SEEK_CUR);
					buf[buf_size-1]=0;
					return buf_size-1;
				}
				
				//测试代码：
				void c_normalfile_is_get_line_test()
				{			
					char path[1000] = {0};
					get_sample_data(path, "gnss00_utilities/isgetlinetest.ini");//把字符串放到buf中；
					CPPUNIT_ASSERT_MESSAGE(path,file_system_check_file(path));
					
					//1、StreamFormatter 2、IStreamFormatter 3、os_printf 打开文件保存到IStrFor中；4、获取内容；
					StreamFormatter _fmt1;
					IStreamFormatter &fmt1(_fmt1.getInnerObject());
					os_printf(fmt1, "os_file:path=%s", path);
					const char * content = fmt1.getBuffer();
			
					StreamContainer c1(content, 0);
					IInputStream &is1 = c1.getInputStream();
			
					char buf1[5] = {0};
					char buf2[5] = {0};
					char buf3[7] = {0};
					char buf5[100] = {0};
			
					int nRet = 0;
					while(!is1.eof())
					{
						nRet = is_get_line(buf5, sizeof(buf5), is1);
						CPPUNIT_ASSERT_EQUAL(1,nRet);
						nRet=is_get_line(buf1, sizeof(buf1), is1);
						CPPUNIT_ASSERT_EQUAL(4, nRet);
						nRet = is_get_line(buf2, sizeof(buf2), is1);
						CPPUNIT_ASSERT_EQUAL(1, nRet);
						nRet = is_get_line(buf3, sizeof(buf3), is1);
						CPPUNIT_ASSERT_EQUAL(6, nRet);
					}
			
					AUTO_TEST_ASSERT_STR_EQUAL("\n", buf5);
					AUTO_TEST_ASSERT_STR_EQUAL("abcd", buf1);
					AUTO_TEST_ASSERT_STR_EQUAL("\n", buf2);
					AUTO_TEST_ASSERT_STR_EQUAL("abcde\n", buf3);
			
			
					nRet = is1.fseek(0,SEEK_SET);
					char buf4[1]={0};
					while(!is1.eof())
					{
						nRet = is_get_line(buf4, sizeof(buf4), is1);
						CPPUNIT_ASSERT_EQUAL(1,nRet);
					}
					
					char wsp2[255] = {0};
					get_sample_data(wsp2, "gnss00_utilities/etc.zip");
					StreamFormatter _fmt3;
					IStreamFormatter &fmt3(_fmt3.getInnerObject());
					os_printf(fmt3, "zip_file:path=%s,subPath=etc/isgetlinetest.ini", wsp2);
					const char *csa2 = fmt3.getBuffer();
			
					StreamContainer c2(csa2, 0);
					IInputStream &is2 = c2.getInputStream();
					char buf6[1000]={0};
					char buf7[1000]={0};
					char buf8[1000]={0};
					while(!is2.eof())
					{
						is_get_line(buf6, sizeof(buf6), is2);
						is_get_line(buf7, sizeof(buf7), is2);
						is_get_line(buf8, sizeof(buf8), is2);
					}
					AUTO_TEST_ASSERT_STR_EQUAL("\n", buf6);
					AUTO_TEST_ASSERT_STR_EQUAL("abcd\n", buf7);
					AUTO_TEST_ASSERT_STR_EQUAL("abcde\n", buf8);
			
				}
	//练习常用的属性读取数据：			
			get_sample_data();//WGIS_TEST_DATA_DIR环境变量取值
			read_attribute_table1()
			{
				TestFunction tm(__FUNCTION__);
				char fn[1000];
				get_sample_data(fn, "southgnss_test_data/shp/tdly441323/dltb.shp");
				CPPUNIT_ASSERT_MESSAGE(fn, file_system_check_file(fn));
				
				FileGroupW _grp(fn);
				IFileGroup &grp(_grp.getInnerObject());
				
				WorkspaceW _wsShp(fn);
				IBasicWorkspace &wsShp(_wsShp.getInnerObject());
				BasicTableW _fcshp(wsShp.openTable(grp.getBase(), "rw"));
				IRevisionTable &fcshp = dynamic_cast<IRevisionTable&>(_fcshp.getInnerObject());
				
				//WorkspaceW _ws(grp.compositeFileName(".sqlite"));
				//IBasicWorkspace &ws(_ws.getInnerObject());
				//BasicTableW _att(ws.openTable("xiangxiang_select","rw"));
				//IRevisionTable &fcSqlite = dynamic_cast<IRevisionTable&>(att.getInnerObject());
				
				fchshp.rollbackTransaction();
				
				CPPUNIT_ASSERT_NO_THROW(read_attribute_table(fcshp));
			}
	
			pthreadVC2.lib//之前添加了sqlite3.lib
			
			
			0x002fe874 "!missing [e:/gnss/southgnss/etc/coordinate_systems/ellipsoids.csv]"
				E:\gnss\southgnss_sdk\etc\coordinate_systems
				//解决问题：重新拷贝一份文件夹到那个目标文件夹；

	新版的geom_to_pnt_dist函数的改进点：
			a、线的阈值判断；
			b、pline_point_distance和pline_snap_near的区别：
				前者是点到曲线的最短距离（绝对值），后者是返回折线上与指定点最近的点位；
			c、把与最外层环的距离脱离循环，减少循环次数；
			double geom_to_pnt_dist(const void *geom, int gt, const Point2d &pnt, double TOL)
			{
				double dist = TOL;
				switch (gt)
				{
				case FEATURE_TYPE_POINT:
					{
						const Point2d &pnt1 = *(const Point2d*)geom;
						dist = vec_length(pnt1 - pnt);
					}
					break;
				case FEATURE_TYPE_PLINE:
					{
						const IPLine &pl = *(const IPLine*)geom;
			
						// 判断该点是否与多边形最小矩形的距离大于阈值
						if (0<TOL)
						{
							GisRect bnd = pl.getBND();
							bnd.expand(TOL);
							if (!bnd.contains(pnt))
							{
								return dist;
							}
						}
			
						pline_point_distance(pl, pnt, dist);
						return fabs(dist);
					}
					break;
				case FEATURE_TYPE_POLYGON:
					{
						const IGisPolygon &pgn = *(const IGisPolygon*)geom;
			
						// 判断该点是否与多边形最小矩形的距离大于阈值
						if (0<TOL)
						{
							GisRect bnd = pgn.getBND();
							bnd.expand(TOL);
							if (!bnd.contains(pnt))
							{
								return dist;
							}
						}
						
						Point2d pnt1;
						PLineW _pl;
						IPLine &pl(_pl.getInnerObject());
						const int N = pgn.getNLoops();
			
						pgn.getLoop(0, pl);
						pline_point_distance(pl, pnt, dist);
						if (0<=dist)
						{
							// 点在外边界左边，即在多边形外部：就是这个距离了
							return dist;
						}
			
						// 点在外边界右边：检查是否落在岛区内
						for (int i=1; i<N; ++i)
						{
							pgn.getLoop(i,pl);
							pline_point_distance(pl, pnt, dist);
							if (0<=dist)
							{
								// 点在内边界左边，即在岛区内：就是这个距离了
								return dist;
							}
						}
			
						// 内部或者边界
						return 0.0;
					}
					break;
				}
				return dist;
			}

	[ticket:474]将成果转移到gnss01_kernel模块
		//原来的样子：
		geom_tools_tests.cpp
			#include <gnss00_utilities/gnss00_utilities.h>
			#include <gnss01_test_utils/test_utils.h>
			#include <wgis.h>
			
					PLineW _pl;
					IPLine &pl(_pl.getInnerObject());
					pl.vertexAdd(Point2d(1,9));
					pl.vertexAdd(Point2d(9,9));
					pl.vertexAdd(Point2d(9,1));
					pl.vertexAdd(Point2d(1,1));	
			
					PLineW _pl2;
					IPLine &pl2(_pl2.getInnerObject());
					pl2.vertexAdd(Point2d(2,6));
					pl2.vertexAdd(Point2d(2,3));
					pl2.vertexAdd(Point2d(4,3));				
					pl2.vertexAdd(Point2d(4,6));		
			
					PLineW _pl3;
					IPLine &pl3(_pl3.getInnerObject());
					pl3.vertexAdd(Point2d(7,6));
					pl3.vertexAdd(Point2d(7,3));
					pl3.vertexAdd(Point2d(8,3));
					pl3.vertexAdd(Point2d(8,6));
			
					GisPolygonW _pgn;
					IGisPolygon &pgn(_pgn.getInnerObject());
					pgn.beginBuild();
					pgn.appendLoop(pl);
					pgn.appendLoop(pl3);
					pgn.appendLoop(pl2);
					pgn.commitBuild();
		gnss01_kernel的utilities：
			就是没有两个文件；
		//更改之后：
		geom_tools_tests.cpp
			#include <gnss00_utilities/gnss00_utilities.h>
			#include <gnss01_test_utils/test_utils.h>
			#include <gnss01_kernel/gnss01_kernel.h>//增加
			#include <wgis01_kernel/wgis_kernel.h>//增加
			
			static int parse_pgn(IGisPolygon &pgn, const char *s_pgn)
			{
				PLineW _pl;
				IPLine &pl(_pl.getInnerObject());
				
				char buf[1000],word[1000];
				cosnt char *p = s_pgn;
				Point2d pnt;
				while(*p)
				{
					pl.clear();
					p += arrary_next_word3(buf, p, ';');
					const char *q = buf;
					while(*q)
					{
						q+= arrary_next_word3(word, q, ',');
						pnt.x= atof(word);
						q += array_next_word3(word, q, ',');
						pnt.y = atof(word);
						pl.vertexAdd(pnt);
					}
					pl.refresh();
					pgn.appendLoop(pl);
				}
				
				pgn.commitBuild();
				refresh 0;
			}

process_utils.cpp
//未完成：12'-14Line;
//（要获取路径的buf，buf大小， 是否可以打印日志， 格式字符串，va_list可变参数列表变量）
	int process_resolve_path_in_v(char *buf, const size_t buf_size, int isLogEnabled, const char *fmt, va_list args)
	{
		const char *context = __FUNCTION__;//获取函数名
	
		if (!buf)//如果指针为空
		{
			if (isLogEnabled)
			{
				wlog("!<ERROR ctx='%s(%s)'> buf(%p)==NULL </ERROR>"
					, context, fmt, buf, buf_size);//log内容：函数名，格式字符串，buf地址，
			}
			return -11;
		}
	
		if (buf_size<100)//如果buf大小小于100；
		{
			if (isLogEnabled)
			{
				wlog("!<ERROR ctx='%s(%s)'> buf_size(%d)<100 </ERROR>"
					, context, fmt, buf_size);//小于100也要打印？？？
			}
			return -11;
		}
	
		int step = 0;
		try
		{
			StreamFormatter _os;
			IStreamFormatter &os(_os.getInnerObject());//创建字符串buf；
			os_vprintf(os, fmt, args);//按格式化把所有可变参数列表组装成字符串；
			const char *path_with_var = os.getBuffer();//获取字符串
			if (isLogEnabled)
			{
				wlog("!%s(%s)", context, path_with_var);
			}
			const char *s = path_with_var;//另起变量保存字符串；（为什么？）
			char *t = buf;//另起变量保存buf首地址；
			size_t bufSize = buf_size;
			while (*t = *s)
			{
				++step;
				int len1 = 1, len2 = 1;
				//解析字符串；
				if ('$'==s[0] && '('==s[1])
				{
					char var_name[1000];
					len1 = 2;
					len1 += next_word3(var_name, s+len1, ')', sizeof(var_name));
					int ret = -1;
					if (const char *s = process_read_environment_in(var_name, 0, isLogEnabled))
					{
						csz_strncpy(t, s, bufSize);
						ret = 0;
					}
					if (0!=ret)
					{
						// @return {-1:环境变量未定义,-2:缓冲区尺寸不够}
						return ret;
					}
					len2 = (int)strlen(t);
				}
				s += len1;
				if (bufSize==len2)
				{
					t[bufSize-1] = 0;
					if (isLogEnabled)
					{
						wlog("!<ERROR ctx='%s(%s)'> buf_size(%d) toooo short! </ERROR>"
							, context, fmt, buf_size);
					}
					return -2;
				}
				bufSize -= len2;
				t += len2;
			}
	
			++step;
			// 没有引用环境变量，直接拷贝
			file_system_path_standardization_in(buf, buf_size, buf, isLogEnabled);
			if (isLogEnabled)
			{
				wlog("!%s:%s", context, buf);
			}
		}
		catch (std::exception &e)
		{
			if (isLogEnabled)
			{
				wlog("!<ERROR ctx='%s(%s)' step='%d'>%s</ERROR>"
					, context, fmt, step, e.what());
			}
			return -12;
		}
		catch (...)
		{
			if (isLogEnabled)
			{
				wlog("!<ERROR ctx='%s(%s)' step='%d'>%s</ERROR>"
					, context, fmt, step, "unknown exception");
			}
			return -13;
		}
	
		return 0;
	}
	
	int process_resolve_path(char *buf, const size_t buf_size, const char *fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		//  遍历文件夹时，打log会很卡。
		int res = process_resolve_path_in_v(buf, buf_size, 0, fmt, args);
		va_end(args);
		return res;
	}

//交会计算
	cogo_is_valid_line
		直接判断两点间的距离；
	cogo_is_line_sparallel

	bool cogo_calc_intersect_point(const tagCalcIntersectPoint data, double *north, double *east, int &flag)
	{
	
		double x1, y1, x2, y2, x3, y3, x4, y4;
		x1 = data.ptA.dbN;
		y1 = data.ptA.dbE;
		x2 = data.ptB.dbN;
		y2 = data.ptB.dbE;
		x3 = data.ptC.dbN;
		y3 = data.ptC.dbE;
		x4 = data.ptD.dbN;
		y4 = data.ptD.dbE;
	
		// 先检查两线段是否有交点
		if(   !cogo_is_valid_line(x1, y1, x2, y2) || !cogo_is_valid_line(x3, y3, x4, y4) 
			|| cogo_is_line_sparallel(x1, y1, x2, y2, x3, y3, x4, y4))
		{
			flag = 0;                           //两线段平行
			if(    !cogo_is_valid_line(x1,y1,x3,y3) || !cogo_is_valid_line(x1,y1,x4,y4)
				|| !cogo_is_valid_line(x2,y2,x3,y3) || !cogo_is_valid_line(x2,y2,x3,y3)
				|| cogo_is_line_sparallel(x1, y1, x3, y3, x1, y1, x4, y4) )
			{
				flag = 1;                       //两线段在同一条直线
			}	
	
			return false;                       // 两线段没有交点
		}
	
		if(fabs(x1-x2) < EPSILON_6)
		{
			// L1为垂直线段，平行Y轴
			*north = x1;
			*east = (y4-y3)*x1/(x4-x3) + (y3*x4-x3*y4)/(x4-x3);
		}
		else if(fabs(x3-x4) < EPSILON_6)
		{
			// L2为垂直线段，平行Y轴
			*north = x3;
			*east = (y2-y1)*x3/(x2-x1) + (y1*x2-x1*y2)/(x2-x1);
		}
		else
		{
			// 利用斜截式求解
			const double k1 = (y2-y1)/(x2-x1);
			const double k2 = (y4-y3)/(x4-x3);
			const double b1 = (y1*x2-x1*y2)/(x2-x1);
			const double b2 = (y3*x4-x3*y4)/(x4-x3);
			*north = (b2-b1)/(k1-k2);
			*east = k1 * *north + b1;
		}
		// 判断交点是否与延长线相关
		double dL1  = calc_distance_2d(x1,y1,x2,y2);
		double dL1A = calc_distance_2d(x1,y1,*north,*east);
		double dL1B = calc_distance_2d(x2,y2,*north,*east);
	
		double dL2  = calc_distance_2d(x3,y3,x4,y4);
		double dL2A = calc_distance_2d(x3,y3,*north,*east);
		double dL2B = calc_distance_2d(x4,y4,*north,*east);
	
		flag = 0;
		if(fabs(dL1 - dL1A - dL1B) < 1E-10)        
			flag += 2*10;                          //交点在L1的线段中
		else if(dL1A > dL1B)                   
			flag += 3*10;                          //交点在L1的前延长线中
		else
			flag += 1*10;                          //交点在L1的后延长线中
	
		if(fabs(dL2 - dL2A - dL2B) < 1E-10)       
			flag += 2*1;                          //交点在L2的线段中
		else if(dL2A > dL2B)                   
			flag += 3*1;                          //交点在L2的前延长线中
		else
			flag += 1*1;                          //交点在L2的后延长线中
			
		return true;
	}

//夹角计算
	int cogo_calc_intersect_angle(const tagCalcIntersectAngle data,double *angA, double *angB, double *angC)
	{
		double northB = data.ptB.dbN;
		double eastB = data.ptB.dbE;
		double elevB = data.ptB.dbH;
	
		double northC = data.ptC.dbN;
		double eastC = data.ptC.dbE;
		double elevC = data.ptC.dbH;
	
		double northA = data.ptA.dbN;
		double eastA = data.ptA.dbE;
		double elevA = data.ptA.dbH;
	
		double a = sqrt(pow((northB-northC),2) + pow((eastB-eastC),2));//获取BC点的距离
		double b = sqrt(pow((northC-northA),2) + pow((eastC-eastA),2));//获取AC点的距离
		double c = sqrt(pow((northB-northA),2) + pow((eastB-eastA),2));//获取AB点的距离
	
		//1.判断点是否合格 
		//1a.三条边的长度都不能为零
		if (a<EPSILON_6 || b<EPSILON_6 || c<EPSILON_6)
		{
			return ERROR_SIDE_ZERO;
		}
	
		bool bCalcHor = data.bHorizontal;
		if ( !bCalcHor )//如果计算垂直角,判断偏距是否在指定范围内
		{
			//计算垂直角为什么用平面上的点的距离来求偏距呢？//面积*2/边c；
			double p = (a+b+c)/2.0;
			double s = sqrt(p*(p-a)*(p-b)*(p-c));
			double distTemp = s*2.0/c;				//计算偏离距
	
			if (distTemp < data.offsetDist)
			{
				return ERROR_OFFSET_OUT_OF_LIMIT;
			}
	
			//不超限,计算空间距,垂直角使用空间距计算
			a = sqrt(pow((northB-northC),2) + pow((eastB-eastC),2) + pow((elevB-elevC),2));//空间点BC距离；
			b = sqrt(pow((northC-northA),2) + pow((eastC-eastA),2) + pow((elevC-elevA),2));//空间点AC距离；
			c = sqrt(pow((northB-northA),2) + pow((eastB-eastA),2) + pow((elevB-elevA),2));//空间点AB距离；
		}
	
		//2.开始计算
		double dTmp;
		//2-1.A
		dTmp = (a*a+b*b-c*c)/(2*a*b);
		*angC = rad2deg(acos(dTmp));
	
		//2-2.B
		dTmp = (c*c+a*a-b*b)/(2*c*a);
		*angB = rad2deg(acos(dTmp));
	
		//2-3.C
		dTmp = (b*b+c*c-a*a)/(2*b*c);
		*angA = rad2deg(acos(dTmp));
	
		return ERROR_NULL;
	}

//直线：点线长模式
	/// 通过点、线模式计算线元素
    /// @param[in]  pNE : 点的坐标
    /// @param[in]  aziTangent : 起点方位角
    /// @param[in]  arcLength : 线长度
    /// @return 返回操作错误码，0为成功，其他失败
	int CStakeCurveManage::CalcLineByAziDist(Point2d pNE, double  aziTangent, double arcLength)
	{
		tagElementItem temElement;//曲线元素；
		memset(&temElement, '\0', sizeof(tagElementItem));
		//清空文件数据
		ClearFile();
	
		//长度无效
		if (arcLength <= 1E-7)
		{
			return SCD_ERROR_LENGTH_INVALID;
		}
	
		//先记录第一个元素：交点
		temElement.type = tagElementItem::CURVE_ELEMENT_TYPE_POINT;//元素类型为点；
		temElement.coord = pNE;//起点作为交点？
		temElement.mileage = m_dStartMileage;//起始里程；
		temElement.azimuth = aziTangent;//起点方位角；
		AddElementItem(temElement);//把这个元素添加进去；
	
		//先记录第二个元素：线
		temElement.type = tagElementItem::CURVE_ELEMENT_TYPE_LINE;//元素类型为线；
		temElement.startRadius = temElement.endRadius = -1;//起点半径和终点半径都为-1；
		temElement.length = arcLength;//线的长度；
		AddElementItem(temElement);
	
		//计算坐标列表
		return CalcElementNodeList();
	}
// 计算曲线元素节点坐标列表
	eFileError CStakeManage::CalcElementNodeList()
	{
		double dMileage = 0;
		double temAngle = 0;
		tagCurveNode temNode;//节点（逐桩坐标）定义:(数据索引,eCurveNodeType,点名，是否已放样，里程，方位角，高程，起点)
		//eCurveNodeType:
		//未知类型,起点,终点；中间13个点：直缓节点，缓直，缓圆，圆缓，曲中，直圆，圆直，缓缓，圆圆，直线上，缓曲上，圆曲上，加桩点。
		tagElementItem temElement;
		memset(&temNode, '\0', sizeof(tagCurveNode));
	
		/// 逐桩坐标列表
		m_nCurveNodeCount = 0;
		m_nCurveNodeMaxSize = 0;
		if (NULL != m_pCurveNodeList)
		{
			free(m_pCurveNodeList);
			m_pCurveNodeList = NULL;
		}
		if (m_nElementCount <= 1)
		{
			return SCD_ERROR_LACK_ELEMENT;
		}

	//对所有元素进行处理：
		//处理第几个元素,不处理第一个元素“点”//也就是第一个元素不处理？？
		for (int nIndex = 1; nIndex < m_nElementCount; nIndex++)
		{
			temElement = m_pElementList[nIndex];//获取曲线元素；
	
			//元素起点//设置逐桩坐标点的各项值：
			temNode.mileage = temElement.mileage;
			temNode.coord.x = temElement.coord.x;
			temNode.coord.y = temElement.coord.y;
			temNode.azimuth = temElement.azimuth;

			//节点类型//设置逐桩坐标点的类型；根据前一个元素的类来判断？？
			switch (temElement.type)
			{
			case tagElementItem::CURVE_ELEMENT_TYPE_LINE://如果是线；
				{
					switch (m_pElementList[nIndex-1].type)//查看前一个点的类型
					{
					case tagElementItem::CURVE_ELEMENT_TYPE_POINT://如果是点：
						temNode.type = tagCurveNode::CURVE_NODE_TYPE_QD;//则类型为起点；
						break;
					case tagElementItem::CURVE_ELEMENT_TYPE_LINE://线
						temNode.type = tagCurveNode::CURVE_NODE_TYPE_Z;//直线上的点；
						break;
					case tagElementItem::CURVE_ELEMENT_TYPE_CIRCLE://圆曲
						temNode.type = tagCurveNode::CURVE_NODE_TYPE_YZ;//圆直节点；
						break;
					case tagElementItem::CURVE_ELEMENT_TYPE_EASE://缓曲
						temNode.type = tagCurveNode::CURVE_NODE_TYPE_HZ;//缓直节点；
						break;
					}
				}
				break;
			case tagElementItem::CURVE_ELEMENT_TYPE_CIRCLE://圆曲
				{
					switch (m_pElementList[nIndex-1].type)//查看前一个点的类型：
					{
					case tagElementItem::CURVE_ELEMENT_TYPE_POINT://点
						temNode.type = tagCurveNode::CURVE_NODE_TYPE_QD;//起点
						break;
					case tagElementItem::CURVE_ELEMENT_TYPE_LINE://线
						temNode.type = tagCurveNode::CURVE_NODE_TYPE_ZY;//直圆节点；
						break;
					case tagElementItem::CURVE_ELEMENT_TYPE_CIRCLE: //圆曲
						temNode.type = tagCurveNode::CURVE_NODE_TYPE_YY;//圆圆
						break;
					case tagElementItem::CURVE_ELEMENT_TYPE_EASE:
						temNode.type = tagCurveNode::CURVE_NODE_TYPE_HY;//缓圆
						break;
					}
				}
				break;
			case tagElementItem::CURVE_ELEMENT_TYPE_EASE://缓曲
				{
					switch (m_pElementList[nIndex-1].type)
					{
					case tagElementItem::CURVE_ELEMENT_TYPE_POINT:
						temNode.type = tagCurveNode::CURVE_NODE_TYPE_QD;
						break;
					case tagElementItem::CURVE_ELEMENT_TYPE_LINE:
						temNode.type = tagCurveNode::CURVE_NODE_TYPE_ZH;
						break;
					case tagElementItem::CURVE_ELEMENT_TYPE_CIRCLE:
						temNode.type = tagCurveNode::CURVE_NODE_TYPE_YH;
						break;
					case tagElementItem::CURVE_ELEMENT_TYPE_EASE:
						temNode.type = tagCurveNode::CURVE_NODE_TYPE_HH;
						break;
					}
				}
				break;
			}
	
		//添加节点
			if(AddCurveNodeItem(temNode)<0)
				return SCD_ERROR_MEMORY_FAILED;
	
			//将里程定位到元素内部
		//设置逐桩坐标点的里程：
			dMileage = 0;
			if (SCD_MAKE_TYPE_INTEGRAL_MARK == m_nMakeType)//如果是根据整桩号生成
			{
				while (dMileage <= temElement.mileage)//直到元素的里程相等或者小于一个间隔值？
				{
					dMileage += m_dMileageInterval;
				}
			}
			else if (SCD_MAKE_TYPE_INTEGRAL_SPACE == m_nMakeType)// 如果是根据整桩距生成
			{
				dMileage = temNode.mileage + m_dMileageInterval;//里程 = 逐桩元素的里程+里程间隔？
			}
			else
			{
				return SCD_ERROR_MAKE_TYPE;
			}	
			temAngle = deg2rad(temElement.azimuth);//度转弧度；
			
			//由于圆要处理曲中，所以要另外处理
			if (tagElementItem::CURVE_ELEMENT_TYPE_CIRCLE == temElement.type)//如果元素类型是圆；
			{//设置桩点的里程和类型，并添加桩点；
			
				//直到当前里程大于曲中最大里程//里程不断按里程间隔增加；
				while(temElement.mileage + temElement.length/2.0 > dMileage)//如果元素里程+长度/2大于上面求得的里程；
				{
					//获取指定里程的坐标和方位角//指定里程为：里程-元素里程？？，偏距为0；//不明白？？
					hcurve_moffset_to_posa(temNode.coord, temNode.azimuth, temElement, dMileage-temElement.mileage, 0);
					//元素上桩点
					temNode.mileage = dMileage;//桩点的里程就是求得的里程；
	
					temNode.type = tagCurveNode::CURVE_NODE_TYPE_Y;//桩点的类型：圆
	
			//添加节点
					if(AddCurveNodeItem(temNode)<0)
						return SCD_ERROR_MEMORY_FAILED;
	
					dMileage += m_dMileageInterval;//里程+里程间隔；
				}
	
				//计算曲中//指定里程为：元素的长度/2，偏距为0；
				hcurve_moffset_to_posa(temNode.coord, temNode.azimuth, temElement, temElement.length/2.0, 0);
				//元素起点
				temNode.mileage = temElement.mileage + temElement.length/2.0;//桩点的里程 = 元素的里程+元素长度/2:
				temNode.type = tagCurveNode::CURVE_NODE_TYPE_QZ;//桩点类型：起点；
				
			//添加节点
				if(AddCurveNodeItem(temNode)<0)
					return SCD_ERROR_MEMORY_FAILED;
	
				//整桩距在曲中的基础上加上里程间隔
				if (SCD_MAKE_TYPE_INTEGRAL_SPACE == m_nMakeType)//如果生成方式是整桩距生成；
				{
					dMileage = temNode.mileage + m_dMileageInterval;//里程 = 逐桩元素里程+里程间隔；
				}
			
			//设置桩点的里程和类型：
				//直到当前里程大于线元最大里程
				while(temElement.mileage + temElement.length > dMileage)//如果元素里程 + 元素长度>里程；就执行；
				{
					//获取指定里程的坐标和方位角//指定里程为：里程-元素里程？？，偏距为0；
					hcurve_moffset_to_posa(temNode.coord, temNode.azimuth, temElement, dMileage-temElement.mileage, 0);
					//元素上桩点
					temNode.mileage = dMileage;
	
					temNode.type = tagCurveNode::CURVE_NODE_TYPE_Y;
	
			//添加节点
					if(AddCurveNodeItem(temNode)<0)
						return SCD_ERROR_MEMORY_FAILED;
	
					dMileage += m_dMileageInterval;
				}
			}//if (ElementItem::CURVE_ELEMENT_TYPE_ARC == temElement.type)
			else//如果元素类型不是圆；
			{
				//直到当前里程大于线元最大里程
				while(temElement.mileage + temElement.length > dMileage)//如果元素里程+元素的长度大于当前里程；
				{
				//设置桩点的里程和类型：
					//获取指定里程的坐标和方位角
					hcurve_moffset_to_posa(temNode.coord, temNode.azimuth, temElement, dMileage-temElement.mileage, 0);
					//元素上桩点
					temNode.mileage = dMileage;
	
					switch (temElement.type)//根据元素类型：
					{
					case tagElementItem::CURVE_ELEMENT_TYPE_LINE: //如果是线；
						temNode.type = tagCurveNode::CURVE_NODE_TYPE_Z;//直线上的点；
						break;
					case tagElementItem::CURVE_ELEMENT_TYPE_EASE:
						temNode.type = tagCurveNode::CURVE_NODE_TYPE_H;//缓曲上的点；
						break;
					}
			//添加节点
					if(AddCurveNodeItem(temNode)<0)
						return SCD_ERROR_MEMORY_FAILED;
	
					dMileage += m_dMileageInterval;
				}
			}//else if (ElementItem::CURVE_ELEMENT_TYPE_ARC != temElement.type)
		}
	
	//添加终点坐标
		//获取指定里程的坐标和方位角//指定里程为：元素的长度，偏距为0；就可以求终点坐标；
		hcurve_moffset_to_posa(temNode.coord, temNode.azimuth, temElement, temElement.length, 0);
	
		//元素上桩点
		temNode.mileage = temElement.mileage + temElement.length;//元素的里程+元素的长度；
		temNode.type = tagCurveNode::CURVE_NODE_TYPE_ZD;
	//添加节点
		if(AddCurveNodeItem(temNode)<0)
			return SCD_ERROR_MEMORY_FAILED;
	
	//将节点填充点名
		int nCount = 0, nZHCount = 0, nHZCount = 0, nHYCount = 0, nYHCount = 0;
		int nQZCount = 0, nZYCount = 0, nYZCount = 0, nHHCount = 0, nYYCount = 0;
		//对所有的桩点进行循环；
		for(int k=0; k<GetCurveNodeCount(); k++)
		{
			temNode = GetCurveNodeItem(k);//获取桩点；
			switch(temNode.type)//根据类型设置点名；
			{
			case tagCurveNode::CURVE_NODE_TYPE_QD:
				sprintf(temNode.name, "%s", "QD");
				break;
			case tagCurveNode::CURVE_NODE_TYPE_ZD:
				sprintf(temNode.name, "%s", "ZD");
				break;
			case tagCurveNode::CURVE_NODE_TYPE_ZH:
				sprintf(temNode.name, "%s%d", "ZH", ++nZHCount);
				break;
			case tagCurveNode::CURVE_NODE_TYPE_HZ:
				sprintf(temNode.name, "%s%d", "HZ", ++nHZCount);
				break;
			case tagCurveNode::CURVE_NODE_TYPE_HY:
				sprintf(temNode.name, "%s%d", "HY", ++nHYCount);
				break;
			case tagCurveNode::CURVE_NODE_TYPE_YH:
				sprintf(temNode.name, "%s%d", "YH", ++nYHCount);
				break;
			case tagCurveNode::CURVE_NODE_TYPE_QZ:
				sprintf(temNode.name, "%s%d", "QZ", ++nQZCount);
				break;
			case tagCurveNode::CURVE_NODE_TYPE_ZY:
				sprintf(temNode.name, "%s%d", "ZY", ++nZYCount);
				break;
			case tagCurveNode::CURVE_NODE_TYPE_YZ:
				sprintf(temNode.name, "%s%d", "YZ", ++nYZCount);
				break;
			case tagCurveNode::CURVE_NODE_TYPE_HH:
				sprintf(temNode.name, "%s%d", "HH", ++nHHCount);
				break;
			case tagCurveNode::CURVE_NODE_TYPE_YY:
				sprintf(temNode.name, "%s%d", "YY", ++nYYCount);
				break;
			case tagCurveNode::CURVE_NODE_TYPE_Z:
			case tagCurveNode::CURVE_NODE_TYPE_H:
			case tagCurveNode::CURVE_NODE_TYPE_Y:
				sprintf(temNode.name, "%d", ++nCount);
				break;
			}//switch(data.type)
	
			SetCurveNodeItem(k, temNode);
		}
	
		return SCD_SUCCEED;
	}

CRoadManage
	CalcElementNodeList()//计算曲线元素节点坐标列表	
	CalculateElementItem（）// 计算生成元素值
		//其实修改元素的值，使之更趋近于公式？
		元素个数小于2，返回；
		
		第一个元素的里程 = 起点里程；
		
		对所有元素进行循环：
			获取前一个元素；
			获取当前元素；
			
			利用前一元素，及其长度，偏距为0计算终点坐标和偏角； 并作为当前元素的坐标和偏角；
			
			//使用断链计算元素表内容
			对所有断链个数进行处理：
				获取断链；
				如果元素的里程-断链的断前里程 < 0.0001;
					元素的里程 = 断链元素的断后里程；
					又赋值回断链表？
					跳出；
		返回；
	TestElementItem()  // 检查综合曲线是否符合标准,修正可修改部分,返回0表示成功
		元素个数小于2，则返回；
		
		对所有的元素进行处理：
			获取元素;
			根据元素类型进行判断：//当前元素
				如果是线：
					起点半径和终点半径=-1；//修改数据？
					//只有长度有效
					如果i+1小于元素总数 并且 起点半径的绝对值==0 且i+1元素时直线
						i+1元素的起点半径=当前的终点半径（-1）；
				圆：
					同上；
					设置i+1元素的半径和偏向；
				缓曲：
					//如果i+1是直线
					如果当前元素的终点半径==0并且i+1元素类型为直线；
						设置当前点的终点半径为-1；
					否则如果 当前元素的终点半径==0 并且 i+1元素时圆
						根据i+1元素设置当前元素的终点半径和偏向；
					否则如果当前元素的终点半径==0
						直接设置为 -1；
					
					//不存在两端都无穷大的缓曲
					
					//两端半径相等，退化成圆
						修改类型
				点：
					设置长度和终点半径；
				
			//不允许出现长度为0的元素
			
			//如果i！=0；
				//增加,处理断链，将元素分割//不懂？？-断链数据：断前里程，断后里程？？
				对所有断链进行处理：
					获取断链元素；
					
					判断断链所在元素
					如果元素的里程==断前里程 并且 元素里程+长度>断前里程；
						下次从下一个开始查找（k已经++了，再+1）；
						添加里程 = 断后里程-断前里程？？//
						如果（元素里程-断前里程>0.0001)
							保存元素长度；
							拷贝一份元素；
							元素的长度改为：断前里程-元素里程；//改变元素长度；
							拷贝元素的长度 = 保存元素长度-新元素长度；
							
							如果（拷贝元素的长度>0.0001）
								//计算缓曲分割时半径//??什么叫缓曲分隔时半径？
								如果拷贝元素的类型为缓曲：
									获取起点和终点的半径；
									
									0点到起点、到终点、到当前点的曲线长？？
									如果（起点半径==0或者小于0）//起点曲率半径为无穷大的曲线：曲率半径：曲率的倒数就是曲率半径；//曲率半径越大，圆弧越平缓，曲率半径越小，圆弧越陡。
										到终点的曲线长=原元素的长度；
										到当前点 = 原元素的新长度；
									//起点曲率半径不为无穷大
										如果终点半径==0
											终点半径=起点半径；
											终点的曲线上同上；
											当前点的曲线长：拷贝元素的长度；
										否则
											到起点的曲线长 = 保存的长度*终点半径/（起点半径-终点半径）；
											到终点的曲线长 = 
											到当前点的曲线长 = ；
									原元素的终点半径 = 拷贝元素的起点半径 =  终点半径*到终点曲线长/当前点；
								添加拷贝元素 到i+1的位置；
						跳出循环？
							
			如果（i<元素个数-1）//不是最后一个元素；
				设置i+1元素的里程 = 元素的里程 + 元素的长度 + 添加里程：
			
			把元素放到i位置；
		返回true；
					
		
	// 计算缓曲的切线长//切线长 = T = （R（半径） + P）tg（a/2） + m；//根据弧长公式 l = rθ （式中：l是弧长,r是半径,θ是圆心角）//所以有：θ =l/r,即弧长除以半径是圆心角的大小,该圆心角用弧度制表示.
	double hcurve_calc_ease_tangent_length(const double &radius,const double &angle, const double &lengh)
		//半径，角度，长度；
		半径不小于0；
		
		角度转换为弧度(angle)；
		B0 = 长度/(2*半径)；//计算用参数；
		da =  弧度+2*B0；//根据角度，长度和半径；
		
		P = 长度的平方/（24*半径）- 长度的4次方/(2688*半径的3次方)；//根据长度和半径求出；
		m0= 长度的一半 - 长度的3次方/（240*半径的平方） + 长度的5次方/34560.0*半径的平方；//根据长度和半径就可以求出来；
		result = （半径+P）*tan（da/2.0) + m0;

	/// 将交点法中的交点换算成元素
		eFileError CRoadManage::IntersectToElement()
		{
			tagElementItem temElement;
		
			//清空原来元素数据
			m_nElementCount = 0;
			if (m_pElementList)
			{
				free(m_pElementList);
				m_pElementList = NULL;
			}
		
			//交点数目必须大小2
			if (m_pIntersectList == NULL || m_nIntersectCount < 2)
			{
				return SCD_ERROR_LACK_ELEMENT;
			}
		
			//先记录第一个元素：交点
			Point2d pnt0=m_pIntersectList[0].pntNE;
			Point2d pnt1=m_pIntersectList[1].pntNE;
			memset(&temElement, '\0', sizeof(tagElementItem));
			temElement.type = tagElementItem::CURVE_ELEMENT_TYPE_POINT;
			temElement.coord = pnt0;
			temElement.mileage = m_pIntersectList[0].mileage;
			temElement.azimuth = vec_angle(pnt1-pnt0, 1);//设置元素偏向角 = 后一个点到前一个点的角度；（x0，y0，x1，y1）//先求出两者的差值，然后用atan2求角度；
			AddElementItem(temElement);
		
			double   dTemDist1 = 0.0;
			double   dTemDist2 = 0.0;
			double   dBeforDist = 0.0;
			double   nLineDist = 0.0;   //直线段长
		
			//前后方位角,用来计算转角,从而得到左偏右偏标识
			double   dAfterAng = 0.0; 
			double   dBeforAng = 0.0;
			bool	 bDirectionR = false;  //左偏右偏标识
		
			//每个元素有两个方位角,求取用来识别方向
			for(int n=1; n<m_nIntersectCount-1; n++)
			{
				//如果不是第一个点和最后一个点而半径小于0，则返回错误
				if (m_pIntersectList[n].radius < 1e-6 && n != m_nIntersectCount-1)
				{
					return SCD_ERROR_INVALID_TYPE;
				}
		
				//N点到N-1点的方位角
				Point2d pntN1(m_pIntersectList[n].pntNE);
				Point2d pntN0(m_pIntersectList[n-1].pntNE);
				dBeforAng = vec_angle(pntN0-pntN1, 1);
		
				//N-1与N点的距离
				dBeforDist = vec_length(pntN0-pntN1);
		
				//当前点不是最后一个点
				if(n != m_nIntersectCount-1)  
				{
					//3a.计算出转角->圆曲的圆心角->圆曲线长度
					Point2d pntN2(m_pIntersectList[n+1].pntNE);
					dAfterAng = vec_angle(pntN2-pntN1, 1);
		
					//方位角1减方位角得到夹角
					double res = dBeforAng - dAfterAng;
					if(res < 0) 
						res += 360;
		
					if(res < 180.0)	//通过夹角大小确定左右偏转方向
						bDirectionR = true;
					else
						bDirectionR = false;
		
					//计算交角及弧长
					
					// 圆曲部分的圆心角
					const double dYuanAng = fabs(res - 180.0)
						- rad2deg(m_pIntersectList[n].A1/(m_pIntersectList[n].radius*2))
						- rad2deg(m_pIntersectList[n].A2/(m_pIntersectList[n].radius*2));
		
					// 圆曲线弧长(圆心角乘半径)
					const double dYuanLen = (deg2rad(dYuanAng))*m_pIntersectList[n].radius;
					
					//得到切线长1和切线长2
					const double T1 = hcurve_calc_ease_tangent_length(m_pIntersectList[n].radius, dYuanAng, m_pIntersectList[n].A1); 
					const double T2 = hcurve_calc_ease_tangent_length(m_pIntersectList[n].radius, dYuanAng, m_pIntersectList[n].A2);
		
					//计算HZ点和t2点经四参数以后的坐标
					Point2d p0, pp0;
					{
						Point2d pnt1,pnt2;
						Point2d pnt11, pnt22;
						hcurve_calc_end_points(pnt1, pnt2, m_pIntersectList[n].radius, dYuanAng, m_pIntersectList[n].A1, bDirectionR);
						hcurve_calc_end_points(pnt11, pnt22, m_pIntersectList[n].radius, dYuanAng, m_pIntersectList[n].A2, !bDirectionR);
		
						//此时求解第一个四参数
						double Ro, dScale;
						Point2d pnt0;
						p4_from_point_pairs(pnt0, Ro, dScale, pnt22, pnt1, pnt11, pnt2);
		
						//[2009.10.12]:p0为HZ点坐标,pp0为切线点2的坐标
						//HZ点
						p0.x = dScale*(cos(Ro) * 0 - sin(Ro) * 0) + pnt0.x;
						p0.y = dScale*(sin(Ro) * 0 + cos(Ro) * 0) + pnt0.y;
		
						//切线点2的坐标: 08.12.18 禄 增加,解决短边控制长边问题
						//xx0 = dScale*(cos(Ro) * T2 - sin(Ro) * 0) + X0;
						//yy0 = dScale*(sin(Ro) * T2 + cos(Ro) * 0) + Y0;
						pp0.x = p0.x - T2* cos(deg2rad(res));
						pp0.y = p0.y + T2* sin(deg2rad(res));
					}
		
					//求交点坐标
					Point2d pntResult;
					line_cross(pntResult, Point2d(0,0), Point2d(T1,0), p0, pp0);
		
					//3c.求取距离:通过以上求出的JD坐标,可以得到ZH到交点的实际距离
					//通过两个交点的实际坐标,可以求出两交点之间的实际距离
					//相减得到第一段直线长
					dTemDist1 = vec_length(Point2d(0,0)-pntResult);
					//直线长
					nLineDist = dBeforDist - dTemDist1 - dTemDist2;  //后面就存在两条,详细见说明文档
					//还要求出交点到HZ点距离,以求下一个JD的第一段直线长
					dTemDist2 = vec_length(p0-pntResult);
		
					//3d.存储顺序:直线->缓曲->圆曲->缓曲
					/// 直线元素
					if (nLineDist > 1E-7)
					{
						memset(&temElement, '\0', sizeof(temElement));
						temElement.type = tagElementItem::CURVE_ELEMENT_TYPE_LINE;
						temElement.length = nLineDist;
						temElement.overhgt = 0;
						AddElementItem(temElement);
					}
		
					//如果缓合曲线的长度大于零，则写入缓曲部分
					if(m_pIntersectList[n].A1 > 1e-7)
					{
						memset(&temElement, '\0', sizeof(tagElementItem));
						temElement.type = tagElementItem::CURVE_ELEMENT_TYPE_EASE;
						temElement.length = m_pIntersectList[n].A1;
						temElement.startRadius = -1;
						temElement.endRadius = m_pIntersectList[n].radius;
						temElement.directionR = bDirectionR; //方向
						temElement.overhgt = m_pIntersectList[n].overhgt;
						AddElementItem(temElement);
					}
		
					//如果圆曲长大于0，添加圆曲
					if (dYuanLen > 1E-5)
					{
						memset(&temElement, '\0', sizeof(tagElementItem));
						temElement.type = tagElementItem::CURVE_ELEMENT_TYPE_CIRCLE;
						temElement.length = dYuanLen;
						temElement.startRadius = m_pIntersectList[n].radius;
						temElement.endRadius = temElement.startRadius;
						temElement.directionR = bDirectionR; //方向
						temElement.overhgt = m_pIntersectList[n].overhgt;
						AddElementItem(temElement);
					}
		
					//如果缓合曲线的长度大于零，则写入缓曲部分
					if(m_pIntersectList[n].A2 > 1e-8)
					{
						memset(&temElement, '\0', sizeof(tagElementItem));
						temElement.type = tagElementItem::CURVE_ELEMENT_TYPE_EASE;
						temElement.startRadius = m_pIntersectList[n].radius;
						temElement.endRadius = -1;
						temElement.length = m_pIntersectList[n].A2;
						temElement.directionR = bDirectionR; //方向
						temElement.overhgt = m_pIntersectList[n].overhgt;
						AddElementItem(temElement);
					}
				}
				else
				{
					//这种情况只会出现在只有两个点的时候
					memset(&temElement, '\0', sizeof(temElement));
					temElement.type = tagElementItem::CURVE_ELEMENT_TYPE_LINE;
					temElement.length = dBeforDist;
		
					//第二个元素：直线
					temElement.overhgt = 0;
					AddElementItem(temElement);
					break;
				}
		
				//如果到了最后一个交点
				if(n+2 == m_nIntersectCount)
				{
					dBeforDist = vec_length(m_pIntersectList[n+1].pntNE-m_pIntersectList[n].pntNE);
		
					nLineDist = dBeforDist - dTemDist2;
		
					if (nLineDist > 1E-7)
					{
						/// 直线元素
						memset(&temElement, '\0', sizeof(temElement));
						temElement.type = tagElementItem::CURVE_ELEMENT_TYPE_LINE;
						temElement.length = nLineDist;
						AddElementItem(temElement);
					}
					break;
				}
			}
		
			return SCD_SUCCEED;
		}
	eFileError IntersectToElement()
		清空原来的数据；
		交点数目必须大于2；
		
		从交点数组获取第一个和第二个交点；
		设置元素类型；
		设置元素坐标；
		设置元素里程；
		设置元素偏向角 = 后一个点到前一个点的角度；（x0，y0，x1，y1）//先求出两者的差值，然后用atan2求角度；
		添加第一个元素；
		
		临时距离1；
		临时距离2；
		前距离；
		直线长度；//哪段直线？
		
		前方位角；
		后方位角；//由这两个计算转角，从而得到左偏右偏；
		左偏右偏标识；
		
		对所有交点进行处理：//每个元素有两个方位角,求取用来识别方向//首先得知道交点是什么？
			//如果不是第一个点和最后一个点而半径小于0，则返回错误
			
			N点到N-1点的方位角；//作为前方位角；//这里注意是n点到n-1点不是n-1点到n点的方位角；
			两点的距离为前距离；
			
			当前点不是最后一个点
				后角 = n+1点到n点的偏向角；
				
				前角减后角的角度差res；
				<0则+360；
				如果<180则是偏右；//根据大于180还是小于180判断；
				否则偏左；
				
				计算交角及弧长：
				圆曲部分的圆心角：//第一缓曲：
					res-180的绝对值 - 第一缓曲/2*R的角度-第二缓曲的角度；
					
				圆曲线弧长(圆心角乘半径)
				
				得到切线长1和切线长2//通过半径，求得的圆心角，第一缓曲长求切线长；
					hcurve_calc_ease_tangent_length(m_pIntersectList[n].radius, dYuanAng, m_pIntersectList[n].A1); 
					hcurve_calc_ease_tangent_length(m_pIntersectList[n].radius, dYuanAng, m_pIntersectList[n].A2);
				
				//计算HZ点和t2点经四参数以后的坐标
					//用半径，角度，n点的第一缓曲，求第一缓曲的两端点；
					hcurve_calc_end_points(pnt1, pnt2, m_pIntersectList[n].radius, dYuanAng, m_pIntersectList[n].A1, bDirectionR);
					//用半径，角度，n点的第二缓曲，求第二缓曲的两端点；
					hcurve_calc_end_points(pnt11, pnt22, m_pIntersectList[n].radius, dYuanAng, m_pIntersectList[n].A2, !bDirectionR);
					
					//此时求解第一个四参数//R0旋转角度，dScale比例，pnt0偏移偏量；
					p4_from_point_pairs(pnt0, Ro, dScale, pnt22, pnt1, pnt11, pnt2);
					
					//[2009.10.12]:p0为HZ点坐标,pp0为切线点2的坐标
					//HZ点
					
					//切线点2的坐标: 08.12.18 禄 增加,解决短边控制长边问题
					
				//求交点坐标
				
				//3c.求取距离:通过以上求出的JD坐标,可以得到ZH到交点的实际距离
				//通过两个交点的实际坐标,可以求出两交点之间的实际距离
				//相减得到第一段直线长//直缓（0,0）减去交点坐标；
				
				//直线长
				
			否则//当前点是最后一个点：
			
			//如果到了最后一个交点
	eFileError DesignCalculate(eRoadDesignType nType)
		//生成道路放样数据以及逐桩坐标表
		清空原来的数据；
		如果是交点法，先通过交点法换算成元素法；
			IntersectToElement()；
			
		//测试曲线是否满足输入要求
			TestElementItem()
			
		//计算元素内的各值
			CalculateElementItem()
			
		return CalcElementNodeList()
RoadManageTest.cpp：
	CmpMileageCent()
		// 测试校验25米间隔时，中心坐标点与同里程计算线路点的距离	
		process_resolve_path（缓存,缓存大小，//获取$(GNSS_TEST_DATA_DIR)的绝对路径，获取ip文件的路径；
		设置起点里程；
		设置里程间隔；
		设置类型；//根据整桩号生成；根据整桩距生成；
		
		加载文件；
		设计计算；
		
		获取总的点数；
		定义逐桩坐标点变量；



卸载中软防水墙软件
	我这里所谓的卸载就是使得它不能运行	
	步骤如下：
	1. 新建c:\a.bat批处理, 放在C:\Windows\System32目录下该文件的目的就是重命名防水墙的相关文件:
	//C:\Windows\SysWOW64
	//C:\Windows\SysWOW64\CSSSP\cache\SPAstMgr.dll
	//C:\Windows\SysWOW64\SPMCenter.exe
	//C:\Windows\SysWOW64\CSSSP\cache\SPMCenter.exe
	//C:\Windows\SysWOW64\WSPLog\spmcenter.log
	rename CSSSP aaaCSSSP2
	rename SPAstMgr.dll aaaSPAstMgr.dll2
	rename SPCab.dll aaaSPCab.dll2
	rename SPCAntiLeak.dll aaaSPCAntiLeak.dll2
	rename SPCdr.sys aaaSPCdr.sys2
	rename SPCFire.dll aaaSPCFire.dll2
	rename SpcMendMgr.dll aaaSpcMendMgr.dll2
	rename SPCNetPatrol.dll aaaSPCNetPatrol.dll2
	rename SPCRun.dll aaaSPCRun.dll2
	rename SPCSecOpt.dll aaaSPCSecOpt.dll2
	rename SPCSecPly.dll aaaSPCSecPly.dll2
	rename SPCSftDis.dll aaaSPCSftDis.dll2
	rename SpcVirusMgr.dll aaaSpcVirusMgr.dll2
	rename SPDCryLib.dll aaaSPDCryLib.dll2
	rename SPDrvType.dll aaaSPDrvType.dll2
	rename SPFCryLib.dll aaaSPFCryLib.dll2
	rename SPFFlt.dll aaaSPFFlt.dll2
	rename SPFhk.dll aaaSPFhk.dll2
	rename SPFile.sys aaaSPFile.sys2
	rename SPHwMgr.dll aaaSPHwMgr.dll2
	rename SPIdtAux.dll aaaSPIdtAux.dll2
	rename SPIpcComm.dll aaaSPIpcComm.dll2
	rename SPKMMgr.dll aaaSPKMMgr.dll2
	rename SPLice.dll aaaSPLice.dll2
	rename SPMCenter.exe aaaSPMCenter.exe2
	rename SpMend.dll aaaSpMend.dll2
	rename SPModem.dll aaaSPModem.dll2
	rename SPNdis.sys aaaSPNdis.sys2
	rename SPNetCfg.dll aaaSPNetCfg.dll2
	rename SPNetFlt.dll aaaSPNetFlt.dll2
	rename SpNotify.dll aaaSpNotify.dll2
	rename SPPhk.dll aaaSPPhk.dll2
	rename SPPsFlt.dll aaaSPPsFlt.dll2
	rename SPPsFlt.sys aaaSPPsFlt.sys2
	rename SPRegFlt.dll aaaSPRegFlt.dll2
	rename SPRegFlt.sys aaaSPRegFlt.sys2
	rename SpRtMgr.dll aaaSpRtMgr.dll2
	rename SPSecMon.dll aaaSPSecMon.dll2
	rename SPSecOpt.dll aaaSPSecOpt.dll2
	rename SPSFIcon.dll aaaSPSFIcon.dll2
	rename SPSFMenu.dll aaaSPSFMenu.dll2
	rename SPSoftDisp.dll aaaSPSoftDisp.dll2
	rename SPSysLog.dll aaaSPSysLog.dll2
	rename SPTdi.sys aaaSPTdi.sys2
	rename SPUninst.dll aaaSPUninst.dll2
	rename SPUserReg.dll aaaSPUserReg.dll2
	rename SPViewer.exe aaaSPViewer.exe2
	rename SpVirus.dll aaaSpVirus.dll2
	rename SPNetAuth.dll aaaSPNetAuth.dll2
	rename WBISecDoc.dll aaaWBISecDoc.dll2
	rename WBSecdoc.sys aaaWBSecdoc.sys2
	rename EfsCbCt.dll aaaEfsCbCt.dll2
	rename EFSControl.dll aaaEFSControl.dll2
	rename EfsUser.dll aaaEfsUser.dll2
	rename ScanEncrypt.dll aaaScanEncrypt.dll2
	rename SecureDoc.dll aaaSecureDoc.dll2
	rename WBScanEncrypt.exe aaaWBScanEncrypt.exe2
	rename SecDocExp.dll aaaSecDocExp.dll2
	rename RecorverModule.dll aaaRecorverModule.dll2
	rename ExamAppr.dll aaaExamAppr.dll2
	rename EFSCtlExp.dll aaaEFSCtlExp.dll2
	rename SDocShll.dll aaaSDocShll.dll2
	rename SPSVerf.dll aaaSPSVerf.dll2
	rename SPCSDoc.dll aaaSPCSDoc.dll2
	rename SPTSMgr.dll aaaSPTSMgr.dll2
	rename SPCTStor.dll aaaSPCTStor.dll2
	rename SPTSHK.dll aaaSPTSHK.dll2
	rename WBTSMnt.dll aaaWBTSMnt.dll2
	rename WBTSDrv.sys aaaWBTSDrv.sys2
	rename SPNetPatrol.dll aaaSPNetPatrol.dll2
	rename SPTSDropHandler.dll aaaSPTSDropHandler.dll2
	rename SPSens.dll aaaSPSens.dll2
	rename ScanCheckFile.exe aaaScanCheckFile.exe2
	rename SPFParse.dll aaaSPFParse.dll2
	rename SPSdMgr.dll aaaSPSdMgr.dll2
	rename sprun.exe aaasprun.exe2
	rename SDocEqualShll.dll aaaSDocEqualShll.dll2
	rename SDocHighShll.dll aaaSDocHighShll.dll2
	rename SDocLowShll.dll aaaSDocLowShll.dll2
	rename SPCTbfps.dll aaaSPCTbfps.dll2
	rename SDocOrdLvlShll.dll aaaSDocOrdLvlShll.dll2
	pause
	
	2、重启系统, 用你的办法进入命令行模式(只要防水墙没被运行的模式都行, 例如启动盘, 安装盘等), cd 到C:\WINDOWS\system32\ 运行a.bat
	3、重启系统，正常进入系统下，运行services.msc，进入服务管理，将WaterBox Client Security Patron Service服务设为“禁用”;
	4、运行msconfig ,启动,找到SPMCenter启动项，去掉前面的勾，并“应用”。目的是不将其作为自启动项。
	5、删除以下注册表项：
	HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Shared Tools\MSConfig\startupreg\SpMessageCenter
	HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run 下 SpMessageCenter项
	HKEY_CURRENT_USER\Software\Microsoft\Windows\ShellNoRoam\MUICache 下 C:\WINDOWS\system32\SpmCenter.exe项
	HKEY_CURRENT_USER\Software\NVIDIA Corporation\Global\nView\WindowManagement\spmcenter
	[HKLM\SYSTEM\CurrentControlSet\Services\WBTS]
	[HKLM\SYSTEM\CurrentControlSet\Services\NPF]
	[HKLM\SYSTEM\CurrentControlSet\Services\SpNdis]
	[HKLM\SYSTEM\CurrentControlSet\Services\SPTdi]
	[HKLM\SYSTEM\CurrentControlSet\Services\SPCdr]
	[HKLM\SYSTEM\CurrentControlSet\Services\SPRegFlt]
	[HKLM\SYSTEM\CurrentControlSet\Services\SPPsFlt]
	[HKLM\SYSTEM\CurrentControlSet\Services\SPFile]
	[HKLM\SYSTEM\CurrentControlSet\Services\SecPatron]
	6、重新启动，检验效果。并用超级兔子之类的工具清理系统和注册表垃圾文件。
 
如何彻底卸载删除防水墙呢？
	XP系统，卸载防水墙的步骤
	我的机器是XP，近期因换工作的缘故，不再需要防水墙了，但是发现很难删除，无法按通常的步骤卸载。经过一番努力，终于成功。遂记录下来分享。
	
	说明：防水墙（中软统一终端安全平台）
		进程1：SecPatron.exe
		进程2：SPMCenter.exe
		服务：WaterBox Client Security Patron Service ~ system32\CSSSP\bin\SecPatron.exe
				//c:\Windows\SysWOW64\SPMCenter.exe
	步骤如下：
	1、在XP中，下载个虚拟软驱VFloppy，设置为可引导（具体方法很简单，在此略了）;
	
		并将以下命令，保存为c:\1.bat批处理，目的是在dos下删除这些dll文件：  
	
	del c:\windows\system32\SPAstMgr.dll
	del c:\windows\system32\SPCab.dll
	del c:\windows\system32\SPCAntiLeak.dll
	del c:\windows\system32\SPCdr.sys
	del c:\windows\system32\SPCFire.dll
	del c:\windows\system32\SpcMendMgr.dll
	del c:\windows\system32\SPCNetPatrol.dll
	del c:\windows\system32\SPCRun.dll
	del c:\windows\system32\SPCSecOpt.dll
	del c:\windows\system32\SPCSecPly.dll
	del c:\windows\system32\SPCSftDis.dll
	del c:\windows\system32\SpcVirusMgr.dll
	del c:\windows\system32\SPDCryLib.dll
	del c:\windows\system32\SPDrvType.dll
	del c:\windows\system32\SPFCryLib.dll
	del c:\windows\system32\SPFFlt.dll
	del c:\windows\system32\SPFhk.dll
	del c:\windows\system32\SPFile.sys
	del c:\windows\system32\SPHwMgr.dll
	del c:\windows\system32\SPIdtAux.dll
	del c:\windows\system32\SPIpcComm.dll
	del c:\windows\system32\SPKMMgr.dll
	del c:\windows\system32\SPLice.dll
	del c:\windows\system32\SPMCenter.exe
	del c:\windows\system32\SpMend.dll
	del c:\windows\system32\SPModem.dll
	del c:\windows\system32\SPNdis.sys
	del c:\windows\system32\SPNetCfg.dll
	del c:\windows\system32\SPNetFlt.dll
	del c:\windows\system32\SpNotify.dll
	del c:\windows\system32\SPPhk.dll
	del c:\windows\system32\SPPsFlt.dll
	del c:\windows\system32\SPPsFlt.sys
	del c:\windows\system32\SPRegFlt.dll
	del c:\windows\system32\SPRegFlt.sys
	del c:\windows\system32\SpRtMgr.dll
	del c:\windows\system32\SPSecMon.dll
	del c:\windows\system32\SPSecOpt.dll
	del c:\windows\system32\SPSFIcon.dll
	del c:\windows\system32\SPSFMenu.dll
	del c:\windows\system32\SPSoftDisp.dll
	del c:\windows\system32\SPSysLog.dll
	del c:\windows\system32\SPTdi.sys
	del c:\windows\system32\SPUninst.dll
	del c:\windows\system32\SPUserReg.dll
	del c:\windows\system32\SPViewer.exe
	del c:\windows\system32\SpVirus.dll
	del c:\windows\system32\SPNetAuth.dll
	del c:\windows\system32\WBISecDoc.dll
	del c:\windows\system32\WBSecdoc.sys
	del c:\windows\system32\EfsCbCt.dll
	del c:\windows\system32\EFSControl.dll
	del c:\windows\system32\EfsUser.dll
	del c:\windows\system32\ScanEncrypt.dll
	del c:\windows\system32\SecureDoc.dll
	del c:\windows\system32\WBScanEncrypt.exe
	del c:\windows\system32\SecDocExp.dll
	del c:\windows\system32\RecorverModule.dll
	del c:\windows\system32\ExamAppr.dll
	del c:\windows\system32\EFSCtlExp.dll
	del c:\windows\system32\SDocShll.dll
	del c:\windows\system32\SPSVerf.dll
	del c:\windows\system32\SPCSDoc.dll
	del c:\windows\system32\SPTSMgr.dll
	del c:\windows\system32\SPCTStor.dll
	del c:\windows\system32\SPTSHK.dll
	del c:\windows\system32\WBTSMnt.dll
	del c:\windows\system32\WBTSDrv.sys
	del c:\windows\system32\SPNetPatrol.dll
	del c:\windows\system32\SPTSDropHandler.dll
	del c:\windows\system32\SPSens.dll
	del c:\windows\system32\ScanCheckFile.exe
	del c:\windows\system32\SPFParse.dll
	del c:\windows\system32\SPSdMgr.dll
	del c:\windows\system32\sprun.exe
	del c:\windows\system32\SDocEqualShll.dll
	del c:\windows\system32\SDocHighShll.dll
	del c:\windows\system32\SDocLowShll.dll
	del c:\windows\system32\SPCTbfps.dll
	del c:\windows\system32\SDocOrdLvlShll.dll
	
	pause
	
	重启系统后，在操作系统选择界面，进入虚拟软驱，利用其引导进入DOS下；
	2、在纯Dos下，找到C:\WINDOWS\system32\CSSSP\文件夹，用命令delete之（或rename之）；
		并执行上面创建的c:\1.bat；
	3、重启系统，正常进入Win XP下，运行services.msc，进入服务管理，将WaterBox Client Security Patron Service服务设为“禁用”;
	4、在XP下，运行msconfig ,启动,找到SPMCenter启动项，去掉前面的勾，并“应用”。目的是不将其作为自启动项。
	5、在XP下，删除以下注册表项：
	HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Shared Tools\MSConfig\startupreg\SpMessageCenter
	HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run 下 SpMessageCenter项
	HKEY_CURRENT_USER\Software\Microsoft\Windows\ShellNoRoam\MUICache 下 C:\WINDOWS\system32\SpmCenter.exe项
	HKEY_CURRENT_USER\Software\NVIDIA Corporation\Global\nView\WindowManagement\spmcenter
	[HKLM\SYSTEM\CurrentControlSet\Services\WBTS]
	[HKLM\SYSTEM\CurrentControlSet\Services\NPF]
	[HKLM\SYSTEM\CurrentControlSet\Services\SpNdis]
	[HKLM\SYSTEM\CurrentControlSet\Services\SPTdi]
	[HKLM\SYSTEM\CurrentControlSet\Services\SPCdr]
	[HKLM\SYSTEM\CurrentControlSet\Services\SPRegFlt]
	[HKLM\SYSTEM\CurrentControlSet\Services\SPPsFlt]
	[HKLM\SYSTEM\CurrentControlSet\Services\SPFile]
	[HKLM\SYSTEM\CurrentControlSet\Services\SecPatron]
	
	6、重新启动XP，检验效果。并用超级兔子之类的工具清理系统和注册表垃圾文件。

*/
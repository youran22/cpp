/*

ģ����޸���ʾ��
��Ҫ������ʹ�ã�
dlg�ļ�����д����
�Ի����޸����̣�
��������⣺
������ʹ�ã�



ģ����޸���ʾ��
		�������������\\192.168.10.115\software\pc_toolsĿ¼
	����Ҫ�������ո�ʽ�����������
		printf("%15E", PI)    ���"3.14159265E+000"
		printf("%.15E", PI)   ���"3.141592653589793E+000"
		printf("%.15G", PI)   �����
		printf("%15G", PI)    �����
		
	��������ԭ���DOS�����������ԡ�C���ԣ�������C++����������д�淶�����ݽṹ������ԭ������ϵͳ����������硢���ݿ�ԭ��������ʽ���������ԣ�����C++�����ܹ�����

	��ѧϰ����ߵ��Ҹ棺
		����С�Ժ��֣����ô��ԡ��۾����죬������ѧ���̣�
		�۹�ǧ�鲻���ֹ�һ�飡
		�鿴ǧ�в�������һ�У�
		����ǧ�в��絥��һ�У�
		����Դ����ǧ�в��絥��Debug���Ӧ���һ�У�
		����Debug���Ӧ���ǧ�в��絥��Release���Ӧ���һ�У�
		���ᵥ��Release���Ӧ��ࣿ�����뵥��Release��C/C++����Ƭ�ϵ�ǰ����ʱ��һ��DebugBreak();�ؽ����У�Ȼ����IDE�����С���һ�����Ҳ�����������
		
		VC����ʱ��Alt+8��Alt+7��Alt+6��Alt+5,�򿪻�ര�ڡ���ջ���ڡ��ڴ洰�ںͼĴ������ڿ�ÿ��C��Ӧ�Ļ�ࡢ����ִ�в��۲���Ӧ��ջ���ڴ�ͼĴ����仯��������һ�鲻��ɶ����������
		��VC��˵����ν������ʱ�����Ǳ�������ͨ���Ժ󣬰�F10��F11������ִ��һ���Ժ��ʱ�򣬻�����ĳ�а�F9���˶ϵ��F5ִ��ͣ�ڸöϵ㴦��ʱ��

	����ǭ 2017-01-05 20:57:18
		@ALL��������־�ּ�����
		* ���������wlog2()�����������÷����ڸ��õĵط��ú�����
		* ����warn_log()��info_log()��debug_log()��verbose_log()�Ա����ԭ�д��룻
		
		���⣬Ŀǰ��������WLOG_LEVEL_THRESHOLD��Ĭ��ֵ�ƺ�������Ҫ�����
	����ǭ 2017-01-05 21:03:29
		@���ǲ���ע��gnss02_transform_test�в��ֲ��������Ѿ�ʧЧ
		�����ƺ�֮ǰû�г�ʼ��nMethod��Ա�ĳ������������Գ�ʼ���󣬽���е�����
	����ǭ 2017-01-05 17:17:39
		wlog()������ǿ��
		* Ӧ����wlog2()����ȡ��wlog()�������Ա�ָ��levelֵ��
		* levelָ����־���𣬶�����{0:����,1:����,2:��Ϣ,3:����,4:��ϸ}//������Ϊ0�������������س̶��½���
		* �û�������WLOG_LEVEL_THRESHOLD��������־�����ϸ�̶ȣ�
		* ���磬�趨WLOG_LEVEL_THRESHOLDΪ2����ֻ��levelֵΪ{0,1,2}��wlog2()������������־���������ƣ�
		* WLOG_LEVEL_THRESHOLDĬ��ֵΪ2��
		* wlog()���˻�Ϊwlog2()��һ�����ã�����levelֵΪ2��
		����ǭ 2017-01-05 17:27:17
		Ҳ����˵��
		* �����д����Ӧ����wlog2()����Ҫ����wlog()
		* ֮ǰ�ɵ�wlog()��������ع�����������ʱ��Ӧ��Ϊ����wlog2()����ָ��ǡ����levelֵ��
		* ������Ƶ�ʷǳ��ߵĵط���Ӧ�ø��Ƚϸߵ�levelֵ�������������ƿ����//����Ƶ�ʱȽϸߵĵط���Ӧ��Ҫ���Ƚϸߵ�levelֵ��
			
	������ǭ��  2017-01-04  09:37:42
		gnss01_test_utils�����TestFunction���ͣ�
		* �÷���gnss02_transform_test/TranParm7CalcTest.cpp��ʾ��
		* �����ƶ���֮��
	������ǭ��  2017-01-03  15:32:58
		gnss05_test_tools�ѸĻ�southgnss��
		
		�����¼�������ĵ���ǰ�����������¡�
		* ģ��������
		* ģ����ĸ��ֿ�ȥ����
		* ʹ�ù㷺��ȫ�ֺ��������Ͷ��壻
	��ҫ 2017-01-09 11:23:08
		�ҶԹ���֮�ǶԻ������DialogExtBase����һ���Ƚϴ�ĵ�����
		����������ӿ�IBasicDialog,�ýӿ�ֻ��һ��������pop���Ժ�����չ����DialogExtBaseֱ�Ӽ̳�
		Ŀ�ģ����д�DialogExtBase�̳еĶԻ���Ŀǰ��ϵͳ���жԻ��򣩶�ӵ�ж�̬ע������������пɲ����߼�������ֱ�������Ի����²��ɲ��ԡ�
		
		��ҫ 2017-01-09 11:31:53
		����Ժ���ģ̬�Ի���Ի������²��ɸ��ã�������ExtensibleFactory�Ǽǻ������������ӿ�������ԶԻ���������͵�ֱ��ǿ��ϡ�
		����μ�StakeLineSettingsDialog.cpp���޸ģ�
	��һ��buildbot��ôforce build 
		buildbot ���Ͻǵ�¼
		�˺� gnss
		���� 1234567a
		
		��¼���builder
		Ȼ�󿴵����¶���
		
	����ҫ��  2017-01-11  09:02:27
		ע�ⲻ��¼û��force build ��Ŀ
	�����ǿ��  2017-01-11  11:20:40
		���ע��һ�£����ڰ�wlog�ļ������ΪWLOG_DEBUG��ֵΪ3��Ĭ�ϴ��log�ļ���ΪWLOG_INFO��ֵΪ2��
		����������Ĵ󲿷ֵ�log�������ᱻ������������ɣ����������ߣ����ٵĸо��������ԡ�
	�����ǿ��  2017-01-11  11:22:20
		������WLOG_DEBUG�����log���޸�../etc/gnss00_utilities/gnss_environment_variables.cfg���ļ���
		��WLOG_LEVEL_THRESHOLDֵΪ3���ɡ�
	�����ǿ��  2017-01-11  11:22:43
		�õ���Ӱ��ϴ����Ҹ��´����Լ�sdk
	�����ǿ��  2017-01-11  11:23:39
		�Ժ���Ҫ��logʱ��Ҳ������ϸ����һ��log����
	�����ǿ��  2017-01-11  15:29:24
		������wlogĬ�ϼ������WLOG_INFO���������ʹ��ָ������ķ�������error_log��info_log��debug_log�ȣ���ʹ��wlog������
	�����ǿ��  2017-01-11  15:30:15
		���׹淶��
		*   ����ʹ��error_log
		*   ���ȶ����ֵģ�ʹ��verbose_log
		*   �����ȶ����ֵģ�ʹ��info_wlog
	������ǭ��  2017-01-11  15:35:23
		== ����wlog()������Ĺ��� ==
		1. wlog()�ȼ���wlog2(WLOG_LEVEL_INFO)
		2. error_log()����д��WLOG_LEVEL_ERROR(0)�������־��
		3. �硰���������Ի��������û��ض������������ڵ���־��Ӧ����info_log()������wlog()����
		4. ���׸��ֵĳ�����Ϊ�о���;��д����־��Ӧ����verbose_log()��
	����ҫ��  2017-01-11  16:43:49
		wlogϵ�к�������������ǿ������WARNING���߸����ؼ��𶼼��ϣ����塣
	���ǿ 2017-01-18 17:14:06
		��λ����Ҫ�޸ģ�IResourceManager�ṩ���������ӿڣ�������Դ��SurvStarUI�ṩ������SurvStar���̡�
		��ʾ��������Դ��һ��
	��������
		else if(!csz_stricmp("ask_transform", callback_type))
		{
		//_changeAllLable(dicUI);
		// ת��
		_calcCoordTrans(dicUI);
		}
		else if (!csz_stricmp("ask_tra_rev", callback_type))
		{
		//_changeAllLable(dicUI);
		//��ת��
		_calcCoordTrans(dicUI, 1);
		}
		
		������ ����ת�� ��_changeAllLable(dicUI)�����ܲ���ȥ�����о�û�õ�����?
	
	��ҫ��
		��λע�⣺warn_log��error_log���ɻ���ȡ����Ҫ�ı�Ҫ����������߱��������Ѿ��޷���ִ����ȥ���쳣��ǰ��ֻ��д��log�������û���κ�Ӱ�졣
	����ǭ 2017-02-06 15:02:45
		һ��Ҫע��error_log()��warn_log()������
		
		���ֻ�밴WLOG_ERROR����д��־���������쳣����Ӧ����wlog2()������error_log()
		����Ӧ�ò���Ҫ��ô���ɡ���

��Ҫ������ʹ�ã�
	�ļ��Ķ�ȡ��
	���õĴ���
		ISystemSettings &settings;
		m_dlgMgr(*settings.getUiManager().getDialogManager());
		�Ϸ����߼����Ҫ�������exe�ļ���
			E:\gnss\southgnss_sdk\win32bin\res\config.ini:��Ҫ�ڴ�ini�ļ��µģ�[enable_tools]�ڵ㰴˳�����exe���֣�
			E:\gnss\southgnss_sdk\win32bin\res\string.txt��ͬʱ��Ҫ�ڴ�ini�ļ��µģ�<!-- ������������ֶ� -->��<!-- ������������ؼ������ֶ� -->�������Ӧ����Ϣ��
		
	�ַ�����c����
		next_word3��
			//��һ���ַ����а�ָ���ָ�����ȡһ�����ʵ���һ��������buf�У�Ҳ����ָ���ַ���ǰ�沿�֣�
			//���ص��ǽ�ȡ���ֽ�����ֱ��ָ��+�Ϳ��Ի�ȡ��ȡ�󣬺����ʣ�ಿ�֣�
			example��
				const char *p = csvEscapes;
				p += next_word3(word, p, ',', sizeof(word));
		next_word4��
		
		TextConverter;
			�Խӿ�ITextConverter�Ĳ�����װ��
				ITextConverter
					�ӿ��ࣻ
					����1��
					class TextConverterImp:public ITextConverter//�ڴ˿ռ��namespace TextConverterImp_NS
						wchar_t wc = 1;//unsigned short 
						const char *p = (const char*)&wc;//const char * = ǿת��ַ��
						const int flag = sizeof(wc)+p[0];//wc�Ĵ�С+��һ���ֽ�����
				ϵͳ������ Դ�����ļ� Я���� �ַ������� ���� �ļ�·��ʱ��Ӧʹ��gbk_localeת������
					TextConverter gbk_locale("GBK", "char");
				sqlite3_open(wsp, &db)Ҫ��wsp����UTF-8���룬������Ҫʹ��locale_utf8ת������
					TextConverter locale_utf8("char", "UTF-8");
			��const char *srcEncoding, const char *destEncoding��//���Ϊ������ϵͳ����Ĳ�����(�ܹ��ұ�׼��GB/T2312-1980,GB/T18030-2000����Ӱ�죬windows�����û�һ���趨localeΪGBK����)
			//Դ�ַ��������ַ����룬����"GBK"��Ŀ���ַ��������ַ����룬����"UTF-8"
			//�ı�ת���֧࣬�ֽ�"GBK"������ַ���ת��Ϊ"UTF-8"������ַ�����
			TextConverter convW("wchar_t", "");
			ITextConverter &conv = convW.getInnerObject();
			csz_strncpy(buf, conv.convert((const char*)m_strKey.GetString()), buf_size);//�ַ����Ŀ�����
				//��wchar_t���ַ���ǿתconst char*ʹ�ã�//����Ҫת�����ַ���������ת������ַ�����
			
			//����ʹ�ã�
			TextConverter _conv("UCS-2-INTERNAL", "");
			ITextConverter &conv(_conv.getInnerObject());
			while(a < 200)
			{
				wchar_t *w=L"�������ӷ���һ��ʱ���û����ȷ�𸴻����ӵ�����û�з�Ӧ�����ӳ���ʧ�ܡ�\n";
				const char *v = conv.convert((const char*)w);
				//thread_sleep(500);
				a++;
			}
			
			//�����÷���
				char utf8[100];
				TextConverter _utf2gbk("UTF-8", "GBK");				
				ITextConverter &utf2gbk(_utf2gbk.getInnerObject());
				
				TextConverter _gbk2utf("GBK", "UTF-8");
				ITextConverter &gbk2utf(_gbk2utf.getInnerObject());
		
				csz_strncpy(utf8, gbk2utf.convert("shp_files/�������.sqlite"), 100);
				CPPUNIT_ASSERT_EQUAL(25, gbk2utf.getSrcLength());
				CPPUNIT_ASSERT_EQUAL(29, gbk2utf.getResultLength());
		
				AUTO_TEST_ASSERT_STR_EQUAL("shp_files/�������.sqlite", utf2gbk.convert(utf8));
				CPPUNIT_ASSERT_EQUAL(29, utf2gbk.getSrcLength());
				CPPUNIT_ASSERT_EQUAL(25, utf2gbk.getResultLength());
		
				csz_strncpy(utf8, gbk2utf.convert("�Ϸ�PK"), 100);
				CPPUNIT_ASSERT_EQUAL(6, gbk2utf.getSrcLength());
				CPPUNIT_ASSERT_EQUAL(8, gbk2utf.getResultLength());
		
				AUTO_TEST_ASSERT_STR_EQUAL("�Ϸ�PK", utf2gbk.convert(utf8));
				CPPUNIT_ASSERT_EQUAL(8, utf2gbk.getSrcLength());
				CPPUNIT_ASSERT_EQUAL(6, utf2gbk.getResultLength());
				�����ף�
						StreamFormatter fmtFile;
						os_printf(fmtFile, "GPS-RTK���߿���׮��%02d%02d.xls", time.wHour,time.wMinute);
						TextConverter _conv("GBK","wchar_t");//����һ��gbk��wchar_tת���Ķ���
						ITextConverter &conv(_conv.getInnerObject());
						char buf[128]={0};
						//����convert������Ҫת���ַ��������ȣ�ת����
						//csz_strncpy(buf, conv.convert(fmtFile.getBuffer()), sizeof(buf));
						int nSize = sizeof(buf);
						const char *pchFile = fmtFile.getBuffer();
						const char *pFile = conv.convert(pchFile);
						csz_strncpy(buf, pFile, sizeof(buf));
						//��δ�����ôת�����ˣ�
		Dictionary�÷���
			dictionary_merge��				
				Dictionary dicMid;
				dictionary_merge(dicMid.getInnerObject(), dicIn, 1);
				dictionary_merge(dicMid.getInnerObject(), dicNew, 1);	
			һ����÷���������
				Dictionary _dic;
				IDictionary &dic = _dic.getInnerObject();//ע��&���ţ�
			
			IDictionary���÷���
				��set��getʹ�ã�������ΪʲôҪ�������أ�
				StreamFormatter fmt;
				dictionary_to_csa(fmt, dic);//ת���ɶ��ŷָ��ַ���
			dictionary_copy_spec
				Dictionary _dic1(0, "key1=1, b=2, c=3, key4=4");
				IDictionary &dic1(_dic1.getInnerObject());
				Dictionary _dic2;
				IDictionary &dic2(_dic2.getInnerObject());
				
				//��"a=key1,b,d=key4"�����ֵ䣺�Ӹ��ֵ��е�value�л�ȡdic1��Ӧ��key��valueȻ��ֵ��
				dictionary_copy_spec(dic2, dic1, "a=key1,b,d=%s", "key4");
			dic_get_r8
				dic_get_r8(initUI,"edit_lat","0.0");//������Ĭ��ֵ�����Ҳ�����ʱ�׳��쳣
			���ֵ��л�ȡֵ��
			dic_get_csz
				array_strncpy(gcp.name, dic_get_csz(dicLine, "name", ""));//Ҫע����������Ҫд��"0"
				parse_dot_dms(dic_get_csz(dicLine, "lat1", "0"));
			//��ӡdic�ķ�����
			dictionary_get_keys��
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
				//���ã�
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
				//���ã�
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
				//���ã�
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
		char *��
			const char *fn
			if (fn && fn[0])
			{
				parsePath(fn);
			}
			
			array_strncpy(gcp.name, dic_get_csz(data, "szName", ""));
		IOutputStream
			//�ֽ���д�ӿ�
			class IOutputStream: public IStreamBase
		StreamFormatter
			//Ϊʲôos_print����ֱ��ʹ�ã�ӦΪʹ����ǿת��
			//�˽ӿ�ֻ���𴴽����ͷŶ���ʹ�õ�ʱ����ʹ��IStreamFormatter����ô����Ӧ��ʹ�����أ�//ʹ��IStreamFormatter����
			//��ʽ��������ַ���������StreamFormatter��IOutputStream���䣻
			//IStreamFormatter�ӿڵĴ������ͷŷ�װ�ࣻ
			Ĭ�ϵĻ����
			IStreamFormatter
				class IStreamFormatter:public IOutputStream
				�ӿ��ࣻ
				����1��
				class StreamFormatterImp:public IStreamFormatter
				
			StreamFormatter fmt;
			os_printf(fmt, "%s", key);
			const char *chi = fmt.getBuffer();			
					
			StreamFormatter fmtKeys;
			dictionary_get_keys(fmtKeys, dicNew);		
			const char *csvKeys = fmtKeys.getBuffer();
			
			StreamFormatter m_fmtName;//����һ��StreamFormatter�Ķ���
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
			
			//����Ŀ���ֱ��ʹ�ã�����ΪʲôҪ�м�ISteamFormatter��
			StreamFormatter _fmtFile;//Ӧ���ǻ�ȡ�ڴ�ռ䣿
			IStreamFormatter &fmtFile(_fmtFile.getInnerObject());//Ҫ���&
			os_printf(fmtFile, "os_file:path=%s", chFileName);
			const char *pFilePath = fmtFile.getBuffer();
				//���ۣ��󲿷�ʹ�ö���ֱ��ʹ�õģ�
			//�����Ƿ����ֱ��ʹ��StreamFormatter?//�Ƿ����ֱ��ʹ��=�ţ�//���ۣ������ԣ�
			void test_StreamFormat1()
			{
				StreamFormatter fmt1, fmt2;
				os_printf(fmt1, "%s", "��ã�");//Ϊʲô����ֱ��ʹ�õģ�
				const char *p1 = fmt1.getBuffer();
				AUTO_TEST_ASSERT_STR_EQUAL("��ã�", p1);
		
				os_printf(fmt2, "%s", "����̶��");
				fmt2 = fmt1;
				const char *p2 = fmt2.getBuffer();
				AUTO_TEST_ASSERT_STR_EQUAL("��ã�", p2);
			}
	
	�ļ��ࣺ
		StreamContainerW
			��װIStreamContainer��Ĵ������ͷţ�
				IStreamContainer
					�ӿ��ࣺ//��ȡ�����������������������
					//����û������̳У���
				class InputFileStream : public IInputStream
					class IInputStream: public IStreamBase
				class OutputFileStream: public IOutputStream
					class IOutputStream: public IStreamBase
			//���ļ�����ȡ�ļ����ݣ�
				StreamContainerW _c1(csa1, 0);//csa1���ļ�·���� 0Ϊ����������1Ϊ�ӷ�������
				IStreamContainer &c1 = _c1.getInnerObject();
				IInputStream &is1 = c1.getInputStream();
				char buf1[1000]={0};
				while(!is1.eof())
				{
					is_get_line(buf1, sizeof(buf1), is1);
				}
			//���ļ�д���ļ�
				StreamContainerW _mapContainer(schema, 0);
				IStreamContainer &mapContainer = _mapContainer.getInnerObject();
				IOutputStream &os = mapContainer.getOutputStream();
				os.writeBytes(c1, strlen(c1), 1);
				os.fseek(4 * 1024 * 1024 - 10, SEEK_DATUM_SET);
				
				os.writeBytes(c2, strlen(c2), 1);
				os.writeBytes(" normal again!", 14, 1);
			//����ļ��Ƿ���ڣ�
				file_system_check_file��path����
			//ɾ��
				file_system_delete_file(fn2);
			//����
				file_system_copy_file(fn1, fn3);;
			
				
		IFileGroup
			�ӿ��ࣺ//���ڷֽ��ļ�·��ΪĿ¼���ļ�������չ���������֡�ͬʱ�ṩ��ԭ���ļ�·������������������ļ�·���ķ�����
			����1��
			class FileGroupImp: public IFileGroup
			FileGroupW
				��װIFileGroup�Ĵ������ͷŽӿ��ࣻ
			ʹ�ã�
				const char *baseFilePath��
				FileGroupW _grp(baseFilePath);//1���������ļ�·��ֱ�ӹ��죻2��Ҳ����ֱ�ӵ���parsePath����ת��·����
				IFileGroup &grp(_grp.getInnerObject());
				
				FileGroupW _m_grp;
				IFileGroup &m_grp;
				m_grp.parsePath("d:\\test\\for\\good.txt");
				AUTO_TEST_ASSERT_STR_EQUAL(".txt", m_grp.getExt());
				AUTO_TEST_ASSERT_STR_EQUAL("good", m_grp.getBase());
				AUTO_TEST_ASSERT_STR_EQUAL("d:/test/for/good.bat", m_grp.compositeFileName(".bat"));//�������·������
				AUTO_TEST_ASSERT_STR_EQUAL("d:/test/for/bad.bat", m_grp.compositeFileName("bad", ".bat"));
				
			�ļ�·����׼����
				char buf[1000];
				file_system_path_standardization(buf, sizeof(buf), "d:\\dir1\\/dir2\\\\dir3\\////dir4")��
				AUTO_TEST_ASSERT_STR_EQUAL("d:/dir1/dir2/dir3/dir4", buf);
			ö���ļ����µ�ָ���ļ���
				char fn[500];
				process_resolve_path(fn, sizeof(fn), "$(GNSS_TEST_DATA_DIR)/file_system_test_data/");
				
				StreamFormatter	_fmtJobFiles, _fmt2;
				IStreamFormatter &fmtJobFiles(_fmtJobFiles.getInnerObject());
				IStreamFormatter &fmt2(_fmt2.getInnerObject());
				const char *csv1 = 0, *csv2 = 0;

				file_system_enumerate_files(fmtJobFiles, fn, "*.txt", -1);//���������fmtJobFiles��
				csv1 = fmtJobFiles.getBuffer();//�ý�����ԣ��ŷָ���
				
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
					//����E:\gnss\southgnss_sdk\etc\SurvStar\cn\surv_star_strings2.ini���ļ��е�tool_trans_params_edit��title����dialog_title_keyΪkey�����ݣ����ظ�ֵ��
		��������ַ�����//����ַ���������"-78.5959999"��ʾ-78��59��59.999��
			double parse_dot_dms(const char *ddms);//����ʮ���ƣ��������ַ���"78.3000000"��Ӧʮ���ƶ�78.5
		
		wch_to_mb??	

	*����ϰ�ߣ��粻������Ա�������������ٹ����ĳ�Ա����������cstring���ӿڣ�ͨ�������Ի�����Ϊȷ����Ҫ�Ĳ����ȡ�
	*�ɸ��öԻ�������Ҫʹ�ÿɸ��öԻ���Ļ��ƺϲ��Ϸ����߼���SurvStar�е���ͬ���ܶԻ���

dlg�ļ�����д����
	�߼���
		��Ҫ�ڵ��ô�������ӻص������Լ��ص�������ʵ�֣�
	�����ļ�������
		$�����ֵ�����ȡֵ��
		#:��ʱֻ��������ʹ�����ȡֵ�ģ�
		&:
		@:�������ļ�����ȡֵ��
			//@label1�Ǵ������ļ��л�ȡ��ֵ��E:\gnss\southgnss_sdk\etc\SurvStar\cn\surv_star_strings2.ini�е�[broken_chains]���ֶε�ֵ��
			//�����İ��Ӣ�İ��Ҫһһ��Ӧ���޸Ĳ�����鷳��
		
		�����SurvStarģ�飬���dlg�ļ�֮����Ҫ��debug��release�����汾�ĵط���Ҫ��ӣ�
			����Ŀ�����еģ�Deployment->Additional Files:����ĸ˳����Ӹ�dlg�ļ���	
	��һ������ͷ
		dialog_title:@dialog_name;//����Ի������֣�
		title_name:broken_chains;//E:\gnss\southgnss_sdk\etc\SurvStar\cn\surv_star_strings2.ini�Ľ�����
		dialog_width:200;//�Ի����Ⱥ͸߶�
		dialog_height:200;
	�ڶ���������
		group:v;//��//����
		{	
			group//��
			{
				control:label;fldname:label1;defaultValue:@label1;//control�����ͣ�fldname����������Ĭ��ֵ������ı�����ֵ��
				control:textedit;fldname:bMileage;							
			}
			group//��
			{
				control:label;fldname:label2;defaultValue:@label2;
				control:textedit;fldname:aMileage;
			}
		}
		group//�У�
		{
			control:pushbutton;fldname:ok;on_click:accept;showname:@ok;	//���ͣ�pushbutton��fldname����������on_click��accept������¼����ɽ��ܣ�����ʾ���֣���������ֵ��					
			control:pushbutton;fldname:cancel;on_click:reject;showname:@cancel;
		}		
	���������������ļ�������Ӧ���ֶ���ֵ��E:\gnss\southgnss_sdk\etc\SurvStar\cn\surv_star_strings2.ini
		���磺
			[south_tools_import_matching_file]
			dialog_name = "�ļ�ƥ�䵼��"
			knowed_plane_coord_data_label = "��֪ƽ����������"
			plane_coord_open_file_btn_label = "��"
			wgs_data_label = "WGS84����"
			wgs_open_file_btn_label = "��"
			import_btn = "����"
			cancel_btn	= "ȡ��"
		
	���ÿؼ���
		label��
			example:
				control:label;fldname:time_zone_label;defaultValue:@time_zone_label;//survstar_config_general_set.dlg
				//ע�⣺����ؼ�һ��Ҫfldname����Ϊû�б������Ļ��������������checkbox���ÿؼ��������������޷���ʾ��
				//�������ﲻ����showname����ؼ��֣�ֻ����defaultValue��
				//������������е㲻һ����
		textedit��
			example��
				control:textedit;fldname:ElevationMask;defaultValue:0;keyboard:#KeyBoardUsage;numberflag:0;
				control:textedit;fldname:IncrementStep;defaultValue:0;keyboard:#KeyBoardUsage;numberflag:0;
			//textedit:��û��showname����ؼ��ֵİɣ�����Ϊ������ʾ��
		pushbutton��
			example:
				control:pushbutton;fldname:ok;showname:@ok;on_click:accept,call_back;call_back:ok;
				control:pushbutton;fldname:cancel;showname:@cancel;on_click:reject;
				control:lineedit;fldname:A2;showname:@label_A2;keyboard:#KeyBoardUsage;numberflag:0;regex:.+;notice:@note_A0;height:45;label_size:60;visiable:$nMode&3;
				//ע�⣺����ؼ�������$�����޸İ�ť�����ƣ���
				
		checkbox:
			example:
				control:checkbox; fldname:UseVoicePrompt; showname:@prompt_checkbox;height:50;//survstar_config_general_set.dlg
				//ע�⣺һ��Ҫ����fldname����������������������ؼ��ҹ�����
		combobox:
			example: //û��showname���ѡ�
				control:combobox;fldname:TimeZone;fill_pairs:@time_zone_all;//survstar_config_general_set.dlg
					//fill_pairs:@time_zone_all;�����ļ���������ȱʡֵ��
						�磺time_zone_all = "0=-12,1=-11,2=-10,3=-9,4=-8,5=-7,6=-6,7=-5,8=-4,9=-3,10=-2,11=-1,12=0,13=1,14=2,15=3,16=4,17=5,18=6,19=7,20=8,21=9,22=10,23=11,24=12"//surv_star_strings2.ini
				control:combobox;fldname:tool_calcute_triangle_method_select;fill_pairs:@tool_calcute_triangle_method_select;on_click:call_back;call_back:select;
		linectrle��	
		lineedit:
			example��//transform
					control:lineedit;fldname:cogo_calc_coord_pointname_edit;height:50;showname:@pointname_text_showname;keyboard:#KeyBoardUsage;numberflag:1;defaultValue:POINT;label_size:150;
					control:lineedit;fldname:cogo_calc_coord_north_edit;height:50;regex:^(-)?[0-9]+(\.[0-9]+)?$;notice:@north_edit_notice;showname:@north_edit_showname;keyboard:#KeyBoardUsage;numberflag:0;label_size:150;defaultValue:0;
			showname��ָ��ǩ�������磺���֣�xxxxxx??
		radios: //
			example:
				control:radios;fldname:radios_select;fill_pairs:@import_file_type_selcet;on_click:call_back;call_back:select;height:120;groupby:h;
				//fldname:radios_select;//�ÿؼ��ı�������initDic.setValue("radios_select", "0");Ĭ��ѡ���һ�
				//fill_pairs:@import_file_type_selcet:���ѡ�����ʽ��"0=�߶�,1=Ԫ��,2=����"
		tablewidget: //fldname:ע�ⲻ���ظ����ظ��Ļ��������⣻
			example:
				control:tablewidget;width:480;fldname:ctrl_point_list;fill_pairs:$ctrl_point_list_fill_pairs;headers:$ctrl_point_list_headers;
					//$Ӧ���Ǵӳ����еı����л�ȡֵ�ã�
		on_click:(���������Behaviour������һ���Ļ����ᵼ�¶Ի���ĵ����ť��Ӧ���ˣ��ر��Ǳ�������ͬ�ĵ����ť)
			control:pushbutton;fldname:ok;showname:@ok;on_click:accept,call_back;call_back:ok;
				//���accept�������ǣ����������Ի���
		�޸ĶԻ�������
			dic_set_value(m_dicUi, "dialog_title", "%s", "���������");
	�����﷨��
		������ʽ��regex:^(-)?[0-9]+(\.[0-9]+)?$;
			regex:.+;
			//http://www.cnblogs.com/light169/archive/2006/10/18/532347.html
		showname:@point_north;
		fldname:line1_start_label;
			//������fldname���ֵ���Լ����key����//Ҳ���Ե������������Դ������洫����ֵ��
			//@label1�Ǵ������ļ��л�ȡ��ֵ��E:\gnss\southgnss_sdk\etc\SurvStar\cn\surv_star_strings2.ini�е�[broken_chains]���ֶε�ֵ��
		on_click:call_back;
			on_click:accept,call_back;call_back:ok;
		call_back:askline1start;
		height:40;
		width:40;
			//2���ְ�ťһ��width=20�ȿ����ˣ�height=
			//textedit�Ŀ��һ��Ϊ��60���ɣ�
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
			//���ؿؼ���&2��Ҳ�����أ���
			//&0;
			//-1:����ʾ�ģ�
			//�����&��ֵ�޹أ�����д���ֵ����1Ϊ��ʾ������Ϊ���أ�
			//$nMode=2;
				//nmode==2��ֵ��ʱ������ʾ������������أ�
		defaultValue:
			//��ָ�ÿؼ��Ķ�Ӧ������ֵ������ʾ�ı�ǩ���֣�
		import_file_type_selcet = "0=@file_format_desc/rtk4_fmt_desc,1=@file_format_desc/dat_fmt_desc,2=@file_format_desc/cot_fmt_desc"
			//0=@file_format_desc/rtk4_fmt_desc����ini�ļ��µ�file_format_desc�ڵ��µ�keyΪ��rtk4_fmt_desc��ֵ��
		space:26;	
�Ի����޸����̣�
		1��dlg��д��
		2����ӻص�������
			IDialogBehaviour���Ի�����Ϊ�ӿڣ���������Ϊ�Ի�����¼�������
			���ڻص���������ֵ�������̣�
				1�����ڴ���ȥ��dicUi�ĳ�ʼֵ��������ʾ�Ի������ؿؼ���ʼ������
				2��һ���ı�ؼ�������ֵ����callback���и�params�������dicUi�ϲ���������dicUi��ͬ�ؼ��ֵ�ֵ��
					//����Ҫע��һ����ǣ���params����dicUi�����ߵ��Ⱥ��ϵҪ�������
		3����ʾ�Ի���
		
	ԭ��

		�����ִ�����̣�
			���-�����ƣ�			
			������Դ��ͼƬ�ȵȣ�E:\gnss\SurvStar\SurvStarUI\res\240_320
				{APPDIR}/Program Files/SurvStar "/Program Files/SurvStar/etc/gnss04_dialogs/"
				"/Program Files/SurvStar/etc/cn/surv_star_menus.xml"
				",bmpDown=job_down.jpg ,bmpUp=job_up.jpg ,caption=���� ,menu=sys_job_man ,rowID=0 ,style=menu_window; 
				,bmpDown=config_down.jpg ,bmpUp=config_up.jpg ,caption=���� ,menu=sys_equip_settings ,rowID=0 ,style=menu_window;
				,bmpDown=survey_down.jpg ,bmpUp=survey_up.jpg ,caption=���� ,menu=sys_surv_menu ,productMask=11/ ,rowID=1 ,style=menu_window;
				,bmpDown=road_down.jpg ,bmpUp=road_up.jpg ,caption=��· ,menu=sys_road_menu ,productMask=11/ ,rowID=1 ,style=menu_window; 
				,bmpDown=tool_down.jpg ,bmpUp=tool_up.jpg ,caption=���� ,menu=sys_tools_menu ,rowID=2 ,style=menu_window; 
				,bmpDown=cogo_down.jpg ,bmpUp=cogo_up.jpg ,caption=COGO ,menu=sys_cogo_menu ,rowID=2 ,style=menu_window;
				,bmpDown=exit_down.jpg ,bmpUp=exit_up.jpg ,caption=�˳� ,cmd_id=2060 ,rowID=2"
			
			ͨ��e:\gnss\southgnss_gui\gnss04_mfc_dialogs\DialogManager.cpp��doModal������Ӧ�����ߡ������
					int ask_by_named_dialog��else if (0 == strcmp(dialog_name, "menu_window"))
					Ȼ�����e:\gnss\southgnss_gui\gnss04_mfc_dialogs\MenuWindow.cpp��show_window_menu������ʾ�˵���
						dicOut��"menu_items,resourceDllName"
				
				ͨ��e:\gnss\SurvStar\SurvStar\MainFrm.cpp��void CMainFrame::processEvent��else if(strcmp(eventName, "MENU_COMMAND") == 0)���������¼���
				ͨ��
				e:\gnss\southgnss\gnss04_survstar\surv_star_command_trigger.h
					surv_star_command_trigger
			e:\gnss\southgnss\gnss04_survstar\ConfigManager.cpp��
				//��ȡ�����ļ���
					var/Configure.ini  var/SurvStar/Configure.ini //��֪��ʲô��
					etc/surv_star_init_params.ini ����etc/SurvStar/surv_star_init_params.ini //
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

��������⣺
	//StakeManage.cpp
		//�����������ߵ����е����ӵ������ֵ䣻//������������Ԫ�ؽ��м��㣻
		eFileError CStakeManage::CalcNodePLine(IPLine &plHor, IPLine &plVer, IPLine &plOver, IDictionary &dicName);
			//���أ���·����ģʽ���ͣ���ͨ��·�����������������������б�������
			//��ˮƽ���ߣ���ֱ���ߣ��������ߣ�,�����ֵ䣩��//��Щ�������Ƿ���ֵ��
				ˮƽ���ߡ���ֱ������գ�
				���ȣ�0.01��//���Ϊʲôȥ0.01����
				ˮƽ�㼯����ֱ�㼯������
				
				// ��ȷ����ʾ��ID�Ƿ��뽻���ID�Ƿ�һ�£�ά����֮ǰ�߼�һ�¡����塣
				//�����ף�������ʶ��ID�뽻���ID��
				���֣�
				������
				
				����Ԫ�ر�����
				������Ԫ�ؽ���ѭ����					
					//����ڼ���Ԫ��,�������һ��Ԫ�ء��㡱--??
					��ȡԪ�أ�
					Ԫ���������ߣ�
						��Ԫ�������ӽ�ˮƽ�㼯��
						�ж�ǰһ��Ԫ�ص����ͣ�//����ǰһ��Ԫ�ص������������֣�
							�㣺
								��������Ϊ"QD";
							�ߣ�
								"Z"
							������
								"YZ"
							Բ����
								"HZ"
					Ԫ�������ǻ������ߣ�
						����ǰһ��Ԫ�ص������������֣�
							�㣺
								"QD"
							�ߣ�
								"ZH"
							������
								"YH"
							Բ����
								"HH"
						//������̼����
						��ȡ�뾶������յ�뾶�����뾶�������յ�뾶��
						��ȡ��� = 2*��ƽ����2*�뾶*����-���ȵ�ƽ������//��ôС��
						��ȡ��� = Ԫ�ص���̣�
						ѭ���жϣ����Ԫ�����+���ȴ�����̣�
							�������ӽ�ˮƽ�㼯��
							��� += �����
					Ԫ��������Բ���ߣ�
						����ǰһ��Ԫ�������������֣�"QD","ZY","YY","HY"
						//������̼����
						//����Բ�����ĵ�
						��������Ϊ��QZ+nQZCount;
						���������Ϊkey��valueΪ��Ԫ�����+���ȵ�һ�㣻
						�����value��ӵ�ˮƽ�㼯
						ѭ���жϣ����Ԫ�����+���ȴ�����̣�//�ⲿ��ʲô����»�
							�������ӽ�ˮƽ�㼯��
							��� += �����
				//�յ�
				��������:"ZD"
				������Ϊkey��value����ΪԪ�����+Ԫ�س��ȣ�//�յ��ֵ=Ԫ�����+Ԫ�س��ȣ�
				��Ԫ�����+Ԫ�س���)��ӽ�ˮƽ�㼯��

				�����߽ṹ������
				�����������߽���ѭ����
					ȡ�����ߣ�

					��ȡ�뾶��
					��ȡ���ֵ=2*��ƽ����2*�뾶*����-����*���ȣ���//ʲô��ʽ��2*R*D-pow��I/2��2��=D*D��

					���= �����̣�
					ѭ������������<��������̣�
						����������ӵ���ֱ�㼯��
						���+=�����
					���������ֵ��ӽ���ֱ�㼯��

					ѭ������������<=�������յ���̣�
						����������ӵ���ֱ�㼯��
						��� += �����
				//ƽ������̣���������̽������PLINE
				��ȡ��ֱ�㼯��ˮƽ�㼯������

				�����ֱ�㼯��������0��mV=��һ����ֱ�㼯�ĵ㣻

				������ˮƽ�㼯�ĵ�ѭ����
					��ȡˮƽ�㼯�ĵ㣻
					�����ˮƽ��<=��ֱ�� ���� j>��ֱ����-1��
						AddNodePLine(mV, plHor, plVer, plOver);//����ֱ�㣬ˮƽ���ߣ���ֱ���ߣ��������ߣ����м���
						continue��

					ѭ�������ˮƽ��>��ֱ�� ���� j<=��ֱ����-1��
						��ֱ��= ��ֱ�㼯��j����
						AddNodePLine(mV, plHor, plVer, plOver);
						++j��
			���سɹ���

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
		
			// ����ƽ����Ԫ�ؽڵ�
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
			//����ָ����̣�����̣߳�Ȼ��ֱ�����������ߵ�һ���㣿��
			void CStakeManage::AddNodePLine(const double mileage, IPLine &plHor, IPLine &plVer, IPLine &plOver)
			//����̣�ˮƽ���ߣ���ֱ���ߣ��������ߣ���//ֻ�Ǽ���·�����������Ƿ���ȷ��
			//ԭ���Ǵ����ģ��������ӽ����ߣ��򾫶ȴﲻ��������
				
			//���߱�����
			//�̱߳�����
			//�����߽ṹ�壻//���ͣ�ģʽ�������̡��̣߳��յ㣬���µ���̡��̣߳��±�1���±�2��Բ�ģ��뾶;

			//�����������߸�������ѭ����//����߳�
				//��ȡ������Ԫ�أ�
				//���ָ�����С�ڸ������ߵ��յ���� || ��Ų��������һ����������ţ�
					vcurve_mileage_to_hgt//(�����ߣ���̣��߳�);// ������̣�������̵ĸ߳�
					break��//��˼��ֻҪһ���Ϳ����ˣ�

			��ָ�����Ϊx���߳�Ϊy��Ϊһ���㣻
			��ӽ������ߵ㼯�У�

			//����Ԫ�ؽṹ�������Ԫ�����ͣ�����Ԫ�����ͣ����򣬳��ߣ���̣�
			//������Ԫ�ظ�������ѭ����// ����ƽ����Ԫ�ؽڵ�//��ˮƽ���ߵĵ�ͳ������ߵĵ㣿
				//��ȡ����Ԫ�أ�
				//������ߵ����С��=ָ����� ���� ���ߵ����+���ȴ��ڵ���ָ����̣�				
					hcurve_moffset_to_posa// ��ȡԪ����ָ�� ��̺�ƫ��(��Ϊ������Ϊ��) ��Ӧ��  ����ͷ�λ��//ָ�����Ϊ��ָ�����-Ԫ����̣�ƫ��Ϊ0.0��
					��ȡ������
					�Ѹ��������ӽ�ˮƽ���ߣ�
					
					over_height_to_posa//(����Ԫ�أ���̣�����)//��ȡԪ����ָ����̶�Ӧ�ĳ���ֵ(��λ:0.1mm)//ָ�����Ϊ��ָ�����-Ԫ�����
					��ָ����̺ͼ���ĳ�����Ϊx��y��ӽ��������ߣ�
					break��
			//��˼��ֻҪ�ﵽ��һ���Ϳ����ˣ�
CRoadManage
	// ͨ��ָ�� ��̺�б�߳��� �Լ� ��Ӧƫ�ǣ���ȡ��Ӧ�� б�����˵����꣬���ں�/б���������ͼ������ȡ��GetTransectNodeList
	//����̣�б�߳��ȣ�ƫ�ǣ� ��ȡб�����˵����꣩
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
		//ָ�����ΪdL��ƫ��Ϊ0��
		if (!GetXYandAngle(dL, 0, pntNE, dA, overHgt))//��ȡָ�� ��� �� ƫ�� �����꣬ƫ�ǣ����ߣ�
		{
			return false;
		}
		double temAngle = deg2rad(dA+dOffsetAngle-90);//ת��Ϊ���ȣ�//ƫ��+ָ��ƫ��-90��ΪʲôҪ��ȥ90�ȣ�
	
		pntNode.x = pntNE.x + sin(temAngle)*dLength;//б�����˵������x+sin����*���ȣ�����Ϊ��xָ��˳ʱ��Ϊ����������sin����
		pntNode.y = pntNE.y - cos(temAngle)*dLength;
		nodeList->push_back(pntNode);
	
		pntNode.x = pntNE.x - sin(temAngle)*dLength;
		pntNode.y = pntNE.y + cos(temAngle)*dLength;
		nodeList->push_back(pntNode);
	
		return true;
	}



CurveFuntion.h
	bool over_height_to_posa(const tagElementItem& element, const double &length, unsigned short &overHgt)
	// ��ȡԪ����ָ�� ��̶�Ӧ�� ����ֵ(��λ:0.1mm) //���㳬��[0,65535]//ָ��Ԫ�أ����ߣ��� ��̣� ��ȡ�ĳ��ߣ�
		Ԫ�صģ����ȣ���С�� ָ����̣���ֵ < -0.0000001 (ǰ��С) ���� ָ����̽ӽ���0 �������Ͳ�Ϊ�㣻
			�����������
				�򷵻سɹ�//��㲻�Ǻ���⣿��

		//Ҳ����˵���Ԫ�صĳ��ȴ���ָ����� ���� ָ����̽ӽ�0��������Ϊ���ʱ��Ž������¼��㣿

		��ʱ�Ƕȱ�����
		����Ԫ�������жϣ�
			�㣺
				����=0��
				ture��
			�ߣ�
				����=0��
				����true��
			Բ����
				����=Ԫ�صĳ��ߣ�
				����true��
			Բ����
				���Ԫ�ص����뾶<=�յ�뾶
					����=unsigned short��ǿת����Ԫ�صĳ���/Ԫ�صĳ��� * ָ����̣�
				����
					=Ԫ�صĳ���/Ԫ�صĳ���*��Ԫ�صĳ���-ָ����̣���
				true��
	//���ߵĸ�����ʲô��˼����

		
	//ָ�� ��� �� ƫ�� �����ꡢƫ�ǡ����ߣ�
	bool CRoadManage::GetXYandAngle(const double& dL, const double& dOffset, Point2d &pntXY, double &angle, unsigned short &overHgt)
	(dL, 0, pntNE, dA, overHgt)//����̣�ƫ�࣬��ȡ�����꣬ƫ�ǣ����ߣ�
		���߽ṹ����
		��������Ԫ�أ�
			���������
			Ԫ�ص����<=ָ������ ���� ���+���� > ָ������
			Ԫ�ص���̴��ڳ��� ���� Ϊ��һ��Ԫ�أ�
			Ԫ�ص����С��ָ������ ���� Ϊ������һ��Ԫ�أ�
				//�󳬸ߣ�
				over_height_to_posa(tempElement, dL-tempElement.mileage, overHgt);��Ԫ�أ����-Ԫ�ص���̣�Ҫ��ó��ߣ���
				//������ͷ�λ�ǣ�
				return hcurve_moffset_to_posa(pntXY, angle, tempElement, dL-tempElement.mileage, dOffset);
					//// ��ȡԪ����ָ����̺�ƫ��(��Ϊ������Ϊ��)��Ӧ������ͷ�λ��
					//��
		return false��
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
	// ��ȡԪ����ָ����̺�ƫ��(��Ϊ������Ϊ��)��Ӧ������ͷ�λ��//
	bool hcurve_moffset_to_posa(Point2d &pntOut, double &angle, const tagElementItem &element, const double dL, const double dOffset)
		//�����꣬��λ�ǣ�Ԫ�أ���̣�ƫ�ࣩ��
		���磺hcurve_moffset_to_posa��&n,&e, &angle, Ԫ��tagElementItem, dL��̣�doffsetƫ�ࣩ

		����Ƕȱ���dA��
		�����pnt1��
		�������_hcurve_mileage_to_relative_posa( pnt1, dA, element, dL)
			////��ȡԪ����ָ����̵����λ�á���λ�ǣ�//�����˭��λ�ã�
			����false��
		�Ƕ�ת��Ϊ���ȣ�
		���x-ƫ��*sin�����ȣ���
		y+ƫ��*cos�����ȣ���
		
		Ԫ�صķ�λ��ת���ȣ�
		�ԣ�cos���ȣ�sin���ȣ�Ϊ������
		��Ԫ�ص�����͸÷�λ������������������ϵ�ࣻ
		pnt2 = lcs.trans_b(pnt1);/// �ӱ�������ϵ�������ԭ��(����)������ϵ������
		�Ƕ�= Ԫ�صĽǶ�+ƫ�ǣ�
			//Ԫ�ص����꣺��Ԫ�ص�����ϵ�У�
			//��λ����������������ϵ��
		
		true��

	//��̾�����ʲô��
	//��ȡֱ�ߡ�Բ���ߡ�����������һ��������̵����λ�á��Ƕȣ�//��ȡ����Ԫ����ָ����̵����λ�úͽǶȣ�//��ԭ�������꣬�ͽǶȣ�
	static bool _hcurve_mileage_to_relative_posa(Point2d &pnt, double &angle, const tagElementItem &element, const double length)
		//��λ�ã��Ƕȣ�Ԫ�أ���̣�
		����0��
		�Ƕ���0��
		�����Ԫ�س���-ָ�����<-0.00001 (С��ָ����̣� || ָ�����С��0 ���� ���ͣ�=�㣩
			������ͣ�=��//�ѵ�˵Ԫ�س���=��̵�ʱ�����ֱ���ˣ���
				����false��

		�Ƕ�=0.0��
		����Ԫ�ص����ͣ�
			�ߣ�
				���x = ָ����̣�
				����true��//����û�нǶȵģ�
			Բ����
				���뾶�������0��
				�Ƕ�=ָ�����/Ԫ�ص����뾶��
				x = ���뾶*sin�Ƕȣ�
				y = ���뾶*��1-cos�Ƕȣ�//
				true��
			������
				���룺���뾶���յ�뾶������0��
				���룺���뾶С���յ�뾶��//���ǣ���
				��ȡ��㡢�յ�뾶��

				//0�㵽�����յ�����߳���//0����ָ��0,0��λ�ã����߳���ô��⣿0����ǰλ�ã�
				L1��L2��L3��
			��Ϊ������������������ߣ�
				������뾶С��=0.000001��������ʰ뾶Ϊ���������ߣ�
					L2 = ���߳��ȣ�//0���յ� = ���߳��ȣ�
					L3 = ָ����̣�//0����ǰ�� = ָ����̣�
					double C2=R2*R2*L2*L2�����յ�뾶��ƽ��*��0�㵽�յ�����߳�����ƽ������
					_hcurve_moffset_to_pos(pnt.x, pnt.y, 0.0, L2, L3, R1, R2);//��L1=0��x��y��
					��ת�Ƕ�=L3*L3/2*R2*L2;//0�㵽��ǰ��λ��ƽ��/2*�յ�뾶*0���յ����ȳ���
				����������ʰ뾶��Ϊ�����
					����յ�뾶 < 0.000001��
						0�㵽�������߳� = ����Ԫ�س��ȣ�
					����
						0�㵽�������߳� = Ԫ�س���*�յ�뾶/�����뾶-�յ�뾶����
					0�㵽�յ�����߳� = L1 + Ԫ�صĳ��ȣ�
					0�㵽��ǰλ�� = L1 + ָ����̣�

					��ȡ��ʱ����λ�ã�
					_hcurve_moffset_to_pos(dxTem, dyTem, L1, L2, L3, R1, R2);

					��ת�Ƕ� = L3*L3-L1*L1��/2*R1*L1��//0����ǰλ��ƽ����ȥ0�����ƽ�� /2*���뾶*0����㣻

					//���������ͶӰ����㷽��Ϊ0������ϵ��
					double angle = ��L1*L1��/(2*R1*L1);//��㷽��Ƕȣ�//0���������߳�ƽ��/2*���뾶*0���������߳���

					x = cos��angle��*dxTemp + sin��angle��*dyTemp��
					y = cos��angle�� *dyTemp - sin��angle��*dxTemgp��

				true��
			����ѭ����
		����ǵ㣺
			true��
		angle = ��ת���ȣ�temAngle����
		�����Ԫ�����ң�
			y��ֵȡ��ֵ��
			agnleȡ��ֵ��
		true��

	static int _hcurve_moffset_to_pos(double &north, double &east, double L1, double L2, double L3, double R1,double R2)
		
	hcurve_relative_mileage_to_posa(&n,&e, &angle, Ԫ��tagElementItem, dL��̣�lengthƫ��)//��ȡֱ�ߡ�Բ���ߡ�����������һ��������̵����λ��
			
		
	//�����ࣺ��õ���̣��������㣩��ƫ�ࣨ�������ߵķ������ƫ����㷨��
		������ָ��������� ������ ����� ���ߵ� ��̲��ƫ�ࣿ��
	_ease_pos_to_moffset�����ߣ� n��e�� l��̣�doffsetƫ�ࣩ
			��㵽���������������㴦�ķ�λ���������Լ���������֮��ļнǣ�
			�յ㵽������������� �յ㴦�ķ�λ���������Լ���������֮��ļнǣ�
			�е㵽������������� �е㴦�ķ�λ���������Լ���������֮��ļнǣ�
			
			���������ꣻ�����������꣩��
			������꣨���������ڵ�������꣩��
			�����ڵķ���ǣ����������߷��򣿣�
			
			���������������С�������Ϊ0��ƫ��ҲΪ0��
			
			�յ����ꣻ
			�յ㷽λ�ǣ�
			�м�����ꣻ
			�м�㷽λ�ǣ�
			�ж���ƫ��ƫ��
			
			dL1=0.0��			�������߳��ȣ�
			dL2=���ߵ��߳���	�յ�����߳��ȣ�
			dL0��				�е�ࡰ��ʼ�㡱�����߳��ȣ�����
			
			//��һ���������յ�������յ㷽λ�ǣ�
				ͨ���յ���̺�����ƫ��0�������յ������(x2,y2)
				hcurve_moffset_to_posa����// ��ȡԪ����ָ����̺�ƫ��(��Ϊ������Ϊ��)��Ӧ������ͷ�λ��
					�ѷ�λ��ת��Ϊ�ȣ�
					100�ε�����
						��㴦�ķ�λ����������sin��angle1),cos(angle1));
						��㵽������������������������
						��λ�������ĳ���*�����ĳ��ȣ�
						�������ļн� = acos�����/�����ֵ����
						
						�յ㷽λ������������
						�յ㵽������������
						ͬ�ϣ�
						ͬ�ϣ�
						
						�е���߳�dL0 = (0+�����߳�)/2;
						��������Ȼ�1��2����ֵ����С�����н�1-pi��/2 * ���н�2-pi��/2 < 0
							��������Ȼ�1�ľ���ֵ<0.0(7)1 ���� ���н�1-pi��/2 < 1E-8�������н���90�Ĳ�ֵ�����֮һ��
								��� = 0.0��
								ƫ�� = ��㵽������������ĳ��ȣ�
								r1 = ��㵽����������x*cos���������нǣ� - ��㵽������������y*sin���������ļнǣ���
									r1<0 ƫ��ȡ����
								����true��
							����� ���Ȼ�2�ľ���ֵ<0.0(7)1 ���� ���н�2-pi��/2 < 1E-8�������н���90�Ĳ�ֵ�����֮һ��
								��� = �߳���
								ƫ�� = �յ㵽�����������ĳ��ȣ�
								r1 = 
							����� �н�1 < �н�2 
								//��ȡԪ����ָ�� ��� �� ƫ��(��Ϊ������Ϊ��) ��Ӧ �� ����ͷ�λ��
								���hcurve_moffset_to_posa���м��x���м��y�� ����ǣ����ߣ���̣�ƫ����Ϊ0��// ��ȡԪ����ָ����̺�ƫ��(��Ϊ������Ϊ��)   ��Ӧ������ͷ�λ��
									�����תΪ�ȣ�
									�м�㷽���������
									�м�㵽ָ�����������//������
									�������ĳ�����ˣ�
									ƫ�� = �м�㵽������ĳ��ȣ�
									r1 = ��������x*cos������ǣ�-��������y*sin������ǣ���
									���r1<0://ƫ��*-1��//��ƫΪ������ƫΪ����
									
									
							
							����
							
						����
						
					����������
					
					��� = 0.0��
					ƫ�� = 
					����true��
					
				���� false��			
			
	//Բ���ࣺ����ָ��������� ������ ����� ���ߵ� ��̲��ƫ�ࣿ
	_circle_pos_to_moffset�����ߣ�n��e��l��̲doffsetƫ�ࣩ
			��n��e��Ϊ��ǰ�㣻��ָ���㡢�����㣩
			���Ϊ���������������ꣻ
			��һ��������Բ������
				cen��
				Vector2d vec��0�����뾶����//���������y����ѣ�
				vec_rotate��vec�� azimuth����//��ת�ǣ��ȣ�xָ��yָ��ʱ��ʱ��Ϊ����xָ��yָ��ʱ˳ʱ��Ϊ��
				cen = pnt0-vec;//�����Բ�������ˣ�
			�ڶ�����Բ�ĵ����ķ�λ�ǣ�Բ�ĵ�������ķ�λ�ǣ����յ�ķ�λ�ǣ�
				�����ķ�λ�ǣ�
				��������ķ�λ�ǣ�
				��λ��������
					��������ҵģ�
						Բ�ĵ�������ķ�λ�� - �����ķ�λ�ǣ�
					����
						��������
			�����������յ���յ㷽��ǣ�//��ָ����̺�ƫ�����������ͷ�λ�ǵķ�����
				Point2d pnt1��
				�����hcurve_moffset_to_posa��x��y�� ��λ�ǣ����ߣ����ߵ��߳���Ϊ��̣�ƫ��Ϊ0���Ϳ�������յ㣿// ��ȡԪ����ָ����̺�ƫ��(��Ϊ������Ϊ��)��Ӧ������ͷ�λ��
					��Բ�ĵ��յ�ķ�λ�ǣ�
					��Բ�ĵ����ķ�λ�� - Բ�ĵ��յ�ķ�λ�ǣ�--��λ��������
						��������ң���ȡ����
					���ǰ��ķ�λ���������ڴˣ��򷵻�false��
			���Ĳ�������̲��ƫ�ࣺ
				���뾶*��λ��������Բ�ĵ�������-Բ�ĵ���㣩
				ƫ�ࣺ�����㵽Բ�ĵľ��� - ���뾶���ȣ�					
			
	//ֱ���ࣺ����ָ��������� ������ ����� ���ߵ� ��̲��ƫ�ࣿ
	//line_pos_to_moffset�����߻���Ԫ�ؽṹ��n��e��L��̲dOffset��
			n,e����ָ�������ꣻ
			element���������ߵ�������ꣻ
			//��һ������ȡ�յ����꣺
				//���ȣ���ȡԪ����ָ����̺�ƫ��(��Ϊ������Ϊ��)��Ӧ������ͷ�λ�ǣ�
				hcurve_moffset_to_posa���յ������.x,�յ������y����λ��ea��Ԫ�أ�Ԫ�ص���̣�ָ��ƫ��Ϊ0����// ��ȡԪ����ָ����̺�ƫ��(��Ϊ������Ϊ��)��Ӧ������ͷ�λ��
				//��ȡ��㵽�յ�ķ�λ�ǣ�
				//��ȡ��㵽��ǰ��ķ�λ�ǣ�
				//��ȡ��ǰ�㵽�յ�ļнǣ�
			//�ڶ�������㵽��ǰ��ľ���//��Ҫ�������
			//��������ƽ�ࡢ���ࣨ��̲ƫ��������ƽ����ǵ�ǰ���������ϵ�ͶӰ�㵽���ľ��룻
			
	//����ָ��������� ������ ����� ���ߵ� ��̺�ƫ��//ע��һ������̲��ƫ�࣬һ������̺�ƫ�ࣻ
	//hcurve_pos_to_moffset(����Ԫ�ؽṹ��n��e��dMileage��̣�doffsetƫ��)
			//���ݸ����ߵ����ͷ֣��ߣ�Բ�����������ࣻ
			�ߣ�
				//����ָ�����������̲��ƫ��
				//line_pos_to_moffset(���ߣ�n��e�� ��̲ ƫ��)
				���= ��̲�+����Ԫ�ص����
			Բ����_circle_pos_to_moffset�����ߣ�n��e����̲ ƫ�ࣩ
				���= ��̲�+����Ԫ�ص����
			������_ease_pos_to_moffset�����ߣ� n�� e�� ��̲ ƫ�ࣩ//�������ߵķ������ƫ����㷨
				���= ��̲�+����Ԫ�ص����
	Բ����
		//ƫ�����ô���壿//��ʵ�Ǻ�һ�������뵱ǰ���������ĽǶȲ
		//�����ô���壿//�����ʵ����̺�*��̼��+����������
		//ƫ����ô���壿//
		//������ô���壿//����Ҫ���ֻ�������Բ������������ֱ�ߵĳ��ȣ�Բ���Ļ��������ߵĳ��ȣ�
		//������������ô����ģ�//Ҫ��ǰ����������жϳ�ƫ����ƫ�ң�//һ����˵��������ǰ�����򣬴������������ң����ҵ�����������


//RoadPLine_test.cpp
	calc_max_dist(rgMgr, plHor, plVer, 0, 72529)
		a��������������ã���roadMgr��ˮƽ���߶���1����ֱ���߶���2�������̣��յ���̣�ƫ�ࣩ
			locate_with_mileage_offset_pline�����ȣ� ƫ�࣬��׮����ṹ�� ˮƽ���ߣ� ��ֱ���ߣ�
				�����д�ֱ�����ϵĵ����ѭ����//ֻҪ�ҵ�һ������ڳ��ȾͿ����ˣ�
					ȡ��ֱ�����ϵĵ㣨���λ�ȡ��
					�����������ڳ���
						��ȡ��ֱ����ǰһ������ꣻ
						ǰһ�㱱�����볤�Ȳ
						�Գ�����Ϊ��׮�������̣�
						
						��ȡˮƽ���ߵ�ǰһ��͵�ǰ�㣻
						��ȡ���������������֮ǰ�ı������볤�Ȳ���Ϊ��������ģ��
						��ȡ�������ļнǣ�
						ȡ��ֵ��ֵ����׮�ṹ�������ǣ�
						ˮƽ���ߵ�ǰһ��+����ֵ ��ֵ����׮���ꣻ
						
						�����·ƫ�����꣺
							���ƫ��ֵ����ֵ����0.0001��
							 ���ƫ��ֵΪ��������
							 ������ʱ����ת90�ȣ���
							 ����ģֵ��
							 ����ƫ�����ꣻ

������ʹ�ã�

	3��RoadManage.cpp��666-674��
		{{{
			double temAngle = deg2rad(dA+dOffsetAngle-90);//��ת���ȣ���ͨ��ָ����̺�ƫ����õ�Ԫ��ƫ���+ƫ��-90�ȣ���

			pntNode.x = pntNE.x + sin(temAngle)*dLength;//ͨ���ƶ���̺�ƫ����õ�����+sin�Ƕ�*���ȣ�
			pntNode.y = pntNE.y - cos(temAngle)*dLength;
			nodeList->push_back(pntNode);
		
			pntNode.x = pntNE.x - sin(temAngle)*dLength;
			pntNode.y = pntNE.y + cos(temAngle)*dLength;
			nodeList->push_back(pntNode);
		}}}
		{{{
			Vector2d vec(dLength, 0);//vec(x��y)//����Ϊָ����ƽ����x���������
			//������������ת��
			vec_rotate(vec, dA+dOffsetAngle+90);//ֱ��������ת�Ƕȣ��ͱ�������pntNode��������-��+�����෴;
*				//������Ǻ����ģ�
					//����Ӧ��Ϊ��x+cos(temAngle);y+sin(temAngle);��
					//����Ƕ�Ϊ��ֵ�أ�Ҳ���԰���x+cos(temAngle);y-sin(temAngle);
					//���x��ָ���أ�����x��y�����������x-sin��temAngle);y+cos(temAngle);
					//����ΪʲôpntNE-vec�͵��ڣ���
			nodeList->push_back(pntNE-vec);
			nodeList->push_back(pntNE+vec);
		}}}
		//Բ������ļ��㣺
		//���ұ߲���Ҫx0 = element.north + element.startRadius*sin(temAngle);��
		if(element.directionR)//���������ָ�ڰ����򣿼������ڰ�����0Ϊ������1Ϊ�����ң�
		{//����Բ������
			x0 = element.north - element.startRadius*sin(temAngle);//Ԫ�صı�����-Ԫ�ص����뾶*sin����ǣ�������Ƕ���Ԫ�ص�ƫ���ת�������ģ���//���������ʱ�������
			y0 = element.east + element.startRadius*cos(temAngle);//Ԫ�صĶ�����+Ԫ�ص����뾶*cosƫ��ǣ�������Ӧ��-ȥ�𣿣�
		}
		else
		{
			x0 = element.north + element.startRadius*sin(temAngle);//������ + �뾶*sinƫ��ǣ�
			y0 = element.east - element.startRadius*cos(temAngle);
		}
		�ȼ��ڣ�
		//����Բ������
		Point2d cen;
		Vector2d vec(0, element.startRadius);//�����İ뾶Ϊ���ȣ�����ƽ����y���������
		vec_rotate(vec, element.azimuth);//��������תƫ��Ƕȣ�
		if (element.directionR)//
		{
			// ����
			vec = -vec;
		}
		cen = pnt0-vec;//Բ���������Ԫ�ص������ ��ȥ ������ƽ����y���������תƫ��Ǻ������
	//��㵽�յ�ķ�λ�ǣ�
		calc_azimuth(n1,e1,n2,e2)
		�ȼ��ڣ�
		azimuth_normalize(vec_angle(pnt1-pnt0))
			azimuth_normalize(rad2deg(atan2(y, x));
	//����ľ��룺
		double length = sqrt(
		�ȼ��ڣ�
		vec_length(pntx-pnt0);

	������
		P11x = sin(angle1);
		P11y = cos(angle1);
		�ȼ��ڣ�
		const Vector2d vec11(sin(angle1), cos(agnle1));
		
		P12x = pntX.y-pnt0.y;
		P12y = pntX.x-pnt0.x;
		�ȼ��ڣ�//����ǲ��ȼۣ�
		const Vector2d vec12(pntX-pnt1);
		
		const Vect2d vec12(pntX-pnt1);
		�ȼ��ڣ�
		const vect2d vec12(pntX.y-pnt1.y, pntX.x-pnt1.x);
		
		flagLR=P12y*cos(angle1)-P12x*sin(angle1);
		�ȼ��ڣ�
		_cross_product2d(vec12, vec11);
		
		const Vector2d vec11(sin(angle1), cos(angle1));
		�ȼ��ڣ�
		const Vector2d vec11(cos(angle1), sin(angle1));
xָ����yָ������ʱ��Ϊ����//��������£�xָ����yָ����˳ʱ��Ϊ����//��������£�		

	2��
		RoadPLine_test.cpp:
			ԭ����
			node.coord.x = pt1.y+vec.y;//Line:86
			node.coord.y =  pt1.x+vec.x;
			node.coord.x	= node.coord.x + vec.y;//103
			node.coord.y	= node.coord.y + vec.x;
			���ڣ�
			node.coord.x = pt1.x+vec.x;
			node.coord.y =  pt1.y+vec.y;
			node.coord.x	= node.coord.x + vec.x;
			node.coord.y	= node.coord.y + vec.y;
			
			ԭ����line:167
			const double dist	= sqrt((plNode.coord.x-north)*(plNode.coord.x-north)+(plNode.coord.y-east)*(plNode.coord.y-east));
			���ڣ�
			const double dist	= sqrt((plNode.coord.y-north)*(plNode.coord.y-north)+(plNode.coord.x-east)*(plNode.coord.x-east));
			
			ԭ����line��334��
			plNode.coord.x
			���ڣ�
			plNode.coord.y
			
			ԭ����282�رգ�124�򿪣�
			���ڣ���     124�رգ�

		StakeManage.cpp��
			ԭ����1166
			pt = pntNE;//����
		DK209200��DK282.hor��
			420��419:X=515316.375528,Y=2732489.634713
			1474��1473:X=483941.901974,Y=2714220.431340
			1499:X=483491.442313,Y=2713723.434224
			1713:X=475579.410049,Y=2708495.384701
	CLanguageManage
			//$(APP_DIR)/res/%s,  "string.txt" :"E:/gnss/southgnss_sdk/win32bin/res/string.txt"
				//���ļ������ݣ�Ϊ���е����İ�ģ����б�ţ���
			//������Դ�ļ���������
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


	����ĵ������ݵ��߼���
			void _load_control_point_par(CString strFileName)
				std::vector<ControlCoordPar>	m_vGcps;//
				������ݣ�
				gcps_from_file(m_vGcps, chFileName);//���ļ��л�ȡ���ݣ�
				_view_control_point_list();//���¿ؼ���
			int gcps_from_file(std::vector<ControlCoordPar> &gcps, const char *fnGcp)
				class GcpFileReader: public IDictionaryCallback��//����һ���ࣿ��
				GcpFileReader reader(gcps);//�������Ķ���
				return reader.loadGcps(fnGcp);//���ø���ķ���Ȼ�󷵻أ�
			class GcpFileReader: public IDictionaryCallback
				���ֻࣺ�д��麯����
				��Ա��
				������
					int loadGcps(const char *fnGcps)
						return read_csv_with_head_file(*this, fnGcps, ',', cot_fldns);
			int read_csv_with_head_file(IDictionaryCallback &callBack, const char *fn, const char TOK, const char *_csvFldns)
				
			_view_control_point_list()
				������ݣ�
	������Ƶ���߼���⣺
			import_ctrl_pnts_std(IDictionary &importInfo, IDbManager &dbMgr, const char *fnSrc�ļ���, const char *csvFldns, IProgress *tipAgent, const char *tipText)
				//��������Ϣdic�� DBManager�� fnSrc�����ļ����� csvFldns�����ļ����ݸ�ʽ�� ������ָ�룬 ��ʾ��Ϣ�ַ�����
				CtrlPointCallBack ctrlPoint(dbMgr, csvFldns);//����һ������
				int rc = ctrlPoint.readData(fnSrc, tipAgent, tipText);//���ö�ȡ����������
					
			class CtrlPointImport : public IDialogBehaviour
				���ࣺ
				��Ա��
				������
					void getExtName(char *ext, size_t sz, const IDictionary &dic)
						//��ȡѡ���ģʽ��
						//�ļ���ʽ����
						//����ģʽѡ����չ����Ȼ���Ƶ�ext�У�
					int _importPoint(IDictionary &dicUI)
						
					_getCurFormat(dicUI, csvFldns)
						static char *allExt[] = {"RTK","dat", "cot"};//���е���չ��//,"cot"//,"szName,dNorth,dEast,dElev,dLat,dLon,dEllipHgt"
						static char *nStdFormat[] = {"szName, dLat, dLon, dEllipHgt","szName, dNorth, dEast, dElev","szName,dNorth,dEast,dElev, dLat,dLon,dEllipHgt"};
						int mode = //��ȡѡ���ģʽ��
						csvFldns = nStdFormat[mode];//��ȡ��Ӧ���ļ����ݸ�ʽ��
					int _selectFolder(IDictionary &dicUI, int nType)
						char *csvFldns = NULL;
						const char *curExt = _getCurFormat(dicUI, csvfldns);//��ȡ�ļ�����׺���ļ����ݸ�ʽ��
						�򿪶Ի���
						����·��
			class CtrlPointCallBack:public IDictionaryCallback
				���ࣺ
					**
					* ��ȡ��#! csvFldnsͷ�е�csv�ļ�
					* @remarks ͨ��feedData()���ֵ���ʽ����ÿһ�����ݣ�
					* @remarks ͨ��feedHeader()������������#!��Ϣ
					*
					class IDictionaryCallback
					{
					public:
						virtual int feedHeader(int lineID, const char *sLine)=0;
						virtual int feedData(int lineID, const IDictionary &data)=0;
					};
				��Ա��
					IDbManager &m_dbMgr;;���ݿ�����ࣻ
					ISurvStarTable &m_table;//����һЩ���躯����
					int m_ctrlType;//��ǰ������ļ������ͣ�csvFldnsȷ��������ôȷ������
					
					//ͳ������
					int  m_ncount;//������ʲô�ļ�����
					int	 m_upNum��//���µĸ���������ͬ���ϲ��ĸ�����
					int  m_addNum��//��ӵĸ���
				������
					���캯����
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
						cosnt char *csvNEH = "dNorth, dEast, dElev";//�����꣬�����꣬�̣߳�//ƽ������
						const char *csvBLH = "dLat, dLon, dEllipHgt";//ά��latitude������longitude������ߣ�
						
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
							�����ŷָ���ȡ����ǰ��ĵ��ʲ����ƣ�
							const char *q = allFlnds;
							while(*q)
							{
								�����ŷָ���ȡ����ǰ��ĵ��ʲ����ƣ�
								�ж��Ƿ����
									����++countFlnds��
							}
						}
					void _setCommitSize(const int size)
						m_dbMgr.setCommitSize(size);
					int feedHeader(int lineID, const char *sLine)
						return 0��
					int feedData(int lineID, const IDictionary &rowData)
						���Ȱ�rowDataת����csa��ʽ�ַ���(comma seperate quote)
						�ж��Ǻ����ͣ���ȡ���ݣ�
						m_dbMgr.getLastCtrlIdByName();
					int readData(const char *fnSrc, IProgress *tipAgent, const char *tipText)
					{
						CallbackFile callback(this, tipAgent, tipText);//����һ������
						return read_import_rtk_file(callback, fnSrc, ',', m_csvFldns);//���ø÷�����
					}
				class CallbackFile : public IDictionaryCallback
					
				int read_import_rtk_file(IDictionaryCallback &callBack, const char *fn�ļ���, const char TOK�ָ���, 
					const char *_csvFldns �ļ����ݸ�ʽ)
					//�����������ʲô���飿�����ļ����ݣ�ÿ������һ�����ݣ��ͻص�һ���������д���
					char line[1000],csvFldns[2000],word[100], key[100], val[100];
					Dictionary  _dicLine;
					IDictionary &dicLine = _dicLine.getInnerObject();
					array_strncpy(csvFldns, _csvFldns);
					wlog("!%s", fn);
					InputFileStream is(fn, "rb");//��ȡ�ļ����ݣ�
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
					
						if ('R'==line[0])//��R��ͷ��
						{
							if (0==strncmp("Rem ", line, 4))
							{
								continue;
							}
						}
						if ('#'==line[0])//��#��ͷ��
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
									callBack.feedHeader(lineID, line+2);//ֱ�ӵ��ú����洢������ݣ�
								}
							}
							continue;
						}
						
						//�����ǳ���R��#��ͷ�ģ�
						const char *p = csvFldns;	// �ֶ���
						const char *q = line;		// ������
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
		���ݿ⣺
				class CDBManager : public IDbManager
					���ࣺ
						class IDbManager
							ֻ���麯�����������ݿ�Ĳ�����
					��Ա��
						IConfigSections		*m_cfgMgr;
						IPointDatabase		*m_pointDB;//
						IPageOfPoints		*m_pagePoints;
						IDBRtkSettings		*m_rtkPar;
						IGnssBuffer			*m_gnssBuf;						
						int		m_openFlag;					//���ݿ��ļ��Ƿ��Ѿ���
						int		m_updataFlag;				//���ݿ��ļ��Ƿ��Ѿ�����
					������
						���캯����
							
						int getLastCtrlIdByName(int &rePntId, int &reType, const char *name)
							return m_pointDB->getLastCtrlIdByName(rePntId, reType, name);
				class IPointDatabase
					ֻ���麯��
				class CPointDatabase : public IPointDatabase
					��Ա��
						SurvStarDatabase m_db;
						ITextConverter &m_toUtf8;
						ITextConverter &m_fromUtf8;
						int m_openCount;			// ��¼���ݿ�򿪴���
					
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
					������
						���캯����
			ConfigManager.cpp��
				����һЩ������
				.h�ļ�������һЩ�����ռ���ַ������壻
				������	
					IConfigSections *surv_star_get_config_manager()
						char *iniFile = 
							$(APP_DIR)/../etc/SurvStar/surv_star_init_params.ini
							$(APP_DIR)/../etc/SurvStar/surv_star_init_params_gen.ini
						char *cfgFile = "$(APP_DIR)/../var/SurvStar/Configure.ini"
						// �÷�װ�����������������ķ�����ͷ�
						class Wrapper��
						static Wrapper w(cfgFile, iniFile, 0);
						return w.getConfigManager();
		���Թ��̣�
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
			SurvStart����Ҫ���Թ��̣�
				C:\Program Files (x86)\Microsoft Visual Studio 9.0\VC\ce\atlmfc\src\mfc\winmain.cpp
				int InitApplication()
				gnss00_utilities_debug.dll!ConfigSectionsImp::getConfiguration(const char* sectionName = 0x21b2fad0) Line: 216, Byte Offsets: 00	C++
					e:\gnss\southgnss_gui\gnss03_mfc_utilities\GuiManager.cpp
				SurvStar_d.exe!CSurvStarApp::InitInstance(void) Line: 206, Byte Offsets: 0x14c	C++
				c:\Program Files (x86)\Windows CE Tools\wce500\STANDARDSDK_500\Include\Armv4i\shellapi.h
					SHGetSpecialFolderPath
				void _createShortCut(const wchar_t *szPath)
			//CMainFrame��
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
			//����ת��	
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

	1027.1���Ի�����޸ģ�1028.1 1101.3
		a��Ҫ��ɵ�Ч����
			e:\gnss\south_tools\CoordSystemTool\SettingConvertConfigDlg.cpp
			e:\gnss\SurvStar\SurvStar\ToolComputeTransParamConfig.cpp
			e:\gnss\south_tools\RoadDesign\AddBrokenChainDlg.cpp  ����
			
			e:\gnss\SurvStar\SurvStar\CoordSysEdit.cpp
		b���޸Ĳ��裻
			1��ɾ��ԭ�������ݣ����ͷ�ļ���
				#include <gnss00_utilities/dictionary_utils.h>
				#include <gnss01_gui/DialogManager.h>
				
			2�����ӶԻ��򲼾��ļ���dlg�ļ�				
						
			3������ʵ��ԭ��				
				1�����������������ͷ�ļ���
					class IDialogBehaviour
					class ICallbackDialog
					class IDialogManager
				2��EXTENSIBLE_FACTORY_DECLARE(IDialogManager, API01);
					*
					* ����չ����������
					*
					* @remarks csvTypeString����ָ����������ַ���(�԰�Ƕ��ŷֿ�)
					*     ���extensible_factory_register_IMapProjection("gauss,tmerc2", "", ctor1, dtor1);
					*     ���������ֵ��ý�����ͬһ���͵�ʵ����
					*     extensible_factory_get_IMapProjection("gauss:ellps=iau76,lon_0=111,x_0=500000",0);
					*     extensible_factory_get_IMapProjection("tmerc2:ellps=iau76,lon_0=111,x_0=500000",0);
					*
					#define EXTENSIBLE_FACTORY_DECLARE(InterfaceType, DLL_API_SPEC) \
						C_API DLL_API_SPEC InterfaceType *extensible_factory_get_##InterfaceType(const char *schema, const void *binParams);\
						C_API DLL_API_SPEC void extensible_factory_release_##InterfaceType(InterfaceType *&p);\
						C_API DLL_API_SPEC void extensible_factory_register_##InterfaceType(const char *csvTypeStrings, const char *descrpitionString, InterfaceType* (*ctor)(const char *csaParams, const void *binParams), void (*dtor)(InterfaceType*&));\
						C_API DLL_API_SPEC int extensible_factory_list_##InterfaceType##_type_strings(IOutputStream &os);\
						C_API DLL_API_SPEC const char *extensible_factory_get_##InterfaceType##_description(const char *distinction_tag);
				3��EXTENSIBLE_FACTORY_DEFINE
				4��EXTENSIBLE_FACTORY_REGISTER
				class QtDialogManagerImp: public IDialogManager
					//�����鿴�궨���ֵ��
						//VC�Ļ� /P���Ԥ����֮��Ĵ��� 
						//��VA�Ϳ����ˡ���������ö����һ�ţ�ֵ����ʾ�����ˣ�����ʾֱ�Ӷ��廹������ֵ������VAѡ��������
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
			�����޸����ӣ�ת������
				����ϵͳ:��ת�����������ã�
					��ӦSurvStar�����ߣ�����ת�����������㣺
					E:\gnss\southgnss_sdk\etc\gnss04_dialogs\survstar_tool_convert_config.dlg
						�����ֵ��E:\gnss\southgnss_sdk\etc\SurvStar\cn\surv_star_strings2.ini��tool_convert_config�ֶλ�ȡ��
					��Ӧ��Ҳ������ļ���
				�����Ķ�һ����				
					fldname���ֵ���Լ����key����ͨ����Դ�����еı�������
					����#���ļ������أ�#KeyBoardUsage
				
					tool_calculate_trans_param_config���򿪶Ի�������	
						��ȡȫ�ֵ������ļ��������IConfigSections��
						��ȡ�Ի������ù������IDialogManger��
						��ȡ�Ի����е�ת�������������ݣ�key ��"TransformConfig"
							"FittingMode,HorLimit,RmsAssignMode,TransformMethod,UseRmsAssign,VtcLimit,
							mode,parent_hwnd"
						Ȼ�󴴽�һ���ص��������������Ҫ�Լ�д�ģ���������һ���ص�����
						doModal
							ask_by_named_dialog
								����Ǵ��ļ�
									�����ͼ
									�����������
									�˵��б�
									�˵�����
									������ı�
									��Щ�Ի������͵Ļ������⴦��
								����
								��ȡ�Ի����ļ�·����
									uiMgr.getDlgFilePath()��
										"/Program Files/SurvStar/etc/gnss04_dialogs/"
									resolve_dlg_file�����ݽ����Ĳ������鿴�Ƿ���Ҫ��ȡ����������ֵ���滻��
										"/Program Files/SurvStar/etc/gnss04_dialogs/survstar_tool_convert_config.dlg"
									
									huoqu �������:Point��x=330��y=628��
										"$form_top_left_x,$form_top_left_y,
										FittingMode,HorLimit,RmsAssignMode,TransformMethod,UseRmsAssign,VtcLimit,
										mode,parent_hwnd"
									cfgMgr->getConfiguration(g_cm_transform_config)��
										"$form_top_left_x,$form_top_left_y,
										FittingMode,HorLimit,KeyBoardUsage,RmsAssignMode,TransformMethod,UseRmsAssign,VtcLimit,
										_productMask,_splash,_title_bar,()
										label1,label2,label3,label4,label5,label6,label7,()
										mode,parent_hwnd"
										
									resuable_dialog_show_modal()
										���ø�����
										���ü����Ի����¼�
										doModal
										��ȡ�������
							
						Ȼ���ͷŻص�����
				���ڸöԻ������Ϣ��������
					gnss04_mfc_dialogs_debug.dll!LineControl::set_readonly_and_keyboard(IDictionary& record = {...}, IDictionary& dicCfg = {...}, ReusableEditEx* wnd = 0x01c82a20) Line: 180, Byte Offsets: 0x10	C++
					gnss04_mfc_dialogs_debug.dll!EditBaseControl::initEdit(IDictionary& dic = {...}, ILayoutBox* box = 0x01c81d10) Line: 1088, Byte Offsets: 0x118	C++
					gnss04_mfc_dialogs_debug.dll!SingleEditControl::SingleEditControl(ILayoutBox* box = 0x01c81d10, IDictionary& dic = {...}, ISlotWindow* slot = 0x1fb2aef0, IGuiManager& uiMgr = {...}) Line: 1107, Byte Offsets: 0xbc	C++
					gnss04_mfc_dialogs_debug.dll!control_line_get_instance(ILayoutBox* box = 0x01c81d10, IDictionary& dic = {...}, ISlotWindow* slot = 0x1fb2aef0, IGuiManager& uiMgr = {...}) Line: 1653, Byte Offsets: 0x20c	C++
					gnss04_mfc_dialogs_debug.dll!parse_controls(const char* fnCfg = 0x1fb2af70, IDictionary& params = {...}, std::map<int,IControlLine *,std::less<int>,std::allocator<std::pair<int const ,IControlLine *> > >& name2ctrl = {...}, ILayoutBox* vLayout = 0x01c7b4f0, ISlotWindow* slotWindow = 0x1fb2aef0, IGuiManager& uiMgr = {...}) Line: 603, Byte Offsets: 0x104c	C++
					gnss04_mfc_dialogs_debug.dll!ReusableDialog::_generateForm(void) Line: 20, Byte Offsets: 0x8c	C++
					gnss04_mfc_dialogs_debug.dll!ReusableDialog::OnInitDialog(void) Line: 78, Byte Offsets: 0x40	C++
					������Ի����lineedit�ڵı༭���
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
				�ص������ı�д��
					���޸ģ�
						
				���õĲ鿴�ֵ��ڵ���Ϣ������
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
				�鿴mfc�µ������������ģ�
					
			�����޸����ӣ��Ĳ�����
				����ת�����Ĳ����ã�
					��Ӧ��SurvStar�����̣��������ԣ�����ϵ��
						E:\gnss\southgnss_sdk\etc\gnss04_dialogs\survstar_coord_system_edit_four_setting.dlg//���������coord_system_four_setting��ֵ��
							�����ֵ��E:\gnss\southgnss_sdk\etc\SurvStar\cn\surv_star_strings2.ini�ļ���coord_system_four_setting�ֶλ�ȡ��
					
				�Լ����޸ģ�
					1�����dlg�ļ���south_tools_coord_edit_four_param.dlg
						//Deployment->AdditionalFiles��
						//ֻ�ǻ������ֶ��ѵĻ������ݲ���Ҳ�ǿ��Եģ�
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
								//�����滻�ǳɹ��ģ�ֻҪȷ��fldname����һ���ģ�������ֵ����������ڣ�����ֵ�޷����棻
								//������dN2���������ģ�
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
		�����޸����ӣ��ռ���룺
			SurvStar�����ߣ��ռ���룺
				dialog_title:"�ռ����"
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
			�����޸����ӣ�
				��������->���棺�����б��
					�ο���survstar_config_set_short_cut.dlg
				survstar_config_general_set.dlg
					0x78e8f444 "$(APP_DIR)/../var/Configure.ini"
					0x78e8f418 "$(APP_DIR)/../etc/surv_star_init_params.ini"
					0x23b2f5b0 "/Program Files/SurvStar/etc/surv_star_rtk_commands.ini"
					urv_star_strings2.ini
					//���������ļ���Ϣ�����¼�����
					//��ȡ�����ļ���Ϣ
					return 1����ʾȡ��������ԭ���ĶԻ���
					return 0����ʾȷ�����˳��Ի���
					
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
				//�ص������ı�д��
					elevation ���θ߶�  antenna ����  radius �뾶��Χ
				namespace
				{
					//��������
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
				//������̵ĵ��������⣺
				
				
				//ԭ���ĶԻ����߼���
					#include "stdafx.h"
					#include <gnss00_utilities/gnss00_utilities.h>
					#include <gnss01_gui/DialogManager.h>
					#include <gnss03_mfc_utilities/GuiManager.h>
					#include <gnss04_survstar/ConfigManager.h>
					#include "SurvStar.h"
					
					// CSetupGeneral �Ի���
					
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
								//���ǽ�ֹ�����ò�����
								if ( dElevationMask<0 || 90<=dElevationMask || nIncrementStep<=0)
								{
									HWND hwnd = (HWND)dic_get_i4(params, "hwnd");
									message_box(hwnd, IDS_SET_MSGBOX_INPUT_VALID_VALUE, IDS_PUBLIC_MSGBOX_WARNNING, MB_ICONINFORMATION);
									return 1;
								}
								double dBaseDistTolerance = dic_get_r8(params, g_gc_base_tolerance, "");
								double dTiltLimit = dic_get_r8(params, g_gc_tilt_limit, "");
								//��վ������ֵ����б�޲����ò�����
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
					
				//���û�վ��ֵ���ƻ�ȡ����ֵ�����⣺
					e:\gnss\SurvStar\SurvStar\SetupGeneral.cpp //��֪��ʲôԭ�򣿣�
				//���öϵ㣺
					e:\gnss\SurvStar\SurvStar\SettingShortcut.cpp
						int callBack(const char *msg, IDictionary &params)
					e:\gnss\SurvStar\SurvStar\SetupGeneral.cpp 
						int callBack(const char *msg, IDictionary &params)
						GeneralSettingBehaviour(IConfigSections &cfgMgr)
						int setup_general(ISurvStar &settings, HWND p)
					e:\gnss\SurvStar\SurvStar\CommonCommands.cpp
						virtual void execute(const char *csaParam, void *binParam)
					e:\gnss\southgnss\gnss00_utilities\ConfigSections.cpp
			 �����޸����ӣ���ӿ��Ƶ�����ͱ༭���Ƶ������
				E:\gnss\southgnss_sdk\etc\SurvStar\cn\surv_star_strings2.ini
				latitude γ��  longitude ����
				
				//fldname��key��


	1017.2:�ļ���ȡ��ת����
		ԭģ����ļ���ȡ������ʹ�ã�
		bool CLanguageManage::LoadConfig()��
		    CString strFilePath;
			strFilePath.Format(_T("%s\\res\\config.ini"), strTemName);
			CSouthReadFile ResFile;
			if (ResFile.Open(strFilePath))//���ļ��ɹ�
			{
				char cRead[MAX_READ_LINE];
				CString strLine;
				while(ResFile.GetLine(cRead))//ѭ����ȡһ������
				{            
					strLine = CString(cRead);//
					if (strLine.Find(',') > 0)//����ܹ����ҵ�����
					{
						strLine = strLine.Left(strLine.Find(','));//�ҵ��Ļ��ͻ�ȡ��ߵ��ֶ�
					}
					return switchLanguage(_wtoi(strLine));//����ת��Ϊ������ֵ��
				}
			}
		����ļ������������裺
			void zip_test()
			{
				char wsp1[255] = {0};
				get_sample_data(wsp1, "surv_star_etc/surv_star_init_params.ini");
				char wsp2[255] = {0};
				get_sample_data(wsp2, "surv_star_etc/etc.zip");
		
				StreamFormatter _fmt1;
				IStreamFormatter &fmt1(_fmt1.getInnerObject());//����һ��������
				os_printf(fmt1, "os_file:path=%s", wsp1);//��ʽ���ļ�·�������������󣬾ʹ��ļ��ˣ����ǣ�ֻ�ǹ����ļ�·������
				const char *csa1 = fmt1.getBuffer();//��ȡ�ļ�����//��ȡ�ļ�·��
				char buf1[1000]={0};
				StreamContainer c1(csa1, 0);//����һ��container����
				IInputStream &is1 = c1.getInputStream();//��ȡһ������������
		
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
			if (ResFile.Open(strResPathFile))//���ļ�
			{
				char cRead[MAX_READ_LINE];
				CString strLine;
				CString strID, strString;
				while(ResFile.GetLine(cRead))//��ȡһ���ļ�
				{            
					strLine = CString(cRead);
					if (strLine.Find(',') > 0)//�ָ��ļ�����
					{
						strID = strLine.Left(strLine.Find(','));
						strString = strLine.Mid(strLine.Find(',')+1);
						mResStringList.SetAt(_wtoi(strID), strString);
					}
				}//��ȡ��Դ�ļ�����
			}
			
			// ��ȡ��ǰ���г����Ŀ¼
			char chfilepath[255]={0};
			int nsize = 0;
			nsize = GetModuleFileName(NULL, chfilepath, SIZEOF_ARRAY(chfilepath)-1);
			chfilepath[nsize]=0;
			
			StreamFormatter _fmtFile;
			IStreamFormatter fmtFile(&_fmtFile.getInnerObject());
			os_printf(fmtFile, "os_file:path=|%s\\res\\config.ini", chfilepath);//��ȡ�ļ�
			const char* pFile = fmtFile.getBuffer();//��ȡ�ļ�����
			StreamContainer fileContain(pFile, 0);//����һ��container����
			IInputStream isFile=fileContain.getInputStream();//��ȡ����������
		
			char chRead[128]={0};
			int nLineSize=0;
			while((nLineSize=is_get_line(chRead, SIZEOF_ARRAY(chRead), isFile, TEXT_EOL_STYLE_DOS)))
			{
				const char *p=chRead;
				char chReadPer[128]={0};
				int nWordSize = 0;
				nWordSize=next_word3(chReadPer, p, ',', 100);//��100�ֽ��ַ���ȡ�ָ���
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
			// ��ȡ��ǰ���г����Ŀ¼
			GetModuleFileName(NULL,strTemName.GetBufferSetLength (MAX_PATH+1),MAX_PATH);
			strTemName.ReleaseBuffer ();
			strTemName=strTemName.Left(strTemName.ReverseFind ('\\'));
			CString strConfigFilePath;
			strConfigFilePath.Format(_T("%s\\config.dll"), strTemName);
			CSouthReadFile ResFile;
			if (ResFile.Open(strConfigFilePath))//��ȡ�ļ�
			{
				char cRead[MAX_READ_LINE];
				CString strLine;
				int resID, appID = 931;
				while(ResFile.GetLine(cRead))//��ȡһ������
				{            
					strLine = CString(cRead);
					if (strLine.Find(',') > 0)
					{
						resID = _wtoi(strLine.Left(strLine.Find(',')));//��ȡ��ߵ�ֵ
						if (resID >= 931 && resID <= 946)
						{
							if (ExistExecuteApp(strLine.Mid(strLine.Find(',')+1)))//��ȡ��ֵ
							{
								CString strTem = pLanguage->getString(resID, _T(""));
								strTem.Replace(_T("\\r\\n"), _T("\r\n"));
								GetDlgItem(appID)->SetWindowText(strTem);
								mExecuteAppList.Add(strLine.Mid(strLine.Find(',')+1));
								GetDlgItem(appID++)->ShowWindow(TRUE);
							}
						}
					}
				}//��ȡ��Դ�ļ�����
			}
		//���ؿ��Ƶ�����
		BOOL CDataProcessDlg::LoadTransformParameter(CString strFileName)
			CSouthReadFile temReadFile;
			if (!temReadFile.Open(strFileName))
				return FALSE;
		class CCalcTransformParameterDlg : public CDialog
			void LoadControlPointPar(CString strFileName)
						CSouthReadFile temReadFile;
			if (!temReadFile.Open(strFileName))
				return;
	RoadDesignTool���ӣ�
			���ԣ�
				c/c++->general:Addi:..;"$(GNSS_DIR)/include"(ԭ����..)
				link->Input:Additional ��gnss03_curve_debug.lib
				link->general:Add:"$(GNSS_DIR)/win32lib" (ԭ������)
				Build Events->Post-Build Event->Command:copy "$(OutDir)\$(TargetName).exe" "$(GNSS_DIR)\win32bin\" (ԭ������)
				OutputFile="$(OutDir)\$(ProjectName)_debug.exe"
				Debugging->Command:$(GNSS_DIR)/win32bin/$(TargetFileName)
				����������ȥ����			
			// RoadDesignDlg.h :
				#include "include/gnss03_curve/RoadManage.h"
				�ĳɣ�#include <gnss03_curve/RoadManage.h>
			//RoadDesignDlg.cpp:
				//��ȡ���㣺
				m_RoadManage.GetCurveNodeItem(i, item);�ĳɣ�item = m_RoadManage.GetCurveNodeItem(i);
			
			//�������⣺
			.\GeneratedFiles\Debug\moc_ReusableDialogBase.cpp : warning C4819: The file contains a character that cannot be represented in the current code page (936). Save the file in Unicode format to prevent data loss
				ʲô���������أ�qt��
				
			�޸ģ�Common���֣�
				GetStrDegreeFromDecimalDegree(dangle,nFormatFlag(0-�ȣ�1-��o�֡��롯����2-�ȣ��֣��룬3-��.����),ndigit=8 );
					format_angle(char* buf, buf_size, dangle, LatLongFormatEnum, dec);
				GetDecimalDegreeFromStrDegree��CString &strAngle, int nFormatFlag=0);
					parse_angle(char* val,LatLongFromatEnum flag(LL_DEC=0-�ȣ�LL_DMS-��o�֡��롯��,LL_HMS-�ȣ��֣���,LL_DOT-��ȣ�LL-AZI-��λ�ǣ�����))
				toMulChar(CString , int nCodePage=CP_ACP);					
				toCString(char* value, int nCodePage=CP_ACP);
				
				//error C2664: 'void ATL::CStringT<BaseType,StringTraits>::Format(const wchar_t *,...)' : cannot convert parameter 1 from 'const char [3]' to 'const wchar_t *'
					mstrAzimuth.Format("%s", buf);//mstrAzimuth = CommonFunction::toCString(buf);
				ԭ�����ã�CommonFunction::GetStrDegreeFromDecimalDegree(mElementItem.azimuth, 1, 9);
				
				    //���ܣ���ʮ���ƶ�ת��Ϊ�ȷ�����ʽ�ַ���
					//���룺dangle����ʮ���ƶ�
					//		bShowFlag������ʾ�ȸ�ʽ��־��0-�ȣ�1-�ȡ�֡���壬2-��:��:�룬 3-��.����
					//�������
					//���أ��ȷ�����ʽ�ַ���
					//���ڣ�2013.05.09
					//////////////////////////////////////////////////////////////////////////
					CString GetStrDegreeFromDecimalDegree(double dangle, int nFormatFlag = 0, int nDigit = 8);
				
					//���ܣ����ȷ�����ʽ�ַ���ת��Ϊʮ���ƶ�
					//���룺strAngle������Ӧ��ʽ���ַ���
					//		nFormatFlag������ʾ�ȸ�ʽ��־��0-�ȣ�1-�ȡ�֡���壬2-��:��:�룬 3-��.����
					//���أ�ʮ���ƶ�
					double GetDecimalDegreeFromStrDegree(const CString &strAngle, int nFormatFlag = 0);
					
					
					//���ܣ���ʮ���ƶ�ת��Ϊ�ȷ�����ʽ�ַ���
					//���룺dangle����ʮ���ƶ�
					//		bShowFlag������ʾ�ȸ�ʽ��־��0-�ȣ�1-�ȡ�֡���壬2-��:��:�룬 3-��.����
					//�������
					//���أ��ȷ�����ʽ�ַ���
					//���ڣ�2013.05.09
					//////////////////////////////////////////////////////////////////////////
					CString GetStrDegreeFromDecimalDegree(double dangle, int nFormatFlag = 0, int nDigit = 8)
					{
						//����Ǹ�������Ӧ�ü��ϸ��� [6/26/2009 HuangKun]
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
								//ת��Ϊ�ȷ���
								double du, fen, miao;
								fen = modf(fabs(dangle), &du);     
								fen = fen*60;
								miao = modf(fen, &fen);
								miao = miao*60;
				
								//�������������60����
								if (fabs(miao-60.0)<1E-5)
								{
									miao = 0;
									fen++;
								}
								//�ֵ�����������60����
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
				
						//����Ǹ�������Ӧ�ü��ϸ��� 
						if (bNegative)
						{
							strAngle.Insert(0, '-');
						}
				
						return strAngle;
					}
				
					//���ܣ����ȷ�����ʽ�ַ���ת��Ϊʮ���ƶ�
					//���룺strAngle������Ӧ��ʽ���ַ���
					//		nFormatFlag������ʾ�ȸ�ʽ��־��0-�ȣ�1-�ȡ�֡���壬2-��:��:�룬 3-��.����
					//���أ�ʮ���ƶ�
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
								//��ת����ddd:mm:ss.ssss��ʽ
								strTemAngle.Replace(CString(IDS_GLOBAL_DEGREE), _T(":"));
								strTemAngle.Replace(CString(IDS_GLOBAL_MINUTE), _T(":"));
								strTemAngle.Replace(CString(IDS_GLOBAL_SECOND), _T(""));
							}
						case 2:
						case 3:
							{
								CString strTem;
								CString strDegree, strMinute, strSecond;
								//�Զ�ת���ɶ�.������ת��
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
				
								//�����Ƕȴ�С
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
				
						//����Ǹ�������Ӧ�ü��ϸ��� 
						if (bNegative)
						{
							dAngle = -dAngle;
						}
				
						return dAngle;
					}
				1010.2.13:	
				//CString��char* ������ת��,����һ��������Ͽ�֧�����ģ�	
				toMulChar(CString, int nCodePage=CP_ACP)
					//WideCharToMultiByte//��ӳ��һ��unicode�ַ�����һ�����ֽ��ַ���
					
					**
					* ȡ��ǰ���л��������ֱ����ַ���
					*
					* @param buf ���������
					* @param bufSize ����������Ĵ�С
					* @return ���ɹ���Ϊbuf����ʼ��ַ����ʧ�ܣ�Ϊ0
					*
					* @remarks
					* (1) Ҫ��50<=bufSize;
					* (2) �����ַ���������"UTF-8", "CP936";
					* (3) ����ֵ��LIBICONVҪ������ø�ʽ������"936"������"CP936"
					*
					wcs_to_mbs(char* buf, int buf_size, const wchar_t *wcs);
					
				//char* ��CString��ת��
				toCString(char*, int nCodePage)
					//MultiByteToWideChar//���ֽ�ת���ַ�unicode
					
					mbs_to_wcs(wchar_t * buf, int buf_size, const char *mbs);
					
					
					    //����CString��char *������ת��,����һ��������Ͽ�֧������ [9/14/2010 yongchang]
						// �޸� [11/23/2010 liyongchang]
						char* toMulChar(const CString value, int nCodePage = CP_ACP)
						{
							int len;
							char *chbuf;
					
							//��Unicodeת����GB2312  �����UTF-8ת����Unicode��ʹ��CP_UTF8
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
					
						//����char *��CString������ת�� [9/14/2010 yongchang]
						CString toCString(const char* value, int nCodePage = CP_ACP)
						{
							int len;
							CString strbuf;
							wchar_t *wchbuf = NULL;
							//��GB2312ת����Unicode  //�����UTF-8ת����Unicode��ʹ��CP_UTF8
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
					��ͷ�ļ�
						#include <gnss00_utilities/rism_utils.h>//SIEZE_ARRAY
						#include <gnss00_utilities/TextConverter.h>//wcs_to_mbs

				    //���ܣ����ȷ�����ʽ�ַ���ת��Ϊʮ���ƶ�
					//���룺strAngle������Ӧ��ʽ���ַ���
					//		nFormatFlag������ʾ�ȸ�ʽ��־��0-�ȣ�1-�ȡ�֡���壬2-��:��:�룬 3-��.����
					//���أ�ʮ���ƶ�
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
					
					//���ܣ���ʮ���ƶ�ת��Ϊ�ȷ�����ʽ�ַ���
					//���룺dangle����ʮ���ƶ�
					//		bShowFlag������ʾ�ȸ�ʽ��־��0-�ȣ�1-�ȡ�֡���壬2-��:��:�룬 3-��.����
					//�������
					//���أ��ȷ�����ʽ�ַ���
					//���ڣ�2013.05.09
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
			
		DataProcessTool��
			General->OutputDirectory:$(SolutionDir)$(ConfigurationName) ��ԭ����$(SolutionDir)$(PlatformName)_$(ConfigurationName)��
			General->IntermediateDirectory�� $(ConfigurationName)(ԭ����$(OutDir)\$(ProjectName)\)
			AdditionalIncludeDirectories=".." ��ԭ����$(GNSS_DIR)/include��
			link��AdditionalDependencies="../lib/Win32/gnss02_transform_debug.lib ../lib/Win32/gnss02_gis_dic_debug.lib ../lib/Win32/gnss03_svg_debug.lib ../lib/Win32/gnss03_curve_debug.lib"
				ԭ����AdditionalDependencies="gnss02_transform_debug.lib gnss02_gis_dic_debug.lib gnss03_svg_debug.lib gnss03_curve_debug.lib"
					ԭ����AdditionalLibraryDirectories="$(GNSS_DIR)/win32lib" ��ȥ����
			
			�޸ģ�
				c/c++->Additional:..;"$(GNSS_DIR)/include"(ԭ����..)
				link->Input->Additional :(ԭ��������ӣ�../lib/Win32/)
				link->general:Add:"$(GNSS_DIR)/win32lib" (ԭ������)


		���ĵĴ��룺����main.cpp,feature_class_test_routines.cpp,feature_class_test_routines.hpp
		û�и����඼ע�͵���ǰ�����ӣ�
				wgis_test��FeatureClass_Test.cpp��
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

	b��getLine�ĶԱȣ�IOStream.h��NormalFile��FileStream.h
			*Ҫ�ܹ�ͳһʹ��rb��r���ļ��򿪸�ʽ��������r:��\r\n����\r\n;rb:��\r\n����\n����
				NormalFile.cpp��//������\n
					����ǽ�β�򷵻�0��
					*ѭ�������ַ���
						getByte��ȡ�ַ���
						�����-1��0���أ�
						�����\n����\r��
							��0�������������ַ�����ȡ���һ���ַ������أ�
					�����ַ���
				FileStream.cpp��//����\r\n,�����һ��\n�����棻
					�пգ�
					�����rb��ʽ
						ѭ����ȡ�ֽڣ�getByte()
							�������ĩβ����0���أ�
							���棻
							��������\n��ĩβ
								��������ڶ�������0��
								����+1��0��
								����
							++��
						��0��
					
					fgetsֱ�Ӷ�ȡ������Ҳ����\n��
				StreamFormatter.h://����\r\n
					��ȡʣ���ֽ�����
					Ҫ��ȡ���ֽ����߽��趨��
					ѭ����ȡ��
						����ַ���\n������ֱ�ӱ��棩��
							i+1��0�����أ�
					�������С�ڵ�ǰλ�ã���0���أ�
					//���ࣿ
				ZipFileReader.cpp://ֻ��������\r\n�ж϶�ȡ����\r\n���������\n��������ȡ��
					ѭ����ȡ��
						����ַ���\n��
							���i>1��ǰһ����\r����i-1��0��������ȡ��
						����
							�����ַ���
			*�ܰ����в�ͬ-ϸ΢��ͬ��getLine�ϲ���һ��ȫ�ֺ�����
				//��ȡ�ļ���buf�У�buf�Ĵ�СΪbuf_size��
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
				
				//�Ż���
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
							if('\r'==ch)//����ǵ���\r
							{
								ch = is.getByte();
								if( !('\n' == ch) )//����������\n������һ��
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
				//�ٴ��Ż�
				int is_get_line(char *buf, size_t buf_size, IInputStream &is)
				{
					//���С��2�Ļ�����ʹ��1Ҳ�Ų���һ��0�����ԣ�Ӧ�ÿ��Զ�ȡһ���ַ���
					if (is.eof() || buf_size<1)
					{
						return 0;
					}
					for (size_t i=0; i<buf_size; ++i)
					{
						int ch = is.getByte();//��ȡ�ַ�
						if (-1==ch)//������ļ���β
						{
							buf[i] = 0;
							return i-1;
						}
						//�������\r\n�ּ��������
						a��\r��ʱ��
							�����\n�Ͳ�����
						b��\n��ʱ��
						if ('\n'==ch || '\r'==ch)
						{		
							//while(ch=='\r' || ch=='\n')//���治�ܸ�����\r\n��Ӧ�ú���
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
				
							if( (i+1)>=buf_size )//�����Է�\n
							{
								buf[i]=0;
								is.fseek(-1,SEEK_CUR);
								return i;
							}
							else//���Է�\n
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
				
				//���հ汾
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
				
				//���Դ��룺
				void c_normalfile_is_get_line_test()
				{			
					char path[1000] = {0};
					get_sample_data(path, "gnss00_utilities/isgetlinetest.ini");//���ַ����ŵ�buf�У�
					CPPUNIT_ASSERT_MESSAGE(path,file_system_check_file(path));
					
					//1��StreamFormatter 2��IStreamFormatter 3��os_printf ���ļ����浽IStrFor�У�4����ȡ���ݣ�
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
	//��ϰ���õ����Զ�ȡ���ݣ�			
			get_sample_data();//WGIS_TEST_DATA_DIR��������ȡֵ
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
	
			pthreadVC2.lib//֮ǰ�����sqlite3.lib
			
			
			0x002fe874 "!missing [e:/gnss/southgnss/etc/coordinate_systems/ellipsoids.csv]"
				E:\gnss\southgnss_sdk\etc\coordinate_systems
				//������⣺���¿���һ���ļ��е��Ǹ�Ŀ���ļ��У�

	�°��geom_to_pnt_dist�����ĸĽ��㣺
			a���ߵ���ֵ�жϣ�
			b��pline_point_distance��pline_snap_near������
				ǰ���ǵ㵽���ߵ���̾��루����ֵ���������Ƿ�����������ָ��������ĵ�λ��
			c����������㻷�ľ�������ѭ��������ѭ��������
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
			
						// �жϸõ��Ƿ���������С���εľ��������ֵ
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
			
						// �жϸõ��Ƿ���������С���εľ��������ֵ
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
							// ������߽���ߣ����ڶ�����ⲿ���������������
							return dist;
						}
			
						// ������߽��ұߣ�����Ƿ����ڵ�����
						for (int i=1; i<N; ++i)
						{
							pgn.getLoop(i,pl);
							pline_point_distance(pl, pnt, dist);
							if (0<=dist)
							{
								// �����ڱ߽���ߣ����ڵ����ڣ��������������
								return dist;
							}
						}
			
						// �ڲ����߽߱�
						return 0.0;
					}
					break;
				}
				return dist;
			}

	[ticket:474]���ɹ�ת�Ƶ�gnss01_kernelģ��
		//ԭ�������ӣ�
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
		gnss01_kernel��utilities��
			����û�������ļ���
		//����֮��
		geom_tools_tests.cpp
			#include <gnss00_utilities/gnss00_utilities.h>
			#include <gnss01_test_utils/test_utils.h>
			#include <gnss01_kernel/gnss01_kernel.h>//����
			#include <wgis01_kernel/wgis_kernel.h>//����
			
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
//δ��ɣ�12'-14Line;
//��Ҫ��ȡ·����buf��buf��С�� �Ƿ���Դ�ӡ��־�� ��ʽ�ַ�����va_list�ɱ�����б������
	int process_resolve_path_in_v(char *buf, const size_t buf_size, int isLogEnabled, const char *fmt, va_list args)
	{
		const char *context = __FUNCTION__;//��ȡ������
	
		if (!buf)//���ָ��Ϊ��
		{
			if (isLogEnabled)
			{
				wlog("!<ERROR ctx='%s(%s)'> buf(%p)==NULL </ERROR>"
					, context, fmt, buf, buf_size);//log���ݣ�����������ʽ�ַ�����buf��ַ��
			}
			return -11;
		}
	
		if (buf_size<100)//���buf��СС��100��
		{
			if (isLogEnabled)
			{
				wlog("!<ERROR ctx='%s(%s)'> buf_size(%d)<100 </ERROR>"
					, context, fmt, buf_size);//С��100ҲҪ��ӡ������
			}
			return -11;
		}
	
		int step = 0;
		try
		{
			StreamFormatter _os;
			IStreamFormatter &os(_os.getInnerObject());//�����ַ���buf��
			os_vprintf(os, fmt, args);//����ʽ�������пɱ�����б���װ���ַ�����
			const char *path_with_var = os.getBuffer();//��ȡ�ַ���
			if (isLogEnabled)
			{
				wlog("!%s(%s)", context, path_with_var);
			}
			const char *s = path_with_var;//������������ַ�������Ϊʲô����
			char *t = buf;//�����������buf�׵�ַ��
			size_t bufSize = buf_size;
			while (*t = *s)
			{
				++step;
				int len1 = 1, len2 = 1;
				//�����ַ�����
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
						// @return {-1:��������δ����,-2:�������ߴ粻��}
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
			// û�����û���������ֱ�ӿ���
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
		//  �����ļ���ʱ����log��ܿ���
		int res = process_resolve_path_in_v(buf, buf_size, 0, fmt, args);
		va_end(args);
		return res;
	}

//�������
	cogo_is_valid_line
		ֱ���ж������ľ��룻
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
	
		// �ȼ�����߶��Ƿ��н���
		if(   !cogo_is_valid_line(x1, y1, x2, y2) || !cogo_is_valid_line(x3, y3, x4, y4) 
			|| cogo_is_line_sparallel(x1, y1, x2, y2, x3, y3, x4, y4))
		{
			flag = 0;                           //���߶�ƽ��
			if(    !cogo_is_valid_line(x1,y1,x3,y3) || !cogo_is_valid_line(x1,y1,x4,y4)
				|| !cogo_is_valid_line(x2,y2,x3,y3) || !cogo_is_valid_line(x2,y2,x3,y3)
				|| cogo_is_line_sparallel(x1, y1, x3, y3, x1, y1, x4, y4) )
			{
				flag = 1;                       //���߶���ͬһ��ֱ��
			}	
	
			return false;                       // ���߶�û�н���
		}
	
		if(fabs(x1-x2) < EPSILON_6)
		{
			// L1Ϊ��ֱ�߶Σ�ƽ��Y��
			*north = x1;
			*east = (y4-y3)*x1/(x4-x3) + (y3*x4-x3*y4)/(x4-x3);
		}
		else if(fabs(x3-x4) < EPSILON_6)
		{
			// L2Ϊ��ֱ�߶Σ�ƽ��Y��
			*north = x3;
			*east = (y2-y1)*x3/(x2-x1) + (y1*x2-x1*y2)/(x2-x1);
		}
		else
		{
			// ����б��ʽ���
			const double k1 = (y2-y1)/(x2-x1);
			const double k2 = (y4-y3)/(x4-x3);
			const double b1 = (y1*x2-x1*y2)/(x2-x1);
			const double b2 = (y3*x4-x3*y4)/(x4-x3);
			*north = (b2-b1)/(k1-k2);
			*east = k1 * *north + b1;
		}
		// �жϽ����Ƿ����ӳ������
		double dL1  = calc_distance_2d(x1,y1,x2,y2);
		double dL1A = calc_distance_2d(x1,y1,*north,*east);
		double dL1B = calc_distance_2d(x2,y2,*north,*east);
	
		double dL2  = calc_distance_2d(x3,y3,x4,y4);
		double dL2A = calc_distance_2d(x3,y3,*north,*east);
		double dL2B = calc_distance_2d(x4,y4,*north,*east);
	
		flag = 0;
		if(fabs(dL1 - dL1A - dL1B) < 1E-10)        
			flag += 2*10;                          //������L1���߶���
		else if(dL1A > dL1B)                   
			flag += 3*10;                          //������L1��ǰ�ӳ�����
		else
			flag += 1*10;                          //������L1�ĺ��ӳ�����
	
		if(fabs(dL2 - dL2A - dL2B) < 1E-10)       
			flag += 2*1;                          //������L2���߶���
		else if(dL2A > dL2B)                   
			flag += 3*1;                          //������L2��ǰ�ӳ�����
		else
			flag += 1*1;                          //������L2�ĺ��ӳ�����
			
		return true;
	}

//�нǼ���
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
	
		double a = sqrt(pow((northB-northC),2) + pow((eastB-eastC),2));//��ȡBC��ľ���
		double b = sqrt(pow((northC-northA),2) + pow((eastC-eastA),2));//��ȡAC��ľ���
		double c = sqrt(pow((northB-northA),2) + pow((eastB-eastA),2));//��ȡAB��ľ���
	
		//1.�жϵ��Ƿ�ϸ� 
		//1a.�����ߵĳ��ȶ�����Ϊ��
		if (a<EPSILON_6 || b<EPSILON_6 || c<EPSILON_6)
		{
			return ERROR_SIDE_ZERO;
		}
	
		bool bCalcHor = data.bHorizontal;
		if ( !bCalcHor )//������㴹ֱ��,�ж�ƫ���Ƿ���ָ����Χ��
		{
			//���㴹ֱ��Ϊʲô��ƽ���ϵĵ�ľ�������ƫ���أ�//���*2/��c��
			double p = (a+b+c)/2.0;
			double s = sqrt(p*(p-a)*(p-b)*(p-c));
			double distTemp = s*2.0/c;				//����ƫ���
	
			if (distTemp < data.offsetDist)
			{
				return ERROR_OFFSET_OUT_OF_LIMIT;
			}
	
			//������,����ռ��,��ֱ��ʹ�ÿռ�����
			a = sqrt(pow((northB-northC),2) + pow((eastB-eastC),2) + pow((elevB-elevC),2));//�ռ��BC���룻
			b = sqrt(pow((northC-northA),2) + pow((eastC-eastA),2) + pow((elevC-elevA),2));//�ռ��AC���룻
			c = sqrt(pow((northB-northA),2) + pow((eastB-eastA),2) + pow((elevB-elevA),2));//�ռ��AB���룻
		}
	
		//2.��ʼ����
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

//ֱ�ߣ����߳�ģʽ
	/// ͨ���㡢��ģʽ������Ԫ��
    /// @param[in]  pNE : �������
    /// @param[in]  aziTangent : ��㷽λ��
    /// @param[in]  arcLength : �߳���
    /// @return ���ز��������룬0Ϊ�ɹ�������ʧ��
	int CStakeCurveManage::CalcLineByAziDist(Point2d pNE, double  aziTangent, double arcLength)
	{
		tagElementItem temElement;//����Ԫ�أ�
		memset(&temElement, '\0', sizeof(tagElementItem));
		//����ļ�����
		ClearFile();
	
		//������Ч
		if (arcLength <= 1E-7)
		{
			return SCD_ERROR_LENGTH_INVALID;
		}
	
		//�ȼ�¼��һ��Ԫ�أ�����
		temElement.type = tagElementItem::CURVE_ELEMENT_TYPE_POINT;//Ԫ������Ϊ�㣻
		temElement.coord = pNE;//�����Ϊ���㣿
		temElement.mileage = m_dStartMileage;//��ʼ��̣�
		temElement.azimuth = aziTangent;//��㷽λ�ǣ�
		AddElementItem(temElement);//�����Ԫ����ӽ�ȥ��
	
		//�ȼ�¼�ڶ���Ԫ�أ���
		temElement.type = tagElementItem::CURVE_ELEMENT_TYPE_LINE;//Ԫ������Ϊ�ߣ�
		temElement.startRadius = temElement.endRadius = -1;//���뾶���յ�뾶��Ϊ-1��
		temElement.length = arcLength;//�ߵĳ��ȣ�
		AddElementItem(temElement);
	
		//���������б�
		return CalcElementNodeList();
	}
// ��������Ԫ�ؽڵ������б�
	eFileError CStakeManage::CalcElementNodeList()
	{
		double dMileage = 0;
		double temAngle = 0;
		tagCurveNode temNode;//�ڵ㣨��׮���꣩����:(��������,eCurveNodeType,�������Ƿ��ѷ�������̣���λ�ǣ��̣߳����)
		//eCurveNodeType:
		//δ֪����,���,�յ㣻�м�13���㣺ֱ���ڵ㣬��ֱ����Բ��Բ�������У�ֱԲ��Բֱ��������ԲԲ��ֱ���ϣ������ϣ�Բ���ϣ���׮�㡣
		tagElementItem temElement;
		memset(&temNode, '\0', sizeof(tagCurveNode));
	
		/// ��׮�����б�
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

	//������Ԫ�ؽ��д���
		//����ڼ���Ԫ��,�������һ��Ԫ�ء��㡱//Ҳ���ǵ�һ��Ԫ�ز�������
		for (int nIndex = 1; nIndex < m_nElementCount; nIndex++)
		{
			temElement = m_pElementList[nIndex];//��ȡ����Ԫ�أ�
	
			//Ԫ�����//������׮�����ĸ���ֵ��
			temNode.mileage = temElement.mileage;
			temNode.coord.x = temElement.coord.x;
			temNode.coord.y = temElement.coord.y;
			temNode.azimuth = temElement.azimuth;

			//�ڵ�����//������׮���������ͣ�����ǰһ��Ԫ�ص������жϣ���
			switch (temElement.type)
			{
			case tagElementItem::CURVE_ELEMENT_TYPE_LINE://������ߣ�
				{
					switch (m_pElementList[nIndex-1].type)//�鿴ǰһ���������
					{
					case tagElementItem::CURVE_ELEMENT_TYPE_POINT://����ǵ㣺
						temNode.type = tagCurveNode::CURVE_NODE_TYPE_QD;//������Ϊ��㣻
						break;
					case tagElementItem::CURVE_ELEMENT_TYPE_LINE://��
						temNode.type = tagCurveNode::CURVE_NODE_TYPE_Z;//ֱ���ϵĵ㣻
						break;
					case tagElementItem::CURVE_ELEMENT_TYPE_CIRCLE://Բ��
						temNode.type = tagCurveNode::CURVE_NODE_TYPE_YZ;//Բֱ�ڵ㣻
						break;
					case tagElementItem::CURVE_ELEMENT_TYPE_EASE://����
						temNode.type = tagCurveNode::CURVE_NODE_TYPE_HZ;//��ֱ�ڵ㣻
						break;
					}
				}
				break;
			case tagElementItem::CURVE_ELEMENT_TYPE_CIRCLE://Բ��
				{
					switch (m_pElementList[nIndex-1].type)//�鿴ǰһ��������ͣ�
					{
					case tagElementItem::CURVE_ELEMENT_TYPE_POINT://��
						temNode.type = tagCurveNode::CURVE_NODE_TYPE_QD;//���
						break;
					case tagElementItem::CURVE_ELEMENT_TYPE_LINE://��
						temNode.type = tagCurveNode::CURVE_NODE_TYPE_ZY;//ֱԲ�ڵ㣻
						break;
					case tagElementItem::CURVE_ELEMENT_TYPE_CIRCLE: //Բ��
						temNode.type = tagCurveNode::CURVE_NODE_TYPE_YY;//ԲԲ
						break;
					case tagElementItem::CURVE_ELEMENT_TYPE_EASE:
						temNode.type = tagCurveNode::CURVE_NODE_TYPE_HY;//��Բ
						break;
					}
				}
				break;
			case tagElementItem::CURVE_ELEMENT_TYPE_EASE://����
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
	
		//��ӽڵ�
			if(AddCurveNodeItem(temNode)<0)
				return SCD_ERROR_MEMORY_FAILED;
	
			//����̶�λ��Ԫ���ڲ�
		//������׮��������̣�
			dMileage = 0;
			if (SCD_MAKE_TYPE_INTEGRAL_MARK == m_nMakeType)//����Ǹ�����׮������
			{
				while (dMileage <= temElement.mileage)//ֱ��Ԫ�ص������Ȼ���С��һ�����ֵ��
				{
					dMileage += m_dMileageInterval;
				}
			}
			else if (SCD_MAKE_TYPE_INTEGRAL_SPACE == m_nMakeType)// ����Ǹ�����׮������
			{
				dMileage = temNode.mileage + m_dMileageInterval;//��� = ��׮Ԫ�ص����+��̼����
			}
			else
			{
				return SCD_ERROR_MAKE_TYPE;
			}	
			temAngle = deg2rad(temElement.azimuth);//��ת���ȣ�
			
			//����ԲҪ�������У�����Ҫ���⴦��
			if (tagElementItem::CURVE_ELEMENT_TYPE_CIRCLE == temElement.type)//���Ԫ��������Բ��
			{//����׮�����̺����ͣ������׮�㣻
			
				//ֱ����ǰ��̴�������������//��̲��ϰ���̼�����ӣ�
				while(temElement.mileage + temElement.length/2.0 > dMileage)//���Ԫ�����+����/2����������õ���̣�
				{
					//��ȡָ����̵�����ͷ�λ��//ָ�����Ϊ�����-Ԫ����̣�����ƫ��Ϊ0��//�����ף���
					hcurve_moffset_to_posa(temNode.coord, temNode.azimuth, temElement, dMileage-temElement.mileage, 0);
					//Ԫ����׮��
					temNode.mileage = dMileage;//׮�����̾�����õ���̣�
	
					temNode.type = tagCurveNode::CURVE_NODE_TYPE_Y;//׮������ͣ�Բ
	
			//��ӽڵ�
					if(AddCurveNodeItem(temNode)<0)
						return SCD_ERROR_MEMORY_FAILED;
	
					dMileage += m_dMileageInterval;//���+��̼����
				}
	
				//��������//ָ�����Ϊ��Ԫ�صĳ���/2��ƫ��Ϊ0��
				hcurve_moffset_to_posa(temNode.coord, temNode.azimuth, temElement, temElement.length/2.0, 0);
				//Ԫ�����
				temNode.mileage = temElement.mileage + temElement.length/2.0;//׮������ = Ԫ�ص����+Ԫ�س���/2:
				temNode.type = tagCurveNode::CURVE_NODE_TYPE_QZ;//׮�����ͣ���㣻
				
			//��ӽڵ�
				if(AddCurveNodeItem(temNode)<0)
					return SCD_ERROR_MEMORY_FAILED;
	
				//��׮�������еĻ����ϼ�����̼��
				if (SCD_MAKE_TYPE_INTEGRAL_SPACE == m_nMakeType)//������ɷ�ʽ����׮�����ɣ�
				{
					dMileage = temNode.mileage + m_dMileageInterval;//��� = ��׮Ԫ�����+��̼����
				}
			
			//����׮�����̺����ͣ�
				//ֱ����ǰ��̴�����Ԫ������
				while(temElement.mileage + temElement.length > dMileage)//���Ԫ����� + Ԫ�س���>��̣���ִ�У�
				{
					//��ȡָ����̵�����ͷ�λ��//ָ�����Ϊ�����-Ԫ����̣�����ƫ��Ϊ0��
					hcurve_moffset_to_posa(temNode.coord, temNode.azimuth, temElement, dMileage-temElement.mileage, 0);
					//Ԫ����׮��
					temNode.mileage = dMileage;
	
					temNode.type = tagCurveNode::CURVE_NODE_TYPE_Y;
	
			//��ӽڵ�
					if(AddCurveNodeItem(temNode)<0)
						return SCD_ERROR_MEMORY_FAILED;
	
					dMileage += m_dMileageInterval;
				}
			}//if (ElementItem::CURVE_ELEMENT_TYPE_ARC == temElement.type)
			else//���Ԫ�����Ͳ���Բ��
			{
				//ֱ����ǰ��̴�����Ԫ������
				while(temElement.mileage + temElement.length > dMileage)//���Ԫ�����+Ԫ�صĳ��ȴ��ڵ�ǰ��̣�
				{
				//����׮�����̺����ͣ�
					//��ȡָ����̵�����ͷ�λ��
					hcurve_moffset_to_posa(temNode.coord, temNode.azimuth, temElement, dMileage-temElement.mileage, 0);
					//Ԫ����׮��
					temNode.mileage = dMileage;
	
					switch (temElement.type)//����Ԫ�����ͣ�
					{
					case tagElementItem::CURVE_ELEMENT_TYPE_LINE: //������ߣ�
						temNode.type = tagCurveNode::CURVE_NODE_TYPE_Z;//ֱ���ϵĵ㣻
						break;
					case tagElementItem::CURVE_ELEMENT_TYPE_EASE:
						temNode.type = tagCurveNode::CURVE_NODE_TYPE_H;//�����ϵĵ㣻
						break;
					}
			//��ӽڵ�
					if(AddCurveNodeItem(temNode)<0)
						return SCD_ERROR_MEMORY_FAILED;
	
					dMileage += m_dMileageInterval;
				}
			}//else if (ElementItem::CURVE_ELEMENT_TYPE_ARC != temElement.type)
		}
	
	//����յ�����
		//��ȡָ����̵�����ͷ�λ��//ָ�����Ϊ��Ԫ�صĳ��ȣ�ƫ��Ϊ0���Ϳ������յ����ꣻ
		hcurve_moffset_to_posa(temNode.coord, temNode.azimuth, temElement, temElement.length, 0);
	
		//Ԫ����׮��
		temNode.mileage = temElement.mileage + temElement.length;//Ԫ�ص����+Ԫ�صĳ��ȣ�
		temNode.type = tagCurveNode::CURVE_NODE_TYPE_ZD;
	//��ӽڵ�
		if(AddCurveNodeItem(temNode)<0)
			return SCD_ERROR_MEMORY_FAILED;
	
	//���ڵ�������
		int nCount = 0, nZHCount = 0, nHZCount = 0, nHYCount = 0, nYHCount = 0;
		int nQZCount = 0, nZYCount = 0, nYZCount = 0, nHHCount = 0, nYYCount = 0;
		//�����е�׮�����ѭ����
		for(int k=0; k<GetCurveNodeCount(); k++)
		{
			temNode = GetCurveNodeItem(k);//��ȡ׮�㣻
			switch(temNode.type)//�����������õ�����
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
	CalcElementNodeList()//��������Ԫ�ؽڵ������б�	
	CalculateElementItem����// ��������Ԫ��ֵ
		//��ʵ�޸�Ԫ�ص�ֵ��ʹ֮�������ڹ�ʽ��
		Ԫ�ظ���С��2�����أ�
		
		��һ��Ԫ�ص���� = �����̣�
		
		������Ԫ�ؽ���ѭ����
			��ȡǰһ��Ԫ�أ�
			��ȡ��ǰԪ�أ�
			
			����ǰһԪ�أ����䳤�ȣ�ƫ��Ϊ0�����յ������ƫ�ǣ� ����Ϊ��ǰԪ�ص������ƫ�ǣ�
			
			//ʹ�ö�������Ԫ�ر�����
			�����ж����������д���
				��ȡ������
				���Ԫ�ص����-�����Ķ�ǰ��� < 0.0001;
					Ԫ�ص���� = ����Ԫ�صĶϺ���̣�
					�ָ�ֵ�ض�����
					������
		���أ�
	TestElementItem()  // ����ۺ������Ƿ���ϱ�׼,�������޸Ĳ���,����0��ʾ�ɹ�
		Ԫ�ظ���С��2���򷵻أ�
		
		�����е�Ԫ�ؽ��д���
			��ȡԪ��;
			����Ԫ�����ͽ����жϣ�//��ǰԪ��
				������ߣ�
					���뾶���յ�뾶=-1��//�޸����ݣ�
					//ֻ�г�����Ч
					���i+1С��Ԫ������ ���� ���뾶�ľ���ֵ==0 ��i+1Ԫ��ʱֱ��
						i+1Ԫ�ص����뾶=��ǰ���յ�뾶��-1����
				Բ��
					ͬ�ϣ�
					����i+1Ԫ�صİ뾶��ƫ��
				������
					//���i+1��ֱ��
					�����ǰԪ�ص��յ�뾶==0����i+1Ԫ������Ϊֱ�ߣ�
						���õ�ǰ����յ�뾶Ϊ-1��
					������� ��ǰԪ�ص��յ�뾶==0 ���� i+1Ԫ��ʱԲ
						����i+1Ԫ�����õ�ǰԪ�ص��յ�뾶��ƫ��
					���������ǰԪ�ص��յ�뾶==0
						ֱ������Ϊ -1��
					
					//���������˶������Ļ���
					
					//���˰뾶��ȣ��˻���Բ
						�޸�����
				�㣺
					���ó��Ⱥ��յ�뾶��
				
			//��������ֳ���Ϊ0��Ԫ��
			
			//���i��=0��
				//����,�����������Ԫ�طָ�//��������-�������ݣ���ǰ��̣��Ϻ���̣���
				�����ж������д���
					��ȡ����Ԫ�أ�
					
					�ж϶�������Ԫ��
					���Ԫ�ص����==��ǰ��� ���� Ԫ�����+����>��ǰ��̣�
						�´δ���һ����ʼ���ң�k�Ѿ�++�ˣ���+1����
						������ = �Ϻ����-��ǰ��̣���//
						�����Ԫ�����-��ǰ���>0.0001)
							����Ԫ�س��ȣ�
							����һ��Ԫ�أ�
							Ԫ�صĳ��ȸ�Ϊ����ǰ���-Ԫ����̣�//�ı�Ԫ�س��ȣ�
							����Ԫ�صĳ��� = ����Ԫ�س���-��Ԫ�س��ȣ�
							
							���������Ԫ�صĳ���>0.0001��
								//���㻺���ָ�ʱ�뾶//??ʲô�л����ָ�ʱ�뾶��
								�������Ԫ�ص�����Ϊ������
									��ȡ�����յ�İ뾶��
									
									0�㵽��㡢���յ㡢����ǰ������߳�����
									��������뾶==0����С��0��//������ʰ뾶Ϊ���������ߣ����ʰ뾶�����ʵĵ����������ʰ뾶��//���ʰ뾶Խ��Բ��Խƽ�������ʰ뾶ԽС��Բ��Խ����
										���յ�����߳�=ԭԪ�صĳ��ȣ�
										����ǰ�� = ԭԪ�ص��³��ȣ�
									//������ʰ뾶��Ϊ�����
										����յ�뾶==0
											�յ�뾶=���뾶��
											�յ��������ͬ�ϣ�
											��ǰ������߳�������Ԫ�صĳ��ȣ�
										����
											���������߳� = ����ĳ���*�յ�뾶/�����뾶-�յ�뾶����
											���յ�����߳� = 
											����ǰ������߳� = ��
									ԭԪ�ص��յ�뾶 = ����Ԫ�ص����뾶 =  �յ�뾶*���յ����߳�/��ǰ�㣻
								��ӿ���Ԫ�� ��i+1��λ�ã�
						����ѭ����
							
			�����i<Ԫ�ظ���-1��//�������һ��Ԫ�أ�
				����i+1Ԫ�ص���� = Ԫ�ص���� + Ԫ�صĳ��� + �����̣�
			
			��Ԫ�طŵ�iλ�ã�
		����true��
					
		
	// ���㻺�������߳�//���߳� = T = ��R���뾶�� + P��tg��a/2�� + m��//���ݻ�����ʽ l = r�� ��ʽ�У�l�ǻ���,r�ǰ뾶,����Բ�Ľǣ�//�����У��� =l/r,���������԰뾶��Բ�ĽǵĴ�С,��Բ�Ľ��û����Ʊ�ʾ.
	double hcurve_calc_ease_tangent_length(const double &radius,const double &angle, const double &lengh)
		//�뾶���Ƕȣ����ȣ�
		�뾶��С��0��
		
		�Ƕ�ת��Ϊ����(angle)��
		B0 = ����/(2*�뾶)��//�����ò�����
		da =  ����+2*B0��//���ݽǶȣ����ȺͰ뾶��
		
		P = ���ȵ�ƽ��/��24*�뾶��- ���ȵ�4�η�/(2688*�뾶��3�η�)��//���ݳ��ȺͰ뾶�����
		m0= ���ȵ�һ�� - ���ȵ�3�η�/��240*�뾶��ƽ���� + ���ȵ�5�η�/34560.0*�뾶��ƽ����//���ݳ��ȺͰ뾶�Ϳ����������
		result = ���뾶+P��*tan��da/2.0) + m0;

	/// �����㷨�еĽ��㻻���Ԫ��
		eFileError CRoadManage::IntersectToElement()
		{
			tagElementItem temElement;
		
			//���ԭ��Ԫ������
			m_nElementCount = 0;
			if (m_pElementList)
			{
				free(m_pElementList);
				m_pElementList = NULL;
			}
		
			//������Ŀ�����С2
			if (m_pIntersectList == NULL || m_nIntersectCount < 2)
			{
				return SCD_ERROR_LACK_ELEMENT;
			}
		
			//�ȼ�¼��һ��Ԫ�أ�����
			Point2d pnt0=m_pIntersectList[0].pntNE;
			Point2d pnt1=m_pIntersectList[1].pntNE;
			memset(&temElement, '\0', sizeof(tagElementItem));
			temElement.type = tagElementItem::CURVE_ELEMENT_TYPE_POINT;
			temElement.coord = pnt0;
			temElement.mileage = m_pIntersectList[0].mileage;
			temElement.azimuth = vec_angle(pnt1-pnt0, 1);//����Ԫ��ƫ��� = ��һ���㵽ǰһ����ĽǶȣ���x0��y0��x1��y1��//��������ߵĲ�ֵ��Ȼ����atan2��Ƕȣ�
			AddElementItem(temElement);
		
			double   dTemDist1 = 0.0;
			double   dTemDist2 = 0.0;
			double   dBeforDist = 0.0;
			double   nLineDist = 0.0;   //ֱ�߶γ�
		
			//ǰ��λ��,��������ת��,�Ӷ��õ���ƫ��ƫ��ʶ
			double   dAfterAng = 0.0; 
			double   dBeforAng = 0.0;
			bool	 bDirectionR = false;  //��ƫ��ƫ��ʶ
		
			//ÿ��Ԫ����������λ��,��ȡ����ʶ����
			for(int n=1; n<m_nIntersectCount-1; n++)
			{
				//������ǵ�һ��������һ������뾶С��0���򷵻ش���
				if (m_pIntersectList[n].radius < 1e-6 && n != m_nIntersectCount-1)
				{
					return SCD_ERROR_INVALID_TYPE;
				}
		
				//N�㵽N-1��ķ�λ��
				Point2d pntN1(m_pIntersectList[n].pntNE);
				Point2d pntN0(m_pIntersectList[n-1].pntNE);
				dBeforAng = vec_angle(pntN0-pntN1, 1);
		
				//N-1��N��ľ���
				dBeforDist = vec_length(pntN0-pntN1);
		
				//��ǰ�㲻�����һ����
				if(n != m_nIntersectCount-1)  
				{
					//3a.�����ת��->Բ����Բ�Ľ�->Բ���߳���
					Point2d pntN2(m_pIntersectList[n+1].pntNE);
					dAfterAng = vec_angle(pntN2-pntN1, 1);
		
					//��λ��1����λ�ǵõ��н�
					double res = dBeforAng - dAfterAng;
					if(res < 0) 
						res += 360;
		
					if(res < 180.0)	//ͨ���нǴ�Сȷ������ƫת����
						bDirectionR = true;
					else
						bDirectionR = false;
		
					//���㽻�Ǽ�����
					
					// Բ�����ֵ�Բ�Ľ�
					const double dYuanAng = fabs(res - 180.0)
						- rad2deg(m_pIntersectList[n].A1/(m_pIntersectList[n].radius*2))
						- rad2deg(m_pIntersectList[n].A2/(m_pIntersectList[n].radius*2));
		
					// Բ���߻���(Բ�Ľǳ˰뾶)
					const double dYuanLen = (deg2rad(dYuanAng))*m_pIntersectList[n].radius;
					
					//�õ����߳�1�����߳�2
					const double T1 = hcurve_calc_ease_tangent_length(m_pIntersectList[n].radius, dYuanAng, m_pIntersectList[n].A1); 
					const double T2 = hcurve_calc_ease_tangent_length(m_pIntersectList[n].radius, dYuanAng, m_pIntersectList[n].A2);
		
					//����HZ���t2�㾭�Ĳ����Ժ������
					Point2d p0, pp0;
					{
						Point2d pnt1,pnt2;
						Point2d pnt11, pnt22;
						hcurve_calc_end_points(pnt1, pnt2, m_pIntersectList[n].radius, dYuanAng, m_pIntersectList[n].A1, bDirectionR);
						hcurve_calc_end_points(pnt11, pnt22, m_pIntersectList[n].radius, dYuanAng, m_pIntersectList[n].A2, !bDirectionR);
		
						//��ʱ����һ���Ĳ���
						double Ro, dScale;
						Point2d pnt0;
						p4_from_point_pairs(pnt0, Ro, dScale, pnt22, pnt1, pnt11, pnt2);
		
						//[2009.10.12]:p0ΪHZ������,pp0Ϊ���ߵ�2������
						//HZ��
						p0.x = dScale*(cos(Ro) * 0 - sin(Ro) * 0) + pnt0.x;
						p0.y = dScale*(sin(Ro) * 0 + cos(Ro) * 0) + pnt0.y;
		
						//���ߵ�2������: 08.12.18 » ����,����̱߿��Ƴ�������
						//xx0 = dScale*(cos(Ro) * T2 - sin(Ro) * 0) + X0;
						//yy0 = dScale*(sin(Ro) * T2 + cos(Ro) * 0) + Y0;
						pp0.x = p0.x - T2* cos(deg2rad(res));
						pp0.y = p0.y + T2* sin(deg2rad(res));
					}
		
					//�󽻵�����
					Point2d pntResult;
					line_cross(pntResult, Point2d(0,0), Point2d(T1,0), p0, pp0);
		
					//3c.��ȡ����:ͨ�����������JD����,���Եõ�ZH�������ʵ�ʾ���
					//ͨ�����������ʵ������,�������������֮���ʵ�ʾ���
					//����õ���һ��ֱ�߳�
					dTemDist1 = vec_length(Point2d(0,0)-pntResult);
					//ֱ�߳�
					nLineDist = dBeforDist - dTemDist1 - dTemDist2;  //����ʹ�������,��ϸ��˵���ĵ�
					//��Ҫ������㵽HZ�����,������һ��JD�ĵ�һ��ֱ�߳�
					dTemDist2 = vec_length(p0-pntResult);
		
					//3d.�洢˳��:ֱ��->����->Բ��->����
					/// ֱ��Ԫ��
					if (nLineDist > 1E-7)
					{
						memset(&temElement, '\0', sizeof(temElement));
						temElement.type = tagElementItem::CURVE_ELEMENT_TYPE_LINE;
						temElement.length = nLineDist;
						temElement.overhgt = 0;
						AddElementItem(temElement);
					}
		
					//����������ߵĳ��ȴ����㣬��д�뻺������
					if(m_pIntersectList[n].A1 > 1e-7)
					{
						memset(&temElement, '\0', sizeof(tagElementItem));
						temElement.type = tagElementItem::CURVE_ELEMENT_TYPE_EASE;
						temElement.length = m_pIntersectList[n].A1;
						temElement.startRadius = -1;
						temElement.endRadius = m_pIntersectList[n].radius;
						temElement.directionR = bDirectionR; //����
						temElement.overhgt = m_pIntersectList[n].overhgt;
						AddElementItem(temElement);
					}
		
					//���Բ��������0�����Բ��
					if (dYuanLen > 1E-5)
					{
						memset(&temElement, '\0', sizeof(tagElementItem));
						temElement.type = tagElementItem::CURVE_ELEMENT_TYPE_CIRCLE;
						temElement.length = dYuanLen;
						temElement.startRadius = m_pIntersectList[n].radius;
						temElement.endRadius = temElement.startRadius;
						temElement.directionR = bDirectionR; //����
						temElement.overhgt = m_pIntersectList[n].overhgt;
						AddElementItem(temElement);
					}
		
					//����������ߵĳ��ȴ����㣬��д�뻺������
					if(m_pIntersectList[n].A2 > 1e-8)
					{
						memset(&temElement, '\0', sizeof(tagElementItem));
						temElement.type = tagElementItem::CURVE_ELEMENT_TYPE_EASE;
						temElement.startRadius = m_pIntersectList[n].radius;
						temElement.endRadius = -1;
						temElement.length = m_pIntersectList[n].A2;
						temElement.directionR = bDirectionR; //����
						temElement.overhgt = m_pIntersectList[n].overhgt;
						AddElementItem(temElement);
					}
				}
				else
				{
					//�������ֻ�������ֻ���������ʱ��
					memset(&temElement, '\0', sizeof(temElement));
					temElement.type = tagElementItem::CURVE_ELEMENT_TYPE_LINE;
					temElement.length = dBeforDist;
		
					//�ڶ���Ԫ�أ�ֱ��
					temElement.overhgt = 0;
					AddElementItem(temElement);
					break;
				}
		
				//����������һ������
				if(n+2 == m_nIntersectCount)
				{
					dBeforDist = vec_length(m_pIntersectList[n+1].pntNE-m_pIntersectList[n].pntNE);
		
					nLineDist = dBeforDist - dTemDist2;
		
					if (nLineDist > 1E-7)
					{
						/// ֱ��Ԫ��
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
		���ԭ�������ݣ�
		������Ŀ�������2��
		
		�ӽ��������ȡ��һ���͵ڶ������㣻
		����Ԫ�����ͣ�
		����Ԫ�����ꣻ
		����Ԫ����̣�
		����Ԫ��ƫ��� = ��һ���㵽ǰһ����ĽǶȣ���x0��y0��x1��y1��//��������ߵĲ�ֵ��Ȼ����atan2��Ƕȣ�
		��ӵ�һ��Ԫ�أ�
		
		��ʱ����1��
		��ʱ����2��
		ǰ���룻
		ֱ�߳��ȣ�//�Ķ�ֱ�ߣ�
		
		ǰ��λ�ǣ�
		��λ�ǣ�//������������ת�ǣ��Ӷ��õ���ƫ��ƫ��
		��ƫ��ƫ��ʶ��
		
		�����н�����д���//ÿ��Ԫ����������λ��,��ȡ����ʶ����//���ȵ�֪��������ʲô��
			//������ǵ�һ��������һ������뾶С��0���򷵻ش���
			
			N�㵽N-1��ķ�λ�ǣ�//��Ϊǰ��λ�ǣ�//����ע����n�㵽n-1�㲻��n-1�㵽n��ķ�λ�ǣ�
			����ľ���Ϊǰ���룻
			
			��ǰ�㲻�����һ����
				��� = n+1�㵽n���ƫ��ǣ�
				
				ǰ�Ǽ���ǵĽǶȲ�res��
				<0��+360��
				���<180����ƫ�ң�//���ݴ���180����С��180�жϣ�
				����ƫ��
				
				���㽻�Ǽ�������
				Բ�����ֵ�Բ�Ľǣ�//��һ������
					res-180�ľ���ֵ - ��һ����/2*R�ĽǶ�-�ڶ������ĽǶȣ�
					
				Բ���߻���(Բ�Ľǳ˰뾶)
				
				�õ����߳�1�����߳�2//ͨ���뾶����õ�Բ�Ľǣ���һ�����������߳���
					hcurve_calc_ease_tangent_length(m_pIntersectList[n].radius, dYuanAng, m_pIntersectList[n].A1); 
					hcurve_calc_ease_tangent_length(m_pIntersectList[n].radius, dYuanAng, m_pIntersectList[n].A2);
				
				//����HZ���t2�㾭�Ĳ����Ժ������
					//�ð뾶���Ƕȣ�n��ĵ�һ���������һ���������˵㣻
					hcurve_calc_end_points(pnt1, pnt2, m_pIntersectList[n].radius, dYuanAng, m_pIntersectList[n].A1, bDirectionR);
					//�ð뾶���Ƕȣ�n��ĵڶ���������ڶ����������˵㣻
					hcurve_calc_end_points(pnt11, pnt22, m_pIntersectList[n].radius, dYuanAng, m_pIntersectList[n].A2, !bDirectionR);
					
					//��ʱ����һ���Ĳ���//R0��ת�Ƕȣ�dScale������pnt0ƫ��ƫ����
					p4_from_point_pairs(pnt0, Ro, dScale, pnt22, pnt1, pnt11, pnt2);
					
					//[2009.10.12]:p0ΪHZ������,pp0Ϊ���ߵ�2������
					//HZ��
					
					//���ߵ�2������: 08.12.18 » ����,����̱߿��Ƴ�������
					
				//�󽻵�����
				
				//3c.��ȡ����:ͨ�����������JD����,���Եõ�ZH�������ʵ�ʾ���
				//ͨ�����������ʵ������,�������������֮���ʵ�ʾ���
				//����õ���һ��ֱ�߳�//ֱ����0,0����ȥ�������ꣻ
				
				//ֱ�߳�
				
			����//��ǰ�������һ���㣺
			
			//����������һ������
	eFileError DesignCalculate(eRoadDesignType nType)
		//���ɵ�·���������Լ���׮�����
		���ԭ�������ݣ�
		����ǽ��㷨����ͨ�����㷨�����Ԫ�ط���
			IntersectToElement()��
			
		//���������Ƿ���������Ҫ��
			TestElementItem()
			
		//����Ԫ���ڵĸ�ֵ
			CalculateElementItem()
			
		return CalcElementNodeList()
RoadManageTest.cpp��
	CmpMileageCent()
		// ����У��25�׼��ʱ�������������ͬ��̼�����·��ľ���	
		process_resolve_path������,�����С��//��ȡ$(GNSS_TEST_DATA_DIR)�ľ���·������ȡip�ļ���·����
		���������̣�
		������̼����
		�������ͣ�//������׮�����ɣ�������׮�����ɣ�
		
		�����ļ���
		��Ƽ��㣻
		
		��ȡ�ܵĵ�����
		������׮����������



ж�������ˮǽ���
	��������ν��ж�ؾ���ʹ������������	
	�������£�
	1. �½�c:\a.bat������, ����C:\Windows\System32Ŀ¼�¸��ļ���Ŀ�ľ�����������ˮǽ������ļ�:
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
	
	2������ϵͳ, ����İ취����������ģʽ(ֻҪ��ˮǽû�����е�ģʽ����, ����������, ��װ�̵�), cd ��C:\WINDOWS\system32\ ����a.bat
	3������ϵͳ����������ϵͳ�£�����services.msc��������������WaterBox Client Security Patron Service������Ϊ�����á�;
	4������msconfig ,����,�ҵ�SPMCenter�����ȥ��ǰ��Ĺ�������Ӧ�á���Ŀ���ǲ�������Ϊ�������
	5��ɾ������ע����
	HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Shared Tools\MSConfig\startupreg\SpMessageCenter
	HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run �� SpMessageCenter��
	HKEY_CURRENT_USER\Software\Microsoft\Windows\ShellNoRoam\MUICache �� C:\WINDOWS\system32\SpmCenter.exe��
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
	6����������������Ч�������ó�������֮��Ĺ�������ϵͳ��ע��������ļ���
 
��γ���ж��ɾ����ˮǽ�أ�
	XPϵͳ��ж�ط�ˮǽ�Ĳ���
	�ҵĻ�����XP�������򻻹�����Ե�ʣ�������Ҫ��ˮǽ�ˣ����Ƿ��ֺ���ɾ�����޷���ͨ���Ĳ���ж�ء�����һ��Ŭ�������ڳɹ������¼��������
	
	˵������ˮǽ������ͳһ�ն˰�ȫƽ̨��
		����1��SecPatron.exe
		����2��SPMCenter.exe
		����WaterBox Client Security Patron Service ~ system32\CSSSP\bin\SecPatron.exe
				//c:\Windows\SysWOW64\SPMCenter.exe
	�������£�
	1����XP�У����ظ���������VFloppy������Ϊ�����������巽���ܼ򵥣��ڴ����ˣ�;
	
		���������������Ϊc:\1.bat������Ŀ������dos��ɾ����Щdll�ļ���  
	
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
	
	����ϵͳ���ڲ���ϵͳѡ����棬����������������������������DOS�£�
	2���ڴ�Dos�£��ҵ�C:\WINDOWS\system32\CSSSP\�ļ��У�������delete֮����rename֮����
		��ִ�����洴����c:\1.bat��
	3������ϵͳ����������Win XP�£�����services.msc��������������WaterBox Client Security Patron Service������Ϊ�����á�;
	4����XP�£�����msconfig ,����,�ҵ�SPMCenter�����ȥ��ǰ��Ĺ�������Ӧ�á���Ŀ���ǲ�������Ϊ�������
	5����XP�£�ɾ������ע����
	HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Shared Tools\MSConfig\startupreg\SpMessageCenter
	HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run �� SpMessageCenter��
	HKEY_CURRENT_USER\Software\Microsoft\Windows\ShellNoRoam\MUICache �� C:\WINDOWS\system32\SpmCenter.exe��
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
	
	6����������XP������Ч�������ó�������֮��Ĺ�������ϵͳ��ע��������ļ���

*/
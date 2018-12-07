#ifndef COMMON_DEFINE_H_73CBA391_55CF_4A19_8A27_B71F9F2EAF3D
#define COMMON_DEFINE_H_73CBA391_55CF_4A19_8A27_B71F9F2EAF3D
#include <boost/cstdint.hpp>

#define safe_release(x)  {if(x) {(x)->release(); (x)=nullptr;}}
#define safe_delete(x)  {if(x) {delete (x); (x)=nullptr;}}
#define safe_free(x)  {if(x) {free (x); (x)=nullptr;}}

#define Tranverse16(X) ((((unsigned short)(X) & 0xff00) >> 8) |(((unsigned short)(X) & 0x00ff) << 8))
#define Tranverse32(X) ((((unsigned int)(X) & 0xff000000) >> 24) | (((unsigned int)(X) & 0x00ff0000) >> 8) | (((unsigned int)(X) & 0x0000ff00) << 8) | (((unsigned int)(X) & 0x000000ff) << 24))

/**  
 *  ��������: ģ�洴��get, setϵ�к���
		@param FunctionName ����������
		@param ParamType ����������
		@param MemberName ���Ա����
 */
#define FUNCTION_GET_SET(FunctionName, ParamType, MemberName) \
		public:\
		void Set##FunctionName(const ParamType& c) { this->MemberName = c; } \
		ParamType& Get##FunctionName() { return this->MemberName; }

/**  
 *  ��������: ģ�洴��add, releaseϵ�к���
		@param FunctionName ����������
		@param ParamType ����������
		@param MemberName ���Ա����
 */
#define FUNCTION_ADD_RELEASE(FunctionName, ParamType, MemberName) \
		public:\
		void Add##FunctionName() { this->MemberName++; } \
		void Release##FunctionName() { this->MemberName--; }

/**  
 *  ��������: ģ�洴��get����
		@param FunctionName ����������
		@param ParamType ����������
		@param MemberName ���Ա����
 */
#define FUNCTION_GET_REF(FunctionName, ParamType, MemberName) \
		public:\
				ParamType& Get##FunctionName() { return this->MemberName; }

/**
 *  ��������: ��std::map<std::string, std::string> ������ȡ����
 *  @param MAP_CONFIG ������ݵ�mapָ��
 *  @param KEY ��ѯ���ݵ�key, std::string&����
 *  @param RETURN_VALUE ����ֵ, std::string&����
 *  @param DEFAULT_VALUE Ĭ��ֵ, const std::string& ����
 */
#define MAP_CONFIG_GET(MAP_CONFIG, KEY, RETURN_VALUE, DEFAULT_VALUE) \
		if (MAP_CONFIG != nullptr && (MAP_CONFIG->find(KEY) != MAP_CONFIG->end()) && (MAP_CONFIG->at(KEY)).empty() == false) { \
				RETURN_VALUE = MAP_CONFIG->at(KEY); \
		} else { \
				RETURN_VALUE = DEFAULT_VALUE; \
		}

/**  
 *  ��������: ģ�洴����ļ���
 *  @param CLASSNAME ��Ҫ�������������
 *  @param DllCreateFunction dll������Create����
 *	@param DllCreateInterface dll�����Ľӿ�
 */
#define MODULE_CLASS_COMMON_DEFINE_(CLASSNAME, DllCreateFunction) \
	typedef std::map<std::string, std::string>* MODULE_CONFIG_POINT; \
	typedef void* (__stdcall *fun_##DllCreateFunction)(MODULE_CONFIG_POINT); \
	ASL_LIBRARY_BEGIN(CLASSNAME##_) \
		ASL_SYMBOL_EXPLICIT(fun_##DllCreateFunction, DllCreateFunction) \
	ASL_LIBRARY_END() \

#define MODULE_CLASS_COMMON_DEFINE(CLASSNAME, DllCreateFunction, DllCreateInterface) \
extern CLASSNAME##_ the##CLASSNAME##_; \
typedef std::map<std::string, std::string>* MODULE_CLASS_CONFIG_POINT; \
class CLASSNAME { \
	public: \
		CLASSNAME() { \
			common_interface = nullptr; \
			is_load_library = false; \
		} \
		~CLASSNAME() { \
			Release(); \
		} \
		bool Init(const char* module_path,MODULE_CLASS_CONFIG_POINT config_map) {\
			if (the##CLASSNAME##_.IsLoaded() == false) { \
				try { \
					the##CLASSNAME##_.Load(module_path); \
				} catch (const ASL::LibraryNotFoundException& e) { \
					return false; \
				} catch (const ASL::SymbolNotFoundException& e) { \
					return false; \
				} \
			} \
			is_load_library = true; \
			common_interface = (DllCreateInterface*)the##CLASSNAME##_.DllCreateFunction(); \
			return common_interface != nullptr; \
		} \
		DllCreateInterface* GetInterface() { \
			return common_interface; \
		} \
		void Release() {\
			safe_release(common_interface); \
		} \
	protected: \
		bool is_load_library; \
		DllCreateInterface *common_interface; \
};

#define MODULE_CLASS_COMMON_DEFINE2(CLASSNAME, DllCreateFunction, DllCreateInterface) \
typedef std::map<std::string, std::string>* MODULE_CLASS_CONFIG_POINT; \
class CLASSNAME { \
	public: \
		CLASSNAME() { \
			common_interface = nullptr; \
								} \
		~CLASSNAME() { \
			Release(); \
								} \
		bool Init(const char* module_path,MODULE_CLASS_CONFIG_POINT config_map) {\
			if (class_name_.IsLoaded() == false) { \
				try { \
					class_name_.Load(module_path); \
				} catch (const ASL::LibraryNotFoundException& e) { \
					return false; \
				} catch (const ASL::SymbolNotFoundException& e) { \
					return false; \
				} \
			} \
			common_interface = (DllCreateInterface*)class_name_.DllCreateFunction(config_map); \
			return common_interface != nullptr; \
								} \
		DllCreateInterface* GetInterface() { \
			return common_interface; \
								} \
		void Release() {\
			safe_release(common_interface); \
								} \
	protected: \
		CLASSNAME##_ class_name_; \
		DllCreateInterface *common_interface; \
};

#endif

/**
 * ��������, Window/Linux����
 */
#if defined(_MSC_VER)
		//  Microsoft
		#define EXPORT __declspec(dllexport)
		#define IMPORT __declspec(dllimport)
#else
		//  GCC
		#define EXPORT __attribute__((visibility("default")))
		#define IMPORT
#endif

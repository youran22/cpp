#ifndef BASIC_INTERFACE_H_7F42EF3C_D0CD_4CF7_BC2B_9995F8478372
#define BASIC_INTERFACE_H_7F42EF3C_D0CD_4CF7_BC2B_9995F8478372

#ifndef OP_OPTIONAL
#define OP_OPTIONAL
#endif

namespace OPLibrary {

// ½Ó¿Ú×î¶¥²ã
class IBasicCommon {
public:
	virtual ~IBasicCommon() {}

	virtual void release() = 0;
};

}

#endif
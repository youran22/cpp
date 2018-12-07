#ifndef __DLLANDROID_H_
#define __DLLANDROID_H_

#ifdef __cplusplus
#	define C_API extern "C"
#else
#	define C_API
#endif

#ifndef API00
#	define API00 _declspec(dllexport)
#endif

#endif //__DLLANDROID_H_

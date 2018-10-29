#ifndef coord_h__
#define coord_h__

#if defined __WIN32  || defined _WIN32
# define OGRE_PLATFORM_WIN32
#elif defined __APPLE_CC__ 
# define OGRE_PLATFORM_APPLE
#else
# define OGRE_PLATFORM_LINUX
#endif

#ifdef OGRE_PLATFORM_WIN32
# define ISNAN _isnan
#else
# define ISNAN isnan
#endif

#ifdef __cplusplus
#define C_API extern "C"
#else
#define C_API 
#endif

#ifndef SOUTH_API_COORD
#define SOUTH_API_COORD
#endif
//#ifndef OGRE_PLATFORM_WIN32
//#define SOUTH_API_COORD __attribute__ ((visibility("default")))
//#endif

struct ProjectPara
{
	int unused;
};
// 投影参数句柄
typedef ProjectPara* HPRJ;

//C_API SOUTH_API_COORD
//void Description(char* res, int size);
//
//C_API SOUTH_API_COORD
//void GetCoordVersion(char* version, int size);

//C_API SOUTH_API_COORD
//bool XYZToBLH(double R,double alfa,double X,double Y,double Z,double* B,double* L,double* H);

//C_API SOUTH_API_COORD
//void BLHToXYZ(double R, double alfa,double B, double L, double H, double* X, double* Y, double* Z);

//C_API SOUTH_API_COORD
//HPRJ CreateProjection(double R,double alfa, double lon_org,double lat_org, int proj_method,
//					  double factor, double proj_height, double false_north, double false_east,
//					  double cutting_radius, double parallel_1, double parallel_2);
//
//C_API SOUTH_API_COORD
//void DeleteProjection(HPRJ proj);
//
//
//C_API SOUTH_API_COORD
//void BLToNE(double B,double L,HPRJ proj,double* N, double* E);
//
//C_API SOUTH_API_COORD
//void NEToBL(double N, double E, HPRJ proj, double* B, double* L);
//
//C_API SOUTH_API_COORD
//HPRJ CreateProjectionOblique(double R,double alfa, double lon_org,double lat_org, int proj_method,
//					  double factor, double false_north, double false_east,
//					  double azimuth, double lon1, double lat1, double lon2, double lat2);
//
//C_API SOUTH_API_COORD
//void DeleteProjectionOblique(HPRJ proj);
//
//C_API SOUTH_API_COORD
//void BLToNEOblique(double B,double L,HPRJ proj,double* N, double* E);
//
//C_API SOUTH_API_COORD
//void NEToBLOblique(double N, double E, HPRJ proj, double* B, double* L);

#ifndef SWIG

C_API SOUTH_API_COORD
void Add(double* a1, double* a2);

C_API SOUTH_API_COORD
void GetName(char *name, int nsize);

#else

C_API SOUTH_API_COORD
void Add(double* OUTPUT, double* OUTPUT);

C_API SOUTH_API_COORD
void GetName(char *BYTE, int nsize);

#endif//SWIG

#endif // coord_h__

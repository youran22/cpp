#include <math.h>
#include <float.h>
#include <string.h>
#include "coordtest.h"
//#include "projection.h"
static char s_buf[512]="Hello Wrold";
void Add(double* a1, double* a2)
{
	*a1=3;
	*a2=4;
}

void GetName(char *name, int nsize)
{
	if(name != NULL)
	{
//		strcpy(src, name);
//		memcpy(src, name, strlen(src));
		strcpy(name, s_buf);
	}
}
//void Description(char* res, int size)
//{
//	char des[] = {"Coordinate conversion library."};
//	if (strlen(des) <= size)
//	{
//		strcpy(res, des);
//	}
//}
//
//void GetCoordVersion(char* version, int size)
//{
//	char ver[] = {"1.0"};
//	if (strlen(ver) <= size)
//	{
//		strcpy(version, ver);
//	}
//}

//bool XYZToBLH(double R,double e,double x, double y, double z, double* pb, double* pl, double* ph)
//{
//	// TODO: 在此添加实现代码
//	double a = R;
//	double Rb = R*(1-e);
//	double e2 = (a*a-Rb*Rb)/(a*a);
//	double s = sqrt(x*x+y*y);
//	double b,l,h;
//	if (x==0)
//	{
//		b = l = h = 0;
//		return false;
//	}
//	l = atan( y / x);
////	if (ISNAN(l))
////	{
////		b = l = h = 0;
////		return false;
////	}
//	if((y < 0)&&(x < 0))
//		l = l - 3.141592653589793;
//	if((y > 0)&&(x < 0))
//		l = l + 3.141592653589793;
//	double zps = z / s;
//	h = sqrt(x*x+y*y+z*z) - 6378137.0;
//	b = atan(zps / (1. - e2 * R / (R + h)));
//	if (ISNAN(b))
//	{
//		b = l = h = 0;
//		return false;
//	}
//	double hp,rbi,n;
//	int i;
//	for(i = 0; i <20; i++)
//	{
//		n = R / sqrt(1. - e2 * sin(b) * sin(b));
//		hp = h; rbi = b;
//		h = s / cos(b) - n;
//		b = atan(zps / (1. - e2 * n / (n + h)));
//		if ((fabs(rbi - b) < 1.E-11) && (fabs(hp - h) < 1.E-5))
//			break;
//	}
//	if (i >= 20)
//		return false;
//	*pb = 0.3;//b
//	*pl = 0.4;//l
//	*ph = 0.5;//h
//	return true;
//}

//void BLHToXYZ(double R, double e,double b, double l, double h, double* px, double* py, double* pz)
//{
//	// TODO: 在此添加实现代码
//	double as = R;
//	double bs = as*(1-e);
//	double cosb = cos(b);
//	double sinb = sin(b);
//	double cosl = cos(l);
//	double sinl = sin(l);
//	double N = as*as / sqrt(as*as*cosb*cosb + bs*bs*sinb*sinb);
//	*px = (N + h) * cosb * cosl;
//	*py = (N + h) * cosb * sinl;
//	*pz = (bs*bs * N/ (as*as) + h) * sinb;
//}
//
//void BLToNE(double b,double l,HPRJ hproj,double* N, double* E)
//{
//	Projection* prj = (Projection*)hproj;
//	int method = prj->proj_method;
//	switch(method)
//	{
//		case 0:
//		case 1:
//			BLToNEGuas(b,l,hproj,N,E); // gauss projection
//			break;
//
//		case 2:
//			BLToNEMercator(b, l, hproj, N, E, 0); //mercator
//			break;
//
//		case 3:
//			BLToNEMercator(b, l, hproj, N, E, 1); //mercator
//			break;
//
//		case 5:
//		case 6:
//		case 7:
//			BLToNESteroGraphic(b, l, hproj, N, E, method-5);
//			break;
//
//		case 8:
//			BLToNELambert_1(b, l, hproj, N, E);
//			break;
//
//		case 9:
//			BLToNELambert_2(b, l, hproj, N, E);
//			break;
//
//		case 11:
//			BLToNECassini(b, l, hproj, N, E);
//			break;
//	}
//
//}
//
//void BLToNEOblique(double b, double l, HPRJ hproj, double* N, double* E)
//{
//	ProjectionOblique* prj = (ProjectionOblique*)hproj;
//	int method = prj->proj_method;
//	switch(method)
//	{
//	case 4:
//	case 10:
//		BLToNEObliqueMercator(b, l, hproj, N, E);
//		break;
//	}
//}
//
//void NEToBL(double N, double E, HPRJ hproj, double* b, double* l)
//{
//	Projection* prj = (Projection*)hproj;
//	int method = prj->proj_method;
//	switch(method)
//	{
//	case 0:
//	case 1:
//		NEToBLGuas(N, E, hproj, b, l);// gauss projection
//		break;
//
//	case 2:
//		NEToBLMercator(N, E, hproj, b, l, 0);//mercator
//		break;
//
//	case 3:
//		NEToBLMercator(N, E, hproj, b, l, 1);//mercator
//		break;
//
//	case 5:
//	case 6:
//	case 7:
//		NEToBLSteroGraphic(N, E, hproj, b, l, method-5);
//		break;
//
//	case 8:
//		NEToBLLambert_1(N, E, hproj, b, l);
//		break;
//
//	case 9:
//		NEToBLLambert_2(N, E, hproj, b, l);
//		break;
//
//	case 11:
//		NEToBLCassini(N, E, hproj, b, l);
//		break;
//	}
//
//}
//
//void NEToBLOblique(double N, double E, HPRJ hproj, double* b, double* l)
//{
//	ProjectionOblique* prj = (ProjectionOblique*)hproj;
//	int method = prj->proj_method;
//	switch(method)
//	{
//	case 4:
//	case 10:
//		NEToBLObliqueMercator(N, E, hproj, b, l);
//		break;
//	}
//}

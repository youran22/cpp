// SouthgnssMapKm2Creater.cpp : 定义 DLL 应用程序的导出函数。
#include "CarBulider.h"
#include <math.h>
#include <fstream>
#include "../common/define_ndk.h"

bool CarBulider::setCarBaseStation(double latitude, double longitude, double altitude)
{
  m_baseLat = latitude;
  m_baseLon = longitude;
  m_baseHgt = altitude;
  return true;
}
bool CarBulider::setCarCoord(SFPoint frontAntennaPoint, SFPoint backAntennaPoint, std::vector<SFPoint> &pts)
{
  m_frontPt = frontAntennaPoint;
  m_backPt = backAntennaPoint;

  m_ptsCoord.clear();
  m_ptsCoord.assign(pts.begin(), pts.end());

  return true;
}

bool CarBulider::calcCarCoord()
{
  const int sz = m_ptsCoord.size();
  m_ptsCar.clear();

  SFPoint xAxis,yAxis;
  yAxis.x = m_frontPt.x - m_backPt.x;
  yAxis.y = m_frontPt.y - m_backPt.y;
  double length = sqrt(yAxis.x*yAxis.x + yAxis.y*yAxis.y);

  yAxis.x /= length;//cos
  yAxis.y /= length;//sin

  xAxis.x = yAxis.y;//sin
  xAxis.y = (-yAxis.x);//-cos

  for(int i=0; i<32; i++)
  {
    const SFPoint &ptCoord = m_ptsCoord.at(i);

    SFPoint pt;
    pt.x = ptCoord.x - m_backPt.x;
    pt.y = ptCoord.y - m_backPt.y;

    pt.x = (pt.x*xAxis.x + pt.y*xAxis.y);
    pt.y = (pt.x*yAxis.x + pt.y*yAxis.y);
    m_ptsCar.push_back(pt);
  }

  bool ret = (m_ptsCar.size()==32);
  return ret;
}

double CarBulider::Angle2Radian(const double a)
{
	return (3.1415926535897932384626433832795/180.0)*a; 
}
double CarBulider::CalcAzi(double x0, double y0, double x1, double y1, bool bRadian)
{
	double azi=0;

	const double x = x1 - x0;
	const double y = y1 - y0;

	//判断条件先后调整	
	if(fabs(x)<=1E-10 && fabs(y)<=1E-10)
	{
		return 0;
	}
	else if(fabs(x) <= 1E-10)
	{
		return (y1-y0)>0 ? 90 : 270;
	}
	else if(fabs(y) <= 1E-10)
	{
		return (x1-x0)>0 ? 0 : 180;
	}


	//返回弧度
	if (bRadian)
	{
		azi = atan2(y, x);
		azi < 0 ? azi+(3.1415926535897932384626433832795*2) : azi;
	}
	else//返回度
	{
		azi = atan2(y, x)*180/3.1415926535897932384626433832795;
		azi = azi<360 ? azi+360 : azi;
		azi = azi>360 ? azi-360 : azi;
	}

	return azi;
}
void CarBulider::rotateZ_GPSCONVERT(const double x, const double y, const double z, double a,double &xout, double &yout, double &zout)  
{//绕Z轴旋转
	xout = x * cos(a) - y * sin(a);
	yout = x * sin(a) + y * cos(a);
	zout = z;
}

//将空间点绕Z轴旋转
//输入参数 x y为空间点原始x y坐标
//thetaz为空间点绕Z轴旋转多少度，角度制范围在-180到180
//outx outy为旋转后的结果坐标
void CarBulider::RotateByZ(double x, double y, double thetaz, double& outx, double& outy)
{
	double x1 = x;//将变量拷贝一次，保证&x == &outx这种情况下也能计算正确
	double y1 = y;
	double rz = thetaz * 3.1415926535897932384626433832795 / 180.0;
	outx = cos(rz) * x1 - sin(rz) * y1;
	outy = sin(rz) * x1 + cos(rz) * y1;

}



//定义返回结构体
struct Point3f
{
	Point3f(double _x, double _y, double _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}
	double x;
	double y;
	double z;
};
//点绕任意向量旋转，右手系
//输入参数old_x，old_y，old_z为旋转前空间点的坐标
//vx，vy，vz为旋转轴向量
//theta为旋转角度角度制，范围在-180到180
//返回值为旋转后坐标点
Point3f RotateByVector(double old_x, double old_y, double old_z, double vx, double vy, double vz, double theta)
{
	double r = theta * 3.1415926535897932384626433832795 / 180;
	double c = cos(r);
	double s = sin(r);
	double new_x = (vx*vx*(1 - c) + c) * old_x + (vx*vy*(1 - c) - vz*s) * old_y + (vx*vz*(1 - c) + vy*s) * old_z;
	double new_y = (vy*vx*(1 - c) + vz*s) * old_x + (vy*vy*(1 - c) + c) * old_y + (vy*vz*(1 - c) - vx*s) * old_z;
	double new_z = (vx*vz*(1 - c) - vy*s) * old_x + (vy*vz*(1 - c) + vx*s) * old_y + (vz*vz*(1 - c) + c) * old_z;
	return Point3f(new_x, new_y, new_z);
}

bool CarBulider::calcCarCoord_2()
{
	m_ptsCar.clear();

	//double ryaw = CalcAzi(m_backPt.y,m_backPt.x,m_frontPt.y,m_frontPt.x,false);
	//ryaw = fmodf(360-(ryaw+270),360.0);
	//ryaw = ryaw<0?ryaw+360:ryaw;
	//ryaw = Angle2Radian(-ryaw);

	double ryaw = CalcAzi(m_frontPt.x,m_frontPt.y,m_backPt.x,m_backPt.y,false);
	//double ryaw = CalcAzi(0,0,1,0,false);
	ryaw = Angle2Radian(360-ryaw+90);

	{
		//char strLine[200];

		//SFPoint pt_q;
		//pt_q.x = m_frontPt.x - m_backPt.x;
		//pt_q.y = m_frontPt.y - m_backPt.y;

		//sprintf(strLine, "org-%d;,00,%.6f,%.6f,0.000\n", -1, pt_q.x, pt_q.y);
		//data.append(strLine);

		//SFPoint pt_h;
		//pt_h.x = m_backPt.x - m_backPt.x;
		//pt_h.y = m_backPt.y - m_backPt.y;
		//sprintf(strLine, "org-%d;,00,%.6f,%.6f,0.000\n", 0, pt_h.x, pt_h.y);
		//data.append(strLine);

		for(int i=0; i<32; i++)
		{
			const SFPoint &ptCoord = m_ptsCoord.at(i);

			SFPoint pt;
			pt.x = ptCoord.x - m_backPt.x;
			pt.y = ptCoord.y - m_backPt.y;

			//sprintf(strLine, "org-%d;,00,%.6f,%.6f,0.000\n", i+1, pt.x, pt.y);
			//data.append(strLine);

			double xout;
			double yout;
			double zout;
			rotateZ_GPSCONVERT(pt.x, pt.y, 0, ryaw,xout, yout, zout);

			pt.x = xout;
			pt.y = yout;

			m_ptsCar.push_back(pt);
		}
	}

	return true;

}

bool CarBulider::convCarPoints(std::string &data)
{
	//return convCarPoints_2(data);

  data.clear();  
  //calcCarCoord();
	calcCarCoord_2();
  
	char strLine[200];
	for(int i=0; i<32; i++)
	{
		const SFPoint &pt = m_ptsCar[i];
		sprintf(strLine, "%d;%.6f,%.6f,0.000\n", i+1, pt.x, pt.y);
		data.append(strLine);
	}

  return true;
}

bool CarBulider::convCarPoints_2(std::string &data)
{
	data.clear();

  //double ryaw = CalcAzi(m_backPt.y,m_backPt.x,m_frontPt.y,m_frontPt.x,false);
  //ryaw = fmodf(360-(ryaw+270),360.0);
  //ryaw = ryaw<0?ryaw+360:ryaw;
  //ryaw = Angle2Radian(-ryaw);

  double ryaw = CalcAzi(m_backPt.x,m_backPt.y,m_frontPt.x,m_frontPt.y,false);
  //double ryaw = CalcAzi(0,0,1,0,false);
  ryaw = Angle2Radian(360-ryaw+90);

  {
	  char strLine[200];

	  //SFPoint pt_q;
	  //pt_q.x = m_frontPt.x - m_backPt.x;
	  //pt_q.y = m_frontPt.y - m_backPt.y;

	  //sprintf(strLine, "org-%d;,00,%.6f,%.6f,0.000\n", -1, pt_q.x, pt_q.y);
	  //data.append(strLine);

	  //SFPoint pt_h;
	  //pt_h.x = m_backPt.x - m_backPt.x;
	  //pt_h.y = m_backPt.y - m_backPt.y;
	  //sprintf(strLine, "org-%d;,00,%.6f,%.6f,0.000\n", 0, pt_h.x, pt_h.y);
	  //data.append(strLine);

	  for(int i=0; i<32; i++)
	  {
		  const SFPoint &ptCoord = m_ptsCoord.at(i);

		  SFPoint pt;
		  pt.x = ptCoord.x - m_backPt.x;
		  pt.y = ptCoord.y - m_backPt.y;

		  //sprintf(strLine, "org-%d;,00,%.6f,%.6f,0.000\n", i+1, pt.x, pt.y);
		  //data.append(strLine);


		  m_ptsCar.push_back(pt);
	  }
  }

  

  /*
  calcCarCoord();
  */

  {
	  char strLine[200];

	  //SFPoint pt_q;
	  //pt_q.x = m_frontPt.x - m_backPt.x;
	  //pt_q.y = m_frontPt.y - m_backPt.y;
	  //double xout;
	  //double yout;
	  //double zout;
	  //rotateZ_GPSCONVERT(pt_q.x, pt_q.y, 0, ryaw,xout, yout, zout);
	  //sprintf(strLine, "##rot-%d;,00,%.6f,%.6f,0.000\n", -1, pt_q.x, pt_q.y);
	  //data.append(strLine);

	  //SFPoint pt_h;
	  //pt_h.x = m_backPt.x - m_backPt.x;
	  //pt_h.y = m_backPt.y - m_backPt.y;
	  //sprintf(strLine, "##rot-%d;,00,%.6f,%.6f,0.000\n", 0, pt_h.x, pt_h.y);
	  //data.append(strLine);

	  for(int i=0; i<32; i++)
	  {
		  SFPoint &pt = m_ptsCar[i];

		  double xout;
		  double yout;
		  double zout;
		  rotateZ_GPSCONVERT(pt.x, pt.y, 0, ryaw,xout, yout, zout);

		  pt.x = xout;
		  pt.y = yout;

		  sprintf(strLine, "%d;%.6f,%.6f,0.000\n", i+1, pt.x, pt.y);
		  data.append(strLine);
	  }
  }

  
  return true;
}

bool CarBulider::convCarCoord(std::string &data)
{
  data.clear();
  data.append("///ExportTime,12345\n");
  data.append("///BaseLatitude,11\n");
  data.append("///BaseLongitude,22\n");
  data.append("///BaseAltitude,33\n");
  data.append("///Measurer,author\n");
  data.append("///CarType,auto\n");
  data.append("///,,,,\n");

  // 前后天线坐标
  char buff[200];
  sprintf(buff, "CX01-htx,,%.6f,%.6f,0.000\n", m_backPt.x, m_backPt.y);
  data.append(buff);

  sprintf(buff, "CX01-qtx,,%.6f,%.6f,0.000\n", m_frontPt.x, m_frontPt.y);
  data.append(buff);

  // 车型数据
  for(int i=0; i<32; i++)
  {
    const SFPoint &pt = m_ptsCar[i];
    sprintf(buff, "%02d,,%.6f,%.6f,0.000\n", i, pt.x, pt.y);
    data.append(buff);
  }
  return true;
}

bool CarBulider::importCarCoord(const char *path)
{
  m_ptsCoord.clear();
  
  char szLine[256];
  std::string strLine;

  ifstream is(path, ios::in);
  while(is.getline(szLine, sizeof(szLine)))
  {
    strLine = szLine;
    const int pos = strLine.find("///");

    if(-1 != pos)
    {
      const int posA = strLine.find(",");
      const int posB = strLine.find(",", posA+1);

      std::string key = strLine.substr(3, (posA-3));
      std::string val = strLine.substr(posB+1, posB);
      continue;
    }

    // 坐标数据
    const int posA = strLine.find(",");
    const int posB = strLine.find(",", posA+1);
    const int posC = strLine.find(",", posB+1);
    const int posD = strLine.find(",", posC+1);

    std::string strName = strLine.substr(0, posA);
    std::string strX = strLine.substr(posB+1, posC-(posB+1));
    std::string strY= strLine.substr(posC+1, posD-(posC+1));

    SFPoint pt;
    pt.x = ndk_atof(strX.c_str());
    pt.y = ndk_atof(strY.c_str());

    if(-1 != strName.find("htx"))
    {
      m_backPt = pt;
    }
    else if(-1 != strName.find("qtx"))
    {
      m_frontPt = pt;
    }
    else
    {
      m_ptsCoord.push_back(pt);
    }
  }
  is.close();

  return true;
}
bool CarBulider::generateCarCoord(const char *path)
{
  std::string data;
  convCarCoord(data);

  ofstream os(path, ios::out);
  os.write(data.c_str(), data.length());
  os.close();

  return true;
}
bool CarBulider::generateCar(const char *path)
{
  std::string data;
  convCarPoints(data);

  ofstream os(path, ios::out);
  os.write(data.c_str(), data.length());
  os.close();

  return true;
}
void CarBulider::cleanCar()
{
  m_ptsCar.clear();
  m_ptsCoord.clear();
}
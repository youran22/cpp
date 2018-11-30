#include <string>
#include <vector>
#include "../common/define.h"

class CarBulider
{
public:
    /**
   * \brief 设置车型基站坐标
   */
  bool setCarBaseStation(double latitude, double longitude, double altitude);
  /**
   * \brief 设置车型数据
   * \param frontAntennaPoint 前天线位置
   * \param backAntennaPoint 后天线位置
   * \param pts 车型采集点
   * \return 
   */
  bool setCarCoord(SFPoint frontAntennaPoint, SFPoint backAntennaPoint, std::vector<SFPoint> &pts);

  bool importCarCoord(const char *path);

  bool generateCarCoord(const char* path);

  bool generateCar(const char* path);
  
  void cleanCar();

private:
	double Angle2Radian(const double a);
	double CalcAzi(double x0, double y0, double x1, double y1, bool bRadian);
	void rotateZ_GPSCONVERT(const double x, const double y, const double z, double a,double &xout, double &yout, double &zout);
	void RotateByZ(double x, double y, double thetaz, double& outx, double& outy);

  bool calcCarCoord();
	bool calcCarCoord_2();
  bool convCarPoints(std::string &data);
	bool convCarPoints_2(std::string &data);
  bool convCarCoord(std::string &data);

  double m_baseLat;
  double m_baseLon;
  double m_baseHgt;

  SFPoint m_frontPt;
  SFPoint m_backPt;
  std::vector<SFPoint> m_ptsCoord;
  std::vector<SFPoint> m_ptsCar;
};
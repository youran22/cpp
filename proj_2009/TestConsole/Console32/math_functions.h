#pragma once

#ifndef _DEBUG

//E:\gnss\southgnss_sdk\include\wgis01_kernel
#ifdef __cplusplus
#	define C_API extern "C"
#endif

#ifndef WGIS01
#	define WGIS01
#endif

class GisRect;

/**
 * 重新设置矩形边界
 * @parms x1 点1的x值
 * @parms y1 点1的y值
 * @parms x2 点2的x值
 * @parms y2 点2的y值
 * @remarks 可以是矩形中的任意两个点
 */
C_API WGIS01 void gis_rect_set2d(GisRect &rect, double x1, double y1, double x2, double y2);

/**
 *	2-4维空间里的正交矩形
 */
class GisRect  
{

public:

	unsigned int dim;

	//! 8个边界
	double xmin, xmax, ymin, ymax, zmin, zmax, tmin, tmax;

	/**
	 * 默认构造函数初始化的Rect为一点
	 */
	GisRect(int _dim=2)
		: dim(_dim)
	{
		setDimension(_dim);
	}

	/**
	 * 构造函数，输入两个点的坐标值
	 * @parms x1 点1的x值
	 * @parms y1 点1的y值
	 * @parms x2 点2的x值
	 * @parms y2 点2的y值
	 * @remarks 可以是矩形中的任意两个点
	 */
	GisRect(double x1,double y1,double x2,double y2)
		: dim(2)
	{
		setDimension(2);
		gis_rect_set2d(*this, x1, y1, x2, y2);
	}

	/**
	 * 构造函数，输入两个点的坐标值
	 * @parms p1 点1实例
	 * @parms p2 点2实例
	 * @remarks 可以是矩形中的任意两个点
	 */
	GisRect(const Point2d &p1,const Point2d &p2)
		: dim(2)
	{
		setDimension(2);
		gis_rect_set2d(*this, p1.x, p1.y, p2.x, p2.y);
	}

	//! 拷贝构造函数:Nonesense. Byte copy is ok.

	//! 矩形赋值:Nonesense. Byte copy is ok.

	/**
	 * 重置矩形维数且初始化坐标值
	 */
	void setDimension(unsigned int _dim)
	{
		dim = _dim;
		//! 构造成min>max的局面，以便merge()方法识别
		xmin=ymin=zmin=tmin= 1;
		xmax=ymax=zmax=tmax=-1;
	}

	/**
	 * 重新设置矩形边界
	 * @parms x_min 左下角点的x值
	 * @parms y_min 左下角点的y值
	 * @parms x_max 右上角点的x值
	 * @parms y_max 右上角点的y值
	 */
	void setExact(double x_min,double y_min,double x_max,double y_max)
	{
		xmin=x_min; ymin=y_min; xmax=x_max; ymax=y_max;
	}

public:

	/// 矩形面积
	double area()const 
	{
		return (xmax-xmin)*(ymax-ymin);
	}

	/// 周长
	double perimeter()const 
	{
		return (xmax-xmin+ymax-ymin)*2;
	}

	/// 矩形中心点
	Point2d center()const 
	{
		return Point2d((xmin+xmax)/2,(ymin+ymax)/2);
	}

	/// 宽度
	double width()const 
	{
		return xmax-xmin;
	}

	/// 高度
	double height()const 
	{
		return ymax-ymin;
	}

	//! 判断是否包含点pnt
	bool contains(const Point2d &pnt)const
	{
		return xmin<=pnt.x && pnt.x<=xmax && ymin<=pnt.y && pnt.y<=ymax;
	}
};

/**
 * 由多个点算出矩形边界
 * @param p 点数组
 * @param N 数组长度
 */
C_API WGIS01 void gis_rect_set_by_coords(GisRect &rect, const Point2d *p, const int N);

C_API WGIS01 void gis_rect_from_csv(GisRect &rect, const char *csvRect);

/**
 * 合并矩形（扩展me的范围以包含o）
 *
 * @param o 要被合并的矩形
 *
 * @return  *this被修改的情况
 *
 * @remarks 返回值为下列值的任意组合：
 *      1	xmin被扩展
 *      2	ymin被扩展
 *      4	xmax被扩展
 *      8	ymax被扩展
 *     16	zmin被扩展
 *     32	tmin被扩展
 *     64	zmax被扩展
 *    128	tmax被扩展
 */
C_API WGIS01 int gis_rect_merge(GisRect &me, const GisRect &o);

/**
 * 生成包含此点的最小矩形
 * @param o 要被包含的点
 * @return 被扩展的部分：
 * @return 1 xmin被扩展
 * @return 2 ymin被扩展
 * @return 4 xmax被扩展
 * @return 8 ymax被扩展
 */
C_API WGIS01 int gis_rect_merge_pnt(GisRect &me, const Point2d &pnt);

/**
 * 将本矩形修改为本矩形与o矩形的交集
 *
 * @return 掩码
 *	 1: xmin被改动
 *	 2: ymin被改动
 *	 4: xmax被改动
 *	 8: ymax被改动
 *	16: 空集!
 *	32: X方向无交集
 *	64: Y方向无交集
 */
C_API WGIS01 int gis_rect_intersect(GisRect &me, const GisRect &o);

/**
 * 保持矩形中心不变，每个限值向外扩展tol单位
 */
C_API WGIS01 GisRect &gis_rect_expand(GisRect &me, const double tol);

/**
 * 保持矩形中心不变，扩大矩形scale倍
 */
C_API WGIS01 GisRect &gis_rect_scale(GisRect &me, const double scale);

/*
 * 按二维向量vec指示平移矩形
 */
C_API WGIS01 GisRect &gis_rect_offset2d(GisRect &me, const Vector2d &vec);

/*
 * 按三维向量vec指示平移矩形
 */
C_API WGIS01 GisRect &gis_rect_offset3d(GisRect &me, const Vector3d &vec);

/*
 * 矩形与向量的加法：按二维向量vec指示平移矩形
 */
inline GisRect operator + (const GisRect &lhs, const Vector2d &vec)
{
	GisRect ret(lhs);
	gis_rect_offset2d(ret, vec);
	return ret;
}

/*
 * 矩形与标量乘法：保持矩形中心不变，扩大矩形scale倍
 */
inline GisRect operator * (const GisRect &lhs, double scale)
{
	GisRect ret(lhs);
	gis_rect_scale(ret, scale);
	return ret;
}

//! 判断矩形是否跨过或包含线段(p1,p2)
C_API WGIS01 bool gis_rect_cross_line(const GisRect &rect, const Point2d &p1, const Point2d &p2);

//! 判断是否与rect有重叠
C_API WGIS01 bool gis_rect_cross_rect(const GisRect &me, const GisRect &o);

//! 判断是否包含矩形o
C_API WGIS01 bool gis_rect_contains_rect(const GisRect &me, const GisRect &o);


#ifdef __cplusplus
#	define C_API extern "C"
#endif

#ifndef WGIS01
#	define WGIS01
#endif

/**
 * （1）折线上共有VC个顶点，编号为0,1,...,VC-1。（VC是VertexCount的简称，下同）
 * （2）折线上共有VC-1个线段，编号为0,1,...,VC-2。
 * （3）折线和线段具有方向，由顶点的顺序定义。
 */
class IPLine
{
public:
	//! VC清0，但保留分配的资源（即v_buf_size和v不变）
	virtual void clear()=0;

	//! 计算m_bnd和m_length
	virtual void refresh()=0;

	/**
	 * 将pnt添加为折线的最后一个顶点
	 *
	 * @pre point_2d_is_valid(pnt)
	 */
	virtual int vertexAdd(const Point2d &pnt)=0;

	/*
	 * 给折线续N个点
	 * @param v: 点数组指针
	 * @param N: 点个数；
	 * @remarks 若N<0，将逆序添加v[]数组中的N个点；
	 */
	virtual int vertexAppend(const Point2d *v, int N)=0;

	// 截断折线: 只留下VC个点
	virtual int vertexTruncate(int VC)=0;

	// 将pnt插入为折线的第index号顶点，
	// （1）原index号顶点改为index+1号顶点，后面的定点以此类推
	// （2）如果index不在范围[0,VC-1]内，行为未定义。
	virtual int vertexIns(int index, Point2d pnt)=0;

	// 删除第index号顶点，返回剩余节点数；
	// 如果index不在范围[0,VC-1]内，行为未定义。
	virtual int vertexDel(int index)=0;

	// 修改第index号顶点的位置为pnt
	// 如果index不在范围[0,VC-1]内，行为未定义。
	virtual int vertexMov(int index, Point2d pnt)=0;

	// 反转折线的方向
	virtual int flip()=0;

	virtual void transform(const ITransform2d *trans)=0;

	virtual int getVCount()const=0;

	virtual const Point2d &vertex(int i)const=0;

	virtual const Point2d *vertexes()const=0;

	virtual GisRect getBND()const=0;

	virtual double getLength()const=0;

	// 把折线当成多边形（连接首尾点），计算该多边形的面积。
	// 约定：右手多边形面积为正，左手多边形面积为负。
	virtual double area()const=0;
};

C_API WGIS01 IPLine *wgis_pline_get_instance();
C_API WGIS01 void wgis_pline_release_instance(IPLine *&p);

// 将折线pl依pnt点一分为二，前段留给pl自己，后段分给plOut
C_API WGIS01 int pline_split(IPLine &pl, IPLine &plOut, const Point2d &pnt, double fuzzy);

// 第index个线段的方向（弧度，X轴向为0，逆时针为正）
C_API WGIS01 double pline_ask_segment_angle(const IPLine &pl, int i);

// 找到与pnt最近的顶点，返回顶点号；
C_API WGIS01 int pline_snap_vertex(const IPLine &pl, const Point2d &pnt, double fuzzy);

// 找到与pnt最近的线段，返回线段号；
C_API WGIS01 int pline_snap_segment(const IPLine &pl, const Point2d &pnt, double fuzzy=0.2);

// 折线上与指定点最近的点位（在段上的垂足，或最近的顶点）
C_API WGIS01 int pline_snap_near(Point2d &ptOut, const IPLine &pl, const Point2d &pnt);

// dist取回点到折线的最短距离，返回值是最近点所在的线段号
// （1）距离具有方向性，左边为正，右边为负；
// （2）所谓最短距离，指绝对值最小的距离；
C_API WGIS01 int pline_point_distance(const IPLine &pl, const Point2d &pnt, double &dist);

//! 折线是否穿过给定的矩形
C_API WGIS01 int pline_cross_rect(const IPLine &pl, const GisRect &rect);
//! 折线代表的多边形是否包含给定的矩形
C_API WGIS01 int pline_contains_rect(const IPLine &pl, const GisRect &rect, double fuzzy);

class PLineW
{
	IPLine *imp;
public:

	PLineW()
	{
		imp = wgis_pline_get_instance();
	}

	~PLineW()
	{
		wgis_pline_release_instance(imp);
	}

	PLineW(const PLineW &_o)
	{
		const IPLine &o(_o.getInnerObject());
		imp = wgis_pline_get_instance();
		imp->vertexAppend(o.vertexes(), o.getVCount());
	}

	PLineW(const IPLine &o)
	{
		imp = wgis_pline_get_instance();
		imp->vertexAppend(o.vertexes(), o.getVCount());
	}

	PLineW &operator=(const IPLine &o)
	{
		if (&o == imp)
			return *this;
		imp->clear();
		imp->vertexAppend(o.vertexes(), o.getVCount());
		return *this;
	}

	IPLine &getInnerObject()
	{
		return *imp;
	}

	const IPLine &getInnerObject()const
	{
		return *imp;
	}
};

/**
 * 针对某个向量为X轴的本地坐标系（：
 * @remarks 此类的实例为不可改(immutable)的
 * @remarks 此类只管旋转的坐标转换，不管缩放等其它仿射变换
 * @remarks 这种坐标系转换对求两个线段的关系有很直观和方便的作用
 */
class LocalCoordSystem2d
{
private:
	//转换前的坐标
	const Point2d m_base;
	//旋转角度的sin和cosin
	double m_cos_a;//方向角的余璇之后的数值；
	double m_sin_a;//方向角的正弦之后的数值；

public:
	//原来（世界）的坐标系：右手法则，x向右，y向上；
	//本地坐标系：
	/// 从原来(世界)的 坐标系坐标 求出 本地坐标系 的 x
	double f_x(const double &x,const double &y)const//参数是什么？
	{
		return m_cos_a*(x-m_base.x)+m_sin_a*(y-m_base.y);//cos值*（世界坐标x-转换前坐标.x) + sin值*（y-转换前坐标y）；返回本地坐标x；
	}

	/// 从原来(世界)的 坐标系坐标 求出 本地坐标系 的 y
	double f_y(const double &x,const double &y)const
	{
		return -m_sin_a*(x-m_base.x)+m_cos_a*(y-m_base.y);
	}

	/// 从 本地坐标系坐标 求出 原来(世界)的坐标系 的 x
	double b_x(const double &x,const double &y)const
	{
		return m_cos_a*x-m_sin_a*y+m_base.x;
	}

	/// 从 本地坐标系坐标 求出 原来(世界)的坐标系 的 y
	double b_y(const double &x,const double &y)const
	{
		return m_sin_a*x+m_cos_a*y+m_base.y;
	}

public:

	/**
	 * 根据起点和初始化x轴初始化此本地坐标系参数
	 * @param origin 起点作为本地坐标系的原点
	 * @param vec 向量的方向 作为 本地坐标系的初始化x轴
	 * @remarks vec is the direction vector of the X axis.
	 */
	LocalCoordSystem2d(const Point2d &origin, const Vector2d &vec)
		:m_base(origin)
	{
		const double vecLen = vec_length(vec);
		m_sin_a = vec.y/vecLen;//sina = y/长度；//
		m_cos_a = vec.x/vecLen;//cosa = x/长度；
	}
	/// 从原来(世界)的坐标系坐标求出本地坐标系的坐标
	Point2d trans_f(double x,double y)const
	{
		return Point2d(f_x(x,y),f_y(x,y));
	}
	/// 从本地坐标系坐标求出原来(世界)的坐标系的坐标
	Point2d trans_b(double x,double y)const
	{
		return Point2d(b_x(x,y),b_y(x,y));
	}
	/// 从原来(世界)的坐标系坐标求出本地坐标系的坐标
	Point2d trans_f(const Point2d& p)const
	{
		return Point2d(f_x(p.x, p.y), f_y(p.x, p.y));
	}
	/// 从本地坐标系坐标求出原来(世界)的坐标系的坐标
	Point2d trans_b(const Point2d& p)const
	{
		return Point2d(b_x(p.x, p.y), b_y(p.x, p.y));//p是指元素在指定里程的相对位置；
		//m_cos_a*x-m_sin_a*y+m_base.x//b.y/b.长度 * x - b.x/b.长度 * y+b.x;//x*sin-y*cos+b.x;//不对？？它的角是靠近x轴的补角？
		//m_sin_a*x+m_cos_a*y+m_base.y//
		//
	}
	//例如：元素的坐标在原来的坐标系中坐标为：coord（x，y）；它的cos：和sin；方位角为：dA；（起点切线方向到水平的角度？）
	//LocalCoordSystem2d（coord，vector2d（cos（dA），sin（dA））；

};

#ifdef __cplusplus
#	define C_API extern "C"
#endif

#ifndef WGIS01
#	define WGIS01
#endif

/// 二维点类
class Point2d
{
public:
	double x,y;

	// Point2d constructors
	Point2d()
		: x(0), y(0)
	{
	}

	Point2d(double _x,double _y)//直接坐标（x，y）作为向量；
		:x(_x),y(_y)
	{
	}

	Point2d(const Point2d &p)//
		:x(p.x),y(p.y)
	{
	}

	// Vector2d generators
	Vector2d operator-(const Point2d &p2)const//两个点相减 返回一个向量；
	{
		return Vector2d(x-p2.x,y-p2.y);
	}

	// Point2d generators
	Point2d operator-(const Vector2d &vec)const//一个点减去一个向量 返回一个点；
	{
		return Point2d(x-vec.x,y-vec.y);
	}

	Point2d operator+(const Vector2d &vec)const//一个点加上一个向量 返回一个点；
	{
		return Point2d(x+vec.x,y+vec.y);
	}

	// Point2d manipulators
	Point2d& operator=(const Point2d& p)
	{
		if(this==&p)
			return *this;
		x=p.x; 
		y=p.y;
		return *this;
	}

	Point2d& operator-=(const Vector2d &o)//-= 一个向量 放回一个点；
	{
		x-=o.x;
		y-=o.y;
		return *this;
	}

	Point2d& operator+=(const Vector2d &o)// += 一个向量 返回一个点；
	{
		x+=o.x;
		y+=o.y;
		return *this;
	}
};

//#include "Vector2d.h"
#ifdef __cplusplus
#	define C_API extern "C"
#endif

#ifndef WGIS01
#	define WGIS01
#endif

/**
 * 圆周率:3.1415926535897932384626
 */
C_API WGIS01 double math_pi();

/**
 * 弧度化度: 180==rad2deg(math_pi())
 */
C_API WGIS01 double rad2deg(double r);

/**
 * 度化弧度: math_pi()==deg2rad(180)
 */
C_API WGIS01 double deg2rad(double d);

/**
 * @brief 二维向量类(2-dimensional geometry features for the GIS platform.)
 *
 * @author wanxiangqian@netease.com,2003-02-28, Point2d, GisRect, LineSeg2d, MATH_PI, epsilon
 *
 * @author wanxiangqian@163.com, 2006-07-05, ITransform2d
 *
 * @author wanxiangqian@163.com, 2007-10-05, Vector2d, LocalCoordSystem2d
 */
class Vector2d  
{
public:
	double x,y;

	Vector2d()
	{
	}
	Vector2d(double _x,double _y)//x，y坐标做向量，就是0,0到x，y的向量
		:x(_x),y(_y)
	{
	}
	Vector2d(const Vector2d &p)//已另外一条向量
		:x(p.x),y(p.y)
	{
	}
	Vector2d& operator=(const Vector2d& p)//赋值函数
	{
		if(this==&p)
			return *this;
		x=p.x; 
		y=p.y;
		return *this;
	}

	Vector2d& operator-=(const Vector2d &o)//-=函数
	{
		x-=o.x;
		y-=o.y;
		return *this;
	}
	Vector2d& operator+=(const Vector2d &o)
	{
		x+=o.x;
		y+=o.y;
		return *this;
	}
	Vector2d& operator*=(const double s)//*=函数
	{
		x*=s;
		y*=s;
		return *this;
	}
	Vector2d& operator/=(double s)
	{
		x/=s;
		y/=s;
		return *this;
	}

public: // others

	/** 
	 * 单目运算--翻转方向
	 */
	Vector2d operator-()const//取反函数-
	{
		return Vector2d(-x,-y);
	}
	Vector2d operator-(const Vector2d &p2)const//-
	{
		return Vector2d(x-p2.x,y-p2.y);
	}
	Vector2d operator+(const Vector2d &p2)const//+ 
	{
		return Vector2d(x+p2.x,y+p2.y);
	}
	Vector2d operator*(double s)const 
	{
		return Vector2d(x*s,y*s);
	}
	Vector2d operator/(double s)const
	{
		return Vector2d(x/s,y/s);
	}

	//! 向量点积,例如 力矢量 * 位移矢量 = 做功
	double dotProduct(const Vector2d &vec)const
	{
		return x*vec.x+y*vec.y;
	}

	//! 向量长度平方（模）（比长度少点计算量）
	double vecLen2()const//x*x + y*y;
	{
		return dotProduct(*this);
	}
};

//! 将向量的|模|变为指定值：R*(cos(φ)+i*sin(φ)) => norm*(cos(φ)+i*sin(φ))
C_API WGIS01 Vector2d &vec_set_normal(Vector2d &vec, double norm);

//! 向量点积,例如 力矢量 * 位移矢量 = 做功
inline double vec_dot_product(const Vector2d &lhs, const Vector2d &rhs)
{
	return lhs.dotProduct(rhs);
}

/**
 * 向量旋转
 * @param angle 旋转角，度，x指东y指北时逆时针为正，x指北y指东时顺时针为正//不对吧？？
 * @remarks 精度只能达到1E-7(0.0000001)
 */
C_API WGIS01 Vector2d &vec_rotate(Vector2d &vec, double angle);//x指东，y指北：逆时针为正；x指北，y指东：顺时针为正；

/**
 * 向量长度（模）：math_sqrt(vec.vecLen2())
 */
C_API WGIS01 double vec_length(const Vector2d &vec);

/**
 * 向量角:取值范围是(-180,180], 三点钟方向为零，逆时针方向为正
 */
C_API WGIS01 double vec_angle(const Vector2d &vec);//三点种方向为0，逆时针方向为正；取值范围是（-180,180]

/**
 * 数学角度 转换为 方位角（度）
 * @return 值域是[0,360)
 * @remarks 向量方位角 起始于 Y轴正向（北向），顺时针为正
 */
C_API WGIS01 double math_angle_to_azimuth(double angle);

/**
 * 方位角 转换 为数学角度（度）
 * @return 值域是(-180,180]
 * @remarks 向量方位角 起始于 Y轴正向（北向），顺时针为正
 */
C_API WGIS01 double azimuth_to_math_angle(double azimuth);











bool GetXYandAngle(const double& dL, const double& dOffset, Point2d &pntXY, double &angle, unsigned short &overHgt);

//计算两点距离，简单计算
double calc_dist(const double &x0, const double &y0, const double &x1, const double &y1)
{
	const double result = sqrt(pow(y1-y0, 2) + pow(x1-x0, 2));//pow是指平方？？
	//Point2d pnt0(x0,y0);
	//Point2d pnt1(x1,y1);
	//const double result = vec_length(pnt1-pnt0);
	return result;

}

double azimuth_normalize(double a)
{
	double ret = a;
	if (ret<0)
	{
		while (ret<0)
		{
			ret += 360;
		}
	}
	else if (360<=ret)
	{
		while (360<=ret)
		{
			ret -= 360;
		}
	}
	return ret;
}
//计算方位角
double calc_azimuth(double x0, double y0, double x1, double y1)
{
	//点(x0,y0)到(x1,y1)的方位角//也就是atan2（y1-y0,x1-x0);获取的是弧度的角度；为什么是(y1-y0,为前呢？
	double azi = rad2deg(atan2(y1-y0, x1-x0));

	//确保结果大于0
	if (azi < 0)
	{
		azi += 360;
	}

	return azi;
}
//计算方位角
double calc_azimuth(double x0, double y0, double x1, double y1)
{
	Point2d pnt0(x0,y0);
	Point2d pnt1(x1,y1);
	//点(x0,y0)到(x1,y1)的方位角
	double azi = azimuth_normalize(vec_angle(pnt1-pnt0));

	return azi;
}

double calc_azimuth(double aNorth, double aEast, double bNorth, double bEast, bool bRadian)
{
	const double x = bNorth - aNorth;
	const double y = bEast - aEast;

	//判断条件先后调整		[2015-02-27 hervey]
	if(fabs(x)<=1E-10 && fabs(y)<=1E-10)
	{
		return 0;
	}
	else if(fabs(x) <= 1E-10)
	{
		return (bEast-aEast)>0 ? 90 : 270;
	}
	else if(fabs(y) <= 1E-10)
	{
		return (bNorth-aNorth)>0 ? 0 : 180;
	}

	// 返回度
	double azi = azimuth_normalize(rad2deg(atan2(y, x)));
	if (bRadian)
	{
		//返回弧度
		azi = deg2rad(azi);
	}

	return azi;
}
void calc_azimuth_test()
{
	//dic.setValue("dNorth", "58782.932");
	//dic.setValue("dEast",  "4505.692");
	Point2d pnt1(0, 0);
	Point2d pnt2(0, 1);
	double azimuth = 0;
	azimuth = calc_azimuth(pnt1.x, pnt1.y, pnt2.x, pnt2.y);
	//AUTO_TEST_ASSERT_DOUBLES_EQUAL(90, azimuth, TOL7);//待完善；
	azimuth = calc_azimuth(pnt2.x, pnt2.y, pnt1.x, pnt1.y);//pnt2在前？
	//AUTO_TEST_ASSERT_DOUBLES_EQUAL(270, azimuth, TOL7);
	azimuth = calc_azimuth(pnt1.y, pnt1.x, pnt2.y, pnt2.x);//坐标翻转？
	Vector2d vec2 = vec_rotate(Vector2d(0,1),-90);
	//AUTO_TEST_ASSERT_DOUBLES_EQUAL(0, azimuth, TOL7);
}


#ifndef API04
#	define API04
#endif
/**
 *方位角计算：计算点A(x0,y0)到点B(x1,y1)向量的方位角
 *
 * @param x0					点A的北坐标
 * @param y0					点A的东标
 * @param x1					点B的北坐标
 * @param y1					点B的东坐标
 * @param bRadian				是否返回弧度，true返回弧度，false返回角度
 * @return						返回方位角
 */
C_API API04 double calc_azimuth(double aNorth, double aEast, double bNorth, double bEast, bool bRadian=false);
double calc_azimuth(double aNorth, double aEast, double bNorth, double bEast, bool bRadian)
{
	const double x = bNorth - aNorth;//x指向北，y指向西；逆时针方向为正；
	const double y = bEast - aEast;

	//判断条件先后调整		[2015-02-27 hervey]
	if(fabs(x)<=1E-10 && fabs(y)<=1E-10)
	{
		return 0;
	}
	else if(fabs(x) <= 1E-10)//北值相等；
	{
		return (bEast-aEast)>0 ? 90 : 270;//跟东平行，则垂直，要么90要么270；
	}
	else if(fabs(y) <= 1E-10)
	{
		return (bNorth-aNorth)>0 ? 0 : 180;
	}

	// 返回度
	double azi = azimuth_normalize(rad2deg(atan2(y, x)));
	if (bRadian)
	{
		//返回弧度
		azi = deg2rad(azi);
	}

	return azi;
}
double cogo_dist3d(double x1, double y1, double h1, double x2, double y2, double h2)
{
	return sqrt( pow((x1-x2),2) + pow((y1-y2),2) + pow((h1-h2),2) );
}

#endif
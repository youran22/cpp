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
 * �������þ��α߽�
 * @parms x1 ��1��xֵ
 * @parms y1 ��1��yֵ
 * @parms x2 ��2��xֵ
 * @parms y2 ��2��yֵ
 * @remarks �����Ǿ����е�����������
 */
C_API WGIS01 void gis_rect_set2d(GisRect &rect, double x1, double y1, double x2, double y2);

/**
 *	2-4ά�ռ������������
 */
class GisRect  
{

public:

	unsigned int dim;

	//! 8���߽�
	double xmin, xmax, ymin, ymax, zmin, zmax, tmin, tmax;

	/**
	 * Ĭ�Ϲ��캯����ʼ����RectΪһ��
	 */
	GisRect(int _dim=2)
		: dim(_dim)
	{
		setDimension(_dim);
	}

	/**
	 * ���캯�������������������ֵ
	 * @parms x1 ��1��xֵ
	 * @parms y1 ��1��yֵ
	 * @parms x2 ��2��xֵ
	 * @parms y2 ��2��yֵ
	 * @remarks �����Ǿ����е�����������
	 */
	GisRect(double x1,double y1,double x2,double y2)
		: dim(2)
	{
		setDimension(2);
		gis_rect_set2d(*this, x1, y1, x2, y2);
	}

	/**
	 * ���캯�������������������ֵ
	 * @parms p1 ��1ʵ��
	 * @parms p2 ��2ʵ��
	 * @remarks �����Ǿ����е�����������
	 */
	GisRect(const Point2d &p1,const Point2d &p2)
		: dim(2)
	{
		setDimension(2);
		gis_rect_set2d(*this, p1.x, p1.y, p2.x, p2.y);
	}

	//! �������캯��:Nonesense. Byte copy is ok.

	//! ���θ�ֵ:Nonesense. Byte copy is ok.

	/**
	 * ���þ���ά���ҳ�ʼ������ֵ
	 */
	void setDimension(unsigned int _dim)
	{
		dim = _dim;
		//! �����min>max�ľ��棬�Ա�merge()����ʶ��
		xmin=ymin=zmin=tmin= 1;
		xmax=ymax=zmax=tmax=-1;
	}

	/**
	 * �������þ��α߽�
	 * @parms x_min ���½ǵ��xֵ
	 * @parms y_min ���½ǵ��yֵ
	 * @parms x_max ���Ͻǵ��xֵ
	 * @parms y_max ���Ͻǵ��yֵ
	 */
	void setExact(double x_min,double y_min,double x_max,double y_max)
	{
		xmin=x_min; ymin=y_min; xmax=x_max; ymax=y_max;
	}

public:

	/// �������
	double area()const 
	{
		return (xmax-xmin)*(ymax-ymin);
	}

	/// �ܳ�
	double perimeter()const 
	{
		return (xmax-xmin+ymax-ymin)*2;
	}

	/// �������ĵ�
	Point2d center()const 
	{
		return Point2d((xmin+xmax)/2,(ymin+ymax)/2);
	}

	/// ���
	double width()const 
	{
		return xmax-xmin;
	}

	/// �߶�
	double height()const 
	{
		return ymax-ymin;
	}

	//! �ж��Ƿ������pnt
	bool contains(const Point2d &pnt)const
	{
		return xmin<=pnt.x && pnt.x<=xmax && ymin<=pnt.y && pnt.y<=ymax;
	}
};

/**
 * �ɶ����������α߽�
 * @param p ������
 * @param N ���鳤��
 */
C_API WGIS01 void gis_rect_set_by_coords(GisRect &rect, const Point2d *p, const int N);

C_API WGIS01 void gis_rect_from_csv(GisRect &rect, const char *csvRect);

/**
 * �ϲ����Σ���չme�ķ�Χ�԰���o��
 *
 * @param o Ҫ���ϲ��ľ���
 *
 * @return  *this���޸ĵ����
 *
 * @remarks ����ֵΪ����ֵ��������ϣ�
 *      1	xmin����չ
 *      2	ymin����չ
 *      4	xmax����չ
 *      8	ymax����չ
 *     16	zmin����չ
 *     32	tmin����չ
 *     64	zmax����չ
 *    128	tmax����չ
 */
C_API WGIS01 int gis_rect_merge(GisRect &me, const GisRect &o);

/**
 * ���ɰ����˵����С����
 * @param o Ҫ�������ĵ�
 * @return ����չ�Ĳ��֣�
 * @return 1 xmin����չ
 * @return 2 ymin����չ
 * @return 4 xmax����չ
 * @return 8 ymax����չ
 */
C_API WGIS01 int gis_rect_merge_pnt(GisRect &me, const Point2d &pnt);

/**
 * ���������޸�Ϊ��������o���εĽ���
 *
 * @return ����
 *	 1: xmin���Ķ�
 *	 2: ymin���Ķ�
 *	 4: xmax���Ķ�
 *	 8: ymax���Ķ�
 *	16: �ռ�!
 *	32: X�����޽���
 *	64: Y�����޽���
 */
C_API WGIS01 int gis_rect_intersect(GisRect &me, const GisRect &o);

/**
 * ���־������Ĳ��䣬ÿ����ֵ������չtol��λ
 */
C_API WGIS01 GisRect &gis_rect_expand(GisRect &me, const double tol);

/**
 * ���־������Ĳ��䣬�������scale��
 */
C_API WGIS01 GisRect &gis_rect_scale(GisRect &me, const double scale);

/*
 * ����ά����vecָʾƽ�ƾ���
 */
C_API WGIS01 GisRect &gis_rect_offset2d(GisRect &me, const Vector2d &vec);

/*
 * ����ά����vecָʾƽ�ƾ���
 */
C_API WGIS01 GisRect &gis_rect_offset3d(GisRect &me, const Vector3d &vec);

/*
 * �����������ļӷ�������ά����vecָʾƽ�ƾ���
 */
inline GisRect operator + (const GisRect &lhs, const Vector2d &vec)
{
	GisRect ret(lhs);
	gis_rect_offset2d(ret, vec);
	return ret;
}

/*
 * ����������˷������־������Ĳ��䣬�������scale��
 */
inline GisRect operator * (const GisRect &lhs, double scale)
{
	GisRect ret(lhs);
	gis_rect_scale(ret, scale);
	return ret;
}

//! �жϾ����Ƿ���������߶�(p1,p2)
C_API WGIS01 bool gis_rect_cross_line(const GisRect &rect, const Point2d &p1, const Point2d &p2);

//! �ж��Ƿ���rect���ص�
C_API WGIS01 bool gis_rect_cross_rect(const GisRect &me, const GisRect &o);

//! �ж��Ƿ��������o
C_API WGIS01 bool gis_rect_contains_rect(const GisRect &me, const GisRect &o);


#ifdef __cplusplus
#	define C_API extern "C"
#endif

#ifndef WGIS01
#	define WGIS01
#endif

/**
 * ��1�������Ϲ���VC�����㣬���Ϊ0,1,...,VC-1����VC��VertexCount�ļ�ƣ���ͬ��
 * ��2�������Ϲ���VC-1���߶Σ����Ϊ0,1,...,VC-2��
 * ��3�����ߺ��߶ξ��з����ɶ����˳���塣
 */
class IPLine
{
public:
	//! VC��0���������������Դ����v_buf_size��v���䣩
	virtual void clear()=0;

	//! ����m_bnd��m_length
	virtual void refresh()=0;

	/**
	 * ��pnt���Ϊ���ߵ����һ������
	 *
	 * @pre point_2d_is_valid(pnt)
	 */
	virtual int vertexAdd(const Point2d &pnt)=0;

	/*
	 * ��������N����
	 * @param v: ������ָ��
	 * @param N: �������
	 * @remarks ��N<0�����������v[]�����е�N���㣻
	 */
	virtual int vertexAppend(const Point2d *v, int N)=0;

	// �ض�����: ֻ����VC����
	virtual int vertexTruncate(int VC)=0;

	// ��pnt����Ϊ���ߵĵ�index�Ŷ��㣬
	// ��1��ԭindex�Ŷ����Ϊindex+1�Ŷ��㣬����Ķ����Դ�����
	// ��2�����index���ڷ�Χ[0,VC-1]�ڣ���Ϊδ���塣
	virtual int vertexIns(int index, Point2d pnt)=0;

	// ɾ����index�Ŷ��㣬����ʣ��ڵ�����
	// ���index���ڷ�Χ[0,VC-1]�ڣ���Ϊδ���塣
	virtual int vertexDel(int index)=0;

	// �޸ĵ�index�Ŷ����λ��Ϊpnt
	// ���index���ڷ�Χ[0,VC-1]�ڣ���Ϊδ���塣
	virtual int vertexMov(int index, Point2d pnt)=0;

	// ��ת���ߵķ���
	virtual int flip()=0;

	virtual void transform(const ITransform2d *trans)=0;

	virtual int getVCount()const=0;

	virtual const Point2d &vertex(int i)const=0;

	virtual const Point2d *vertexes()const=0;

	virtual GisRect getBND()const=0;

	virtual double getLength()const=0;

	// �����ߵ��ɶ���Σ�������β�㣩������ö���ε������
	// Լ�������ֶ�������Ϊ�������ֶ�������Ϊ����
	virtual double area()const=0;
};

C_API WGIS01 IPLine *wgis_pline_get_instance();
C_API WGIS01 void wgis_pline_release_instance(IPLine *&p);

// ������pl��pnt��һ��Ϊ����ǰ������pl�Լ�����ηָ�plOut
C_API WGIS01 int pline_split(IPLine &pl, IPLine &plOut, const Point2d &pnt, double fuzzy);

// ��index���߶εķ��򣨻��ȣ�X����Ϊ0����ʱ��Ϊ����
C_API WGIS01 double pline_ask_segment_angle(const IPLine &pl, int i);

// �ҵ���pnt����Ķ��㣬���ض���ţ�
C_API WGIS01 int pline_snap_vertex(const IPLine &pl, const Point2d &pnt, double fuzzy);

// �ҵ���pnt������߶Σ������߶κţ�
C_API WGIS01 int pline_snap_segment(const IPLine &pl, const Point2d &pnt, double fuzzy=0.2);

// ��������ָ��������ĵ�λ���ڶ��ϵĴ��㣬������Ķ��㣩
C_API WGIS01 int pline_snap_near(Point2d &ptOut, const IPLine &pl, const Point2d &pnt);

// distȡ�ص㵽���ߵ���̾��룬����ֵ����������ڵ��߶κ�
// ��1��������з����ԣ����Ϊ�����ұ�Ϊ����
// ��2����ν��̾��룬ָ����ֵ��С�ľ��룻
C_API WGIS01 int pline_point_distance(const IPLine &pl, const Point2d &pnt, double &dist);

//! �����Ƿ񴩹������ľ���
C_API WGIS01 int pline_cross_rect(const IPLine &pl, const GisRect &rect);
//! ���ߴ���Ķ�����Ƿ���������ľ���
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
 * ���ĳ������ΪX��ı�������ϵ����
 * @remarks �����ʵ��Ϊ���ɸ�(immutable)��
 * @remarks ����ֻ����ת������ת�����������ŵ���������任
 * @remarks ��������ϵת�����������߶εĹ�ϵ�к�ֱ�ۺͷ��������
 */
class LocalCoordSystem2d
{
private:
	//ת��ǰ������
	const Point2d m_base;
	//��ת�Ƕȵ�sin��cosin
	double m_cos_a;//����ǵ����֮�����ֵ��
	double m_sin_a;//����ǵ�����֮�����ֵ��

public:
	//ԭ�������磩������ϵ�����ַ���x���ң�y���ϣ�
	//��������ϵ��
	/// ��ԭ��(����)�� ����ϵ���� ��� ��������ϵ �� x
	double f_x(const double &x,const double &y)const//������ʲô��
	{
		return m_cos_a*(x-m_base.x)+m_sin_a*(y-m_base.y);//cosֵ*����������x-ת��ǰ����.x) + sinֵ*��y-ת��ǰ����y�������ر�������x��
	}

	/// ��ԭ��(����)�� ����ϵ���� ��� ��������ϵ �� y
	double f_y(const double &x,const double &y)const
	{
		return -m_sin_a*(x-m_base.x)+m_cos_a*(y-m_base.y);
	}

	/// �� ��������ϵ���� ��� ԭ��(����)������ϵ �� x
	double b_x(const double &x,const double &y)const
	{
		return m_cos_a*x-m_sin_a*y+m_base.x;
	}

	/// �� ��������ϵ���� ��� ԭ��(����)������ϵ �� y
	double b_y(const double &x,const double &y)const
	{
		return m_sin_a*x+m_cos_a*y+m_base.y;
	}

public:

	/**
	 * �������ͳ�ʼ��x���ʼ���˱�������ϵ����
	 * @param origin �����Ϊ��������ϵ��ԭ��
	 * @param vec �����ķ��� ��Ϊ ��������ϵ�ĳ�ʼ��x��
	 * @remarks vec is the direction vector of the X axis.
	 */
	LocalCoordSystem2d(const Point2d &origin, const Vector2d &vec)
		:m_base(origin)
	{
		const double vecLen = vec_length(vec);
		m_sin_a = vec.y/vecLen;//sina = y/���ȣ�//
		m_cos_a = vec.x/vecLen;//cosa = x/���ȣ�
	}
	/// ��ԭ��(����)������ϵ���������������ϵ������
	Point2d trans_f(double x,double y)const
	{
		return Point2d(f_x(x,y),f_y(x,y));
	}
	/// �ӱ�������ϵ�������ԭ��(����)������ϵ������
	Point2d trans_b(double x,double y)const
	{
		return Point2d(b_x(x,y),b_y(x,y));
	}
	/// ��ԭ��(����)������ϵ���������������ϵ������
	Point2d trans_f(const Point2d& p)const
	{
		return Point2d(f_x(p.x, p.y), f_y(p.x, p.y));
	}
	/// �ӱ�������ϵ�������ԭ��(����)������ϵ������
	Point2d trans_b(const Point2d& p)const
	{
		return Point2d(b_x(p.x, p.y), b_y(p.x, p.y));//p��ָԪ����ָ����̵����λ�ã�
		//m_cos_a*x-m_sin_a*y+m_base.x//b.y/b.���� * x - b.x/b.���� * y+b.x;//x*sin-y*cos+b.x;//���ԣ������Ľ��ǿ���x��Ĳ��ǣ�
		//m_sin_a*x+m_cos_a*y+m_base.y//
		//
	}
	//���磺Ԫ�ص�������ԭ��������ϵ������Ϊ��coord��x��y��������cos����sin����λ��Ϊ��dA����������߷���ˮƽ�ĽǶȣ���
	//LocalCoordSystem2d��coord��vector2d��cos��dA����sin��dA������

};

#ifdef __cplusplus
#	define C_API extern "C"
#endif

#ifndef WGIS01
#	define WGIS01
#endif

/// ��ά����
class Point2d
{
public:
	double x,y;

	// Point2d constructors
	Point2d()
		: x(0), y(0)
	{
	}

	Point2d(double _x,double _y)//ֱ�����꣨x��y����Ϊ������
		:x(_x),y(_y)
	{
	}

	Point2d(const Point2d &p)//
		:x(p.x),y(p.y)
	{
	}

	// Vector2d generators
	Vector2d operator-(const Point2d &p2)const//��������� ����һ��������
	{
		return Vector2d(x-p2.x,y-p2.y);
	}

	// Point2d generators
	Point2d operator-(const Vector2d &vec)const//һ�����ȥһ������ ����һ���㣻
	{
		return Point2d(x-vec.x,y-vec.y);
	}

	Point2d operator+(const Vector2d &vec)const//һ�������һ������ ����һ���㣻
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

	Point2d& operator-=(const Vector2d &o)//-= һ������ �Ż�һ���㣻
	{
		x-=o.x;
		y-=o.y;
		return *this;
	}

	Point2d& operator+=(const Vector2d &o)// += һ������ ����һ���㣻
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
 * Բ����:3.1415926535897932384626
 */
C_API WGIS01 double math_pi();

/**
 * ���Ȼ���: 180==rad2deg(math_pi())
 */
C_API WGIS01 double rad2deg(double r);

/**
 * �Ȼ�����: math_pi()==deg2rad(180)
 */
C_API WGIS01 double deg2rad(double d);

/**
 * @brief ��ά������(2-dimensional geometry features for the GIS platform.)
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
	Vector2d(double _x,double _y)//x��y����������������0,0��x��y������
		:x(_x),y(_y)
	{
	}
	Vector2d(const Vector2d &p)//������һ������
		:x(p.x),y(p.y)
	{
	}
	Vector2d& operator=(const Vector2d& p)//��ֵ����
	{
		if(this==&p)
			return *this;
		x=p.x; 
		y=p.y;
		return *this;
	}

	Vector2d& operator-=(const Vector2d &o)//-=����
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
	Vector2d& operator*=(const double s)//*=����
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
	 * ��Ŀ����--��ת����
	 */
	Vector2d operator-()const//ȡ������-
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

	//! �������,���� ��ʸ�� * λ��ʸ�� = ����
	double dotProduct(const Vector2d &vec)const
	{
		return x*vec.x+y*vec.y;
	}

	//! ��������ƽ����ģ�����ȳ����ٵ��������
	double vecLen2()const//x*x + y*y;
	{
		return dotProduct(*this);
	}
};

//! ��������|ģ|��Ϊָ��ֵ��R*(cos(��)+i*sin(��)) => norm*(cos(��)+i*sin(��))
C_API WGIS01 Vector2d &vec_set_normal(Vector2d &vec, double norm);

//! �������,���� ��ʸ�� * λ��ʸ�� = ����
inline double vec_dot_product(const Vector2d &lhs, const Vector2d &rhs)
{
	return lhs.dotProduct(rhs);
}

/**
 * ������ת
 * @param angle ��ת�ǣ��ȣ�xָ��yָ��ʱ��ʱ��Ϊ����xָ��yָ��ʱ˳ʱ��Ϊ��//���԰ɣ���
 * @remarks ����ֻ�ܴﵽ1E-7(0.0000001)
 */
C_API WGIS01 Vector2d &vec_rotate(Vector2d &vec, double angle);//xָ����yָ������ʱ��Ϊ����xָ����yָ����˳ʱ��Ϊ����

/**
 * �������ȣ�ģ����math_sqrt(vec.vecLen2())
 */
C_API WGIS01 double vec_length(const Vector2d &vec);

/**
 * ������:ȡֵ��Χ��(-180,180], �����ӷ���Ϊ�㣬��ʱ�뷽��Ϊ��
 */
C_API WGIS01 double vec_angle(const Vector2d &vec);//�����ַ���Ϊ0����ʱ�뷽��Ϊ����ȡֵ��Χ�ǣ�-180,180]

/**
 * ��ѧ�Ƕ� ת��Ϊ ��λ�ǣ��ȣ�
 * @return ֵ����[0,360)
 * @remarks ������λ�� ��ʼ�� Y�����򣨱��򣩣�˳ʱ��Ϊ��
 */
C_API WGIS01 double math_angle_to_azimuth(double angle);

/**
 * ��λ�� ת�� Ϊ��ѧ�Ƕȣ��ȣ�
 * @return ֵ����(-180,180]
 * @remarks ������λ�� ��ʼ�� Y�����򣨱��򣩣�˳ʱ��Ϊ��
 */
C_API WGIS01 double azimuth_to_math_angle(double azimuth);











bool GetXYandAngle(const double& dL, const double& dOffset, Point2d &pntXY, double &angle, unsigned short &overHgt);

//����������룬�򵥼���
double calc_dist(const double &x0, const double &y0, const double &x1, const double &y1)
{
	const double result = sqrt(pow(y1-y0, 2) + pow(x1-x0, 2));//pow��ָƽ������
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
//���㷽λ��
double calc_azimuth(double x0, double y0, double x1, double y1)
{
	//��(x0,y0)��(x1,y1)�ķ�λ��//Ҳ����atan2��y1-y0,x1-x0);��ȡ���ǻ��ȵĽǶȣ�Ϊʲô��(y1-y0,Ϊǰ�أ�
	double azi = rad2deg(atan2(y1-y0, x1-x0));

	//ȷ���������0
	if (azi < 0)
	{
		azi += 360;
	}

	return azi;
}
//���㷽λ��
double calc_azimuth(double x0, double y0, double x1, double y1)
{
	Point2d pnt0(x0,y0);
	Point2d pnt1(x1,y1);
	//��(x0,y0)��(x1,y1)�ķ�λ��
	double azi = azimuth_normalize(vec_angle(pnt1-pnt0));

	return azi;
}

double calc_azimuth(double aNorth, double aEast, double bNorth, double bEast, bool bRadian)
{
	const double x = bNorth - aNorth;
	const double y = bEast - aEast;

	//�ж������Ⱥ����		[2015-02-27 hervey]
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

	// ���ض�
	double azi = azimuth_normalize(rad2deg(atan2(y, x)));
	if (bRadian)
	{
		//���ػ���
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
	//AUTO_TEST_ASSERT_DOUBLES_EQUAL(90, azimuth, TOL7);//�����ƣ�
	azimuth = calc_azimuth(pnt2.x, pnt2.y, pnt1.x, pnt1.y);//pnt2��ǰ��
	//AUTO_TEST_ASSERT_DOUBLES_EQUAL(270, azimuth, TOL7);
	azimuth = calc_azimuth(pnt1.y, pnt1.x, pnt2.y, pnt2.x);//���귭ת��
	Vector2d vec2 = vec_rotate(Vector2d(0,1),-90);
	//AUTO_TEST_ASSERT_DOUBLES_EQUAL(0, azimuth, TOL7);
}


#ifndef API04
#	define API04
#endif
/**
 *��λ�Ǽ��㣺�����A(x0,y0)����B(x1,y1)�����ķ�λ��
 *
 * @param x0					��A�ı�����
 * @param y0					��A�Ķ���
 * @param x1					��B�ı�����
 * @param y1					��B�Ķ�����
 * @param bRadian				�Ƿ񷵻ػ��ȣ�true���ػ��ȣ�false���ؽǶ�
 * @return						���ط�λ��
 */
C_API API04 double calc_azimuth(double aNorth, double aEast, double bNorth, double bEast, bool bRadian=false);
double calc_azimuth(double aNorth, double aEast, double bNorth, double bEast, bool bRadian)
{
	const double x = bNorth - aNorth;//xָ�򱱣�yָ��������ʱ�뷽��Ϊ����
	const double y = bEast - aEast;

	//�ж������Ⱥ����		[2015-02-27 hervey]
	if(fabs(x)<=1E-10 && fabs(y)<=1E-10)
	{
		return 0;
	}
	else if(fabs(x) <= 1E-10)//��ֵ��ȣ�
	{
		return (bEast-aEast)>0 ? 90 : 270;//����ƽ�У���ֱ��Ҫô90Ҫô270��
	}
	else if(fabs(y) <= 1E-10)
	{
		return (bNorth-aNorth)>0 ? 0 : 180;
	}

	// ���ض�
	double azi = azimuth_normalize(rad2deg(atan2(y, x)));
	if (bRadian)
	{
		//���ػ���
		azi = deg2rad(azi);
	}

	return azi;
}
double cogo_dist3d(double x1, double y1, double h1, double x2, double y2, double h2)
{
	return sqrt( pow((x1-x2),2) + pow((y1-y2),2) + pow((h1-h2),2) );
}

#endif
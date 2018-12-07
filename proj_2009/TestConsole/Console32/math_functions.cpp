#include "math_functions.h"

//
//bool GetXYandAngle(const double& dL, const double& dOffset, Point2d &pntXY, double &angle, unsigned short &overHgt)
//{
//	//遍历所有元素
//	//if(m_nElementCount>0)
//	//{
//	//	tagElementItem *p = (tagElementItem *)algorithm_bsearch(&dL, m_pElementList+1, m_nElementCount-1, sizeof(tagElementItem), element_item_compare);
//	//	if(p != NULL)
//	//	{
//	//		over_height_to_posa(*p, dL-p->mileage, overHgt);
//	//		return hcurve_moffset_to_posa(x, y, angle, *p, dL-p->mileage, dOffset);
//	//	}
//	//}
//	//return false;
//
//	//遍历所有元素
//	tagElementItem tempElement;
//	for (int nIndex = 1; nIndex < m_nElementCount; nIndex++)
//	{
//		tempElement = m_pElementList[nIndex];
//
//		if (  (tempElement.mileage <= dL && tempElement.mileage+tempElement.length >= dL)
//			||(tempElement.mileage > dL && nIndex == 1)
//			||(tempElement.mileage < dL && nIndex == m_nElementCount-1)
//			)
//		{
//			over_height_to_posa(tempElement, dL-tempElement.mileage, overHgt);
//			return hcurve_moffset_to_posa(pntXY, angle, tempElement, dL-tempElement.mileage, dOffset);
//		}
//	}//for (int nIndex = 1; nIndex < m_nElementItemCount; nIndex++)
//
//	return false;
//}


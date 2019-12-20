// Circle.h: interface for the CCircle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CIRCLE_H__D2ABBED0_0D5D_4100_BAE3_C0716952BBC7__INCLUDED_)
#define AFX_CIRCLE_H__D2ABBED0_0D5D_4100_BAE3_C0716952BBC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include"RGB.h"
#include"P2.h"
class CCircle  
{
public:
	CCircle();
	virtual ~CCircle();
	void Mbellipse(CDC*,CP2,CP2);
	void EllipsePoint(CDC*,double,double,CP2);
};

#endif // !defined(AFX_CIRCLE_H__D2ABBED0_0D5D_4100_BAE3_C0716952BBC7__INCLUDED_)

// P2.h: interface for the CP2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_P2_H__65A91BD3_6D09_49B1_BF61_C66B4CEF660B__INCLUDED_)
#define AFX_P2_H__65A91BD3_6D09_49B1_BF61_C66B4CEF660B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include"RGB.h"
class CP2  
{
public:
	CP2();
	virtual ~CP2();
	CP2(double,double);
	CP2(double,double,CRGB);
public:
	double x;
	double y;
	CRGB c;
};


#endif // !defined(AFX_P2_H__65A91BD3_6D09_49B1_BF61_C66B4CEF660B__INCLUDED_)

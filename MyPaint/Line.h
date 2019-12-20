// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__056C4294_E768_4BB2_A176_5855D3BBB204__INCLUDED_)
#define AFX_LINE_H__056C4294_E768_4BB2_A176_5855D3BBB204__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include"RGB.h"
#include"P2.h"
class CLine  
{
public:
	CLine();
	virtual ~CLine();
	void MoveTo(CDC*,CP2);
	void MoveTo(CDC*,double,double,CRGB);
	void LineTo(CDC*,CP2);
	void LineTo(CDC*,double,double,CRGB);
	CRGB Interpolation(double,double,double,CRGB,CRGB);
public:
	CP2 P0;
	CP2 P1;
};


#endif // !defined(AFX_LINE_H__056C4294_E768_4BB2_A176_5855D3BBB204__INCLUDED_)

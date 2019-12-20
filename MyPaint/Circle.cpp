// Circle.cpp: implementation of the CCircle class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyPaint.h"
#include "Circle.h"
#define ROUND(x) ( (int)(x + 0.5) )
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCircle::CCircle()
{

}

CCircle::~CCircle()
{

}
void CCircle::Mbellipse(CDC*pDC,CP2 p1,CP2 p2)//Õ÷‘≤µƒBresenhamÀ„∑®
{
	double x,y,d1,d2;
	x=0;y=p1.y;
	d1=p1.y*p1.y+p1.x*p1.x*(-p1.y+0.25);
	EllipsePoint(pDC,x,y,p2);
	while(p1.y*p1.y*(x+1)<p1.x*p1.x*(y-0.5))//Õ÷‘≤ACª°∂Œ
	{
		if (d1<0)
		{
			d1+=p1.y*p1.y*(2*x+3);
		}
		else
		{
			d1+=p1.y*p1.y*(2*x+3)+p1.x*p1.x*(-2*y+2);
			y--;
		}
		x++;
		EllipsePoint(pDC,x,y,p2);
	}
	d2=p1.y*p1.y*(x+0.5)*(x+0.5)+p1.x*p1.x*(y-1)*(y-1)-p1.x*p1.x*p1.y*p1.y;//Õ÷‘≤CBª°∂Œ
	while(y>0)
	{
		if (d2<0)
		{
			d2+=p1.y*p1.y*(2*x+2)+p1.x*p1.x*(-2*y+3);
			x++;
		}
		else
		{
			d2+=p1.x*p1.x*(-2*y+3);
			
		}
		y--;
		EllipsePoint(pDC,x,y,p2);
	}
}
void CCircle::EllipsePoint(CDC*pDC,double x,double y,CP2 p2)//Àƒ∑÷∑®ª≠Õ÷‘≤
{
	COLORREF  rgb=RGB(p2.c.red,p2.c.green,p2.c.blue);//∂®“ÂÕ÷‘≤µƒ—’…´
	pDC->SetPixel(ROUND(x+p2.x),ROUND(y+p2.y),rgb);
	pDC->SetPixel(ROUND(-x+p2.x),ROUND(y+p2.y),rgb);
	pDC->SetPixel(ROUND(x+p2.x),ROUND(-y+p2.y),rgb);
	pDC->SetPixel(ROUND(-x+p2.x),ROUND(-y+p2.y),rgb);
}

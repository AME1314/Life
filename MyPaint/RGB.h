// RGB.h: interface for the CRGB class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RGB_H__BB668063_548B_4156_A9BA_0C64E3554CE1__INCLUDED_)
#define AFX_RGB_H__BB668063_548B_4156_A9BA_0C64E3554CE1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRGB  
{
public:
	CRGB();
	CRGB(double,double,double);
	friend CRGB operator +(CRGB&,CRGB &);
	friend CRGB operator *(double,CRGB &);
	virtual ~CRGB();
public:
	double red;
	double green;
	double blue;
};


#endif // !defined(AFX_RGB_H__BB668063_548B_4156_A9BA_0C64E3554CE1__INCLUDED_)

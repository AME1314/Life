// FillColor.h: interface for the CFillColor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILLCOLOR_H__FF1A07FD_D834_48CE_A9BA_D6B7BC2AF3BE__INCLUDED_)
#define AFX_FILLCOLOR_H__FF1A07FD_D834_48CE_A9BA_D6B7BC2AF3BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "P2.h"
class CFillColor  
{
public:
	typedef struct LNode{
		struct LNode *front;
		CPoint FillPoint;
		struct LNode *next;
	}LNode;
public:
	CFillColor();
	virtual ~CFillColor();
	LNode*p;
	CPoint OriginalP;
	void InitList_L(LNode*);
	void DestoryList_L(LNode*);
	void ListInsert_L(LNode*,CPoint,LNode*);
	void ListDelete_L(LNode*,LNode*);
	void ListFillStart(CDC*,CPoint,CRGB);
	void ListFillColor(CDC*,LNode*,CPoint,CRGB,LNode*);
};


#endif // !defined(AFX_FILLCOLOR_H__FF1A07FD_D834_48CE_A9BA_D6B7BC2AF3BE__INCLUDED_)

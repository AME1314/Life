// FillColor.cpp: implementation of the CFillColor class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyPaint.h"
#include "FillColor.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFillColor::CFillColor()
{

}

CFillColor::~CFillColor()
{

}
void CFillColor::InitList_L(LNode *L){
	L=new LNode;
	L->front=NULL;
	L->next=NULL;
}
void CFillColor::DestoryList_L(LNode *L){
	while (L)
	{
		LNode*q=L;
		L=L->next;
		delete q;
	}
}
void CFillColor::ListInsert_L(LNode*L,CPoint P0,LNode*p){
	LNode* s;
	s=new LNode;
	s->FillPoint=P0;
	s->next=NULL;
	s->front=p;
	p->next=s;
	p=p->next;
}
void CFillColor::ListDelete_L(LNode*L,LNode*p){
	p=p->front;
	delete p->next;
	p->next=NULL;
}
void CFillColor::ListFillStart(CDC*pDC,CPoint P0,CRGB c){
	LNode*L=new LNode;
	InitList_L(L);
	p=L;
	OriginalP=P0;
	ListInsert_L(L,P0,p);
	ListFillColor(pDC,L,P0,c,p);
	pDC->SetPixel(P0.x,P0.y,(c.red,c.green,c.blue));
	DestoryList_L(L);
}
void CFillColor::ListFillColor(CDC*pDC,LNode*L,CPoint p1,CRGB c,LNode*p){
	if(pDC->GetPixel(OriginalP.x,OriginalP.y)==pDC->GetPixel(p1.x,p1.y+1)){
		p1.y++;if(p1!=OriginalP){
			pDC->SetPixel(p1.x,p1.y,(c.red,c.green,c.blue));
			ListInsert_L(L,p1,p);
			ListFillColor(pDC,L,p1,c,p);
		}
	}
	if(pDC->GetPixel(OriginalP.x,OriginalP.y)==pDC->GetPixel(p1.x-1,p1.y)){
		p1.x--;if(p1!=OriginalP){
			pDC->SetPixel(p1.x,p1.y,(c.red,c.green,c.blue));
			ListInsert_L(L,p1,p);
			ListFillColor(pDC,L,p1,c,p);
		}
	}
	if(pDC->GetPixel(OriginalP.x,OriginalP.y)==pDC->GetPixel(p1.x,p1.y-1)){
		p1.y--;if(p1!=OriginalP){
			pDC->SetPixel(p1.x,p1.y,(c.red,c.green,c.blue));
			ListInsert_L(L,p1,p);
			ListFillColor(pDC,L,p1,c,p);
		}
	}
	if(pDC->GetPixel(OriginalP.x,OriginalP.y)==pDC->GetPixel(p1.x+1,p1.y)){
		p1.x++;if(p1!=OriginalP){
			pDC->SetPixel(p1.x,p1.y,(c.red,c.green,c.blue));
			ListInsert_L(L,p1,p);
			ListFillColor(pDC,L,p1,c,p);
		}
	}
}

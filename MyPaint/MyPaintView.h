// MyPaintView.h : interface of the CMyPaintView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYPAINTVIEW_H__C1CF4C07_BF88_4697_8FEE_5C962C3B43A4__INCLUDED_)
#define AFX_MYPAINTVIEW_H__C1CF4C07_BF88_4697_8FEE_5C962C3B43A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "P2.h"
#include "Line.h"
#include "Circle.h"
#include "RGB.h"
#include "FillColor.h"
#include "WINDOWSX.H"
class CMyPaintView : public CView
{
protected: // create from serialization only
	CMyPaintView();
	DECLARE_DYNCREATE(CMyPaintView)

// Attributes
public:
	CMyPaintDoc* GetDocument();
	void DrawMouseMove(UINT,CPoint);
	void DrawLButtonUp(UINT,CPoint);
// Operations
public:
	int m_DrawType;
	bool m_isDraw;
	bool m_IsDrawIng;
	CP2 m_OriginPoint;
	CP2 m_endpoint;
	CPoint m_StartPoint;
	CPoint m_EndPoint;
	int rgbr;
	int rgbg;
	int rgbb;
	COLORREF m_clr;
	HCURSOR m_hCross;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyPaintView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyPaintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyPaintView)
	afx_msg void OnPaintline();
	afx_msg void OnPaintgreen();
	afx_msg void OnPaintblue();
	afx_msg void OnPaintcolor();
	afx_msg void OnPaintcurve();
	afx_msg void OnPaintfill();
	afx_msg void OnPaintoval();
	afx_msg void OnPaintovalSolid();
	afx_msg void OnPaintreaser();
	afx_msg void OnPaintrectangle();
	afx_msg void OnPaintrectangleSolid();
	afx_msg void OnPaintred();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnFileSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MyPaintView.cpp
inline CMyPaintDoc* CMyPaintView::GetDocument()
   { return (CMyPaintDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYPAINTVIEW_H__C1CF4C07_BF88_4697_8FEE_5C962C3B43A4__INCLUDED_)

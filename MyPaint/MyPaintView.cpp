// MyPaintView.cpp : implementation of the CMyPaintView class
//

#include "stdafx.h"
#include "MyPaint.h"
#include "math.h"
#include "MyPaintDoc.h"
#include "MyPaintView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyPaintView

IMPLEMENT_DYNCREATE(CMyPaintView, CView)

BEGIN_MESSAGE_MAP(CMyPaintView, CView)
	//{{AFX_MSG_MAP(CMyPaintView)
	ON_COMMAND(ID_PAINTLINE, OnPaintline)
	ON_COMMAND(ID_PAINTGREEN, OnPaintgreen)
	ON_COMMAND(ID_PAINTBLUE, OnPaintblue)
	ON_COMMAND(ID_PAINTCOLOR, OnPaintcolor)
	ON_COMMAND(ID_PAINTCURVE, OnPaintcurve)
	ON_COMMAND(ID_PAINTFILL, OnPaintfill)
	ON_COMMAND(ID_PAINTOVAL, OnPaintoval)
	ON_COMMAND(ID_PAINTOVAL_SOLID, OnPaintovalSolid)
	ON_COMMAND(ID_PAINTREASER, OnPaintreaser)
	ON_COMMAND(ID_PAINTRECTANGLE, OnPaintrectangle)
	ON_COMMAND(ID_PAINTRECTANGLE_SOLID, OnPaintrectangleSolid)
	ON_COMMAND(ID_PAINTRED, OnPaintred)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyPaintView construction/destruction

CMyPaintView::CMyPaintView()
{
	// TODO: add construction code here
	m_DrawType = 1;//Ĭ�ϳ�ʼ��ͼ״̬Ϊ����ֱ�߶�
	m_isDraw = true;//��ǰ���ڻ�ͼ״̬
	m_IsDrawIng=false;
	m_hCross=AfxGetApp()->LoadStandardCursor(IDC_CROSS);//����m_hCross�����״��Ϊʮ����
}

CMyPaintView::~CMyPaintView()
{
}

BOOL CMyPaintView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyPaintView drawing

void CMyPaintView::OnDraw(CDC* pDC)
{
	CMyPaintDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMyPaintView printing

BOOL CMyPaintView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyPaintView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyPaintView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyPaintView diagnostics

#ifdef _DEBUG
void CMyPaintView::AssertValid() const
{
	CView::AssertValid();
}

void CMyPaintView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyPaintDoc* CMyPaintView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyPaintDoc)));
	return (CMyPaintDoc*)m_pDocument;
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyPaintView message handlers

void CMyPaintView::OnPaintline() 
{
	// TODO: Add your command handler code here
	m_DrawType = 2;//2��ʾ����ֱ�߶�
	m_isDraw = true;//��ʼ״̬Ϊ�����������
	m_IsDrawIng=false;//��ʼ״̬Ϊ��ͼ״̬
	m_endpoint=m_OriginPoint;//��ʼ����ʼ���������

}

void CMyPaintView::OnPaintred() 
{
	// TODO: Add your command handler code here
	rgbr=255;
	rgbg=0;
	rgbb=0; //��ɫ����
}

void CMyPaintView::OnPaintgreen() 
{
	// TODO: Add your command handler code here
	rgbr=0;
	rgbg=255;
	rgbb=0; //��ɫ����
}

void CMyPaintView::OnPaintblue() 
{
	// TODO: Add your command handler code here
	rgbr=0;
	rgbg=0;
	rgbb=255; //��ɫ����
}

void CMyPaintView::OnPaintcolor() 
{
	// TODO: Add your command handler code here
	CColorDialog dlg;
	dlg.m_cc.Flags|=CC_RGBINIT|CC_FULLOPEN;
	dlg.m_cc.rgbResult=m_clr;
	if (IDOK==dlg.DoModal())
	{
		m_clr=dlg.m_cc.rgbResult;
	}
	rgbr=GetRValue(m_clr);//����ѡ��ɫ���벢������Ӧ������
	rgbb=GetBValue(m_clr);
	rgbg=GetGValue(m_clr);
}

void CMyPaintView::OnPaintcurve() 
{
	// TODO: Add your command handler code here
	m_DrawType = 1;//1��ʾ����
	m_isDraw = true;//��ʼ״̬Ϊ�����������
	m_IsDrawIng=false;//��ʼ״̬Ϊ��ͼ״̬

}

void CMyPaintView::OnPaintfill() 
{
	// TODO: Add your command handler code here
	m_DrawType=6;//6��ʾ�������  
	m_isDraw=true;//��ǰ���ڻ�ͼ״̬  
	m_IsDrawIng=false;  
}

void CMyPaintView::OnPaintoval() 
{
	// TODO: Add your command handler code here
	m_DrawType = 3;//3��ʾ��Բ
	m_isDraw=true;//��ʼ״̬Ϊ�����������
	m_IsDrawIng=false;//��ʼ״̬Ϊ��ͼ״̬
}

void CMyPaintView::OnPaintovalSolid() 
{
	// TODO: Add your command handler code here
	m_DrawType=7;//7��ʾ��Բ����
	m_isDraw=true;//��ǰ���ڻ�ͼ״̬
	m_IsDrawIng=false;
}

void CMyPaintView::OnPaintreaser() 
{
	// TODO: Add your command handler code here
	m_DrawType=5;//5��ʾ��Ƥ��
	m_isDraw=true;//��ʼ״̬Ϊ�����������
	m_IsDrawIng=false;//��ʼ״̬Ϊ��ͼ״̬
}

void CMyPaintView::OnPaintrectangle() 
{
	// TODO: Add your command handler code here
	m_DrawType=4;//4��ʾ����
	m_isDraw=true;//��ʼ״̬Ϊ�����������
	m_IsDrawIng=false;//��ʼ״̬Ϊ��ͼ״̬

}

void CMyPaintView::OnPaintrectangleSolid() 
{
	// TODO: Add your command handler code here
	m_DrawType=8;//8��ʾ��������
	m_isDraw=true;//��ǰ���ڻ�ͼ״̬
	m_IsDrawIng=false;
}

void CMyPaintView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	SetCapture();		//�������Ϣ���͵��Ӵ���
	CRect rect;
	GetClientRect(&rect);	//�õ��ͻ����ڵĴ�С
	ClientToScreen(&rect);	//����ǰ��������ת������Ļ����
	ClipCursor(&rect);		//������޶���ָ���ľ���������(�����ڣ�Ҳ���ǵ�ǰ������)
	SetCursor(m_hCross);	//�����ָ����״��Ϊʮ����

	if (m_isDraw)
	{	
		m_IsDrawIng=true;//����������״̬��ΪTURE
		m_OriginPoint.x=point.x;//��ʼ��m_OriginPoint
		m_OriginPoint.y=point.y;	
		m_OriginPoint.c.red=rgbr;
		m_OriginPoint.c.blue=rgbb;
		m_OriginPoint.c.green=rgbg;	
		m_StartPoint=point;//��ʼ��m_StartPoint
		m_EndPoint=point;//��ʼ��m_EndPoint
	}
	if (m_DrawType==5)
	{
		CClientDC dc(this);	
		CPen * pOldPen;  //���滭��
		CPen SolidPen(PS_SOLID,20,RGB(255,255,255));  //���廭��
		pOldPen=dc.SelectObject(&SolidPen);  //
		dc.SetROP2(R2_COPYPEN);		//���û滭ģʽ 
		dc.MoveTo(m_StartPoint);	//�����д������㵽��굱ǰλ�û���
		dc.LineTo(point);
		m_StartPoint=point;
	}

	CView::OnLButtonDown(nFlags, point);
}

void CMyPaintView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (m_IsDrawIng&&m_DrawType==1)//����
	{
		DrawMouseMove(nFlags,point);
	}
	if (m_IsDrawIng&&m_DrawType==2)//ֱ�߶�
	{
		DrawMouseMove(nFlags,point);
	}
	if (m_IsDrawIng&&m_DrawType==5)//��Ƥ  
	{  
        DrawMouseMove(nFlags,point);  
	}  
	if (m_IsDrawIng&&m_DrawType==7)//��Բ����
	{
		DrawMouseMove(nFlags,point);
	}
	if (m_IsDrawIng&&m_DrawType==8)//��������
	{
		DrawMouseMove(nFlags,point);
	}
	CView::OnMouseMove(nFlags, point);
}

void CMyPaintView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	ReleaseCapture();  
	ClipCursor(NULL);  
	if (m_IsDrawIng)
	{
		CClientDC dc(this);//�����豸��������
		m_IsDrawIng=false;//������״̬��ΪFALSE
		m_endpoint.c.red=rgbr;
		m_endpoint.c.blue=rgbb;
		m_endpoint.c.green=rgbg;
		if (m_DrawType==2)
		{
			DrawLButtonUp(nFlags,point);
		}
		if (m_DrawType==3)
		{	
			DrawLButtonUp(nFlags,point);
		}
		if (m_DrawType==4)
		{
			DrawLButtonUp(nFlags,point);
		}
		if (m_DrawType==6)
		{
			DrawLButtonUp(nFlags,point);
		}

	}
	CView::OnLButtonUp(nFlags, point);
}
void CMyPaintView::DrawLButtonUp(UINT nFlags,CPoint point)
{
	if (m_DrawType==2)//ֱ�߶�
	{	
		m_endpoint.x=point.x;
		m_endpoint.y=point.y;
		CLine dc;
		CDC*pDC=GetDC();
		dc.MoveTo(pDC,m_OriginPoint);//�ӵ�m_OriginPoint������m_endpoint
		dc.LineTo(pDC,m_endpoint);
	}
	if (m_DrawType==3)//��Բ
	{	
		CDC*pDC=GetDC();
		CCircle dc;
		m_endpoint.x=fabs(point.x-m_OriginPoint.x)/2;//����m_endpoint��Ϊ��Բ�����ĵ�
		m_endpoint.y=fabs(point.y-m_OriginPoint.y)/2;
		if (m_OriginPoint.x>point.x) //�жϵ�ǰ�����ʼ���λ�ù�ϵ������m_OriginPoint��Ϊ��Բ��A��B��
		{		
			m_OriginPoint.x=m_OriginPoint.x-m_endpoint.x;
		}
		if (m_OriginPoint.y>point.y)
		{	
			m_OriginPoint.y=m_OriginPoint.y-m_endpoint.y;
		}
		if (m_OriginPoint.x<point.x)
		{	
			m_OriginPoint.x=m_OriginPoint.x+m_endpoint.x;
		}
		if (m_OriginPoint.y<point.y)
		{	
			m_OriginPoint.y=m_OriginPoint.y+m_endpoint.y;
		}
		if (nFlags==MK_SHIFT)//������SHIFT�󻭳���ͼ��ΪԲ��
	{
			m_endpoint.y=m_endpoint.x;
		}
		
		dc.Mbellipse(pDC,m_endpoint,m_OriginPoint);
	}
	if (m_DrawType==4)//����
	{	if (m_OriginPoint.x!=point.x&&m_OriginPoint.y!=point.y)//�����ʼ����ڵ�ǰ����ִ�иó���
		{		
			CDC *pDC=GetDC();
			CLine dc;
			CP2 a,b,c,d;//�������ĸ�����ֱ�Ϊa��b��c��d
			a.c=m_OriginPoint.c;//��ʼ��abcd
			b.c=m_OriginPoint.c;
			c.c=m_OriginPoint.c;
			d.c=m_OriginPoint.c;
			a=m_OriginPoint;//��ʼ��aΪ��ʼ��
			b.x=m_OriginPoint.x;
			c.y=m_OriginPoint.y;
			CP2 dt;
			dt.x=fabs(m_OriginPoint.x-point.x);//�������ĳ��ڿ�
			dt.y=fabs(m_OriginPoint.y-point.y);	
			if (nFlags==MK_SHIFT)//������SHIFT��ͼ��Ϊ������
			{
			dt.x=dt.y;
			}
			if (m_OriginPoint.x>point.x)//�жϳ�ʼ���뵱ǰ���λ�ù�ϵ
			{		
				c.x=m_OriginPoint.x-dt.x;
				d.x=a.x-dt.x;
			}
			if (m_OriginPoint.y>point.y)
			{	
				b.y=m_OriginPoint.y-dt.y;
				d.y=a.y-dt.y;
			}
			if (m_OriginPoint.x<point.x)
			{	
				c.x=m_OriginPoint.x+dt.x;
				d.x=a.x+dt.x;
			}
			if (m_OriginPoint.y<point.y)
			{	
				b.y=m_OriginPoint.y+dt.y;
				d.y=a.y+dt.y;
			}
			dc.MoveTo(pDC,a);//������ʵ��
			dc.LineTo(pDC,b);
			dc.MoveTo(pDC,a);
			dc.LineTo(pDC,c);
			dc.MoveTo(pDC,b);
			dc.LineTo(pDC,d);
			dc.MoveTo(pDC,c);
			dc.LineTo(pDC,d);
		}
	}
	if (m_DrawType==6)//���
	{
		CRect Rect;
		GetClientRect(&Rect);
		CDC *pDC=GetDC();
		CFillColor color;
		CRGB c;
		c.red=rgbr;
		c.green=rgbg;
		c.blue=rgbb;								  				
		color.ListFillStart(pDC,point,c);
		m_IsDrawIng=false;
	}
}
void CMyPaintView::DrawMouseMove(UINT nFlags,CPoint point)
{

CClientDC dc(this);//�����豸��������
	if (m_IsDrawIng&&m_DrawType==1)//�ж�����ƶ���ͬʱ���������£�����Ҫ���Ƶ��ǻ���
	{
		CP2 p;					
		p.x=point.x;		//��ʼ��������Ϣ
		p.y=point.y;
		p.c.red=rgbr;
		p.c.blue=rgbb;
		p.c.green=rgbg;
		if (m_IsDrawIng)
		{	
			CLine dc;	//���ƻ���
			CDC*pDC=GetDC();
			dc.MoveTo(pDC,m_OriginPoint);
			dc.LineTo(pDC,p);
		}
		m_OriginPoint.x=point.x;
		m_OriginPoint.y=point.y;
	}
	if ( m_IsDrawIng&& m_DrawType == 2)	//�ж�����ƶ���ͬʱ���������£�����Ҫ���Ƶ���ֱ�߶�
	{
		CPen * pOldPen;  //���滭��
		CPen SolidPen(PS_SOLID,1,RGB(rgbr,rgbg,rgbb));  //���廭��
		pOldPen=dc.SelectObject(&SolidPen);  //
		dc.SetROP2(R2_MERGEPENNOT);//���û�ͼģʽΪR2_MERGEPENNOT�����»���ǰһ������ƶ���Ϣ���������Ƶ�ֱ�߶Σ���Ϊ��ͼģʽ��ԭ�򣬽���ǲ����˸��߶�
		dc.MoveTo(m_StartPoint);
		dc.LineTo(m_EndPoint);
		dc.MoveTo(m_StartPoint);//�����µ�ֱ�߶�
		dc.LineTo(point);
		m_EndPoint = point;	//�����µ�ֱ�߶��յ�
	}
	if (m_IsDrawIng&&m_DrawType==5)  
    {  
        CClientDC dc(this);   
        CPen * pOldPen;  //���滭��  
        CPen SolidPen(PS_SOLID,20,RGB(255,255,255));  //���廭��  
        pOldPen=dc.SelectObject(&SolidPen);  //  
        dc.SetROP2(R2_COPYPEN);     //���û滭ģʽ   
        dc.MoveTo(m_StartPoint);    //�����д������㵽��굱ǰλ�û���  
        dc.LineTo(point);  
        m_StartPoint=point;       
    }  
	if (m_IsDrawIng&&m_DrawType==7)//��Բ����
	{
		CClientDC dc(this);	//�豸����
		CPen * pOldPen;//���滭��
		CPen SolidPen(PS_SOLID,1,RGB(rgbr,rgbg,rgbb));//���廭��
		pOldPen=dc.SelectObject(&SolidPen);
		dc.SetROP2(R2_NOT);//���û滭ģʽR2_NOT���뱳��ɫ�෴����ɫ��ͼ 
		dc.SetROP2(R2_WHITE);		
		dc.MoveTo(m_StartPoint);//�����д����ǲ�������㣨��갴�µ㣩��
		dc.Ellipse(m_StartPoint.x,m_StartPoint.y,m_EndPoint.x,m_EndPoint.y);		//�ϴ�����ƶ�����λ��֮�����ʱ��
		dc.SetROP2(R2_COPYPEN);	
		dc.MoveTo(m_StartPoint);//�����д������㵽��굱ǰλ�û���
		dc.Ellipse(m_StartPoint.x,m_StartPoint.y,point.x,point.y);
		  m_EndPoint=point;//��굱ǰλ������һ������ƶ��¼���������"��λ��"
	}
	if (m_IsDrawIng&&m_DrawType==8)//��������
	{
		CClientDC dc(this);	//�豸����
		CPen * pOldPen;  //���滭��
		CPen SolidPen(PS_SOLID,1,RGB(rgbr,rgbg,rgbb));  //���廭��
		pOldPen=dc.SelectObject(&SolidPen);  
		dc.SetROP2(R2_NOT);//���û滭ģʽ   R2_NOT���뱳��ɫ�෴����ɫ��ͼ 
		dc.SetROP2(R2_WHITE); 		
		dc.MoveTo(m_StartPoint);
		dc.Rectangle(m_StartPoint.x,m_StartPoint.y,m_EndPoint.x,m_EndPoint.y);	//�ϴ�����ƶ�����λ��֮�����ʱ��
		dc.SetROP2(R2_COPYPEN);	
		dc.MoveTo(m_StartPoint);	//�����д������㵽��굱ǰλ�û���
		dc.Rectangle(m_StartPoint.x,m_StartPoint.y,point.x,point.y);
		m_EndPoint=point;	//��굱ǰλ������һ������ƶ��¼���������"��λ��"
	}
}

void CMyPaintView::OnFileSave() 
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
	CDC memDC;
	CRect rect;
	GetClientRect(rect);
	memDC.CreateCompatibleDC(&dc);
	CBitmap bm;
	int Width=rect.Width();
	int Height=rect.Height();
	bm.CreateCompatibleBitmap(&dc,Width,Height);
	CBitmap* pOld=memDC.SelectObject(&bm);
	memDC.BitBlt(0,0,Width,Height,&dc,0,0,SRCCOPY);
	memDC.SelectObject(pOld);
	BITMAP btm;
	bm.GetBitmap(&btm);
	DWORD size=btm.bmWidthBytes* btm.bmHeight;
	LPSTR lpData=(LPSTR)GlobalAllocPtr(GPTR,size);//�����ڴ�ռ�
	BITMAPFILEHEADER bfh;
	////////////////////////////////////
	BITMAPINFOHEADER bih;
	bih.biBitCount=btm.bmBitsPixel;
	bih.biClrImportant=0;
	bih.biClrUsed=0;
	bih.biCompression=0;
	bih.biHeight=btm.bmHeight;
	bih.biPlanes=1;
	bih.biSize=sizeof(BITMAPINFOHEADER);
	bih.biSizeImage=size;
	bih.biWidth=btm.bmWidth;
	bih.biXPelsPerMeter=0;
	bih.biYPelsPerMeter=0;
	GetDIBits(dc,bm,0,bih.biHeight,lpData,(BITMAPINFO*)&bih,DIB_RGB_COLORS);
	bfh.bfReserved1=bfh.bfReserved2=0;
	bfh.bfType=((WORD)('M'<<8)|'B');
	bfh.bfSize=54+size;
	bfh.bfOffBits=54;
	CFileDialog dlg(false,_T("BMP"),_T("*.bmp"),OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,"λͼ�ļ�(*.bmp|*.bmp|",NULL);
	if (dlg.DoModal()!=IDOK)
	{
		return;
	}
	CString filename=dlg.GetFileName()+".bmp";
	CFile bf;
	CString ss=dlg.GetPathName();
	if (bf.Open(ss,CFile::modeCreate|CFile::modeWrite))
	{
		bf.WriteHuge(&bfh,sizeof(BITMAPFILEHEADER));
		bf.WriteHuge(&bih,sizeof(BITMAPINFOHEADER));
		bf.WriteHuge(lpData,size);
		bf.Close();
		AfxMessageBox("����ɹ�");
	}
	GlobalFreePtr(lpData);
}

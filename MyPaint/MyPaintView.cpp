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
	m_DrawType = 1;//默认初始绘图状态为绘制直线段
	m_isDraw = true;//当前处于绘图状态
	m_IsDrawIng=false;
	m_hCross=AfxGetApp()->LoadStandardCursor(IDC_CROSS);//定义m_hCross鼠标形状设为十字形
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
	m_DrawType = 2;//2表示绘制直线段
	m_isDraw = true;//初始状态为允许左键点下
	m_IsDrawIng=false;//初始状态为绘图状态
	m_endpoint=m_OriginPoint;//初始化起始点与结束点

}

void CMyPaintView::OnPaintred() 
{
	// TODO: Add your command handler code here
	rgbr=255;
	rgbg=0;
	rgbb=0; //颜色变量
}

void CMyPaintView::OnPaintgreen() 
{
	// TODO: Add your command handler code here
	rgbr=0;
	rgbg=255;
	rgbb=0; //颜色变量
}

void CMyPaintView::OnPaintblue() 
{
	// TODO: Add your command handler code here
	rgbr=0;
	rgbg=0;
	rgbb=255; //颜色变量
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
	rgbr=GetRValue(m_clr);//将所选颜色分离并放入相应变量中
	rgbb=GetBValue(m_clr);
	rgbg=GetGValue(m_clr);
}

void CMyPaintView::OnPaintcurve() 
{
	// TODO: Add your command handler code here
	m_DrawType = 1;//1表示画笔
	m_isDraw = true;//初始状态为允许左键点下
	m_IsDrawIng=false;//初始状态为绘图状态

}

void CMyPaintView::OnPaintfill() 
{
	// TODO: Add your command handler code here
	m_DrawType=6;//6表示种子填充  
	m_isDraw=true;//当前处于绘图状态  
	m_IsDrawIng=false;  
}

void CMyPaintView::OnPaintoval() 
{
	// TODO: Add your command handler code here
	m_DrawType = 3;//3表示椭圆
	m_isDraw=true;//初始状态为允许左键点下
	m_IsDrawIng=false;//初始状态为绘图状态
}

void CMyPaintView::OnPaintovalSolid() 
{
	// TODO: Add your command handler code here
	m_DrawType=7;//7表示椭圆区域
	m_isDraw=true;//当前处于绘图状态
	m_IsDrawIng=false;
}

void CMyPaintView::OnPaintreaser() 
{
	// TODO: Add your command handler code here
	m_DrawType=5;//5表示橡皮擦
	m_isDraw=true;//初始状态为允许左键点下
	m_IsDrawIng=false;//初始状态为绘图状态
}

void CMyPaintView::OnPaintrectangle() 
{
	// TODO: Add your command handler code here
	m_DrawType=4;//4表示矩形
	m_isDraw=true;//初始状态为允许左键点下
	m_IsDrawIng=false;//初始状态为绘图状态

}

void CMyPaintView::OnPaintrectangleSolid() 
{
	// TODO: Add your command handler code here
	m_DrawType=8;//8表示矩形区域
	m_isDraw=true;//当前处于绘图状态
	m_IsDrawIng=false;
}

void CMyPaintView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	SetCapture();		//将鼠标消息发送到视窗口
	CRect rect;
	GetClientRect(&rect);	//得到客户窗口的大小
	ClientToScreen(&rect);	//将当前窗口坐标转换成屏幕坐标
	ClipCursor(&rect);		//把鼠标限定在指定的矩形区域内(矩形内，也就是当前窗口内)
	SetCursor(m_hCross);	//把鼠标指针形状设为十字形

	if (m_isDraw)
	{	
		m_IsDrawIng=true;//将程序运行状态变为TURE
		m_OriginPoint.x=point.x;//初始化m_OriginPoint
		m_OriginPoint.y=point.y;	
		m_OriginPoint.c.red=rgbr;
		m_OriginPoint.c.blue=rgbb;
		m_OriginPoint.c.green=rgbg;	
		m_StartPoint=point;//初始化m_StartPoint
		m_EndPoint=point;//初始化m_EndPoint
	}
	if (m_DrawType==5)
	{
		CClientDC dc(this);	
		CPen * pOldPen;  //保存画笔
		CPen SolidPen(PS_SOLID,20,RGB(255,255,255));  //定义画笔
		pOldPen=dc.SelectObject(&SolidPen);  //
		dc.SetROP2(R2_COPYPEN);		//设置绘画模式 
		dc.MoveTo(m_StartPoint);	//这两行代码从起点到鼠标当前位置画线
		dc.LineTo(point);
		m_StartPoint=point;
	}

	CView::OnLButtonDown(nFlags, point);
}

void CMyPaintView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (m_IsDrawIng&&m_DrawType==1)//画笔
	{
		DrawMouseMove(nFlags,point);
	}
	if (m_IsDrawIng&&m_DrawType==2)//直线段
	{
		DrawMouseMove(nFlags,point);
	}
	if (m_IsDrawIng&&m_DrawType==5)//橡皮  
	{  
        DrawMouseMove(nFlags,point);  
	}  
	if (m_IsDrawIng&&m_DrawType==7)//椭圆区域
	{
		DrawMouseMove(nFlags,point);
	}
	if (m_IsDrawIng&&m_DrawType==8)//矩形区域
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
		CClientDC dc(this);//构造设备环境对象
		m_IsDrawIng=false;//将程序状态变为FALSE
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
	if (m_DrawType==2)//直线段
	{	
		m_endpoint.x=point.x;
		m_endpoint.y=point.y;
		CLine dc;
		CDC*pDC=GetDC();
		dc.MoveTo(pDC,m_OriginPoint);//从点m_OriginPoint画到点m_endpoint
		dc.LineTo(pDC,m_endpoint);
	}
	if (m_DrawType==3)//椭圆
	{	
		CDC*pDC=GetDC();
		CCircle dc;
		m_endpoint.x=fabs(point.x-m_OriginPoint.x)/2;//将点m_endpoint设为椭圆的中心点
		m_endpoint.y=fabs(point.y-m_OriginPoint.y)/2;
		if (m_OriginPoint.x>point.x) //判断当前点与初始点的位置关系，并将m_OriginPoint设为椭圆的A与B。
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
		if (nFlags==MK_SHIFT)//在摁下SHIFT后画出的图像为圆形
	{
			m_endpoint.y=m_endpoint.x;
		}
		
		dc.Mbellipse(pDC,m_endpoint,m_OriginPoint);
	}
	if (m_DrawType==4)//矩形
	{	if (m_OriginPoint.x!=point.x&&m_OriginPoint.y!=point.y)//如果初始点等于当前点则不执行该程序
		{		
			CDC *pDC=GetDC();
			CLine dc;
			CP2 a,b,c,d;//设矩阵的四个顶点分别为a、b、c、d
			a.c=m_OriginPoint.c;//初始化abcd
			b.c=m_OriginPoint.c;
			c.c=m_OriginPoint.c;
			d.c=m_OriginPoint.c;
			a=m_OriginPoint;//初始化a为初始点
			b.x=m_OriginPoint.x;
			c.y=m_OriginPoint.y;
			CP2 dt;
			dt.x=fabs(m_OriginPoint.x-point.x);//计算矩阵的长于宽
			dt.y=fabs(m_OriginPoint.y-point.y);	
			if (nFlags==MK_SHIFT)//在摁下SHIFT后图形为正方形
			{
			dt.x=dt.y;
			}
			if (m_OriginPoint.x>point.x)//判断初始点与当前点的位置关系
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
			dc.MoveTo(pDC,a);//将矩阵实现
			dc.LineTo(pDC,b);
			dc.MoveTo(pDC,a);
			dc.LineTo(pDC,c);
			dc.MoveTo(pDC,b);
			dc.LineTo(pDC,d);
			dc.MoveTo(pDC,c);
			dc.LineTo(pDC,d);
		}
	}
	if (m_DrawType==6)//填充
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

CClientDC dc(this);//构造设备环境对象
	if (m_IsDrawIng&&m_DrawType==1)//判断鼠标移动的同时鼠标左键按下，并且要绘制的是画笔
	{
		CP2 p;					
		p.x=point.x;		//初始化画笔信息
		p.y=point.y;
		p.c.red=rgbr;
		p.c.blue=rgbb;
		p.c.green=rgbg;
		if (m_IsDrawIng)
		{	
			CLine dc;	//绘制画笔
			CDC*pDC=GetDC();
			dc.MoveTo(pDC,m_OriginPoint);
			dc.LineTo(pDC,p);
		}
		m_OriginPoint.x=point.x;
		m_OriginPoint.y=point.y;
	}
	if ( m_IsDrawIng&& m_DrawType == 2)	//判断鼠标移动的同时鼠标左键按下，并且要绘制的是直线段
	{
		CPen * pOldPen;  //保存画笔
		CPen SolidPen(PS_SOLID,1,RGB(rgbr,rgbg,rgbb));  //定义画笔
		pOldPen=dc.SelectObject(&SolidPen);  //
		dc.SetROP2(R2_MERGEPENNOT);//设置绘图模式为R2_MERGEPENNOT，重新绘制前一个鼠标移动消息处理函数绘制的直线段，因为绘图模式的原因，结果是擦除了该线段
		dc.MoveTo(m_StartPoint);
		dc.LineTo(m_EndPoint);
		dc.MoveTo(m_StartPoint);//绘制新的直线段
		dc.LineTo(point);
		m_EndPoint = point;	//保存新的直线段终点
	}
	if (m_IsDrawIng&&m_DrawType==5)  
    {  
        CClientDC dc(this);   
        CPen * pOldPen;  //保存画笔  
        CPen SolidPen(PS_SOLID,20,RGB(255,255,255));  //定义画笔  
        pOldPen=dc.SelectObject(&SolidPen);  //  
        dc.SetROP2(R2_COPYPEN);     //设置绘画模式   
        dc.MoveTo(m_StartPoint);    //这两行代码从起点到鼠标当前位置画线  
        dc.LineTo(point);  
        m_StartPoint=point;       
    }  
	if (m_IsDrawIng&&m_DrawType==7)//椭圆区域
	{
		CClientDC dc(this);	//设备上下
		CPen * pOldPen;//保存画笔
		CPen SolidPen(PS_SOLID,1,RGB(rgbr,rgbg,rgbb));//定义画笔
		pOldPen=dc.SelectObject(&SolidPen);
		dc.SetROP2(R2_NOT);//设置绘画模式R2_NOT用与背景色相反的颜色绘图 
		dc.SetROP2(R2_WHITE);		
		dc.MoveTo(m_StartPoint);//这两行代码是擦除从起点（鼠标按下点）到
		dc.Ellipse(m_StartPoint.x,m_StartPoint.y,m_EndPoint.x,m_EndPoint.y);		//上次鼠标移动到的位置之间的临时线
		dc.SetROP2(R2_COPYPEN);	
		dc.MoveTo(m_StartPoint);//这两行代码从起点到鼠标当前位置画线
		dc.Ellipse(m_StartPoint.x,m_StartPoint.y,point.x,point.y);
		  m_EndPoint=point;//鼠标当前位置在下一次鼠标移动事件看来就是"旧位置"
	}
	if (m_IsDrawIng&&m_DrawType==8)//矩形区域
	{
		CClientDC dc(this);	//设备上下
		CPen * pOldPen;  //保存画笔
		CPen SolidPen(PS_SOLID,1,RGB(rgbr,rgbg,rgbb));  //定义画笔
		pOldPen=dc.SelectObject(&SolidPen);  
		dc.SetROP2(R2_NOT);//设置绘画模式   R2_NOT用与背景色相反的颜色绘图 
		dc.SetROP2(R2_WHITE); 		
		dc.MoveTo(m_StartPoint);
		dc.Rectangle(m_StartPoint.x,m_StartPoint.y,m_EndPoint.x,m_EndPoint.y);	//上次鼠标移动到的位置之间的临时线
		dc.SetROP2(R2_COPYPEN);	
		dc.MoveTo(m_StartPoint);	//这两行代码从起点到鼠标当前位置画线
		dc.Rectangle(m_StartPoint.x,m_StartPoint.y,point.x,point.y);
		m_EndPoint=point;	//鼠标当前位置在下一次鼠标移动事件看来就是"旧位置"
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
	LPSTR lpData=(LPSTR)GlobalAllocPtr(GPTR,size);//分配内存空间
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
	CFileDialog dlg(false,_T("BMP"),_T("*.bmp"),OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,"位图文件(*.bmp|*.bmp|",NULL);
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
		AfxMessageBox("保存成功");
	}
	GlobalFreePtr(lpData);
}

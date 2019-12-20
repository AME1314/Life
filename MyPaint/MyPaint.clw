; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyPaintView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MyPaint.h"
LastPage=0

ClassCount=5
Class1=CMyPaintApp
Class2=CMyPaintDoc
Class3=CMyPaintView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_Paint
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Resource3=IDD_ABOUTBOX

[CLS:CMyPaintApp]
Type=0
HeaderFile=MyPaint.h
ImplementationFile=MyPaint.cpp
Filter=N

[CLS:CMyPaintDoc]
Type=0
HeaderFile=MyPaintDoc.h
ImplementationFile=MyPaintDoc.cpp
Filter=N

[CLS:CMyPaintView]
Type=0
HeaderFile=MyPaintView.h
ImplementationFile=MyPaintView.cpp
Filter=C
LastObject=ID_FILE_SAVE
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=MyPaint.cpp
ImplementationFile=MyPaint.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[TB:IDR_Paint]
Type=1
Class=?
Command1=ID_PAINTCURVE
Command2=ID_PAINTLINE
Command3=ID_PAINTOVAL
Command4=ID_PAINTRECTANGLE
Command5=ID_PAINTOVAL_SOLID
Command6=ID_PAINTRECTANGLE_SOLID
Command7=ID_PAINTREASER
Command8=ID_PAINTFILL
Command9=ID_PAINTRED
Command10=ID_PAINTGREEN
Command11=ID_PAINTBLUE
Command12=ID_PAINTCOLOR
CommandCount=12


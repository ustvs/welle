; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMDIVolnaView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "mdivolna.h"
LastPage=0

ClassCount=11
Class1=CChildFrame
Class2=CDlgSetup4PlaneVolnovod
Class3=CDlgSetupIzlu
Class4=CDlgSetupMode
Class5=CDlgInputUgol
Class6=CDlgSetupVolnovod
Class7=CMainFrame
Class8=CMDIVolnaApp
Class9=CAboutDlg
Class10=CMDIVolnaDoc
Class11=CMDIVolnaView

ResourceCount=9
Resource1=IDD_DLG_SETUP_VOLNOVOD
Resource2=IDR_MAINFRAME
Resource3=IDD_DLG_ANDEREN
Resource4=IDR_MDIVOLTYPE
Resource5=IDD_DLG_SETUP_IZLU
Resource6=IDD_ABOUTBOX
Resource7=IDD_DLG_INPUT_UGOL
Resource8=IDR_MENU1
Resource9=IDR_MAINFRAME (English (U.S.))

[CLS:CChildFrame]
Type=0
BaseClass=CMDIChildWnd
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp

[CLS:CDlgSetup4PlaneVolnovod]
Type=0
BaseClass=CDialog
HeaderFile=DlgSetup4PlaneVolnovod.h
ImplementationFile=DlgSetup4PlaneVolnovod.cpp
Filter=D
VirtualFilter=dWC
LastObject=ID_VIEW_GRAF

[CLS:CDlgSetupIzlu]
Type=0
BaseClass=CDialog
HeaderFile=DlgSetupIzlu.h
ImplementationFile=DlgSetupIzlu.cpp

[CLS:CDlgSetupMode]
Type=0
BaseClass=CDialog
HeaderFile=DlgSetupMode.h
ImplementationFile=DlgSetupMode.cpp

[CLS:CDlgInputUgol]
Type=0
BaseClass=CDialog
HeaderFile=DlgSetupMode.h
ImplementationFile=DlgSetupMode.cpp
LastObject=CDlgInputUgol

[CLS:CDlgSetupVolnovod]
Type=0
BaseClass=CDialog
HeaderFile=DlgSetupVolnovod.h
ImplementationFile=DlgSetupVolnovod.cpp

[CLS:CMainFrame]
Type=0
BaseClass=CMDIFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp

[CLS:CMDIVolnaApp]
Type=0
BaseClass=CWinApp
HeaderFile=MDIVolna.h
ImplementationFile=MDIVolna.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=MDIVolna.cpp
ImplementationFile=MDIVolna.cpp

[CLS:CMDIVolnaDoc]
Type=0
BaseClass=CDocument
HeaderFile=MDIVolnaDoc.h
ImplementationFile=MDIVolnaDoc.cpp

[CLS:CMDIVolnaView]
Type=0
BaseClass=CView
HeaderFile=MDIVolnaView.h
ImplementationFile=MDIVolnaView.cpp
LastObject=ID_EDIT_ANDEREN
Filter=C
VirtualFilter=VWC

[DLG:IDD_DLG_SETUP_IZLU]
Type=1
Class=CDlgSetupIzlu
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT2,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,button,1342177287
Control9=IDC_RADIO_TE,button,1342308361
Control10=IDC_RADIO_TM,button,1342177289

[DLG:IDD_DLG_ANDEREN]
Type=1
Class=CDlgSetupMode
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_RADIO_F,button,1342308361
Control5=IDC_RADIO_CF,button,1342177289
Control6=IDC_RADIO_FS,button,1342177289
Control7=IDC_STAT,static,1342177294
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT1,edit,1350631424
Control10=IDC_BUTTON_HELP,button,1342242816

[DLG:IDD_DLG_INPUT_UGOL]
Type=1
Class=CDlgInputUgol
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631424
Control4=IDC_BUTTON_HELP,button,1342242816
Control5=IDCANCEL,button,1342242816

[DLG:IDD_DLG_SETUP_VOLNOVOD]
Type=1
Class=CDlgSetupVolnovod
ControlCount=16
Control1=IDOK,button,1342242816
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631424
Control4=IDC_EDIT2,edit,1350631424
Control5=IDC_EDIT3,edit,1350631424
Control6=IDC_EDIT4,edit,1350631424
Control7=IDC_STATIC,button,1342177287
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,button,1342177287
Control14=IDC_EDIT5,edit,1350631424
Control15=IDC_STATIC,static,1342308352
Control16=IDC_BUTTON_HELP,button,1342242816

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=6
Control1=IDC_STATIC,static,1342177294
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[TB:IDR_MAINFRAME]
Type=1
Class=CMDIVolnaView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_ANDEREN
Command6=ID_EDIT_IZLU
Command7=ID_EDIT_VOLNOVOD
Command8=ID_VIEW_TE_TM_1
Command9=ID_VIEW_TE_TM
Command10=ID_VIEW_MODE
Command11=ID_VIEW_GRAF
Command12=ID_VIEW_DIGITAL
Command13=ID_APP_ABOUT
CommandCount=13

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_APP_EXIT
Command5=ID_VIEW_TOOLBAR
Command6=ID_VIEW_STATUS_BAR
Command7=ID_APP_ABOUT
CommandCount=7

[MNU:IDR_MDIVOLTYPE]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_APP_EXIT
Command10=ID_EDIT_VOLNOVOD
Command11=ID_EDIT_IZLU
Command12=ID_EDIT_ANDEREN
Command13=ID_VIEW_GRAF
Command14=ID_VIEW_MODE
Command15=ID_VIEW_TE_TM
Command16=ID_VIEW_TE_TM_1
Command17=ID_VIEW_DIGITAL
Command18=ID_VIEW_TOOLBAR
Command19=ID_VIEW_STATUS_BAR
Command20=ID_VIEW_REFRESH
Command21=ID_WINDOW_NEW
Command22=ID_WINDOW_CASCADE
Command23=ID_WINDOW_TILE_HORZ
Command24=ID_APP_ABOUT
CommandCount=24

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_EDIT_VOLNOVOD
Command2=ID_EDIT_IZLU
Command3=ID_EDIT_ANDEREN
Command4=ID_VIEW_GRAF
Command5=ID_VIEW_MODE
Command6=ID_VIEW_TE_TM
Command7=ID_VIEW_TE_TM_1
Command8=ID_VIEW_DIGITAL
Command9=ID_VIEW_REFRESH
CommandCount=9

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT
Command4=ID_FILE_SAVE
Command5=ID_EDIT_PASTE
Command6=ID_EDIT_UNDO
Command7=ID_EDIT_CUT
Command8=ID_EDIT_VOLNOVOD
Command9=ID_VIEW_GRAF
Command10=ID_EDIT_IZLU
Command11=ID_VIEW_MODE
Command12=ID_EDIT_ANDEREN
Command13=ID_VIEW_TE_TM
Command14=ID_VIEW_TE_TM_1
Command15=ID_VIEW_DIGITAL
Command16=ID_NEXT_PANE
Command17=ID_PREV_PANE
Command18=ID_EDIT_COPY
Command19=ID_EDIT_PASTE
Command20=ID_EDIT_CUT
Command21=ID_EDIT_UNDO
CommandCount=21


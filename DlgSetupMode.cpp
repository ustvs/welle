// DlgSetupMode.cpp : implementation file
//

#include "stdafx.h"
#include "MDIVolna.h"
#include "DlgSetupMode.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSetupMode dialog


CDlgSetupMode::CDlgSetupMode(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSetupMode::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSetupMode)
	m_rb_F = -1;
	m_Ugol = 0.0;
	//}}AFX_DATA_INIT
}


void CDlgSetupMode::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSetupMode)
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
	DDX_Control(pDX, IDC_STAT, m_Bitmap);
	DDX_Radio(pDX, IDC_RADIO_F, m_rb_F);
	DDX_Text(pDX, IDC_EDIT1, m_Ugol);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSetupMode, CDialog)
	//{{AFX_MSG_MAP(CDlgSetupMode)
	ON_BN_CLICKED(IDC_RADIO_F, OnRadioF)
	ON_BN_CLICKED(IDC_RADIO_CF, OnRadioCf)
	ON_BN_CLICKED(IDC_RADIO_FS, OnRadioFs)
	ON_BN_CLICKED(IDC_BUTTON_HELP, OnButtonHelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSetupMode message handlers

BOOL CDlgSetupMode::OnInitDialog() 
{
	CDialog::OnInitDialog();
	HBITMAP hbitmap;
	char str[20];
	switch(pDoc->vol.mode)
	{
	case 0:
		{
			hbitmap=LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP1));
			sprintf(str, "%.4f", pDoc->vol.Teta*180/PI);
			m_Edit.SetWindowText(str);
			m_Edit.EnableWindow(false);
			break;
		}
	case 1:
		{
			
			hbitmap=LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP2));
			m_Edit.EnableWindow(true);
			sprintf(str, "%.4f", pDoc->vol.Teta*180/PI);
			m_Edit.SetWindowText(str);
			break;
		}
	case 2:
		{
			hbitmap=LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP3));
			m_Edit.EnableWindow(true);
			sprintf(str, "%.4f", pDoc->vol.Teta*180/PI);
			m_Edit.SetWindowText(str);
			break;
		}
	}
	m_Bitmap.SetBitmap(hbitmap);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgSetupMode::OnRadioF() 
{
	HBITMAP hbitmap;
	hbitmap=LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP1));
	m_Bitmap.SetBitmap(hbitmap);
	m_Edit.EnableWindow(false);
}

void CDlgSetupMode::OnRadioCf() 
{
	HBITMAP hbitmap;
	hbitmap=LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP2));
	m_Bitmap.SetBitmap(hbitmap);	
	m_Edit.EnableWindow(true);
}

void CDlgSetupMode::OnRadioFs() 
{
	HBITMAP hbitmap;
	hbitmap=LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP3));
	m_Bitmap.SetBitmap(hbitmap);
	m_Edit.EnableWindow(true);
}
/////////////////////////////////////////////////////////////////////////////
// CDlgInputUgol dialog


CDlgInputUgol::CDlgInputUgol(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgInputUgol::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgInputUgol)
	m_Ugol = 0.0;
	//}}AFX_DATA_INIT
}


void CDlgInputUgol::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgInputUgol)
	DDX_Text(pDX, IDC_EDIT1, m_Ugol);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgInputUgol, CDialog)
	//{{AFX_MSG_MAP(CDlgInputUgol)
	ON_BN_CLICKED(IDC_BUTTON_HELP, OnButtonHelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgInputUgol message handlers

void CDlgInputUgol::OnOK() 
{

	UpdateData(true);
	if( (m_Ugol > asin(pDoc->vol.Nc/pDoc->vol.Nf)*180/PI) &&
		(m_Ugol < asin(pDoc->vol.Ns/pDoc->vol.Nf)*180/PI) )
	{
		pDoc->vol.Teta = m_Ugol*PI/180;
		CDialog::OnOK();
	}
	else MessageBox("Enter Correct Corner", "Message");
}

BOOL CDlgInputUgol::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgInputUgol::OnButtonHelp() 
{

	char str[84];
	sprintf(str, "Available range: %.3f - %.3f",asin(pDoc->vol.Nc/pDoc->vol.Nf)*180/PI,
		asin(pDoc->vol.Ns/pDoc->vol.Nf)*180/PI);
	MessageBox(str, "Help");
}

void CDlgSetupMode::OnButtonHelp() 
{
	char str[84];
	UpdateData(true);
	if(m_rb_F == 2)
	{
		sprintf(str, "Available range: %.3f - %.3f",asin(pDoc->vol.Nc/pDoc->vol.Nf)*180/PI,
			asin(pDoc->vol.Ns/pDoc->vol.Nf)*180/PI);
		MessageBox(str, "Help", MB_ICONINFORMATION);
	}
	if(m_rb_F == 1)
	{
		sprintf(str, "Available range: 0 - %.3f",asin(pDoc->vol.Nc/pDoc->vol.Nf)*180/PI);
		MessageBox(str, "Help", MB_ICONINFORMATION);
	}
}

void CDlgSetupMode::OnOK() 
{

	UpdateData(true);
	if(m_rb_F == 2)
	{
		if((m_Ugol < asin(pDoc->vol.Nc/pDoc->vol.Nf)*180/PI) || 
			(m_Ugol > asin(pDoc->vol.Ns/pDoc->vol.Nf)*180/PI)  )
			MessageBox("Invalid angle. See help.", "Error", MB_ICONSTOP);
		else
			CDialog::OnOK();
	}

	if(m_rb_F == 1)
	{
		if((m_Ugol < 0) || 
			(m_Ugol > asin(pDoc->vol.Nc/pDoc->vol.Nf)*180/PI)  )
			MessageBox("Invalid angle. See help.", "Error", MB_ICONSTOP);
		else
			CDialog::OnOK();
	}
	if(m_rb_F == 0) 
		CDialog::OnOK();


}

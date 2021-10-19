// DlgSetupIzlu.cpp : implementation file
//

#include "stdafx.h"
#include "MDIVolna.h"
#include "DlgSetupIzlu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSetupIzlu dialog


CDlgSetupIzlu::CDlgSetupIzlu(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSetupIzlu::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSetupIzlu)
	m_lambda = 0.0;
	m_rb_TE = -1;
	m_Amplitude = 0.0;
	//}}AFX_DATA_INIT
}


void CDlgSetupIzlu::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSetupIzlu)
	DDX_Text(pDX, IDC_EDIT1, m_lambda);
	DDX_Radio(pDX, IDC_RADIO_TE, m_rb_TE);
	DDX_Text(pDX, IDC_EDIT2, m_Amplitude);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSetupIzlu, CDialog)
	//{{AFX_MSG_MAP(CDlgSetupIzlu)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSetupIzlu message handlers

BOOL CDlgSetupIzlu::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
/*	CButton *rb = (CButton *) GetDlgItem(IDC_RADIO_TE);
	m_rb_TE.SetCheck(true);
	rb = () GetDlgItem(IDC_RADIO_TM);
	m_rb_TM.SetCheck(false);
*/	
//	m_rb_TE = 1;
//	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



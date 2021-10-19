// DlgSetupVolnovod.cpp : implementation file
//

#include "stdafx.h"
#include "MDIVolna.h"
#include "Volna.h"
#include "DlgSetupVolnovod.h"
#include	 <math.h>
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSetupVolnovod dialog


CDlgSetupVolnovod::CDlgSetupVolnovod(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSetupVolnovod::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSetupVolnovod)
	m_Nc = 0.0;
	m_Nf = 0.0;
	m_Ns = 0.0;
	m_h = 0.0;
	m_v = 0;
	//}}AFX_DATA_INIT
}


void CDlgSetupVolnovod::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSetupVolnovod)
	DDX_Text(pDX, IDC_EDIT1, m_Nc);
	DDX_Text(pDX, IDC_EDIT2, m_Nf);
	DDX_Text(pDX, IDC_EDIT3, m_Ns);
	DDX_Text(pDX, IDC_EDIT4, m_h);
	DDX_Text(pDX, IDC_EDIT5, m_v);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSetupVolnovod, CDialog)
	//{{AFX_MSG_MAP(CDlgSetupVolnovod)
	ON_BN_CLICKED(IDC_BUTTON_HELP, OnButtonHelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSetupVolnovod message handlers

void CDlgSetupVolnovod::OnOK() 
{
	CVolna* tmp = new CVolna();
	
	char* str = new char[20];
	CEdit* ce = (CEdit* )GetDlgItem(IDC_EDIT1);
	ce->GetWindowText(str, 20);
	tmp->Nc = atof(str);
	
	
	ce = (CEdit* )GetDlgItem(IDC_EDIT2);
	ce->GetWindowText(str, 20);
	tmp->Nf = atof(str);
			
	ce = (CEdit* )GetDlgItem(IDC_EDIT3);
	ce->GetWindowText(str, 20);
	tmp->Ns = atof(str);
	
	ce = (CEdit* )GetDlgItem(IDC_EDIT4);
	ce->GetWindowText(str, 20);
	tmp->h = atof(str)*1e-6;
	
	ce = (CEdit* )GetDlgItem(IDC_EDIT5);
	ce->GetWindowText(str, 20);
	tmp->v = atoi(str);
	
	tmp->lambda = pDoc->vol.lambda;
	tmp->type_welle = pDoc->vol.type_welle;
	tmp->mode = pDoc->vol.mode;

	double res = tmp->FindenTeta(); 
//	if(tmp->h > 100e-6 || tmp->h < tmp->lambda/2.) MessageBox("Толщина должна быть соизмерима с длиной волны", "Ошибка ввода значения толщины пленки");
//	else
//	{
		if(tmp->Nf > tmp->Ns)
			if(tmp->Ns >= tmp->Nc)
			{
				if(!pDoc->vol.mode)
				{
					if( res == ERROR_INTERVAL )
						MessageBox("Недопустимая мода");
					else CDialog::OnOK();
				}
				else CDialog::OnOK();
			}
		else MessageBox("Введенные  коэффициенты преломления\nнедопустимы. Пожалуйста введите правильные!!");
//	}
	delete []str;
	delete tmp;
}

void CDlgSetupVolnovod::OnButtonHelp() 
{

	CVolna* tmp = new CVolna();
	
	char* str = new char[84];
	CEdit* ce = (CEdit* )GetDlgItem(IDC_EDIT1);
	ce->GetWindowText(str, 20);
	tmp->Nc = atof(str);
	
	
	ce = (CEdit* )GetDlgItem(IDC_EDIT2);
	ce->GetWindowText(str, 20);
	tmp->Nf = atof(str);
			
	ce = (CEdit* )GetDlgItem(IDC_EDIT3);
	ce->GetWindowText(str, 20);
	tmp->Ns = atof(str);
	
	ce = (CEdit* )GetDlgItem(IDC_EDIT4);
	ce->GetWindowText(str, 20);
	tmp->h = atof(str)*1e-6;
	
	ce = (CEdit* )GetDlgItem(IDC_EDIT5);
	ce->GetWindowText(str, 20);
	tmp->v = atoi(str);
	
	tmp->lambda = pDoc->vol.lambda;
	tmp->type_welle = pDoc->vol.type_welle;

	
	int count =int( 2*tmp->h/tmp->lambda*sqrt(tmp->Nf*tmp->Nf -
		tmp->Ns*tmp->Ns) );
	sprintf(str, "Примерное количество волноводных мод: %d", count);
	MessageBox(str, "Справка",MB_ICONINFORMATION);
	delete []str;
	delete tmp;
}

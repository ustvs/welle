#if !defined(AFX_DLGSETUPIZLU_H__765528C5_5318_11D4_81AA_0000E8DAC825__INCLUDED_)
#define AFX_DLGSETUPIZLU_H__765528C5_5318_11D4_81AA_0000E8DAC825__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgSetupIzlu.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSetupIzlu dialog

class CDlgSetupIzlu : public CDialog
{
// Construction
public:
	CDlgSetupIzlu(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSetupIzlu)
	enum { IDD = IDD_DLG_SETUP_IZLU };
	double	m_lambda;
	int		m_rb_TE;
	double	m_Amplitude;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSetupIzlu)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSetupIzlu)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSETUPIZLU_H__765528C5_5318_11D4_81AA_0000E8DAC825__INCLUDED_)

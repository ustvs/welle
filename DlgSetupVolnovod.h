#if !defined(AFX_DLGSETUPVOLNOVOD_H__765528C4_5318_11D4_81AA_0000E8DAC825__INCLUDED_)
#define AFX_DLGSETUPVOLNOVOD_H__765528C4_5318_11D4_81AA_0000E8DAC825__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgSetupVolnovod.h : header file
//
#include "MDIVolnaDoc.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgSetupVolnovod dialog

class CDlgSetupVolnovod : public CDialog
{
// Construction
public:
	CMDIVolnaDoc* pDoc;
	CDlgSetupVolnovod(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSetupVolnovod)
	enum { IDD = IDD_DLG_SETUP_VOLNOVOD };
	double	m_Nc;
	double	m_Nf;
	double	m_Ns;
	double	m_h;
	int		m_v;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSetupVolnovod)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSetupVolnovod)
	virtual void OnOK();
	afx_msg void OnButtonHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSETUPVOLNOVOD_H__765528C4_5318_11D4_81AA_0000E8DAC825__INCLUDED_)

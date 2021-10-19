#if !defined(AFX_DLGSETUPMODE_H__26F7C7C1_557E_11D4_81AA_0000E8DAC825__INCLUDED_)
#define AFX_DLGSETUPMODE_H__26F7C7C1_557E_11D4_81AA_0000E8DAC825__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgSetupMode.h : header file
//
#include "MDIVolnaDoc.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgSetupMode dialog

class CDlgSetupMode : public CDialog
{
// Construction
public:
	CMDIVolnaDoc* pDoc;
	CDlgSetupMode(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSetupMode)
	enum { IDD = IDD_DLG_ANDEREN };
	CEdit	m_Edit;
	CStatic	m_Bitmap;
	int		m_rb_F;
	double	m_Ugol;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSetupMode)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSetupMode)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioF();
	afx_msg void OnRadioCf();
	afx_msg void OnRadioFs();
	afx_msg void OnButtonHelp();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HBITMAP bitmap;
};

/////////////////////////////////////////////////////////////////////////////
// CDlgInputUgol dialog

class CDlgInputUgol : public CDialog
{
// Construction
public:
	CMDIVolnaDoc* pDoc;
	CDlgInputUgol(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgInputUgol)
	enum { IDD = IDD_DLG_INPUT_UGOL };
	double	m_Ugol;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgInputUgol)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgInputUgol)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSETUPMODE_H__26F7C7C1_557E_11D4_81AA_0000E8DAC825__INCLUDED_)

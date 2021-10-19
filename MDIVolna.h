// MDIVolna.h : main header file for the MDIVOLNA application
//

#if !defined(AFX_MDIVOLNA_H__1CF1C927_51C2_11D4_81AA_0000E8DAC825__INCLUDED_)
#define AFX_MDIVOLNA_H__1CF1C927_51C2_11D4_81AA_0000E8DAC825__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMDIVolnaApp:
// See MDIVolna.cpp for the implementation of this class
//

class CMDIVolnaApp : public CWinApp
{
public:
	CMDIVolnaApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMDIVolnaApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMDIVolnaApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDIVOLNA_H__1CF1C927_51C2_11D4_81AA_0000E8DAC825__INCLUDED_)

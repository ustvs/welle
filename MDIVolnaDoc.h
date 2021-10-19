// MDIVolnaDoc.h : interface of the CMDIVolnaDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MDIVOLNADOC_H__1CF1C92F_51C2_11D4_81AA_0000E8DAC825__INCLUDED_)
#define AFX_MDIVOLNADOC_H__1CF1C92F_51C2_11D4_81AA_0000E8DAC825__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "volna.h"

class CMDIVolnaDoc : public CDocument
{
protected: // create from serialization only
	CMDIVolnaDoc();
	DECLARE_DYNCREATE(CMDIVolnaDoc)

// Attributes
public:
	CVolna	vol;
	// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMDIVolnaDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	bool isNew;
	virtual ~CMDIVolnaDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMDIVolnaDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDIVOLNADOC_H__1CF1C92F_51C2_11D4_81AA_0000E8DAC825__INCLUDED_)

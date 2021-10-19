// MDIVolnaView.h : interface of the CMDIVolnaView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MDIVOLNAVIEW_H__1CF1C931_51C2_11D4_81AA_0000E8DAC825__INCLUDED_)
#define AFX_MDIVOLNAVIEW_H__1CF1C931_51C2_11D4_81AA_0000E8DAC825__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
///////////////////////////////////////////////////////////////////////
#define		VIEW_TE_TM		0
#define		VIEW_TE_TM_1	1
#define		VIEW_GRAF		2
#define		VIEW_MODE		3
///////////////////////////////////////////////////////////////////////
//RECT rect0;

class CMDIVolnaView : public CView
{
protected: // create from serialization only

	CMDIVolnaView();
	DECLARE_DYNCREATE(CMDIVolnaView)

// Attributes
public:
	CMDIVolnaDoc* GetDocument();
	CMenu menu;
	//int maxX, maxY;
	//CDC memDC;
	//CBitmap bmp;
	//CBrush  bkbrush;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMDIVolnaView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	int flag;
	void Calculate(int flag, CDC* pDC);
	RECT rect;
	void Net(CDC* pDC);
	virtual ~CMDIVolnaView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMDIVolnaView)
	afx_msg void OnEditIzlu();
	afx_msg void OnEditVolnovod();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnEditAnderen();
	afx_msg void OnViewGraf();
	afx_msg void OnViewRefresh();
	afx_msg void OnViewTeTm();
	afx_msg void OnViewTeTm1();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnViewDigital();
	afx_msg void OnViewMode();
	afx_msg void OnUpdateViewDigital(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEdit3plane(CCmdUI* pCmdUI);
	afx_msg void OnUpdate4plane(CCmdUI* pCmdUI);
	afx_msg void OnEdit3plane();
	afx_msg void OnUpdateViewGraf(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewMode(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewTeTm(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewTeTm1(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void Title_big(bool, CDC*);
	void PaintMode(CDC* pDC);
	CFont* cur_font_it;
	CFont* symb_font;
	TEXTMETRIC tm;
	CFont* small_font;
	CFont* cur_font;
	void PaintFx(CDC* pDC);
	void PaintFc(CDC* pDC);
	void PaintFs(CDC* pDC);
	void Paint_Graf_Define(CDC* pDC);
};

#ifndef _DEBUG  // debug version in MDIVolnaView.cpp
inline CMDIVolnaDoc* CMDIVolnaView::GetDocument()
   { return (CMDIVolnaDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDIVOLNAVIEW_H__1CF1C931_51C2_11D4_81AA_0000E8DAC825__INCLUDED_)

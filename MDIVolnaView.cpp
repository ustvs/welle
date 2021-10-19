// MDIVolnaView.cpp : implementation of the CMDIVolnaView class
//

#include "stdafx.h"
#include "MDIVolna.h"
#include  <string.h>

#include "Volna.h"
#include "MDIVolnaDoc.h"
#include "MDIVolnaView.h"
#include "DlgSetupVolnovod.h"
#include "DlgSetupIzlu.h"
#include "DlgSetupMode.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include <math.h>
/////////////////////////////////////////////////////////////////////////////
// CMDIVolnaView

IMPLEMENT_DYNCREATE(CMDIVolnaView, CView)

BEGIN_MESSAGE_MAP(CMDIVolnaView, CView)
	//{{AFX_MSG_MAP(CMDIVolnaView)
	ON_COMMAND(ID_EDIT_IZLU, OnEditIzlu)
	ON_COMMAND(ID_EDIT_VOLNOVOD, OnEditVolnovod)
	ON_WM_SIZE()
	ON_COMMAND(ID_EDIT_ANDEREN, OnEditAnderen)
	ON_COMMAND(ID_VIEW_GRAF, OnViewGraf)
	ON_COMMAND(ID_VIEW_REFRESH, OnViewRefresh)
	ON_COMMAND(ID_VIEW_TE_TM, OnViewTeTm)
	ON_COMMAND(ID_VIEW_TE_TM_1, OnViewTeTm1)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_VIEW_DIGITAL, OnViewDigital)
	ON_COMMAND(ID_VIEW_MODE, OnViewMode)
	ON_UPDATE_COMMAND_UI(ID_VIEW_DIGITAL, OnUpdateViewDigital)
	ON_UPDATE_COMMAND_UI(ID_EDIT_3PLANE, OnUpdateEdit3plane)
	ON_UPDATE_COMMAND_UI(ID_4PLANE, OnUpdate4plane)
	ON_COMMAND(ID_EDIT_3PLANE, OnEdit3plane)
	ON_UPDATE_COMMAND_UI(ID_VIEW_GRAF, OnUpdateViewGraf)
	ON_UPDATE_COMMAND_UI(ID_VIEW_MODE, OnUpdateViewMode)
	ON_UPDATE_COMMAND_UI(ID_VIEW_TE_TM, OnUpdateViewTeTm)
	ON_UPDATE_COMMAND_UI(ID_VIEW_TE_TM_1, OnUpdateViewTeTm1)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMDIVolnaView construction/destruction

CMDIVolnaView::CMDIVolnaView()
{
	cur_font_it = new CFont;
	//cur_font_it->CreatePointFont(2500, "Arial Italic");
	cur_font_it->CreateFont(470,
			0, 0, 0, FW_SEMIBOLD, TRUE, FALSE, 0,
			RUSSIAN_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
			DEFAULT_QUALITY, DEFAULT_PITCH|FF_SWISS, "Arial");
	
	cur_font = new CFont;
	cur_font->CreateFont(470,
			0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, 0,
			RUSSIAN_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
			DEFAULT_QUALITY, DEFAULT_PITCH|FF_SWISS, "Arial");
	symb_font = new CFont;
	symb_font->CreateFont(700,
			0, 0, 0, FW_NORMAL, TRUE, FALSE, 0,
			ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
			DEFAULT_QUALITY, DEFAULT_PITCH|FF_SWISS, "Symbol");
	small_font = new CFont;
	small_font->CreateFont(370,
			0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, 0,
			RUSSIAN_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
			DEFAULT_QUALITY, DEFAULT_PITCH|FF_SWISS, "Arial");
	flag = 0;
}

CMDIVolnaView::~CMDIVolnaView()
{
	cur_font_it->DeleteObject();
	cur_font->DeleteObject();
	small_font->DeleteObject();
	symb_font->DeleteObject();
}

BOOL CMDIVolnaView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	CBrush bk(RGB(255, 255, 255));
	cs.lpszClass = AfxRegisterWndClass(CS_DBLCLKS, 
					AfxGetApp()->LoadStandardCursor(IDC_CROSS), bk,
					AfxGetApp()->LoadIcon(IDR_MAINFRAME));
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMDIVolnaView drawing

void CMDIVolnaView::OnDraw(CDC* pDC)	// OnPaint
{
	CMDIVolnaDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
/*	if(pDoc->vol.type_volnovod == 4)
	{
		CBrush* old;
		old = (CBrush*)pDC->SelectStockObject(WHITE_BRUSH);
		pDC->Rectangle(0, 0, rect.right, rect.bottom);
		pDC->SelectObject(old);
		return;
	}
*/
	pDC->SetMapMode(MM_HIMETRIC);
	Calculate(flag, pDC);
	
}

/////////////////////////////////////////////////////////////////////////////
// CMDIVolnaView printing

BOOL CMDIVolnaView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMDIVolnaView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMDIVolnaView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMDIVolnaView diagnostics

#ifdef _DEBUG
void CMDIVolnaView::AssertValid() const
{
	CView::AssertValid();
}

void CMDIVolnaView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMDIVolnaDoc* CMDIVolnaView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMDIVolnaDoc)));
	return (CMDIVolnaDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMDIVolnaView message handlers


void CMDIVolnaView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
}

void CMDIVolnaView::OnEditIzlu() 
{
	// TODO: Add your command handler code here
	CMDIVolnaDoc *pDoc = (CMDIVolnaDoc *) GetDocument();
	
	CDlgSetupIzlu	DlgSetupIzlu;

	DlgSetupIzlu.m_lambda = pDoc->vol.lambda*1e6;
	DlgSetupIzlu.m_Amplitude = pDoc->vol.Amplitude;
	DlgSetupIzlu.m_rb_TE = !pDoc->vol.type_welle;

	int result = DlgSetupIzlu.DoModal();

    if(result == IDOK)
	{
		pDoc->vol.lambda = DlgSetupIzlu.m_lambda*1e-6;
		pDoc->vol.Amplitude = DlgSetupIzlu.m_Amplitude;
		pDoc->vol.type_welle = !DlgSetupIzlu.m_rb_TE;
	
		InvalidateRect(NULL);
		pDoc->SetModifiedFlag();
	}
}

void CMDIVolnaView::OnEditVolnovod() 
{
	// TODO: Add your command handler code here
	CMDIVolnaDoc *pDoc = (CMDIVolnaDoc *) GetDocument();
	
	CDlgSetupVolnovod	DlgSetupVol;

	DlgSetupVol.m_h  = pDoc->vol.h*1e6;
	DlgSetupVol.m_Nc = pDoc->vol.Nc;
	DlgSetupVol.m_Nf = pDoc->vol.Nf;
	DlgSetupVol.m_Ns = pDoc->vol.Ns;
	DlgSetupVol.m_v  = pDoc->vol.v;
	DlgSetupVol.pDoc = pDoc;
	
	int result = DlgSetupVol.DoModal();

	
    
	if(result == IDOK)
	{
		pDoc->vol.h  = DlgSetupVol.m_h*1e-6;
		pDoc->vol.Nc = DlgSetupVol.m_Nc;
		pDoc->vol.Nf = DlgSetupVol.m_Nf;
		pDoc->vol.Ns = DlgSetupVol.m_Ns;
		pDoc->vol.v  = DlgSetupVol.m_v;
		pDoc->SetModifiedFlag();		
		InvalidateRect(NULL);
	}
}


void CMDIVolnaView::Net(CDC* pDC)
{

	CFont* old_font;
	int i;
	CMDIVolnaDoc *pDoc = (CMDIVolnaDoc *) GetDocument();
	CClientDC dc(this);
	old_font = dc.SelectObject(cur_font);
	pDC->SelectObject(cur_font);
	dc.GetTextMetrics(&tm);

	CPen pen(PS_SOLID, 1, RGB(125, 125, 125));
	
	CPen* old_pen = pDC->SelectObject(&pen);
	
	//Vertical:
	pDC->MoveTo(1500, -2500);

	double koef =((double)rect.right - 2500.)/9.;
	for(i = 0; i<10; i++)
	{	
		pDC->LineTo(int(1500 + koef*(double)i),
			rect.bottom + 400 + 2*tm.tmHeight);
		pDC->MoveTo(int(1500+ koef*(double)(i+1)),
			-2500);
	}

	//Horizontal:

	pDC->MoveTo(1500, -2500);
	koef = ((double)rect.bottom + 2900. + 2*tm.tmHeight)/9.;
	for(i = 0; i<10; i++)
	{	
		pDC->LineTo(rect.right - 1000,
			int(-2500 + koef*(double)i) );
		pDC->MoveTo(1500,
			int(-2500 + koef*double( (i+1) ) ) );
	}
	pDC->SelectObject(old_pen);

	//Ïîäïèñü ê ãðàôèêó
	pDC->TextOut(int(1500. - dc.GetTextExtent("0", 1).cx*2),
		rect.bottom + 300 + 2*tm.tmHeight,"0", 1);
	pDC->TextOut(int(1500. - dc.GetTextExtent("180", 3).cx*1.5),
		- 2500,"180", 3);
	pDC->TextOut(int(1500 + (rect.right - 2500)/9*3 - dc.GetTextExtent("30", 2).cx*.5),
		 rect.bottom + 300 + 2*tm.tmHeight,"30", 2);
	pDC->TextOut(int(1500 + (rect.right - 2500)/9*6 - dc.GetTextExtent("60", 2).cx*.5),
		rect.bottom + 300 + 2*tm.tmHeight, "60", 2);	
	
	pDC->TextOut(int(1500. - dc.GetTextExtent("60", 2).cx*1.7),
		int(- 2250. + (rect.bottom + 2900 + 2*tm.tmHeight)/9*6),"60", 2);
	pDC->TextOut(int(1500. - dc.GetTextExtent("90", 2).cx*1.7),
		int(- 2250.+ (rect.bottom + 2900 + 2*tm.tmHeight)/9*3),"90", 2);
	
	//Ïîäïèñûâàåì ãðàäóñû äëÿ ýòèõ ïîäïèñåé
	pDC->SelectObject(small_font);
	pDC->TextOut(int(1500. - dc.GetTextExtent("0", 1).cx*.8),
		rect.bottom + 300 + 2*tm.tmHeight,"0", 1);
	pDC->TextOut(int(1500. - dc.GetTextExtent("180", 3).cx*.3),
		- 2500,"0", 1);
	pDC->TextOut(int(1500 + (rect.right - 2500)/9*3 + dc.GetTextExtent("30", 2).cx*.7),
		 rect.bottom + 300 + 2*tm.tmHeight,"0", 1);
	pDC->TextOut(int(1500 + (rect.right - 2500)/9*6 + dc.GetTextExtent("60", 2).cx*.7),
		rect.bottom + 300 + 2*tm.tmHeight, "0", 1);	
	
	pDC->TextOut(int(1500. - dc.GetTextExtent("60", 2).cx*.5),
		int(- 2250. + (rect.bottom + 2900 + 2*tm.tmHeight)/9*6),"0", 1);
	pDC->TextOut(int(1500. - dc.GetTextExtent("90", 2).cx*.5),
		int(- 2250. + (rect.bottom + 2900 + 2*tm.tmHeight)/9*3),"0", 1);
	
	//Ïîäïèñûâàåì òåòà
	pDC->SelectObject(symb_font);
	dc.SelectObject(symb_font);	
	pDC->TextOut(rect.right - 900,
		rect.bottom + 500 + 2*tm.tmHeight, "q", 1);

	dc.SelectObject(old_font);
	pDC->SelectObject(old_font);

	Title_big(true, pDC);

}

void CMDIVolnaView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	CMDIVolnaDoc *pDoc = (CMDIVolnaDoc *) GetDocument();
	ASSERT_VALID(pDoc);

	// Çàïèñûâàåì íîâûå ðàçìåðû îêíà â ÷ëåí êëàññà CMDIVolnaView::rect
	CClientDC dc(this);
	dc.SetMapMode(MM_HIMETRIC);
	GetClientRect(&rect);
	dc.DPtoLP(&rect);

	InvalidateRect(FALSE);
}

void CMDIVolnaView::OnEditAnderen() 
{
	CMDIVolnaDoc *pDoc = (CMDIVolnaDoc *) GetDocument();	
	
	CDlgSetupMode	DlgSetupMode;
	DlgSetupMode.pDoc = pDoc;
	DlgSetupMode.m_rb_F = pDoc->vol.mode;
	int result = DlgSetupMode.DoModal();
	
	if(result == IDOK)
	{
		UpdateData(true);
		pDoc->vol.mode = DlgSetupMode.m_rb_F;
		pDoc->SetModifiedFlag();
		pDoc->vol.Teta = DlgSetupMode.m_Ugol*PI/180;
		InvalidateRect(NULL);
	}

}

//*********************************************************************	
//			The first graph is the dependence of the Fc from the corner
//*********************************************************************	

void CMDIVolnaView::PaintFc(CDC* pDC)
{
	CFont* old_font;
	CMDIVolnaDoc *pDoc = (CMDIVolnaDoc *) GetDocument();
	pDC->SetMapMode(MM_HIMETRIC);

	CSize shift;
	old_font = pDC->SelectObject(cur_font);
	pDC->GetTextMetrics(&tm);
	pDC->SelectObject(cur_font);
	//Ïîäïèñü ê ãðàôèêó:
	CString title("Dependence of phase shifts at the boundaries on the propagation angle");
	CString type, TE("For TE wave"), TM("For TM wave");
	shift = pDC->GetTextExtent(title);
	pDC->TextOut(rect.right/2 - shift.cx/2,
		- int(tm.tmHeight * 1.), title);
	if(pDoc->vol.type_welle == 1) type = TE;
	else type = TM;
	shift = pDC->GetTextExtent(type);
	pDC->TextOut(rect.right/2 - shift.cx/2,
		- int( tm.tmHeight * 2. ), type);
	
	char str[84];	
	int len = tm.tmAveCharWidth*11;
	
	//Picture of normal symbols:
	pDC->SelectObject(cur_font_it);
	pDC->TextOut(rect.right/2 - len/2, 
			- int(tm.tmHeight * 3.5), "n", 1 );
	pDC->TextOut(rect.right/2 - len/2 - 500 - len, 
			- int(tm.tmHeight * 3.5), "n", 1 );
	pDC->TextOut(rect.right/2 + len/2 + 500, 
			- int(tm.tmHeight * 3.5), "n", 1 );

	//Draw small symbols:
	pDC->SelectObject(small_font);
	pDC->TextOut(rect.right/2 - len/2 + int(tm.tmAveCharWidth*1.3), 
		- int(tm.tmHeight * 4), "c", 1);
	pDC->TextOut(rect.right/2 - len/2 - 500 - len + int(tm.tmAveCharWidth*1.3), 
		- int(tm.tmHeight * 4), "f", 1);
	pDC->TextOut(rect.right/2 + len/2 + 500 + int(tm.tmAveCharWidth*1.3), 
		- int(tm.tmHeight * 4), "s", 1);
	
	pDC->SelectObject(cur_font);
	
	//Write values to the symbols Nc, Nf, Nc
	sprintf(str, "= %.4f", pDoc->vol.Nc);
	title = str;
	pDC->TextOut(rect.right/2 - len/2 + 3 * tm.tmAveCharWidth, 
			- int(tm.tmHeight * 3.5), title);
	sprintf(str, "= %.4f", pDoc->vol.Nf);
	title = str;
	pDC->TextOut(rect.right/2 - len/2 - 500 - len + 3 * tm.tmAveCharWidth, 
			- int(tm.tmHeight * 3.5), title);
	sprintf(str, "= %.4f", pDoc->vol.Ns);
	title = str;
	pDC->TextOut(rect.right/2 + len/2 + 500 + 3 * tm.tmAveCharWidth, 
			- int(tm.tmHeight * 3.5), title);

	//Grid captions
	pDC->SelectObject(symb_font);
	
	pDC->SetTextColor(RGB(255, 0, 0));
	pDC->TextOut(1500 - int(pDC->GetTextExtent("f",1).cx*2),
		- 2300, "f", 1);
	pDC->SetTextColor(RGB(0, 0, 255));
	pDC->TextOut(rect.right/2 + 500 - int(pDC->GetTextExtent("f",1).cx*2),
		- 2300, "f", 1);
	pDC->SetTextColor(RGB(0, 0, 0));

	pDC->TextOut(rect.right/2 - 500 + int(pDC->GetTextExtent("q",1).cx*.1),
		rect.bottom + 1100, "q", 1);
	pDC->TextOut(rect.right - 1500 + int(pDC->GetTextExtent("q",1).cx*.1),
		rect.bottom + 1100, "q", 1);

	pDC->SelectObject(small_font);
	pDC->SetTextColor(RGB(255, 0, 0));
	pDC->TextOut(1500 - int(pDC->GetTextExtent("c",1).cx*1),
		- 2300 - int(tm.tmHeight*.9), "c", 1);
	pDC->SetTextColor(RGB(0, 0, 255));	
	pDC->TextOut(rect.right/2 + 500 - int(pDC->GetTextExtent("s",1).cx*1),
		- 2300 - int(tm.tmHeight*.9), "s", 1);
	pDC->SetTextColor(RGB(0, 0, 0));

	pDC->SelectObject(cur_font);

	pDC->TextOut(1500 - int(pDC->GetTextExtent("0",1).cx*1.2),
		rect.bottom + 900, "0", 1);
	pDC->TextOut(rect.right/2 + int(pDC->GetTextExtent("0",1).cx*1.2),
		rect.bottom + 900, "0", 1);
	pDC->TextOut(rect.right  - 1500 + int(pDC->GetTextExtent("90",2).cx*.2),
		-2300, "90", 2);
	pDC->TextOut(rect.right/2 + 500 +(rect.right/2 - 2000)/9*3 - int(pDC->GetTextExtent("30",2).cx*.5),
		rect.bottom + 900 , "30");
	pDC->TextOut(rect.right/2 + 500 +(rect.right/2 - 2000)/9*6 - int(pDC->GetTextExtent("30",2).cx*.5),
		rect.bottom + 900 , "60");
	pDC->TextOut(1500 +(rect.right/2 - 2000)/9*3 - int(pDC->GetTextExtent("30",2).cx*.5),
		rect.bottom + 900 , "30");
	pDC->TextOut(1500 +(rect.right/2 - 2000)/9*6 - int(pDC->GetTextExtent("30",2).cx*.5),
		rect.bottom + 900 , "60");
	
	pDC->TextOut(rect.right/2 - int(pDC->GetTextExtent("30", 2).cx/2.),
		- 2500 + (rect.bottom + 3500)/9*6 + int(pDC->GetTextExtent("30",2).cy*.5), "30");
	pDC->TextOut(rect.right/2 -  int(pDC->GetTextExtent("60", 2).cx/2.),
		- 2500 + (rect.bottom + 3500)/9*3 + int(pDC->GetTextExtent("60",2).cy*.5), "60");
	
	//Write grades
	pDC->SelectObject(small_font);
	pDC->TextOut(1500 - int(pDC->GetTextExtent("0",1).cx*.2),
		rect.bottom + 900, "0", 1);
	pDC->TextOut(rect.right/2 + int(pDC->GetTextExtent("0",1).cx*2.2),
		rect.bottom + 900, "0", 1);
	pDC->TextOut(rect.right  - 1500 + int(pDC->GetTextExtent("90",2).cx*1.2),
		-2300, "0", 1);
	pDC->TextOut(rect.right/2 + 500 +(rect.right/2 - 2000)/9*3 + int(pDC->GetTextExtent("30",2).cx*.5),
		rect.bottom + 900 , "0", 1);
	pDC->TextOut(rect.right/2 + 500 +(rect.right/2 - 2000)/9*6 + int(pDC->GetTextExtent("30",2).cx*.5),
		rect.bottom + 900 , "0", 1);
	pDC->TextOut(1500 +(rect.right/2 - 2000)/9*3 + int(pDC->GetTextExtent("30",2).cx*.5),
		rect.bottom + 900 , "0", 1);
	pDC->TextOut(1500 +(rect.right/2 - 2000)/9*6 + int(pDC->GetTextExtent("30",2).cx*.5),
		rect.bottom + 900 , "0", 1);
	
	pDC->TextOut(rect.right/2 + int(pDC->GetTextExtent("30", 2).cx/2.),
		- 2500 + (rect.bottom + 3500)/9*6 + int(pDC->GetTextExtent("30",2).cy*.5), "0", 1);
	pDC->TextOut(rect.right/2 +  int(pDC->GetTextExtent("60", 2).cx/2.),
		- 2500 + (rect.bottom + 3500)/9*3 + int(pDC->GetTextExtent("60",2).cy*.5), "0", 1);
	
	//Drawing a grid for the graph
	CPen pen(PS_SOLID, 1, RGB(125, 125, 125));
	CPen* old_pen = pDC->SelectObject(&pen);

	int i;
	pDC->MoveTo(1500, - 2500);
	double koef =((double)rect.right/2 - 2000.)/9.;
	for(i = 0; i<10; i++)
	{	// vertical lines
		pDC->LineTo(int(1500 + koef*(double)i), rect.bottom + 1000);
		pDC->MoveTo(int(1500 + koef*(double)(i+1)), -2500);
	}
	
	pDC->MoveTo(1500, -2500);
	koef = ((double)rect.bottom + 3500)/9.;
	for(i = 0; i<10; i++)
	{	// ãîðèçîíòàëüíûå ëèíèè
		pDC->LineTo(rect.right/2 - 500,int(-2500 + koef*(double)i) );
		pDC->MoveTo(1500, int(-2500 + koef*(double)(i+1)) );
	}

	pDC->SelectObject(old_pen);

	//Draw graph:

	pDC->MoveTo(rect.right/2 - 500, - 2500);
	CPoint point;
	point.y = -2500;
	double d;
	double koef_x = (rect.right/2 - 2000)/(PI/2);
	double koef_y = (rect.bottom + 3500)/(PI/2);
	pen.DeleteObject();
	CPen pen2(PS_SOLID, 1, RGB(255, 0, 0));
	old_pen = pDC->SelectObject(&pen2);
	for(d = PI/2; d >= 0; d -=PI/5000)
	{
		point.x = int(1500. + d*koef_x);
		if(pDoc->vol.FindenFc(d) == OUR_ERROR)break;
		else point.y = int((double)rect.bottom + 1000. - koef_y*pDoc->vol.FindenFc(d));
		pDC->LineTo(point);
	}
	pDC->SelectObject(old_pen);
	pDC->SelectObject(old_font);
}

//*********************************************************************	
//			The right graph is the dependence of the Fs from the corner
//*********************************************************************	
void CMDIVolnaView::PaintFs(CDC* pDC)
{

	CPen pen(PS_SOLID, 1, RGB(125, 125, 125));
	
	CMDIVolnaDoc *pDoc = (CMDIVolnaDoc *) GetDocument();
	CPen* old_pen = pDC->SelectObject(&pen);

	int i;
	//Vertical lines:

	pDC->MoveTo(rect.right/2 + 500, -2500);
	double koef =((double)rect.right/2 - 2000)/9.;
	for(i = 0; i<10; i++)
	{	
		pDC->LineTo(int(rect.right/2 + 500 + koef*(double)i), rect.bottom + 1000);
		pDC->MoveTo(int(rect.right/2 + 500 + koef*(double)(i+1)), -2500);
	}

	//Horizontal lines:

	pDC->MoveTo(rect.right/2 + 500, -2500);
	koef = ((double)rect.bottom + 3500)/9.;
	for(i = 0; i<10; i++)
	{	
		pDC->LineTo(rect.right - 1500, int(-2500 + koef*(double)i) );
		pDC->MoveTo(rect.right/2 + 500, int(-2500 + koef*(double)(i+1)) );
	}

	pDC->SelectObject(old_pen);

	//Draw Graph:

	pDC->MoveTo(rect.right - 1500, - 2500);
	CPoint point;
	point.y = - 2500;
	double d;
	double koef_x = (rect.right/2 - 2000)/(PI/2);
	double koef_y = (rect.bottom + 3500)/(PI/2);
	
	pen.DeleteObject();
	CPen pen2(PS_SOLID, 1, RGB(0, 0, 255));
	
	for(d = PI/2; d >= 0; d -=PI/5000)
	{
		point.x = int(rect.right/2 + 500. + d*koef_x);
		if(pDoc->vol.FindenFs(d) == OUR_ERROR) break;//point.y = rect.bottom - 50;
		else point.y = int((double)rect.bottom + 1000. - koef_y*pDoc->vol.FindenFs(d));
		pDC->LineTo(point);
	}
	pDC->SelectObject(old_pen);

}

void CMDIVolnaView::Calculate(int flag, CDC* pDC)
{	
	CMDIVolnaDoc *pDoc = (CMDIVolnaDoc *) GetDocument();	

	pDC->SetMapMode(MM_HIMETRIC);
	pDC->SelectStockObject(WHITE_BRUSH);
	pDC->Rectangle(-10, 10, rect.right + 10, rect.bottom - 10);

	
	//Please check the accessibility of the parameters in support
	if(pDoc->vol.mode == 2)
	{
		if(pDoc->vol.Teta < asin(pDoc->vol.Nc/pDoc->vol.Nf) ||
			pDoc->vol.Teta > asin(pDoc->vol.Ns/pDoc->vol.Nf))
		{
			MessageBox("The options you selected are not\n"
				   "correspond to the case of emitting modes into the substrate.\n"
			 	   "You should either change parameters of the waveguide\n"
				   "or consider another case.");
			return;
		}
	}
	//Both sides
	if(pDoc->vol.mode == 1)
	{
		if(!(pDoc->vol.Teta < asin(pDoc->vol.Nc/pDoc->vol.Nf) ||
			pDoc->vol.Teta > 0) )
		{
			MessageBox("The options you selected are not appropriate for the case\n"
				   "emitting modes into the substrate and cover layer. To you\n"
				   "either change the parameters of the waveguide\n" 
				   "or consider another case.");
			return;
		}
	}
	if(pDoc->vol.h < pDoc->vol.lambda/2.)
	{
		MessageBox("The film thickness should be more than half the wavelength.\n"
			   "Either reduce the wavelength or increase the thickness", "Error");
		return;
	}
	
	switch(flag)
	{
	case VIEW_TE_TM : PaintFc(pDC); PaintFs(pDC);
		break;
	case VIEW_GRAF : Paint_Graf_Define(pDC);
		break;
	case VIEW_TE_TM_1 : PaintFx(pDC);
		break;
	case VIEW_MODE : PaintMode(pDC);
	}
}

void CMDIVolnaView::Paint_Graf_Define(CDC *pDC)
{
	Net(pDC);
	
	CFont* old_font;
	old_font = pDC->SelectObject(cur_font);
	pDC->GetTextMetrics(&tm);

	CMDIVolnaDoc *pDoc = (CMDIVolnaDoc *) GetDocument();
	CPoint point;
	point.y = -500 - int(3.5*tm.tmHeight);
	double d;
	double koef_x = (rect.right - 2500)/(PI/2);
	double koef_y = (rect.bottom + 2900 + 2*tm.tmHeight)/(PI);
	CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	CPen* old_pen = pDC->SelectObject(&pen);
	
	pDC->MoveTo(rect.right - 1000, -2500);
	for(d = PI/2; d >= 0; d -=PI/5000)
	{
		point.x = int(1500. + d*koef_x);
		if(pDoc->vol.FindenFs(d) == OUR_ERROR && pDoc->vol.FindenFc(d) == OUR_ERROR)break;
		if(pDoc->vol.FindenFs(d) == OUR_ERROR )
			point.y = int((double)rect.bottom + 400. + 2*tm.tmHeight - koef_y*pDoc->vol.FindenFc(d));
		else point.y = int((double)rect.bottom + 400. + 2*tm.tmHeight -
			koef_y*pDoc->vol.FindenFs(d) -  koef_y*pDoc->vol.FindenFc(d));
		pDC->LineTo(point);
	}
	pDC->SelectObject(old_pen);

	//Ðèñóåì ïåðâóþ ÷àñòü äèñï. óðàâíåíèÿ

	CPen pen_array[5];
	pen_array[0].CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	pen_array[1].CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	pen_array[2].CreatePen(PS_SOLID, 1, RGB(255, 255, 0));
	pen_array[3].CreatePen(PS_SOLID, 1, RGB(0, 255, 255));
	pen_array[4].CreatePen(PS_SOLID, 1, RGB(255, 0, 255));
	
	//Çäåñü ðèñóþòñÿ ïåðâûå 5 ìîä
	for(int i = 0; i<5; i++)
	{
		pDC->SelectObject(&pen_array[i]);
		pDC->MoveTo(1500,rect.bottom + 400 + 2*tm.tmHeight - 
			int(koef_y*(2*PI/pDoc->vol.lambda*pDoc->vol.Nf*pDoc->vol.h - i*PI)));
		for(d = 0.; d <= PI/2; d +=PI/5000)
		{
			point.x = int(1500. + d*koef_x);
			point.y = rect.bottom + 400 + 2*tm.tmHeight - int(koef_y*
				(
					2*PI/pDoc->vol.lambda*pDoc->vol.Nf*pDoc->vol.h*cos(d)
					- i*PI
				)
			);
			if(point.y > - 2500)
			{
				point.y = - 2500;
				pDC->MoveTo(point);continue;
			}
			if(point.y <= rect.bottom + 400 + 2*tm.tmHeight)break;
			pDC->LineTo(point);
		}
		pen_array[i].DeleteObject();
	}
	
	CPen pen2(PS_SOLID, 70, RGB(0, 0, 255));
	pDC->SelectObject(&pen2);
	pDC->MoveTo(1500,rect.bottom + 400 + 2*tm.tmHeight - 
			int(koef_y*(2*PI/pDoc->vol.lambda*pDoc->vol.Nf*pDoc->vol.h - pDoc->vol.v*PI)));
	
	//Çäåñü ðèñóåòñÿ ìîäà, âûáðàííàÿ by user
	for(d = 0.; d <= PI/2; d +=PI/5000)
	{
		point.x = int(1500. + d*koef_x);
		point.y = rect.bottom + 400 + 2*tm.tmHeight - int(koef_y*
			(
				2*PI/pDoc->vol.lambda*pDoc->vol.Nf*pDoc->vol.h*cos(d)
				- pDoc->vol.v*PI
			)
		);
		if(point.y > - 2500)
		{
			point.y = - 2500;
			pDC->MoveTo(point);continue;
		}
		if(point.y <= rect.bottom + 400 + 2*tm.tmHeight)break;
		pDC->LineTo(point);
	}
	pDC->SelectObject(old_font);
}

void CMDIVolnaView::OnViewGraf() 
{
	// TODO: Add your command handler code here
	flag = VIEW_GRAF;	
	InvalidateRect(NULL);
}

void CMDIVolnaView::OnViewRefresh() 
{

	InvalidateRect(NULL);
}

void CMDIVolnaView::OnViewTeTm() 
{
	// TODO: Add your command handler code here
	flag = VIEW_TE_TM;
	InvalidateRect(NULL);	
}

void CMDIVolnaView::PaintFx(CDC* pDC)
{
	CFont* old_font;
	
	CPen old_pen(PS_SOLID, 1, RGB(0, 0, 0));
	CPen blue_pen(PS_SOLID, 1, RGB(0, 0, 255));
	CPen gray_pen(PS_SOLID, 1, RGB(125, 125, 125));
	CPen red_pen(PS_SOLID, 1, RGB(255, 0, 0));

	CMDIVolnaDoc *pDoc = (CMDIVolnaDoc *) GetDocument();
	pDC->SetMapMode(MM_HIMETRIC);

	CSize shift;
	old_font = pDC->SelectObject(cur_font);
	pDC->GetTextMetrics(&tm);
	pDC->SelectObject(cur_font);
	//Ïîäïèñü ê ãðàôèêó:
	CString title("Dependence of phase shifts at the boundaries on the propagation angle");
	CString type, TE("For TE wave"), TM("For TM wave");
	shift = pDC->GetTextExtent(title);
	pDC->TextOut(rect.right/2 - shift.cx/2,
		- int(tm.tmHeight * 1.), title);
	if(pDoc->vol.type_welle == 1) type = TE;
	else type = TM;
	shift = pDC->GetTextExtent(type);
	pDC->TextOut(rect.right/2 - shift.cx/2,
		- int( tm.tmHeight * 2. ), type);
	
	char str[84];	
	int len = tm.tmAveCharWidth*11;
	//Ðèñóåì íîðìàëüíûå ñèìâîëû
	pDC->TextOut(rect.right/2 - len/2, 
			- int(tm.tmHeight * 3.5), "n", 1 );
	pDC->TextOut(rect.right/2 - len/2 - 500 - len, 
			- int(tm.tmHeight * 3.5), "n", 1 );
	pDC->TextOut(rect.right/2 + len/2 + 500, 
			- int(tm.tmHeight * 3.5), "n", 1 );

	//Ðèñóåì ìàëåíüêèå ñèìâîëû:
	pDC->SelectObject(small_font);
	pDC->SelectObject(small_font);
	pDC->TextOut(rect.right/2 - len/2 + int(tm.tmAveCharWidth*1.3), 
		- int(tm.tmHeight * 4), "c", 1);
	pDC->TextOut(rect.right/2 - len/2 - 500 - len + int(tm.tmAveCharWidth*1.3), 
		- int(tm.tmHeight * 4), "f", 1);
	pDC->TextOut(rect.right/2 + len/2 + 500 + int(tm.tmAveCharWidth*1.3), 
		- int(tm.tmHeight * 4), "s", 1);
	
	pDC->SelectObject(cur_font);
	pDC->SelectObject(cur_font);
	
	//Ïîäïèñûâàåì çíà÷åíèÿ ê ñèìâîëàì Nc, Nf, Nc
	sprintf(str, "= %.4f", pDoc->vol.Nc);
	title = str;
	pDC->TextOut(rect.right/2 - len/2 + 3 * tm.tmAveCharWidth, 
			- int(tm.tmHeight * 3.5), title);
	sprintf(str, "= %.4f", pDoc->vol.Nf);
	title = str;
	pDC->TextOut(rect.right/2 - len/2 - 500 - len + 3 * tm.tmAveCharWidth, 
			- int(tm.tmHeight * 3.5), title);
	sprintf(str, "= %.4f", pDoc->vol.Ns);
	title = str;
	pDC->TextOut(rect.right/2 + len/2 + 500 + 3 * tm.tmAveCharWidth, 
			- int(tm.tmHeight * 3.5), title);

	//Ïîäïèñè ê ñåòêå
	pDC->SelectObject(symb_font);
	pDC->SelectObject(symb_font);
	
	pDC->SetTextColor(RGB(255, 0, 0));
	pDC->TextOut(4000 - tm.tmAveCharWidth*8,
		- 2300, "f", 1);
	pDC->SetTextColor(RGB(0, 0, 255));
	pDC->TextOut(4000 - tm.tmAveCharWidth*3,
		- 2300, "f", 1);
	pDC->SetTextColor(RGB(0, 0, 0));
	pDC->TextOut(rect.right - 4000 + int(tm.tmAveCharWidth*.1),
		rect.bottom + 1600, "q", 1);

	pDC->SelectObject(small_font);
	pDC->SelectObject(small_font);
	pDC->SetTextColor(RGB(255, 0, 0));
	pDC->TextOut(4000 - int(tm.tmAveCharWidth*6),
		- 2300 - int(tm.tmHeight*.9), "c", 1);
	pDC->SetTextColor(RGB(0, 0, 255));
	pDC->TextOut(4000 - int(tm.tmAveCharWidth*1),
		- 2300 - int(tm.tmHeight*.9), "s", 1);
	pDC->SetTextColor(RGB(0, 0, 0));
	pDC->SelectObject(cur_font);
	pDC->SelectObject(cur_font);
	pDC->TextOut(4000 - int(tm.tmAveCharWidth*4.5),
		- 2200 - int(tm.tmHeight*.9), ",", 1);


	pDC->TextOut(4000 - int(pDC->GetTextExtent("0",1).cx*1.2),
		rect.bottom + 1400, "0", 1);
	pDC->TextOut(rect.right  - 4000 + int(pDC->GetTextExtent("90",2).cx*.2),
		-2300, "90", 2);
	pDC->TextOut(4000 +(rect.right - 8000)/9*3 - int(pDC->GetTextExtent("30",2).cx*.5),
		rect.bottom + 1400 , "30");
	pDC->TextOut(4000 +(rect.right - 8000)/9*6 - int(pDC->GetTextExtent("30",2).cx*.5),
		rect.bottom + 1400 , "60");
	pDC->TextOut(rect.right - 4000 + int(pDC->GetTextExtent("30", 2).cx*.2),
		- 2500 + (rect.bottom + 4000)/9*6 + int(pDC->GetTextExtent("30",2).cy*.5), "30");
	pDC->TextOut(rect.right - 4000 + int(pDC->GetTextExtent("60", 2).cx*.2),
		- 2500 + (rect.bottom + 4000)/9*3 + int(pDC->GetTextExtent("60",2).cy*.5), "60");
	
	//Ïîäïèñûâàåì ãðàäóñû
	pDC->SelectObject(small_font);
	pDC->TextOut(4000 - int(pDC->GetTextExtent("0",1).cx*.2),
		rect.bottom + 1400, "0", 1);
	pDC->TextOut(rect.right  - 4000 + int(pDC->GetTextExtent("90",2).cx*1.2),
		-2300, "0", 1);
	pDC->TextOut(4000 +(rect.right - 8000)/9*3 + int(pDC->GetTextExtent("30",2).cx*.5),
		rect.bottom + 1400 , "0", 1);
	pDC->TextOut(4000 +(rect.right - 8000)/9*6 + int(pDC->GetTextExtent("30",2).cx*.5),
		rect.bottom + 1400 , "0", 1);
	pDC->TextOut(rect.right - 4000 + int(pDC->GetTextExtent("30", 2).cx*1.2),
		- 2500 + (rect.bottom + 4000)/9*6 + int(pDC->GetTextExtent("30",2).cy*.5), "0", 1);
	pDC->TextOut(rect.right - 4000 + int(pDC->GetTextExtent("60", 2).cx*1.2),
		- 2500 + (rect.bottom + 4000)/9*3 + int(pDC->GetTextExtent("60",2).cy*.5), "0", 1);
	
	
	//Ðèñóåì ñåòêó äëÿ ãðàôèêà
	pDC->SelectObject(&gray_pen);

	int i;
	pDC->MoveTo(4000, - 2500);
	double koef =((double)rect.right - 8000.)/9.;
	for(i = 0; i<10; i++)
	{	// âåðòèêàëüíûå ëèíèè
		pDC->LineTo(int(4000 + koef*(double)i), rect.bottom + 1500);
		pDC->MoveTo(int(4000 + koef*(double)(i+1)), -2500);
	}
	
	pDC->MoveTo(4000, -2500);
	koef = ((double)rect.bottom + 4000)/9.;
	for(i = 0; i<10; i++)
	{	// ãîðèçîíòàëüíûå ëèíèè
		pDC->LineTo(rect.right - 4000,int(-2500 + koef*(double)i) );
		pDC->MoveTo(4000, int(-2500 + koef*(double)(i+1)) );
	}

	pDC->SelectObject(&old_pen);

	//Ðèñóåì ãðàôèê1:

	pDC->MoveTo(rect.right - 4000, - 2500);
	CPoint point;
	point.y = -2500;
	double d;
	double koef_x = (rect.right - 8000)/(PI/2);
	double koef_y = (rect.bottom + 4000)/(PI/2);
	pDC->SelectObject(&red_pen);
	for(d = PI/2; d >= 0; d -=PI/5000)
	{
		point.x = int(4000. + d*koef_x);
		if(pDoc->vol.FindenFc(d) == OUR_ERROR)break;// point.y = rect.bottom - 50;
		else point.y = int((double)rect.bottom + 1500. - koef_y*pDoc->vol.FindenFc(d));
		pDC->LineTo(point);
	}
	
	//À òåïåðü ãðàôèê 2:
	pDC->MoveTo(rect.right - 4000, - 2500);
	pDC->SelectObject(&blue_pen);
	point.y = -2500;
	for(d = PI/2; d >= 0; d -=PI/5000)
	{
		point.x = int(4000. + d*koef_x);
		if(pDoc->vol.FindenFs(d) == OUR_ERROR)break;// point.y = rect.bottom - 50;
		else point.y = int((double)rect.bottom + 1500. - koef_y*pDoc->vol.FindenFs(d));
		pDC->LineTo(point);
	}
	
	pDC->SelectObject(&old_pen);
	old_pen.DeleteObject();
	red_pen.DeleteObject();
	blue_pen.DeleteObject();
	gray_pen.DeleteObject();

	pDC->SelectObject(old_font);
	pDC->SelectObject(old_font);
}

void CMDIVolnaView::OnViewTeTm1() 
{
	// TODO: Add your command handler code here
	flag = VIEW_TE_TM_1;
	InvalidateRect(NULL);
}

void CMDIVolnaView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	CMDIVolnaDoc* pDoc = (CMDIVolnaDoc*)GetDocument();
	ASSERT_VALID(pDoc);

	static int l = 1;
	if(l)
	{
		l = 0;
		CMenu *sub;
		ClientToScreen (&point);
		menu.LoadMenu(IDR_MENU1);
		sub = menu.GetSubMenu(0);
		if(pDoc->vol.mode)
			sub->EnableMenuItem(ID_VIEW_DIGITAL, MF_GRAYED);
	
		sub->EnableMenuItem(ID_EDIT_3PLANE, MF_CHECKED);
		sub->EnableMenuItem(ID_4PLANE, MF_UNCHECKED);
	
		sub->TrackPopupMenu(0, point.x, point.y, this);
		menu.DestroyMenu();
		l = 1;
	}

	CView::OnRButtonDown(nFlags, point);

/*

	if(pDoc->type_volnovod == 4)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
*/
}

void CMDIVolnaView::OnViewDigital() 
{
	CMDIVolnaDoc *pDoc = (CMDIVolnaDoc *) GetDocument();
	
	char* str = new char[300];
	
		if(pDoc->vol.h < pDoc->vol.lambda/2.)
		{
			MessageBox("The film thickness should be more than half the wavelength.\n"
				   "Either reduce the wavelength or increase the thickness", "Error");
			return;
		}
	
		int type;
		
		if(pDoc->vol.FindenTeta() == ERROR_INTERVAL)
		{
			type = MB_ICONERROR;
			sprintf(str, "Mode %d is not a waveguide type.", pDoc->vol.v);
		}
		else 
		{
			pDoc->vol.calculate_Xi();
			type = MB_ICONINFORMATION;
			sprintf(str, "The propagation angle is  %.2f  (in grades)\n"
						 "The penetration depth is\n"
						 "( the second digit is a percentage of the film thickness ):\n"
						 "into the covering layer:        %.3f (micron)  --   %.2f\n"
						"into the substrate:                   %.3f (micron)  --   %.2f\n"
						"Effective fiber thickness   --  %.3f (micron)",
						pDoc->vol.FindenTeta()*180/PI,
						pDoc->vol.Xc*1e6, (pDoc->vol.Xc/pDoc->vol.h*100),
						pDoc->vol.Xs*1e6, (pDoc->vol.Xs/pDoc->vol.h*100),
						(pDoc->vol.h + pDoc->vol.Xc + pDoc->vol.Xs)*1e6 );
		}
		MessageBox(str, "Numerical solution", type);
	delete []str;
}

void CMDIVolnaView::OnViewMode() 
{
	flag = VIEW_MODE;
	InvalidateRect(NULL);
}

void CMDIVolnaView::PaintMode(CDC* pDC)
{
	CFont* old_font;
	
	CMDIVolnaDoc *pDoc = (CMDIVolnaDoc *) GetDocument();
	pDC->SetMapMode(MM_HIMETRIC);

	old_font = pDC->SelectObject(cur_font);
	pDC->GetTextMetrics(&tm);
	pDC->SelectObject(cur_font);

	Title_big(false, pDC);
	
	CPen* old_pen;
	CPen thick_pen(PS_SOLID, 70, RGB(0, 0, 0));
	old_pen = pDC->SelectObject(&thick_pen);

	pDC->MoveTo(rect.right/4,
		- 2500 + (rect.bottom + 3500)/4);
	pDC->LineTo(3*rect.right/4,
		- 2500 + (rect.bottom + 3500)/4);
	pDC->MoveTo(rect.right/4,
		-2500 + 3*(rect.bottom + 3500)/4);
	pDC->LineTo(3*rect.right/4,
		- 2500 + 3*(rect.bottom + 3500)/4);
	//Ñòðåëêè
	pDC->MoveTo(3*rect.right/4 - 500,
		- 2500 + 3*(rect.bottom + 3500)/4 + 70);
	pDC->LineTo(3*rect.right/4,
		- 2500 + 3*(rect.bottom + 3500)/4);
	pDC->MoveTo(3*rect.right/4 - 500,
		- 2500 + 3*(rect.bottom + 3500)/4 - 70);
	pDC->LineTo(3*rect.right/4,
		- 2500 + 3*(rect.bottom + 3500)/4);
	
	pDC->SelectObject(old_pen);
	pDC->MoveTo(rect.right/2, -2500);
	pDC->LineTo(rect.right/2, rect.bottom + 1000);

	pDC->TextOut(rect.right/2 - int(tm.tmAveCharWidth*1.5),
		- 2570 + 3*(rect.bottom + 3500)/4, "0", 1);
	pDC->SelectObject(cur_font_it);
	pDC->TextOut(rect.right/2 - int(tm.tmAveCharWidth*1.5),
		- 2430 + (rect.bottom + 3500)/4 + tm.tmHeight, "h", 1);
	
	pDC->TextOut(rect.right/2 - int(tm.tmAveCharWidth*4.5),
		rect.bottom + 1000 + tm.tmHeight, "-h/2", 4);
	pDC->TextOut(rect.right/2 - int(tm.tmAveCharWidth*5),
		-2500 , "1.5h", 4);
	//×åðòî÷êè ê h/2 è -h/2
	pDC->MoveTo(rect.right/2 - 100, -2500);
	pDC->LineTo(rect.right/2 + 100, -2500);
	pDC->MoveTo(rect.right/2 - 100, rect.bottom + 1000);
	pDC->LineTo(rect.right/2 + 100, rect.bottom + 1000);
	pDC->MoveTo(rect.right/2  - 100, - 2500 + (rect.bottom + 3500)/2 );
	pDC->LineTo(rect.right/2  + 100, - 2500 + (rect.bottom + 3500)/2 );

	//Íó à òåïåðü ïîïðîáóåì íàðèñîâàòü ñå÷åíèå:
	CPen blue_pen(PS_SOLID, 1, RGB(0, 0, 255));
	pDC->SelectObject(&blue_pen);
	
	double x, y, koef_x, koef_y;
	koef_y = (rect.bottom + 3500)/2./pDoc->vol.h ;
	koef_x = (rect.right/2. - rect.right/4.)/pDoc->vol.Amplitude;
	CPoint p;
	p.x = int(rect.right/2 + koef_x*pDoc->vol.get_mode_amplitude(-pDoc->vol.h/2));
	pDC->MoveTo(p.x, rect.bottom + 1000);
	for(y = -pDoc->vol.h/2; y <= pDoc->vol.h*3/2; y += pDoc->vol.h/300)
	{
		p.y = int(rect.bottom + 1000. - (rect.bottom + 3500)/4. - koef_y*y);
		x = pDoc->vol.get_mode_amplitude(y);
		p.x = int(rect.right/2 + koef_x*x);
		pDC->LineTo(p);
	}
	
	
	
	//×åðòî÷êè äëÿ ÷àéíèêîâ
	p.y = int(rect.bottom + 1000. - (rect.bottom + 3500)/4. - koef_y*pDoc->vol.h + 100);
	x = pDoc->vol.get_mode_amplitude(pDoc->vol.h);
	p.x = int(rect.right/2 + koef_x*x);
	pDC->MoveTo(p);
	p.y = int(rect.bottom + 1000. - (rect.bottom + 3500)/4. - koef_y*pDoc->vol.h - 150);
	p.x = int(rect.right/2 + koef_x*x);
	pDC->LineTo(p);
	pDC->TextOut(p.x , int(p.y + tm.tmHeight*1.5), "Ec", 2);

	p.y = int(rect.bottom + 1000. - (rect.bottom + 3500)/4. + 100);
	x = pDoc->vol.get_mode_amplitude(0);
	p.x = int(rect.right/2 + koef_x*x);
	pDC->MoveTo(p);
	p.y = int(rect.bottom + 1000. - (rect.bottom + 3500)/4. - 150);
	p.x = int(rect.right/2 + koef_x*x);
	pDC->LineTo(p);
	pDC->TextOut(p.x , p.y , "Es", 2);

	//Enter the value for Es, Ec
	pDC->SelectObject(cur_font_it);
	pDC->SelectObject(cur_font_it);
	
	char str[20];
	sprintf(str, "Ec = %.4f", pDoc->vol.get_mode_amplitude(pDoc->vol.h) );
	if(pDoc->vol.get_mode_amplitude(pDoc->vol.h) >= 0.)
		pDC->TextOut(rect.right - 3500 , -2200 + (rect.bottom + 3500)/8, str, 11 );
	else 
		pDC->TextOut(rect.right - 3500 , -2200 + (rect.bottom + 3500)/8, str, 12 );

	sprintf(str, "Ef = %.4f", pDoc->vol.Amplitude );
	pDC->TextOut(rect.right - 3500, -2200 + (rect.bottom + 3500)*4/8, str, 11 );

	sprintf(str, "Es = %.4f", pDoc->vol.get_mode_amplitude(0.) );
	if(pDoc->vol.get_mode_amplitude(0) >= 0.)
		pDC->TextOut(rect.right - 3500, -2200 + (rect.bottom + 3500)*7/8, str, 11 );
	else 
		pDC->TextOut(rect.right - 3500, -2200 + (rect.bottom + 3500)*7/8, str, 12 );
	pDC->TextOut(3000, -2200 + (rect.bottom + 3500)/8, "n", 1);
	pDC->TextOut(3000, -2200 + (rect.bottom + 3500)*4/8, "n", 1);
	pDC->TextOut(3000, -2200 + (rect.bottom + 3500)*7/8, "n", 1);
	
	pDC->SelectObject(small_font);
	pDC->SelectObject(small_font);
	pDC->TextOut(int(3000 + tm.tmAveCharWidth*1.5), -2200 + (rect.bottom + 3500)/8 - tm.tmHeight/2, "c", 1);
	pDC->TextOut(int(3000 + tm.tmAveCharWidth*1.5), -2200 + (rect.bottom + 3500)*4/8 - tm.tmHeight/2, "f", 1);
	pDC->TextOut(int(3000 + tm.tmAveCharWidth*1.5), -2200 + (rect.bottom + 3500)*7/8 - tm.tmHeight/2, "s", 1);

	pDC->SelectObject(old_font);
	pDC->SelectObject(old_font);
	pDC->SelectObject(old_pen);
}

/*********************************************************/
//Drawing a header with full parameters
/*********************************************************/
void CMDIVolnaView::Title_big(bool isPaint_5Mod, CDC* pDC)
{
	CClientDC dc(this);
	CMDIVolnaDoc *pDoc = (CMDIVolnaDoc *) GetDocument();
	CFont* old_font;
	//Çàãîëîâêè
	pDC->SelectObject(cur_font);
	old_font = dc.SelectObject(cur_font);
	dc.GetTextMetrics(&tm);
	CString title;
	if(flag == VIEW_GRAF)
	{
		if(pDoc->vol.type_welle)
		title = "Graphics solution of the dispersion level for EE - wave";
		else title = "Graphics solution of the dispersion level for the UM - wave";
	}
	if(flag == VIEW_MODE)
	{
		if(pDoc->vol.type_welle)
		title = "Mode tip for EM - wave";
		else title = "Mode cross section for TM - waves";
	}
	pDC->TextOut(rect.right/2 - (dc.GetTextExtent(title)).cx/2, -int(tm.tmHeight * 1.), title);

	pDC->SelectObject(small_font);
	dc.SelectObject(small_font);
	title = "The solution for the first five modes is shown. ";
	CString title1 = " The selected mod is shown in blue";
	if(isPaint_5Mod)
	{
		pDC->TextOut(rect.right/2 - (dc.GetTextExtent(title + title1)).cx/2,
			rect.bottom + 200 + tm.tmHeight, title);
		pDC->SetTextColor(RGB(0, 0, 255));
		pDC->TextOut(rect.right/2 -
			(dc.GetTextExtent(title + title1).cx)/2 + dc.GetTextExtent(title).cx,
			rect.bottom + 200 + tm.tmHeight, title1);
		
	}
	else
	{
		pDC->SetTextColor(RGB(0, 0, 255));
		pDC->TextOut(rect.right/2 - (dc.GetTextExtent(title1)).cx/2,
			rect.bottom + 200 + tm.tmHeight, title1);
	}
	pDC->SetTextColor(RGB(0, 0, 0));

	char str[84];	
	int len = tm.tmAveCharWidth*17;
	
	//Ðèñóåì íàêëîíåííûå ñèìâîëû
	pDC->SelectObject(cur_font_it);
	dc.SelectObject(cur_font_it);
	pDC->TextOut(rect.right/2 - len/2, 
			- int(tm.tmHeight * 1.5)- int(tm.tmHeight * 1.), "n", 1 );
	pDC->TextOut(rect.right/2 - len/2 - 500 - len, 
			- int(tm.tmHeight * 1.5) - int(tm.tmHeight * 1.), "n", 1 );
	pDC->TextOut(rect.right/2 + len/2 + 500, 
			- int(tm.tmHeight * 1.5) - int(tm.tmHeight * 1.), "n", 1 );
	pDC->TextOut(rect.right/2 + len/2 + 500, 
			- int(tm.tmHeight * 1.5) - int(tm.tmHeight * 2.5), "h", 1 );
	float p = 4; 
	if(pDoc->vol.lambda >= 10e-6) p = 2.5;
	pDC->TextOut(int(rect.right/2 - len/2 - 500 - p*tm.tmAveCharWidth), 
			- int(tm.tmHeight * 1.5) - int(tm.tmHeight * 2.5), "ìêì", 3 );
	if(pDoc->vol.h >= 10e-6) p = 2.5;
	else p = 4.;
	pDC->TextOut(int(rect.right/2 + len/2 + 500 + len - p*tm.tmAveCharWidth), 
			- int(tm.tmHeight * 1.5) - int(tm.tmHeight * 2.5), "ìêì", 3 );
	
	//À òåïåðü ìàëåíüêèå ðÿäîì ñ íèìè
	pDC->SelectObject(small_font);
	dc.SelectObject(small_font);
	pDC->TextOut(rect.right/2 - len/2 + int(tm.tmAveCharWidth*1.3), 
		- int(tm.tmHeight * 1.5) - int(tm.tmHeight * 1.5), "c", 1);
	pDC->TextOut(rect.right/2 - len/2 - 500 - len + int(tm.tmAveCharWidth*1.3), 
		- int(tm.tmHeight * 1.5) - int(tm.tmHeight * 1.5), "f", 1);
	pDC->TextOut(rect.right/2 + len/2 + 500 + int(tm.tmAveCharWidth*1.3), 
		- int(tm.tmHeight * 1.5) - int(tm.tmHeight * 1.5), "s", 1);
	
	//Ðèñóåì ãðå÷åñêèå áóêâû
	pDC->SelectObject(symb_font);
	dc.SelectObject(symb_font);
	pDC->TextOut(rect.right/2 - len/2, 
			- int(tm.tmHeight * 1.5) - int(tm.tmHeight * 2.2), "n", 1 );
	pDC->TextOut(rect.right/2 - len/2 - 500 - len, 
			- int(tm.tmHeight * 1.5) - int(tm.tmHeight * 2.2), "l", 1 );
	
	//Subscribing values to symbols
	pDC->SelectObject(cur_font);
	dc.SelectObject(cur_font);
	
	sprintf(str, "= %.4f", pDoc->vol.Nc);
	title = str;
	pDC->TextOut(rect.right/2 - len/2 + 3 * tm.tmAveCharWidth, 
			- int(tm.tmHeight * 1.5) - int(tm.tmHeight * 1.), title);
	sprintf(str, "= %.4f", pDoc->vol.Nf);
	title = str;
	pDC->TextOut(rect.right/2 - len/2 - 500 - len + 3 * tm.tmAveCharWidth, 
			- int(tm.tmHeight * 1.5) - int(tm.tmHeight * 1.), title);
	sprintf(str, "= %.4f", pDoc->vol.Ns);
	title = str;
	pDC->TextOut(rect.right/2 + len/2 + 500 + 3 * tm.tmAveCharWidth, 
			- int(tm.tmHeight * 1.5) - int(tm.tmHeight * 1.), title);

	sprintf(str, "= %d", pDoc->vol.v);
	title = str;
	pDC->TextOut(rect.right/2 - len/2 + 3 * tm.tmAveCharWidth, 
			- int(tm.tmHeight * 1.5) - int(tm.tmHeight * 2.5), title);
	sprintf(str, "= %.4f", pDoc->vol.lambda*1e6);
	title = str;
	pDC->TextOut(rect.right/2 - len/2 - 500 - len + 3 * tm.tmAveCharWidth, 
			- int(tm.tmHeight * 1.5) - int(tm.tmHeight * 2.5), title);
	sprintf(str, "= %.4f", pDoc->vol.h*1e6);
	title = str;
	pDC->TextOut(rect.right/2 + len/2 + 500 + 3 * tm.tmAveCharWidth, 
			- int(tm.tmHeight * 1.5) - int(tm.tmHeight * 2.5), title);

	pDC->SelectObject(old_font);
	dc.SelectObject(old_font);
}

void CMDIVolnaView::OnUpdateViewDigital(CCmdUI* pCmdUI) 
{

	CMDIVolnaDoc* pDoc = (CMDIVolnaDoc* )GetDocument();
	ASSERT_VALID(pDoc);
	if(pDoc->vol.mode)
		pCmdUI->Enable(false);
	
	else pCmdUI->Enable(true);

}

void CMDIVolnaView::OnUpdateEdit3plane(CCmdUI* pCmdUI) 
{

	CMDIVolnaDoc* pDoc = (CMDIVolnaDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	pCmdUI->SetCheck(true);
}

void CMDIVolnaView::OnUpdate4plane(CCmdUI* pCmdUI) 
{
	
	CMDIVolnaDoc* pDoc = (CMDIVolnaDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	pCmdUI->SetCheck(true);
}

void CMDIVolnaView::OnEdit3plane() 
{

	CMDIVolnaDoc* pDoc = (CMDIVolnaDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	InvalidateRect(NULL);

}


void CMDIVolnaView::OnUpdateViewGraf(CCmdUI* pCmdUI) 
{
	CMDIVolnaDoc* pDoc = (CMDIVolnaDoc*)GetDocument();
	ASSERT_VALID(pDoc);
}

void CMDIVolnaView::OnUpdateViewMode(CCmdUI* pCmdUI) 
{

	CMDIVolnaDoc* pDoc = (CMDIVolnaDoc*)GetDocument();
	ASSERT_VALID(pDoc);
}

void CMDIVolnaView::OnUpdateViewTeTm(CCmdUI* pCmdUI) 
{

	CMDIVolnaDoc* pDoc = (CMDIVolnaDoc*)GetDocument();
	ASSERT_VALID(pDoc);
}

void CMDIVolnaView::OnUpdateViewTeTm1(CCmdUI* pCmdUI) 
{

	CMDIVolnaDoc* pDoc = (CMDIVolnaDoc*)GetDocument();
	ASSERT_VALID(pDoc);
}

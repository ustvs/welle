// MDIVolnaDoc.cpp : implementation of the CMDIVolnaDoc class
//

#include "stdafx.h"
#include "MDIVolna.h"

#include "MDIVolnaDoc.h"
#include "DlgSetupVolnovod.h"
#include "DlgSetupIzlu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMDIVolnaDoc

IMPLEMENT_DYNCREATE(CMDIVolnaDoc, CDocument)

BEGIN_MESSAGE_MAP(CMDIVolnaDoc, CDocument)
	//{{AFX_MSG_MAP(CMDIVolnaDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMDIVolnaDoc construction/destruction

CMDIVolnaDoc::CMDIVolnaDoc()
{
	// TODO: add one-time construction code here
}

CMDIVolnaDoc::~CMDIVolnaDoc()
{
}

BOOL CMDIVolnaDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument()) return FALSE;

	vol.mode = 0;
	isNew = true;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMDIVolnaDoc serialization

void CMDIVolnaDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// Запись данных
			ar << vol.h << vol.lambda << vol.Nc << vol.Nf << vol.Ns << vol.Teta << vol.v;
			ar << vol.type_welle << vol.Amplitude << vol.mode;

	}
	else
	{
		// Чтение данных
			ar >> vol.h >> vol.lambda >> vol.Nc >> vol.Nf>> vol.Ns >> vol.Teta >> vol.v;
			ar >> vol.type_welle >> vol.Amplitude >> vol.mode;
		
			isNew = true;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMDIVolnaDoc diagnostics

#ifdef _DEBUG
void CMDIVolnaDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMDIVolnaDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMDIVolnaDoc commands

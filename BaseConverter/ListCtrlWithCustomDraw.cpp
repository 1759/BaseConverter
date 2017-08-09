// ListCtrlWithCustomDraw.cpp : implementation file
//

#include "stdafx.h"
#include "BaseConverter.h"
#include "ListCtrlWithCustomDraw.h"
#include "BaseConverterDlg.h"

// CListCtrlWithCustomDraw

IMPLEMENT_DYNAMIC(CListCtrlWithCustomDraw, CListCtrl)

CListCtrlWithCustomDraw::CListCtrlWithCustomDraw()
{

}

CListCtrlWithCustomDraw::~CListCtrlWithCustomDraw()
{
}


BEGIN_MESSAGE_MAP(CListCtrlWithCustomDraw, CListCtrl)
	ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, &CListCtrlWithCustomDraw::OnNMCustomdraw)
END_MESSAGE_MAP()



// CListCtrlWithCustomDraw message handlers




void CListCtrlWithCustomDraw::OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLVCUSTOMDRAW lpLVCustomDraw = reinterpret_cast<LPNMLVCUSTOMDRAW>(pNMHDR);

	*pResult = 0;
	*pResult |= CDRF_NOTIFYPOSTPAINT;
	*pResult |= CDRF_NOTIFYITEMDRAW;
	*pResult |= CDRF_NOTIFYSUBITEMDRAW;


	
}


void CListCtrlWithCustomDraw::PreSubclassWindow()
{	
	CListCtrlWithCustomDraw();
	CHeaderCtrl* pHeader = NULL;
	pHeader = GetHeaderCtrl();

	if (pHeader != NULL)
	{
		VERIFY(m_MyHeader.SubclassWindow(pHeader->m_hWnd));
	}
	
	CListCtrl::PreSubclassWindow();
}	
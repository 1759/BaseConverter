// MyHeader.cpp : implementation file
//

#include "stdafx.h"
#include "BaseConverter.h"
#include "MyHeader.h"


// MyHeader

IMPLEMENT_DYNAMIC(MyHeader, CHeaderCtrl)

MyHeader::MyHeader()
{

}

MyHeader::~MyHeader()
{
}


BEGIN_MESSAGE_MAP(MyHeader, CHeaderCtrl)
	ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, &MyHeader::OnNMCustomdraw)
END_MESSAGE_MAP()



// MyHeader message handlers

void MyHeader::OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	LPNMLVCUSTOMDRAW lplvcd = (LPNMLVCUSTOMDRAW)pNMHDR;

	NMLVCUSTOMDRAW *pCD = (NMLVCUSTOMDRAW*)pNMHDR;

	*pResult = CDRF_DODEFAULT;	

	if (pNMCD->dwDrawStage == CDDS_PREPAINT)
	{
		*pResult = CDRF_NOTIFYITEMDRAW;
	}
	else if (pNMCD->dwDrawStage == CDDS_ITEMPREPAINT)
	{
		SelectObject(lplvcd->nmcd.hdc, CreateFont(16, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
			CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, VARIABLE_PITCH, TEXT("Courier New")));

		lplvcd->clrText = RGB(255, 0, 0);
		lplvcd->clrTextBk = RGB(210, 245, 245);
		*pResult = CDRF_NOTIFYSUBITEMDRAW;
	}

	else if (pNMCD->dwDrawStage == CDDS_SUBITEM | CDDS_ITEMPREPAINT) {
		lplvcd->clrText = RGB(0, 255, 0);
		lplvcd->clrTextBk = RGB(210, 245, 245);
		*pResult = CDRF_NEWFONT;

	}
	
}

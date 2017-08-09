// MyEditCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "BaseConverter.h"
#include "MyEditCtrl.h"


// MyEditCtrl

IMPLEMENT_DYNAMIC(MyEditCtrl, CEdit)

MyEditCtrl::MyEditCtrl()
{

}

MyEditCtrl::~MyEditCtrl()
{
}


BEGIN_MESSAGE_MAP(MyEditCtrl, CEdit)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()



// MyEditCtrl message handlers

HBRUSH MyEditCtrl::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CEdit::OnCtlColor(pDC, pWnd, nCtlColor);

	
	return hbr;
}

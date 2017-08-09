#pragma once

#include "MyHeader.h"
// CListCtrlWithCustomDraw

class CListCtrlWithCustomDraw : public CListCtrl
{
	DECLARE_DYNAMIC(CListCtrlWithCustomDraw)

public:
	CListCtrlWithCustomDraw();
	virtual ~CListCtrlWithCustomDraw();

protected:
	DECLARE_MESSAGE_MAP()
	MyHeader m_MyHeader;

public:
	afx_msg void OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult);
	void PreSubclassWindow();
};



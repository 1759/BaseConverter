#pragma once


// MyEditCtrl

class MyEditCtrl : public CEdit
{
	DECLARE_DYNAMIC(MyEditCtrl)

public:
	MyEditCtrl();
	virtual ~MyEditCtrl();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	bool ChangeColor = TRUE;

};



#pragma once


// MyHeader

class MyHeader : public CHeaderCtrl
{
	DECLARE_DYNAMIC(MyHeader)

public:
	MyHeader();
	virtual ~MyHeader();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult);
};



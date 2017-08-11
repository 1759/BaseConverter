
// BaseConverterDlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "ListCtrlWithCustomDraw.h"


// CBaseConverterDlg dialog
class CBaseConverterDlg : public CDialogEx
{
// Construction
public:
	CBaseConverterDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BASECONVERTER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	CListCtrlWithCustomDraw GetList();

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrlWithCustomDraw m_listCtrl;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit3();
	CButton insertItem;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit2();
	CEdit dez_input;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	void OnOK();

	CString DezAppendDots(CString);

	CString editorText=NULL;

	CString CleanSpaces(CString no);

	CString CleanBadCharcaters(CString no);

	CString CutDezAtFirstSpecialChar(CString no);

	CString HexToHex(CString no);
	CString HexToDezUnsigned(CString no);
	CString HexToDezSigned(CString no);
	CString HexToBin(CString no);
	CString DezToHex(CString no);

	CString DezToDezUnsigned(CString no);

	CString DezToDezSigned(CString no);

	CString DezToBin(CString no);

	CString BinToHex(CString no);

	CString BinToDezUnsigned(CString no);

	CString BinToDezSigned(CString no);

	CString BinToBin(CString no);


	CEdit hex_input;
	CEdit bin_input;
};

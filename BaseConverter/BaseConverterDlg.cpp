
// BaseConverterDlg.cpp : implementation file
//


#include "stdafx.h"
#include "BaseConverter.h"
#include "BaseConverterDlg.h"
#include "afxdialogex.h"
#include "ListCtrlWithCustomDraw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include<string>
#include <bitset>
#include<stdlib.h>
#include<wchar.h>
#include <sstream>


using namespace std;
// CBaseConverterDlg dialog

CBaseConverterDlg::CBaseConverterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_BASECONVERTER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBaseConverterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listCtrl);
	DDX_Control(pDX, IDC_BUTTON1, insertItem);
	DDX_Control(pDX, IDC_EDIT2, dez_input);
	DDX_Control(pDX, IDC_EDIT1, hex_input);
	DDX_Control(pDX, IDC_EDIT3, bin_input);
}

BEGIN_MESSAGE_MAP(CBaseConverterDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CBaseConverterDlg::OnLvnItemchangedList1)
	ON_EN_CHANGE(IDC_EDIT1, &CBaseConverterDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT3, &CBaseConverterDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON1, &CBaseConverterDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT2, &CBaseConverterDlg::OnEnChangeEdit2)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CBaseConverterDlg message handlers

BOOL CBaseConverterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GotoDlgCtrl(GetDlgItem(IDC_EDIT1));

	//list control
	m_listCtrl.InsertColumn(0, _T("Bin"), LVCFMT_CENTER, 355);
	m_listCtrl.InsertColumn(0, _T("Dez(signed)"), LVCFMT_CENTER, 160);
	m_listCtrl.InsertColumn(0, _T("Dez(unsigned)"), LVCFMT_CENTER, 150);
	m_listCtrl.InsertColumn(0, _T("Hex"), LVCFMT_LEFT, 100);



	HWND header = ListView_GetHeader(m_listCtrl);
	DWORD dwHeaderStyle = ::GetWindowLong(header, GWL_STYLE);
	dwHeaderStyle |= HDS_BUTTONS;
	::SetWindowLong(header, GWL_STYLE, dwHeaderStyle);

	HDITEM hdi = { 0 };
	hdi.mask = HDI_FORMAT;
	Header_GetItem(header, 0, &hdi);
	hdi.fmt |= HDF_LEFT;
	Header_SetItem(header, 0, &hdi);

	HDITEM hdi1 = { 1 };
	hdi1.mask = HDI_FORMAT;
	Header_GetItem(header, 1, &hdi1);
	hdi1.fmt |= HDF_CENTER;
	Header_SetItem(header, 1, &hdi1);

	HDITEM hdi2 = { 1 };
	hdi2.mask = HDI_FORMAT;
	Header_GetItem(header, 2, &hdi2);
	hdi2.fmt |= HDF_CENTER;
	Header_SetItem(header, 2, &hdi2);

	HDITEM hdi3 = { 1 };
	hdi3.mask = HDI_FORMAT;
	Header_GetItem(header, 3, &hdi3);
	hdi3.fmt |= HDF_CENTER;
	Header_SetItem(header, 3, &hdi3);

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	return FALSE;
}

void CBaseConverterDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}
HCURSOR CBaseConverterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBaseConverterDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}

void CBaseConverterDlg::OnEnChangeEdit1()
{
}

void CBaseConverterDlg::OnEnChangeEdit3()
{}

void CBaseConverterDlg::OnBnClickedButton1()
{
	int listLength = m_listCtrl.GetItemCount();
	for (int nItem = 0; nItem < listLength; nItem++)
	{
		m_listCtrl.DeleteItem(0);
	}
}


void CBaseConverterDlg::OnEnChangeEdit2()
{}

HBRUSH CBaseConverterDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	HBRUSH m_brBack = CreateSolidBrush(RGB(255, 255, 255));

	if (pWnd->GetDlgCtrlID() == IDC_EDIT1)
	{
		pDC->SetBkColor(RGB(194, 194, 214));
		hbr = m_brBack;
		hex_input.GetWindowText(editorText);

	}
	else if (pWnd->GetDlgCtrlID() == IDC_EDIT2)
	{
		pDC->SetBkColor(RGB(194, 194, 214));
		hbr = m_brBack;
		dez_input.GetWindowText(editorText);
	}
	else if (pWnd->GetDlgCtrlID() == IDC_EDIT3)
	{
		pDC->SetBkColor(RGB(194, 194, 214));
		hbr = m_brBack;
		bin_input.GetWindowText(editorText);

	}
		return hbr; 
}


void CBaseConverterDlg::OnOK()
{
	CWnd* pwndCtrl = GetFocus();
	CWnd* pwndCtrlNext = pwndCtrl;
	int ctrl_ID = pwndCtrl->GetDlgCtrlID();

	switch (ctrl_ID) {
	case IDC_EDIT1: {
		int nIndex = m_listCtrl.InsertItem(0, HexToHex(editorText));
		m_listCtrl.SetItemText(nIndex, 1, DezAppendDots(HexToDezUnsigned(editorText)));
		m_listCtrl.SetItemText(nIndex, 2, DezAppendDots(HexToDezSigned(editorText)));
		m_listCtrl.SetItemText(nIndex, 3, HexToBin(editorText));
		hex_input.SetWindowTextW(_T(""));
		break;
	}

	case IDC_EDIT2: {
		int nIndex = m_listCtrl.InsertItem(0, DezToHex(editorText));
		m_listCtrl.SetItemText(nIndex, 1, DezAppendDots(DezToDezUnsigned(editorText)));
		m_listCtrl.SetItemText(nIndex, 2, DezAppendDots(DezToDezSigned(editorText)));
		m_listCtrl.SetItemText(nIndex, 3, DezToBin(editorText));
		dez_input.SetWindowTextW(_T(""));
		break;
	}

	case IDC_EDIT3: {
		int nIndex = m_listCtrl.InsertItem(0, BinToHex(editorText));
		m_listCtrl.SetItemText(nIndex, 1, DezAppendDots(BinToDezUnsigned(editorText)));
		m_listCtrl.SetItemText(nIndex, 2, DezAppendDots(BinToDezSigned(editorText)));
		m_listCtrl.SetItemText(nIndex, 3, BinToBin(editorText));
		bin_input.SetWindowTextW(_T(""));

		break;
	}
	case IDOK:
		CDialog::OnOK();
		break;
	default:
		break;
	}
	pwndCtrlNext->SetFocus();
}




CString CBaseConverterDlg::DezAppendDots(CString no){
	no.MakeReverse();
	for (int i = 1; i<no.GetLength()/3; i++)
		no.Insert(i * 3 + i-1, _T(","));
	return no.MakeReverse();

}

CString CBaseConverterDlg::CleanSpaces(CString no) {
	CString aux = NULL;
	for (int i = 0; i< no.GetLength(); i++)
		if (no.GetAt(i) != ' ') {
			aux += no.GetAt(i);
		}
	return aux;
}

CString CBaseConverterDlg::CleanBadCharcaters(CString no) {
	CString aux = NULL;
	int i = 0;
	for (; i < no.GetLength(); i++)
		if (!(no.GetAt(i) <= '9' && no.GetAt(i) >= '0') || !(no.GetAt(i) <= 'z' && no.GetAt(i) >= 'a') || !(no.GetAt(i) <= 'Z' && no.GetAt(i) >= 'A')) {
			break;
		}
		else
			aux += no.GetAt(i);
	return aux;
}

CString CBaseConverterDlg::HexToHex(CString no) {
	CString s = NULL;
	no = CleanSpaces(no);
	no.MakeReverse();
	if (no.GetLength() < 8) {
		for (int i = no.GetLength(); i < 8; i++)
			no += _T("0");
	}
	no.MakeReverse();

	int i = no.GetLength()-1;
	for (int j = 0;  j < 8 && i>=0 ;i--) {
		if (j == 4)
			s += " ";
		if ((no.GetAt(i) >= 'a' && no.GetAt(i) <= 'f') || (no.GetAt(i) >= 'A' && no.GetAt(i) <= 'F') || (no.GetAt(i) <= '9' && no.GetAt(i) >= '0') ) {
			s += no.GetAt(i);
			j++;
		}
		else
			return _T("FFFF FFFF");
	}
	return s.MakeUpper().MakeReverse();
}

CString CBaseConverterDlg::HexToDezUnsigned(CString no) {
	no = HexToHex(no);
	no = CleanSpaces(no);
	int i = no.GetLength() - 1;
	for (int j = 0; j < 8 && i >= 0; i--)
		if (!((no.GetAt(i) >= 'a' && no.GetAt(i) <= 'f') || (no.GetAt(i) >= 'A' && no.GetAt(i) <= 'F') || (no.GetAt(i) <= '9' && no.GetAt(i) >= '0')))
			return HexToDezUnsigned(_T("FFFF FFFF"));
	CT2CA pszConvertedAnsiString(no);
	std::string s(pszConvertedAnsiString);
	unsigned x;
	std::stringstream ss;
	ss << std::hex << s;
	ss >> x;
	int y = static_cast<int>(x);
	no.Format(_T("%u"), y);
	return no;
}

CString CBaseConverterDlg::HexToDezSigned(CString no) {
	no = HexToHex(no);
	no = CleanSpaces(no);
	int i = no.GetLength() - 1;
	for (int j = 0; j < 8 && i >= 0; i--)
		if (!((no.GetAt(i) >= 'a' && no.GetAt(i) <= 'f') || (no.GetAt(i) >= 'A' && no.GetAt(i) <= 'F') || (no.GetAt(i) <= '9' && no.GetAt(i) >= '0')))
			return HexToDezSigned(_T("FFFF FFFF"));
	CT2CA pszConvertedAnsiString(no);
	std::string s(pszConvertedAnsiString);

	unsigned x;
	std::stringstream ss;
	ss << std::hex << s;
	ss >> x;
	no.Format(_T("%ld"), x);
	return no;
}

const char* hex_char_to_bin(char c)
{
	// TODO handle default / error
	switch (toupper(c))
	{
	case '0': return "0000";
	case '1': return "0001";
	case '2': return "0010";
	case '3': return "0011";
	case '4': return "0100";
	case '5': return "0101";
	case '6': return "0110";
	case '7': return "0111";
	case '8': return "1000";
	case '9': return "1001";
	case 'A': return "1010";
	case 'B': return "1011";
	case 'C': return "1100";
	case 'D': return "1101";
	case 'E': return "1110";
	case 'F': return "1111";
	}
}

CString CBaseConverterDlg::HexToBin(CString no) {
	CString s = NULL;
	no = CleanSpaces(no);
	int i = 0;
	for (int j = 0; j < 8 && i < no.GetLength(); i++) {
		if (!((no.GetAt(i) >= 'a' && no.GetAt(i) <= 'f') || (no.GetAt(i) >= 'A' && no.GetAt(i) <= 'F') || (no.GetAt(i) <= '9' && no.GetAt(i) >= '0')))
			return HexToBin(_T("FFFF FFFF"));
		else
		{
			s += hex_char_to_bin(no.GetAt(i));
			j++;
		}
	}


	s.MakeReverse();
	for (int i = s.GetLength()+1; i <= 32; i++) {
		s += _T("0");
	}
	s.MakeReverse();
	for(int i=1;i<8;i++)
		s.Insert(i*4+i-1,_T( " "));
	return s;
}

CString CBaseConverterDlg::DezToHex(CString no) {
	CString aux = NULL;
	for (int i = 0; i < no.GetLength(); i++)
	{
		if (no.GetAt(i) == '-') {
			no = DezToDezUnsigned(no);
			
		}
		else
			if (!(no.GetAt(i) <= '9' && no.GetAt(i) >= '0'))
				return HexToHex(_T("FFFF FFFF"));;
	}
	wchar_t *end = NULL;
	uint64_t value = _wcstoui64(no, &end, 10);
	std::stringstream ss;
	ss << std::hex << value;
	ss >> value;
	no.Format(_T("%lx"), value);
	no.MakeReverse();
	if (no.GetLength() < 8) {
		for (int i = no.GetLength(); i < 8; i++)
			no += _T("0");
	}
	no.Insert(4, ' ');

	no.MakeReverse().MakeUpper();
	return no;
}

CString CBaseConverterDlg::DezToDezUnsigned(CString no) {
	//get the first part before a 

	wchar_t *end = NULL;
	uint64_t value = _wcstoui64(no, &end, 10);

	std::stringstream ss;
	ss << std::hex << value;
	ss >> value;
	no.Format(_T("%lu"), value);

	for (int i = 0; i < no.GetLength(); i++) {
		if (no.GetAt(i) == '-') {
			value = 4294967296 -  value;
			no.Format(_T("%lu"), value);
		}

		else if (!(no.GetAt(i) <= '9' && no.GetAt(i) >= '0'))
			return _T("0");
	}		
	

	/*
	if (value > 4294967295 && value <= 8589934591) {
		value -= 4294967296;
		CString decStr;
		decStr.Format(L"%llu", value);
		return decStr;
	}
	else if (value > 8589934591 ) {
		value -= 8589934592;
		CString decStr;
		decStr.Format(L"%llu", value);
		return decStr;
	}
	//12884901888

	*/
	return no;
}

CString CBaseConverterDlg::DezToDezSigned(CString no) {
	bool neg= false;
	for (int i = 0; i < no.GetLength(); i++) {
		 if (!(no.GetAt(i) <= '9' && no.GetAt(i) >= '0') && no.GetAt(i)!= '-')
			return _T("0");
	}
	wchar_t *end = NULL;
	uint64_t value = _wcstoui64(no, &end, 10);

	std::stringstream ss;
	ss << std::hex << value;
	ss >> value;
	no.Format(_T("%ld"), value);

	return no;
}

CString CBaseConverterDlg::DezToBin(CString no) {
	for (int i = 0; i < no.GetLength(); i++) {

		if (no.GetAt(i) == '-') {
			no = DezToDezUnsigned(no);
			no = DezToHex(no);
			no = HexToBin(no);
			return no;
			//oricum trebuiaa sa trunchiez la al doilea minus sa ignor ce e dupa d

		}
		else	if (!(no.GetAt(i) <= '9' && no.GetAt(i) >= '0'))
			return _T("0000 0000 0000 0000 0000 0000 0000 0000");
	}
	wchar_t *end = NULL;
	uint64_t value = _wcstoui64(no, &end, 10);

	std::stringstream ss;
	ss << std::hex << value;
	ss >> value;
	no.Format(_T("%lx"), value);
	CString s = NULL;;
	for (int i=0;i< no.GetLength();i++)
	{
		s += hex_char_to_bin(no.GetAt(i));
	}

	s.MakeReverse();
	for (int i = s.GetLength(); i <= 32; i++) {
		s += _T("0");
	}
	s.MakeReverse();
	for (int i = 1; i<8; i++)
		s.Insert(i * 4 + i -1 , _T(" "));
	return s;
}

CString CBaseConverterDlg::BinToHex(CString no) {
	no = BinToBin(no);
	no = CleanSpaces(no);

	CString rest("");
	CString tmp, chr("0000");
	int len = no.GetLength() / 4;
	chr = chr.Mid(0, len);
	for (int i = 0; i<no.GetLength(); i += 4)
	{
		tmp = no.Mid(i, 4);
		if (!tmp.Compare(_T("0000")))
		{
			rest +=  "0";
		}
		else if (!tmp.Compare(_T("0001")))
		{
			rest += "1";
		}
		else if (!tmp.Compare(_T("0010")))
		{
			rest += "2";
		}
		else if (!tmp.Compare(_T("0011")))
		{
			rest += "3";
		}
		else if (!tmp.Compare(_T("0100")))
		{
			rest += "4";
		}
		else if (!tmp.Compare(_T("0101")))
		{
			rest += "5";
		}
		else if (!tmp.Compare(_T("0110")))
		{
			rest += "6";
		}
		else if (!tmp.Compare(_T("0111")))
		{
			rest += "7";
		}
		else if (!tmp.Compare(_T("1000")))
		{
			rest += "8";
		}
		else if (!tmp.Compare(_T("1001")))
		{
			rest += "9";
		}
		else if (!tmp.Compare(_T("1010")))
		{
			rest += "A";
		}
		else if (!tmp.Compare(_T("1011")))
		{
			rest += "B";
		}
		else if (!tmp.Compare(_T("1100")))
		{
			rest += "C";
		}
		else if (!tmp.Compare(_T("1101")))
		{
			rest += "D";
		}
		else if (!tmp.Compare(_T("1110")))
		{
			rest += "E";
		}
		else if (!tmp.Compare(_T("1111")))
		{
			rest += "F";
		}
		else
		{
			continue;
		}
	}

	return rest;
}

CString CBaseConverterDlg::BinToDezUnsigned(CString no) {
	no = BinToHex(no);
	no = CleanSpaces(no);
	no = HexToDezUnsigned(no);

	return no;
}

CString CBaseConverterDlg::BinToDezSigned(CString no) {
	no = BinToHex(no);
	no = CleanSpaces(no);
	no = HexToDezSigned(no);

	return no;
}

CString CBaseConverterDlg::BinToBin(CString no) {
	CString s = NULL;
	for (int i = 0; i < no.GetLength(); i++)
	{
		if (no.GetAt(i) != '0' && no.GetAt(i) != '1') {
			return _T("0000 0000 0000 0000 0000 0000 0000 0000");
		}
	}
	if (no.GetLength() < 32) {
		no.MakeReverse();
		for (int j = no.GetLength(); j < 32; j++) {
			no += _T("0");
		}
		no.MakeReverse();
	}
		int i = no.GetLength() - 1;
		for (int j = 0; j < 32 && i >= 0; i--) {
			s += no.GetAt(i);
			j++;
			if (j % 4 == 0 && j != 0)
				s += " ";
		}
		return s.MakeReverse();
}


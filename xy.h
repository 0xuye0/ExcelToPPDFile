#pragma once

// xy �Ի���
#include "CExcel.h"


class xy : public CDialog
{
	DECLARE_DYNAMIC(xy)
public:
	xy(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~xy();
	CExcel a;
	int IfIsXls;
	
// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CString m_a;
};

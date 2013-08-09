#pragma once

// xy 对话框
#include "CExcel.h"


class xy : public CDialog
{
	DECLARE_DYNAMIC(xy)
public:
	xy(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~xy();
	CExcel a;
	int IfIsXls;
	
// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CString m_a;
};

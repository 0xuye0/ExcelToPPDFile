// ppd08office03.h : ppd08office03 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������
#include "xy.h"


// Cppd08office03App:
// �йش����ʵ�֣������ ppd08office03.cpp
//

class Cppd08office03App : public CWinApp
{
public:
	Cppd08office03App();
	xy m_mainDlg;

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cppd08office03App theApp;
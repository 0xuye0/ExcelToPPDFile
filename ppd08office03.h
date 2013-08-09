// ppd08office03.h : ppd08office03 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号
#include "xy.h"


// Cppd08office03App:
// 有关此类的实现，请参阅 ppd08office03.cpp
//

class Cppd08office03App : public CWinApp
{
public:
	Cppd08office03App();
	xy m_mainDlg;

// 重写
public:
	virtual BOOL InitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cppd08office03App theApp;
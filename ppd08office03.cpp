// ppd08office03.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "ppd08office03.h"
#include "MainFrm.h"

#include "ppd08office03Doc.h"
#include "ppd08office03View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cppd08office03App

BEGIN_MESSAGE_MAP(Cppd08office03App, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &Cppd08office03App::OnAppAbout)
	// 基于文件的标准文档命令
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// 标准打印设置命令
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()


// Cppd08office03App 构造

Cppd08office03App::Cppd08office03App()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 Cppd08office03App 对象

Cppd08office03App theApp;


// Cppd08office03App 初始化

BOOL Cppd08office03App::InitInstance()
{
	m_mainDlg.DoModal();
	return TRUE;
}



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// 用于运行对话框的应用程序命令
void Cppd08office03App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// Cppd08office03App 消息处理程序


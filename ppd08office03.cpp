// ppd08office03.cpp : ����Ӧ�ó��������Ϊ��
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
	// �����ļ��ı�׼�ĵ�����
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// ��׼��ӡ��������
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()


// Cppd08office03App ����

Cppd08office03App::Cppd08office03App()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� Cppd08office03App ����

Cppd08office03App theApp;


// Cppd08office03App ��ʼ��

BOOL Cppd08office03App::InitInstance()
{
	m_mainDlg.DoModal();
	return TRUE;
}



// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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

// �������жԻ����Ӧ�ó�������
void Cppd08office03App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// Cppd08office03App ��Ϣ�������


// xy.cpp : 实现文件
//
#include "stdafx.h"
#include "ppd08office03.h"
#include "xy.h"
#include <string>
#include "CExcel.h"
#include "CommandFactory.h"
#include "BuildCommands.h"

// xy 对话框

IMPLEMENT_DYNAMIC(xy, CDialog)

xy::xy(CWnd* pParent /*=NULL*/)
	: CDialog(xy::IDD, pParent)
	, m_a(_T(""))
{

}

xy::~xy()
{
}

void xy::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_a);
}


BEGIN_MESSAGE_MAP(xy, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &xy::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &xy::OnBnClickedButton2)
END_MESSAGE_MAP()


// xy 消息处理程序

void xy::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码


    CFileDialog dlg(TRUE, NULL, NULL, 0, L"xls 文件 (*.xls)|*.xls|所有文件 (*.*)|*.*||");
	if (dlg.DoModal() == IDOK)
	{
		IfIsXls = 1;
		m_a = dlg.GetPathName();
		this->UpdateData ( false );
	}
	else
	{
		m_a = "";
		IfIsXls=0;
		this->UpdateData ( false );
	}
}

void xy::OnBnClickedButton2()
{
	 //TODO: 在此添加控件通知处理程序代码

	while ( m_a.Right( 4 )!= ".xls" && IfIsXls==1 )
	{
		AfxMessageBox(L"    无法处理的格式\n请重新选择正确的文件");
		OnBnClickedButton1 ();
	}
    a.Attach( m_a );
	CString bbb = L"Base";
	CString str,str1;
	a.ReadSheet(bbb);
	int i = 0; 
	do
	{
		i++;
		str = a.GetValue(i,1);
		str1 = a.GetValue(i,1);		
	}while( str1.MakeUpper() != L"BEGIN" );
	int ii=i;
	
	for( int j=21;j<24;j++ )
	{
		str1 = L"begin";
		str = L"begin";
		i = ii;
		while(str1.MakeUpper() != L"END")
		{
			CString YON=a.GetValue(i,j);
			if( YON != "" )//判断该设备是否需要执行当前函数
			{
				
				str = a.GetValue(i,2);
				str1 = a.GetValue(i,2);
				CCommandFactory d;
				CBuildCommands *dd = d.CommandConvert( str1 );
				dd->excute(a,i,j);
			}
			++i;
			str = a.GetValue(i,1);
			str1 = a.GetValue(i,1);
		}
		//a.map1.clear();
	}

    a.books.Close();   
    a.app.Quit();             // 退出  
    //释放对象    
    a.range.ReleaseDispatch();  
    a.sheet.ReleaseDispatch();  
    a.sheets.ReleaseDispatch();  
    a.book.ReleaseDispatch();  
    a.books.ReleaseDispatch();  
    a.app.ReleaseDispatch();  
    OnOK();  
    MessageBox(str);  
}
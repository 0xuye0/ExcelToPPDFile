// ppd08office03Doc.cpp : Cppd08office03Doc 类的实现
//

#include "stdafx.h"
#include "ppd08office03.h"

#include "ppd08office03Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cppd08office03Doc

IMPLEMENT_DYNCREATE(Cppd08office03Doc, CDocument)

BEGIN_MESSAGE_MAP(Cppd08office03Doc, CDocument)
END_MESSAGE_MAP()


// Cppd08office03Doc 构造/析构

Cppd08office03Doc::Cppd08office03Doc()
{
	// TODO: 在此添加一次性构造代码

}

Cppd08office03Doc::~Cppd08office03Doc()
{
}

BOOL Cppd08office03Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// Cppd08office03Doc 序列化

void Cppd08office03Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// Cppd08office03Doc 诊断

#ifdef _DEBUG
void Cppd08office03Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Cppd08office03Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Cppd08office03Doc 命令

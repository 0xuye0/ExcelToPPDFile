// ppd08office03Doc.cpp : Cppd08office03Doc ���ʵ��
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


// Cppd08office03Doc ����/����

Cppd08office03Doc::Cppd08office03Doc()
{
	// TODO: �ڴ����һ���Թ������

}

Cppd08office03Doc::~Cppd08office03Doc()
{
}

BOOL Cppd08office03Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// Cppd08office03Doc ���л�

void Cppd08office03Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// Cppd08office03Doc ���

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


// Cppd08office03Doc ����

// ppd08office03View.cpp : Cppd08office03View ���ʵ��
//

#include "stdafx.h"
#include "ppd08office03.h"

#include "ppd08office03Doc.h"
#include "ppd08office03View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cppd08office03View

IMPLEMENT_DYNCREATE(Cppd08office03View, CView)

BEGIN_MESSAGE_MAP(Cppd08office03View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Cppd08office03View ����/����

Cppd08office03View::Cppd08office03View()
{
	// TODO: �ڴ˴���ӹ������

}

Cppd08office03View::~Cppd08office03View()
{
}

BOOL Cppd08office03View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cppd08office03View ����

void Cppd08office03View::OnDraw(CDC* /*pDC*/)
{
	Cppd08office03Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cppd08office03View ��ӡ

BOOL Cppd08office03View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cppd08office03View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cppd08office03View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cppd08office03View ���

#ifdef _DEBUG
void Cppd08office03View::AssertValid() const
{
	CView::AssertValid();
}

void Cppd08office03View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cppd08office03Doc* Cppd08office03View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cppd08office03Doc)));
	return (Cppd08office03Doc*)m_pDocument;
}
#endif //_DEBUG


// Cppd08office03View ��Ϣ�������

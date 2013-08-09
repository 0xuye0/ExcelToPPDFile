// ppd08office03View.cpp : Cppd08office03View 类的实现
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Cppd08office03View 构造/析构

Cppd08office03View::Cppd08office03View()
{
	// TODO: 在此处添加构造代码

}

Cppd08office03View::~Cppd08office03View()
{
}

BOOL Cppd08office03View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cppd08office03View 绘制

void Cppd08office03View::OnDraw(CDC* /*pDC*/)
{
	Cppd08office03Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Cppd08office03View 打印

BOOL Cppd08office03View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cppd08office03View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cppd08office03View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cppd08office03View 诊断

#ifdef _DEBUG
void Cppd08office03View::AssertValid() const
{
	CView::AssertValid();
}

void Cppd08office03View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cppd08office03Doc* Cppd08office03View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cppd08office03Doc)));
	return (Cppd08office03Doc*)m_pDocument;
}
#endif //_DEBUG


// Cppd08office03View 消息处理程序

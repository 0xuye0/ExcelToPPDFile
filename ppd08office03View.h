// ppd08office03View.h : Cppd08office03View 类的接口
//


#pragma once


class Cppd08office03View : public CView
{
protected: // 仅从序列化创建
	Cppd08office03View();
	DECLARE_DYNCREATE(Cppd08office03View)

// 属性
public:
	Cppd08office03Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Cppd08office03View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ppd08office03View.cpp 中的调试版本
inline Cppd08office03Doc* Cppd08office03View::GetDocument() const
   { return reinterpret_cast<Cppd08office03Doc*>(m_pDocument); }
#endif


// ppd08office03View.h : Cppd08office03View ��Ľӿ�
//


#pragma once


class Cppd08office03View : public CView
{
protected: // �������л�����
	Cppd08office03View();
	DECLARE_DYNCREATE(Cppd08office03View)

// ����
public:
	Cppd08office03Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~Cppd08office03View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ppd08office03View.cpp �еĵ��԰汾
inline Cppd08office03Doc* Cppd08office03View::GetDocument() const
   { return reinterpret_cast<Cppd08office03Doc*>(m_pDocument); }
#endif


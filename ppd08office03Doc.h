// ppd08office03Doc.h : Cppd08office03Doc ��Ľӿ�
//


#pragma once


class Cppd08office03Doc : public CDocument
{
protected: // �������л�����
	Cppd08office03Doc();
	DECLARE_DYNCREATE(Cppd08office03Doc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~Cppd08office03Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};




// 20160274_Practice_10_2Doc.h : CMy20160274_Practice_10_2Doc Ŭ������ �������̽�
//


#pragma once


class CMy20160274_Practice_10_2Doc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CMy20160274_Practice_10_2Doc();
	DECLARE_DYNCREATE(CMy20160274_Practice_10_2Doc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CMy20160274_Practice_10_2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	CString m_strDept;
	CString m_strName;
	CString m_strSex;
	CString m_strHobby;
};

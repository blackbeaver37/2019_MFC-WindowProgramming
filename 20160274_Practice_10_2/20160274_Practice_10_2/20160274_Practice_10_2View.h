
// 20160274_Practice_10_2View.h : CMy20160274_Practice_10_2View 클래스의 인터페이스
//

#pragma once
#include "atltypes.h"


class CMy20160274_Practice_10_2View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy20160274_Practice_10_2View();
	DECLARE_DYNCREATE(CMy20160274_Practice_10_2View)

// 특성입니다.
public:
	CMy20160274_Practice_10_2Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMy20160274_Practice_10_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	CPoint m_ptFollow;
	int m_nCount;
	CPoint m_ptFixate[5];
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 20160274_Practice_10_2View.cpp의 디버그 버전
inline CMy20160274_Practice_10_2Doc* CMy20160274_Practice_10_2View::GetDocument() const
   { return reinterpret_cast<CMy20160274_Practice_10_2Doc*>(m_pDocument); }
#endif


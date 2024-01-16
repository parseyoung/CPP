﻿
// mfc_test14View.h: Cmfctest14View 클래스의 인터페이스
//

#pragma once


class Cmfctest14View : public CEditView
{
protected: // serialization에서만 만들어집니다.
	Cmfctest14View() noexcept;
	DECLARE_DYNCREATE(Cmfctest14View)

// 특성입니다.
public:
	Cmfctest14Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~Cmfctest14View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // mfc_test14View.cpp의 디버그 버전
inline Cmfctest14Doc* Cmfctest14View::GetDocument() const
   { return reinterpret_cast<Cmfctest14Doc*>(m_pDocument); }
#endif


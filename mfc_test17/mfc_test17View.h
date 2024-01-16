
// mfc_test17View.h: Cmfctest17View 클래스의 인터페이스
//

#pragma once


class Cmfctest17View : public CFormView
{
protected: // serialization에서만 만들어집니다.
	Cmfctest17View() noexcept;
	DECLARE_DYNCREATE(Cmfctest17View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC_TEST17_FORM };
#endif

// 특성입니다.
public:
	Cmfctest17Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~Cmfctest17View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedMeta1();
	afx_msg void OnStnClickedMeta2();

	CStatic m_meta1;
	CStatic m_meta2;

};

#ifndef _DEBUG  // mfc_test17View.cpp의 디버그 버전
inline Cmfctest17Doc* Cmfctest17View::GetDocument() const
   { return reinterpret_cast<Cmfctest17Doc*>(m_pDocument); }
#endif



// mfc_test20View.h: Cmfctest20View 클래스의 인터페이스
//

#pragma once


class Cmfctest20View : public CFormView
{
protected: // serialization에서만 만들어집니다.
	Cmfctest20View() noexcept;
	DECLARE_DYNCREATE(Cmfctest20View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC_TEST20_FORM };
#endif

// 특성입니다.
public:
	Cmfctest20Doc* GetDocument() const;

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
	virtual ~Cmfctest20View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_list_meal;
	CListBox m_list_dessert;
	CListBox m_list_result;
	afx_msg void OnBnClickedButtonMeal();
	afx_msg void OnBnClickedButtonDessert();
	CString m_edit_etc;
	afx_msg void OnBnClickedButtonReset(); // reset
	afx_msg void OnEnChangeEditEtc();
	afx_msg void OnBnClickedButtonEtc();
	afx_msg void OnBnClickedButtonDel();
};

#ifndef _DEBUG  // mfc_test20View.cpp의 디버그 버전
inline Cmfctest20Doc* Cmfctest20View::GetDocument() const
   { return reinterpret_cast<Cmfctest20Doc*>(m_pDocument); }
#endif


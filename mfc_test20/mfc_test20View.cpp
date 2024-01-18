
// mfc_test20View.cpp: Cmfctest20View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "mfc_test20.h"
#endif

#include "mfc_test20Doc.h"
#include "mfc_test20View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfctest20View

IMPLEMENT_DYNCREATE(Cmfctest20View, CFormView)

BEGIN_MESSAGE_MAP(Cmfctest20View, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON_MEAL, &Cmfctest20View::OnBnClickedButtonMeal)
	ON_BN_CLICKED(IDC_BUTTON_DESSERT, &Cmfctest20View::OnBnClickedButtonDessert)
	ON_BN_CLICKED(IDC_BUTTON3, &Cmfctest20View::OnBnClickedButtonReset)
	ON_EN_CHANGE(IDC_EDIT_ETC, &Cmfctest20View::OnEnChangeEditEtc)
	ON_BN_CLICKED(IDC_BUTTON_ETC, &Cmfctest20View::OnBnClickedButtonEtc)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &Cmfctest20View::OnBnClickedButtonDel)
END_MESSAGE_MAP()

// Cmfctest20View 생성/소멸

Cmfctest20View::Cmfctest20View() noexcept
	: CFormView(IDD_MFC_TEST20_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cmfctest20View::~Cmfctest20View()
{
}

void Cmfctest20View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_MEAL, m_list_meal);
	DDX_Control(pDX, IDC_LIST_DESSERT, m_list_dessert);
	DDX_Control(pDX, IDC_LIST_RESULT, m_list_result);
	DDX_Text(pDX, IDC_EDIT_ETC, m_edit_etc);
}

BOOL Cmfctest20View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void Cmfctest20View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_list_meal.AddString(_T("된장찌개"));
	m_list_meal.AddString(_T("잡채밥"));
	m_list_meal.AddString(_T("불고기백반"));
	m_list_meal.AddString(_T("칼국수"));
	m_list_meal.AddString(_T("라면"));
	m_list_meal.AddString(_T("만두"));
	m_list_meal.AddString(_T("김치찌개"));
	m_list_meal.AddString(_T("스파게티"));

	m_list_dessert.AddString(_T("아이스아메리카노"));
	m_list_dessert.AddString(_T("아이스크림"));
	m_list_dessert.AddString(_T("녹차"));
	m_list_dessert.AddString(_T("케이크"));
	m_list_dessert.AddString(_T("사과주스"));
	m_list_dessert.AddString(_T("오렌지주스"));
	m_list_dessert.AddString(_T("쿠키"));
	m_list_dessert.AddString(_T("말차라뗴"));

}


// Cmfctest20View 인쇄

BOOL Cmfctest20View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cmfctest20View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cmfctest20View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void Cmfctest20View::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// Cmfctest20View 진단

#ifdef _DEBUG
void Cmfctest20View::AssertValid() const
{
	CFormView::AssertValid();
}

void Cmfctest20View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cmfctest20Doc* Cmfctest20View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfctest20Doc)));
	return (Cmfctest20Doc*)m_pDocument;
}
#endif //_DEBUG


// Cmfctest20View 메시지 처리기


void Cmfctest20View::OnBnClickedButtonMeal()
{
	int Index = m_list_meal.GetCurSel(); // 선택한 리스트 메뉴를 Index에 대입

	if (Index != LB_ERR)
	{
		CString str;
		m_list_meal.GetText(Index, str); // 문자열 get
		m_list_meal.SetCurSel(Index); // 문자열 선택
		m_list_result.AddString(str); // m_list_result에 문자열 추가
	}
}


void Cmfctest20View::OnBnClickedButtonDessert()
{
	//CString str;
	//int count = m_list_dessert.GetCurSel();
	//m_list_dessert.GetText(count, str); // 문자열 get
	//m_list_dessert.SetCurSel(count); // 문자열 선택
	//m_list_result.AddString(str); // m_list_result에 문자열 추가

	CString str;
	int count = m_list_dessert.GetCount(); // 총 갯수 조사

	for (int i = count - 1; i >= 0; i--)
	{
		if (m_list_dessert.GetSel(i)) // 다중 선택 
		{
			m_list_dessert.GetText(i, str);
			m_list_result.AddString(str);
		}
	}
}


void Cmfctest20View::OnBnClickedButtonReset()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_ETC);
	UpdateData(TRUE);

	m_edit_etc = _T("");  // = 연산자를 사용하여 값을 대입
	pEdit->SetFocus();
	UpdateData(FALSE);
}



void Cmfctest20View::OnBnClickedButtonEtc()
{
	CString str;
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_ETC);
	UpdateData(TRUE);

	if (m_edit_etc.IsEmpty())  // IsEmpty() 함수를 사용
	{
		MessageBox(_T(" 기타 메뉴를 입력하세요"), _T("Error"), MB_ICONSTOP | MB_OK);
		pEdit->SetFocus();
		return;
	}

	str = m_edit_etc;
	m_list_result.AddString(str);
	UpdateData(FALSE);
}


void Cmfctest20View::OnBnClickedButtonDel()
{
	int Index;
	Index = m_list_result.GetCurSel();
	if(Index != LB_ERR)
	{
		m_list_result.DeleteString(Index);
	}
	else
	{
		AfxMessageBox(_T("삭제할 메뉴 선택하세요"));
	}
}

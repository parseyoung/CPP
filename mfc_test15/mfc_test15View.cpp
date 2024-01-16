// 컨트롤 문제은행 만들기 //

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "mfc_test15.h"
#endif

#include "mfc_test15Doc.h"
#include "mfc_test15View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfctest15View

IMPLEMENT_DYNCREATE(Cmfctest15View, CScrollView)

BEGIN_MESSAGE_MAP(Cmfctest15View, CScrollView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_CREATE()

	// 버튼 클릭시 발생하는 메세지와 함수 연결 
	ON_BN_CLICKED(101, OnButtonClicked1) // 버튼 아이디, 멤버 함수
	ON_BN_CLICKED(102, OnButtonClicked2) // 버튼 아이디, 멤버 함수
	ON_BN_CLICKED(999, sum1)

END_MESSAGE_MAP()

// Cmfctest15View 생성/소멸

Cmfctest15View::Cmfctest15View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cmfctest15View::~Cmfctest15View()
{
}

BOOL Cmfctest15View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CScrollView::PreCreateWindow(cs);
}

// Cmfctest15View 그리기

void Cmfctest15View::OnDraw(CDC* pDC)
{
	Cmfctest15Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// 문제 은행 
	pDC->SetTextColor(RGB(0, 0, 0)); // 글씨색
	pDC->SetBkColor(RGB(255, 255, 0)); // 글씨 배경색
	pDC->TextOutW(50, 50, CString(_T(" * 다음 물음에 알맞은 답을 고르시오. *")));

	pDC->SetTextColor(RGB(0, 0, 0)); 
	pDC->SetBkColor(RGB(255, 255, 255));
	CFont font, * pOldFont;
	font.CreatePointFont(150, _T("맑은고딕"));
	pOldFont = (CFont*)pDC->SelectObject(&font);

	pDC->TextOutW(50, 100, CString(_T("1. 다음중 박세영의 생일은? [20점]")));
	pDC->TextOutW(50, 140, CString(_T("1) 12월 9일")));
	pDC->TextOutW(50, 180, CString(_T("2) 12월 29일")));
	pDC->TextOutW(50, 220, CString(_T("3) 12월 19일")));
	pDC->TextOutW(50, 260, CString(_T("4) 12월 15일")));
	pDC->TextOutW(50, 300, CString(_T("5) 12월 4일")));

	pDC->TextOutW(50, 350, CString(_T("2. 다음중 박세영과 먹지 않은 음식은? [15점]")));
	pDC->TextOutW(50, 390, CString(_T("1) 치킨")));
	pDC->TextOutW(50, 430, CString(_T("2) 떡볶이")));
	pDC->TextOutW(50, 470, CString(_T("3) 라멘")));
	pDC->TextOutW(50, 510, CString(_T("4) 꼬북칩")));
	pDC->TextOutW(50, 550, CString(_T("5) 가지덮밥")));

	pDC->TextOutW(50, 800, CString(_T("연습으로 화면을 벗어난 컨트롤")));
	pDC->TextOutW(50, 850, CString(_T("연습으로 화면을 벗어난 컨트롤!!!")));

}

void Cmfctest15View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 이 뷰의 전체 크기를 계산합니다.
	sizeTotal.cx = sizeTotal.cy = 3000;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// Cmfctest15View 인쇄

BOOL Cmfctest15View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cmfctest15View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cmfctest15View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// Cmfctest15View 진단

#ifdef _DEBUG
void Cmfctest15View::AssertValid() const
{
	CScrollView::AssertValid();
}

void Cmfctest15View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

Cmfctest15Doc* Cmfctest15View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfctest15Doc)));
	return (Cmfctest15Doc*)m_pDocument;
}
#endif //_DEBUG


// Cmfctest15View 메시지 처리기


int Cmfctest15View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CScrollView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// 버튼 컨트롤 생성

	// ============= 1번 문항 =====================
	m_pushbutton1.Create(_T("정답 확인"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		CRect(590, 90, 690, 130), this, 101);

	m_checkbox1_1.Create(_T(""), WS_CHILD | WS_VISIBLE | WS_GROUP | BS_AUTORADIOBUTTON,
		CRect(30, 130, 80, 170), this, 1001);
	m_checkbox1_2.Create(_T(""), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		CRect(30, 170, 80, 210), this, 1002);
	m_checkbox1_3.Create(_T(""), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		CRect(30, 210, 80, 250), this, 1003);
	m_checkbox1_4.Create(_T(""), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		CRect(30, 250, 80, 290), this, 1004);
	m_checkbox1_5.Create(_T(""), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		CRect(30, 290, 80, 330), this, 1005);

	m_groupbox1.Create(_T(""), WS_CHILD | BS_GROUPBOX,
		CRect(10, 110, 170, 350), this, 1006);

	m_checkbox1_1.SetCheck(0); //1은 체크 됨
	m_checkbox1_2.SetCheck(0);
	m_checkbox1_3.SetCheck(0);
	m_checkbox1_4.SetCheck(0);
	m_checkbox1_5.SetCheck(0);

	// ============= 2번 문항 =====================
	m_pushbutton2.Create(_T("정답 확인"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		CRect(790, 390, 890, 430), this, 102);

	m_checkbox2_1.Create(_T(""), WS_CHILD | WS_VISIBLE | WS_GROUP | BS_AUTORADIOBUTTON,
		CRect(30, 430, 80, 470), this, 1021);
	m_checkbox2_2.Create(_T(""), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		CRect(30, 470, 80, 510), this, 1022);
	m_checkbox2_3.Create(_T(""), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		CRect(30, 510, 80, 550), this, 1023);
	m_checkbox2_4.Create(_T(""), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		CRect(30, 550, 80, 590), this, 1024);
	m_checkbox2_5.Create(_T(""), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		CRect(30, 590, 80, 630), this, 1025);

	m_groupbox2.Create(_T(""), WS_CHILD | BS_GROUPBOX,
		CRect(10, 410, 170, 700), this, 2006);

	m_checkbox2_1.SetCheck(0);
	m_checkbox2_2.SetCheck(0);
	m_checkbox2_3.SetCheck(0);
	m_checkbox2_4.SetCheck(0);
	m_checkbox2_5.SetCheck(0);

	m_sumbutton.Create(_T("전체 성적 : "), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		CRect(890, 90, 990, 130), this, 999);

	return 0;
}


void Cmfctest15View::OnButtonClicked1()
{
	int state_checkbox1_1 = m_checkbox1_1.GetCheck();
	int state_checkbox1_2 = m_checkbox1_2.GetCheck();
	int state_checkbox1_3 = m_checkbox1_3.GetCheck();
	int state_checkbox1_4 = m_checkbox1_4.GetCheck();
	int state_checkbox1_5 = m_checkbox1_5.GetCheck();

	CString str1;
	str1.Format(_T("맞은 점수 :  [ %d ] 점"),
		state_checkbox1_1 * 20);

	//state_checkbox1_2 * 0;
	//state_checkbox1_3 * 15;

	MessageBox(str1, _T("1번 문제 결과"), MB_ICONINFORMATION);
}

void Cmfctest15View::OnButtonClicked2()
{
	int state_checkbox2_1 = m_checkbox2_1.GetCheck();
	int state_checkbox2_2 = m_checkbox2_2.GetCheck();
	int state_checkbox2_3 = m_checkbox2_3.GetCheck();
	int state_checkbox2_4 = m_checkbox2_4.GetCheck();
	int state_checkbox2_5 = m_checkbox2_5.GetCheck();

	CString str2;
	str2.Format(_T("맞은 점수 :  [ %d ] 점"),
		state_checkbox2_3 * 15);

	MessageBox(str2, _T("2번 문제 결과"), MB_ICONINFORMATION);
}

void Cmfctest15View::sum1()
{
	int state_checkbox1_1 = m_checkbox1_1.GetCheck();
	int state_checkbox2_3 = m_checkbox2_3.GetCheck();

	CString tot1;
	tot1.Format(_T(" [ %d ] 점"),
		(state_checkbox1_1 * 20) + (state_checkbox2_3 * 15));

	MessageBox(tot1, _T("전체 성적을 알려드려요"), MB_ICONINFORMATION);

	CClientDC dc1(this);
	dc1.TextOutW(1000, 98, tot1);

}
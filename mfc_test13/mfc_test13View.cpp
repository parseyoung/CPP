// Document / View MFC ??

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "mfc_test13.h"
#endif

#include "mfc_test13Doc.h"
#include "mfc_test13View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfctest13View

IMPLEMENT_DYNCREATE(Cmfctest13View, CView)

BEGIN_MESSAGE_MAP(Cmfctest13View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Cmfctest13View 생성/소멸

Cmfctest13View::Cmfctest13View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cmfctest13View::~Cmfctest13View()
{
}

BOOL Cmfctest13View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// Cmfctest13View 그리기

void Cmfctest13View::OnDraw(CDC* pDC)
{
	Cmfctest13Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	/* mapping mode란? 주어진 좌표가 화면상의 실제 어디에 해당하는지를 계산하는 방법을 말함
	* 매핑모드는 두가지 좌표 사용
	* 논리좌표 : 윈도우에서 사용하는 좌표로 작업영역의 좌표
	* 물리좌표 : 화면좌표로 화면상 절대 좌표
	* 매핑모드는 논리좌표를 물리좌표로 변환하는 방법 의미
	*/

	//pDC->SetMapMode(MM_LOMETRIC); // 0.1mm 단위 매핑모드(MM) 변경, 화면출력 및 인쇄 
	//pDC->SetMapMode(MM_TEXT); // 픽셀 단위 MM
	//pDC->SetMapMode(MM_HIMETRIC); // 0.1mm 단위 MM
	//pDC->SetMapMode(MM_LOENGLISH); // 0.01inch 단위 MM
	//pDC->SetMapMode(MM_HIENGLISH); // 0,001inch 단위 MM
	//pDC->SetMapMode(MM_TWIPS); // 1/1440inch 단위 MM

	pDC->SetMapMode(MM_LOMETRIC);
	// 화면에 사각형, 타원 그리기
	pDC->Rectangle(50, -50, 350, -350); //30mm 정사각형
	pDC->Ellipse(500, -50, 800, -350); //30mm 타원

	// MM_LOMETRIC 선언 한 경우,
	// y좌표 음수로 하지 않으면 화면에 출력 X
	pDC->Rectangle(50, 50, 100, 100);
	pDC->MoveTo(400, 450);
	pDC->LineTo(600, 450);
	
	//화면 출력 시 y좌표는 내려갈 수록 음수값임 (출력 O)
	pDC->MoveTo(450, 500);
	pDC->LineTo(450, -500); 


	pDC->SetMapMode(MM_TEXT); // <- 주석하면 화면에 그려지지 X
	pDC->MoveTo(400, 450);
	pDC->LineTo(600, 450);

	CPen pen, * pen1;
	CPen pen_Red;

	pen.CreatePen(PS_SOLID, 3, RGB(0, 0, 0)); // black
	//pen_Red.CreatePen(PS_SOLID, 1, RGB(255, 0, 0)); // red 실선
	pen_Red.CreatePen(PS_DOT, 1, RGB(255, 0, 0)); // red 점선

	pen1 = pDC->SelectObject(&pen);
	pDC->MoveTo(50, 200);
	pDC->LineTo(50, 500);
	pDC->LineTo(700, 500);

	pen1 = pDC->SelectObject(&pen_Red);

	pDC->MoveTo(50, 500);
	pDC->LineTo(150, 300);
	pDC->LineTo(250, 350);
	pDC->LineTo(350, 200);
	pDC->LineTo(450, 350);
	pDC->LineTo(550, 300);
	pDC->LineTo(650, 100);

	CFont font1;

	font1.CreatePointFont(300, _T("궁서"));
	pDC->SelectObject(&font1);

	pDC->SetTextColor(RGB(0, 255, 0));
	pDC->TextOutW(500, 30, CString(_T("0.1mm 단위 MM rect")));

	pDC->SetTextColor(RGB(0, 0, 255));
	pDC->TextOutW(700, 160, CString(_T("MFC DOC/VIEW ")));

	// 글씨 only black
	pDC->SetTextColor(RGB(0, 0, 0));
	pDC->TextOut(100, 550, CString(_T("Vision SW 개발자 된다!")));
}

// Cmfctest13View 인쇄

BOOL Cmfctest13View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cmfctest13View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cmfctest13View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// Cmfctest13View 진단

#ifdef _DEBUG
void Cmfctest13View::AssertValid() const
{
	CView::AssertValid();
}

void Cmfctest13View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cmfctest13Doc* Cmfctest13View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfctest13Doc)));
	return (Cmfctest13Doc*)m_pDocument;
}
#endif //_DEBUG


// Cmfctest13View 메시지 처리기

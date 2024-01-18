
// mfc_test22View.cpp: Cmfctest22View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "mfc_test22.h"
#endif

#include "mfc_test22Doc.h"
#include "mfc_test22View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfctest22View

IMPLEMENT_DYNCREATE(Cmfctest22View, CFormView)

BEGIN_MESSAGE_MAP(Cmfctest22View, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Cmfctest22View 생성/소멸

Cmfctest22View::Cmfctest22View() noexcept
	: CFormView(IDD_MFC_TEST22_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cmfctest22View::~Cmfctest22View()
{
}

void Cmfctest22View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL Cmfctest22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void Cmfctest22View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// Cmfctest22View 인쇄

BOOL Cmfctest22View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cmfctest22View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cmfctest22View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void Cmfctest22View::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// Cmfctest22View 진단

#ifdef _DEBUG
void Cmfctest22View::AssertValid() const
{
	CFormView::AssertValid();
}

void Cmfctest22View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cmfctest22Doc* Cmfctest22View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfctest22Doc)));
	return (Cmfctest22Doc*)m_pDocument;
}
#endif //_DEBUG


// Cmfctest22View 메시지 처리기

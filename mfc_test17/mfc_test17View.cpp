
// mfc_test17View.cpp: Cmfctest17View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "mfc_test17.h"
#endif

#include "mfc_test17Doc.h"
#include "mfc_test17View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfctest17View

IMPLEMENT_DYNCREATE(Cmfctest17View, CFormView)

BEGIN_MESSAGE_MAP(Cmfctest17View, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_STN_CLICKED(IDC_META1, &Cmfctest17View::OnStnClickedMeta1)
	ON_STN_CLICKED(IDC_META2, &Cmfctest17View::OnStnClickedMeta2)

END_MESSAGE_MAP()

// Cmfctest17View 생성/소멸

Cmfctest17View::Cmfctest17View() noexcept
	: CFormView(IDD_MFC_TEST17_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cmfctest17View::~Cmfctest17View()
{
}

void Cmfctest17View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_META1, m_meta1);
	DDX_Control(pDX, IDC_META2, m_meta2);

}

BOOL Cmfctest17View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void Cmfctest17View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	// SetEnhMetaFile() : 확장 메타파일과 static control 연결
	// GetEnhMetaFile() : 확장 메타파일을 가르키는 handle return
	m_meta1.SetEnhMetaFile(::GetEnhMetaFile(_T("rect.emf")));
	m_meta2.SetEnhMetaFile(::GetEnhMetaFile(_T("tri.emf")));
}


// Cmfctest17View 인쇄

BOOL Cmfctest17View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cmfctest17View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cmfctest17View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void Cmfctest17View::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// Cmfctest17View 진단

#ifdef _DEBUG
void Cmfctest17View::AssertValid() const
{
	CFormView::AssertValid();
}

void Cmfctest17View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cmfctest17Doc* Cmfctest17View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfctest17Doc)));
	return (Cmfctest17Doc*)m_pDocument;
}
#endif //_DEBUG


// Cmfctest17View 메시지 처리기


void Cmfctest17View::OnStnClickedMeta1()
{
	MessageBox(_T(" 메타파일 사각형 입니다!"));
}

void Cmfctest17View::OnStnClickedMeta2()
{
	MessageBox(_T(" 메타파일 타원 입니다!"));
}



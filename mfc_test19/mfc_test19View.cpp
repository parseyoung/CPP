// Edite control, Static text, picture control //

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "mfc_test19.h"
#endif

#include "mfc_test19Doc.h"
#include "mfc_test19View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfctest19View

IMPLEMENT_DYNCREATE(Cmfctest19View, CFormView)

BEGIN_MESSAGE_MAP(Cmfctest19View, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_EN_CHANGE(IDC_EDIT1, &Cmfctest19View::OnEnChangeEdit1)
	ON_EN_MAXTEXT(IDC_EDIT1, &Cmfctest19View::OnEnMaxtextEdit1)
	ON_STN_CLICKED(IDC_STATIC1, &Cmfctest19View::OnStnClickedStatic1)
END_MESSAGE_MAP()

// Cmfctest19View 생성/소멸

Cmfctest19View::Cmfctest19View() noexcept
	: CFormView(IDD_MFC_TEST19_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cmfctest19View::~Cmfctest19View()
{
}

void Cmfctest19View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC1, m_static1);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
}

BOOL Cmfctest19View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

// control state 변경
void Cmfctest19View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_edit1.SetLimitText(30); //init code 최대 한글 영문 숫자 30

}


// Cmfctest19View 인쇄

BOOL Cmfctest19View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cmfctest19View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cmfctest19View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void Cmfctest19View::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// Cmfctest19View 진단

#ifdef _DEBUG
void Cmfctest19View::AssertValid() const
{
	CFormView::AssertValid();
}

void Cmfctest19View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cmfctest19Doc* Cmfctest19View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfctest19Doc)));
	return (Cmfctest19Doc*)m_pDocument;
}
#endif //_DEBUG


void Cmfctest19View::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// === add code ===== 
	CString str;
	m_edit1.GetWindowText(str); // edete control에 입력된 텍스트 얻음
	m_static1.SetWindowText(str); // static control에 edite control에 입력된 문자 출력
}


void Cmfctest19View::OnEnMaxtextEdit1()
{
	// === add code ===== 


	MessageBox(_T("최대 길이 도달"), _T("글자 수 제한 오류"), MB_ICONERROR);
}


void Cmfctest19View::OnStnClickedStatic1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	MessageBox(_T("왜요? 난 static control"), _T("hello"), MB_ICONERROR);

}

// 메뉴 만들어 글씨 색깔 변하게 하기 //
// 툴바 색 선택 후 글씨 색 바꾸기 //

#include "pch.h"
#include "framework.h"
#include "mfc_test11.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_color = RGB(255, 0, 0);
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_RED, &CChildView::OnRed)
	ON_COMMAND(ID_GREAN, &CChildView::OnGrean)
	ON_COMMAND(ID_BLUE, &CChildView::OnBlue)
	ON_COMMAND(ID_YELLOW, &CChildView::OnYellow)
	ON_UPDATE_COMMAND_UI(ID_RED, &CChildView::OnUpdateRed)
	ON_UPDATE_COMMAND_UI(ID_GREAN, &CChildView::OnUpdateGrean)
	ON_UPDATE_COMMAND_UI(ID_BLUE, &CChildView::OnUpdateBlue)
	ON_WM_CONTEXTMENU()
	ON_UPDATE_COMMAND_UI(ID_YELLOW, &CChildView::OnUpdateYellow)
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	CFont font1;
	font1.CreatePointFont(300, _T("궁서"));
	dc.SelectObject(&font1);
	dc.SetTextColor(m_color); // red

	CRect rect1;
	GetClientRect(&rect1);
	CString str1 = _T("박세영 MFC STudy");
	dc.DrawText(str1, &rect1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	dc.TextOutW(400, 200, CString(_T("visul mfc 연습")));

	// 여기서 부터는 black text color
	dc.SetTextColor(RGB(0, 0, 0));
	dc.TextOutW(400, 500, CString(_T("Vision SW 개발자를 위하여!")));
}


void CChildView::OnRed()
{
	m_color = RGB(255, 0, 0);
	Invalidate(); // 화면 갱신
}
void CChildView::OnGrean()
{
	m_color = RGB(0, 255, 0);
	Invalidate(); 
}
void CChildView::OnBlue()
{
	m_color = RGB(0, 0, 255);
	Invalidate(); 
}
void CChildView::OnYellow()
{
	m_color = RGB(255, 255, 0);
	Invalidate();
}

// CMD UI에 선택 한 색상 check 표시 func
void CChildView::OnUpdateRed(CCmdUI* pCmdUI)
{
	// pCmdUI : CMD UI 포인터 주소값
	pCmdUI->SetCheck(m_color == RGB(255, 0, 0));
}
void CChildView::OnUpdateGrean(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_color == RGB(0, 255, 0));
}
void CChildView::OnUpdateBlue(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_color == RGB(0, 0, 255));
}

void CChildView::OnUpdateYellow(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_color == RGB(255, 255, 0));
}




void CChildView::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	CMenu menu1;
	menu1.LoadMenuW(IDR_MAINFRAME); //IDR_MAINFRAME 메뉴 리소스 Load
	CMenu* pMenu = menu1.GetSubMenu(4); // 메뉴 5번째 위치 [글자색] pMenu에 대입 

	// 연습으로 추가 
	pMenu->AppendMenuW(MF_SEPARATOR);
	
	// ID가 20인 메뉴 항목 추가
	pMenu->AppendMenuW(MF_STRING, 20, _T("원하는 색 선택()"));
	// 왼쪽정렬, 오른쪽 마우스 버튼 클릭시
	pMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, AfxGetMainWnd());
}




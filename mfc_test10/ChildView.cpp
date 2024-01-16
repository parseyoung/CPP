// 키보드로 도형 이동 시키기 //

#include "pch.h"
#include "framework.h"
#include "mfc_test10.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView
// 생성자에서 ChildView.h 선언 한 멤버변수 초기화 함
CChildView::CChildView()
{
	m_xPos = m_yPos = 100; // x, y 100위치에 초기화
	m_bFill = FALSE; // 도형 내부 채우지 않음
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_KEYDOWN()
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
	
	if (m_bFill == TRUE) dc.SelectStockObject(BLACK_BRUSH);
	
	CBrush brush1(RGB(255, 0, 0));
	dc.SelectObject(&brush1);	

	dc.Ellipse(m_xPos - 20, m_yPos - 20, m_xPos + 20, m_yPos + 20); // 타원 x1,y1,x2,y2
	
}



void CChildView::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);
	m_xClient = cx; // 클라이언트 영역 x좌표 픽셀 값
	m_yClient = cy; // 클라이언트 영역 y좌표 픽셀 값
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
	switch (nChar)
	{
	case VK_LEFT:
		m_xPos -=20;
		break;
	case VK_RIGHT:
		m_xPos += 20;
		break;
	case VK_UP:
		m_yPos -= 20;
		break;
	case VK_DOWN:
		m_yPos += 20;
		break;
	case VK_HOME: // HOME 이동 가상 키보드
		m_xPos += -10000;  // 가장 작은 값, 처음으로 이동
		m_yPos += -10000;
		break;
	case VK_SPACE:
		m_bFill = !m_bFill; // 도형 반전(검정)
		break;
	}

	// 도형의 위치가 클라이언트 영역을 벗어나지 않게 함
	m_xPos = min(max(20, m_xPos), m_xClient - 20);
	// m_xPos = max(20, m_xPos), m_xClient - 20; : 도형 위치 클라이언트 영역 벗어남
	m_yPos = min(max(20, m_yPos), m_yClient - 20);
	
	// 윈도우화면 가려져 다시 그려야 하는 경우 클라이언트 영역 전체 무효화해서
	// WM_PAINT 메시지 강제로 발생
	Invalidate();

}

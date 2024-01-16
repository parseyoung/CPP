
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "mfc_test7.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_DrawMode = FALSE;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
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
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}





void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	SetCapture(); // 마우스 캡쳐 시작

	m_DrawMode = TRUE;

	m_x1 = m_x2 = point.x;
	m_y1 = m_y2 = point.y;
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// 그리기 모드이면 타원을 지우고 그리기 반복
	if (m_DrawMode)
	{
		CClientDC dc(this);
		dc.SelectStockObject(NULL_BRUSH); // : 이전에 그린 타원을 지움

		dc.SetROP2(R2_NOT); //wingd.h 파일에 정의, 레스터 오퍼레이션
		// : 윈도우에 이미 그려진 그림과 새로 그려질 그림 합성

		//dc.Ellipse(m_x1, m_y1, m_x2, m_y2);
		dc.Rectangle(m_x1, m_y1, m_x2, m_y2);

		//새로운 타원 그림
		dc.SetROP2(R2_NOT);
		m_x2 = point.x;
		m_y2 = point.y;
		//dc.Ellipse(m_x1, m_y1, m_x2, m_y2);
		dc.Rectangle(m_x1, m_y1, m_x2, m_y2);

	}
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	CClientDC dc(this);

	CPen pen(PS_SOLID, 3, RGB(255, 0, 0)); // red 3fixel
	dc.SelectObject(&pen);

	dc.SelectStockObject(NULL_BRUSH);
	// 최종 타원 그림
	dc.SetROP2(R2_COPYPEN);

	m_x2 = point.x;
	m_y2 = point.y;
	//dc.Ellipse(m_x1, m_y1, m_x2, m_y2);
	dc.Rectangle(m_x1, m_y1, m_x2, m_y2);

	// 그리기 모드 해제
	m_DrawMode = FALSE;

	::ReleaseCapture(); // :: scope 글로벌 범위
}

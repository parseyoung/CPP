
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "mfc_test6.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
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
	
	// Solid brush : 속이 꽉찬 브러시
	CBrush brush1(RGB(0, 0, 255));
	dc.SelectObject(&brush1);
	dc.Rectangle(50, 50, 200, 200);

	CBrush brush2(HS_DIAGCROSS, RGB(0, 0, 255));
	dc.SelectObject(&brush2);
	dc.Rectangle(250, 50, 400, 200);

	// pattern brush : 비트멥의 반복 무늬 브러시
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP2);

	CBrush brush3(&bitmap);
	dc.SelectObject(&brush3);
	dc.Rectangle(450, 50, 600, 200);

	// solid brush : 속이 꽉찬 브러시
	CBrush brush4(RGB(255, 0, 0));
	dc.SelectObject(&brush4);
	dc.Rectangle(50, 350, 200, 500);

	// hach brush : 교차하는 평행성 브러시
	CBrush brush5(HS_DIAGCROSS, RGB(255, 0, 0));
	dc.SelectObject(&brush5);
	dc.Ellipse(250, 350, 400, 500);

	// pattern brush : 비트멥의 반복 무늬 브러시
	CBitmap bitmap2;
	bitmap2.LoadBitmap(IDB_BITMAP3);
	CBrush brush6(&bitmap2);
	dc.SelectObject(&brush6);
	dc.RoundRect(450, 350, 600, 500, 50, 50);



}


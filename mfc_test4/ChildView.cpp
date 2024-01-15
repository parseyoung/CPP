
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "mfc_test4.h"
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
	
	int nPenStyle[] = { PS_SOLID, PS_DASH, PS_DOT, PS_DASHDOT, PS_DASHDOTDOT, PS_NULL, PS_INSIDEFRAME };
	// char : 1byte
	// WCHAR : 멀티바이트캐릭터셋, 2byte unsigned short 
	// TCHAR : 프로젝트 디버깅 설정에서 정한 캐릭터셋에 따라 멀티바이트가 되기도 하고,
	// 유니코드가 되기도 하는 자료형(컴파일 단계 결정) 즉, 문자열 깨짐 방지위해 사용

	TCHAR* PenStyle[] = { _T("1. PS_SOLID(실선)"), _T("2. PS_DASH(파선)"), _T("3. PS_DOT(가는점선)"),
	 _T(". PS_DASHDOT(1점쇄선)"), _T("5. PS_DASHDOTDOT(2점쇄선)"), _T("6. PS_NULL(투명선)"),
	 _T("7. PS_INSIDEFRAME(안쪽프레임선)") };

	dc.SetTextAlign(TA_BASELINE); //텍스트 기본 정렬 방식

	for (int i = 0; i < sizeof(nPenStyle) / sizeof(nPenStyle[0]); i++)
	{
		CPen pen(nPenStyle[i], 1, RGB(255, 0, 0)); // 픽셀 굵기 1
		dc.SelectObject(&pen);
		dc.TextOut(50, 25 + i * 25, PenStyle[i], lstrlen(PenStyle[i]));
		// x : 50
		// y : y 50, 75, 100, 125 ...
		// lstrlen : TextOut()는 마지막 문자열 길이를 요구하여 길이를 알려줘 유니코드 변환 시 깨짐 방지
		dc.MoveTo(500, 25 + i * 25); // (500, 50  75  100  125 ...)
		dc.LineTo(1000, 25 + i * 25);
	}

	CPen blackpen1(PS_SOLID, 3, RGB(0, 0, 0)); // 폭 3, black
	CPen blackpen2(PS_SOLID, 3, RGB(0, 255, 0)); // 폭 3, grean

	dc.SelectObject(&blackpen1);
	dc.Rectangle(50, 400, 150, 300); // 폭과 높이가 100인 직사각형
	CPen pen1(PS_SOLID, 20, RGB(255, 0, 0)); // 폭 20, red PS_SOLID
	dc.SelectObject(&pen1);
	dc.Ellipse(50, 400, 150, 300); // 지름 100 원

	dc.SelectObject(&blackpen2);
	dc.Rectangle(250, 400, 350, 300); // 폭과 높이가 100인 직사각형
	CPen pen2(PS_INSIDEFRAME, 20, RGB(0, 0, 255)); // 폭 20, blue PS_INSIDEFRAME(안쪽으로만 선 확장)
	dc.SelectObject(&pen2);
	dc.Ellipse(250, 400, 350, 300); // 지름 100 원



}


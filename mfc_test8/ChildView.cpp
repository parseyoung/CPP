// 마우스 커서 모양 변경, 그림 불러와서 확대, 축소하기//

#include "pch.h"
#include "framework.h"
#include "mfc_test8.h"
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
    ON_WM_SETCURSOR()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs)
{
    if (!CWnd::PreCreateWindow(cs))
        return FALSE;

    cs.dwExStyle |= WS_EX_CLIENTEDGE;
    cs.style &= ~WS_BORDER;
    cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
        ::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), nullptr);

    return TRUE;
}

void CChildView::OnPaint()
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

	dc.SelectStockObject(LTGRAY_BRUSH);
	dc.Ellipse(10, 10, 400, 200);

	// Get size information after loading bitmap resource
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);

	// 메모리 DC를 만든 후 비트맵을 선택해 낳는다
	CDC dcmem;
	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&bitmap);

	// 비트맵 화면에 출력 / BitBit : 비트맵 그림 원본 복사 함수
	dc.BitBlt(500, 10, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);

	dc.SetTextColor(RGB(0, 0, 255)); // 글자색

	CFont font, * pOldFont;
	font.CreatePointFont(150, _T("Tahoma"));
	pOldFont = (CFont * )dc.SelectObject(&font);

	dc.TextOut(100, 350, CString(_T("그림 1/2 축소")));
	dc.StretchBlt(10, 400, bmpinfo.bmWidth / 2, bmpinfo.bmHeight / 2, &dcmem, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
}



BOOL CChildView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
    if (nHitTest == HTCLIENT)
    {
        CPoint point;
        ::GetCursorPos(&point); // 커서 위치 스크린 좌표 얻음 global 변수
        ScreenToClient(&point); // 스크린 좌표를 클라이언트 좌표로 변환

        CRgn rgn; // 다양한 형태의 면선택에 사용, Region : 구역, 영역이란 뜻
        rgn.CreateEllipticRgn(10, 10, 400, 200); // 타원형 리전 생성

        if (rgn.PtInRegion(point)) // 커서가 리전 안쪽에 있는지 확인

           // 사용자가 만든 커서로 변경
            ::SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
        else
            // 표준 커서 중 하나로 변경
            ::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS));
        return true;

    }

    return CWnd::OnSetCursor(pWnd, nHitTest, message);
}
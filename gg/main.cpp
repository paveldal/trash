#define _USE_MATH_DEFINES

#include <windows.h>
#include <cmath>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

HDC dc;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASS wc = { 0 };
    wc.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = L"CMyWnd";
    RegisterClass(&wc);
    HWND hWnd = CreateWindow(L"CMyWnd", L"WinMain sample",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, 500, 500, NULL, NULL, hInstance, NULL);
    dc = GetDC(hWnd);
    ShowWindow(hWnd, nCmdShow);

    SetTimer(hWnd, 1, USER_TIMER_MINIMUM, NULL);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;

}

const double r = 70;
const double margin_top = 50;

void func(double r, double t, double t1, double& x1, double& y1, double& x2, double& y2) {
    x1 = r * t - r * sin(t1);
    y1 = -(-r * cos(t1) ) + r + margin_top;

    x2 = r * t - r * sin(t1 + M_PI);
    y2 = -(-r * cos(t1 + M_PI)) + r + margin_top;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    static bool Move = true;
    static int Phase = 0, Width, Height;

    switch (message) {
    case WM_LBUTTONDOWN:
    case WM_RBUTTONDOWN:
        Move = !Move;
    case WM_TIMER:
        if (Move)
            Phase++;
        else
            Phase--;

    case WM_PAINT: {
        Rectangle(dc, -1, -1, Width + 1, Height + 1);

        Ellipse(dc, -r + r * Phase * 0.01, margin_top, r + r * Phase * 0.01, margin_top + r * 2);

        MoveToEx(dc, 0, margin_top + r * 2, (LPPOINT)NULL);
        LineTo(dc, Width, margin_top + r * 2);

        double tm = 0;
        for (int i = 0; i < 4; i++) {
            double x1, y1, x2, y2;
            func(r, Phase * 0.01, Phase * 0.01 + tm, x1, y1, x2, y2);
            MoveToEx(dc, x1, y1, (LPPOINT)NULL);
            LineTo(dc, x2, y2);
            tm += M_PI / 4;
        }
    }
        break;
    case WM_SIZE:
        Width = LOWORD(lParam),
        Height = HIWORD(lParam);
        break;
    case WM_KEYDOWN:
        if (wParam != VK_ESCAPE)
            break;
    case WM_DESTROY:
        PostQuitMessage(0);
    }

    return DefWindowProc(hWnd, message, wParam, lParam);
}

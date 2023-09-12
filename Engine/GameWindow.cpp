#include "pch.h"
#include "GameWindow.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_SIZE:
    {
        //DWORD newWidth = LOWORD(lParam);
        //DWORD newHeight = HIWORD(lParam);
        //if (g_window) {
        //    g_window->SetWindowSize(newWidth, newHeight);
        //}
    }
    break;
    case WM_KEYDOWN:
        if (wParam == VK_ESCAPE) {
            PostQuitMessage(0);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}

GameWindow::GameWindow() :
    m_HInstance(nullptr),
    m_hWnd(nullptr),
    m_WindowWidth(0),
    m_WindowHeight(0),
    m_WindowPosX(0),
    m_WindowPosY(0),
    m_WindowExStyle(WS_EX_APPWINDOW),
    m_WindowStyle(WS_OVERLAPPEDWINDOW) //WS_OVERLAPPEDWINDOW)
{}

void GameWindow::MakeWindow(std::wstring title, HINSTANCE hInst, DWORD dwWindowWidth, DWORD dwWindowHeight)
{
    WNDCLASSEX wcex{};
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.hInstance = m_HInstance = hInst;
    wcex.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.lpszClassName = title.c_str();

    if (RegisterClassExW(&wcex) == 0) {
        assert(false && "Register window class failed");
        return;
    }

    RECT windowRect = { 0, 0, dwWindowWidth, dwWindowHeight };
    AdjustWindowRect(&windowRect, m_WindowStyle, FALSE);

    // È­¸é Áß¾Ó¿¡ ¶ç¿ì±â
    m_WindowPosX = (GetSystemMetrics(SM_CXSCREEN) - (windowRect.right - windowRect.left)) / 2;
    m_WindowPosY = (GetSystemMetrics(SM_CYSCREEN) - (windowRect.bottom - windowRect.top)) / 2;

    m_hWnd = CreateWindowEx(
        m_WindowExStyle,
        title.c_str(),
        title.c_str(),
        m_WindowStyle,
        m_WindowPosX, m_WindowPosY,
        windowRect.right - windowRect.left, windowRect.bottom - windowRect.top,
        nullptr, nullptr, m_HInstance, nullptr);

    if (!m_hWnd) {
        assert(false && "HWND creation failed");
        return; 
    }

    ShowWindow(m_hWnd, SW_SHOWNORMAL);
}


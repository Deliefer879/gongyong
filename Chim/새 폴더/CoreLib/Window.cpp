#include "Window.h"
#include "Constant.h"

// this function handle window message
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam); // return message to window
	}

	return 0;
}

bool Window::SetRegisterClassWindow(HINSTANCE hInstance)
{
	this->hInstance = hInstance;			// set instance handle

	WNDCLASSEX wcex;							// window class EX
	ZeroMemory(&wcex, sizeof(wcex));		// init window class EX

	//set window class EX members value
	wcex.cbSize = sizeof(WNDCLASSEX);				// window class size
	wcex.style = CS_HREDRAW | CS_VREDRAW;		// window style
	wcex.lpfnWndProc = WndProc;					// Set window procedure function
	wcex.hInstance = hInstance;			// Set instance handle
	wcex.lpszClassName = L"CreateRenderObject";	// Set window class name
	wcex.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));	// Set window background color (cut blue light)
	wcex.hCursor = LoadCursor(nullptr, IDC_CROSS);	// Set window cursor

	WORD ret = RegisterClassEx(&wcex);			// Register window class

	return true;
}

bool Window::SetWindow(const WCHAR* title, DWORD width, DWORD height)
{
	dwWindowHeight = g_Constant.g_winSizeY = height;
	dwWindowWidth  = g_Constant.g_winSizeX = width;

#ifdef _DEBUG
	dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
	dwStyle |= WS_VISIBLE;
#else // release
	dwStyle = WS_POPUPWINDOW;
	dwExStyle = WS_EX_TOPMOST;
#endif
	RECT rc = {0, 0, dwWindowWidth, dwWindowHeight};
	AdjustWindowRectEx(&rc, dwStyle, FALSE, dwExStyle); // adjust window size

	hWnd = CreateWindowEx(dwExStyle, L"CreateRenderObject", title, dwStyle, // you need to set window class name same as you set in SetRegisterClassWindow function
	CW_USEDEFAULT,CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, nullptr, nullptr, hInstance, nullptr); // create WindowClass

	if (!hWnd)
		return false;

	ShowWindow(hWnd, SW_SHOWNORMAL);	// show window
	g_Constant.g_hWnd = hWnd;

	return true;
}

bool Window::HandleMessage()
{
	MSG msg = { 0 };

	while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
	{
		if(msg.message == WM_QUIT)
			return false;

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return true;
}

bool Window::Init(HINSTANCE hInstance, const WCHAR* title, DWORD width, DWORD height)
{
	if(SetRegisterClassWindow(hInstance))
		if(SetWindow(title, width, height))
			return true;

	return false;
}

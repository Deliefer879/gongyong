#pragma once

#include "Std.h"

class Window
{
private:
	HINSTANCE hInstance;	// instance handle	(frequently use in window class so we have this member value)
	HWND hWnd;				// window handle	(frequently use in window class so we have this member value)
	DWORD dwStyle = WS_OVERLAPPEDWINDOW;			// window style
	DWORD dwExStyle = 0;		// window extended style (need when use RegisterClassEx function)
	DWORD dwWindowPosX = 100;		// window position x (screen)
	DWORD dwWindowPosY = 100;		// window position y (screen)
	DWORD dwWindowWidth;	// window width
	DWORD dwWindowHeight;	// window height
private:
	bool SetRegisterClassWindow(HINSTANCE hInstance); // set window class
	bool SetWindow(const WCHAR* title, DWORD width = 800, DWORD height = 600);
public:
	bool HandleMessage();
	bool Init(HINSTANCE hInstance, const WCHAR* title, DWORD width , DWORD height);

	HINSTANCE& GetHInstance() { return hInstance; }
	HWND& GetHWnd() { return hWnd; }
	DWORD& GetWindowWidth() { return dwWindowWidth; }
	DWORD& GetWindowHeight() { return dwWindowHeight; }
};

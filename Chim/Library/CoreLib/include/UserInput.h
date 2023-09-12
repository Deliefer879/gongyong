#pragma once

#include "Std.h"
#include "Singleton.hpp"

#include <dinput.h>
#pragma comment (lib, "dinput8.lib")
#pragma comment (lib, "dxguid.lib")

enum class KeyState
{
	NONE = (0x01 << 0),   //1
	UP = (0x01 << 1),   //2
	PUSH = (0x01 << 2),   //4
	HOLD = (0x01 << 3),	  //8
};

class UserInput : public Singleton<UserInput>
{
private:
	friend class Singleton<UserInput>;
	UserInput() {};

	IDirectInput8* pDirectInput;
	IDirectInputDevice8* pKeyboardDevice;
	IDirectInputDevice8* pMouseDevice;

	unsigned char keyboardState[256];
	KeyState keyStateArr[256];

	KeyState mouseStateArr[4];
	DIMOUSESTATE mouseState;

	POINT mousePoint;
	Vector2 mousePos;
private:
	bool InitKeyboard(HINSTANCE hInstance, HWND hwnd);
	bool InitMouse(HINSTANCE hInstance, HWND hwnd);

	bool ReadKeyboard();
	bool ReadMouse();

	void ProcessKeyboardInput();
	void ProcessMouseInput();

public:
	bool Init(HINSTANCE hInstance, HWND hwnd);
	bool Frame();
	void Release();

	Vector2  GetMousePos() const { return mousePos; };
	KeyState GetKeyState(const unsigned char key) const;
	KeyState GetMouseState(const int key) const;
};


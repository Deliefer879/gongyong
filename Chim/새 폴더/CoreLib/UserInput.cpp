#include "UserInput.h"

#include "Constant.h"
#include "CameraManger.h"

bool UserInput::InitKeyboard(HINSTANCE hInstance, HWND hwnd)
{
	HRESULT hr = DirectInput8Create(hInstance, DIRECTINPUT_VERSION
		, IID_IDirectInput8, (void**)&pDirectInput, nullptr);
	if (FAILED(hr))
	{
		ShowErrorMessage(hr);
		return false;
	}

	hr = pDirectInput->CreateDevice(GUID_SysKeyboard, &pKeyboardDevice, nullptr);
	if (FAILED(hr))
	{
		ShowErrorMessage(hr);
		return false;
	}

	hr = pKeyboardDevice->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(hr))
	{
		ShowErrorMessage(hr);
		return false;
	}

	hr = pKeyboardDevice->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	if (FAILED(hr))
	{
		ShowErrorMessage(hr);
		return false;
	}

	hr = pKeyboardDevice->Acquire();
	if (FAILED(hr))
	{
		ShowErrorMessage(hr);
		return false;
	}

	return true;
}
bool UserInput::InitMouse(HINSTANCE hInstance, HWND hwnd)
{
	HRESULT hr = pDirectInput->CreateDevice(GUID_SysMouse, &pMouseDevice, nullptr);
	if (FAILED(hr))
	{
		ShowErrorMessage(hr);
		return false;
	}

	hr = pMouseDevice->SetDataFormat(&c_dfDIMouse);
	if (FAILED(hr))
	{
		ShowErrorMessage(hr);
		return false;
	}

	hr = pMouseDevice->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	if (FAILED(hr))
	{
		ShowErrorMessage(hr);
		return false;
	}

	hr = pMouseDevice->Acquire();
	if (FAILED(hr))
	{
		ShowErrorMessage(hr);
		return false;
	}

	return true;
}
bool UserInput::ReadKeyboard()
{
	HRESULT hr = pKeyboardDevice->GetDeviceState(256, keyboardState);

	if (FAILED(hr))
	{
		if (hr == DIERR_INPUTLOST || hr == DIERR_NOTACQUIRED) // if keyboard lost or not acquired
			pKeyboardDevice->Acquire();
		else
			return false;
	}

	return true;
}
bool UserInput::ReadMouse()
{
	HRESULT hr = pMouseDevice->GetDeviceState(sizeof(DIMOUSESTATE), &mouseState);

	if (FAILED(hr))
	{
		if (hr == DIERR_INPUTLOST || hr == DIERR_NOTACQUIRED) // if mouse lost or not acquired
			pMouseDevice->Acquire();
		else
			return false;
	}

	return true;
}
void UserInput::ProcessKeyboardInput()
{
	for (int i = 0; i < 256; ++i)
	{
		if (keyboardState[i] & 0x80)
		{
			if (keyStateArr[i] == KeyState::NONE)
				keyStateArr[i] = KeyState::PUSH;
			else
				keyStateArr[i] = KeyState::HOLD;
		}
		else
		{
			if (keyStateArr[i] == KeyState::PUSH || keyStateArr[i] == KeyState::HOLD)
				keyStateArr[i] = KeyState::UP;
			else
				keyStateArr[i] = KeyState::NONE;
		}
	}
}
void UserInput::ProcessMouseInput()
{
	// updeate mouse position
	GetCursorPos(&mousePoint);
	ScreenToClient(g_Constant.g_hWnd, &mousePoint);

	mousePos.x = MainCamera->camPos.x - g_Constant.g_winSizeX * 0.5f;
	mousePos.y = MainCamera->camPos.y + g_Constant.g_winSizeY * 0.5f;
	mousePos.x += mousePoint.x;
	mousePos.y -= mousePoint.y;

	// update mouse button state

	for (int i = 0; i < 4; ++i)
	{
		if (mouseState.rgbButtons[i] & 0x80)
		{
			if (mouseStateArr[i] == KeyState::NONE)
				mouseStateArr[i] = KeyState::PUSH;
			else
				mouseStateArr[i] = KeyState::HOLD;
		}
		else
		{
			if (mouseStateArr[i] == KeyState::PUSH || mouseStateArr[i] == KeyState::HOLD)
				mouseStateArr[i] = KeyState::UP;
			else
				mouseStateArr[i] = KeyState::NONE;
		}
	}
}
bool UserInput::Init(HINSTANCE hInstance, HWND hwnd)
{
	if (!InitKeyboard(hInstance, hwnd))
		return false;
	if (!InitMouse(hInstance, hwnd))
		return false;

	return true;
}
bool UserInput::Frame()
{
	if(!ReadKeyboard())
		return false;

	if (!ReadMouse())
		return false;

	ProcessMouseInput();
	ProcessKeyboardInput();

	return true;
}

void UserInput::Release()
{
	if (pKeyboardDevice)
	{
		pKeyboardDevice->Unacquire();
		pKeyboardDevice->Release();
		pKeyboardDevice = nullptr;
	}

	if (pMouseDevice)
	{
		pMouseDevice->Unacquire();
		pMouseDevice->Release();
		pMouseDevice = nullptr;
	}

	if (pDirectInput)
	{
		pDirectInput->Release();
		pDirectInput = nullptr;
	}

	return;
}

KeyState UserInput::GetKeyState(const unsigned char key) const
{
	return keyStateArr[key];
}

KeyState UserInput::GetMouseState(const int key) const
{
	return mouseStateArr[key];
}

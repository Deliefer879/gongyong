#pragma once

enum KeyState
{
    KEY_FREE = 0,
    KEY_UP = 1,
    KEY_PUSH = 2,
    KEY_HOLD = 3,
};

class InputHandler
{
public:
    XMFLOAT3 GetMouseWorldPos(XMFLOAT2 vWindow, XMFLOAT3 vCamera);
    POINT GetMousePos() const { return MousePos; }
    bool  UpdateKeyEvent(HWND hwnd);
    
    static InputHandler& GetInstance()
    {
        static InputHandler input;
        return input;
    }
private:    
    InputHandler() { ZeroMemory(&KeyState, sizeof(KeyState)); }
    ~InputHandler() {}
    POINT MousePos{};
    DWORD KeyState[256];
};

#define INPUT_HANDLER InputHandler::GetInstance()
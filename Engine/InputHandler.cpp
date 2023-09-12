#include "pch.h"
#include "InputHandler.h"

XMFLOAT3 InputHandler::GetMouseWorldPos(XMFLOAT2 vWindow, XMFLOAT3 vCamera)
{
    float fHalfWidth = vWindow.x / 2.0f;
    float fHalfHeight = vWindow.y / 2.0f;

    // client
    XMFLOAT3 vMouse = { (float)MousePos.x, (float)MousePos.y , 0.0f};
    // world
    XMFLOAT2 vMouseWorldLT = { vCamera.x - fHalfWidth, vCamera.y + fHalfHeight };
    vMouse.x = vMouseWorldLT.x + vMouse.x;
    vMouse.y = vMouseWorldLT.y - vMouse.y;
    return vMouse;
}

bool  InputHandler::UpdateKeyEvent(HWND hwnd)
{       
    ::GetCursorPos(&MousePos); // ½ºÅ©¸° ÁÂÇ¥
    ::ScreenToClient(hwnd, &MousePos);

    for (int ikey = 0; ikey < 256; ikey++)
    {
        SHORT s = GetAsyncKeyState(ikey);
        if (s & 0x8000) {
            if (KeyState[ikey] == KEY_FREE)  
                KeyState[ikey] = KEY_PUSH;
            else 
                KeyState[ikey] = KEY_HOLD;
        }
        else
        {
            if (KeyState[ikey] == KEY_PUSH || KeyState[ikey] == KEY_HOLD) 
                KeyState[ikey] = KEY_UP;
            else 
                KeyState[ikey] = KEY_FREE;
        }
    }    
    return true;
}

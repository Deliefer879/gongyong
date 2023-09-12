#pragma once
#include "D3D11Renderer.h"
#include "Timer.h"
#include "InputHandler.h"
#include "TextManager.h"
#include "ShaderManager.h"
#include "TextureManager.h"
#include "AudioManager.h"

class EngineCore
{
private:
    void  EngineInit();
    bool  EngineFrame();
    bool  EngineRender();

public:
    void  Run();
    EngineCore() = delete;
    EngineCore(const std::wstring& title, HINSTANCE& hInst, DWORD dwWindowWidth, DWORD dwWindowHeight);

private:
    std::shared_ptr<GameWindow>     MainWindow;
    std::shared_ptr<D3D11Renderer>  MainRenderer;
};

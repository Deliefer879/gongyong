#include "pch.h"
#include "Core.h"

void  EngineCore::EngineInit()
{
    TEXT_MANAGER.InitDWrite(MainRenderer->GetBackBufferSurface(), MainWindow->GetWindowHandle(), 17.f, L"¸¼Àº °íµñ");
    TEXTURE_MANAGER.GetDevice(MainRenderer->GetDevice());
    SHADER_MANAGER.GetDevice(MainRenderer->GetDevice());
}

bool  EngineCore::EngineFrame()
{
    TIMER.UpdateClock();
    INPUT_HANDLER.UpdateKeyEvent(MainWindow->GetWindowHandle());
    AUDIO_MANAGER.UpdateAudioFrame();
    // ACTOR_MANAGER.UpdateTick();

    return true;
}

bool  EngineCore::EngineRender()
{
    // PRE RENDER
    MainRenderer->RenderClearAndSetBlendState();

    // RENDER
    // ACTOR_MANAGER.RenderActors();
    TIMER.DrawTimeInfo();

    // POST RENDER
    TEXT_MANAGER.RenderTexts();
    MainRenderer->Present();

    return true;
}

void EngineCore::Run()
{
    EngineInit();
    MSG msg{};
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            if (!EngineFrame() || !EngineRender())
            {
                break;
            }
        }
    }
}

EngineCore::EngineCore(const std::wstring& title, HINSTANCE& hInst, DWORD dwWindowWidth, DWORD dwWindowHeight)
{
    MainWindow = make_shared<GameWindow>();
    MainWindow->MakeWindow(title, hInst, dwWindowWidth, dwWindowHeight);
    MainRenderer = make_shared<D3D11Renderer>(MainWindow->GetWindowHandle(), MainWindow->GetWindowWidth(), MainWindow->GetWindowHeight());
}

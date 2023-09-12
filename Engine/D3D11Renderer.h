#pragma once
#include "GameWindow.h"

class D3D11Renderer : public IWindowObserver
{
public:
    void  RenderClearAndSetBlendState();
    void  Present();
    void  OnWindowResize(DWORD width, DWORD height) override;
    ComPtr<IDXGISurface1> GetBackBufferSurface();
    ComPtr<ID3D11Device> GetDevice() { return m_Device; }


    D3D11Renderer() = delete;
    D3D11Renderer(HWND hwnd, float winWidth, float winHeight);

private:
    ComPtr<IDXGISwapChain>          m_SwapChain;
    ComPtr<ID3D11Device>            m_Device;
    ComPtr<ID3D11DeviceContext>     m_ImmediateContext;
    ComPtr<ID3D11RenderTargetView>  m_RenderTargetView;
    ComPtr<ID3D11BlendState>        m_BlendState;
    D3D11_VIEWPORT			        m_ViewPort;
};

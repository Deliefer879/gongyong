#include "Graphics.h"

void Graphics::SetViewPort(int topLeftX, int topLeftY, int width, int height, int minDepth, int maxDepth)
{
    viewPort.TopLeftX = topLeftX;
    viewPort.TopLeftY = topLeftY;
    viewPort.Width = width;
    viewPort.Height = height;
    viewPort.MinDepth = minDepth;
    viewPort.MaxDepth = maxDepth;

    pImmediateContext->RSSetViewports(1, &viewPort);
}

bool Graphics::SetAlphaBlending()
{
    D3D11_BLEND_DESC blendDesc;
    ZeroMemory(&blendDesc, sizeof(blendDesc));

    blendDesc.RenderTarget[0].BlendEnable = true; // enable blending
    blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA; // set source blending factor
    blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA; // set destination blending factor
    blendDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD; // set blending operation
    blendDesc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD; // set blending operation for alpha
    blendDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE; // set source blending factor for alpha
    blendDesc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO; // set destination blending factor for alpha

    blendDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL; // set color write mask
    
    HRESULT hr = pDevice->CreateBlendState(&blendDesc, &pBlendState); // create blend state

    if (FAILED(hr))
    {
		ShowErrorMessage(hr);
		return false;
	}

    return true;
}

bool Graphics::SetRenderTargetView()
{
    // get back buffer
    ID3D11Texture2D* pBackBuffer;
    HRESULT hr = pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer); // get back buffer from swap chain
    // buffer index(we have only one back buffer), buffer interface type, buffer interface pointer
    if (FAILED(hr))
    {
        ShowErrorMessage(hr);
        return false;
    }

    // set render target view
    hr = pDevice->CreateRenderTargetView(pBackBuffer, NULL, &pRenderTargetView); // create render target view
    if (FAILED(hr))
    {
        ShowErrorMessage(hr);
        pBackBuffer->Release();
        return false;
    }

    pImmediateContext->OMSetRenderTargets(1, &pRenderTargetView, NULL); // bind render target view to device context
    pBackBuffer->Release();

    return true;
}

bool Graphics::CreateDevice()
{
    D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_11_0; // set feature level (directx version) : we use directx 11
    UINT flags = D3D11_CREATE_DEVICE_BGRA_SUPPORT; // for dx write

    HRESULT hr = D3D11CreateDevice(
        nullptr,
        D3D_DRIVER_TYPE::D3D_DRIVER_TYPE_HARDWARE,
        nullptr,
        flags,
        &featureLevel,1,
        D3D11_SDK_VERSION,
        &pDevice,
        nullptr,
        &pImmediateContext);

    if (FAILED(hr))
    { 
        ShowErrorMessage(hr);
        return false;
    }

    return true;
}

bool Graphics::CreateSwapChain(HWND wHnd, int wWidth, int wHeight)
{
    // create IDXGIFactory2 for use CreateSwapChainHwnd
    IDXGIFactory2* pDxgiFactory = nullptr;
    HRESULT hr = CreateDXGIFactory1(__uuidof(IDXGIFactory2), (LPVOID*)&pDxgiFactory);

    if (FAILED(hr)) // failed to create IDXGIFactory2
    {
        ShowErrorMessage(hr);
        return false;
    }

    // set swap chain(back buffer) description
    DXGI_SWAP_CHAIN_DESC1 swapChainDesc;  // multi buffer description
    ZeroMemory(&swapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC1)); // initialize to zero

    swapChainDesc.Width = wWidth;  // buffer width it needs to same with window width
    swapChainDesc.Height = wHeight; // buffer height it needs to same with window height
    swapChainDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; // buffer format (set 32bit color format) : buffer needs to same with window color format
    swapChainDesc.SampleDesc.Count = 1; // sample count must be more than 1
    swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; // what is the usage of this buffer (set render target output)
    swapChainDesc.BufferCount = 1; // buffer count (set 1)

    // create swap chain
    hr = pDxgiFactory->CreateSwapChainForHwnd(
        pDevice,
        wHnd,
        &swapChainDesc,
        nullptr,
        nullptr,
        &pSwapChain
    );
    pDxgiFactory->Release();

    if (FAILED(hr)) // failed to create swap chain
	{
        ShowErrorMessage(hr);
		return false;
	}

    return true;
}

void Graphics::CreateSamplerState()
{
    D3D11_SAMPLER_DESC descSamp;
    descSamp.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
    descSamp.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
    descSamp.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
    descSamp.MipLODBias = 0;
    descSamp.MaxAnisotropy = 16;

    descSamp.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
    descSamp.ComparisonFunc = D3D11_COMPARISON_NEVER;

    descSamp.BorderColor[0] = 1.0f;
    descSamp.BorderColor[1] = 0.0f;
    descSamp.BorderColor[2] = 0.0f;
    descSamp.BorderColor[3] = 1.0f;
    descSamp.MinLOD = 0;
    descSamp.MaxLOD = D3D11_FLOAT32_MAX;
    pDevice->CreateSamplerState(&descSamp, &pSamplerState);
}

bool Graphics::Init(HWND wHnd, int wWidth, int wHeight)
{
    CreateDevice();
    CreateSwapChain(wHnd, wWidth, wHeight);
    SetRenderTargetView();
    SetAlphaBlending();
    SetViewPort(0, 0, wWidth, wHeight, 0.0f, 1.0f);

    return true;
}

bool Graphics::Frame()
{
    return true;
}

void Graphics::PreRender()
{
    // clear render target view
    float clearColor[4] = { 1.0f, 1.0f, 1.0f, 1.0f }; // set clear color
    pImmediateContext->ClearRenderTargetView(pRenderTargetView, clearColor); // clear render target view

    // set blend state
    pImmediateContext->OMSetBlendState(pBlendState, nullptr, -1); // set blend state
}

void Graphics::PostRender()
{
    pSwapChain->Present(0, 0); // swap front buffer and back buffer
}

bool Graphics::Release()
{
    if (pDevice) pDevice->Release();                  // we have to release resource 
    if (pImmediateContext) pImmediateContext->Release();    // if we are not release resource, ref count will not be zero
    if (pSwapChain) pSwapChain->Release();
    if (pRenderTargetView) pRenderTargetView->Release();
    if (pBlendState) pBlendState->Release();

    return true;
}

IDXGISurface1* Graphics::GetBackBuffer()
{
    IDXGISurface1* pBackBuffer;
    HRESULT hr = pSwapChain->GetBuffer(0, __uuidof(IDXGISurface1), (LPVOID*)&pBackBuffer); // get back buffer from swap chain

    if(FAILED(hr))
    {
		ShowErrorMessage(hr);
		return nullptr;
	}

    return pBackBuffer;
}

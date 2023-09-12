#pragma once

#include "Std.h"

class Graphics
{
	// device, swap chain, render target view interface
private:
	IDXGISwapChain1* pSwapChain = nullptr;				 // interface for multiple buffer management
	ID3D11RenderTargetView* pRenderTargetView = nullptr; // interface for render target

	ID3D11BlendState* pBlendState = nullptr;			 // interface for alpha blending

	D3D11_VIEWPORT viewPort;							 // viewport
public:
	ID3D11Device* pDevice = nullptr;					 // interface for primary resource creation and delete
	ID3D11DeviceContext* pImmediateContext = nullptr;    // interface for resource management

	ID3D11SamplerState* pSamplerState = nullptr;		 // interface for texture sampling
private:
	void SetViewPort(int topLeftX, int topLeftY, int width, int height, int minDepth, int maxDepth);
	bool SetAlphaBlending();
	bool SetRenderTargetView();
	bool CreateDevice();
	bool CreateSwapChain(HWND wHnd, int wWidth, int wHeight);

	void  CreateSamplerState();
public: 
	// main logic
	bool Init(HWND wHnd, int wWidth, int wHeight);
	bool Frame();
	void PreRender();
	void PostRender();
	bool Release();

	IDXGISurface1* GetBackBuffer();
};


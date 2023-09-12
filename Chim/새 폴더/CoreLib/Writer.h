#pragma once

#include "Std.h"
#include "Singleton.hpp"

struct TextData
{
	std::wstring text;
	D2D1_RECT_F layout;
	D2D1_COLOR_F color = {0,0,0,1};
};

class Writer : public Singleton<Writer>
{
private:
	friend class Singleton<Writer>;
	Writer() {};
	~Writer() {};

private:
	ID2D1Factory* pD2DFactory = nullptr;
	ID2D1RenderTarget* pRenderTarget = nullptr;
	ID2D1SolidColorBrush* pBrush = nullptr;
	IDWriteFactory* pDWriteFactory = nullptr;
	IDWriteTextFormat* pTextFormat = nullptr;

	std::vector<TextData> textDataList;
private:
	bool CreateDeviceIndependentResources();
	bool CreateDeviceResources(HWND hwnd, IDXGISurface1* pBackBuffer);
public:
	bool Init(HWND hwnd, IDXGISurface1* pBackBuffer);
	bool Frame();
	void PreRender();
	bool Render();
	void PostRender();
	bool Release();

public:
	void AddText(std::wstring text, D2D1_RECT_F layout, D2D1_COLOR_F color = { 0,0,0,1 });
};


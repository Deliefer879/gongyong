#include "Writer.h"

bool Writer::CreateDeviceIndependentResources()
{
	HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pD2DFactory);
	if (FAILED(hr))
	{
		ShowErrorMessage(hr);
		return false;
	}

	hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&pDWriteFactory));
	if (FAILED(hr))
	{
		ShowErrorMessage(hr);
		return false;
	}

	hr = pDWriteFactory->CreateTextFormat(
		L"±Ã¼­",
		nullptr,
		DWRITE_FONT_WEIGHT_REGULAR,
		DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL,
		15.0f,
		L"ko-kr",
		&pTextFormat
	);
	if (FAILED(hr))
	{
		ShowErrorMessage(hr);
		return false;
	}

	return true;
}

bool Writer::CreateDeviceResources(HWND hwnd, IDXGISurface1* pBackBuffer)
{
	float dpi = GetDpiForWindow(hwnd); // dpi : dots per inch(x, y is same)

	D2D1_RENDER_TARGET_PROPERTIES prop;
	ZeroMemory(&prop, sizeof(prop));
	prop.type = D2D1_RENDER_TARGET_TYPE_DEFAULT;
	prop.pixelFormat.format = DXGI_FORMAT_UNKNOWN;
	prop.pixelFormat.alphaMode = D2D1_ALPHA_MODE_PREMULTIPLIED;
	prop.dpiX = dpi;
	prop.dpiY = dpi;
	prop.usage = D2D1_RENDER_TARGET_USAGE_NONE;
	prop.minLevel = D2D1_FEATURE_LEVEL_DEFAULT;

	// Cast the IDXGISurface1 pointer to an IDXGISurface pointer.
	IDXGISurface* pDXGISurface = nullptr;
	HRESULT hr = pBackBuffer->QueryInterface(__uuidof(IDXGISurface), reinterpret_cast<void**>(&pDXGISurface));
	if (FAILED(hr))
	{
		ShowErrorMessage(hr);
		return false;
	}

	// Create the render target.
	hr = pD2DFactory->CreateDxgiSurfaceRenderTarget(pDXGISurface, &prop, &pRenderTarget);
	pDXGISurface->Release();
	if (FAILED(hr))
	{
		ShowErrorMessage(hr);
		return false;
	}

	hr = pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &pBrush);
	if (FAILED(hr))
	{
		ShowErrorMessage(hr);
		return false;
	}

	return true;
}

bool Writer::Init(HWND hwnd, IDXGISurface1* pBackBuffer)
{
	if (!CreateDeviceIndependentResources())
		return false;
	if (!CreateDeviceResources(hwnd, pBackBuffer))
		return false;

    return true;
}

bool Writer::Frame()
{
    return true;
}

void Writer::PreRender()
{
	if (pRenderTarget)
	{
		pRenderTarget->BeginDraw();
		pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	}
}

bool Writer::Render()
{
	PreRender();

	for (int i = 0; i < textDataList.size(); ++i)
	{
		pBrush->SetColor(textDataList[i].color);
		pRenderTarget->DrawTextW(
			textDataList[i].text.c_str(),
			textDataList[i].text.size(),
			pTextFormat,
			textDataList[i].layout,
			pBrush
		);
	}

	PostRender();

    return true;
}

void Writer::PostRender()
{
	if (pRenderTarget)
		pRenderTarget->EndDraw();

	textDataList.clear();
}

bool Writer::Release()
{
	if (pD2DFactory) pD2DFactory->Release();
	if (pRenderTarget) pRenderTarget->Release();
	if (pBrush) pBrush->Release();
	if (pDWriteFactory) pDWriteFactory->Release();
	if (pTextFormat) pTextFormat->Release();

    return true;
}

void Writer::AddText(std::wstring text, D2D1_RECT_F layout, D2D1_COLOR_F color)
{
	TextData textData;
	textData.text = text;
	textData.layout = layout;
	textData.color = color;

	textDataList.push_back(textData);
}

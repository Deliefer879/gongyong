#include "pch.h"
#include "TextManager.h"

void TextManager::InitDWrite(ComPtr<IDXGISurface1> backBuffer, HWND hwnd, FLOAT fontSize, const WCHAR* fontFamilyName)
{
    HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_MULTI_THREADED, m_D2DFactory.GetAddressOf());
    ASSERT_HR(hr);

    hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), (IUnknown**)m_DWriteFactory.GetAddressOf());
    ASSERT_HR(hr);

    hr = m_DWriteFactory->CreateTextFormat(
        fontFamilyName,
        nullptr,
        DWRITE_FONT_WEIGHT_NORMAL,
        DWRITE_FONT_STYLE_NORMAL,
        DWRITE_FONT_STRETCH_NORMAL,
        fontSize,
        L"ko-kr", // en-us
        m_DefaultTextFormat.GetAddressOf());
    ASSERT_HR(hr);

    CreateDXWriteRenderTarget(backBuffer, hwnd);
}

void TextManager::CreateDXWriteRenderTarget(ComPtr<IDXGISurface1>& backBuffer, HWND hwnd)
{
    float dpi = GetDpiForWindow(hwnd);

    D2D1_RENDER_TARGET_PROPERTIES prop{};
    prop.type = D2D1_RENDER_TARGET_TYPE_DEFAULT;
    prop.pixelFormat.format = DXGI_FORMAT_UNKNOWN;
    prop.pixelFormat.alphaMode = D2D1_ALPHA_MODE_PREMULTIPLIED;
    prop.dpiX = dpi;
    prop.dpiY = dpi;
    prop.usage = D2D1_RENDER_TARGET_USAGE_NONE;
    prop.minLevel = D2D1_FEATURE_LEVEL_DEFAULT;

    HRESULT hr = m_D2DFactory->CreateDxgiSurfaceRenderTarget(
        backBuffer.Get(),
        &prop,
        m_RenderTargetView.GetAddressOf());
    ASSERT_HR(hr);

    hr = m_RenderTargetView->CreateSolidColorBrush(
        D2D1::ColorF(D2D1::ColorF::Yellow),
        m_DefaultBrush.GetAddressOf());
    ASSERT_HR(hr);
}

void TextManager::AddTextToBuffer(const std::wstring& text, const D2D1_RECT_F& layout, D2D1::ColorF color)
{
    m_TextBuffer.emplace_back(text, layout, color );
}

void TextManager::RenderTexts()
{
    // begin draw
    m_RenderTargetView->BeginDraw();

    // draw all texts
    m_RenderTargetView->SetTransform(D2D1::IdentityMatrix());
    m_DefaultTextFormat->GetFontSize();

    for (int i = 0; i < m_TextBuffer.size(); ++i) {

        m_DefaultBrush->SetColor(m_TextBuffer[i].m_TextColor);
        m_DefaultBrush->SetOpacity(1.0f);

        m_RenderTargetView->DrawText(
            m_TextBuffer[i].m_Text.c_str(),
            m_TextBuffer[i].m_Text.size(),
            m_DefaultTextFormat.Get(),
            &m_TextBuffer[i].m_TextLayout,
            m_DefaultBrush.Get());
    }

    // end draw
    m_RenderTargetView->EndDraw();
    m_TextBuffer.clear();
}

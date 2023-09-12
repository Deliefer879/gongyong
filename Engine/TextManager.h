#pragma once
struct Text
{
	std::wstring m_Text;
	D2D1_RECT_F  m_TextLayout; // 출력 영역
	D2D1::ColorF m_TextColor;
	
    Text(const std::wstring& text, const D2D1_RECT_F& layout, D2D1::ColorF color)
        : m_Text(text), m_TextLayout(layout), m_TextColor(color)
    {}
};

class TextManager 
{
public:
	void InitDWrite(ComPtr<IDXGISurface1> backBuffer, HWND hwnd, FLOAT fontSize, const WCHAR* fontFamilyName);

	void AddTextToBuffer(const std::wstring& text, const D2D1_RECT_F& layout, D2D1::ColorF color);

	void RenderTexts();

	static TextManager& GetInstance()
	{
		static TextManager input;
		return input;
	}

private:
	void CreateDXWriteRenderTarget(ComPtr<IDXGISurface1>& backBuffer, HWND hwnd);
	TextManager() {}
	~TextManager() {}

	std::vector<Text>				m_TextBuffer;
	ComPtr<ID2D1Factory>			m_D2DFactory;
	ComPtr<IDWriteFactory>			m_DWriteFactory;
	ComPtr<IDWriteTextFormat>		m_DefaultTextFormat;
	ComPtr<ID2D1RenderTarget>		m_RenderTargetView;
	ComPtr<ID2D1SolidColorBrush>	m_DefaultBrush;
};

#define TEXT_MANAGER TextManager::GetInstance()
inline TextManager& GetTextManager() { return TextManager::GetInstance(); }
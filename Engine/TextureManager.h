#pragma once

class TextureManager
{
public:
    void GetDevice(ComPtr<ID3D11Device> device);
	ComPtr<ID3D11ShaderResourceView> GetTextureView(std::wstring filePath);

	static TextureManager& GetInstance() {
		static TextureManager instance;
		return instance;
	}

private:
	TextureManager() {}
	
	ComPtr<ID3D11Device> m_Device;
	std::map<std::wstring, ComPtr<ID3D11ShaderResourceView>> m_TextureViews;
};

#define TEXTURE_MANAGER TextureManager::GetInstance()
inline TextureManager& GetTextureManager() { return TextureManager::GetInstance(); }
#pragma once

#include "ResourceManager.hpp"

class Texture
{
private:
	ID3D11ShaderResourceView* pTextureSRV = nullptr;	// interface for texture Shader resource view

public:
	bool Load(std::wstring fileName, ID3D11Device* pDevice);
	bool Render(ID3D11DeviceContext* pContext) const;
	bool Release();
};

class TextureManager : public ResourceManager<Texture, TextureManager>
{
private:
	friend class Singleton<TextureManager>;
	TextureManager() {};
};


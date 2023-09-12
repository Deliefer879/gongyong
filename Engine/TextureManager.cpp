#include "pch.h"
#include "TextureManager.h"

void TextureManager::GetDevice(ComPtr<ID3D11Device> device)
{
    m_Device = device;
}

ComPtr<ID3D11ShaderResourceView> TextureManager::GetTextureView(std::wstring filePath)
{
    // 이미 로드되어있다면 리턴
    auto iter = m_TextureViews.find(filePath);
    if (m_TextureViews.end() != iter)
        return iter->second;

    // 없다면 로드후 리턴
    auto imageobj = std::make_unique<DirectX::ScratchImage>();
    DirectX::TexMetadata metadata;
    ComPtr<ID3D11ShaderResourceView> textureView;

    HRESULT hr = DirectX::GetMetadataFromDDSFile(filePath.c_str(), DirectX::DDS_FLAGS_NONE, metadata);
    if (SUCCEEDED(hr))
    {
        hr = DirectX::LoadFromDDSFile(filePath.c_str(), DirectX::DDS_FLAGS_NONE, &metadata, *imageobj);
        if (SUCCEEDED(hr))
        {
            hr = DirectX::CreateShaderResourceView(m_Device.Get(), imageobj->GetImages(), imageobj->GetImageCount(), metadata, textureView.GetAddressOf());
            if (SUCCEEDED(hr))
            {
                m_TextureViews.insert(std::make_pair(filePath, textureView));
                return textureView;
            }
        }
    }
    hr = DirectX::GetMetadataFromWICFile(filePath.c_str(), DirectX::WIC_FLAGS_NONE, metadata);
    if (SUCCEEDED(hr))
    {
        hr = DirectX::LoadFromWICFile(filePath.c_str(), DirectX::WIC_FLAGS_NONE, &metadata, *imageobj);
        if (SUCCEEDED(hr))
        {
            hr = DirectX::CreateShaderResourceView(m_Device.Get(), imageobj->GetImages(), imageobj->GetImageCount(), metadata, textureView.GetAddressOf());
            if (SUCCEEDED(hr))
            {
                m_TextureViews.insert(std::make_pair(filePath, textureView));
                return textureView;
            }
        }
    }
    hr = DirectX::GetMetadataFromTGAFile(filePath.c_str(), DirectX::TGA_FLAGS_NONE, metadata);
    if (SUCCEEDED(hr))
    {
        hr = DirectX::LoadFromTGAFile(filePath.c_str(), DirectX::TGA_FLAGS_NONE, &metadata, *imageobj);
        if (SUCCEEDED(hr))
        {
            hr = DirectX::CreateShaderResourceView(m_Device.Get(), imageobj->GetImages(), imageobj->GetImageCount(), metadata, textureView.GetAddressOf());
            if (SUCCEEDED(hr))
            {
                m_TextureViews.insert(std::make_pair(filePath, textureView));
                return textureView;
            }
        }
    }
    return nullptr;
}

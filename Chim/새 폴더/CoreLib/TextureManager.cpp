#include "TextureManager.h"

bool Texture::Load(std::wstring fileName, ID3D11Device* pDevice)
{
    auto imageobj = std::make_unique<DirectX::ScratchImage>();
    DirectX::TexMetadata mdata;

    // load dds Texture file
    HRESULT hr = DirectX::GetMetadataFromDDSFile(fileName.c_str(), DirectX::DDS_FLAGS_NONE, mdata);
    if (SUCCEEDED(hr))
    {
        hr = DirectX::LoadFromDDSFile(fileName.c_str(), DirectX::DDS_FLAGS_NONE, &mdata, *imageobj);
        if (SUCCEEDED(hr))
        {
            hr = DirectX::CreateShaderResourceView(pDevice, imageobj->GetImages(), imageobj->GetImageCount(), mdata, &pTextureSRV);
            if (SUCCEEDED(hr))
                return true;
            else
                ShowErrorMessage(hr);
        }
        else
            ShowErrorMessage(hr);
    }

    // load png, jpg, etc Texture file
    hr = DirectX::GetMetadataFromWICFile(fileName.c_str(), DirectX::WIC_FLAGS_NONE, mdata);
    if (SUCCEEDED(hr))
    {
        hr = DirectX::LoadFromWICFile(fileName.c_str(), DirectX::WIC_FLAGS_NONE, &mdata, *imageobj);
        if (SUCCEEDED(hr))
        {
            hr = DirectX::CreateShaderResourceView(pDevice, imageobj->GetImages(), imageobj->GetImageCount(), mdata, &pTextureSRV);
            if (SUCCEEDED(hr))
                return true;
            else
                ShowErrorMessage(hr);
        }
        else
            ShowErrorMessage(hr);
    }

    // load tga Texture file
    hr = DirectX::GetMetadataFromTGAFile(fileName.c_str(), DirectX::TGA_FLAGS_NONE, mdata);
    if (SUCCEEDED(hr))
    {
        hr = DirectX::LoadFromTGAFile(fileName.c_str(), DirectX::TGA_FLAGS_NONE, &mdata, *imageobj);
        if (SUCCEEDED(hr))
        {
            hr = DirectX::CreateShaderResourceView(pDevice, imageobj->GetImages(), imageobj->GetImageCount(), mdata, &pTextureSRV);
            if (SUCCEEDED(hr))
                return true;
            else
                ShowErrorMessage(hr);
        }
        else
            ShowErrorMessage(hr);
    }

    return false;
}

bool Texture::Render(ID3D11DeviceContext* pContext) const
{
    pContext->PSSetShaderResources(0, 1, &pTextureSRV);

    return true;
}

bool Texture::Release()
{
    if (pTextureSRV)pTextureSRV->Release();
    pTextureSRV = nullptr;

    return true;
}
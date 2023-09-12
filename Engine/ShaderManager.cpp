#include "pch.h"
#include "ShaderManager.h"

void  ShaderManager::GetDevice(ComPtr<ID3D11Device> device)
{
    m_Device = device;
}

std::pair<ComPtr<ID3D11VertexShader>, ComPtr<ID3DBlob>> ShaderManager::GetVSAndVertexShaderCode(const std::wstring& filepath)
{
    std::wstring key = std::filesystem::path(filepath).filename().wstring();

    auto iter = m_VertexShadersAndShaderCodes.find(key);
    if (iter != m_VertexShadersAndShaderCodes.end())
    {
        return iter->second;
    }

    ComPtr<ID3DBlob> ErrorCode;
    ComPtr<ID3DBlob> VertexShaderCode;
    ComPtr<ID3D11VertexShader> VS;
    HRESULT hr = D3DCompileFromFile(filepath.c_str(), nullptr, nullptr, "VS", "vs_5_0", 0, 0, VertexShaderCode.GetAddressOf(), ErrorCode.GetAddressOf());
    ASSERT_HR(hr);

    hr = m_Device->CreateVertexShader(VertexShaderCode->GetBufferPointer(), VertexShaderCode->GetBufferSize(), nullptr, VS.GetAddressOf());
    ASSERT_HR(hr);

    m_VertexShadersAndShaderCodes.insert(std::make_pair(filepath, std::make_pair(VS, VertexShaderCode)));
    return std::make_pair(VS, VertexShaderCode);
}

ComPtr<ID3D11PixelShader> ShaderManager::GetPS(const std::wstring& filepath)
{
    std::wstring key = std::filesystem::path(filepath).filename().wstring();

    auto iter = m_PixelShaders.find(key);
    if (iter != m_PixelShaders.end())
    {
        return iter->second;
    }

    ComPtr<ID3DBlob> ErrorCode;
    ComPtr<ID3DBlob> PixelShaderCode;
    ComPtr<ID3D11PixelShader> PS;
    HRESULT hr = D3DCompileFromFile(filepath.c_str(), nullptr, nullptr, "PS", "ps_5_0", 0, 0, PixelShaderCode.GetAddressOf(), ErrorCode.GetAddressOf());
    ASSERT_HR(hr);

    hr = m_Device->CreatePixelShader(PixelShaderCode->GetBufferPointer(), PixelShaderCode->GetBufferSize(), nullptr, PS.GetAddressOf());
    ASSERT_HR(hr);

    m_PixelShaders.insert(std::make_pair(filepath, PS));
    return PS;
}

#include "ShaderManager.h"

bool Shader::LoadShader(ShaderType type, std::wstring fileName, ID3D11Device* pDevice)
{
    std::string shaderFunctionName, shaderVersion;
    ID3DBlob* errorBlob = nullptr;
    ID3DBlob** shaderBlob = nullptr;

    // set shader function and version, blob
    switch (type)
    {
    case ShaderType::VertexShader:
        shaderFunctionName = "VS";
        shaderVersion = "vs_5_0";
        shaderBlob = &pVertexShaderCode;
        break;
    case ShaderType::PixelShader:
        shaderFunctionName = "PS";
        shaderVersion = "ps_5_0";
        shaderBlob = &pPixelShaderCode;
        break;
    }

    // for graphics debugging
    UINT flags = 0;
#ifdef _DEBUG
    flags = D3DCOMPILE_DEBUG;
    flags |= D3DCOMPILE_SKIP_OPTIMIZATION;
#endif

    HRESULT hr = D3DCompileFromFile(
        fileName.c_str(),
        nullptr,
        nullptr,
        shaderFunctionName.c_str(),
        shaderVersion.c_str(),
        flags,
        0,
        shaderBlob,
        &errorBlob);

    if (FAILED(hr))
    {
        ShowErrorMessage(hr, errorBlob);
        return false;
    }

    switch (type)
    {
    case ShaderType::VertexShader:
        hr = pDevice->CreateVertexShader(
            (*shaderBlob)->GetBufferPointer(),
            (*shaderBlob)->GetBufferSize(),
            nullptr,
            &pVertexShader);
        break;
    case ShaderType::PixelShader:
        hr = pDevice->CreatePixelShader(
            (*shaderBlob)->GetBufferPointer(),
            (*shaderBlob)->GetBufferSize(),
            nullptr,
            &pPixelShader);
        break;
    default:
        break;
    }

    if (FAILED(hr))
    {
        ShowErrorMessage(hr);
        return false;
    }

    return true;
}

bool Shader::Load(std::wstring fileName, ID3D11Device* pDevice)
{
    LoadShader(ShaderType::VertexShader, fileName, pDevice);
    LoadShader(ShaderType::PixelShader, fileName, pDevice);
    CreateInputLayout(pDevice);

    return true;
}

bool Shader::Render(ID3D11DeviceContext* pContext, std::vector<Vertex>& vertices) const
{
    pContext->IASetInputLayout(pVertexLayout);           // bind input layout to input assembler stage pipeline

    pContext->VSSetShader(pVertexShader, NULL, 0);
    pContext->PSSetShader(pPixelShader, NULL, 0);

    pContext->HSSetShader(pHS, NULL, 0);
    pContext->DSSetShader(pDS, NULL, 0);
    pContext->CSSetShader(pCS, NULL, 0);
    pContext->GSSetShader(pGS, NULL, 0);

    return true;
}

bool Shader::Release()
{
    if (pVertexLayout) pVertexLayout->Release();
    if (pVertexShaderCode) pVertexShaderCode->Release();
    if (pPixelShaderCode) pPixelShaderCode->Release();
    if (pVertexShader) pVertexShader->Release();
    if (pPixelShader) pPixelShader->Release();
    if (pDS) pDS->Release();
    if (pHS) pHS->Release();
    if (pGS) pGS->Release();
    if (pCS) pCS->Release();

    pVertexShaderCode = nullptr;
    pPixelShaderCode = nullptr;
    pVertexShader = nullptr;
    pPixelShader = nullptr;
    pDS = nullptr;
    pHS = nullptr;
    pGS = nullptr;
    pCS = nullptr;

    return true;
}

bool Shader::CreateInputLayout(ID3D11Device* pDevice)
{
    // D3D11_INPUT_ELEMENT_DESC is description of vertex struct data
    D3D11_INPUT_ELEMENT_DESC layout[] = {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "NORMAL" , 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0},
        { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 24, D3D11_INPUT_PER_VERTEX_DATA, 0},
        { "TEXTURE", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 40, D3D11_INPUT_PER_VERTEX_DATA, 0 },

        // semantic name, semantic index, format, input slot, aligned byte offset, input slot class, instance data step rate
    };

    int size = sizeof(layout) / sizeof(layout[0]);

    HRESULT hr = pDevice->CreateInputLayout(
        layout,
        size,
        pVertexShaderCode->GetBufferPointer(),
        pVertexShaderCode->GetBufferSize(),
        &pVertexLayout);

    if (FAILED(hr))
    {
        ShowErrorMessage(hr);
        return false;
    }

    return true;
}

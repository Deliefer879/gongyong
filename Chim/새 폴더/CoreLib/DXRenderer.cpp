#include "DXRenderer.h"

bool DXRenderer::CreateVertexBuffer(ID3D11Device* pDevice)
{
    // set vertex data (vertices will be move by matrix)

    if (vertices.size() < 1)
    {
        vertices.resize(4);

        vertices[0].tex.x = 0.0f; vertices[0].tex.y = 0.0f;
        vertices[1].tex.x = 1.0f; vertices[1].tex.y = 0.0f;
        vertices[2].tex.x = 0.0f; vertices[2].tex.y = 1.0f;
        vertices[3].tex.x = 1.0f; vertices[3].tex.y = 1.0f;

        vertices[0].pos.x = -1; vertices[0].pos.y = 1;  vertices[0].pos.z = 0.0f;
        vertices[1].pos.x = 1;  vertices[1].pos.y = 1;  vertices[1].pos.z = 0.0f;
        vertices[2].pos.x = -1; vertices[2].pos.y = -1; vertices[2].pos.z = 0.0f;
        vertices[3].pos.x = 1;  vertices[3].pos.y = -1;  vertices[3].pos.z = 0.0f;

        vertices[0].normal = { 0,1,0 };
        vertices[1].normal = { 0,1,0 };
        vertices[2].normal = { 0,1,0 }; 
        vertices[3].normal = { 0,1,0 };

        vertices[0].color = { 1,1,1,1 };
        vertices[1].color = { 1,1,1,1 };
        vertices[2].color = { 1,1,1,1 };
        vertices[3].color = { 1,1,1,1 };
    }
    // set vertex data

    D3D11_BUFFER_DESC desc;
    ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));

    desc.Usage = D3D11_USAGE_DEFAULT;
    desc.ByteWidth = sizeof(Vertex) * vertices.size();
    desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    D3D11_SUBRESOURCE_DATA subResource;
    subResource.pSysMem = &vertices.at(0);

    HRESULT hr = pDevice->CreateBuffer(&desc, &subResource, &pVertexBuffer);
    if (FAILED(hr))
    {
        ShowErrorMessage(hr);
        return false;
    }

    return true;
}

bool DXRenderer::CreateIndexBuffer(ID3D11Device* pDevice)
{
    // set index data
    if (indices.size() < 1)
    {
        indices.resize(6);

        indices[0] = 0;
        indices[1] = 1;
        indices[2] = 2;
        indices[3] = 2;
        indices[4] = 1;
        indices[5] = 3;
    }
    // set index data

    D3D11_BUFFER_DESC desc;
    ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));

    desc.Usage = D3D11_USAGE_IMMUTABLE;
    desc.ByteWidth = sizeof(UINT) * indices.size();
    desc.BindFlags = D3D11_BIND_INDEX_BUFFER;

    D3D11_SUBRESOURCE_DATA subResource;
    subResource.pSysMem = &indices.at(0);

    HRESULT hr = pDevice->CreateBuffer(&desc, &subResource, &pIndexBuffer);
    if (FAILED(hr))
    {
        ShowErrorMessage(hr);
        return false;
    }

    return true;
}

bool DXRenderer::CreateConstantBuffer(ID3D11Device* pDevice)
{
	D3D11_BUFFER_DESC desc;
	ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));

	desc.Usage = D3D11_USAGE_DEFAULT;
	desc.ByteWidth = sizeof(CB_Data);
	desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;

	HRESULT hr = pDevice->CreateBuffer(&desc, nullptr, &pConstantBuffer);
    if (FAILED(hr))
    {
		ShowErrorMessage(hr);
		return false;
	}
	return true;
}

//disable backface culling
//Add the following code inside the DXRenderer class, after the DXRenderer constructor

void DXRenderer::DisableBackfaceCulling(ID3D11Device* pDevice)
{
    ID3D11RasterizerState* rsState;

    ID3D11DeviceContext* pContext;
    pDevice->GetImmediateContext(&pContext);

    D3D11_RASTERIZER_DESC wfdesc;
    ZeroMemory(&wfdesc, sizeof(D3D11_RASTERIZER_DESC));
    wfdesc.FillMode = D3D11_FILL_SOLID;
    wfdesc.CullMode = D3D11_CULL_NONE;
    HRESULT hr = pDevice->CreateRasterizerState(&wfdesc, &rsState);

    if (FAILED(hr))
        ShowErrorMessage(hr);

    pContext->RSSetState(rsState);
}
//disable backface culling

void DXRenderer::SetCBData(Matrix& worldMatrix, Matrix& viewMatrix, Matrix& projMatrix)
{
    cbData.worldMatrix = worldMatrix.Transpose();
	cbData.viewMatrix = viewMatrix.Transpose();
	cbData.projMatrix = projMatrix.Transpose();
    cbData.color = { 1, 1, 1, 1 };
}

void DXRenderer::SetResource(std::wstring texFileName, std::wstring shaFileName)
{
    shader = ShaderManager::GetInstance().Load(shaFileName);
    texture = TextureManager::GetInstance().Load(texFileName);
}

bool DXRenderer::Init(ID3D11Device* pDevice)
{
    CreateVertexBuffer(pDevice);
    CreateIndexBuffer(pDevice);
    CreateConstantBuffer(pDevice);

    return true;
}

bool DXRenderer::Frame()
{
    return true;
}

bool DXRenderer::Render(ID3D11DeviceContext* pContext)
{
    pContext->UpdateSubresource(pConstantBuffer, 0, nullptr, &cbData, 0, 0);
    pContext->VSSetConstantBuffers(0, 1, &pConstantBuffer);

    shader.Render(pContext, vertices);
    texture.Render(pContext);

    UINT stride = sizeof(Vertex);   // size of vertexBuffer element
    UINT offset = 0;                // vertex buffer start offset

    pContext->IASetVertexBuffers(0, 1, &pVertexBuffer, &stride, &offset); // bind vertex buffer to input assembler stage pipeline
    pContext->IASetIndexBuffer(pIndexBuffer, DXGI_FORMAT_R32_UINT, 0);    // bind index buffer to input assembler stage pipeline)
    pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST); // bind information about primitive topology to input assembler stage pipeline
    pContext->DrawIndexed(indices.size(), 0, 0); // draw vertex buffer

    return true;
}

bool DXRenderer::Release()
{
    if (pVertexBuffer) pVertexBuffer->Release();
    if (pIndexBuffer) pIndexBuffer->Release();

    return true;
}

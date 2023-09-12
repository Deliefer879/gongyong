#include "pch.h"
#include "UActorComponent.h"

void UPrimitiveComponent::Render()
{

}

UPrimitiveComponent::UPrimitiveComponent(const std::wstring& shaderFile, const std::wstring& TextureFile, XMFLOAT3& pos, XMFLOAT3& scale, XMFLOAT3& rotation)
{
    m_ShaderFileName = shaderFile;
    m_TextureFileName = TextureFile;
    m_PositionVector = pos;
    m_ScaleVector = scale;
    m_RotationVector = rotation;

    SetAABB({ pos.x, pos.y, scale.x, scale.y });
    CreateConstantBuffer();
    CreateVertexBuffer();
    auto VertexShaderCode = GetShaderManager().GetVSAndVertexShaderCode(m_ShaderFileName).second;
    CreateInputLayout(VertexShaderCode);
    UpdateWorldMatrix();
    SetPipelineState();
}

void UPrimitiveComponent::GetDevice(ComPtr<ID3D11Device> device, ComPtr<ID3D11DeviceContext> context)
{
    m_Device = device;
    m_ImmediateContext = context;
}

void UPrimitiveComponent::CreateInputLayout(ComPtr<ID3DBlob> VertexShaderCode)
{
    const D3D11_INPUT_ELEMENT_DESC layout[] =
    {
        { "POSITION",  0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,  D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "TEXCOORD0",  0, DXGI_FORMAT_R32G32_FLOAT, 0, 12,  D3D11_INPUT_PER_VERTEX_DATA, 0 }
    };
    UINT iNumCount = sizeof(layout) / sizeof(layout[0]);

    if (!m_ShaderFileName.empty())
    {
        HRESULT hr = m_Device->CreateInputLayout(
            layout,
            iNumCount,
            VertexShaderCode->GetBufferPointer(),
            VertexShaderCode->GetBufferSize(),
            m_InputLayout.GetAddressOf());
        ASSERT_HR(hr);
    }
}

void UPrimitiveComponent::CreateVertexBuffer()
{
    m_Vertices.resize(6);
    m_Vertices[0].UV.x = 0.0f; m_Vertices[0].UV.y = 0.0f;
    m_Vertices[1].UV.x = 1.0f; m_Vertices[1].UV.y = 0.0f;
    m_Vertices[2].UV.x = 0.0f; m_Vertices[2].UV.y = 1.0f;
    m_Vertices[3].UV.x = 0.0f; m_Vertices[3].UV.y = 1.0f;
    m_Vertices[4].UV.x = 1.0f; m_Vertices[4].UV.y = 0.0f;
    m_Vertices[5].UV.x = 1.0f; m_Vertices[5].UV.y = 1.0f;
    // 정사각형
    m_Vertices[0].Position.x = -1.0f; m_Vertices[0].Position.y = 1.0f;  m_Vertices[0].Position.z = 0.0f;
    m_Vertices[1].Position.x = 1.0f; m_Vertices[1].Position.y = 1.0f;  m_Vertices[1].Position.z = 0.0f;
    m_Vertices[2].Position.x = -1.0f; m_Vertices[2].Position.y = -1.0f;  m_Vertices[2].Position.z = 0.0f;
    m_Vertices[3] = m_Vertices[2];
    m_Vertices[4] = m_Vertices[1];
    m_Vertices[5].Position.x = 1.0f; m_Vertices[5].Position.y = -1.0f;  m_Vertices[5].Position.z = 0.0f;

    D3D11_BUFFER_DESC Desc{};
    Desc.ByteWidth = sizeof(Vertex) * m_Vertices.size();
    Desc.Usage = D3D11_USAGE_DEFAULT;
    Desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    D3D11_SUBRESOURCE_DATA InitialData{};
    InitialData.pSysMem = &m_Vertices.at(0);

    HRESULT hr = m_Device->CreateBuffer(&Desc, &InitialData, m_VertexBuffer.GetAddressOf());
    ASSERT_HR(hr);
}

void UPrimitiveComponent::CreateConstantBuffer()
{
    D3D11_BUFFER_DESC Desc{};
    Desc.ByteWidth = sizeof(ConstBufferDesc);
    Desc.Usage = D3D11_USAGE_DEFAULT;
    Desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;

    HRESULT hr = m_Device->CreateBuffer(
        &Desc,
        nullptr,
        m_ConstBuffer.GetAddressOf());
    ASSERT_HR(hr);
}

void UPrimitiveComponent::UpdateTransformationMatrices(const XMMATRIX* matWorld, const XMMATRIX* matView, const XMMATRIX* matProj)
{
    // Update matrices if provided
    if (matWorld != nullptr)
        m_WorldMatrix = *matWorld;
    if (matView != nullptr)
        m_ViewMatrix = *matView;
    if (matProj != nullptr)
        m_ProjMatrix = *matProj;

    // Transpose matrices for shader compatibility | Update constant buffer data
    m_ConstBufferData.WorldMatrix = XMMatrixTranspose(m_WorldMatrix);
    m_ConstBufferData.ViewMatrix = XMMatrixTranspose(m_ViewMatrix);
    m_ConstBufferData.ProjMatrix = XMMatrixTranspose(m_ProjMatrix);

    // Update the constant buffer resource
    m_ImmediateContext->UpdateSubresource(m_ConstBuffer.Get(), 0, nullptr, &m_ConstBufferData, 0, 0);
}

void UPrimitiveComponent::UpdateWorldMatrix()
{
    m_WorldMatrix = XMMatrixIdentity();

    XMVECTOR vScale = XMLoadFloat3(&m_ScaleVector);
    XMVECTOR vRotation = XMLoadFloat3(&m_RotationVector);
    XMVECTOR vPosition = XMLoadFloat3(&m_PositionVector);

    XMMATRIX matScale = XMMatrixScalingFromVector(vScale);
    XMMATRIX matRotation = XMMatrixRotationRollPitchYawFromVector(vRotation);
    XMMATRIX matTranslate = XMMatrixTranslationFromVector(vPosition);

    m_WorldMatrix = matScale * matRotation * matTranslate;
}

void UPrimitiveComponent::SetPipelineState()
{
    m_ImmediateContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    m_ImmediateContext->VSSetConstantBuffers(0, 1, m_ConstBuffer.GetAddressOf());

    if (!m_TextureFileName.empty()) {
        auto SRV = GetTextureManager().GetTextureView(m_TextureFileName);
        m_ImmediateContext->PSSetShaderResources(0, 1,SRV.GetAddressOf()); // 0 is the first slot
    }

    if (!m_ShaderFileName.empty()) {
        auto VS = GetShaderManager().GetVSAndVertexShaderCode(m_ShaderFileName).first;
        auto PS = GetShaderManager().GetPS(m_ShaderFileName);
        m_ImmediateContext->VSSetShader(VS.Get(), nullptr, 0);
        m_ImmediateContext->IASetInputLayout(m_InputLayout.Get());
        m_ImmediateContext->PSSetShader(PS.Get(), nullptr, 0);
    }

    const UINT stride = sizeof(Vertex);
    const UINT offset = 0;
    m_ImmediateContext->IASetVertexBuffers(0, 1, m_VertexBuffer.GetAddressOf(), &stride, &offset);
}

void UPrimitiveComponent::Draw()
{
    m_ImmediateContext->Draw(m_Vertices.size(), 0);
}


//=================================================================================================
// UOrthoCameraComponent
void UOrthoCameraComponent::TickComponent(float deltaTime)
{
    //float fHalfWidth = ViewX / 2.0f;
    //float fHalfHeight = ViewY / 2.0f;
    //if (CameraPos.x < -(g_fMapHalfSizeX)+fHalfWidth)
    //{
    //    CameraPos.x = -(g_fMapHalfSizeX)+fHalfWidth;
    //}
    //if (CameraPos.y < -(g_fMapHalfSizeY)+fHalfHeight)
    //{
    //    CameraPos.y = -(g_fMapHalfSizeY)+fHalfHeight;
    //}
    //if (CameraPos.x > (g_fMapHalfSizeX) -fHalfWidth)
    //{
    //    CameraPos.x = (g_fMapHalfSizeX)-fHalfWidth;
    //}
    //if (CameraPos.y > (g_fMapHalfSizeY)-fHalfHeight)
    //{
    //    CameraPos.y = (g_fMapHalfSizeY)-fHalfHeight;
    //}

    //matView._41 = -CameraPos.x;
    //matView._42 = -CameraPos.y;
    //matView._43 = -CameraPos.z;
    //matOrthoProjection._11 = 2.0f / ((float)ViewX);
    //matOrthoProjection._22 = 2.0f / ((float)ViewY);
}

void UOrthoCameraComponent::Render()
{
}

void UOrthoCameraComponent::SetPosition(XMFLOAT3 xyz)
{
    m_Position = xyz;
    UpdateViewMatrix();
}

void UOrthoCameraComponent::SetRotation(XMFLOAT3 pitchYawRoll)
{
    m_Rotation = pitchYawRoll;
    UpdateViewMatrix();
}

void UOrthoCameraComponent::UpdateViewMatrix()
{
    // Compute rotation matrix
    XMVECTOR rotationQuat = XMQuaternionRotationRollPitchYaw(m_Rotation.x, m_Rotation.y, m_Rotation.z);

    // Compute translation vector
    XMVECTOR translationVec = XMLoadFloat3(&m_Position);

    // Create view matrix from rotation and translation
    XMMATRIX viewMatrix = XMMatrixAffineTransformation(XMVectorSet(1.0f, 1.0f, 1.0f, 1.0f), XMVectorZero(), rotationQuat, translationVec);

    // Store view matrix
    XMStoreFloat4x4(&m_ViewMatrix, viewMatrix);
}

void UOrthoCameraComponent::UpdateProjectionMatrix()
{
    // Create orthographic projection matrix
    XMMATRIX projectionMatrix = XMMatrixOrthographicLH(m_Width, m_Height, m_NearZ, m_FarZ);

    // Store projection matrix
    XMStoreFloat4x4(&m_ProjectionMatrix, projectionMatrix);
}



//
//void ASpriteUV::InitThis(SpriteDesc& desc)
//{
//    Sprite = std::move(desc);
//
//    GetDevice(g_pDevice, g_pContext);
//    SetPos(Sprite.Position);
//    SetScale(Sprite.scale);
//
//    // 알파텍스처가 있다면 로드
//    if (!Sprite.AlphaTextureFileName.empty())
//    {
//        Sprite.AlphaTexture = TEXTURE_MANAGER.LoadTextureFile(Sprite.AlphaTextureFileName);
//    }
//
//    //SetUVFrameFromSprite
//    UVFrame uvFrame;
//    TVector2 UV;
//
//    float offsetX = 1.0f / Sprite.ColumnCount;
//    float offsetY = 1.0f / Sprite.RowCount;
//    for (int row = 0; row < Sprite.RowCount; row++)
//    {
//        UV.y = offsetY * row;
//        for (int column = 0; column < Sprite.ColumnCount; column++)
//        {
//            UV.x = offsetX * column;
//            uvFrame.m_Min = UV;
//            uvFrame.m_Max.x = UV.x + offsetX;
//            uvFrame.m_Max.y = UV.y + offsetY;
//            UVFrameList.push_back(uvFrame);
//        }
//    }
//    Sprite.OffsetTime = Sprite.TotalAnimTimeInSecond / UVFrameList.size();
//
//    SetupGraphicsPipeline();
//    Init();
//}
//bool ASpriteUV::Init()
//{
//    AActor::Init();
//    return true;
//}
//bool ASpriteUV::TickComponent()
//{
//    AActor::TickComponent();
//    Sprite.ElapsedTime += g_DeltaTime;
//    if (Sprite.ElapsedTime >= Sprite.OffsetTime)
//    {
//        Sprite.CurrentAnimFrameIndex++;
//        if (Sprite.CurrentAnimFrameIndex >= UVFrameList.size())
//        {
//            Sprite.CurrentAnimFrameIndex = 0;
//        }
//        Sprite.ElapsedTime -= Sprite.OffsetTime;
//    }
//    return true;
//}
//bool ASpriteUV::Render()
//{
//    UVFrame UV = UVFrameList[Sprite.CurrentAnimFrameIndex];
//    m_Vertices[0].UV = UV.m_Min;
//    m_Vertices[1].UV.x = UV.m_Max.x;
//    m_Vertices[1].UV.y = UV.m_Min.y;
//
//    m_Vertices[2].UV.x = UV.m_Min.x;
//    m_Vertices[2].UV.y = UV.m_Max.y;
//    m_Vertices[3].UV = m_Vertices[2].UV;
//
//    m_Vertices[4].UV = m_Vertices[1].UV;
//    m_Vertices[5].UV = UV.m_Max;
//
//    m_ImmediateContext->UpdateSubresource(m_pVertexBuffer, 0, nullptr, &m_Vertices.at(0), 0, 0);
//
//    PreRender();
//    if (Sprite.AlphaTexture)
//    {
//        Sprite.AlphaTexture->BindToPipeline(m_ImmediateContext, 1);
//    }
//    PostRender();
//    return true;
//}
//bool ASpriteUV::Release()
//{
//    AActor::Release();
//    return true;
//}
//ASpriteUV::~ASpriteUV()
//{
//    Release();
//}

#pragma once
#include "TextureManager.h"
#include "ShaderManager.h"
class IUActorComponent
{
public:
    virtual void TickComponent(float deltaTime) = 0;
};


class USceneComponent : public IUActorComponent
{
public:
    virtual void TickComponent(float deltaTime) override {}

public:
    void SetPosition(const XMFLOAT3& pos) { m_PositionVector = pos; }
    void SetScale(const XMFLOAT3& scale) { m_ScaleVector = scale; }
    void SetRotation(const XMFLOAT3& rot) { m_RotationVector = rot; }
    void SetAABB(const Util::Rect& rect) { m_AABB = rect; }

protected:
    XMFLOAT3    m_PositionVector;
    XMFLOAT3    m_ScaleVector;
    XMFLOAT3    m_RotationVector;
    Util::Rect  m_AABB;
};


class UPrimitiveComponent : public USceneComponent
{
    struct ConstBufferDesc
    {
        XMMATRIX WorldMatrix;
        XMMATRIX ViewMatrix;
        XMMATRIX ProjMatrix;
    };
    struct Vertex
    {
        XMFLOAT4 Position;
        XMFLOAT2 UV;
    };
public:
    virtual void TickComponent(float deltaTime) override {}
    virtual void Render();
    UPrimitiveComponent(const std::wstring& shaderFile, const std::wstring& TextureFile, XMFLOAT3& pos, XMFLOAT3& scale, XMFLOAT3& rotation);

    void GetDevice(ComPtr<ID3D11Device> device, ComPtr<ID3D11DeviceContext> context);
    void UpdateTransformationMatrices(const XMMATRIX* matWorld, const XMMATRIX* matView, const XMMATRIX* matProj);
    void UpdateWorldMatrix();
    void SetPipelineState();
    void Draw();

protected:
    void CreateConstantBuffer();
    void CreateInputLayout(ComPtr<ID3DBlob> VertexShaderCode);
    void CreateVertexBuffer();

    ComPtr<ID3D11Device>        m_Device;
    ComPtr<ID3D11DeviceContext> m_ImmediateContext;
    ComPtr<ID3D11Buffer>        m_VertexBuffer;
    ComPtr<ID3D11Buffer>        m_ConstBuffer;
    ComPtr<ID3D11InputLayout>   m_InputLayout;
    ConstBufferDesc             m_ConstBufferData;
    std::vector<Vertex>         m_Vertices;
    std::wstring                m_ShaderFileName;
    std::wstring                m_TextureFileName;
    XMMATRIX                    m_WorldMatrix;
    XMMATRIX                    m_ViewMatrix;
    XMMATRIX                    m_ProjMatrix;
};


//class USpriteComponent : public UPrimitiveComponent
//{
//    struct SpriteDesc
//    {
//        // required
//        WSTR		TextureName;
//        WSTR		ShaderFileName;
//        XMFLOAT3	Position;
//        XMFLOAT3	scale;
//        int			RowCount;
//        int			ColumnCount;
//        float		TotalAnimTimeInSecond;
//        // optional
//        WSTR		    AlphaTextureFileName;
//        const Texture* AlphaTexture = nullptr;
//        std::vector<std::wstring> TextureFileNameList;
//        // dont touch
//        float		ElapsedTime = 0.f;
//        float		OffsetTime = 0.f;
//        int			CurrentAnimFrameIndex = 0;
//    };
//    struct UVFrame
//    {
//        TVector2 m_Min;
//        TVector2 m_Max;
//    };
//public:
//    virtual void TickComponent(float deltaTime) override {}
//    USpriteComponent() = delete;
//protected:
//    SpriteDesc				Sprite;
//    std::vector<UVFrame>	UVFrameList;
//
//public:
//    void InitThis(SpriteDesc& desc);
//
//    bool Init() override;
//    bool TickComponent() override;
//    bool Render() override;
//    bool Release() override;
//};


class UOrthoCameraComponent : public IUActorComponent
{
public:
    virtual void TickComponent(float deltaTime) override;
    virtual void Render();

    UOrthoCameraComponent(float width, float height, float nearZ, float farZ)
        : m_Width(width), m_Height(height), m_NearZ(nearZ), m_FarZ(farZ),
        m_Position(0.0f, 0.0f, 0.0f), m_Rotation(0.0f, 0.0f, 0.0f)
    {
        UpdateViewMatrix();
        UpdateProjectionMatrix();
    }

public:
    void SetPosition(XMFLOAT3 xyz);
    void SetRotation(XMFLOAT3 pitchYawRoll);
    void UpdateViewMatrix();
    void UpdateProjectionMatrix();

protected:
    float m_Width;
    float m_Height;
    float m_NearZ;
    float m_FarZ;
    XMFLOAT3 m_Position;
    XMFLOAT3 m_Rotation;
    XMFLOAT4X4 m_ViewMatrix;
    XMFLOAT4X4 m_ProjectionMatrix;
};
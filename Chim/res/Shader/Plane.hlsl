// ------------------ Vertex Shader ------------------

struct VS_IN
{
    float4 Position : POSITION;
    float3 normal : NORMAL;
    float4 color : COLOR;
    float2 Texture : TEXTURE;
};

struct VS_OUT
{
    float4 Position : SV_POSITION;
    float3 normal : NORMAL;
    float4 color : COLOR;
    float2 Texture : TEXTURE;
};

cbuffer cb0 // constant buffer is not have to be set register (automatic)
{
    matrix matWorld : packoffset(c0); // packoffset is not have to be set register (automatic)
    matrix matView : packoffset(c4);  // float4x4 is 4 float4 so it's 16 bytes so it's 4 register
    matrix matProj : packoffset(c8);
    float4 meshColor : packoffset(c12);
};

VS_OUT VS(VS_IN vIn) // SV_ is system value so you can't change it
{ 
    VS_OUT vOut = (VS_OUT) 0;
    
    float4 vWorld = mul(vIn.Position, matWorld); // mul is cross product but it's not row * column it's rot * row 
    float4 vView = mul(vWorld, matView);         // so we have to set matrix to transposed matrix before set to shader
    float4 vProj = mul(vView, matProj);
    
    vOut.Position = vProj;
    vOut.Texture = vIn.Texture;
    vOut.color = vIn.color * meshColor;
    vOut.normal = vIn.normal;
    
    return vOut;
}

// ------------------ Pixel Shader ------------------

Texture2D g_txDiffuse1 : register(t0);
SamplerState sample0 : register(s0);

float4 PS(VS_OUT pIn) : SV_Target
{
    return g_txDiffuse1.Sample(sample0, pIn.Texture) * pIn.color;
}
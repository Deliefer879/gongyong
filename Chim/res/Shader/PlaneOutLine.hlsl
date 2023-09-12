// ------------------ Vertex Shader ------------------

struct VS_IN
{
    float4 Position : POSITION;
};

struct VS_OUT
{
    float4 Position : SV_POSITION;
};

cbuffer cb0 // constant buffer is not have to be set register (automatic)
{
    matrix matWorld : packoffset(c0); // packoffset is not have to be set register (automatic)
    matrix matView : packoffset(c4);  // float4x4 is 4 float4 so it's 16 bytes so it's 4 register
    matrix matProj : packoffset(c8);
};

VS_OUT VS(VS_IN vIn) // SV_ is system value so you can't change it
{ 
    VS_OUT vOut = (VS_OUT) 0;
    
    float4 vWorld = mul(vIn.Position, matWorld); // mul is cross product but it's not row * column it's rot * row 
    float4 vView = mul(vWorld, matView);         // so we have to set matrix to transposed matrix before set to shader
    float4 vProj = mul(vView, matProj);
    
    vOut.Position = vProj;
    
    return vOut;
}

// ------------------ Pixel Shader ------------------

struct PS_IN
{
    float4 Position : SV_POSITION;
};;

float4 PS(PS_IN pIn) : SV_Target
{
    return (0,1,0,0);
}
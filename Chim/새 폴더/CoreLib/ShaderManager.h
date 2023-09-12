#pragma once

#include "ResourceManager.hpp"

enum class ShaderType
{
	VertexShader,
	PixelShader
};

struct Vertex
{
	Vector3 pos;
	Vector3 normal;
	Vector4 color;
	Vector2 tex;
};

class Shader
{
private:
	ID3D11InputLayout* pVertexLayout = nullptr;		    // interface for input layout
	ID3D11VertexShader* pVertexShader = nullptr;	    // interface for vertex shader   (handle vertex shader code)
	ID3D11PixelShader* pPixelShader = nullptr;		    // interface for pixel shader	(handle pixel shader code)
	ID3D11HullShader* pHS = nullptr;
	ID3D11DomainShader* pDS = nullptr;
	ID3D11ComputeShader* pCS = nullptr;
	ID3D11GeometryShader* pGS = nullptr;
	ID3DBlob* pVertexShaderCode = nullptr;			    // interface for vertex shader blob (blob is used for return randomly length data)
	ID3DBlob* pPixelShaderCode = nullptr;			    // interface for pixel shader blob (blob is used for return randomly length data)
private:
	bool CreateInputLayout(ID3D11Device* pDevice);
	bool LoadShader(ShaderType type, std::wstring fileName, ID3D11Device* pDevice);
public:

	bool Load(std::wstring fileName, ID3D11Device* pDevice);
	bool Render(ID3D11DeviceContext* pContext, std::vector<Vertex>& vertices) const;
	bool Release();
};

class ShaderManager : public ResourceManager<Shader, ShaderManager>
{
private:
	friend class Singleton<ShaderManager>;
	ShaderManager() 
	{ };
};

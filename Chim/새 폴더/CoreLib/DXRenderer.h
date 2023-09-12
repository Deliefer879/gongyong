#pragma once

#include "ShaderManager.h"
#include "TextureManager.h"

struct CB_Data
{
	Matrix worldMatrix;
	Matrix viewMatrix;
	Matrix projMatrix;
	Vector4 color;
};

class DXRenderer
{
private:
	ID3D11Buffer* pVertexBuffer = nullptr;				// interface for vertex buffer	(usually save vertex data or index data)
	ID3D11Buffer* pIndexBuffer = nullptr;				// interface for index buffer
	ID3D11Buffer* pConstantBuffer = nullptr;			// interface for constant buffer

	CB_Data cbData;										// constant buffer data

	Shader shader;										// shader interface
	Texture texture;									// texture interface

	std::vector<Vertex> vertices;
	std::vector<UINT> indices;
private:
	bool CreateVertexBuffer(ID3D11Device* pDevice);
	bool CreateIndexBuffer(ID3D11Device* pDevice);
	bool CreateConstantBuffer(ID3D11Device* pDevice);

public:
	// disable backface culling
	void DisableBackfaceCulling(ID3D11Device* pDevice);
	
	// set vertices and indices
	void SetVertices(std::vector<Vertex>& vertices) { this->vertices = vertices; };
	void SetIndices(std::vector<UINT>& indices) { this->indices = indices; };


	void SetCBData(Matrix& worldMatrix, Matrix& viewMatrix, Matrix& projMatrix);
	void SetResource(std::wstring texFileName, std::wstring shaFileName);

	bool Init(ID3D11Device* pDevice);
	bool Frame();
	bool Render(ID3D11DeviceContext* pContext);
	bool Release();

	std::vector<Vertex>& GetVertices() { return vertices; }
	//temp 
	ID3D11Buffer* GetVertexBuffer() { return pVertexBuffer; }

	DXRenderer() {};
	~DXRenderer() {};
};


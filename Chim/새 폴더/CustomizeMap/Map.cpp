#include "Map.h"

bool Map::Init(ID3D11Device* pDevice, ID3D11DeviceContext* pContext)
{
	//set vertex
	std::vector<Vertex> vertices;
	vertices.resize(vertexNum);
	
	float halfCol = (columnNum-1) * 0.5f;
	float halfRow = (rowNum-1) * 0.5f;
	float texOffsetU = 1.0f / (columnNum - 1);
	float texOffsetV = 1.0f / (rowNum - 1);

	for (int row = 0; row < rowNum; ++row)
	{
		for (int col = 0; col < columnNum; ++col)
		{
			int index = row * columnNum + col;

			vertices[index].pos.x = (col - halfCol) * cellDistance;
			vertices[index].pos.z = -((row - halfRow) * cellDistance);
			vertices[index].pos.y = 0.0f;

			vertices[index].normal = { 0,1,0 };
			vertices[index].color = { 1,1,1,1 };

			vertices[index].tex.x = col * texOffsetU;
			vertices[index].tex.y = row * texOffsetV;
		}
	}
	renderer.SetVertices(vertices);

	//set index
	std::vector<UINT> indices;
	indices.resize(faceNum * 3);

	int index = 0;
	for (int row = 0; row < rowCellNum; ++row)
	{
		for (int col = 0; col < columnCellNum; ++col)
		{
			int nextRow = row + 1;
			int nextCol = col + 1;

			indices[index+0] = row * columnNum + col;
			indices[index+1] = row * columnNum + nextCol;
			indices[index+2] = nextRow * columnNum + col;
					
			indices[index+3] = indices[index+2];
			indices[index+4] = indices[index+1];
			indices[index+5] = nextRow * columnNum + nextCol;

			index += 6;
		}
	}
	renderer.SetIndices(indices);


	renderer.SetResource(info.textureFileName,info.shaderFileName);


	renderer.Init(pDevice);

	return true;
}

bool Map::Frame()
{
	renderer.Frame();
	return true;
}

bool Map::Render(ID3D11DeviceContext* pContext)
{
	renderer.Render(pContext);

	return true;
}

bool Map::Release()
{
	renderer.Release();

	return true;
}

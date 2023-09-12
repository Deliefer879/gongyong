#pragma once

#include "DXRenderer.h"
#include "CameraManger.h"

struct MapInfo
{
	int columnNum;
	int rowNum;
	float cellDistance;
	float scaleHeight;

	std::wstring shaderFileName;
	std::wstring textureFileName;
};

class Map
{
private:
	DXRenderer renderer;

	MapInfo info;
	int columnNum;
	int columnCellNum;
	int rowNum;
	int rowCellNum;
	int vertexNum;
	int faceNum;
	float cellDistance;

public:
	bool Set(MapInfo& info)
	{
		this->info = info;
		columnNum = info.columnNum;
		rowNum = info.rowNum;
		columnCellNum = columnNum - 1;
		rowCellNum = rowNum - 1;

		vertexNum = columnNum * rowNum;
		faceNum = columnCellNum * rowCellNum * 2;
		cellDistance = info.cellDistance;

		return true;
	};
	void SetMatrix()
	{
		Matrix t;
		renderer.SetCBData(t, MainCamera->viewMatrix, MainCamera->projMatrix);
	};


	bool Init(ID3D11Device* pDevice, ID3D11DeviceContext* pContext);
	bool Frame();
	bool Render(ID3D11DeviceContext* pContext);
	bool Release();

	Map() {};
	~Map() {};
};


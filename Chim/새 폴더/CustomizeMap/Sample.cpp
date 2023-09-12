#include "Sample.h"

#include "ShaderManager.h"
#include "TextureManager.h"
#include "Constant.h"

bool Sample::Init()
{
	MapInfo info;

	info.columnNum = 9;
	info.rowNum = 9;
	info.cellDistance = 1.0f;
	info.scaleHeight = 1.0f;
	info.shaderFileName = L"../../res/Shader/Plane.hlsl";
	info.textureFileName = L"../../res/chimuchakusang.png";

	map.Set(info);

	map.Init(graphics.pDevice, graphics.pImmediateContext);

	MainCamera->camPos = { 0,3,-0.1 };
	MainCamera->SetViewMatrix({ 0,0,0 });
	MainCamera->SetProjMatrix(PI / 2.0f, g_Constant.g_winSizeX / g_Constant.g_winSizeY, 1.0f, 1000.0f);

	return true;
}

bool Sample::Frame()
{
	map.Frame();

	return true;
}

bool Sample::Render()
{
	map.SetMatrix();
	map.Render(graphics.pImmediateContext);

	return true;
}

bool Sample::Release()
{
	map.Release();

	return true;
}

GAME_RUN(Basic_Core, 800, 600);

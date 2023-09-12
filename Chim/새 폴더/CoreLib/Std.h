#pragma once

#include "Utils.h"
#include "DirectXTex.h"

#include <Windows.h>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <chrono>

#include <d3d11.h>
#include <d3dcompiler.h>
#include <dxgi1_2.h>
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>

#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dcompiler.lib")
#pragma comment (lib, "dxgi.lib")
#pragma comment (lib, "d2d1.lib")
#pragma comment (lib, "dwrite.lib")
#pragma comment (lib, "DirectXTex.lib")

#pragma comment (lib, "CoreLib.lib")

inline void ShowErrorMessage(HRESULT hr, ID3DBlob* errorCode = nullptr)
{
	LPCSTR errorText = nullptr;

	if (errorCode)
	{
		errorText = (LPCSTR)errorCode->GetBufferPointer();
		MessageBoxA(NULL, errorText, "Error", MB_OK | MB_ICONERROR);
	}

	FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_ALLOCATE_BUFFER,
		NULL, hr, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&errorText, 0, NULL);

	MessageBoxA(NULL, errorText, "Error", MB_OK | MB_ICONERROR);
}

// use unicode so we use wWinMain
#define GAME_RUN(str, width, height) int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)\
{\
	Sample sample;\
	if(sample.GetWindow().Init(hInstance,L#str, width, height))\
		sample.Run();\
	return 0; }\


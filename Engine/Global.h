#pragma once
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4099)

#include <array>
#include <vector>
#include <map>
#include <unordered_map> 
#include <queue>

#include <string>
#include <memory>
#include <chrono>
#include <tchar.h>
#include <algorithm>
#include <sstream>
#include <filesystem>

// D3D11
#include <windows.h>
#include <wrl/client.h>
#include <d3d11.h>
#include <dxgi.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>
#include "DirectXTex.h"	
#pragma comment (lib, "dxgi.lib")
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dcompiler.lib")	
#pragma comment (lib, "DirectXTex.lib")
#pragma comment (lib, "Engine.lib")

// dx write, dx2d
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "dwrite.lib")

// fmod
#include "fmod.h"
#include "fmod.hpp"
#include "fmod_errors.h"
#pragma comment( lib, "fmod_vc.lib")

// 전역 헤더
#include "Geometry.h"
#include "ActorManager.h"

#define T_PI (3.141592f)
#define T_EPSILON ( 0.0001f)
#define RadianToDegree(radian) ( radian *( 180.0f / T_PI))
#define DegreeToRadian(degree) ( degree *( T_PI / 180.0f))
#define randstep(fmin, fmax) ((float)fmin+((float)fmax-(float)fmin)* rand() / RAND_MAX)

using namespace DirectX;
using Microsoft::WRL::ComPtr;
using std::unique_ptr;
using std::shared_ptr;
using std::weak_ptr;
using std::make_unique;
using std::make_shared;

typedef std::basic_string<TCHAR>    STR;
typedef std::basic_string<wchar_t>  WSTR;

#define ASSERT_HR(hr) assert(SUCCEEDED(hr))


//#define TGAME_START int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow){
//#define TGAME_INIT          Sample win;
//#define TGAME_WINDOW(s,w,h) win.MainWindow->MakeWindow(L#s, hInstance, w, h);
//#define TGAME_RUN           win.Run();
//#define TGAME_END           return 0; };
//#define TGAME(s,w,h) TGAME_START;TGAME_INIT;TGAME_WINDOW(s,w,h);TGAME_RUN;TGAME_END;
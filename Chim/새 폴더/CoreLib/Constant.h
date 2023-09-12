#pragma once

#include "Singleton.hpp"
#include <Windows.h>

class Constant : public Singleton<Constant>
{
private:
	friend class Singleton<Constant>;

	Constant() = default;
	~Constant() = default;

public:
	float g_winSizeX = 0;
	float g_winSizeY = 0;
	float g_mapSizeX = 0;
	float g_mapSizeY = 0;

	HWND g_hWnd = nullptr;
};

#define g_Constant Constant::GetInstance()
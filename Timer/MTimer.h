#pragma once
#include <iostream>
#include <Windows.h>
#include <chrono>

using namespace std::chrono;

class Timer
{
private:
	milliseconds globalGameTimer;
	//milliseconds totalFrameTime;
	milliseconds frameTime;
	high_resolution_clock::time_point beforeTime;
	int frameCount;

public:
	void Init();	// 초기화 + 시작전 준비작업등
	void Frame();	// Frame 단위 작업
	void Render();	//실질적 화면 표시
	void Release();// 소멸 ~class
	inline int GetFPS();
	inline milliseconds GetSecPerFrame() { return frameTime; };
	inline milliseconds GetGameTimer() { return globalGameTimer; };
};


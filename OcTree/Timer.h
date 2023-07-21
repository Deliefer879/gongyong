#pragma once

#include <chrono>
#include <iostream>

using namespace std::chrono;

class Timer
{
private:
	high_resolution_clock::duration start;
	milliseconds gameTime;
	nanoseconds deltaTime;
public:
	Timer();
	~Timer();

	void Init();
	void PreFrame();
	void Frame();
	void PostFrame();
	void Render();
	void Release();

	std::chrono::nanoseconds GetDeltaTime() { return deltaTime; }
	std::chrono::milliseconds GetGameTime() { return gameTime; }
};


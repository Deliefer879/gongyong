#pragma once

#include "Singleton.hpp"
#include "Std.h"

using Seconds = std::chrono::microseconds;
const double TIME_EPSILON = 0.000001f;

class Timer: public Singleton<Timer>
{
private:
	friend class Singleton<Timer>;
	Timer() {};
	
	double deltaTime;
	double gameTime;
	std::chrono::high_resolution_clock::time_point lastTime;
public:
	void Init();
	void Frame();
	void Render();
	void Release();

	double GetDeltaTime() const { return deltaTime; }
	double GetGameTime() const { return gameTime; }
	int GetFPS() const { return (int)(1.0f / deltaTime); }
};


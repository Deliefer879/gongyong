#include "Timer.h"

Timer::Timer()
{
}

Timer::~Timer()
{
}

void Timer::Init()
{
	start = system_clock::now().time_since_epoch();
	gameTime = milliseconds(0);
	deltaTime = nanoseconds(1000);
}

void Timer::PreFrame()
{
	start = system_clock::now().time_since_epoch();
}

void Timer::Frame()
{
	std::cout << "GameTime : " << gameTime.count() / 1000 << ", DeltaTime : " << deltaTime.count() / 1000000000.0f 
		<< ", FPS : " << milliseconds(1000) / deltaTime << std::endl;
}

void Timer::PostFrame()
{
	deltaTime = system_clock::now().time_since_epoch() - start;
	gameTime += duration_cast<milliseconds>(deltaTime);
}

void Timer::Render()
{
}

void Timer::Release()
{
}

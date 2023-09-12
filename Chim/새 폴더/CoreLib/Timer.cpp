#include "Timer.h"
#include "Writer.h"

void Timer::Init()
{
	deltaTime = 0;
	gameTime = 0;
	lastTime = std::chrono::high_resolution_clock::now();
}
void Timer::Frame()
{
	auto currentTime = std::chrono::high_resolution_clock::now();

	deltaTime = std::chrono::duration_cast<Seconds>(currentTime - lastTime).count() * TIME_EPSILON;

	lastTime = currentTime;
	gameTime += deltaTime;
}
void Timer::Render()
{
	Writer::GetInstance().AddText(L"FPS : " + std::to_wstring(1 / deltaTime), { 0,0,200,100 }, {1,1,1,1});
	Writer::GetInstance().AddText(L"GameTime : " + std::to_wstring(gameTime), { 0,20,200,120 }, { 1,1,1,1 });
	Writer::GetInstance().AddText(L"DeltaTime : " + std::to_wstring(deltaTime), { 0,40,200,140 }, { 1,1,1, 1 });
}
void Timer::Release()
{

}
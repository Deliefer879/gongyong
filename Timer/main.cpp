#include <iostream>
#include "MTimer.h"
#include <thread>

int main()
{
	Timer timer;
	timer.Init();
	float maxFrame = 30.0f;
	float fstep = 1.0f / 15.0f;
	float fStaticFrame = 0.0f;

	while (timer.GetGameTimer() < std::chrono::seconds(30)) {
		std::this_thread::sleep_for(milliseconds(1));
		timer.Frame();
		fStaticFrame = 0.0f;
		//system("cls");
		timer.Render();
	}
	timer.Release();
}

#include <iostream>
#include "MTimer.h"
#include <thread>

int main()
{
	Timer timer;
	timer.Init();

	while (timer.GetGameTimer() < std::chrono::seconds(30)) {
		std::this_thread::sleep_for(milliseconds(1));
		timer.Frame();
		//system("cls");
		//timer.Render();
	}
	timer.Release();
}

#include "MTimer.h"

void Timer::Init()
{
	globalGameTimer = milliseconds(0);
	frameTime = nanoseconds(0);
	frameCount = 0;
	beforeTime = high_resolution_clock::now();
}

void Timer::Frame()
{
	high_resolution_clock::time_point CurrentTime = high_resolution_clock::now();
	frameTime = duration_cast<nanoseconds>(CurrentTime - beforeTime);

	globalGameTimer += duration_cast<milliseconds>(frameTime);
	beforeTime = CurrentTime;	// 시간연동계산이 끝낫으므로 CurrTime이 현재시간이되고 그다음 들어오는 프레임계산을 해야함.

	frameCount = milliseconds(1000)/frameTime;
}

inline int Timer::GetFPS() {
	return frameCount;
};

void Timer::Render()
{

	std::cout <<
		"[game Time] " << globalGameTimer.count() << "ms" <<
		"[frame time] " << duration_cast<microseconds>(frameTime).count() << "us" <<
		"[fps]" << GetFPS() << "fps" << '\n';
}

void Timer::Release()
{


}
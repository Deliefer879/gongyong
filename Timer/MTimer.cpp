#include "MTimer.h"

void Timer::Init()
{
	globalGameTimer = milliseconds(0);
	//totalFrameTime = milliseconds(0);
	frameTime = milliseconds(0);
	frameCount = 0;
	beforeTime = high_resolution_clock::now();
}

void Timer::Frame()
{
	high_resolution_clock::time_point CurrentTime = high_resolution_clock::now();
	frameTime = duration_cast<milliseconds>(CurrentTime - beforeTime);

	globalGameTimer += frameTime;
	beforeTime = CurrentTime;	// 시간연동계산이 끝낫으므로 CurrTime이 현재시간이되고 그다음 들어오는 프레임계산을 해야함.
	//totalFrameTime += frameTime;

	//if (totalFrameTime >= seconds(1)){
	//	totalFrameTime -= milliseconds(1000);
	//}
	frameCount = milliseconds(1000)/frameTime;
}

inline int Timer::GetFPS() {
	return frameCount;
};

void Timer::Render()
{

	std::cout <<
		"[game Time] " << globalGameTimer.count() << "ms" <<
		"[frame time] " << frameTime.count() << "ms" <<
		"[fps]" << GetFPS() << "fps" << '\n';
}

void Timer::Release()
{


}
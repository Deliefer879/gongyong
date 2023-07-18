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
	beforeTime = CurrentTime;	// �ð���������� �������Ƿ� CurrTime�� ����ð��̵ǰ� �״��� ������ �����Ӱ���� �ؾ���.
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
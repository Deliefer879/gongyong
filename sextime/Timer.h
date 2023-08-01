#pragma once

using namespace std::chrono;
using hrc = high_resolution_clock;

class Timer
{
public:
	duration<float> mTotalTimeElapsed;
	duration<float> mTimeElapsed;
	duration<float, std::milli> mFrameTime;
	hrc::time_point mBeforeTime;
	hrc::time_point mCurrentTime;
	size_t mFrameCount;
	size_t mFps;

public:
	void Init();
	void Frame();
	void Render();
	void Release();
};


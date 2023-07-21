#include "stdafx.h"
#include "Timer.h"

void Timer::Init()
{
	mTotalTimeElapsed = duration<float>(0);
	mTimeElapsed = duration<float>(0);
	mFrameTime = duration<float>(0);
	mFrameCount = 0;
	mFps = 0;
	mBeforeTime = hrc::now();
}

void Timer::Frame()
{
	mCurrentTime = hrc::now();
	mFrameTime = mCurrentTime - mBeforeTime;
	mTotalTimeElapsed += mFrameTime;
	mTimeElapsed += mFrameTime;
	mBeforeTime = mCurrentTime;

	if (mTimeElapsed.count() >= 1.0) {
        mFps = mFrameCount;
        mFrameCount = 0;
		mTimeElapsed -= mTimeElapsed;
    }
	else {
        ++mFrameCount;
    }
}

void Timer::Render()
{
	std::cout 
		<< "[TotalTimeElapsed] "<< mTotalTimeElapsed.count()	<< "s	"
		<< "[Frametime] "		<< mFrameTime.count()			<< "ms	"
		<< "[Fps] "				<< mFps							<< '\n';
}

void Timer::Release()
{
}
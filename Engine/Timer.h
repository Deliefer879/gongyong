#pragma once

class Timer
{
using hrc = std::chrono::high_resolution_clock;

public:
	int		FPS()		{ return m_FPS; }
	float	DeltaTime()	{ return m_FrameTime.count(); }
	float	TotalTime() { return m_TotalTimeElapsed.count(); }

	void	UpdateClock();
	void	DrawTimeInfo();

	static Timer& GetInstance() {
        static Timer Instance;
        return Instance;
    }

private:
	Timer();

	std::chrono::duration<float>	m_TotalTimeElapsed;
	std::chrono::duration<float>	m_FrameTime;
	hrc::time_point					m_BeforeTime;
	int								m_FPS;
};
#define TIMER Timer::GetInstance()

inline Timer& GetTimer() {
	return Timer::GetInstance(); 
}
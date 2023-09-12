#include "pch.h"
#include "Timer.h"
#include "TextManager.h"

Timer::Timer() :
    m_TotalTimeElapsed(std::chrono::duration<float>(0)),
    m_FrameTime(std::chrono::duration<float>(0)),
    m_BeforeTime(hrc::now()),
    m_FPS(0)
{}

void Timer::UpdateClock()
{
    constexpr float oneSecond = 1.0f;
    static float lastFpsTime = 0.0f;

    auto CurrentTime = hrc::now();
    m_FrameTime = CurrentTime - m_BeforeTime;
    m_BeforeTime = CurrentTime;

    m_TotalTimeElapsed += m_FrameTime;
    
    static int FrameCount = 0;
    ++FrameCount;

    if (m_TotalTimeElapsed.count() - lastFpsTime >= oneSecond) {
        m_FPS = FrameCount;
        FrameCount = 0;
        lastFpsTime = m_TotalTimeElapsed.count();
    }
}

void Timer::DrawTimeInfo()
{
    TCHAR m_szBuffer[50]{};
    _stprintf_s(
        m_szBuffer,
        _T("FPS:%u\nTime:%0.0f\nFrameTime:%0.2f"),
        m_FPS, m_TotalTimeElapsed.count(), m_FrameTime.count());
    TEXT_MANAGER.AddTextToBuffer(m_szBuffer, {0,0,1200,800}, D2D1::ColorF::White); //TODO: 하드코딩
}
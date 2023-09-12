#pragma once
#include "TextManager.h"

// 개별적인 사운드 파일
class Audio
{
public:
    void  SetSound(FMOD::Sound* sound) { m_FMODSound = sound; }
    void  RenderAudioInfo();
    void  Release();

    void  Play(FMOD::System* FMODSystem, bool loop = false);
    void  Stop();
    void  Pause();
    void  Resume();
    void  VolumeUp();   // TODO: 방향키로 하드코딩되어 있음. 키보드 입력으로 바꿀 것.
    void  VolumeDown(); // TODO: 방향키로 하드코딩되어 있음. 키보드 입력으로 바꿀 것.

private:
    void ValidateChannel() const;

    float			m_Volume{ 0.f };
    FMOD::Sound*    m_FMODSound{ nullptr };
    FMOD::Channel*  m_FMODChannel{ nullptr };
    wchar_t         m_DisplayBuffer[50];
};

class AudioManager
{
public:
    void PlayAudio(const std::wstring& filepath);
    void UpdateAudioFrame();

    static AudioManager& Instance() {
        static AudioManager instance;
        return instance;
    }
    AudioManager(const AudioManager&) = delete;
    AudioManager& operator=(const AudioManager&) = delete;

private:
    AudioManager();
    ~AudioManager();
    void ReleaseAllAudioResources();
    void ShutdownFMODSystem();

    std::map<std::wstring, std::unique_ptr<Audio>> m_AudioList;
    FMOD::System* m_FMODSystem{ nullptr };
};

#define AUDIO_MANAGER AudioManager::Instance()
inline AudioManager& GetAudioManager() { return AudioManager::Instance(); }


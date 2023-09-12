#include "pch.h"
#include "AudioManager.h"

void Audio::ValidateChannel() const
{
    assert(m_FMODChannel != nullptr && "FMODChannel is null");
}

void Audio::RenderAudioInfo()
{
    unsigned int elapsedTimeMs = 0;
    unsigned int totalTimeMs = 0;
    float currentVolume = 0.0f;

    m_FMODChannel->getPosition(&elapsedTimeMs, FMOD_TIMEUNIT_MS);
    m_FMODSound->getLength(&totalTimeMs, FMOD_TIMEUNIT_MS);
    m_FMODChannel->getVolume(&currentVolume);

    swprintf(m_DisplayBuffer, sizeof(m_DisplayBuffer),
        L"ElapsedTime: %d TotalTime: %d Volume: %0.1f",
        elapsedTimeMs, totalTimeMs, currentVolume);

    TEXT_MANAGER.AddTextToBuffer(m_DisplayBuffer, { 0.f , 300.f, 1200, 800 }, D2D1::ColorF::Blue); //TODO: 하드코딩
}

void  Audio::Release()
{
    if (m_FMODChannel)m_FMODChannel->stop();
    if (m_FMODSound)m_FMODSound->release();
}

void Audio::Play(FMOD::System* FMODSystem, bool loop)
{
    ValidateChannel();

    bool isPlaying;
    m_FMODChannel->isPlaying(&isPlaying);

    if (!isPlaying) {
        // Set the loop mode based on the parameter
        FMOD_MODE mode = loop ? FMOD_LOOP_NORMAL : FMOD_LOOP_OFF;
        m_FMODSound->setMode(mode);

        // Play the sound
        FMOD_RESULT result = FMODSystem->playSound(m_FMODSound, nullptr, false, &m_FMODChannel);
        assert(result == FMOD_OK && "Failed to play sound");
    }
}

void  Audio::Stop()
{
    ValidateChannel();
    m_FMODChannel->stop();
}

void  Audio::Pause()
{
    ValidateChannel();
    m_FMODChannel->setPaused(true);
}

void Audio::Resume()
{
    ValidateChannel();
    m_FMODChannel->setPaused(false);
}

void  Audio::VolumeUp()
{
    ValidateChannel();

    m_FMODChannel->getVolume(&m_Volume);
    m_Volume = std::clamp(m_Volume + 0.1f, 0.0f, 1.0f);
    m_FMODChannel->setVolume(m_Volume);
}

void  Audio::VolumeDown()
{
    ValidateChannel();

    m_FMODChannel->getVolume(&m_Volume);
    m_Volume = std::clamp(m_Volume - 0.1f, 0.0f, 1.0f);
    m_FMODChannel->setVolume(m_Volume);
}

//==================================================================


void AudioManager::PlayAudio(const std::wstring& filePath) {

    // 이미 있는 경우 재생
    if (m_AudioList.find(filePath) != m_AudioList.end()) {
        m_AudioList[filePath]->Play(m_FMODSystem, true);
        return;
    }

    // 없으면 로드하고 재생
    auto audio = std::make_unique<Audio>();
    FMOD::Sound* newSound;
    FMOD_RESULT result = m_FMODSystem->createSound(wtm(filePath).c_str(), FMOD_DEFAULT, nullptr, &newSound);
    if (result == FMOD_OK) {
        m_AudioList.insert(std::make_pair(filePath, std::move(audio)));
        m_AudioList[filePath]->SetSound(newSound);
        m_AudioList[filePath]->Play(m_FMODSystem, true);
    }
    else {
        assert(false && "Failed to load sound");
    }
}

void AudioManager::UpdateAudioFrame() 
{
    if (!m_FMODSystem) return;

    m_FMODSystem->update();

    for (auto& [key, audio] : m_AudioList) {
        audio->RenderAudioInfo();
        // TODO: 볼륨 컨트롤
    }
}

AudioManager::AudioManager() {
    FMOD::System_Create(&m_FMODSystem);
    m_FMODSystem->init(32, FMOD_INIT_NORMAL, nullptr);
}

AudioManager::~AudioManager() {
    ReleaseAllAudioResources();
    ShutdownFMODSystem();
}

void AudioManager::ReleaseAllAudioResources() {
    for (auto& [key, audio] : m_AudioList) {
        audio->Release();
    }
    m_AudioList.clear();
}

void AudioManager::ShutdownFMODSystem() {
    m_FMODSystem->close();
    m_FMODSystem->release();
}

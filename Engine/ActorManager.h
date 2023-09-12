#pragma once
#include "AActor.h"
#include "UActorComponent.h"

class ActorManager
{
public:
    void CallBeginPlays();
    void UpdateTicks(float deltaTime);
    void CallEndPlays();
    void RegisterActor(unique_ptr<AActor> actor, int sceneid);
    void DeleteActor(int id);

    static ActorManager& Get()
    {
        static ActorManager Instance;
        return Instance;
    }
private:
    ActorManager() {}
    ~ActorManager() { m_Actors.clear(); }

    std::multimap<int, unique_ptr<AActor>> m_Actors; // current scene id | actor
    int m_CurrentScene;
};
#define ACTOR_MANAGER ActorManager::Get()
inline ActorManager& GetActorManager() { return ActorManager::Get(); }
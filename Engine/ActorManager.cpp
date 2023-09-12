#include "pch.h"
#include "ActorManager.h"

void ActorManager::CallBeginPlays()
{
}

void ActorManager::UpdateTicks(float deltaTime)
{
    auto range = m_Actors.equal_range(m_CurrentScene);
    for (auto& it = range.first; it != range.second; ++it)
    {
        it->second->Tick(deltaTime);
        it->second->m_pRootComponent->TickComponent(deltaTime);
    }
}

void ActorManager::CallEndPlays()
{

}

//bool ActorManager::Render()
//{
//    int sceneID = SCENE_MANAGER.GetCurrentSceneID();
//    auto range = m_Actors.equal_range(sceneID);
//    for (auto& it = range.first; it != range.second; ++it)
//    {
//        it->second->SetWorldViewProjMatrix(nullptr, &g_pMainCamera->matView, &g_pMainCamera->matOrthoProjection);
//        it->second->Render();
//    }
//    return false;
//}

void ActorManager::RegisterActor(unique_ptr<AActor> actor, int sceneid)
{
    actor->m_CurrentSceneID = sceneid;
    m_Actors.insert(std::make_pair(actor->m_CurrentSceneID, std::move(actor)));
}

void ActorManager::DeleteActor(int id)
{
    m_Actors.erase(id);
}

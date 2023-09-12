#include "SceneManager.h"

void SceneManager::AddScene(int sceneIndex, std::unique_ptr<Scene> scene)
{
	sceneMap.insert(std::make_pair(sceneIndex, std::move(scene)));
}

void SceneManager::ChangeScene(int sceneIndex)
{
	Scene* temp = currentScene;

	if(sceneIndex >= sceneMap.size())
		return;

	currentScene = sceneMap.find(sceneIndex)->second.get();
	
	if (temp != nullptr)
	{
		currentScene->SetPlayerPtr(temp->GetPlayerPtr());
		temp->Release();
	}

	currentScene->Init(pDevice);

	currentSceneIndex = sceneIndex;
}

void SceneManager::Set(ID3D11Device* pDevice, ID3D11DeviceContext* pContext)
{
	this->pDevice = pDevice;
	this->pContext = pContext;
}

void SceneManager::Frame()
{
	currentScene->Frame();
}

void SceneManager::Render()
{
	currentScene->Render(pContext);
}

void SceneManager::Release()
{
	currentScene->Release();
}

#pragma once

#include "Scene.h"
#include "Singleton.hpp"

class SceneManager : public Singleton<SceneManager>
{
private:
	friend class Singleton<SceneManager>;
	SceneManager() {};
	~SceneManager() {};

private:
	Scene* currentScene = nullptr;
	std::unordered_map<int, std::unique_ptr<Scene>> sceneMap;

	ID3D11Device* pDevice = nullptr;
	ID3D11DeviceContext* pContext = nullptr;

public:
	bool loadNextScene = false;
	int currentSceneIndex = 0;
public:
	void AddScene(int sceneIndex,std::unique_ptr<Scene> scene);
	void ChangeScene(int sceneIndex);
	Object* GetPlayer() { return currentScene->GetPlayer(); }
	
	void Set(ID3D11Device* pDevice, ID3D11DeviceContext* pContext);

	void Frame();
	void Render();
	void Release();
};


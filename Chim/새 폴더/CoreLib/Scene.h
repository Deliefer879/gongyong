#pragma once

#include "ObjectManager.h"

class Scene
{
protected:
	std::unique_ptr<Object> playerPtr;
	std::unique_ptr<Object> backGround;

	std::vector<std::unique_ptr<Object>> objList;
	std::vector<std::unique_ptr<Object>> uiList;

	ObjectManager objectManager;
	Vector3 startPos;

	bool isSceneActive = true;
public:
	virtual void Init(ID3D11Device* pDevice);
	virtual void Frame();
	virtual void Render(ID3D11DeviceContext* pContext);
	virtual void Release();

	virtual void SetPlayer(ID3D11Device* pDevice) = 0;
	virtual void SetNpc(ID3D11Device* pDevice) = 0;
	virtual void SetMap(ID3D11Device* pDevice) = 0;
	virtual void SetUI(ID3D11Device* pDevice) = 0;

	void SetPlayerPtr(std::unique_ptr<Object>& playerPtr);
	std::unique_ptr<Object>& GetPlayerPtr() { return playerPtr; };
	Object* GetPlayer() { return playerPtr.get(); };
public:
	Scene() {};
	virtual ~Scene() { Release(); };
};


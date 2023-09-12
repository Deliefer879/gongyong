#include "Scene.h"

void Scene::Init(ID3D11Device* pDevice)
{
	isSceneActive = true;

	SetMap(pDevice);

	SetPlayer(pDevice);

	if(playerPtr != nullptr)
	{
		objectManager.AddCollisionEvent(playerPtr.get(),
			std::bind(&Object::CollisionEvent, playerPtr.get(), std::placeholders::_1, std::placeholders::_2));
	}

	SetNpc(pDevice);
	SetUI(pDevice);
}

void Scene::Frame()
{
	if (!isSceneActive)
		return;

	objectManager.Frame();

	if(backGround != nullptr)	
		backGround->Frame();

	for (auto& obj : objList)
		obj->Frame();

	if(playerPtr != nullptr)
		playerPtr->Frame();

	for (auto& ui : uiList)
		ui->Frame();
}

void Scene::Render(ID3D11DeviceContext* pContext)
{
	if (!isSceneActive)
		return;

	if(backGround != nullptr)
		backGround->Render(pContext);

	for (auto& obj : objList)
		obj->Render(pContext);

	if(playerPtr != nullptr)
		playerPtr->Render(pContext);

	for (auto& ui : uiList)
		ui->Render(pContext);
}

void Scene::Release()
{
	objectManager.Release();

	if (backGround != nullptr)
	{
		backGround->Release();
		backGround.release();
	}
	for (auto& obj : objList)
	{
		obj->Release();
		obj.release();
	}
	for (auto& ui : uiList)
	{
		ui->Release();
		ui.release();
	}
	objList.clear();
	uiList.clear();

	isSceneActive = false;
}

void Scene::SetPlayerPtr(std::unique_ptr<Object>& playerPtr)
{
	if(playerPtr != nullptr)
		this->playerPtr = std::move(playerPtr);
}

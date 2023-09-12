#include "ObjectManager.h"
#include "UserInput.h"

void ObjectManager::AddCollisionEvent(Object* obj, CollsiionFunc func)
{
	obj->objectID = ++collisionID; 
	collisionObjList.insert(std::make_pair(obj->objectID, obj));
	collisionFuncList.insert(std::make_pair(obj->objectID, func));
}

void ObjectManager::DeleteCollisionEvent(Object* obj)
{
	auto iter = collisionObjList.find(obj->objectID);

	if (iter != collisionObjList.end())
	{
		collisionObjList.erase(obj->objectID);
		collisionFuncList.erase(obj->objectID);
	}
}

void ObjectManager::AddSelectEvent(Object* obj, SelectFunc func)
{
	obj->objectID = ++selectID;
	selectObjList.insert(std::make_pair(obj->objectID, obj));
	selectFuncList.insert(std::make_pair(obj->objectID, func));
}

void ObjectManager::DeleteSelectEvent(Object* obj)
{
	auto iter = selectObjList.find(obj->objectID);

	if (iter != selectObjList.end())
	{
		selectObjList.erase(obj->objectID);
		selectFuncList.erase(obj->objectID);
	}
}

void ObjectManager::Init()
{
}

void ObjectManager::Frame()
{
	// check collision
	for (auto& srcObj : collisionObjList)
	{
		if(collisionObjList.size() < 1)
			break;

		Object* sObj = srcObj.second;		

		if (!sObj->isRender || sObj->collisionType == CollisionType::Ignore)
			continue;

		for (auto& destObj : collisionObjList)
		{
			if (collisionObjList.size() < 1)
				break;

			Object* dObj = destObj.second;
			if (!dObj->isRender || sObj->objectID == dObj->objectID)
				continue;

			if (sObj->GetCollisionBox().ToRect(dObj->GetCollisionBox()))
			{
				auto iter = collisionFuncList.find(sObj->objectID);

				if (iter != collisionFuncList.end())
					iter->second(dObj, sObj->collisionType);
			}
		}
	}

	// check select
	for (auto& srcObj : selectObjList)
	{
		if (selectObjList.size() < 1)
			break;

		Object* sObj = srcObj.second;

		if(!sObj->isRender || sObj->selectType == SelectType::Ignore)
			continue;

		if (sObj->GetCollisionBox().ToPoint(UserInput::GetInstance().GetMousePos()))
		{
			KeyState mouseState = UserInput::GetInstance().GetMouseState(0);

			sObj->selectType = SelectType::Hover;

			if(mouseState == KeyState::PUSH || mouseState == KeyState::HOLD)
				sObj->selectType = SelectType::Active;
			else if(mouseState == KeyState::UP)
				sObj->selectType = SelectType::Select;

			auto iter = selectFuncList.find(sObj->objectID);
			if (iter != selectFuncList.end())
				iter->second(sObj, sObj->selectType);
		}
		else if(sObj->selectType != SelectType::Default)
		{
			if(sObj->selectType == SelectType::Active)
				sObj->selectType = SelectType::Cancel;
			else
				sObj->selectType = SelectType::Default;

			auto iter = selectFuncList.find(sObj->objectID);
			if (iter != selectFuncList.end())
				iter->second(sObj, sObj->selectType);
		}
	}
}

void ObjectManager::Release()
{
	collisionID = 0;
	selectID = 0;

	collisionObjList.clear();
	collisionFuncList.clear();
	selectObjList.clear();
	selectFuncList.clear();
}
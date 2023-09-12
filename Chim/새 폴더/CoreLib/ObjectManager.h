#pragma once

#include "Object.h"

using CollsiionFunc = std::function<void(Object*, CollisionType)>;
using SelectFunc = std::function<void(Object*, SelectType)>;

class ObjectManager
{
private:
	int collisionID = 0;
	int selectID = 0;

	std::unordered_map<int, Object*> collisionObjList;
	std::unordered_map<int, Object*> selectObjList;
	std::unordered_map<int, CollsiionFunc> collisionFuncList;
	std::unordered_map<int, SelectFunc> selectFuncList;

public:
	void AddCollisionEvent(Object* obj, CollsiionFunc func);
	void DeleteCollisionEvent(Object* obj);
	void AddSelectEvent(Object* obj, SelectFunc func);
	void DeleteSelectEvent(Object* obj);

	void Init();
	void Frame();
	void Release();

public:
	ObjectManager() {};
	~ObjectManager() { Release(); };
};


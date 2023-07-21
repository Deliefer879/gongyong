#pragma once

#include <type_traits>
#include "Collider.h"

template <typename T>
class Object
{
protected:
	Vector3 objPos;
	T collider;
public:
	Object() { static_assert(std::is_base_of_v<Collider, T>, "T must be derived from Collider"); };
	virtual ~Object() {};

	Vector3& GetObjPos() { return objPos; };
	void SetObjPos(Vector3 pos) { this->objPos = pos; };
	T& GetCollider() { return collider; };
	void SetCollider(T& collider) { this->collider = collider; };

	virtual void Move(float deltaTime) = 0;
	virtual void SetDir(Vector3& target) = 0;
};

template <typename U>
class StaticObject : public Object<U>
{
public:
	StaticObject() 
	{

	};
	virtual ~StaticObject() {};

	virtual void Move(float deltaTime) override {};
	virtual void SetDir(Vector3& target) override {};
};

template <typename U>
class DynamicObject : public Object<U>
{
private:
	Vector3 dir;
	float speed = 50;
public:
	DynamicObject() 
	{
	};
	virtual ~DynamicObject() {};

	virtual void Move(float deltaTime) override
	{
		Object<U>::collider.Pos(Object<U>::objPos);
	};

	virtual void SetDir(Vector3& target) override
	{
		Object<U>::objPos.X();
	};
};

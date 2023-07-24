#pragma once

#include <type_traits>
#include "Collider.h"

template <typename T>
class Object
{
protected:
	Vector3 objPos;
	T area;
public:
	Object() { static_assert(std::is_base_of_v<Collider, T>, "T must be derived from Collider"); };
	Object(Vector3 pos, T area) 
	{ 
		static_assert(std::is_base_of_v<Collider, T>, "T must be derived from Collider");
		this->objPos = pos;
		this->area = area;
	};
	virtual ~Object() {};

	Vector3& GetObjPos() { return objPos; };
	void SetObjPos(const Vector3 pos) { this->objPos = pos; };
	T& GetArea() { return area; };
	void SetArea(const T& area) { this->area = area; };

	virtual void Move(float deltaTime) = 0;
	virtual void SetDir(const Vector3& target) = 0;

	//for print test
	void PrintInfo() { std::cout << "Object Area: "; area.PrintInfo(); }
};

template <typename U>
class StaticObject : public Object<U>
{
public:
	StaticObject() {};
	StaticObject(Vector3 pos, U area) : Object<U>(pos, area) { };
	virtual ~StaticObject() {};

	virtual void Move(float deltaTime) override {};
	virtual void SetDir(const Vector3& target) override {};
};

template <typename U>
class DynamicObject : public Object<U>
{
private:
	Vector3 dir;
	float speed = 50;
public:
	DynamicObject() {};
	DynamicObject(Vector3 pos, U area) : Object<U>(pos, area) { };
	virtual ~DynamicObject() {};

	virtual void Move(float deltaTime) override
	{
		Object<U>::objPos += dir * deltaTime * speed;
		Object<U>::area.Pos(Object<U>::objPos);
	};

	virtual void SetDir(const Vector3& target) override
	{
		dir = target - Object<U>::objPos;
		dir = dir.Normalize();
	};
};

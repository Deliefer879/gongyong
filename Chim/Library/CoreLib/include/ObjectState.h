#pragma once

class Object;

class ObjectState
{
protected:
	Object* owner;

public:
	virtual void Enter() = 0;
	virtual void Execute(Object* other) = 0;
	virtual void Exit() = 0;

public:
	ObjectState(Object* pOwner) : owner(pOwner) {};
};


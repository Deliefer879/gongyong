#pragma once

#include "Animator.h"
#include "DXRenderer.h"
#include "Timer.h"
#include "FiniteState.hpp"

class ObjectState;

enum class ObjectTag
{
	Default = 0,
	Player = 1,
	NPC = 2,
	Wall = 3,
	Floor = 4,
	PlayerWeapon = 5,
	NPCWeapon = 6,
};

enum class CollisionType
{
	Block = 0,
	Overlap = 1,
	Ignore = 2
};

enum class SelectType
{
	Default = 0,
	Hover = 1,
	Active = 2,
	Select = 4,
	Cancel = 8,
	Ignore = 16
};

class Object
{
protected:
	DXRenderer renderer;

public:
	Vector3 position;
	Vector3 rotation;
	Vector3 scale;
	Rect collider;

	ObjectTag objTag = ObjectTag::Default;
	CollisionType collisionType = CollisionType::Ignore;
	SelectType selectType = SelectType::Ignore;
	
	int objectID = 0;
	bool isRender = true;
private:
	void SetMatrix();
public:
	void SetPosition(Vector3 pos)
	{
		position = pos;
		collider.SetPosition({ pos.x, pos.y });
	};
	void SetRotation(Vector3 rot) { rotation = rot; };
	void SetScale(Vector3 sca, bool isFullRect = false) 
	{
		scale = sca; 

		if (isFullRect)
			collider.SetRect({ position.x,position.y }, { fabs(sca.x) * 2 , sca.y * 2});
		else
			collider.SetRect({ position.x,position.y }, { fabs(sca.x) , sca.y});
	};
	virtual void SetSprite(AnimationInfo info);

	virtual void Move(double deltaTime) {};
	virtual void CollisionEvent(Object* obj, CollisionType type) {};
	virtual void SelectEvent(Object* obj, SelectType type) {};
	virtual void AddState(FSMState state, ObjectState* statePtr) {};
	virtual void SetState(FSMState state) {};

	virtual bool Init(ID3D11Device* pDevice);
	virtual bool Frame();
	virtual bool Render(ID3D11DeviceContext* pContext);
	virtual bool Release();

	virtual Rect& GetCollisionBox() { return collider; };
public:
	Object() {};
	virtual ~Object() {};
};


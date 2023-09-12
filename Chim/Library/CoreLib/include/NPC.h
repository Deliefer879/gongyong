#pragma once

#include "Object.h"

class NPC : public Object
{
private:
	Vector2 dir;
	bool isFall = true;

public:
	Animator animator;

public:
	void Move(double deltaTime) override;

	virtual void CollisionEvent(Object* obj, CollisionType type) override;

	virtual void SetSprite(AnimationInfo info) override;
	virtual bool Frame() override;
	virtual bool Render(ID3D11DeviceContext* pContext) override;
public:
	NPC() 
	{ 
		float i = 1;

		if(RandRange(-2, 2) > 0)
			i = -1;

		dir = {i,0,0}; 
	
	};
	~NPC() {};
};
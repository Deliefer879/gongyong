#pragma once

#include "Object.h"

class Player : public Object
{
private:
	bool isFall = true;

public:
	Animator animator;
public:
	virtual void SetSprite(AnimationInfo info) override;
public:
	bool Frame() override;
	bool Render(ID3D11DeviceContext* pContext) override;

	virtual void CollisionEvent(Object* obj, CollisionType type) override;
};


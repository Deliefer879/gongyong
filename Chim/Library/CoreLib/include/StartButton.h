#pragma once

#include "Object.h"

class StartButton : public Object
{
private:
	Animator animator;
public:
	virtual void SetSprite(AnimationInfo info) override;
public:
	virtual void SelectEvent(Object* obj, SelectType type) override;

public:
	virtual bool Frame() override;
	virtual bool Render(ID3D11DeviceContext* pContext) override;
};


#pragma once

#include "Std.h"

class DXRenderer;

struct Vertex;

struct UVRect
{
	Vector2 min;
	Vector2 max;
};

struct AnimationInfo
{
	int spriteRow;
	int spriteColumn;
	int animCount;

	float animTime;

	std::wstring shaFileName;
	std::wstring animFileName;
	std::vector<std::wstring> animNameList;

	void Reset()
	{
		spriteRow = 0;
		spriteColumn = 0;
		animCount = 0;

		animTime = 0;

		animFileName = L"";
		shaFileName = L"";

		animNameList.clear();
	}

	AnimationInfo()
	{
		Reset();
	}
};

class Animator
{
public:
	int currentAnimationIndex = 0;

	float animTime;
	float changeTime;
	float elapsedTime;

	std::unordered_map<std::wstring, std::vector<UVRect>> animationMap;
	std::vector<UVRect>* currentAnimation;

	bool SetAnimation(std::wstring animName);
	bool SetVertexUVData(std::vector<Vertex>& vertices);

	void SetAnimationInfo(AnimationInfo& info);

	void Frame();
	void Render(ID3D11DeviceContext* pContext, DXRenderer& renderer);
};


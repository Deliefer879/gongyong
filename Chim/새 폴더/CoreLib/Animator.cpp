#include "Animator.h"
#include "ShaderManager.h"
#include "Timer.h"

#include "DXRenderer.h"

bool Animator::SetAnimation(std::wstring animName)
{
	auto iter = animationMap.find(animName);
	
	if (iter != animationMap.end())
	{
		// change animation
		currentAnimation = &(iter->second);
		currentAnimationIndex = 0;
		elapsedTime = 0;

		return true;
	}
	return false;
}

bool Animator::SetVertexUVData(std::vector<Vertex>& vertices)
{
	// update vertex uv data

	UVRect uv = currentAnimation->at(currentAnimationIndex);
	vertices[0].tex = uv.min;

	vertices[1].tex.x = uv.max.x;
	vertices[1].tex.y = uv.min.y;

	vertices[2].tex.x = uv.min.x;
	vertices[2].tex.y = uv.max.y;

	vertices[3].tex = uv.max;

	return true;
}

void Animator::Frame()
{
	// frame animation

	elapsedTime += Timer::GetInstance().GetDeltaTime();

	if (elapsedTime >= changeTime)
	{
		elapsedTime -= changeTime;
		++currentAnimationIndex;

		if (currentAnimationIndex >= currentAnimation->size())
			currentAnimationIndex = 0;
	}
}

void Animator::Render(ID3D11DeviceContext* pContext, DXRenderer& renderer)
{
	SetVertexUVData(renderer.GetVertices());
	pContext->UpdateSubresource(renderer.GetVertexBuffer(), 0, nullptr, &renderer.GetVertices().at(0), 0, 0);
}

void Animator::SetAnimationInfo(AnimationInfo& info)
{
	animTime = info.animTime;
	changeTime = info.animTime / info.animCount;

	float spriteRow = 1.0f / info.spriteRow;
	float spriteColumn = 1.0f / info.spriteColumn;

	float minU = 0.0f;
	float minV = 0.0f;
	float maxU = 0.0f;
	float maxV = 0.0f;

	for (int i = 0; i < info.spriteColumn; ++i)
	{
		std::vector<UVRect> uvRects;
		for (int j = 0; j < info.spriteRow; ++j)
		{
			minU = j * spriteRow;
			minV = i * spriteColumn;

			maxU = minU + spriteRow;
			maxV = minV + spriteColumn;

			uvRects.push_back({ {minU, minV}, {maxU, maxV} });
		}
		animationMap.insert(std::make_pair(info.animNameList[i], uvRects));
	}

	SetAnimation(info.animNameList[0]);
}

#pragma once

#include "Collider.h"

class CollisionManager
{
	static bool RectInRect(const Rect& rect1, const Rect& rect2)
	{
		Rect uRect = rect1 + rect2;

		if(uRect.W() < rect1.W() + rect2.W() && uRect.H() < rect1.H() + rect2.H())
			return true;

		return false;
	}

	static bool CubeInCube(const Cube& rect, const Cube& circle)
	{

	}
};
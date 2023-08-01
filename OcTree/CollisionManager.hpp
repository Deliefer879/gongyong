#pragma once

#include "Collider.h"

class CollisionManager
{
public:
	static bool RectInRect(const Rect& rect1, const Rect& rect2)
	{
		Rect uRect = rect1 + rect2;

		if(uRect.W() <= (rect1.W() + rect2.W()) && uRect.H() <= (rect1.H() + rect2.H()))
			return true;

		return false;
	}

	static bool CubeInCube(const Cube& cube1, const Cube& cube2)
	{
		Cube uCube = cube1 + cube2;

		if(uCube.W() <= (cube1.W() + cube2.W()) &&
			uCube.H() <= (cube1.H() + cube2.H()) &&
			uCube.D() <= (cube1.D() + cube2.D()))
			return true;

		return false;
	}
};
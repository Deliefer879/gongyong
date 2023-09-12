#pragma once

class Vector2;
struct Rect;

class Collision
{
public:
	static bool RectToPoint(Vector2& point, Rect& rect);
	static bool RectToRect(Rect& rect1, Rect& rect2);
};


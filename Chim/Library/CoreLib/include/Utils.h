#pragma once

#include "Basic_Math.h"

struct Rect
{
	Vector2 center;
	Vector2 size;
	Vector2 min;
	Vector2 max;
	float angle = 0;

	bool operator == (const Rect& rect);
	bool operator != (const Rect& rect);
	Rect operator + (const Rect& rect); // union rect
	Rect operator - (const Rect& rect); // intersect rect
	Rect operator * (float val);
	Rect operator / (float val);
	Rect& operator *= (float val);
	Rect& operator /= (float val);

	Rect& operator = (const Rect& rect);

	void SetRect(float x, float y, float width, float height);
	void SetRect(Vector2 center, Vector2 size);
	void SetRect(Rect rect);
	void SetPosition(float x, float y);
	void SetPosition(Vector2 position);
	void SetSize(float width, float height);
	void SetSize(Vector2 size);

	bool ToPoint(Vector2 point);
	bool ToRect(Rect rect);
};

struct Circle
{
	Vector2 center;
	float radius;

	bool operator == (const Circle& circle);
	bool operator != (const Circle& circle);

	Circle operator * (float val);
	Circle operator / (float val);
	Circle& operator = (const Circle& circle);

	void SetCircle(float x, float y, float radius);
	void SetCircle(Vector2 center, float radius);
	void SetCircle(Circle circle);
	void SetPosition(float x, float y);
	void SetPosition(Vector2 position);
	void SetRadius(float radius);
	bool ToPoint(Vector2 point);
	bool ToCircle(Circle circle);
};
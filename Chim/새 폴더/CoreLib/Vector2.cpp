#include "Basic_Math.h"

bool Vector2::operator==(const Vector2& v)
{
	if (fabs(x - v.x) < EPSILON)
	{
		if (fabs(y - v.y) < EPSILON)
			return true;
	}

	return false;
}

bool Vector2::operator!=(const Vector2& v)
{
	return !(*this == v);
}

float Vector2::operator|(const Vector2& v)
{
	return x * v.x + y * v.y;
}

Vector2 Vector2::operator+(const Vector2& v)
{
	return Vector2(x + v.x, y + v.y);
}

Vector2 Vector2::operator-(const Vector2& v)
{
	return Vector2(x - v.x, y - v.y);
}

Vector2 Vector2::operator*(float val)
{
	return Vector2(x * val, y * val);
}

Vector2 Vector2::operator/(float val)
{
	return Vector2(x / val, y / val);
}

Vector2& Vector2::operator+=(const Vector2& v)
{
	x = x + v.x;
	y = y + v.y;

	return *this;
}
Vector2& Vector2::operator-=(const Vector2& v)
{
	x = x - v.x;
	y = y - v.y;

	return *this;
}
Vector2& Vector2::operator*=(float val)
{
	x = x * val;
	y = y * val;

	return *this;
}
Vector2& Vector2::operator/=(float val)
{
	x = x / val;
	y = y / val;

	return *this;
}

Vector4 Vector2::operator*(const Matrix m)
{
	Vector4 v;

	v.x = x * m._11 + y * m._21 + m._31 + m._41;
	v.y = x * m._12 + y * m._22 + m._32 + m._42;
	v.z = m._13 + m._23 + m._33 + m._43;
	v.w = m._14 + m._24 + m._34 + m._44;

	return v;
}

Vector2& Vector2::operator=(const Vector2& v)
{
	x = v.x;
	y = v.y;

	return *this;
}

Vector2& Vector2::operator=(const Vector3& v)
{
	x = v.x;
	y = v.y;

	return *this;
}

Vector2& Vector2::operator=(const Vector4& v)
{
	x = v.x;
	y = v.y;

	return *this;
}

bool Vector2::Normalize()
{
	float length = 1.0f / Length();

	if (length == 0.0f)
		return false;

	x = x * length;
	y = y * length;

	return true;
}

float Vector2::Length()
{
	return sqrt(x * x + y * y);
}

Vector2 Vector2::GetNomalVector()
{
	Vector2 v = *this;
	
	if (!v.Normalize())
		return Vector2(0,0);

	return v;
}

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::Vector2(const Vector2& v)
{
	x = v.x;
	y = v.y;
}


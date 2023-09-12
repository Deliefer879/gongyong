#include "Basic_Math.h"

bool Vector3::operator==(const Vector3& v)
{
	if (fabs(x - v.x) < EPSILON)
	{
		if (fabs(y - v.y) < EPSILON)
		{
			if (fabs(z - v.z) < EPSILON)
				return true;
		}
	}

	return false;
}

bool Vector3::operator!=(const Vector3& v)
{
	return !(*this == v);
}

float Vector3::operator|(const Vector3& v)
{
	return x * v.x + y * v.y + z * v.z;
}

Vector3 Vector3::operator^(const Vector3& v)
{
	return Vector3(y * v.z - z * v.y,
		z * v.x - x * v.z,
		x * v.y - y * v.x);
}

Vector4 Vector3::operator*(const Matrix m)
{
	Vector4 v;

	v.x = x * m._11 + y * m._21 + z * m._31 + m._41;
	v.y = x * m._12 + y * m._22 + z * m._32 + m._42;
	v.z = x * m._13 + y * m._23 + z * m._33 + m._43;
	v.w = m._14 + m._24 + m._34 + m._44;

	return v;
}

Vector3 Vector3::operator+(const Vector3& v)
{
	return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3 Vector3::operator-(const Vector3& v)
{
	return Vector3(x - v.x, y - v.y, z - v.z);
}

Vector3 Vector3::operator*(float val)
{
	return Vector3(x * val, y * val, z * val);
}

Vector3 Vector3::operator/(float val)
{
	return Vector3(x / val, y / val, z / val);
}

Vector3& Vector3::operator +=(const Vector3& v)
{
	x = x + v.x;
	y = y + v.y;
	z = z + v.z;

	return *this;
}

Vector3& Vector3::operator -=(const Vector3& v)
{
	x = x - v.x;
	y = y - v.y;
	z = z - v.z;

	return *this;
}

Vector3& Vector3::operator *=(float val)
{
	x = x * val;
	y = y * val;
	z = z * val;

	return *this;
}

Vector3& Vector3::operator /=(float val)
{
	x = x / val;
	y = y / val;
	z = z / val;

	return *this;
}

Vector3& Vector3::operator=(const Vector3& v)
{
	x = v.x;
	y = v.y;
	z = v.z;

	return *this;
}

Vector3& Vector3::operator=(const Vector2& v)
{
	x = v.x;
	y = v.y;
	z = 0;

	return *this;
}

Vector3& Vector3::operator=(const Vector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;

	return *this;
}

float Vector3::Length()
{
	return sqrt(x * x + y * y + z * z);
}

bool Vector3::Normalize()
{
	float length = 1.0f / Length();

	if (length == 0.0f)
		return false;

	x = x * length;
	y = y * length;
	z = z * length;

	return true;
}

Vector3 Vector3::GetNomalVector()
{
	Vector3 v = *this;

	if(!v.Normalize())
		return Vector3(0,0,0);

	return v;
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3(const Vector3& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}

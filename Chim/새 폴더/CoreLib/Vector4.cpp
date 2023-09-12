#include "Basic_Math.h"


bool Vector4::operator==(const Vector4& v)
{
    if (fabs(x - v.x) < EPSILON)
    {
        if (fabs(y - v.y) < EPSILON)
        {
            if (fabs(z - v.z) < EPSILON)
            {
                if (fabs(w - v.w) < EPSILON)
                    return true;
            }
        }
    }

    return false;
}

bool Vector4::operator!=(const Vector4& v)
{
    return !(*this == v);
}

float Vector4::operator|(const Vector4& v)
{
    return x * v.x + y * v.y + z * v.z + w * v.w;
}

Vector4 Vector4::operator*(const Matrix m)
{
    Vector4 v;

    v.x = x * m._11 + y * m._21 + z * m._31 + w * m._41;
    v.y = x * m._12 + y * m._22 + z * m._32 + w * m._42;
    v.z = x * m._13 + y * m._23 + z * m._33 + w * m._43;
    v.w = x * m._14 + y * m._24 + z * m._34 + w * m._44;

    return v;
}

Vector4 Vector4::operator+(const Vector4& v)
{
    return Vector4(x + v.x, y + v.y, z + v.z, w+v.w);
}

Vector4 Vector4::operator-(const Vector4& v)
{
    return Vector4(x - v.x, y - v.y, z - v.z, w-v.w);
}

Vector4 Vector4::operator*(float val)
{
    return Vector4(x * val, y * val, z * val, w*val);
}

Vector4 Vector4::operator/(float val)
{
    return Vector4(x / val, y / val, z / val, w/val);
}

Vector4& Vector4::operator+=(const Vector4& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;

    return *this;
}

Vector4& Vector4::operator-=(const Vector4& v)
{
    x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;

	return *this;
}

Vector4& Vector4::operator*=(float val)
{
    x *= val;
    y *= val;
    z *= val;
    w *= val;

    return *this;
}

Vector4& Vector4::operator/=(float val)
{
    x /= val;
	y /= val;
	z /= val;
	w /= val;

	return *this;
}

Vector4& Vector4::operator=(const Vector2& v)
{
    x = v.x;
    y = v.y;
    z = 0;
    w = 0;

    return *this;
}

Vector4& Vector4::operator=(const Vector3& v)
{
    x = v.x;
	y = v.y;
	z = v.z;
	w = 0;

	return *this;
}

Vector4& Vector4::operator=(const Vector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;

	return *this;
}

bool Vector4::Normalize()
{
    float length = Length();

	if (length == 0.0f)
		return false;

	x /= length;
	y /= length;
	z /= length;
	w /= length;

    return true;
}

 float Vector4::Length()
{
    return sqrt(x * x + y * y + z * z + w*w);
}

 Vector4 Vector4::GetNomalVector()
{
    Vector4 v = *this;

	if(!v.Normalize())
        return Vector4(0,0,0,0);

	return v;
}

 Vector4::Vector4(float x, float y, float z, float w)
{
    this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Vector4::Vector4(const Vector4& v)
{
    x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}


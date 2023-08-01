#pragma once

#include <cmath>

struct Float3
{
	union 
	{
		struct { float x, y, z; };
		float v[3]{0,0,0};
	};
};

class Vector3 : private Float3
{
public:
	float X() const { return x; }
	float Y() const { return y; }
	float Z() const { return z; }
	void X(float x) { this->x = x; }
	void Y(float y) { this->y = y; }
	void Z(float z) { this->z = z; }
	void Set(float x, float y, float z) { this->x = x; this->y = y; this->z = z; }
	void Set(Vector3 val) { this->x = val.x; this->y = val.y; this->z = val.z; }
	Vector3& Get() { return *this; }

	Vector3() = default;
	Vector3(float x, float y, float z);
	float Length() const;
	Vector3 Normalize() const;

	Vector3 operator+(const Vector3& other) const;
	Vector3 operator-(const Vector3& other) const;
	Vector3 operator*(const Vector3& other) const;
	Vector3 operator/(const Vector3& other) const;
	Vector3 operator*(float scalar) const;
	Vector3 operator/(float scalar) const;
	Vector3& operator+=(const Vector3& other);
	Vector3& operator-=(const Vector3& other);
	Vector3& operator*=(const Vector3& other);
	Vector3& operator/=(const Vector3& other);
	Vector3& operator*=(float scalar);
	Vector3& operator/=(float scalar);
	bool operator==(const Vector3& other) const;
	bool operator!=(const Vector3& other) const;
	Vector3& operator=(const Vector3& other);
};


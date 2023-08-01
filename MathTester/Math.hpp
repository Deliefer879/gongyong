#pragma once
#include <corecrt_math_defines.h>
#include <iostream>
#define EPSILON (0.000001f)
//#define RadianToDegree(radian) (radian*(180.0lf/ M_PI))
//#define DegreeToRadian(degree) (degree *(M_PI/180.0lf))
auto RadianToDegree = [](float radian) {
	return float(radian * (180.0f / M_PI));
};
auto DegreeToRadian = [](float degree) {
	return float(degree * (M_PI / 180.0f));
};

class Vector2 {
private:
	union
	{
		struct {
			float x, y;
		};
		float vector[2]{ 0.0f, };
	};


};

class Vector3 {
private:
	union
	{
		struct {
			float x, y, z;
		};
		float vector[3]{ 0.0f, };
	};

public:
	Vector3() {};
	inline Vector3(float _x, float _y, float _z) :x(_x), y(_y), z(_z) {};
	inline Vector3(Vector3& refp) {
		x = refp.x;
		y = refp.y;
		z = refp.z;
	}
	inline Vector3(Vector3&& refp) noexcept {
		x = refp.x;
		y = refp.y;
		z = refp.z;
	}
	inline Vector3& operator = (Vector3& refp) {
		x = refp.x;
		y = refp.y;
		z = refp.z;
		return (*this);
	}
	inline Vector3& operator = (Vector3&& refp) noexcept {
		x = refp.x;
		y = refp.y;
		z = refp.z;
		return (*this);
	}

	inline void SetX(float _x) { x=_x; };
	inline void SetY(float _y) { y=_y; };
	inline void SetZ(float _z) { z=_z; };
	inline void SetV(float _vector[]) {
		if (!(sizeof(*vector) / 3) == sizeof(float))_ASSERT("NOT CORRECT VECTOR ARRAY");
		x = _vector[0];
		y = _vector[1];
		z = _vector[2];
	};
	inline float GetX() { return x; };
	inline float GetY() { return y; };
	inline float GetZ() { return z; };
	inline float* GetV() { 
		float cpVector[3];
		memcpy(cpVector, vector, sizeof(vector));
		return std::move(cpVector); };
public:
	inline bool operator == (const Vector3& refp) {
		return ((fabs(x - refp.x) < EPSILON) && (fabs(y - refp.y) < EPSILON) && (fabs(z - refp.z) < EPSILON));
	};
	inline bool operator != (const Vector3& refp) {
		return !(this == &refp);
	};
	inline Vector3 operator + (const Vector3& p) {
		Vector3 cpVector;
		cpVector.x = x + p.x;
		cpVector.y = y + p.y;
		cpVector.z = z + p.z;
		return cpVector;
	};
	inline Vector3 operator - (const Vector3& p) {
		Vector3 cpVector;
		cpVector.x = x - p.x;
		cpVector.y = y - p.y;
		cpVector.z = z - p.z;
		return cpVector;
	};
	inline Vector3 operator + (float value) {
		Vector3 cpVector;
		cpVector.x = x + value;
		cpVector.y = y + value;
		cpVector.z = z + value;
		return cpVector;
	};
	inline Vector3 operator - (float value) {
		Vector3 cpVector;
		cpVector.x = x - value;
		cpVector.y = y - value;
		cpVector.z = z - value;
		return cpVector;
	};
	inline Vector3 operator * (float value) {
		Vector3 cpVector;
		cpVector.x = x * value;
		cpVector.y = y * value;
		cpVector.z = z * value;
		return cpVector;
	};
	inline void operator *= (float value) {
		x=x * value;
		y=y * value;
		z=z * value;
	};
	inline Vector3 operator / (float value) {
		if (value <= 0.0f)_ASSERT("ZERO DIVISION");
		Vector3 cpVector;
		cpVector.x = x / value;
		cpVector.y = y / value;
		cpVector.z = z / value;
		return cpVector;
	};
	inline void operator /= (float value) {
		if (value <= 0.0f)_ASSERT("ZERO DIVISION");
		x = x / value;
		y = y / value;
		z = z / value;
	}

	inline float operator |(Vector3& refp) {
		return x * refp.x + y * refp.y + z * refp.z;
	};
	inline Vector3 operator^ (Vector3& refp) {
		Vector3 cpVector;
		cpVector.x = this->y * refp.z - this->z * refp.y;
		cpVector.y = this->x * refp.z - this->z * refp.x;
		cpVector.z = this->x * refp.y - this->y * refp.x;
		return cpVector;
	};

public:
	inline float Angle(Vector3& p) {
		Vector3 a = NormalizeVector();
		Vector3 b = p.NormalizeVector();
		float cosAngle = a | b;
		float radian = acos(cosAngle);
		float degree = RadianToDegree(radian);
		return degree;
	}
	inline void Nomarlize() {
		float invertLength = 1.0f / Length();
		x = x * invertLength;
		y = y * invertLength;
		z = z * invertLength;
	};
	inline Vector3 NormalizeVector() {
		float invertLength = 1.0f / Length();
		return *this * invertLength;
	};
	inline float Length() {
		return sqrt((x * x) + (y * y) + (z * z));
	}
	inline float GetDistance(Vector3& refp) {
		return sqrt((refp.x * refp.x) + (refp.y * refp.y) + (refp.z * refp.z));
	}

};

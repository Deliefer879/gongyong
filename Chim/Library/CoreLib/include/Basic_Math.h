#pragma once

#include <math.h>
#include <stdlib.h>

const float PI = 3.1415926535897932384626433832795f;
const float EPSILON = 0.00001f;
inline float RadianToDegree(float radian) { return (radian * 180.0f / PI); }
inline float DegreeToRadian(float degree) { return (degree * PI / 180.0f); }
inline float RandRange(float min, float max) { return (min + (max - min) * rand() / RAND_MAX); }

class Vector2;
class Vector3;
class Vector4;
class Matrix;

#pragma region Floats

struct Float2
{
	union
	{
		struct { float x, y; };
		float v[2] = { 0, };
	};
};
struct Float3
{
	union
	{
		struct { float x, y, z; };
		float v[3] = { 0, };
	};
};
struct Float4
{
	union
	{
		struct { float x, y, z, w; };
		float v[4] = { 0, };
	};
};
struct Float4X4
{
	union
	{
		struct
		{
			float _11, _12, _13, _14;
			float _21, _22, _23, _24;
			float _31, _32, _33, _34;
			float _41, _42, _43, _44;
		};
		float m[4][4] = { 0, };
	};

	Float4X4() {};
};

#pragma endregion

class Vector2 : public Float2
{
public:
	bool	 operator == (const Vector2& v);
	bool	 operator != (const Vector2& v);

	float    operator |  (const Vector2& v); // dot
	Vector4  operator *  (const Matrix m);

	Vector2  operator +  (const Vector2& v);
	Vector2  operator -  (const Vector2& v);
	Vector2  operator *  (float val);
	Vector2  operator /  (float val);

	Vector2& operator += (const Vector2& v);
	Vector2& operator -= (const Vector2& v);
	Vector2& operator *= (float val);
	Vector2& operator /= (float val);

	Vector2& operator =  (const Vector2& v);
	Vector2& operator =  (const Vector3& v);
	Vector2& operator =  (const Vector4& v);
public:
	bool Normalize();
	float Length();
	Vector2 GetNomalVector();
public:
	Vector2();
	Vector2(float x, float y);
	Vector2(const Vector2& v);
};

class Vector3 : public Float3
{
public:
	bool	 operator == (const Vector3& v);
	bool	 operator != (const Vector3& v);

	float    operator |  (const Vector3& v); // dot
	Vector3  operator ^  (const Vector3& v); // cross
	Vector4  operator *  (const Matrix m);

	Vector3  operator +  (const Vector3& v);
	Vector3  operator -  (const Vector3& v);
	Vector3  operator *  (float val);
	Vector3  operator /  (float val);

	Vector3& operator += (const Vector3& v);
	Vector3& operator -= (const Vector3& v);
	Vector3& operator *= (float val);
	Vector3& operator /= (float val);

	Vector3& operator =  (const Vector3& v);
	Vector3& operator =  (const Vector2& v);
	Vector3& operator =  (const Vector4& v);
public:
	bool Normalize();
	float Length();
	Vector3 GetNomalVector();

public:
	Vector3() {};
	Vector3(float x, float y, float z);
	Vector3(const Vector3& v);
};

class Vector4 : public Float4
{
public:
	bool	 operator == (const Vector4& v);
	bool	 operator != (const Vector4& v);

	float    operator |  (const Vector4& v); // dot
	Vector4  operator *  (const Matrix m);

	Vector4  operator +  (const Vector4& v);
	Vector4  operator -  (const Vector4& v);
	Vector4  operator *  (float val);
	Vector4  operator /  (float val);

	Vector4& operator += (const Vector4& v);
	Vector4& operator -= (const Vector4& v);
	Vector4& operator *= (float val);
	Vector4& operator /= (float val);

	Vector4& operator =  (const Vector4& v);
	Vector4& operator =  (const Vector2& v);
	Vector4& operator =  (const Vector3& v);
public:
	bool Normalize();
	float Length();
	Vector4 GetNomalVector();

public:
	Vector4() {};
	Vector4(float x, float y, float z,float w);
	Vector4(const Vector4& v);
};

class Matrix : public Float4X4
{
public:
	Matrix& operator =  (const Matrix& mat);
	Matrix  operator *  (const Matrix& mat);

	Vector4 operator * (const Vector2& vec);
	Vector4 operator * (const Vector3& vec);
	Vector4 operator * (const Vector4& vec);
	float operator () (int iRow, int iColumn) const;
	float& operator () (int iRow, int iColumn);

public:
	void Identity();
	Matrix Transpose();

	void Translate(float x, float y, float z);
	void Translate(const Vector3& vec);
	void Scale(float x, float y, float z);
	void Scale(const Vector3& vec);
	void RotateX(float angle);
	void RotateY(float angle);
	void RotateZ(float angle);
public:
	Matrix();
	Matrix(float _11, float _12, float _13, float _14,
		float _21, float _22, float _23, float _24,
		float _31, float _32, float _33, float _34,
		float _41, float _42, float _43, float _44);
	Matrix(const Matrix& mat);
};


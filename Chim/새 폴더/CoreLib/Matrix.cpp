#include "Basic_Math.h"

#pragma region Matrix

Matrix& Matrix::operator =  (const Matrix& mat)
{
	if (this == &mat)
		return *this;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; j++)
			m[i][j] = mat.m[i][j];
	}
	return *this;
}

Matrix  Matrix::operator *  (const Matrix& mat)
{
	Matrix ret;

	for (int iColumn = 0; iColumn < 4; iColumn++)
	{
		for (int iRow = 0; iRow < 4; iRow++)
		{
			ret.m[iRow][iColumn] =
				m[iRow][0] * mat.m[0][iColumn] +
				m[iRow][1] * mat.m[1][iColumn] +
				m[iRow][2] * mat.m[2][iColumn] +
				m[iRow][3] * mat.m[3][iColumn];
		}
	}

	return ret;
}

Vector4 Matrix::operator*(const Vector4& vec)
{
	Vector4 ret;

	ret.x = vec.x * _11 + vec.y * _21 + vec.z * _31 + vec.w * _41;
	ret.y = vec.x * _12 + vec.y * _22 + vec.z * _32 + vec.w * _42;
	ret.z = vec.x * _13 + vec.y * _23 + vec.z * _33 + vec.w * _43;
	ret.w = vec.x * _14 + vec.y * _24 + vec.z * _34 + vec.w * _44;

	return ret;
}

Vector4 Matrix::operator * (const Vector3& vec)
{
	Vector4 ret;

	ret.x = vec.x * _11 + vec.y * _21 + vec.z * _31 + _41;
	ret.y = vec.x * _12 + vec.y * _22 + vec.z * _32 + _42;
	ret.z = vec.x * _13 + vec.y * _23 + vec.z * _33 + _43;
	ret.w = vec.x * _14 + vec.y * _24 + vec.z * _34 + _44;

	return ret;
}

Vector4 Matrix::operator * (const Vector2& vec)
{
	Vector4 ret;

	ret.x = vec.x * _11 + vec.y * _21 + _31 + _41;
	ret.y = vec.x * _12 + vec.y * _22 + _32 + _42;
	ret.z = vec.x * _13 + vec.y * _23 + _33 + _43;
	ret.w = vec.x * _14 + vec.y * _24 + _34 + _44;

	return ret;
}

float Matrix::operator () (int iRow, int iColumn) const
{
	return m[iRow][iColumn];
}

float& Matrix::operator () (int iRow, int iColumn)
{
	return m[iRow][iColumn];
}

void Matrix::Identity()
{
	m[0][0] = m[1][1] = m[2][2] = m[3][3] = 1.0f;

	m[0][1] = m[0][2] = m[0][3] = 0.0f;
	m[1][0] = m[1][2] = m[1][3] = 0.0f;
	m[2][0] = m[2][1] = m[2][3] = 0.0f;
	m[3][0] = m[3][1] = m[3][2] = 0.0f;
}

Matrix Matrix::Transpose()
{
	Matrix mat;
	mat.m[0][0] = m[0][0]; mat.m[0][1] = m[1][0]; mat.m[0][2] = m[2][0]; mat.m[0][3] = m[3][0];
	mat.m[1][0] = m[0][1]; mat.m[1][1] = m[1][1]; mat.m[1][2] = m[2][1]; mat.m[1][3] = m[3][1];
	mat.m[2][0] = m[0][2]; mat.m[2][1] = m[1][2]; mat.m[2][2] = m[2][2]; mat.m[2][3] = m[3][2];
	mat.m[3][0] = m[0][3]; mat.m[3][1] = m[1][3]; mat.m[3][2] = m[2][3]; mat.m[3][3] = m[3][3];

	return mat;
}

void Matrix::Translate(float x, float y, float z)
{
	_41 = x;
	_42 = y;
	_43 = z;
}
void Matrix::Translate(const Vector3& vec)
{
	_41 = vec.x;
	_42 = vec.y;
	_43 = vec.z;
}
void Matrix::Scale(float x, float y, float z)
{
	_11 = x;
	_22 = y;
	_33 = z;
}
void Matrix::Scale(const Vector3& vec)
{
	_11 = vec.x;
	_22 = vec.y;
	_33 = vec.z;
}
void Matrix::RotateX(float angle)
{
	float c = cosf(angle);
	float s = sinf(angle);

	_22 = c; _23 = s;
	_32 = -s; _33 = c;
}
void Matrix::RotateY(float angle)
{
	float c = cosf(angle);
	float s = sinf(angle);

	_11 = c; _13 = -s;
	_31 = s; _33 = c;
}
void Matrix::RotateZ(float angle)
{
	float c = cosf(angle);
	float s = sinf(angle);

	_11 = c; _12 = s;
	_21 = -s; _22 = c;
}

Matrix::Matrix()
{
	Identity();
}

Matrix::Matrix(float _11, float _12, float _13, float _14,
	float _21, float _22, float _23, float _24,
	float _31, float _32, float _33, float _34,
	float _41, float _42, float _43, float _44)
{
	m[0][0] = _11; m[0][1] = _12; m[0][2] = _13; m[0][3] = _14;
	m[1][0] = _21; m[1][1] = _22; m[1][2] = _23; m[1][3] = _24;
	m[2][0] = _31; m[2][1] = _32; m[2][2] = _33; m[2][3] = _34;
	m[3][0] = _41; m[3][1] = _42; m[3][2] = _43; m[3][3] = _44;
}

Matrix::Matrix(const Matrix& mat)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			m[i][j] = mat.m[i][j];
	}
}

#pragma endregion
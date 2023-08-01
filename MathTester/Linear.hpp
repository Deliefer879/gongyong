#pragma once
#include "Math.hpp"
//--a--> ������ ������ �Ÿ�
class Ray {
private:
	Vector3 position;
	Vector3 direction;
public:
	Ray() {};
	Ray(Vector3 pos, Vector3 direct) {
		position = pos;
		direction = direct;
	}
	float GetDistance(Vector3& p) {
		Vector3 vec = p - position;  //  �����ǿ��� P�� ���� ������ ������� p-position �ݴ���Ұ�� p���� position�ΰ��¹����� ���Ͱ� �������
		float k = (vec | direction) / (direction | direction); // (|vec||d|/|d||d|)d=k;
		Vector3 proj = direction * k; //k ���� direct �������� Segment ����
		Vector3 width = vec - proj; // vec== width+proj;
		return width.Length(); // sqrt(xx+yy+zz)
	}
};
class Plane {
private:
	Vector3 position;
	union {
		struct {
			float x, y, z;
		};
		Vector3 normalVector;
	}; 
	float direction;  // ax*bx+ay*by+az*bz+d=0 �϶� ����, -�� �ڷ� +�� ������ ������ D= (position|normalVector)�ǿ� ==-(p|n)
public:
	Vector3 GetPos() { return position; };
	Vector3 GetNormalVector() { return normalVector; };
	float GetX() { return x; };
	float GetY() { return y; };
	float GetZ() { return z; };
	float GetDirection() { return direction; };
public:
	Plane() {};
	Plane(Vector3 pos, Vector3 direct) {
		normalVector = direct.NormalizeVector();
		position = pos;
		direction = -(normalVector | position);
	};
	Plane(Vector3 pos1, Vector3 pos2, Vector3 pos3) {
		position = pos1; //������
		Vector3 edge1 = pos2 - position;   //������ �������� �ﰢ���� ���;���.
		Vector3 edge2 = pos3 - position;
		normalVector = (edge1 ^ edge2).NormalizeVector(); //�����Ͽ� ����Vector�� ����ȭ�Ͽ� ��ȯ egde1�� edge2�� ������ �������� ��������.
		direction = -(normalVector | position);
	}
	float GetDistance(Vector3& refp) { return ((x * refp.GetX()) + (y * refp.GetY()) + (z * refp.GetZ()) + direction); };
};
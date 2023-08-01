#pragma once
#include "Math.hpp"
//--a--> 직선과 한점의 거리
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
		Vector3 vec = p - position;  //  포지션에서 P로 가는 방향을 만들려면 p-position 반대로할경우 p에서 position로가는방향의 벡터가 만들어짐
		float k = (vec | direction) / (direction | direction); // (|vec||d|/|d||d|)d=k;
		Vector3 proj = direction * k; //k 에서 direct 까지가는 Segment 생성
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
	float direction;  // ax*bx+ay*by+az*bz+d=0 일때 같음, -는 뒤로 +는 앞으로 떨어짐 D= (position|normalVector)의역 ==-(p|n)
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
		position = pos1; //기준점
		Vector3 edge1 = pos2 - position;   //기준점 방향으로 삼각형이 나와야함.
		Vector3 edge2 = pos3 - position;
		normalVector = (edge1 ^ edge2).NormalizeVector(); //외적하여 나온Vector를 정규화하여 반환 egde1과 edge2는 동일한 기준점을 가져야함.
		direction = -(normalVector | position);
	}
	float GetDistance(Vector3& refp) { return ((x * refp.GetX()) + (y * refp.GetY()) + (z * refp.GetZ()) + direction); };
};
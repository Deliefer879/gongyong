#pragma once

#include "Vector3.h"

class Collider
{
private:
	union 
	{
		struct { float x, y, z, w, h, d; };
		struct { Vector3 pos, size; };
	};
	Vector3 min;
	Vector3 max;
	Vector3 center;

	virtual void UpdatePoints() = 0;
public:
	float X() const { return x; }
	float Y() const { return y; }
	virtual float Z() const { return z; }
	float W() const { return w; }
	float H() const { return h; }
	virtual float D() const { return d; }
	Vector3 Pos() const { return pos; }
	Vector3 Size() const { return size; }
	Vector3 Min() const { return min; }
	Vector3 Max() const { return max; }
	Vector3 Center() const { return center; }
	void X(float x) { this->x = x; }
	void Y(float y) { this->y = y; }
	virtual void Z(float z) { this->z = z; }
	void W(float w) { this->w = w; }
	void H(float h) { this->h = h; }
	virtual void D(float d) { this->d = d; }
	void Pos(const Vector3& pos) { this->pos = pos; UpdatePoints(); }
	void Size(const Vector3& size) { this->size = size; }
	void Min(const Vector3& min) { this->min = min; }
	void Max(const Vector3& max) { this->max = max; }
	void Center(const Vector3& center) { this->center = center; }
	virtual void Set(Vector3 pos, Vector3 size) = 0;
	
	Collider() : x(0), y(0), z(0), w(0), h(0), d(0), min({ 0,0,0 }), max({ 0,0,0 }), center({0,0,0}) {};
	virtual ~Collider() {};
};

class Rect : public Collider
{
private:
	virtual void UpdatePoints() override;
public:
	Rect() {};
	Rect(float x, float y, float w, float h);
	Rect(Vector3 pos, Vector3 size);
	virtual ~Rect() {};

	virtual float Z() const override { return 0; }
	virtual float D() const override { return 0; }
	virtual void Z(float z) override { }
	virtual void D(float d) override { }	

	void Set(float x, float y, float w, float h);
	virtual void Set(Vector3 pos, Vector3 size) override;
	void Set(const Rect& rect);

	Rect operator+(const Rect& other) const;
	Rect operator-(const Rect& other) const;
	Rect operator*(float scalar) const;
	Rect operator/(float scalar) const;
	Rect& operator*=(float scalar);
	Rect& operator/=(float scalar);
	bool operator==(const Rect& other) const;
	bool operator!=(const Rect& other) const;
	Rect& operator=(const Rect& other);
};

class Cube : public Collider
{
private:
	virtual void UpdatePoints() override;
public:
	Cube() {};
	Cube(float x, float y, float z, float w, float h, float d);
	Cube(Vector3 pos, Vector3 size);
	virtual ~Cube() {};

	void Set(float x, float y, float z, float w, float h, float d);
	virtual void Set(Vector3 pos, Vector3 size) override;
	void Set(const Cube& cube);

	Cube operator+(const Cube& other) const;
	Cube operator-(const Cube& other) const;
	Cube operator*(float scalar) const;
	Cube operator/(float scalar) const;
	Cube& operator*=(float scalar);
	Cube& operator/=(float scalar);
	bool operator==(const Cube& other) const;
	bool operator!=(const Cube& other) const;
	Cube& operator=(const Cube& other);
};

#include "Collider.h"

void Rect::UpdatePoints()
{
	Min({ X(),Y(),Z() });
	Max({ X() + W(),Y() + H(),Z() + D() });
	Center( (Min() + Max())/2 );
}

Rect::Rect(float x, float y, float w, float h)
{
	Set(x, y, w, h);
}

Rect::Rect(Vector3 pos, Vector3 size)
{
	Set(pos,size);
}

void Rect::Set(float x, float y, float w, float h)
{
	X(x);
	Y(y);
	W(w);
	H(h);

	UpdatePoints();
}

void Rect::Set(Vector3 pos, Vector3 size)
{
	Pos(pos);
	Size(size);

	UpdatePoints();
}

void Rect::Set(const Rect& rect)
{
	Pos(rect.Pos());
	Size(rect.Size());

	UpdatePoints();
}

bool Rect::Collision(Collider* const collider)
{
	Rect* rect2 = dynamic_cast<Rect*>(collider);

	Rect uCube = *this + *rect2;

	if (uCube.W() <= (W() + (*rect2).W()) &&
		uCube.H() <= (H() + (*rect2).H()))
		return true;

	return false;
}

Rect Rect::operator+(const Rect& other) const
{
	Rect unionRect;

	float x = Min().X() < other.Min().X() ? Min().X() : other.Min().X();
	float y = Min().Y() < other.Min().Y() ? Min().Y() : other.Min().Y();
	float w = Max().X() > other.Max().X() ? Max().X() : other.Max().X(); w = w - x;
	float h = Max().Y() > other.Max().Y() ? Max().Y() : other.Max().Y(); h = h - y;

	unionRect.Set(x, y, w, h);

	return unionRect;
}

// not implemented currently
Rect Rect::operator-(const Rect& other) const
{
	return Rect();
}

Rect Rect::operator*(float scalar) const
{
	return Rect({Pos(), Size() * scalar});
}

Rect Rect::operator/(float scalar) const
{
	return Rect({ Pos(), Size() / scalar });
}

Rect& Rect::operator*=(float scalar)
{
	this->Size() *= scalar;
	UpdatePoints();

	return *this;	
}

Rect& Rect::operator/=(float scalar)
{
	this->Size() /= scalar;
	UpdatePoints();

	return *this;
}

bool Rect::operator==(const Rect& other) const
{
	if(Pos() == other.Pos())
		if(Size() == other.Pos())
			return true;

	return false;
}
bool Rect::operator!=(const Rect& other) const
{
	return !(*this == other);
}
Rect& Rect::operator=(const Rect& other)
{
	this->X(other.X());
	this->Y(other.Y());
	this->W(other.W());
	this->H(other.H());
	UpdatePoints();

	return *this;
}
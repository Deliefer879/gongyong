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

Rect Rect::operator+(const Rect& other) const
{
	Rect unionRect;

	float x = Min().X() < other.Min().X() ? Min().X() : other.Min().X();
	float y = Min().Y() < other.Min().Y() ? Min().Y() : other.Min().Y();
	float w = Max().X() > other.Max().X() ? Max().X() : other.Max().X();
	float h = Max().Y() > other.Max().Y() ? Max().Y() : other.Max().Y();

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
	return Rect({Pos() * scalar, Size() * scalar});
}

Rect Rect::operator/(float scalar) const
{
	return Rect({ Pos() / scalar, Size() / scalar });
}

Rect& Rect::operator*=(float scalar)
{
	X(X() * scalar);
	Y(Y() * scalar);
	W(W() * scalar);
	H(H() * scalar);
	UpdatePoints();

	return *this;	
}

Rect& Rect::operator/=(float scalar)
{
	X(X() / scalar);
	Y(Y() / scalar);
	W(W() / scalar);
	H(H() / scalar);
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
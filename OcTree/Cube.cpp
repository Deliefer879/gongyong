#include "Collider.h"

void Cube::UpdatePoints()
{
    Min({ X(),Y(),Z() });
    Max({ X() + W(),Y() + H(),Z() + D() });
    Center((Min() + Max()) / 2);
}

Cube::Cube(float x, float y, float z, float w, float h, float d)
{
    Set(x, y, z, w, h, d);
}

Cube::Cube(Vector3 pos, Vector3 size)
{
    Set(pos, size);
}

void Cube::Set(float x, float y, float z, float w, float h, float d)
{
    X(x);
    Y(y);
    Z(z);
    W(w);
    H(h);
    D(d);
    
    UpdatePoints();
}

void Cube::Set(Vector3 pos, Vector3 size)
{
    Pos(pos);
    Size(size);

    UpdatePoints();
}

void Cube::Set(const Cube& cube)
{
    Pos(cube.Pos());
    Size(cube.Size());

    UpdatePoints();
}

bool Cube::Collision(Collider* const collider)
{
    Cube* cube2 = dynamic_cast<Cube*>(collider);

    Cube uCube = *this + *cube2;

    if (uCube.W() <= (W() + (*cube2).W()) &&
        uCube.H() <= (H() + (*cube2).H()) &&
        uCube.D() <= (D() + (*cube2).D()))
        return true;

    return false;
}

Cube Cube::operator+(const Cube& other) const
{
    Cube unionCube;

    float x = Min().X() < other.Min().X() ? Min().X() : other.Min().X();
    float y = Min().Y() < other.Min().Y() ? Min().Y() : other.Min().Y();
    float z = Min().Z() < other.Min().Z() ? Min().Z() : other.Min().Z();
    float w = Max().X() > other.Max().X() ? Max().X() : other.Max().X(); w = w - x;
    float h = Max().Y() > other.Max().Y() ? Max().Y() : other.Max().Y(); h = h - y;
    float d = Max().Z() > other.Max().Z() ? Max().Z() : other.Max().Z(); d = d - z;

    unionCube.Set(x, y, z, w, h, d);

    return unionCube;
}

// not implemented currently
Cube Cube::operator-(const Cube& other) const
{
    return Cube();
}

Cube Cube::operator*(float scalar) const
{
    return Cube(Pos(), Size() * scalar);
}

Cube Cube::operator/(float scalar) const
{
    return Cube(Pos(), Size() / scalar);
}

Cube& Cube::operator*=(float scalar)
{
    this->Size() *= scalar;
    UpdatePoints();

    return *this;
}

Cube& Cube::operator/=(float scalar)
{
    this->Size() /= scalar;
    UpdatePoints();

    return *this;
}

bool Cube::operator==(const Cube& other) const
{
    if (Pos() == other.Pos())
        if (Size() == other.Pos())
            return true;

    return false;
}

bool Cube::operator!=(const Cube& other) const
{
    return !(*this == other);
}

Cube& Cube::operator=(const Cube& other)
{
    this->Set(other);

    return *this;
}

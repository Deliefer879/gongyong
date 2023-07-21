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
    W(w);
    H(h);
    Z(z);
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

Cube Cube::operator+(const Cube& other) const
{
    return Cube();
}

Cube Cube::operator-(const Cube& other) const
{
    return Cube();
}

Cube Cube::operator*(float scalar) const
{
    return Cube();
}

Cube Cube::operator/(float scalar) const
{
    return Cube();
}

Cube& Cube::operator*=(float scalar)
{
    // TODO: 여기에 return 문을 삽입합니다.
    return *this;
}

Cube& Cube::operator/=(float scalar)
{
    // TODO: 여기에 return 문을 삽입합니다.
    return *this;
}

bool Cube::operator==(const Cube& other) const
{
    return false;
}

bool Cube::operator!=(const Cube& other) const
{
    return false;
}

Cube& Cube::operator=(const Cube& other)
{
    // TODO: 여기에 return 문을 삽입합니다.
    return *this;
}

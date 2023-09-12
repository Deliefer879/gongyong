#include "Utils.h"
#include "Collision.h"

bool Rect::operator == (const Rect& rect)
{
	return (center == rect.center && size == rect.size);
}
bool Rect::operator != (const Rect& rect)
{
	return !(*this == rect);
}
Rect Rect::operator + (const Rect& rect)
{
    Rect rt;
    float fMinX = min.x < rect.min.x ? min.x : rect.min.x;
    float fMinY = min.y < rect.min.y ? min.y : rect.min.y;
    float fMaxX = max.x > rect.max.x ? max.x : rect.max.x;
    float fMaxY = max.y > rect.max.y ? max.y : rect.max.y;

    Vector2 center = { (fMinX + fMaxX) * 0.5f, (fMinY + fMaxY) * 0.5f };
    rt.SetRect(center, { fMaxX - fMinX, fMaxY - fMinY }); \

    return rt;
}
Rect Rect::operator - (const Rect& rect)
{
    Rect rt;

    if (ToRect(rect))
    {
        float fx = min.x > rect.min.x ? min.x : rect.min.x;
        float fy = min.y > rect.min.y ? min.y : rect.min.y;
        float right = max.x < rect.max.x ? max.x : rect.max.x;
        float bottom = max.y < rect.max.y ? max.y : rect.max.y;

        Vector2 center = { (fx + right) * 0.5f, (fy + bottom) * 0.5f };
        rt.SetRect(center, { right - fx, bottom - fy });
    }

    return rt;
}
Rect Rect::operator * (float val)
{
    Rect rt;
    rt.SetRect(center, size * val);
    return rt;
}
Rect Rect::operator / (float val)
{
    Rect rt;
    rt.SetRect(center, size / val);
    return rt;
}
Rect& Rect::operator *= (float val)
{
    size *= val;
    return *this;
}
Rect& Rect::operator /= (float val)
{
    size /= val;
    return *this;
}

Rect& Rect::operator = (const Rect& rect)
{
    this->center = rect.center;
    this->size = rect.size;
    this->min = rect.min;
    this->max = rect.max;

    return *this;
}

void Rect::SetRect(float x, float y, float width, float height)
{
	center = { x,y };
	size = { width,height };
	max = { x + width * 0.5f,y + height * 0.5f };
	min = { x - width * 0.5f,y - height * 0.5f };
}
void Rect::SetRect(Vector2 center, Vector2 size)
{
    this->center = center;
    this->size = size;
    max = { center.x + size.x * 0.5f, center.y + size.y * 0.5f };
    min = { center.x - size.x * 0.5f, center.y - size.y * 0.5f };
}
void Rect::SetRect(Rect rect)
{
    center = rect.center;
	size = rect.size;
	max = rect.max;
	min = rect.min;
}
void Rect::SetPosition(float x, float y)
{
    center = { x,y };
    max = { center.x + size.x * 0.5f, center.y + size.y * 0.5f };
    min = { center.x - size.x * 0.5f, center.y - size.y * 0.5f };
}
void Rect::SetPosition(Vector2 position)
{
    center = position;
    max = { center.x + size.x * 0.5f, center.y + size.y * 0.5f };
    min = { center.x - size.x * 0.5f, center.y - size.y * 0.5f };
}
void Rect::SetSize(float width, float height)
{
    size = { width,height };
	max = { center.x + size.x * 0.5f, center.y + size.y * 0.5f };
	min = { center.x - size.x * 0.5f, center.y - size.y * 0.5f };
}
void Rect::SetSize(Vector2 size)
{
    size = size;
	max = { center.x + size.x * 0.5f, center.y + size.y * 0.5f };
	min = { center.x - size.x * 0.5f, center.y - size.y * 0.5f };
}

bool Rect::ToPoint(Vector2 point)
{
    return Collision::RectToPoint(point, *this);
}

bool Rect::ToRect(Rect rect)
{
    return Collision::RectToRect(*this, rect);
}
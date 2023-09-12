#include "Collision.h"
#include "Utils.h"

Vector2 GetHeightVec(Rect rt)
{
    Vector2 heightVec = { 0,0 };

    heightVec.x = rt.size.y * cos(DegreeToRadian(rt.angle - 90)) * 0.5f;
    heightVec.y = rt.size.y * -sin(DegreeToRadian(rt.angle - 90)) * 0.5f;

    return heightVec;
}

Vector2 GetWidthVec(Rect rt)
{
    Vector2 widthVec = { 0,0 };

    widthVec.x = rt.size.x * cos(DegreeToRadian(rt.angle)) * 0.5f;
    widthVec.y = rt.size.x * sin(DegreeToRadian(rt.angle)) * 0.5f;

    return widthVec;
}

bool Collision::RectToPoint(Vector2& point, Rect& rect)
{
    if (rect.min.x <= point.x && rect.max.x >= point.x
        && rect.min.y <= point.y && rect.max.y >= point.y)
        return true;

    return false;
}

bool Collision::RectToRect(Rect& rect1, Rect& rect2)
{
    Vector2 distanceVec = rect2.center - rect1.center;
    Vector2 vec[4] = { GetHeightVec(rect1),GetHeightVec(rect2),GetWidthVec(rect1),GetWidthVec(rect2) };
    Vector2 unit;
    float sum;

    for (int i = 0; i < 4; ++i)
    {
        sum = 0;
        unit = vec[i].GetNomalVector();

        for (int j = 0; j < 4; ++j)
        {
            float b = vec[j] | unit;
            sum += fabs(vec[j] | unit);
        }

        float a = distanceVec | unit;

        if (fabs(distanceVec | unit) > sum)
            return false;
    }

    return true;
}

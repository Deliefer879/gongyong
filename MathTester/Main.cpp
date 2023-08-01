#include <iostream>
#include "Linear.hpp"

int main()
{
    Vector3 sex(0,0,45);
    Vector3 yas(50,100 , 0);
    Vector3 p(0,16,5);
    Ray ok(sex, yas);
    float ho =   ok.GetDistance(p);
    Plane hi(sex,yas,p);
    float hl = hi.GetDistance(p);
    yas /= 0;
    std::cout << ho << "\n";
    std::cout << hi.GetDirection()<<"\n";
    std::cout << ho << "\n";

#pragma region ->사이각 반환(180내의 작은값)
    /// <summary>
    /// 사이각 반환(180내의 작은값)
    /// </summary>   
    Vector3  x(1, 0, 0);
    Vector3  z(0, 0, 1);
    Vector3  y = (z ^ x);// up
    float fDot1 = y | x;
    float fDot2 = y | z;
    float fDegree = z.Angle(x);
#pragma endregion <-사이각 반환(180내의 작은값)
#pragma region ->직선과 한점의 거리 반환
    /// <summary>
    /// 직선과 한점의 거리 반환
    /// </summary>
    /// <returns></returns>
    Ray ray(Vector3(0,0,0),Vector3(10000,0,0));
    Vector3  p0(10, 0, -7);
    float fDistance = ray.GetDistance(p0);
#pragma endregion 
#pragma region ->평면과 한점의 거리
    /// <summary>
    /// 평면과 한점의 거리
    /// </summary>
    /// <returns></returns>
    Plane plane1(Vector3(10, -10, 0), Vector3(1, 0, 0));
    Plane plane2(Vector3(0, -10, 0), Vector3(0, -10, 10), Vector3(10, -10, 0));
    Vector3 p1(20, 30, 40);
    float f0 = plane1.GetDistance(p1);
    float f1 = plane2.GetDistance(p1);
#pragma endregion 
#pragma region ->임의의 벡터를 기준으로 360로 반환한다
    /// <summary>
    /// 임의의 벡터를 기준으로 360로 반환한다.
    /// </summary>
    /// <returns></returns>
    Vector3  v(10, 0, -10);
    v.NormalizeVector();
    Vector3  up = (z ^ v);
    up.NormalizeVector();
    float fDot3 = up | y;
    float fDegree360 = 0.0f;
    if (fDot3 > 0.0f)
    {
        fDegree360 = z.Angle(v);
    }
    else
    {
        fDegree360 = (180.0f - z.Angle(v)) + 180.0f;
    }
#pragma endregion 

}
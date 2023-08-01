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
    std::cout << ho << "\n";
    std::cout << hi.GetDirection()<<"\n";
    std::cout << ho << "\n";
}
#pragma once
#include "UActorComponent.h"
class AActor
{
public:
    virtual void BeginPlay() {}
    virtual void Tick(float deltaTime) {}
    virtual void EndPlay() {}

    virtual ~AActor() {}

    shared_ptr<IUActorComponent> m_pRootComponent;
protected:
    int             m_ID;
    int             m_CurrentSceneID;
    bool            m_bDead;
};


// TODO: 이거 어떻게 처리할지 고민해보기
//void MoveTo(float destX, float destY, float destZ, float speed) {
//    m_dest.x = destX;
//    m_dest.y = destY;
//    m_dest.z = destZ;
//    m_speed = speed;
//    m_isMoving = true;
//}
//XMFLOAT3 m_dest;   // 목적지
//float m_speed;     // 속도
//bool m_isMoving;   // 움직이고 있는지 여부
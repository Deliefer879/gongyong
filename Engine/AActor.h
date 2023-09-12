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


// TODO: �̰� ��� ó������ ����غ���
//void MoveTo(float destX, float destY, float destZ, float speed) {
//    m_dest.x = destX;
//    m_dest.y = destY;
//    m_dest.z = destZ;
//    m_speed = speed;
//    m_isMoving = true;
//}
//XMFLOAT3 m_dest;   // ������
//float m_speed;     // �ӵ�
//bool m_isMoving;   // �����̰� �ִ��� ����
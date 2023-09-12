#include "pch.h"
#include "AActor.h"
    //if (m_isMoving) {
    //    // 현재 위치와 목적지 사이의 거리를 계산
    //    float dx = m_dest.x - m_PositionVector.x;
    //    float dy = m_dest.y - m_PositionVector.y;
    //    float dz = m_dest.z - m_PositionVector.z;
    //    float distance = std::sqrt(dx * dx + dy * dy + dz * dz);

    //    // 실제 이동할 속도를 계산
    //    float actualSpeed = m_speed * deltaTime;

    //    // 목적지에 도착했는지 확인
    //    if (distance < actualSpeed) {
    //        m_PositionVector = m_dest;
    //        m_isMoving = false;
    //    }
    //    else {
    //        // 단위 벡터를 계산
    //        float ux = dx / distance;
    //        float uy = dy / distance;
    //        float uz = dz / distance;

    //        // 매 프레임마다 속도에 따라 이동
    //        m_PositionVector.x += ux * actualSpeed;
    //        m_PositionVector.y += uy * actualSpeed;
    //        m_PositionVector.z += uz * actualSpeed;
    //    }

    //    // AABB 위치 갱신
    //    AABB.SetCenter(m_PositionVector.x, m_PositionVector.y ); // 가정: TVector2는 x, y 좌표를 저장
    //}
    //// 이동했으니까 월드 행렬을 갱신
    //UpdateWorldMatrix();
#include "pch.h"
#include "AActor.h"
    //if (m_isMoving) {
    //    // ���� ��ġ�� ������ ������ �Ÿ��� ���
    //    float dx = m_dest.x - m_PositionVector.x;
    //    float dy = m_dest.y - m_PositionVector.y;
    //    float dz = m_dest.z - m_PositionVector.z;
    //    float distance = std::sqrt(dx * dx + dy * dy + dz * dz);

    //    // ���� �̵��� �ӵ��� ���
    //    float actualSpeed = m_speed * deltaTime;

    //    // �������� �����ߴ��� Ȯ��
    //    if (distance < actualSpeed) {
    //        m_PositionVector = m_dest;
    //        m_isMoving = false;
    //    }
    //    else {
    //        // ���� ���͸� ���
    //        float ux = dx / distance;
    //        float uy = dy / distance;
    //        float uz = dz / distance;

    //        // �� �����Ӹ��� �ӵ��� ���� �̵�
    //        m_PositionVector.x += ux * actualSpeed;
    //        m_PositionVector.y += uy * actualSpeed;
    //        m_PositionVector.z += uz * actualSpeed;
    //    }

    //    // AABB ��ġ ����
    //    AABB.SetCenter(m_PositionVector.x, m_PositionVector.y ); // ����: TVector2�� x, y ��ǥ�� ����
    //}
    //// �̵������ϱ� ���� ����� ����
    //UpdateWorldMatrix();
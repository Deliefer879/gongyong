#pragma once

namespace Util {

#include <DirectXMath.h>

    struct Rect {
        DirectX::XMVECTOR CenterSize; // [CenterX, CenterY, Width, Height]

        Rect() : CenterSize(DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f)) {}
        
        Rect(DirectX::XMVECTOR centerSize) : CenterSize(centerSize) {}

        Rect(float x, float y, float w, float h)
            : CenterSize(DirectX::XMVectorSet(x, y, w, h)) {}

        void SetCenter(float x, float y) {
            CenterSize = DirectX::XMVectorSetW(CenterSize, y);
            CenterSize = DirectX::XMVectorSetZ(CenterSize, x);
        }

        void SetDimensions(float width, float height) {
            CenterSize = DirectX::XMVectorSetY(CenterSize, height);
            CenterSize = DirectX::XMVectorSetX(CenterSize, width);
        }

        bool IsPointInside(float x, float y) const {
            DirectX::XMVECTOR point = DirectX::XMVectorSet(x, y, 0.0f, 0.0f);
            DirectX::XMVECTOR halfSize = DirectX::XMVectorScale(DirectX::XMVectorSwizzle<2, 3, 2, 3>(CenterSize), 0.5f);
            DirectX::XMVECTOR minCorner = DirectX::XMVectorSubtract(DirectX::XMVectorSwizzle<0, 1, 0, 1>(CenterSize), halfSize);
            DirectX::XMVECTOR maxCorner = DirectX::XMVectorAdd(DirectX::XMVectorSwizzle<0, 1, 0, 1>(CenterSize), halfSize);

            return DirectX::XMVector3GreaterOrEqual(point, minCorner) && DirectX::XMVector3LessOrEqual(point, maxCorner);
        }

        bool IsOverlapping(const Rect& other) const {
            DirectX::XMVECTOR halfSize = DirectX::XMVectorScale(DirectX::XMVectorSwizzle<2, 3, 2, 3>(CenterSize), 0.5f);
            DirectX::XMVECTOR minCorner = DirectX::XMVectorSubtract(DirectX::XMVectorSwizzle<0, 1, 0, 1>(CenterSize), halfSize);
            DirectX::XMVECTOR maxCorner = DirectX::XMVectorAdd(DirectX::XMVectorSwizzle<0, 1, 0, 1>(CenterSize), halfSize);

            DirectX::XMVECTOR otherHalfSize = DirectX::XMVectorScale(DirectX::XMVectorSwizzle<2, 3, 2, 3>(other.CenterSize), 0.5f);
            DirectX::XMVECTOR otherMinCorner = DirectX::XMVectorSubtract(DirectX::XMVectorSwizzle<0, 1, 0, 1>(other.CenterSize), otherHalfSize);
            DirectX::XMVECTOR otherMaxCorner = DirectX::XMVectorAdd(DirectX::XMVectorSwizzle<0, 1, 0, 1>(other.CenterSize), otherHalfSize);

            return DirectX::XMVector3LessOrEqual(minCorner, otherMaxCorner) && DirectX::XMVector3GreaterOrEqual(maxCorner, otherMinCorner);
        }
    };
}

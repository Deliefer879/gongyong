#include "Camera.h"
#include "Constant.h"

void Camera::SetViewMatrix(Vector3 target)
{
    Vector3 upVec = { 0,1,0 };

    Vector3 zAxis = target - camPos;
    zAxis.Normalize();

    float dot = upVec | zAxis;
    Vector3 yAxis = upVec - (zAxis * dot);
    yAxis.Normalize();

    Vector3 xAxis = yAxis ^ zAxis;

    viewMatrix._11 = xAxis.x; viewMatrix._12 = yAxis.x; viewMatrix._13 = zAxis.x; viewMatrix._14 = 0.0f;
    viewMatrix._21 = xAxis.y; viewMatrix._22 = yAxis.y; viewMatrix._23 = zAxis.y; viewMatrix._24 = 0.0f;
    viewMatrix._31 = xAxis.z; viewMatrix._32 = yAxis.z; viewMatrix._33 = zAxis.z; viewMatrix._34 = 0.0f;

    viewMatrix._41 = -(camPos.x * viewMatrix._11 + camPos.y * viewMatrix._21 + camPos.z * viewMatrix._31);
    viewMatrix._42 = -(camPos.x * viewMatrix._12 + camPos.y * viewMatrix._22 + camPos.z * viewMatrix._32);
    viewMatrix._43 = -(camPos.x * viewMatrix._13 + camPos.y * viewMatrix._23 + camPos.z * viewMatrix._33);
}

void Camera::SetProjMatrix(float fov, float aspect, float nearPlane, float farPlane)
{
    float h, w, q;

	h = 1.0f / tan(fov * 0.5f);
	w = h / aspect;
    q = farPlane / (farPlane - nearPlane);

	projMatrix._11 = w;
	projMatrix._22 = h;
    projMatrix._33 = q;
	projMatrix._34 = 1.0f;
	projMatrix._43 = -q * nearPlane;
	projMatrix._44 = 0.0f;
}

bool Camera::Init()
{
	camPosXInterval = g_Constant.g_winSizeX/2;
	camPosYInterval = g_Constant.g_winSizeY/2;

    camPos = {0,0,0};

	return true;
}
bool Camera::Frame()
{
    if (camPos.x < -g_Constant.g_mapSizeX + camPosXInterval)
    {
        camPos.x = -g_Constant.g_mapSizeX + camPosXInterval;
    }
    if (camPos.y < -g_Constant.g_mapSizeY + camPosYInterval)
    {
        camPos.y = -g_Constant.g_mapSizeY + camPosYInterval;
    }
    if (camPos.x > g_Constant.g_mapSizeX - camPosXInterval)
    {
        camPos.x = g_Constant.g_mapSizeX - camPosXInterval;
    }
    if (camPos.y > g_Constant.g_mapSizeY - camPosYInterval)
    {
        camPos.y = g_Constant.g_mapSizeY - camPosYInterval;
    }

    viewMatrix._41 = -camPos.x;
    viewMatrix._42 = -camPos.y;
    viewMatrix._43 = -camPos.z;
    orthoprojMatrix._11 = 2.0f / ((float)g_Constant.g_winSizeX);
    orthoprojMatrix._22 = 2.0f / ((float)g_Constant.g_winSizeY);

    return true;
}
bool Camera::Render()
{
	return true;
}
bool Camera::Release()
{
	return true;
}
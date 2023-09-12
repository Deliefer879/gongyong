#pragma once

#include "Std.h"

class Camera
{
public:
	Matrix viewMatrix;
	Matrix orthoprojMatrix;
	Matrix projMatrix;
	
	Vector3 camPos;

	float camPosXInterval;
	float camPosYInterval;

public:
	void SetViewMatrix(Vector3 target);
	void SetProjMatrix(float fov, float aspect, float nearPlane, float farPlane);
public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
};


#pragma once

#include "Singleton.hpp"
#include "Camera.h"

class Camera;

class CameraManger : public Singleton<CameraManger>
{
private:
	friend class Singleton<CameraManger>;
	CameraManger();
	~CameraManger();

	std::vector<std::shared_ptr<Camera>> cameraList;
public:
	void AddCamera(Camera* camera);

	std::weak_ptr<Camera> GetCurrentCamera();

	bool Init();
	bool Frame();
	bool Render();
	bool Release();
};

#define MainCamera CameraManger::GetInstance().GetCurrentCamera().lock()

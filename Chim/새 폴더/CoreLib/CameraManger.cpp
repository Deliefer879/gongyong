#include "CameraManger.h"


CameraManger::CameraManger()
{
}

CameraManger::~CameraManger()
{
}

void CameraManger::AddCamera(Camera* camera)
{
	cameraList.push_back(std::shared_ptr<Camera>(camera));
}

std::weak_ptr<Camera> CameraManger::GetCurrentCamera()
{
	if(cameraList.size() > 0)
		return cameraList[0];

	cameraList.push_back(std::make_shared<Camera>());
	return cameraList[0];
}

bool CameraManger::Init()
{
	cameraList.push_back(std::make_shared<Camera>());

	for (int i = 0; i < cameraList.size(); ++i)
	{
		cameraList[i]->Init();
	}

	return true;
}

bool CameraManger::Frame()
{
	for (int i = 0; i < cameraList.size(); ++i)
		cameraList[i]->Frame();

	return true;
}

bool CameraManger::Render()
{
	for (int i = 0; i < cameraList.size(); ++i)
		cameraList[i]->Render();

	return true;
}

bool CameraManger::Release()
{
	for (int i = 0; i < cameraList.size(); ++i)
		cameraList[i]->Release();

	return true;
}

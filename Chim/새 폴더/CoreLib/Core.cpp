#include "Core.h"
#include "CameraManger.h"

// this functions will override in child class
bool Core::Init() { return true; }
bool Core::Frame() { return true; }
bool Core::Render() { return true; }
bool Core::Release() { return true; }

// message handle loop
void Core::Run()
{
	EngineInit();

	while (window.HandleMessage())
	{
		EngineFrame();
		EngineRender();
	}

	EngineRelease();
}


bool Core::EngineInit()
{
	Timer::GetInstance().Init();
	UserInput::GetInstance().Init(window.GetHInstance(), window.GetHWnd());
	
	graphics.Init(window.GetHWnd(), window.GetWindowWidth(), window.GetWindowHeight());
	Writer::GetInstance().Init(window.GetHWnd(), graphics.GetBackBuffer());

	TextureManager::GetInstance().Set(graphics.pDevice, graphics.pImmediateContext);
	ShaderManager::GetInstance().Set(graphics.pDevice, graphics.pImmediateContext); 
	SceneManager::GetInstance().Set(graphics.pDevice, graphics.pImmediateContext);

	Init();

	return true;
}

bool Core::EngineFrame()
{
	Timer::GetInstance().Frame();
	UserInput::GetInstance().Frame();

	Writer::GetInstance().Frame();
	graphics.Frame();
	Frame();

	/*if (SceneManager::GetInstance().loadNextScene)
	{
		SceneManager::GetInstance().ChangeScene(SceneManager::GetInstance().currentSceneIndex + 1);
		SceneManager::GetInstance().loadNextScene = false;
	}*/
	return true;
}

bool Core::EngineRender()
{

	Timer::GetInstance().Render();

	graphics.PreRender();
	graphics.pImmediateContext->PSSetSamplers(0, 1, &graphics.pSamplerState);

	Render();

	Writer::GetInstance().Render();
	graphics.PostRender();

	return true;
}

bool Core::EngineRelease()
{
	Timer::GetInstance().Release();
	UserInput::GetInstance().Release();

//	Writer::GetInstance().Release();
	graphics.Release();

	Release();

	return true;
}
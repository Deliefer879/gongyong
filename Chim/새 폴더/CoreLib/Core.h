#pragma once

#include "Window.h"
#include "Graphics.h"
#include "Timer.h"
#include "UserInput.h"
#include "Writer.h"

#include "TextureManager.h"
#include "ShaderManager.h"
#include "SceneManager.h"
#include "CameraManger.h"

class Core 
{
protected:
	Window window;     // window set in winMain function
	Graphics graphics;
private:
	bool EngineInit();
	bool EngineFrame();
	bool EngineRender();
	bool EngineRelease();

public:
	// constructor
	Core() {};
	~Core() {};

	// function
	virtual bool Init();
	virtual bool Frame();
	virtual bool Render();
	virtual bool Release();

	void Run();

	// getter
	Window& GetWindow() { return window; }
	Graphics& GetGraphics() { return graphics; }
};

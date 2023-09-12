#pragma once

#include "Core.h"
#include "Map.h"

class Sample : public Core
{
	Map map;

private:
	bool Init() override;
	bool Frame() override;
	bool Render() override;
	bool Release() override;
};
#include "SpaceDivider.hpp"
#include "constant.h"

int main()
{
	// set window size
	areaSize.width = 600;
	areaSize.height = 600;
	areaSize.depth = 600;

	SpaceDivider<Cube> quadTree;

	std::vector<Object<Cube>*> dObjects;

	quadTree.Init(DivideDimension::DIMENSION3, {0,0,0,(float)areaSize.width,(float)areaSize.height, (float)areaSize.depth});

	//set dObj
	for (int i = 0; i < 10; i++)
	{
		Object<Cube>* dObj = new DynamicObject<Cube>();

		dObj->SetObjPos({(float)(rand() % areaSize.width), (float)(rand() % areaSize.height), (float)(rand() % areaSize.depth)});
		dObj->SetArea(Cube(dObj->GetObjPos(), { (float)(rand() % 10) + 1, (float)(rand() % 10) + 1, (float)(rand() % 10) + 1 }));
		dObj->SetDir({ (float)(rand() % areaSize.width), (float)(rand() % areaSize.height), (float)(rand() % areaSize.depth) });

		quadTree.AddDynamicObject(dObj);
		dObjects.push_back(dObj);
	}

	while (true)
	{
		system("cls");

		// clear tree dynamic object list
		quadTree.Frame();

		for (auto& obj : dObjects)
		{
			obj->Move(0.2f);
			quadTree.AddDynamicObject(obj);
		}

		// print
		quadTree.Render();

		std::cout << "";
	}

	for (int i = 0; i < dObjects.size(); i++)
		delete dObjects[i];

	quadTree.Release();

	return 0;
}
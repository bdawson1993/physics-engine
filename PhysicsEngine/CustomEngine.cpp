#include "pch.h"
#include "CustomEngine.h"


void CustomEngine::SceneSetup()
{
	
	

	cat = new Catapult("Player", physics, scene);

	cube = new Cube("cube", physics);
	cube->CreateDynamic(PxVec3(0, 50, 0), PxVec3(0.5f, 0.5f, 0.5f), default_material);
	scene.AddActor(*cube);
}

void CustomEngine::CustomUpdate()
{
	cat->Update();
	
}

void CustomEngine::KeyPress(char key)
{
	cat->KeyPress(key);
}

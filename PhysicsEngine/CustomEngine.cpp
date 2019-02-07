#include "pch.h"
#include "CustomEngine.h"

void CustomEngine::SceneSetup()
{
	Cube box = Cube("cube", physics);
	box.CreateDynamic(PxVec3(0, 1, 0), PxVec3(0.5f, 0.5f, 0.5f), default_material);
	scene.AddActor(box);

}

void CustomEngine::CustomUpdate()
{
	
}

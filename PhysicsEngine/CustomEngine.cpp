#include "pch.h"
#include "CustomEngine.h"

void CustomEngine::SceneSetup()
{
	Cube cub = Cube("cube", physics);

	cub.CreateDynamic(PxVec3(1, 1, 1), PxVec3(1, 1, 1), default_material);

	
	scene.AddActor(cub);
	

}

void CustomEngine::CustomUpdate()
{
	
	
}

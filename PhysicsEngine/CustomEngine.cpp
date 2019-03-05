#include "pch.h"
#include "CustomEngine.h"


void CustomEngine::SceneSetup()
{
	cat = new Catapult("Player", physics, scene);

	cube = new Cube("falling cube", physics);
	cube->CreateDynamic(PxVec3(0, 50, 0), PxVec3(0.5f, 0.5f, 0.5f), default_material);
	scene.AddActor(*cube);

	goal = new Goal("goal", physics);
	goal->CreateStatic(PxVec3(0, 5.0f, -60), PxVec3(1, 1, 1), default_material);
	scene.AddActor(*goal);

	cube->SetupFiltering(FilterGroup::ACTOR0, FilterGroup::ACTOR1);
	cat->base->SetupFiltering(FilterGroup::ACTOR1, FilterGroup::ACTOR0);


}

void CustomEngine::CustomUpdate()
{
	cat->Update();
	
}

void CustomEngine::KeyPress(char key)
{
	cat->KeyPress(key);
}

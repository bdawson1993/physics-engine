#include "pch.h"
#include "CustomEngine.h"


void CustomEngine::SceneSetup()
{
	cat = new Catapult("Player", physics, &scene);

	
	goal = new Goal("goal", physics);
	goal->CreateStatic(PxVec3(0, 5.0f, -60), PxVec3(1, 1, 1), default_material);
	scene.AddActor(*goal);

	
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

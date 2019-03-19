#include "pch.h"
#include "CustomEngine.h"


void CustomEngine::SceneSetup()
{
	cat = new Catapult("Player", physics, &scene);

	
	goal = new Goal("goal", physics);
	goal->CreateStatic(PxVec3(0, 5.0f, -250), PxVec3(1, 1, 1), default_material);
	scene.AddActor(*goal);

	mill = new WindMill(physics, &scene, default_material);
	

	cat->base->SetupFiltering(FilterGroup::ACTOR1, FilterGroup::ACTOR0);
}

void CustomEngine::CustomUpdate()
{
	cat->Update();
	scene.CheckActors();
}

void CustomEngine::KeyPress(char key)
{
	cat->KeyPress(key);
}

int CustomEngine::GetCatForce()
{
	return cat->GetLaunchForce();
}

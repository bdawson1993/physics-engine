#include "pch.h"
#include "CustomEngine.h"


void CustomEngine::SceneSetup()
{
	
	cat = new Catapult("player", physics, &scene, PxVec3(0, 1, 0), true);
	//cat2 = new Catapult("player1", physics, &scene, PxVec3(35, 1, 10));


	goal = new Goal("goal", physics);
	goal->CreateStatic(PxVec3(0, 5.0f, -250), PxVec3(1, 1, 1), default_material);
	scene.AddActor(*goal);

	mill = new WindMill(physics, &scene, default_material, PxVec3(-15, 5.0f, -200.0f));
	mill2 = new WindMill(physics, &scene, default_material, PxVec3(15, 5.0f, -200.0f));
	mill3 = new WindMill(physics, &scene, default_material, PxVec3(0, 20.0f, -190.0f));

	//setup object filtering
	cat->base->SetupFiltering(FilterGroup::ACTOR0, FilterGroup::ACTOR1);
	//cat2->base->SetupFiltering(FilterGroup::ACTOR0, FilterGroup::ACTOR1);

	
}

void CustomEngine::CustomUpdate()
{
	cat->Update();
	//cat2->Update();

	mill->Update();
	mill2->Update();
	mill3->Update();

	
	scene.CheckActors();
}

void CustomEngine::KeyPress(char key)
{
	cat->KeyPress(key);
	//cat2->KeyPress(key);
}

void CustomEngine::KeyHold(char key)
{
	cat->KeyHold(key);
	//cat2->KeyHold(key);
}


int CustomEngine::GetCatForce()
{
	return cat->GetLaunchForce();
}

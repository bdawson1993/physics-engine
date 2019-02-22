#include "pch.h"
#include "CustomEngine.h"
#include "CollsionModifer.h"

void CustomEngine::SceneSetup()
{
	MyContactModification* coll = new MyContactModification();

	string name = "Player";
	Catapult* cat = new Catapult("Player", physics, scene);
	Cube* cube = new Cube("cube", physics);
	cube->CreateDynamic(PxVec3(0, 50, 0), PxVec3(0.5f, 0.5f, 0.5f), default_material);
	scene.AddActor(*cube);

	
	cat->base.SetupFiltering(FilterGroup::ACTOR0, FilterGroup::ACTOR1);
	cube->SetupFiltering(FilterGroup::ACTOR1, FilterGroup::ACTOR0);
	cube->SetTrigger(true, 0);

	scene.GetScene()->setSimulationEventCallback(coll);
	
	
	
	

}

void CustomEngine::CustomUpdate()
{
	
	
}

#include "pch.h"
#include "CustomEngine.h"


void CustomEngine::SceneSetup()
{
	mat.AddMaterial("water", physics->createMaterial(0.5f, 0.5f, 0.5f));

	
	cat = new Catapult("player", physics, &scene, PxVec3(0, 1, 0), mat.GetMaterial("default"), true);
	//cat2 = new Catapult("player1", physics, &scene, PxVec3(35, 1, 10));

	//create left wall
	leftWall = new Cube("left wall", physics);
	leftWall->CreateStatic(PxVec3(-30.0f, 10.0f, -110.0f), PxVec3(1.0f, 30.0f, 150.0f), mat.GetMaterial("default"));
	leftWall->SetColor(PxVec3(0, 0, 0));
	scene.AddActor(*leftWall);

	//create right wall
	rightWall = new Cube("right wall", physics);
	rightWall->CreateStatic(PxVec3(30.0f, 10.0f, -110.0f), PxVec3(1.0f, 30.0f, 150.0f), mat.GetMaterial("default"));
	rightWall->SetColor(PxVec3(0, 0, 0));
	scene.AddActor(*rightWall);

	//create rear wall
	rearWall = new Cube("rear wall", physics);
	rearWall->CreateStatic(PxVec3(0.0f, 10.0f, 40.0f), PxVec3(30.0f, 30.0f, 1.0f), mat.GetMaterial("default"));
	rearWall->SetColor(PxVec3(0, 0, 0));
	scene.AddActor(*rearWall);

	//create front wall
	frontWall = new Cube("rear wall", physics);
	frontWall->CreateStatic(PxVec3(0.0f, 10.0f, -260.0f), PxVec3(30.0f, 30.0f, 1.0f), mat.GetMaterial("default"));
	frontWall->SetColor(PxVec3(0, 0, 0));
	scene.AddActor(*frontWall);





	goal = new Goal("goal", physics);
	goal->CreateStatic(PxVec3(0, 5.0f, -250), PxVec3(1, 1, 1), default_material);
	scene.AddActor(*goal);

	mill = new WindMill(physics, &scene, default_material, PxVec3(-15, 5.0f, -200.0f));
	mill2 = new WindMill(physics, &scene, default_material, PxVec3(15, 5.0f, -200.0f));
	mill3 = new WindMill(physics, &scene, default_material, PxVec3(0, 20.0f, -190.0f));

	//setup object filtering
	cat->base->SetupFiltering(FilterGroup::ACTOR0, FilterGroup::ACTOR1);
	//cat2->base->SetupFiltering(FilterGroup::ACTOR0, FilterGroup::ACTOR1);

	partEngine = ParticleEngine(&scene, physics, EmitterShape::ShapeRectangle, mat.GetMaterial("water"),
		PxVec3(-40, 20, 200), -20, 20);
}

void CustomEngine::CustomUpdate()
{
	cat->Update();
	//cat2->Update();

	mill->Update();
	mill2->Update();
	mill3->Update();

	
	scene.CheckActors();

	//particle system update
	partEngine.Emit();
	partEngine.Update();
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

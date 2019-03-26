#pragma once
#include "PhysicsEngine.h"
#include "BasicShapes.h"
#include "Catapult.h"
#include "Goal.h"
#include "WindMill.h"
#include "ParticleEngine.h"

class CustomEngine : public PhysicsEngine
{
public:
	CustomEngine() : PhysicsEngine::PhysicsEngine()
	{

	};
	
	~CustomEngine()
	{
		delete cat;
		delete leftWall;
		delete rightWall;
		delete rearWall;
		delete frontWall;
		delete goal;
		delete mill;
		delete mill2;
		delete mill3;
	}


	void SceneSetup();

	void CustomUpdate();

	void KeyPress(char key);

	void KeyHold(char key);

	int GetCatForce();

private:
	Catapult* cat;
	//Catapult* cat2;
	Cube* leftWall;
	Cube* rightWall;
	Cube* rearWall;
	Cube* frontWall;


	Goal* goal;
	WindMill* mill;
	WindMill* mill2;
	WindMill* mill3;
	ParticleEngine partEngine;

};


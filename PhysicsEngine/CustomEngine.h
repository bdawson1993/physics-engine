#pragma once
#include "PhysicsEngine.h"
#include "BasicShapes.h"
#include "Catapult.h"
#include "Goal.h"
#include "WindMill.h"

class CustomEngine : public PhysicsEngine
{
public:
	CustomEngine() : PhysicsEngine::PhysicsEngine()
	{

	};
	
	~CustomEngine()
	{
		delete cat;
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


	Goal* goal;
	WindMill* mill;
	WindMill* mill2;
	WindMill* mill3;

};


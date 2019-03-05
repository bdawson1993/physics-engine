#pragma once
#include "PhysicsEngine.h"
#include "BasicShapes.h"
#include "Catapult.h"
#include "Goal.h"

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
private:
	Catapult* cat;
	Goal* goal;

};


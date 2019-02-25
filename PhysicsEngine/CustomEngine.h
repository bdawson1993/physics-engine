#pragma once
#include "PhysicsEngine.h"
#include "BasicShapes.h"
#include "Catapult.h"

class CustomEngine : public PhysicsEngine
{
public:
	CustomEngine() : PhysicsEngine::PhysicsEngine()
	{

	};
	
	~CustomEngine()
	{
		delete cat;
		delete cube;
	}


	void SceneSetup();

	void CustomUpdate();

	void KeyPress(char key);
private:
	Catapult* cat;
	Cube* cube;

};


#pragma once
#include "PhysicsEngine.h"
#include "BasicShapes.h"
#include "CatapultBase.h"

class CustomEngine : public PhysicsEngine
{
public:
	CustomEngine() : PhysicsEngine::PhysicsEngine()
	{

	};
	
	void SceneSetup();

	void CustomUpdate();

	void KeyPress(char key);
private:

};


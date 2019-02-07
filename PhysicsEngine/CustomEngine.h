#pragma once
#include "PhysicsEngine.h"
#include "BasicShapes.h"

class CustomEngine : public PhysicsEngine
{
public:
	CustomEngine() : PhysicsEngine::PhysicsEngine()
	{

	};
	
	void SceneSetup();

	void CustomUpdate();
private:

};


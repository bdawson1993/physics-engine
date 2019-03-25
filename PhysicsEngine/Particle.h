#pragma once
#include "Actor.h"
#include "BasicShapes.h"

class Particle : public Actor
{

public:
	Particle(const char* name, PxPhysics *physics) : Actor(name, physics)
	{
		
	};

	void Update();
	int GetLife();
	void CreateDynamic(PxVec3 pos, PxVec3 size, PxMaterial* mat);

private:
	int life;
};

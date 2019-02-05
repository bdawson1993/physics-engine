#pragma once
#include "Actor.h"

class Cube : public Actor
{
public:
	Cube(string, PxPhysics* physics, PxMaterial* mat) : Actor::Actor(name, physics)
	{

	};
	
	void CreateStatic(PxVec3 pos, PxVec3 size, PxMaterial* mat);
	void CreateDynamic(PxVec3 pos, PxVec3 size, PxMaterial* mat);

private:

};



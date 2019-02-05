#pragma once
#include "Actor.h"

class Sphere : public Actor
{
public:
	Sphere(string name, PxPhysics* physics) : Actor::Actor(name, physics)
	{

	};

	void CreateDynamic(PxVec3 pos, PxReal size, PxMaterial* mat);
	

private:

};



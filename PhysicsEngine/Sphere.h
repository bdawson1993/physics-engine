#pragma once
#include "Actor.h"



class Sphere : public Actor
{
public:
	Sphere(const char* name, PxPhysics* physics) : Actor::Actor(name, physics)
	{

	};

	void CreateDynamic(PxVec3 pos, PxReal size, PxMaterial* mat);
	

private:

};



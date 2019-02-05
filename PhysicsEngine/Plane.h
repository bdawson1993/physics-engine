#pragma once
#include "Actor.h"
#include <string>


using namespace std;

class Plane : public Actor
{
public:
	Plane(string name, PxPhysics* physics, PxMaterial* mat) : Actor::Actor(name, physics)
	{
		
	};

	void CreateShape(PxVec3 pos, PxVec3 size, PxMaterial* mat);

private:

};


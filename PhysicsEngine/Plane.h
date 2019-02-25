#pragma once
#include "Actor.h"
#include <string>


using namespace std;

class Plane : public Actor
{
public:
	Plane(const char* name, PxPhysics* physics) : Actor::Actor(name, physics)
	{
		
	};

	void CreateStatic(PxVec3 pos, PxVec3 size, PxMaterial* mat);

private:

};


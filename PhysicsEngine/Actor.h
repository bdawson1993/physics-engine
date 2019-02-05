#pragma once
#include "PxPhysicsAPI.h"
#include <string>

using namespace physx;
using namespace std;

class Actor
{

public:
	Actor(string name, PxPhysics *physics);
	PxActor* GetActor();

	virtual void CreateShape(PxVec3 pos, PxVec3 size, PxMaterial* mat);

protected:
	string name;
	PxActor* actor;
	PxPhysics* physics;
	
};
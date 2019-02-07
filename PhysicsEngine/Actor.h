#pragma once
#include "PxPhysicsAPI.h"
#include <string>

using namespace physx;
using namespace std;

class Actor
{

public:
	Actor(string name, PxPhysics *physics);
	PxRigidActor* GetActor();
	string GetName();
	Actor();
	

protected:
	virtual void CreateDynamic(PxVec3 pos, PxVec3 size, PxMaterial* mat);
	virtual void CreateStatic(PxVec3 pos, PxVec3 size, PxMaterial* mat);
	virtual void CreateDynamic();
	virtual void CreateStatic();
	
	


protected:
	string name;
	PxRigidActor* actor;
	PxPhysics* physics;
	
};


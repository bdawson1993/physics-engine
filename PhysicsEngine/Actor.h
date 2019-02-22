#pragma once
#include "PxPhysicsAPI.h"
#include <string>

using namespace physx;
using namespace std;

class Actor
{

public:
	Actor(string name, PxPhysics *physics) : 
		actor(0)
	{
		this->name = name;
		this->physics = physics;
		
	};

	PxRigidActor* GetActor();
	string GetName();
	

protected:
	virtual void CreateDynamic(PxVec3 pos, PxVec3 size, PxMaterial* mat);
	virtual void CreateStatic(PxVec3 pos, PxVec3 size, PxMaterial* mat);
	virtual void CreateDynamic();
	virtual void CreateStatic();
	void CreateShape(const PxGeometry& geometry, int density, PxMaterial& mat, PxVec3 local);
	
	
protected:
	string name;
	PxRigidActor* actor;
	PxPhysics* physics;
	
};


#pragma once
#include "PxPhysicsAPI.h"
#include <string>
#include <vector>

using namespace physx;
using namespace std;

struct FilterGroup
{
	enum Enum
	{
		ACTOR0 = (1 << 0),
		ACTOR1 = (1 << 1),
		ACTOR2 = (1 << 2)
		//add more if you need
	};
};


class Actor
{

public:
	Actor()
	{

	}

	Actor(string name, PxPhysics *physics) : 
		actor(0)
	{
		
		
		this->name = name;
		this->physics = physics;
		
	};

	PxRigidActor* GetActor();
	string GetName();
	void SetTrigger(bool value, PxU32 shape_index=-1);
	void SetupFiltering(PxU32 filterGroup, PxU32 filterMask, PxU32 shape_index=-1);
	vector<PxShape*> GetShapes(PxU32 index);
	

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


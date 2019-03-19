#pragma once
#include "Actor.h"

class WindMill : public Actor
{
public:
	WindMill(const char* name, PxPhysics* phys) : Actor(name, phys)
	{

	}
	void CreateDynamic(PxVec3 pos, PxVec3 size, PxMaterial * mat)
	{
		actor = (PxRigidDynamic*)physics->createRigidDynamic(PxTransform(pos));
		CreateShape(PxBoxGeometry(1, 10, 1), *mat, 100);
		CreateShape(PxBoxGeometry(1, 10, 1), *mat, 100, PxVec3(0,10,1));
		




	}
};

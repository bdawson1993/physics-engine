#pragma once
#include "Actor.h"



class Projectile : public Actor
{
public:
	Projectile(const char* name, PxPhysics* phys) : Actor(name, phys)
	{
		
	}

	virtual void CreateDynamic(PxVec3 pos, PxVec3 size, PxMaterial* mat);
	
};

#pragma once
#include "Actor.h"
#include "BasicShapes.h"



class Projectile : public Sphere
{
public:
	Projectile(const char* name, PxPhysics* phys) : Sphere(name, phys)
	{
		PxMaterial* mat = physics->createMaterial(3, 0, 0);
		CreateDynamic(PxVec3(0, 10, 0), 1.0f, mat);
	}

};

#pragma once
#include "Actor.h"
#include "BasicShapes.h"
#include <iostream>
#include "Scene.h"

using namespace std;

class Projectile : public Sphere
{
public:
	bool onFloor;
	Projectile(const char* name, PxPhysics* phys) : Sphere(name, phys)
	{
		PxMaterial* mat = physics->createMaterial(0, 0, 0);
		CreateDynamic(PxVec3(0, 5, 0), 1.0f, mat);
	}

	void OnContact(Actor* collidedObject);

};

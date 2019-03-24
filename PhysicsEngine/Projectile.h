#pragma once
#include "Actor.h"
#include "BasicShapes.h"
#include <iostream>
#include "Scene.h"

using namespace std;

class Projectile : public Actor
{
public:
	bool onFloor;
	Projectile(const char* name, PxPhysics* phys) : Actor(name, phys)
	{
		
	}

	void CreateDynamic(PxVec3 pos, PxVec3 size, PxMaterial* mat);

	void OnContact(Actor* collidedObject);

};

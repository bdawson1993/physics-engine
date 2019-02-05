#include "pch.h"
#include "Actor.h"

Actor::Actor(string name, PxPhysics *physics)
{
	this->name = name;
	this->physics = physics;
}

PxActor* Actor::GetActor()
{
	return actor;
}

void Actor::CreateShape(PxVec3 pos, PxVec3 size, PxMaterial * mat)
{
}



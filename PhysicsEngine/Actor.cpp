#include "pch.h"
#include "Actor.h"

Actor::Actor(string name, PxPhysics *physics)
{
	this->name = name;
	this->physics = physics;
}

PxRigidActor* Actor::GetActor()
{
	return actor;
}

string Actor::GetName()
{
	return name;
}

void Actor::CreateDynamic(PxVec3 pos, PxVec3 size, PxMaterial * mat)
{
}

void Actor::CreateStatic(PxVec3 pos, PxVec3 size, PxMaterial* mat)
{
}

void Actor::Update()
{
}



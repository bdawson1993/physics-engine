#include "pch.h"
#include "Actor.h"



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

void Actor::CreateDynamic()
{
}

void Actor::CreateStatic()
{
}






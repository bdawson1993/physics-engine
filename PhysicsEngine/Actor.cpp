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

void  Actor::CreateShape(const PxGeometry& geometry, int density, PxMaterial& mat, PxVec3 local)
{

	PxShape* shape = physics->createShape(geometry, mat);
	PxRigidBodyExt::updateMassAndInertia(*(PxRigidDynamic*)actor, density);
	shape->setLocalPose(PxTransform(local));
	actor->attachShape(*shape);
}






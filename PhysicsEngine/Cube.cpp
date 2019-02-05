#include "pch.h"
#include "Cube.h"

void Cube::CreateStatic(PxVec3 pos, PxVec3 size, PxMaterial* mat)
{
	actor = (PxRigidStatic*)physics->createRigidStatic(PxTransform(pos));
	actor->createShape(PxBoxGeometry(PxVec3(size.x, size.y, size.z)), *mat);
}

void Cube::CreateDynamic(PxVec3 pos, PxVec3 size, PxMaterial *mat)
{
	actor = (PxRigidDynamic*)physics->createRigidDynamic(PxTransform(pos));
	actor->createShape(PxBoxGeometry(PxVec3(size.x,size.y,size.z)),*mat);

	PxRigidBody* pb = (PxRigidBody*)actor;
	PxRigidBodyExt::updateMassAndInertia(*pb, 1.f);
}

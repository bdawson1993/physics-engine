#include "pch.h"
#include "Sphere.h"

void Sphere::CreateDynamic(PxVec3 pos, PxReal size, PxMaterial* mat)
{
	//create dynamic actor and sphere shape
	actor = (PxRigidDynamic*)physics->createRigidDynamic(PxTransform(pos));
	actor->createShape(PxSphereGeometry(size), *mat);

	//update mass and inhertia
	PxRigidBody* pb = (PxRigidBody*)actor;
	PxRigidBodyExt::updateMassAndInertia(*pb, 1.f);
}

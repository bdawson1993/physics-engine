#include "pch.h"
#include "Sphere.h"

void Sphere::CreateDynamic(PxVec3 pos, PxReal size, PxMaterial* mat)
{
	actor = (PxRigidDynamic*)physics->createRigidDynamic(PxTransform(pos));
	actor->createShape(PxSphereGeometry(size), *mat);
}

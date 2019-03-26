#include "pch.h"
#include "Sphere.h"

void Sphere::CreateDynamic(PxVec3 pos, PxReal size, PxMaterial* mat)
{
	//create dynamic actor and sphere shape
	actor = (PxRigidDynamic*)physics->createRigidDynamic(PxTransform(pos));
	CreateShape(PxSphereGeometry(size), *mat);

}

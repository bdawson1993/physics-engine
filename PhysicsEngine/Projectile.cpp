#include "Projectile.h"

void Projectile::CreateDynamic(PxVec3 pos, PxVec3 size, PxMaterial * mat)
{
	actor = (PxRigidDynamic*)physics->createRigidDynamic(PxTransform(PxVec3(0, 1, 0)));
	CreateShape(PxSphereGeometry(1.0f), 1.0f, *mat, PxVec3(0,1,0));

}

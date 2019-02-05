#include "pch.h"
#include "Plane.h"

void Plane::CreateShape(PxVec3 pos, PxVec3 size, PxMaterial* mat)
{
	actor = (PxRigidStatic*)PxCreatePlane(*physics, PxPlane(PxVec3(0.f, 1.f, 0.f), 0.f), *mat);
}

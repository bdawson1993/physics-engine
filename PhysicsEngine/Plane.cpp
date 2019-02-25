#include "pch.h"
#include "Plane.h"

void Plane::CreateStatic(PxVec3 pos, PxVec3 size, PxMaterial* mat)
{
	actor = physics->createRigidStatic(PxTransformFromPlaneEquation(PxPlane(pos, 0.0f)));
	CreateShape(PxPlaneGeometry(), *mat);
	
	//actor = (PxRigidStatic*)PxCreatePlane(*physics, PxPlane(PxVec3(0.f, 1.f, 0.f), 0.f), *mat);
}

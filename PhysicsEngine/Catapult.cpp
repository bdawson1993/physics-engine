#include "pch.h"
#include "Catapult.h"

void Catapult::CreateDynamic()
{
	PxMaterial* mat = physics->createMaterial(1, 1, 1);
	actor = (PxRigidDynamic*)physics->createRigidDynamic(PxTransform(PxVec3(0, 0, 0)));

	PxShape* left = physics->createShape(PxBoxGeometry(0.5f, 0.5f, 0.5f), *mat);
	actor->attachShape(*left);

	PxShape* right = physics->createShape(PxBoxGeometry(0.5f, 0.5f, 0.5f), *mat);
	right->setLocalPose(PxTransform(PxVec3(2, 0, 0)));
	actor->attachShape(*right);

	
	
}

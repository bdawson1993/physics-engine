#include "pch.h"
#include "CatapultBase.h"

void CatapultBase::CreateDynamic()
{
	PxMaterial* mat = physics->createMaterial(0, 0, 0);
	actor = (PxRigidDynamic*)physics->createRigidDynamic(PxTransform(PxVec3(1, 1, 1)));

	//left side
	PxShape* left = physics->createShape(PxBoxGeometry(0.5f, 0.5f, 1.0f), *mat);
	actor->attachShape(*left);

	//right side
	PxShape* right = physics->createShape(PxBoxGeometry(0.5f, 0.5f, 1.0f), *mat);
	right->setLocalPose(PxTransform(PxVec3(2, 0, 0)));
	actor->attachShape(*right);

	


}

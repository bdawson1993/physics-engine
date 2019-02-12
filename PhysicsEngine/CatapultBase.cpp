#include "pch.h"
#include "CatapultBase.h"

void CatapultBase::CreateDynamic()
{
	PxMaterial* mat = physics->createMaterial(1, 1, 1);
	actor = (PxRigidDynamic*)physics->createRigidDynamic(PxTransform(PxVec3(0, 0, 0)));

	//left side
	PxShape* left = physics->createShape(PxBoxGeometry(0.5f, 0.5f, 2.0f), *mat);
	actor->attachShape(*left);

	//right side
	PxShape* right = physics->createShape(PxBoxGeometry(0.5f, 0.5f, 2.0f), *mat);
	right->setLocalPose(PxTransform(PxVec3(5, 0, 0)));
	actor->attachShape(*right);

	//front
	PxShape* front = physics->createShape(PxBoxGeometry(3.0f, 0.5f, 0.5f), *mat);
	front->setLocalPose(PxTransform(PxVec3(2.5f, 0.0f, 2.5f)));
	actor->attachShape(*front);

	//back
	PxShape* back = physics->createShape(PxBoxGeometry(3.0f, 0.5f, 0.5f), *mat);
	back->setLocalPose(PxTransform(PxVec3(2.5f, 0.0f, -2.5f)));
	actor->attachShape(*back);
	

	
	


}

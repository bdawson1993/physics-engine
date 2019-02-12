#include "pch.h"
#include "Catapult.h"

void Catapult::CreateDynamic()
{
	PxMaterial* mat = physics->createMaterial(1, 1, 1);
	actor = (PxRigidDynamic*)physics->createRigidDynamic(PxTransform(PxVec3(0, 0, 0)));

	//left side
	PxShape* left = physics->createShape(PxBoxGeometry(0.5f, 0.5f, 1.0f), *mat);
	actor->attachShape(*left);

	//right side
	PxShape* right = physics->createShape(PxBoxGeometry(0.5f, 0.5f, 1.0f), *mat);
	right->setLocalPose(PxTransform(PxVec3(2, 0, 0)));
	actor->attachShape(*right);

	//top
	PxShape* top = physics->createShape(PxBoxGeometry(1.0f, 0.5f, 0.5f), *mat);
	top->setLocalPose(PxTransform(PxVec3(1, 0, 1)));
	actor->attachShape(*top);

	//bottom
	PxShape* bottom = physics->createShape(PxBoxGeometry(1.0f, 0.5f, 0.5f), *mat);
	bottom->setLocalPose(PxTransform(PxTransform(PxVec3(1,0,-1))));
	actor->attachShape(*bottom);



	//left arm
	//left V
	PxShape* lLeftArm = physics->createShape(PxBoxGeometry(1.0f,1.0f, 0.5f), *mat);
	lLeftArm->setLocalPose(PxTransform(PxVec3(1,0,1)));
	actor->attachShape(*lLeftArm);

	//right v
	PxShape* lRightArm = physics->createShape(PxBoxGeometry(1.0f,1.0f, 0.5f), *mat);
	lLeftArm->setLocalPose(PxTransform(PxVec3(1,0,-1)));
	actor->attachShape(*lRightArm);



	//right arm
	//left V
	PxShape* rLeftArm = physics->createShape(PxBoxGeometry(1.0f,1.0f, 0.5f), *mat);
	lLeftArm->setLocalPose(PxTransform(PxVec3(-1,0,1)));
	actor->attachShape(*rLeftArm);

	//right v
	PxShape* rRightArm = physics->createShape(PxBoxGeometry(1.0f,1.0f, 0.5f), *mat);
	lLeftArm->setLocalPose(PxTransform(PxVec3(-1,0,-1)));
	actor->attachShape(*rRightArm);


}

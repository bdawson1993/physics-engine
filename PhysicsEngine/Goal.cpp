#include "Goal.h"

void Goal::CreateStatic(PxVec3 pos, PxVec3 size, PxMaterial * mat)
{
	actor = (PxRigidStatic*)physics->createRigidStatic(PxTransform(pos));

	CreateShape(PxBoxGeometry(0.5f, 10.0f, 0.5f), *mat);
	CreateShape(PxBoxGeometry(10.0f, 0.5f, 0.5f), *mat);
	GetShape(1)->setLocalPose(PxTransform(PxVec3(0.0f, 10.0f, 0.0f)));

	CreateShape(PxBoxGeometry(0.5f, 5.0f, 0.5f), *mat);
	GetShape(2)->setLocalPose(PxTransform(PxVec3(10.0f, 14.5f, 0.0f)));

	CreateShape(PxBoxGeometry(0.5f, 5.0f, 0.5f), *mat);
	GetShape(3)->setLocalPose(PxTransform(PxVec3(-10.0f, 14.5f, 0.0f)));

	CreateShape(PxBoxGeometry(9.0f, 30.0f, 0.5f), *mat);
	GetShape(4)->setLocalPose(PxTransform(PxVec3(0, 40.0f, 0.0f)));
	SetTrigger(true, 4);

	SetColor(PxVec3(255, 0, 0));


}

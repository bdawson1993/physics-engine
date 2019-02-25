#include "pch.h"
#include "CatapultBase.h"

Catapult::Catapult(const char* name, PxPhysics * phy, Scene scene)
{
	base = CatapultBase(name, phy);
	base.CreateDynamic();
	base.SetName();

	arm =  CatapultArm(name, phy);
	arm.CreateDynamic();
	arm.SetName();



	float rad = 2.8f;

	//left side
	PxRevoluteJoint* leftJoint = PxRevoluteJointCreate(*phy, (PxRigidActor*)arm.GetActor(), PxTransform(2.0f, 0.5f, -0.5f),
		(PxRigidActor*)base.GetActor(), PxTransform(4.5f, 0.5f, 0.0f));

	leftJoint->setConstraintFlag(PxConstraintFlag::eVISUALIZATION, true);
	

	leftJoint->setLimit(PxJointAngularLimitPair(-PxPi / rad, PxPi / rad, 1.0f));
	leftJoint->setRevoluteJointFlag(PxRevoluteJointFlag::eLIMIT_ENABLED, true);
	leftJoint->setRevoluteJointFlag(PxRevoluteJointFlag::eDRIVE_ENABLED, true);
	leftJoint->setDriveVelocity(PxReal(-10));

	//right side
	PxRevoluteJoint* rightJoint = PxRevoluteJointCreate(*phy, (PxRigidActor*)arm.GetActor(), PxTransform(PxVec3(-2.0f, 0.5f, -0.5f), PxQuat(0, 1, 0, 0)),
		(PxRigidActor*)base.GetActor(), PxTransform(PxVec3(0.5f, 0.5f, 0.0f), PxQuat(0, 1, 0, 0)));

	rightJoint->setConstraintFlag(PxConstraintFlag::eVISUALIZATION, true);
	rightJoint->setLimit(PxJointAngularLimitPair(-PxPi / rad, PxPi / rad, 1.0f));
	rightJoint->setRevoluteJointFlag(PxRevoluteJointFlag::eLIMIT_ENABLED, true);
	rightJoint->setRevoluteJointFlag(PxRevoluteJointFlag::eDRIVE_ENABLED, true);
	rightJoint->setDriveVelocity(PxReal(-10));



	scene.AddActor(base);
	scene.AddActor(arm);
}


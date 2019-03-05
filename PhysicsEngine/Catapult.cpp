#include "pch.h"
#include "Catapult.h"

Catapult::Catapult()
{

}

Catapult::Catapult(const char* name, PxPhysics* phy, Scene* scene)
{
	base = new CatapultBase(name, phy);
	base->CreateDynamic();
	base->SetName();

	arm = new CatapultArm(name, phy);
	arm->CreateDynamic();
	arm->SetName();



	float rad = 2.8f;

	//left side
	leftJoint = PxRevoluteJointCreate(*phy, (PxRigidActor*)arm->GetActor(), PxTransform(2.0f, 0.5f, -0.5f),
		(PxRigidActor*)base->GetActor(), PxTransform(4.5f, 0.5f, 0.0f));

	leftJoint->setConstraintFlag(PxConstraintFlag::eVISUALIZATION, true);
	

	leftJoint->setLimit(PxJointAngularLimitPair(-PxPi / rad, PxPi / rad, 1.0f));
	leftJoint->setRevoluteJointFlag(PxRevoluteJointFlag::eLIMIT_ENABLED, true);
	leftJoint->setRevoluteJointFlag(PxRevoluteJointFlag::eDRIVE_ENABLED, true);
	leftJoint->setDriveVelocity(PxReal(-10));

	//right side
	rightJoint = PxRevoluteJointCreate(*phy, (PxRigidActor*)arm->GetActor(), PxTransform(PxVec3(-2.0f, 0.5f, -0.5f), PxQuat(0, 1, 0, 0)),
		(PxRigidActor*)base->GetActor(), PxTransform(PxVec3(0.5f, 0.5f, 0.0f), PxQuat(0, 1, 0, 0)));

	rightJoint->setConstraintFlag(PxConstraintFlag::eVISUALIZATION, true);
	rightJoint->setLimit(PxJointAngularLimitPair(-PxPi / rad, PxPi / rad, 1.0f));
	rightJoint->setRevoluteJointFlag(PxRevoluteJointFlag::eLIMIT_ENABLED, true);
	rightJoint->setRevoluteJointFlag(PxRevoluteJointFlag::eDRIVE_ENABLED, true);
	rightJoint->setDriveVelocity(PxReal(-10));


	this->phys = phy;
	this->scene = scene;

	scene->AddActor(*base);
	scene->AddActor(*arm);

	CreateBall();
}

void Catapult::Update()
{

}

void Catapult::KeyPress(char key)
{
	if (key == ' ')
	{

		if (leftJoint->getDriveVelocity() == -10)
		{
			leftJoint->setDriveVelocity(10);
			rightJoint->setDriveVelocity(10);
			ballJoint->setBreakForce(1.0f, 1.0f);

		}
		else
		{
			leftJoint->setDriveVelocity(-10);
			rightJoint->setDriveVelocity(-10);
			CreateBall();

		}

		PxRigidBody* bod = (PxRigidBody*)base->GetActor();
		bod->addForce(PxVec3(0.0f, 0.0f, 0.0f));
	}


	if (key == 'i')
	{
		PxRigidBody* bod = (PxRigidBody*)base->GetActor();
		bod->setLinearVelocity(PxVec3(0, 0, -10));
	}
}

void Catapult::CreateBall()
{
	if (ballJoint != NULL)
	{
		ballJoint->release();
	}

	PxRigidBody* pos = (PxRigidBody*)this->base->GetActor();
	Projectile* ball = new Projectile("ball", phys);
	ball->SetupFiltering(FilterGroup::ACTOR0, FilterGroup::ACTOR1);


	PxRigidBody* bod = (PxRigidBody*)ball->GetActor();



	//ball connection
	ballJoint = PxFixedJointCreate(*phys, (PxRigidActor*)ball->GetActor(), PxTransform(PxVec3(0.0f, 0.0f, 0.0f), PxQuat(0, 1, 0, 0)),
		(PxRigidActor*)arm->GetActor(), PxTransform(PxVec3(0.0, 6.5f, -2.0f), PxQuat(0, 1, 0, 0)));
	ballJoint->setConstraintFlag(PxConstraintFlag::eVISUALIZATION, true);

	scene->AddActor(*ball);

	


}


#include "pch.h"
#include "Catapult.h"

Catapult::Catapult()
{

}

Catapult::Catapult(const char* name, PxPhysics* phy, Scene* scene, PxVec3 pos,bool _hasBall)
{
	hasBall = _hasBall;
	base = new CatapultBase(name, phy);
	base->CreateDynamic(pos);
	base->SetName();
	base->SetHasBall(_hasBall);



	arm = new CatapultArm("arm", phy);
	arm->CreateDynamic(pos);
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

	//create ball only if true
	if(hasBall == true)
		CreateBall();
}

Projectile Catapult::GetBall()
{
	return *ball;
}

int Catapult::GetLaunchForce()
{
	return launchForce;
}

void Catapult::Update()
{
	if (base->GetRecived() == true)
	{
		CreateBall();
		hasBall = true;
		base->SetHasRecived(false);
	}
}

void Catapult::KeyPress(char key)
{
	if ((key == ' ') && (hasBall == true))
	{
		//hasBall = false;
		if (leftJoint->getDriveVelocity() == -10)
		{
			leftJoint->setDriveVelocity(launchForce);
			rightJoint->setDriveVelocity(launchForce);
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


	

	
}

void Catapult::KeyHold(char key)
{
	if (hasBall == true)
	{
		if (key == '[')
		{
			launchForce++;
		}

		if (key == ']')
		{
			launchForce--;
		}

		if (key == 'i')
		{
			PxRigidBody* bod = (PxRigidBody*)base->GetActor();
			int val = 10 * bod->getMass();
			bod->setAngularVelocity(PxVec3(0, -1, 0));
		}

		if (key == 'o')
		{
			PxRigidBody* bod = (PxRigidBody*)base->GetActor();
			int val = 10 * bod->getMass();
			bod->setAngularVelocity(PxVec3(0, 1, 0));
		}
	}
}

void Catapult::CreateBall()
{
	if (ballJoint != NULL)
	{
		ballJoint->release();
	}

	PxRigidBody* pos = (PxRigidBody*)this->base->GetActor();
	ball = new Projectile("ball", phys);
	ball->SetupFiltering(FilterGroup::ACTOR1, FilterGroup::ACTOR0);


	PxRigidBody* bod = (PxRigidBody*)ball->GetActor();



	//ball connection
	ballJoint = PxFixedJointCreate(*phys, (PxRigidActor*)ball->GetActor(), PxTransform(PxVec3(0.0f, 0.0f, 0.0f), PxQuat(0, 1, 0, 0)),
		(PxRigidActor*)arm->GetActor(), PxTransform(PxVec3(0.0, 6.5f, -2.0f), PxQuat(0, 1, 0, 0)));
	ballJoint->setConstraintFlag(PxConstraintFlag::eVISUALIZATION, true);

	scene->AddActor(*ball);

	


}

void CatapultBase::OnTriggerEnter(Actor* collidedObject)
{
	cout << collidedObject->GetName() << endl;
	if (((hasBall == false) && (collidedObject->GetName() == "ball")))
	{
		hasBall = true;
		hasRecivedBall = true;
	}
}

void CatapultBase::SetHasBall(bool value)
{
	hasBall = value;
}

void CatapultBase::SetHasRecived(bool value)
{
	hasRecivedBall = value;
}

bool CatapultBase::GetRecived()
{
	return hasRecivedBall;
}

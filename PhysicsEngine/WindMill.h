#pragma once
#include "Actor.h"

using namespace physx;

class WindMillArms : public Actor
{
public:
	WindMillArms(const char* name, PxPhysics* phys) : Actor(name, phys)
	{

	}
	void CreateDynamic(PxVec3 pos, PxVec3 size, PxMaterial * mat)
	{
		actor = (PxRigidDynamic*)physics->createRigidDynamic(PxTransform(pos));
		CreateShape(PxBoxGeometry(1, 5, 1), *mat, 100);
		CreateShape(PxBoxGeometry(1, 5, 1), *mat, 100, PxVec3(0,15,1));
		CreateShape(PxBoxGeometry(5, 1, 1), *mat, 100, PxVec3(10, 7.5, 1));
		CreateShape(PxBoxGeometry(5, 1, 1), *mat, 100, PxVec3(-10, 7.5, 1));
	}
};

class WindMillBase : public Actor
{
public:
	WindMillBase(const char* name, PxPhysics* phys) : Actor(name, phys)
	{

	}

	void CreateStatic(PxVec3 pos, PxVec3 size, PxMaterial* mat)
	{
		actor = (PxRigidStatic*)physics->createRigidStatic(PxTransform(pos));
		CreateShape(PxBoxGeometry(2, 20, 2), *mat);
		SetColor(PxVec3(255, 34, 54));
	}
};



class WindMill : public GameObject
{

public:
	WindMill(PxPhysics* phys, Scene* scene, PxMaterial* mat)
	{
		//create arms
		arms = new WindMillArms("Windmill Arms", phys);
		arms->CreateDynamic(PxVec3(1, 1, -20), PxVec3(1, 1, 1), mat);
		arms->SetName();

		//create base
		base = new WindMillBase("Windmill Base", phys);
		base->CreateStatic(PxVec3(1, 1, -21), PxVec3(1, 1, 0), mat);
		base->SetName();

		PxRevoluteJoint* joint = PxRevoluteJointCreate(*phys, base->GetActor(), PxTransform(1, 20, -4), arms->GetActor(), PxTransform(1, 10, -4));
		joint->setConstraintFlag(PxConstraintFlag::eVISUALIZATION, true);

		scene->AddActor(*arms);
		scene->AddActor(*base);
		
	}


private:
	PxPhysics* phy;
	WindMillArms* arms;
	WindMillBase* base;
};

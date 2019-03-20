#pragma once
#include "Actor.h"
#include "Scene.h"
#include <cmath>

using namespace physx;
using namespace std;

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
		CreateShape(PxBoxGeometry(1, 5, 1), *mat, 100, PxVec3(0,12,0));

		CreateShape(PxBoxGeometry(5, 1, 1), *mat, 100, PxVec3(7, 6, 0));
		CreateShape(PxBoxGeometry(5, 1, 1), *mat, 100, PxVec3(-7, 6, 0));
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
	WindMillArms* arms;
	WindMillBase* base;
	

	WindMill(PxPhysics* phys, Scene* scene, PxMaterial* mat, PxVec3 pos)
	{
		//create arms
		arms = new WindMillArms("Windmill Arms", phys);
		arms->CreateDynamic(pos, pos, mat);
		arms->SetName();

		//create base
		base = new WindMillBase("Windmill Base", phys);
		base->CreateStatic(pos, pos, mat);
		base->SetName();

		float rad = 2.8f;
		joint = PxRevoluteJointCreate(*phys, base->GetActor(), PxTransform(PxVec3(-0.5, 20, 10), PxQuat(0, sqrt(0.5), 0, sqrt(0.5))), arms->GetActor(),
			PxTransform(PxVec3(-0.5, 6, 5), PxQuat(0, sqrt(0.5), 0, sqrt(0.5))));
		joint->setConstraintFlag(PxConstraintFlag::eVISUALIZATION, true);
		joint->setRevoluteJointFlag(PxRevoluteJointFlag::eDRIVE_ENABLED, true);


		scene->AddActor(*arms);
		scene->AddActor(*base);
		
	}

	void Update();


private:
	PxPhysics* phy;
	PxRevoluteJoint* joint;
};

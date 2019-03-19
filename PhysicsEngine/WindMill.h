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

	void CreateDynamic(PxVec3 pos, PxVec3 size, PxMaterial* mat)
	{
		actor = (PxRigidDynamic*)physics->createRigidDynamic(PxTransform(pos));
		CreateShape(PxBoxGeometry(2, 10, 2), *mat);
	}
};



class WindMill : public GameObject
{

public:
	WindMill(PxPhysics* phys, Scene* scene)
	{
		phy = phys;
		arms = new WindMillArms("Windmill Arms", phys);
		base = new WindMillBase("Windmill Base", phys);

		scene->AddActor(*arms);
		scene->AddActor(*base);
	}


private:
	PxPhysics* phy;
	WindMillArms* arms;
	WindMillBase* base;
};

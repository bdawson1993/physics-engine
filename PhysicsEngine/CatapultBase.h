#pragma once
#include <iostream>
#include "Actor.h"
#include "Scene.h"

using namespace std;
class CatapultBase : public Actor
{
public:
	CatapultBase()
	{

	};

	CatapultBase(string name, PxPhysics* phy) : Actor(name, phy)
	{
		
	};

	
	void CreateDynamic()
	{
			PxMaterial* mat = physics->createMaterial(1, 1, 1);
			actor = (PxRigidDynamic*)physics->createRigidDynamic(PxTransform(PxVec3(0, 1, 0)));

			//sides
			CreateShape(PxBoxGeometry(0.5f, 0.5f, 3.0f), 1, *mat, PxVec3(0, 0, 0));
			CreateShape(PxBoxGeometry(0.5, 0.5f, 3.0f), 100, *mat, PxVec3(5.0f, 0.0f, 0.0f));


			CreateShape(PxBoxGeometry(3.0f, 0.5f, 0.5f), 100, *mat, PxVec3(2.5f, 0.0f, 3.5f)); //top
			CreateShape(PxBoxGeometry(3.0f, 0.5f, 0.5f), 100, *mat, PxVec3(2.5f, 0.0f, -3.5f)); //bottom


			//left stilts
			CreateShape(PxBoxGeometry(0.5f, 1.0f, 0.5f), 1000, *mat, PxVec3(6.0f, -0.5f, 3.5f)); //left
			CreateShape(PxBoxGeometry(0.5f, 1.0f, 0.5f), 1000, *mat, PxVec3(6.0f, -0.5f, -3.5f)); //right

			//right stilitts
			CreateShape(PxBoxGeometry(0.5f, 1.0f, 0.5f), 1000, *mat, PxVec3(-1.0f, -0.5f, 3.5f)); //left
			CreateShape(PxBoxGeometry(0.5f, 1.0f, 0.5f), 1000, *mat, PxVec3(-1.0f, -0.5f, -3.5f)); //left







		
	}
};

class CatapultArm : public Actor
{
public:
	CatapultArm()
	{

	};

	CatapultArm(string name, PxPhysics* phy) : Actor(name, phy)
	{

	};

	void CreateDynamic()
	{
		PxMaterial* mat = physics->createMaterial(1, 1, 1);
		actor = (PxRigidDynamic*)physics->createRigidDynamic(PxTransform(PxVec3(0, 5, 0)));

		CreateShape(PxBoxGeometry(1.5f, 0.5f, 0.5f), 100, *mat, PxVec3(0.0f, 1.0f, 0.0f));
		CreateShape(PxBoxGeometry(.5f, 2.0f, 0.5f), 100, *mat, PxVec3(0.0f, 3.50f, 0.0f));
		CreateShape(PxBoxGeometry(1.0f, 1.0f, 1.0f), 100, *mat, PxVec3(0.0f, 6.5f, 0.0f));
		
	}
};

class Catapult
{
public:
	CatapultBase base;
	CatapultArm arm;
	Catapult(string name, PxPhysics* phy, Scene scene);


};


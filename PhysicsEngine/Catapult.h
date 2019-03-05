#pragma once
#include <iostream>
#include "Actor.h"
#include "Scene.h"
#include "Projectile.h"
#include "GameObject.h"

using namespace std;
class CatapultBase : public Actor
{
public:
	CatapultBase()
	{

	};

	CatapultBase(const char* name, PxPhysics* phy) : Actor(name, phy)
	{
		
	};

	
	void CreateDynamic()
	{
			PxMaterial* mat = physics->createMaterial(1, 1, 1);
			actor = (PxRigidDynamic*)physics->createRigidDynamic(PxTransform(PxVec3(0, 1, 0)));

			//sides
			CreateShape(PxBoxGeometry(0.5f, 0.5f, 3.0f), *mat, 100,  PxVec3(0, 0, 0));
			CreateShape(PxBoxGeometry(0.5, 0.5f, 3.0f), *mat, 100,  PxVec3(5.0f, 0.0f, 0.0f));


			CreateShape(PxBoxGeometry(3.0f, 0.5f, 0.5f), *mat, 100,  PxVec3(2.5f, 0.0f, 3.5f)); //top
			CreateShape(PxBoxGeometry(3.0f, 0.5f, 0.5f), *mat, 100,  PxVec3(2.5f, 0.0f, -3.5f)); //bottom


			//left stilts
			CreateShape(PxBoxGeometry(0.5f, 1.0f, 0.5f), *mat, 1000,  PxVec3(6.0f, -0.5f, 3.5f)); //left
			CreateShape(PxBoxGeometry(0.5f, 1.0f, 0.5f), *mat, 1000,  PxVec3(6.0f, -0.5f, -3.5f)); //right

			//right stilitts
			CreateShape(PxBoxGeometry(0.5f, 1.0f, 0.5f), *mat, 1000,  PxVec3(-1.0f, -0.5f, 3.5f)); //left
			CreateShape(PxBoxGeometry(0.5f, 1.0f, 0.5f), *mat, 1000,  PxVec3(-1.0f, -0.5f, -3.5f)); //left







		
	}
	
};

class CatapultArm : public Actor
{
public:
	CatapultArm()
	{

	};

	CatapultArm(const char* name, PxPhysics* phy) : Actor(name, phy)
	{

	};

	void CreateDynamic()
	{
		PxMaterial* mat = physics->createMaterial(1, 1, 1);
		actor = (PxRigidDynamic*)physics->createRigidDynamic(PxTransform(PxVec3(0, 5, 0)));

		CreateShape(PxBoxGeometry(1.5f, 0.5f, 0.5f), *mat, 100, PxVec3(0.0f, 1.0f, 0.0f));
		CreateShape(PxBoxGeometry(.5f, 2.0f, 0.5f), *mat, 100, PxVec3(0.0f, 3.50f, 0.0f));
		CreateShape(PxBoxGeometry(1.0f, 1.0f, 1.0f), *mat, 100,  PxVec3(0.0f, 6.5f, 0.0f));
		
	}
};

class Catapult : public GameObject
{
public:
	Scene* scene;
	CatapultBase* base;
	CatapultArm* arm;

	PxPhysics* phys;
	PxRevoluteJoint* leftJoint;
	PxRevoluteJoint* rightJoint;

	Catapult();
	Catapult(const char* name, PxPhysics* phy, Scene* scene);

	void Update();
	void KeyPress(char key);


private:
	PxFixedJoint* ballJoint;
	void CreateBall();
};


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

	void CreateDynamic(PxVec3 pos, PxVec3 size, PxMaterial* mat)
	{
			actor = (PxRigidDynamic*)physics->createRigidDynamic(PxTransform(pos));

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

			//pass trigger box
			//CreateShape(PxBoxGeometry(5.0f, 12.0f, 6.5f), *mat, -1, PxVec3(3.0f, 10.0f, 0.0f));
			//SetTrigger(true, 8);
			


	}
	void OnTriggerEnter(Actor* collidedObject);
	void SetHasBall(bool value);
	void SetHasRecived(bool value);
	bool GetRecived();

private:
	bool hasBall;
	bool hasRecivedBall = false;
	
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

	void CreateDynamic(PxVec3 pos, PxVec3 size, PxMaterial* mat)
	{
		actor = (PxRigidDynamic*)physics->createRigidDynamic(PxTransform(pos));

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
	Catapult(const char* name, PxPhysics* phy, Scene* scene, PxVec3 pos, PxMaterial* mat, PxMaterial* ballMat, bool _hasBall = false);
	Projectile* GetBall();

	int GetLaunchForce();
	void Update();
	void KeyPress(char key);
	void KeyHold(char key);
	bool hasBall;

private:
	PxFixedJoint* ballJoint;
	void CreateBall();
	int launchForce = 5;
	Projectile* ball;
	PxMaterial* ballMat;
	
	
};


#pragma once
#include "PxPhysicsAPI.h"
#include <string>
#include <vector>
#include "Extras/UserData.h"
#include "GameObject.h"



using namespace physx;
using namespace std;

struct FilterGroup
{
	enum Enum
	{
		ACTOR0 = (1 << 0),
		ACTOR1 = (1 << 1),
		ACTOR2 = (1 << 2)
		//add more if you need
	};
};


class Actor : public GameObject
{

public:
	Actor()
	{
		
	}

	Actor(const char* name, PxPhysics *physics)
	{
		this->name = name;
		this->physics = physics;
	};


	PxRigidActor* GetActor();
	string GetName();
	void SetName();
	
	
	
	void SetColor(PxVec3 color);
	bool GetDelete();
	void Delete();
	
	//collsion messages
	virtual void OnTriggerEnter(Actor* collidedObject);
	virtual void OnTriggerLeave(Actor* collidedObject);
	virtual void OnContact(Actor* collidedObject);

	//shape
	PxShape* GetShape(PxU32 index);
	vector<PxShape*> GetShapes(PxU32 index);
	void SetTrigger(bool value, PxU32 shape_index = -1);
	void SetupFiltering(PxU32 filterGroup, PxU32 filterMask, PxU32 shape_index = -1);
	

protected:
	virtual void CreateDynamic(PxVec3 pos, PxVec3 size, PxMaterial* mat);
	virtual void CreateStatic(PxVec3 pos, PxVec3 size, PxMaterial* mat);
	virtual void CreateDynamic();
	virtual void CreateStatic();
	virtual void CreateDynamic(PxVec3 pos);
	virtual void CreateStatic(PxVec3 pos);
	void CreateShape(const PxGeometry& geometry, PxMaterial& mat, int density = 1, PxVec3 local = PxVec3(0, 0, 0));
	
	
protected:
	const char* name;
	PxRigidActor* actor;
	PxPhysics* physics;
	vector<PxVec3> colors;
	bool flagForDeletion;

	
	
};


#pragma once
#include <PxPhysicsAPI.h>
#include <vector>
#include "Actor.h"
#include <Windows.h>
#include "BasicShapes.h"
#include <iostream>

using namespace std;
using namespace physx;

class Scene : public PxSimulationEventCallback
{
public:
	bool trigger = false;
	vector<Actor> sceneObj;

	Scene();
	Scene(PxPhysics* physics);
	

	void AddActor(Actor& actor);
	Actor GetActor(string name);
	PxScene* GetScene();
	void ListActors();

	//collsion Callbacks
	static PxFilterFlags CustomFilterShader(PxFilterObjectAttributes attributes0, PxFilterData filterData0,
		PxFilterObjectAttributes attributes1, PxFilterData filterData1,
		PxPairFlags& pairFlags, const void* constantBlock, PxU32 constantBlockSize);


	virtual void onTrigger(PxTriggerPair* pairs, PxU32 count);
	virtual void onContact(const PxContactPairHeader &pairHeader, const PxContactPair *pairs, PxU32 nbPairs);
	virtual void onConstraintBreak(PxConstraintInfo *constraints, PxU32 count) {}
	virtual void onWake(PxActor **actors, PxU32 count) {}
	virtual void onSleep(PxActor **actors, PxU32 count) {}

private:
	PxScene* scene;


};


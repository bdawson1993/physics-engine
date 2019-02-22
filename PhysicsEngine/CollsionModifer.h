#pragma once
#include "PxPhysicsAPI.h"
#include <iostream>

using namespace physx;
using namespace std;

class MyContactModification : public PxSimulationEventCallback
{
public:
	bool trigger;

	MyContactModification() : trigger(false)
	{

	}
	virtual void onTrigger(PxTriggerPair* pairs, PxU32 count);
	virtual void onContact(const PxContactPairHeader &pairHeader, const PxContactPair *pairs, PxU32 nbPairs);
	virtual void onConstraintBreak(PxConstraintInfo *constraints, PxU32 count) {}
	virtual void onWake(PxActor **actors, PxU32 count) {}
	virtual void onSleep(PxActor **actors, PxU32 count) {}

	static PxFilterFlags CustomFilterShader(PxFilterObjectAttributes attributes0, PxFilterData filterData0,
		PxFilterObjectAttributes attributes1, PxFilterData filterData1,
		PxPairFlags& pairFlags, const void* constantBlock, PxU32 constantBlockSize);
};

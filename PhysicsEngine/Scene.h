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
	vector<Actor*> sceneObj;

	Scene() {
		
	
	};
	Scene(PxPhysics* physics, PxSimulationFilterShader custom_filter_shader = PxDefaultSimulationFilterShader) : filter_shader(custom_filter_shader) 
	{
		//create scence
		PxSceneDesc scenceDesc(physics->getTolerancesScale());



		//use CPU
		if (!scenceDesc.cpuDispatcher)
		{
			PxDefaultCpuDispatcher* mCpuDispacher = PxDefaultCpuDispatcherCreate(1);
			scenceDesc.cpuDispatcher = mCpuDispacher;
		}


		 
		scenceDesc.filterShader = &CustomFilterShader;

		


		scene = physics->createScene(scenceDesc);
		scene->setGravity(PxVec3(0.f, -9.81f, 0.f));

		scene->setVisualizationParameter(PxVisualizationParameter::eJOINT_LOCAL_FRAMES, true);
		scene->setVisualizationParameter(PxVisualizationParameter::eJOINT_LIMITS, true);
	
	};
	
	void CheckActors();
	void AddActor(Actor& actor);
	Actor* GetActor(string name);
	PxScene* GetScene();
	vector<PxActor*> GetActors();
	void ListAllActors();

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
	PxSimulationFilterShader filter_shader;


};


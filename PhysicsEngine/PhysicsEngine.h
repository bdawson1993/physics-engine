#pragma once
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <PxPhysicsAPI.h>

using namespace physx;

class PhysicsEngine
{
private:
	PxPhysics* physics;
	PxFoundation* foundation;
	debugger::comm::PvdConnection* vd_connection;
	PxScene* scene;
	bool isLoaded;
	PxMaterial* default_material;
	
	bool InitPhysics();
	void PxRelease();
	void InitScene();


public:
	PhysicsEngine();
	~PhysicsEngine();

	void Update(PxReal delta_time);
	void AddCube(PxVec3 loc, PxBoxGeometry boxDim);


};
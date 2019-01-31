#pragma once
#include <iostream>
#include <PxPhysicsAPI.h>

using namespace physx;

class PhysicsEngine
{
private:
	PxPhysics* physics;
	PxFoundation* foundation;
	debugger::comm::PvdConnection* vd_connection;
	PxScene* scence;

	
	bool InitPhysics();



public:
	PhysicsEngine();
	~PhysicsEngine();


};
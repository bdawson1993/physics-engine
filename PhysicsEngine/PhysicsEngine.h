#pragma once

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <PxPhysicsAPI.h>
#include <string>
#include "Scene.h"
#include "BasicShapes.h"




using namespace physx;
using namespace std;



class PhysicsEngine
{
private:
	
	bool InitPhysics();
	void PxRelease();

public:
	PhysicsEngine();
	~PhysicsEngine();

	
	void Update(PxReal delta_time);
	virtual void CustomUpdate();
	Scene* GetScene();

protected:
	virtual void SceneSetup();
	PxPhysics* physics;
	PxFoundation* foundation;
	debugger::comm::PvdConnection* vd_connection;
	Scene scene;
	bool isLoaded;
	PxMaterial* default_material;

};

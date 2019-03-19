#pragma once

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <PxPhysicsAPI.h>
#include <string>
#include "Scene.h"
#include "BasicShapes.h"
#include "Materials.h"




using namespace physx;
using namespace std;



class PhysicsEngine
{
private:
	
	bool InitPhysics();
	
	bool pause = false;

public:
	PhysicsEngine();

	void PxRelease();
	void Update(PxReal delta_time);
	virtual void CustomUpdate();
	Scene* GetScene();
	bool Pause();
	void Pause(bool value);

	

protected:
	virtual void SceneSetup();
	PxPhysics* physics;
	PxFoundation* foundation;
	debugger::comm::PvdConnection* vd_connection;
	Scene scene;
	bool isLoaded;
	PxMaterial* default_material;
	Materials mat; 

	virtual void KeyPress(char key);

	
	

};

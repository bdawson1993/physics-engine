#pragma once
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <PxPhysicsAPI.h>
#include <string>
#include "Scene.h"
#include "BasicShapes.h"
#include "Materials.h"
#include "SZ_HighResTimer.h"

using namespace physx;
using namespace std;


class PhysicsEngine
{
private:
	bool InitPhysics();
	bool pause = false;
	

public:
	PhysicsEngine();
	~PhysicsEngine();
	void PxRelease();
	float Update(PxReal delta_time);
	virtual void CustomUpdate();
	Scene* GetScene();
	bool Pause();
	void Pause(bool value);
	int GetScore();
	

protected:
	float updateRate;
	SZ_HighResTimer timer;
	virtual void SceneSetup();
	PxPhysics* physics;
	PxFoundation* foundation;
	debugger::comm::PvdConnection* vd_connection;
	Scene scene;
	bool isLoaded;
	PxMaterial* default_material;
	Materials mat; 
	virtual void KeyPress(char key);
	
	int score;
	

	
	

};

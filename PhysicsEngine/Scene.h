#pragma once
#include <PxPhysicsAPI.h>
#include <vector>
#include "Actor.h"
#include <Windows.h>
#include "BasicShapes.h"
#include <iostream>

using namespace std;
using namespace physx;

class Scene
{
public:
	vector<Actor> sceneObj;

	Scene();
	Scene(PxPhysics* physics);
	

	void AddActor(Actor& actor);
	Actor GetActor(string name);
	PxScene* GetScene();
	void ListActors();

private:
	PxScene* scene;


};


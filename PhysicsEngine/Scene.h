#pragma once
#include <PxPhysicsAPI.h>
#include <vector>
#include "Actor.h"

using namespace std;
using namespace physx;

class Scene
{
public:
	vector<Actor*> sceneObj;

	Scene();
	Scene(PxPhysics* physics, PxSceneDesc desc);
	

	void AddActor(Actor* actor);
	Actor* GetActor(string name);
	PxScene* GetScene();

private:
	PxScene* scene;

};
#pragma once

#include <PxPhysicsAPI.h>

using namespace physx;

class Scene
{
public:
	Scene();
	~Scene();
	PxScene* GetScene();
	void Update();
	void AddActor();

private:
	PxScene* scene;
};

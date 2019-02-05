#pragma once

#include <vector>
#include <PxPhysicsAPI.h>



using namespace physx;
using namespace std;

class Scene
{
public:
	Scene();
	~Scene();
	PxScene* GetScene();
	void Update();
	void AddActor();
	void InitScene(PxScene* px);


private:
	PxScene* scene;

};

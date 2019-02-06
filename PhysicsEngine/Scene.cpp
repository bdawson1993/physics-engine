#include "pch.h"
#include "Scene.h"


Scene::Scene()
{
}

Scene::Scene(PxPhysics* physics)
{
	//create scence
	PxSceneDesc scenceDesc(physics->getTolerancesScale());

	//use CPU
	if (!scenceDesc.cpuDispatcher)
	{
		PxDefaultCpuDispatcher* mCpuDispacher = PxDefaultCpuDispatcherCreate(1);
		scenceDesc.cpuDispatcher = mCpuDispacher;
	}


	if (!scenceDesc.filterShader)
	{
		scenceDesc.filterShader = PxDefaultSimulationFilterShader;
	}

	scene = physics->createScene(scenceDesc);
	scene->setGravity(PxVec3(0.f, -9.81f, 0.f));
}

void Scene::AddActor(Actor* actor)
{
	sceneObj.push_back(actor);
	scene->addActor(*actor->GetActor());

}

Actor * Scene::GetActor(string name)
{
	for (int i = 0; i < sceneObj.size(); i++)
	{
		if (sceneObj[i]->GetName() == name)
		{
			return sceneObj[i];
		}
	}

	return nullptr;
}

PxScene * Scene::GetScene()
{
	return scene;
}

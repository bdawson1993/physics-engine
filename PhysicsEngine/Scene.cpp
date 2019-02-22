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

	scene->setVisualizationParameter(PxVisualizationParameter::eJOINT_LOCAL_FRAMES, true);
	scene->setVisualizationParameter(PxVisualizationParameter::eJOINT_LIMITS, true);

	
}

void Scene::AddActor(Actor& actor)
{
	sceneObj.push_back(actor);
	scene->addActor(*actor.GetActor());

}

Actor Scene::GetActor(string name)
{
	for (int i = 0; i < sceneObj.size(); i++)
	{
		if (sceneObj[i].GetName() == name)
		{
			cout << "Found" << endl;
			return sceneObj[i];
		}
	}

	cout << "Not Found" << endl;
}

PxScene * Scene::GetScene()
{
	return scene;
}

void Scene::ListActors()
{
	for (int x = 0; x <= sceneObj.size() - 1; x++)
	{
		cout << sceneObj[x].GetName() << endl;
	}

}


#include "pch.h"
#include "Scene.h"


Scene::Scene()
{
}

Scene::Scene(PxPhysics* physics, PxSceneDesc desc)
{
	scene = physics->createScene(desc);
	scene->setGravity(PxVec3(0.f, -9.81f, 0.f));
}

void Scene::AddActor(Actor* actor)
{
	sceneObj.push_back(actor);

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

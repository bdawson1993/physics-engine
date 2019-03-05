#include "pch.h"
#include "Scene.h"

void Scene::AddActor(Actor& actor)
{
	actor.SetName();
	sceneObj.push_back(&actor);
	scene->addActor(*actor.GetActor());
}

Actor* Scene::GetActor(string name)
{
	for (int i = 0; i < sceneObj.size(); i++)
	{
		if (sceneObj[i]->GetName() == name)
		{
			return sceneObj[i];
		}
	}
}

PxScene * Scene::GetScene()
{
	return scene;
}

vector<PxActor*> Scene::GetActors()
{
	physx::PxActorTypeSelectionFlags selection_flag = PxActorTypeSelectionFlag::eRIGID_DYNAMIC | PxActorTypeSelectionFlag::eRIGID_STATIC |
		PxActorTypeSelectionFlag::eCLOTH;
	std::vector<PxActor*> actors(scene->getNbActors(selection_flag));
	scene->getActors(selection_flag, (PxActor**)&actors.front(), (PxU32)actors.size());
	return actors;

}

PxFilterFlags Scene::CustomFilterShader(PxFilterObjectAttributes attributes0, PxFilterData filterData0, PxFilterObjectAttributes attributes1, PxFilterData filterData1, PxPairFlags & pairFlags, const void * constantBlock, PxU32 constantBlockSize)
{
	// let triggers through
	if (PxFilterObjectIsTrigger(attributes0) || PxFilterObjectIsTrigger(attributes1))
	{
		pairFlags = PxPairFlag::eTRIGGER_DEFAULT;
		return PxFilterFlags();
	}

	pairFlags = PxPairFlag::eCONTACT_DEFAULT;
	//enable continous collision detection
	pairFlags |= PxPairFlag::eCCD_LINEAR;


		//customise collision filtering here
		//e.g.

		// trigger the contact callback for pairs (A,B) where 
		// the filtermask of A contains the ID of B and vice versa.
	if ((filterData0.word0 & filterData1.word1) && (filterData1.word0 & filterData0.word1))
	{
		//trigger onContact callback for this pair of objects
		pairFlags |= PxPairFlag::eNOTIFY_TOUCH_FOUND;
		pairFlags |= PxPairFlag::eNOTIFY_TOUCH_LOST;
		pairFlags |= PxPairFlag::eNOTIFY_CONTACT_POINTS;
	}

	return PxFilterFlags();
}

void Scene::onTrigger(PxTriggerPair * pairs, PxU32 count)
{
	for (PxU32 i = 0; i < count; i++)
	{
		if (pairs[i].status & PxPairFlag::eNOTIFY_TOUCH_FOUND)
		{
			Actor* triggerActor = GetActor(pairs[i].triggerActor->getName());
			Actor* otherActor = GetActor(pairs[i].otherActor->getName());

			//send object that had been collided with
			triggerActor->OnTriggerEnter(otherActor);
			
		}

		if (pairs[i].status & PxPairFlag::eNOTIFY_TOUCH_LOST)
		{
			Actor* triggerActor = GetActor(pairs[i].triggerActor->getName());
			Actor* otherActor = GetActor(pairs[i].otherActor->getName());

			//send object that had been collided with
			triggerActor->OnTriggerLeave(otherActor);
			

			trigger = false;
		}
	}


}

void Scene::onContact(const PxContactPairHeader & pairHeader, const PxContactPair * pairs, PxU32 nbPairs)
{
	//check all pairs
	for (PxU32 i = 0; i < nbPairs; i++)
	{
		//check eNOTIFY_TOUCH_FOUND
		if (pairs[i].events & PxPairFlag::eNOTIFY_TOUCH_FOUND)
		{
			//cerr << "onContact::eNOTIFY_TOUCH_FOUND" << endl;
		}
		//check eNOTIFY_TOUCH_LOST
		if (pairs[i].events & PxPairFlag::eNOTIFY_TOUCH_LOST)
		{
			//cerr << "onContact::eNOTIFY_TOUCH_LOST" << endl;
		}
	}

}


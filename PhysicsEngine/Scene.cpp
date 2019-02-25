#include "pch.h"
#include "Scene.h"







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
//		pairFlags |= PxPairFlag::eCCD_LINEAR;


		//customise collision filtering here
		//e.g.

		// trigger the contact callback for pairs (A,B) where 
		// the filtermask of A contains the ID of B and vice versa.
	if ((filterData0.word0 & filterData1.word1) && (filterData1.word0 & filterData0.word1))
	{
		//trigger onContact callback for this pair of objects
		pairFlags |= PxPairFlag::eNOTIFY_TOUCH_FOUND;
		pairFlags |= PxPairFlag::eNOTIFY_TOUCH_LOST;
		//			pairFlags |= PxPairFlag::eNOTIFY_CONTACT_POINTS;
	}

	return PxFilterFlags();
}

void Scene::onTrigger(PxTriggerPair * pairs, PxU32 count)
{
	//you can read the trigger information here
	for (PxU32 i = 0; i < count; i++)
	{
		//filter out contact with the planes
		if (pairs[i].otherShape->getGeometryType() != PxGeometryType::ePLANE)
		{
			//check if eNOTIFY_TOUCH_FOUND trigger
			if (pairs[i].status & PxPairFlag::eNOTIFY_TOUCH_FOUND)
			{
				
				PxRigidActor* bod = (PxRigidBody*)pairs[i].otherActor;
				cout << bod->getName() << endl;

				cerr << "onTrigger::eNOTIFY_TOUCH_FOUND" << endl;
				trigger = true;
			}
			//check if eNOTIFY_TOUCH_LOST trigger
			if (pairs[i].status & PxPairFlag::eNOTIFY_TOUCH_LOST)
			{
				cerr << "onTrigger::eNOTIFY_TOUCH_LOST" << endl;
				trigger = false;
			}
		}
	}


}

void Scene::onContact(const PxContactPairHeader & pairHeader, const PxContactPair * pairs, PxU32 nbPairs)
{
	cerr << "Contact found between " << pairHeader.actors[0]->getName() << " " << pairHeader.actors[1]->getName() << endl;

	//check all pairs
	for (PxU32 i = 0; i < nbPairs; i++)
	{
		//check eNOTIFY_TOUCH_FOUND
		if (pairs[i].events & PxPairFlag::eNOTIFY_TOUCH_FOUND)
		{
			cerr << "onContact::eNOTIFY_TOUCH_FOUND" << endl;
		}
		//check eNOTIFY_TOUCH_LOST
		if (pairs[i].events & PxPairFlag::eNOTIFY_TOUCH_LOST)
		{
			cerr << "onContact::eNOTIFY_TOUCH_LOST" << endl;
		}
	}

}


#include "pch.h"
#include "CustomEngine.h"

void CustomEngine::SceneSetup()
{
	Catapult cap = Catapult("hello", physics);
	cap.CreateDynamic();

	
	scene.AddActor(cap);
	

}

void CustomEngine::CustomUpdate()
{
	PxRigidDynamic* captupult = (PxRigidDynamic*) scene.GetActor("hello").GetActor();

	
}

#include "pch.h"
#include "CustomEngine.h"

void CustomEngine::SceneSetup()
{
	CatapultBase cat = CatapultBase("base", physics);
	cat.CreateDynamic();

	scene.AddActor(cat);

	
	
	

}

void CustomEngine::CustomUpdate()
{
	
	
}

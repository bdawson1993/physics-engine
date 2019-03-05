#pragma once
#include "Actor.h"
#include <iostream>
#include <functional>

class Goal : public Actor
{
public:
	Goal(const char* name, PxPhysics* phy) : Actor(name, phy)
	{

	};

	Goal()
	{

	};

	void CreateStatic(PxVec3 pos, PxVec3 size, PxMaterial* mat);


	void OnTriggerEnter(void);
};

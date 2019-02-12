#pragma once
#include <iostream>
#include "Actor.h"

using namespace std;
class CatapultBase : public Actor
{
public:
	CatapultBase(string name, PxPhysics* phy) : Actor(name, phy)
	{
		
	};

	void CreateDynamic();
};

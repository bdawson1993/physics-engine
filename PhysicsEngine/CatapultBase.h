#pragma once
#include <iostream>
#include "Actor.h"

using namespace std;
class Catapult : public Actor
{
public:
	Catapult(string name, PxPhysics* phy) : Actor(name, phy)
	{
		
	};

	void CreateDynamic();
};

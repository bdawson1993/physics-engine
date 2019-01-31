// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "PhysicsEngine.h"

int main()
{
	PhysicsEngine physics;
	
	physics.AddCube(PxVec3(0, 10, 0), PxBoxGeometry(.5f, .5f, .5f));
	physics.AddCube(PxVec3(0, 0, 0), PxBoxGeometry(.5f, .5f, .5f), 0.0f,0.0f,0.0f);

	PxReal time = 1.f / 60.0f;
	physics.Update(time);


}

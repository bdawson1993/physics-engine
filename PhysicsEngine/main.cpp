// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "PhysicsEngine.h"

int main()
{
	PhysicsEngine physics;

	for (int x = 1; x < 20; x++)
	{
		for (int y = 1; y < 10; y++)
		{

			physics.AddCube(PxVec3(x, y, 0), PxBoxGeometry(.5f, .5f, .5f));
		}
	}

	physics.AddSphere(PxVec3(4, 20, 0), 2);


	PxReal time = 1.f / 60.0f;
	physics.Update(time);


}

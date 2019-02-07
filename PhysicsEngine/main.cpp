// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "PhysicsEngine.h"







int main()
{
	PhysicsEngine physics;
	PxReal time = 1.f / 60.0f;
	physics.Update(time);

	return 0;
}





// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "CustomEngine.h"

int main(int argc, char* argv[])
{
	CustomEngine physics;
	physics.SceneSetup();

	PxReal time = 1.f / 60.0f;
	physics.Update(time);

	return 0;
}





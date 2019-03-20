#pragma once
#include <PxPhysicsAPI.h>
#include <map>
#include <iostream>

using namespace std;
using namespace physx;

class Materials
{
private:
	map<string, PxMaterial*> materials;


public:
	void AddMaterial(string name, PxMaterial* mat);
	PxMaterial* GetMaterial(string name);




};

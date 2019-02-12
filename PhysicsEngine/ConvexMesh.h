#pragma once
#include "Shape.h"

using namespace std;


class ConvexMesh : public Shape
{
    public:
        ConvexMesh(PxPhysics* physics);
        

	private:
		PxPhysics* physics;

};
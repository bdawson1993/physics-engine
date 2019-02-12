#pragma once

#include "PxPhysicsAPI.h"
#include <vector>

using namespace physx;
using namespace std;

class Shape
{
    public:
        Shape();

    protected:
		PxGeometry* shape;
       

};
#pragma once

#include "PxPhysicsAPI.h"

using namespace phys;

class Shape
{
    public:
        Shape();

    protected:
        PxGemometry* shape;
        virtual PxGemometry* CreateShape();

};
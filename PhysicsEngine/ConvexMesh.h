#pragma once
#include "Shape.h"

using namespace std;


class ConvexMesh : public Shape
{
    public:
        ConvexMesh(PxPhysics* physics);
        CreateShape(vector<PxVec3>& verts, PxTransform& pose=PxTransform(PxIdentity), PxReal density=1.f);

	private:
		PxPhysics* physics;

};
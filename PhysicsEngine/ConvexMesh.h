#pragma once
#include "Shape.h"

using namespace std;


class ConvexMesh : public Shape
{
    public:
        ConvexMesh();
        CreateShape(vector<PxVec3>& verts, PxTransform& pose=PxTransform(PxIdentity), PxReal density=1.f);
};
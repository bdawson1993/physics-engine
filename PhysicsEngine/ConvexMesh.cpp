#include "CovexMesh.h"

CovexMesh::CreateShape(vector<PxVec3>& verts, PxTransform& pose=PxTransform(PxIdentity), PxReal density=1.f)
{
    PxConvexMeshDesc mesh_desc;
	mesh_desc.points.count = (PxU32)verts.size();
	mesh_desc.points.stride = sizeof(PxVec3);
	mesh_desc.points.data = &verts.front();
	mesh_desc.flags = PxConvexFlag::eCOMPUTE_CONVEX;
	mesh_desc.vertexLimit = 256;
}
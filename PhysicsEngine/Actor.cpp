#include "pch.h"
#include "Actor.h"



PxRigidActor* Actor::GetActor()
{
	return actor;
}

string Actor::GetName()
{
	return name;
}

void Actor::SetTrigger(bool value, PxU32 shape_index)
{
	std::vector<PxShape*> shape_list = GetShapes(shape_index);
	for (PxU32 i = 0; i < shape_list.size(); i++)
	{
		shape_list[i]->setFlag(PxShapeFlag::eSIMULATION_SHAPE, !value);
		shape_list[i]->setFlag(PxShapeFlag::eTRIGGER_SHAPE, value);
	}
}

void Actor::SetupFiltering(PxU32 filterGroup, PxU32 filterMask, PxU32 shape_index)
{
	vector<PxShape*> shape_list = GetShapes(shape_index);
	for (PxU32 i = 0; i < shape_list.size(); i++)
		shape_list[i]->setSimulationFilterData(PxFilterData(filterGroup, filterMask, 0, 0));
}

vector<PxShape*> Actor::GetShapes(PxU32 index)
{
	vector<PxShape*> shapes(((PxRigidActor*)actor)->getNbShapes());
	((PxRigidActor*)actor)->getShapes((PxShape**)&shapes.front(), (PxU32)shapes.size());
	if (index == -1)
		return shapes;
	else if (index < shapes.size())
	{
		return std::vector<PxShape*>(1, shapes[index]);
	}
	else
		return std::vector<PxShape*>();
}


void Actor::CreateDynamic(PxVec3 pos, PxVec3 size, PxMaterial * mat)
{
}

void Actor::CreateStatic(PxVec3 pos, PxVec3 size, PxMaterial* mat)
{
}

void Actor::CreateDynamic()
{
}

void Actor::CreateStatic()
{
}

void  Actor::CreateShape(const PxGeometry& geometry, int density, PxMaterial& mat, PxVec3 local)
{

	PxShape* shape = actor->createShape(geometry, mat);
	PxRigidBodyExt::updateMassAndInertia(*(PxRigidDynamic*)actor, density);
	shape->setLocalPose(PxTransform(local));
	
}






#include "pch.h"
#include "Actor.h"
#include <iostream>


PxRigidActor* Actor::GetActor()
{
	return actor;
}

string Actor::GetName()
{
	return name;
}

void Actor::SetName()
{
	actor->setName(name);
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

PxShape * Actor::GetShape(PxU32 index)
{
	std::vector<PxShape*> shapes(((PxRigidActor*)actor)->getNbShapes());
	if (index < ((PxRigidActor*)actor)->getShapes((PxShape**)&shapes.front(), (PxU32)shapes.size()))
		return shapes[index];
	else
		return 0;
}

void Actor::SetColor(PxVec3 color)
{
		for (unsigned int i = 0; i < colors.size(); i++)
			colors[i] = color;
}

void Actor::CreateShape(const PxGeometry& geometry, PxMaterial& mat, int density, PxVec3 local)
{
	if (actor->isRigidDynamic())
	{
		PxShape* shape = actor->createShape(geometry, mat);
		PxRigidBodyExt::updateMassAndInertia(*(PxRigidDynamic*)actor, density);
		shape->setLocalPose(PxTransform(local));

		PxVec3 default_color = PxVec3(255.0f, 0.0f, 0.0f);
		colors.push_back(default_color);

		//pass the color pointers to the renderer
		shape->userData = new UserData();
		for (unsigned int i = 0; i < colors.size(); i++)
			((UserData*)GetShape(i)->userData)->color = &colors[i];
	}
	else
	{

		PxShape* Nshape = actor->createShape(geometry, mat);
		Nshape->setLocalPose(PxTransform(local));

		PxVec3 static_color = PxVec3(0.0f, 255.0f, 0.0f);
		colors.push_back(static_color);

		//pass the color pointers to the renderer
		Nshape->userData = new UserData();
		for (unsigned int i = 0; i < colors.size(); i++)
			((UserData*)GetShape(i)->userData)->color = &colors[i];
	}

}


///abstract functions 
void Actor::OnTriggerEnter(Actor* collidedObject)
{
	cout << "On Trigger Enter " << endl;
}

void Actor::OnTriggerLeave(Actor* collidedObject)
{
	cout << "On Trigger Leave " << endl;
}

void Actor::OnContact(Actor* collidedObject)
{
	cout << "On Contact Enter" << endl;
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










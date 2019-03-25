#include "Projectile.h"

void Projectile::CreateDynamic(PxVec3 pos, PxVec3 size, PxMaterial* mat)
{
	actor = (PxRigidDynamic*)physics->createRigidDynamic(PxTransform(pos));
	CreateShape(PxBoxGeometry(0.5f, 0.5f, 0.5f), *mat, 1, pos);
	CreateShape(PxBoxGeometry(1.0f, 1.0f, 1.0f), *mat, 1, pos + PxVec3(0, pos.y + 0.5f, 0));
	CreateShape(PxBoxGeometry(0.5f, 0.5f, 0.5f), *mat, 1, pos + PxVec3(0, pos.y + 2.0f, 0));
	SetName();
	
}

void Projectile::OnContact(Actor* collidedObject)
{
	if (collidedObject->GetName() == "Ground")
	{
		//flagForDeletion = true;
	}
}

bool Projectile::HasScored()
{
	return hasScored;
}

void Projectile::Reset()
{
	hasScored = false;
}



void Projectile::OnTriggerEnter(Actor* collidedObject)
{
	
	if (collidedObject->GetName() == "goal")
	{
		cout << "collided" << endl;
		hasScored = true;
	}
}

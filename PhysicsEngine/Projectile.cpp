#include "Projectile.h"

void Projectile::OnContact(Actor* collidedObject)
{
	if (collidedObject->GetName() == "Ground")
	{
		delete(collidedObject);
		
	}

	
}

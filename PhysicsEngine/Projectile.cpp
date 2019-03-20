#include "Projectile.h"

void Projectile::OnContact(Actor* collidedObject)
{
	flagForDeletion = true;
	if (collidedObject->GetName() == "Ground")
	{
		
		cout << "Flag" << endl;

	}
	
}

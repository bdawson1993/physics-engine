#include "Projectile.h"

void Projectile::OnContact(Actor* collidedObject)
{
	cout << " DO STUFF " << endl;
	if (collidedObject->GetName() == "ball")
	{
		collidedObject->GetActor()->release();
		
	}

	
}

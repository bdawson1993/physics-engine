#pragma once
#include "Actor.h"

class GameObject : public Actor
{
public:
	GameObject()
	{

	};

	GameObject(const char* name, PxPhysics* phy) : Actor(name, phy)
	{

	};


protected:
	virtual void Update();
	virtual void KeyPress(char key);
	virtual void KeyRelase(char key);
	virtual void KeyHold(char key);
};

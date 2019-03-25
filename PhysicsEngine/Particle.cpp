#include "Particle.h"

void Particle::Update()
{
	life++;
}

int Particle::GetLife()
{
	return life;
}

void Particle::CreateDynamic(PxVec3 pos, PxVec3 size, PxMaterial * mat)
{
	Cube* cube = new Cube("particle", physics);
	cube->CreateDynamic(pos, size, mat);
	cube->SetColor(PxVec3(0.0f, 0.0f, 204.0f));
	actor = cube->GetActor();
}

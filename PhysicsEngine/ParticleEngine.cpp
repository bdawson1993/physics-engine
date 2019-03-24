#include "ParticleEngine.h"

void ParticleEngine::Emit()
{
	switch (shape)
	{
	case EmitterShape::ShapeRectangle:
		PxVec3 loc = PxVec3((-100 + rand() % 200), y, (-100 + rand() % 200));
		Particle* cube = new Particle("particle", phys);
		cube->CreateDynamic(loc, PxVec3(0.2f, 0.2f, 0.2f), mat);
		cube->SetColor(PxVec3(0.0f, 0.0f, 204.0f));
		scene->AddActor(*cube);
		particles.push_back(cube);
			break;
	}

}

void ParticleEngine::Update()
{
	//update all particles
	for (int i = 0; i < particles.size(); i++)
	{
		particles[i]->Update();

		if (particles[i]->GetLife() > life)
		{
			particles[i]->Delete();
			particles.erase(particles.begin() + i);
		}
	}

}



#pragma once
#include "Scene.h"
#include "BasicShapes.h"
#include <random>
#include <vector>
#include "Particle.h"


using namespace std;

enum EmitterShape
{
	ShapeRectangle = 0,
};

struct ParticleEngineSettings
{
	Scene* scene;
	PxPhysics* phys;
	int life = 0;
	int count = 0;
	EmitterShape shape;
	PxMaterial* material;
	int height;
	PxVec2 xRange;
	PxVec2 zRange;


};



class ParticleEngine
{
public:
	ParticleEngine()
	{

	};

	ParticleEngine(ParticleEngineSettings settings)
	{
		
		this->scene = settings.scene;
		this->shape = settings.shape;
		this->xRange = settings.xRange;
		this->zRange = settings.zRange;
		this->y = settings.height;
		this->mat = settings.material;
		this->life = settings.life;
		this->phys = settings.phys;
	}

	

	void Emit();
	void Update();

private:
	EmitterShape shape;
	Scene* scene;
	int y = 0;

	PxVec2 xRange;
	PxVec2 zRange;

	

	PxPhysics* phys;
	PxMaterial* mat;
	vector<Particle*> particles;
	int life = 280;

	int InRange(int min, int max);
	
	




};



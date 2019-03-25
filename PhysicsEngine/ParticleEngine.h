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
	int life = 0;
	int count = 0;
	EmitterShape shape;
	PxMaterial* material;
};



class ParticleEngine
{
public:
	ParticleEngine()
	{

	};

	ParticleEngine(Scene* scene, PxPhysics* phys,  EmitterShape shape, PxMaterial* partMat, PxVec3 pos, int low, int high)
	{
		this->scene = scene;
		this->shape = shape;
		this->xLow = low;
		this->xHigh = high;
		this->zLow = low;
		this->zHigh = high;
		this->y = pos.y;
		this->phys = phys;
		this->mat = partMat;
	}

	void Emit();
	void Update();

private:
	EmitterShape shape;
	Scene* scene;
	int y = 0;
	int xLow = 0;
	int xHigh = 0;
	int zLow = 0;
	int zHigh = 0;
	PxPhysics* phys;
	PxMaterial* mat;
	vector<Particle*> particles;
	int life = 280;

	int InRange(int min, int max);
	
	




};



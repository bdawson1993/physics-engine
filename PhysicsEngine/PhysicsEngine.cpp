#include "pch.h"
#include "PhysicsEngine.h"
#include "glut.h"

PhysicsEngine::PhysicsEngine()
{
	if (InitPhysics() == true)
	{
		isLoaded = true;
	}
	else
	{
		throw exception("Failed To Init Physics");
	}
}

PhysicsEngine::~PhysicsEngine()
{
	
}

float PhysicsEngine::Update(PxReal delta_time)
{
	timer.resetChronoTimer();
	CustomUpdate();
	scene.GetScene()->simulate(delta_time);
	scene.GetScene()->fetchResults(true);
	updateRate = timer.getChronoTime();
	return updateRate;
	
}

void PhysicsEngine::CustomUpdate()
{
}

Scene* PhysicsEngine::GetScene()
{
	return &scene;
}

bool PhysicsEngine::Pause()
{
	return pause;
}

void PhysicsEngine::Pause(bool value)
{
	pause = value;
}

int PhysicsEngine::GetScore()
{
	return score;
}

void PhysicsEngine::SceneSetup()
{
}

void PhysicsEngine::KeyPress(char key)
{
}

bool PhysicsEngine::InitPhysics()
{
	//init error and allocator callbacks
	static PxDefaultErrorCallback gDefaultErrorCallback;
	static PxDefaultAllocator gDefaultAllocatorCallback;

	foundation = PxCreateFoundation(PX_PHYSICS_VERSION, gDefaultAllocatorCallback, gDefaultErrorCallback);


	if (!foundation)
	{
		return false;
	}

	physics = PxCreatePhysics(PX_PHYSICS_VERSION, *foundation, PxTolerancesScale());

	if (!physics)
	{
		return false;
	}

	

	//connect to Visual debugger
	vd_connection = PxVisualDebuggerExt::createConnection(physics->getPvdConnectionManager(), "localhost", 5425, 100,
		PxVisualDebuggerExt::getAllConnectionFlags());

	PxInitExtensions(*physics);


	//create scene
	scene = Scene(physics);

	//visualisation
	scene.GetScene()->setVisualizationParameter(PxVisualizationParameter::eSCALE, 1.0f);
	scene.GetScene()->setVisualizationParameter(PxVisualizationParameter::eCOLLISION_SHAPES, 1.0f);
	scene.GetScene()->setVisualizationParameter(PxVisualizationParameter::eCLOTH_HORIZONTAL, 1.0f);
	scene.GetScene()->setVisualizationParameter(PxVisualizationParameter::eCLOTH_VERTICAL, 1.0f);
	scene.GetScene()->setVisualizationParameter(PxVisualizationParameter::eCLOTH_BENDING, 1.0f);
	scene.GetScene()->setVisualizationParameter(PxVisualizationParameter::eCLOTH_SHEARING, 1.0f);

	//create default material
	default_material = physics->createMaterial(0.35f, 0.35f, 0.0f);

	//create floor
	mat.AddMaterial("Grass", physics->createMaterial(0.35f, 0.35f, 0.0f));
	mat.AddMaterial("default", physics->createMaterial(0.0f, 0.0f, 0.0f));

	Plane* plane = new Plane("Ground", physics);
	plane->CreateStatic(PxVec3(0, 1, 0), PxVec3(1, 1, 1), mat.GetMaterial("Grass"));
	plane->SetColor(PxVec3(0.0f, 255.0f, 0.0f));
	plane->SetupFiltering(FilterGroup::ACTOR0, FilterGroup::ACTOR1);

	scene.AddActor(*plane);


	scene.GetScene()->setSimulationEventCallback(&scene);
	


	return true;
}

void PhysicsEngine::PxRelease()
{
	if (scene.GetScene())
		scene.GetScene()->release();
	if (vd_connection)
		vd_connection->release();
	if (physics)
		physics->release();
	if (foundation)
		foundation->release();
	


}

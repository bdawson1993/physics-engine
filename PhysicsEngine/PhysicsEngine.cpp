#include "pch.h"
#include "PhysicsEngine.h"



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
	PxRelease();
}

void PhysicsEngine::Update(PxReal delta_time)
{
	if (isLoaded == true)
	{
		while (!GetAsyncKeyState(VK_ESCAPE))
		{
			CustomUpdate();
			scene.GetScene()->simulate(delta_time);
			scene.GetScene()->fetchResults(true);
			Sleep(10);
		}

	}

}

void PhysicsEngine::CustomUpdate()
{
}

Scene* PhysicsEngine::GetScene()
{
	return &scene;
}

void PhysicsEngine::SceneSetup()
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


	//create default material
	default_material = physics->createMaterial(1.f, 1.f, 0.f);

	//create floor
	Plane plane = Plane("Ground", physics);
	plane.CreateStatic(PxVec3(0, 1, 0), PxVec3(1, 1, 1), default_material);
	scene.AddActor(plane);

	
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

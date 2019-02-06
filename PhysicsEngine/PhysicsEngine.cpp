#include "pch.h"
#include "PhysicsEngine.h"
#include "Plane.h"
#include "Cube.h"
#include "Sphere.h"


PhysicsEngine::PhysicsEngine()
{
	if (InitPhysics() == false)
	{
		std::cout << "Physics Init Failed" << std::endl;
		isLoaded = false;
	}
	else
	{
		std::cout << "Physics Init Complete" << std::endl;
		isLoaded = true;

	}
}

PhysicsEngine::~PhysicsEngine()
{
	PxRelease();
}

void PhysicsEngine::Update(PxReal delta_time)
{
	for (int x = 1; x < 10; x++)
	{
		for (int y = 1; y < 10; y++)
		{
			for (int z = 1; z < 10; z++)
			{

				Cube cube = Cube("cube" + x, physics);
				cube.CreateDynamic(PxVec3(x, y, z), PxVec3(.5f, .5f, .5f), default_material);
				scene.AddActor(&cube);
			}
		}
	}

	Sphere sp = Sphere("ball", physics);
	sp.CreateDynamic(PxVec3(5, 20, 5), 3, default_material);
	scene.AddActor(&sp);


	if (isLoaded == true)
	{


		while (!GetAsyncKeyState(VK_ESCAPE))
		{
			scene.GetScene()->simulate(delta_time);
			scene.GetScene()->fetchResults(true);
			Sleep(100);
		}

	}

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





	//create base plane and set gravity
	default_material = physics->createMaterial(1.f, 1.f, 0.f);



	//create floor
	Plane plane = Plane("Ground", physics);
	plane.CreateStatic(PxVec3(0, 1, 0), PxVec3(1, 1, 1), default_material);

	scene.AddActor(&plane);



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

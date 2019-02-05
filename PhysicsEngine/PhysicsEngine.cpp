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
	Cube cube = Cube("box", physics);
	cube.CreateStatic(PxVec3(1, 1, 1), PxVec3(.5f,.5f,.5f), default_material);
	scene.AddActor(&cube);

	Cube cube2 = Cube("box", physics);
	cube2.CreateDynamic(PxVec3(1, 10, 1), PxVec3(.5f, .5f, .5f), default_material);
	scene.AddActor(&cube2);

	Sphere sp = Sphere("ball", physics);
	sp.CreateDynamic(PxVec3(3, 10, 1), 1, default_material);
	scene.AddActor(&sp);

	if (isLoaded == true)
	{
		
		sp.GetActor().
		while (!GetAsyncKeyState(VK_ESCAPE))
		{
			scene.GetScene()->simulate(delta_time);
			scene.GetScene()->fetchResults(true);
			Sleep(100);
		}
		
	}

}


void PhysicsEngine::AddSphere(PxVec3 loc, PxReal dim)
{
	PxRigidDynamic* sphere = physics->createRigidDynamic(PxTransform(loc));
	sphere->createShape(PxSphereGeometry(dim), *default_material);
	PxRigidBodyExt::updateMassAndInertia(*sphere, 1.f);
	
}

void PhysicsEngine::AddSphere(PxVec3 loc, PxReal dim, PxReal statFric, PxReal dynmFriction, PxReal bouncyness)
{
	PxRigidDynamic* sphere = physics->createRigidDynamic(PxTransform(loc));
	PxMaterial* mat = physics->createMaterial(statFric, dynmFriction, bouncyness);
	sphere->createShape(PxSphereGeometry(dim), *mat);
	PxRigidBodyExt::updateMassAndInertia(*sphere, 1.f);
	
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
	



	//create scence
	PxSceneDesc scenceDesc(physics->getTolerancesScale());

	//use CPU
	if (!scenceDesc.cpuDispatcher)
	{
		PxDefaultCpuDispatcher* mCpuDispacher = PxDefaultCpuDispatcherCreate(1);
		scenceDesc.cpuDispatcher = mCpuDispacher;
	}


	if (!scenceDesc.filterShader)
	{
		scenceDesc.filterShader = PxDefaultSimulationFilterShader;
	}
	
	scene = Scene(physics, scenceDesc);

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

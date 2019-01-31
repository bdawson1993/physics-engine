#include "pch.h"
#include "PhysicsEngine.h"


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
	if (isLoaded == true)
	{
		while (!GetAsyncKeyState(VK_ESCAPE))
		{
			scene->simulate(delta_time);
			scene->fetchResults(true);
		}
		
	}

}

void PhysicsEngine::AddCube(PxVec3 loc, PxBoxGeometry boxDim)
{
	PxRigidDynamic* box = physics->createRigidDynamic(PxTransform(loc));
	box->createShape(boxDim, *default_material);
	scene->addActor(*box);
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
	
	scene = physics->createScene(scenceDesc);

	if (!scene)
	{
		return false;
	}


	//create base plane and set gravity
	default_material = physics->createMaterial(0.f, 0.f, 0.f);
	scene->setGravity(PxVec3(0.f, -9.81f, 0.f));


	//create floor
	PxRigidStatic* plane = PxCreatePlane(*physics, PxPlane(PxVec3(0.f, 1.f, 0.f), 0.f), *default_material);
	scene->addActor(*plane);



	return true;

	

}

void PhysicsEngine::PxRelease()
{
	if (scene)
		scene->release();
	if (vd_connection)
		vd_connection->release();
	if (physics)
		physics->release();
	if (foundation)
		foundation->release();
}

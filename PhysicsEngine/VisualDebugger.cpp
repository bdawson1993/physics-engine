#include "VisualDebugger.h"
#include <vector>
#include "Extras\Camera.h"
#include "Extras\Renderer.h"
#include "Extras\HUD.h"

namespace VisualDebugger
{
	using namespace physx;

	enum RenderMode
	{
		DEBUG,
		NORMAL,
		BOTH
	};

	enum HUDState
	{
		EMPTY = 0,
		HELP = 1,
		PAUSE = 2
	};

	//function declarations
	void KeyHold();
	void KeySpecial(int key, int x, int y);
	void KeyRelease(unsigned char key, int x, int y);
	void KeyPress(unsigned char key, int x, int y);

	void motionCallback(int x, int y);
	void mouseCallback(int button, int state, int x, int y);
	void exitCallback(void);

	void RenderScene();
	void ToggleRenderMode();
	void HUDInit();

	///simulation objects
	Camera* camera;
	CustomEngine* eng;
	PxReal delta_time = 1.f/60.f;
	PxReal gForceStrength = 20;
	RenderMode render_mode = BOTH;
	const int MAX_KEYS = 256;
	bool key_state[MAX_KEYS];
	bool hud_show = false;
	HUD hud;
	float updateRate = 0.0f;

	//Init the debugger
	void Init(const char *window_name, int width, int height)
	{
		///Init PhysX
		eng = new CustomEngine();
		eng->SceneSetup();

		///Init renderer
		Renderer::BackgroundColor(PxVec3(150.f/255.f,150.f/255.f,150.f/255.f));
		Renderer::SetRenderDetail(40);
		Renderer::InitWindow(window_name, width, height);
		Renderer::Init();

		camera = new Camera(PxVec3(0.0f, 5.0f, 15.0f), PxVec3(0.f,-.1f,-1.f), 5.f);

		//initialise HUD
		//HUDInit();

		///Assign callbacks
		//render
		glutDisplayFunc(RenderScene);

		//keyboard
		glutKeyboardFunc(KeyPress);
		glutSpecialFunc(KeySpecial);
		glutKeyboardUpFunc(KeyRelease);

		//mouse
		glutMouseFunc(mouseCallback);
		glutMotionFunc(motionCallback);
		//glutFullScreen();


		//exit
		atexit(exitCallback);

		//init motion callback
		motionCallback(0,0);
	}

	void HUDInit()
	{
		//initialise HUD
		//add an empty screen
		hud.AddLine(EMPTY, "");
		hud.AddLine(EMPTY, "Launch Force: " + to_string(eng->GetCatForce()));
		hud.AddLine(EMPTY, "Update Rate: " + to_string(updateRate));

		//add a help screen
		hud.AddLine(HELP, "");
		hud.AddLine(HELP, "");
		hud.AddLine(HELP, " Camera");
		hud.AddLine(HELP, "    W,S,A,D,Q,Z - forward,backward,left,right,up,down");
		hud.AddLine(HELP, "    mouse + click - change orientation");
		hud.AddLine(HELP, "    F8 - reset view");
		hud.AddLine(HELP, "");

		hud.AddLine(HELP, " Controls");
		hud.AddLine(HELP, "     Space - fire");
		hud.AddLine(HELP, "     O - Rotate Right");
		hud.AddLine(HELP, "     I - Rotate Left");
		hud.AddLine(HELP, "     [ - Add Force");
		hud.AddLine(HELP, "     ] - Subtract Force");
		
		//add a pause screen
		hud.AddLine(PAUSE, "");
		hud.AddLine(PAUSE, "");
		hud.AddLine(PAUSE, "");
		hud.AddLine(PAUSE, "   Simulation paused. Press F10 to continue.");
		//set font size for all screens
		hud.FontSize(0.018f);
		//set font color for all screens
		hud.Color(PxVec3(0.f,0.f,0.f));
	}

	//Start the main loop
	void Start()
	{ 
		glutMainLoop(); 
	}

	//Render the scene and perform a single simulation step
	void RenderScene()
	{
		HUDInit();
		//handle pressed keys
		KeyHold();

		//start rendering
		Renderer::Start(camera->getEye(), camera->getDir());

		
		if ((render_mode == DEBUG) || (render_mode == BOTH))
		{
			Renderer::Render(eng->GetScene()->GetScene()->getRenderBuffer());
		}

		if ((render_mode == NORMAL) || (render_mode == BOTH))
		{
			std::vector<PxActor*> actors = eng->GetScene()->GetActors();
			if (actors.size())
				Renderer::Render(&actors[0], (PxU32)actors.size());
		}

		//adjust the HUD state
		if (hud_show)
		{
			if (eng->Pause())
				hud.ActiveScreen(PAUSE);
			else
				hud.ActiveScreen(HELP);
		}
		else
			hud.ActiveScreen(EMPTY);

		//render HUD
		hud.Render();

		//finish rendering
		Renderer::Finish();

		//perform a single simulation step
		updateRate = eng->Update(delta_time);
		hud.Clear();
	}

	//user defined keyboard handlers
	void UserKeyPress(int key)
	{
		switch (toupper(key))
		{
		//implement your own
		case 'R':
			
			break;
		default:
			break;
		}
		eng->KeyPress(key);
	}

	void UserKeyRelease(int key)
	{
		switch (toupper(key))
		{
		//implement your own
		case 'R':
			//scene->ExampleKeyReleaseHandler();
			break;
		default:
			break;
		}
	}

	void UserKeyHold(int key)
	{
		eng->KeyHold(key);
	}

	//handle camera control keys
	void CameraInput(int key)
	{
		switch (toupper(key))
		{
		case 'W':
			camera->MoveForward(delta_time);
			break;
		case 'S':
			camera->MoveBackward(delta_time);
			break;
		case 'A':
			camera->MoveLeft(delta_time);
			break;
		case 'D':
			camera->MoveRight(delta_time);
			break;
		case 'Q':
			camera->MoveUp(delta_time);
			break;
		case 'Z':
			camera->MoveDown(delta_time);
			break;
		default:
			break;
		}
	}

	//handle force control keys
	void ForceInput(int key)
	{
		
	}

	///handle special keys
	void KeySpecial(int key, int x, int y)
	{
		//simulation control
		switch (key)
		{
			//display control
		case GLUT_KEY_F5:
			//hud on/off
			hud_show = !hud_show;
			break;
		case GLUT_KEY_F6:
			//shadows on/off
			Renderer::ShowShadows(!Renderer::ShowShadows());
			break;
		case GLUT_KEY_F7:
			//toggle render mode
			ToggleRenderMode();
			break;
		case GLUT_KEY_F8:
			//reset camera view
			camera->Reset();
			break;
		
		case GLUT_KEY_F10:
			//toggle scene pause
			eng->Pause(!eng->Pause());
			break;
		case GLUT_KEY_F12:
			//resect scene
			//scene->Reset();
			break;
		default:
			break;
		}
	}

	//handle single key presses
	void KeyPress(unsigned char key, int x, int y)
	{
		//do it only once
		if (key_state[key] == true)
			return;

		key_state[key] = true;

		//exit
		if (key == 27)
			exit(0);
		UserKeyPress(key);
	}

	//handle key release
	void KeyRelease(unsigned char key, int x, int y)
	{
		key_state[key] = false;
		UserKeyRelease(key);
	}

	//handle holded keys
	void KeyHold()
	{
		for (int i = 0; i < MAX_KEYS; i++)
		{
			if (key_state[i]) // if key down
			{
				CameraInput(i);
				ForceInput(i);
				UserKeyHold(i);
			}
		}
	}

	///mouse handling
	int mMouseX = 0;
	int mMouseY = 0;

	void motionCallback(int x, int y)
	{
		int dx = mMouseX - x;
		int dy = mMouseY - y;

		camera->Motion(dx, dy, delta_time);

		mMouseX = x;
		mMouseY = y;
	}

	void mouseCallback(int button, int state, int x, int y)
	{
		mMouseX = x;
		mMouseY = y;
	}

	void ToggleRenderMode()
	{
		if (render_mode == NORMAL)
			render_mode = DEBUG;
		else if (render_mode == DEBUG)
			render_mode = BOTH;
		else if (render_mode == BOTH)
			render_mode = NORMAL;
	}

	///exit callback
	void exitCallback(void)
	{
		delete camera;
		eng->PxRelease();
		delete eng;
		
		
		
	}
}


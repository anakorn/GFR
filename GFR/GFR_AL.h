#ifndef GFR_FRAMEWORK_ALLEGRO_GFR_AL_H
#define GFR_FRAMEWORK_ALLEGRO_GFR_AL_H
#include "Common.h"
#include "allegro5\allegro.h"
#include "StateManager.h"

namespace framework
{
	/*	Bridges the gap between framework and GFR.
	
		Creates and initializes Allegro systems, manages events,
		I/O, timers, threads, displays. Acts as a layer of abstraction
		between GFR framework and the Allegro library.

		Creates and initializes all non-Allegro-specific systems,
		such as the states, GUI, 
	*/
	class GFR_AL
	{
	public:
		static bool					InitSystems				();
		static void					DestroySystems			();
		static void					InitGame				(game::stateTypes::Type initStateType);

		static void					RunGameLoop				();
		static void					EndGame					();
		static bool					IsRunning				();
		static void					ResizeWindow			(const u32 &width, const u32 &height);
		static u32					GetScreenWidth			();
		static u32					GetScreenHeight			();
		static f32					GetUpdateRate			();
		static f32					GetDrawRate				();


		static void					PrintConsole			(const char* str);

		// ContentMgr
		static void					SetDefaultDirectory		();
		static const std::string	GetContentDirectory		(const char* subFolder);
		static ALLEGRO_BITMAP*		CreateBitmap			(const char* pathFile);
		static void					DestroyBitmap			(ALLEGRO_BITMAP* bitmap);
		static ALLEGRO_SAMPLE*		CreateSample			(const char* pathFile);
		static void					DestroySample			(ALLEGRO_SAMPLE* sample);
		
		// InputMgr
		static bool					InitializeInputDevices	(ALLEGRO_EVENT_QUEUE* queue);
		static std::string			KeyCodeToString			(int keyCode);

		static void					DrawTexture				(ALLEGRO_BITMAP*, f32 dx, f32 dy, u32 flags = 0);
		
		static game::gameState::StateManager s_StateManager;

	private:
		static ALLEGRO_EVENT_QUEUE*	s_EventQueue;
		static ALLEGRO_DISPLAY*		s_Display;
		static ALLEGRO_BITMAP*		s_Buffer;
		static ALLEGRO_TIMER*		s_UpdateTimer;
		static ALLEGRO_TIMER*		s_DrawTimer;
		static f32					s_UpdateRate;
		static f32					s_DrawRate;
		static u32					s_WindowWidth, s_WindowHeight;
		static f32					s_ScaleX, s_ScaleY, s_ScaleW, s_ScaleH;

		static void					CalculateStretchScale	();
		static void					CalculateScale			();
		static void					InitializeGUI			();

		static bool					s_IsRunning;

	};
};
#endif
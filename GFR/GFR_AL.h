#ifndef GFR_FRAMEWORK_ALLEGRO_GFR_AL_H
#define GFR_FRAMEWORK_ALLEGRO_GFR_AL_H
#include "Common.h"
#include "allegro5\allegro.h"
#include "StateManager.h"
#include "Vec2.h"
#include "Texture.h"

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

		static void					DrawTexture				(const Texture& texture, Vec2f position, u32 flags = 0);
		static void					DrawTextureRegion		(const Texture& texture, Vec2f position, u32 regionX, u32 regionY, u32 regionWidth, u32 regionHeight, u32 flags = 0);
		
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
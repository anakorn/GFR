#ifndef GFR_AL_H
#define GFR_AL_H
#include "Common.h"
#include "allegro5\allegro.h"

#include "Agui/Agui.hpp"
#include "Agui/Backends/Allegro5/Allegro5.hpp"

namespace framework
{
	/*	Creates and initializes Allegro systems, manages events,
		I/O, timers, threads, displays.
	*/
	class GFR_AL
	{
	public:
		static bool					Create					(void);
		static void					Destroy					(void);

		static void					RunGameLoop				(void);
		static void					EndGame					(void);

		static void					PrintConsole			(const char* str);

		static ALLEGRO_EVENT_QUEUE*	s_EventQueue;
		static ALLEGRO_DISPLAY*		s_Display;
		static ALLEGRO_BITMAP*		s_Buffer;
		static ALLEGRO_TIMER*		s_UpdateTimer;
		static ALLEGRO_TIMER*		s_DrawTimer;
		static f32					s_UpdateRate;
		static f32					s_DrawRate;
		static agui::Font*			s_DefaultFont;
			 
	private:
		static void					InitializeGUI			(void);
		static void					CalculateStretchScale	(void);
		static void					CalculateScale			(void);

	};
};
#endif
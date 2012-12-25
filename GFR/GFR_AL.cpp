#include "GFR_AL.h"
#include <stdio.h>

using namespace framework;

ALLEGRO_EVENT_QUEUE*	GFR_AL::s_EventQueue;
ALLEGRO_DISPLAY*		GFR_AL::s_Display;
ALLEGRO_TIMER*			GFR_AL::s_UpdateTimer;
ALLEGRO_TIMER*			GFR_AL::s_DrawTimer;
f32						GFR_AL::s_UpdateRate;
f32						GFR_AL::s_DrawRate;

bool GFR_AL::Create(void)
{
	s_Display = NULL;
	s_UpdateTimer = NULL;
	s_DrawTimer = NULL;
	s_EventQueue = NULL;

	/* Systems Initialization */
	if (!al_init()) {
		PrintConsole("GFR_AL::Create() call al_init() failed.\n");
		return false;
	}
	
	if (!al_install_keyboard()) {
		PrintConsole("GFR_AL::Create() call al_install_keyboard() failed.\n");
		return false;
	}

	s_EventQueue = al_create_event_queue();
	if (!s_EventQueue) {
		PrintConsole("GFR_AL::Create() call al_create_event_queue() failed.\n");
		return false;
	}

	s_Display = al_create_display(640, 480);
	if (!s_Display) {
		PrintConsole("GFR_AL::Create() call al_create_display() failed.\n");
		return false;
	}

	// Retrieve max FPS from display refresh rate
	s_DrawRate = (f32) al_get_display_refresh_rate(s_Display);
	s_DrawRate = (s_DrawRate == 0.0f) ? 60.0f : s_DrawRate;

	// Game will be updated @ half of refresh rate
	s_UpdateTimer = al_create_timer(2.0f / s_DrawRate);
	// Game will be drawn @ display refresh rate
	s_DrawTimer = al_create_timer(1.0f / s_DrawRate);
	if (!s_UpdateTimer || !s_DrawTimer) {
		PrintConsole("GFR_AL::Create() call al_create_timer() failed.\n");
		return false;
	}
	
	al_register_event_source(s_EventQueue, al_get_keyboard_event_source());
	al_register_event_source(s_EventQueue, al_get_display_event_source(s_Display));
	al_register_event_source(s_EventQueue, al_get_timer_event_source(s_UpdateTimer));
	al_register_event_source(s_EventQueue, al_get_timer_event_source(s_DrawTimer));

	al_start_timer(s_UpdateTimer);
	al_start_timer(s_DrawTimer);

	al_set_window_title(s_Display, "Godfighter");

	/* Begin game loop */
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();

	return true;
}

void GFR_AL::Destroy(void)
{
	if (s_Display != NULL)
		al_destroy_display(s_Display);
	if (s_EventQueue != NULL)
		al_destroy_event_queue(s_EventQueue);
	if (s_UpdateTimer != NULL)
		al_destroy_timer(s_UpdateTimer);
	if (s_DrawTimer != NULL)
		al_destroy_timer(s_DrawTimer);
}

void GFR_AL::PrintConsole(const char* str)
{
	fprintf(stderr, str);
}
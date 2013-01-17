#include "GFR_AL.h"
#include "GameStateManager.h"
#include "Configuration.h"
#include "InputMgr.h"
#include <stdio.h>
#include <allegro5/allegro_image.h>
#include <allegro5//allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

using namespace framework;

ALLEGRO_EVENT_QUEUE*	GFR_AL::s_EventQueue;
ALLEGRO_DISPLAY*		GFR_AL::s_Display;
ALLEGRO_TIMER*			GFR_AL::s_UpdateTimer;
ALLEGRO_TIMER*			GFR_AL::s_DrawTimer;
f32						GFR_AL::s_UpdateRate;
f32						GFR_AL::s_DrawRate;

// Target resolution is what the game will be built around
// Will scale to other resolutions and letterbox if other aspect ratio is used
const u32				TARGET_SCREEN_WIDTH = 1920;
const u32				TARGET_SCREEN_HEIGHT = 1080;
u32						m_WindowWidth, m_WindowHeight;
f32						m_ScaleX, m_ScaleY, m_ScaleW, m_ScaleH;

static gamestate::GameStateManager s_StateManager;
static bool				s_IsRunning;

bool GFR_AL::Create(void)
{
	atexit(EndGame);

	s_Display = NULL;
	s_UpdateTimer = NULL;
	s_DrawTimer = NULL;
	s_EventQueue = NULL;

	/* Systems Initialization */
	if (!al_init()) {
		PrintConsole("GFR_AL::Create() call al_init() failed.\n");
		return false;
	}

	s_EventQueue = al_create_event_queue();
	if (!s_EventQueue) {
		PrintConsole("GFR_AL::Create() call al_create_event_queue() failed.\n");
		return false;
	}

	if (!InputMgr::Initialize(s_EventQueue)) {
		PrintConsole("InputMgr::Initialize() failed.\n");
		return false;
	}

	// Recreate config file if it doesn't exist or is corrupted
	if (!Configuration::LoadConfigFile("settings.cfg"))
		Configuration::ResetConfigFile("settings.cfg");

	if (Configuration::GetBoolValue("SCREEN", "fullscreen"))
		al_set_new_display_flags(ALLEGRO_FULLSCREEN);

	m_WindowWidth = Configuration::GetIntValue("SCREEN", "width");
	m_WindowHeight = Configuration::GetIntValue("SCREEN", "height");

	CalculateStretchScale();
	s_Display = al_create_display(m_WindowWidth, m_WindowHeight);
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

	InitializeGUI();

	s_StateManager = gamestate::GameStateManager();
	
	al_register_event_source(s_EventQueue, al_get_display_event_source(s_Display));
	al_register_event_source(s_EventQueue, al_get_timer_event_source(s_UpdateTimer));
	al_register_event_source(s_EventQueue, al_get_timer_event_source(s_DrawTimer));

	al_start_timer(s_UpdateTimer);
	al_start_timer(s_DrawTimer);

	al_set_window_title(s_Display, "Godfighter");

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

void GFR_AL::InitializeGUI(void)
{
	al_init_image_addon();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	agui::Image::setImageLoader(new agui::Allegro5ImageLoader());
	agui::Font::setFontLoader(new agui::Allegro5FontLoader());
	agui::Color::setPremultiplyAlpha(true);


	agui::Font* s_DefaultFont = agui::Font::load("assets/Fonts/PTSans.ttf", 16);
	//Setting a global font is required and failure to do so will crash.
	agui::Widget::setGlobalFont(s_DefaultFont);
}

void GFR_AL::CalculateStretchScale()
{
	f32 sx = (f32)m_WindowWidth / (f32)TARGET_SCREEN_WIDTH;
	f32 sy = (f32)m_WindowHeight / (f32)TARGET_SCREEN_HEIGHT;

	ALLEGRO_TRANSFORM trans;
	al_identity_transform(&trans);
	al_scale_transform(&trans, sx, sy);
	al_use_transform(&trans);
}

void GFR_AL::CalculateScale()
{
	f32 sx = (f32)(m_WindowWidth) / (f32)(TARGET_SCREEN_WIDTH);
	f32 sy = (f32)(m_WindowHeight) / (f32)(TARGET_SCREEN_HEIGHT);
	f32 scale = sx < sy ? sx : sy;

	m_ScaleW = TARGET_SCREEN_WIDTH * scale;
	m_ScaleH = TARGET_SCREEN_HEIGHT * scale;
	m_ScaleX = (m_WindowWidth - m_ScaleW) / 2.0f;
	m_ScaleY = (m_WindowHeight - m_ScaleH) / 2.0f;
}

void GFR_AL::ResizeWindow(const u32 &width, const u32 &height)
{
	m_WindowWidth = width;
	m_WindowHeight = height;
}

u32 GFR_AL::GetScreenWidth()
{
	return m_WindowWidth;
}

u32 GFR_AL::GetScreenHeight()
{
	return m_WindowHeight;
}

void GFR_AL::SetGameState(StateTypes::State type, std::vector<void*> args)
{
	s_StateManager.SetGameState(type, args);
}

void GFR_AL::PushGameState(StateTypes::State type, std::vector<void*> args)
{
	s_StateManager.PushGameState(type, args);
}

void GFR_AL::PopGameState()
{
	s_StateManager.PopGameState();
}

void GFR_AL::RemoveGameState(StateTypes::State type)
{
	s_StateManager.RemoveGameState(type);
}

void GFR_AL::RunGameLoop(void)
{
	PushGameState(StateTypes::MAIN_MENU);

	s_IsRunning = true;
	bool redraw = true;

	while(s_IsRunning)
	{
		// Wait for next frame update or recalculate
		// screen dimensions when a display event occurs
		ALLEGRO_EVENT event;
		al_wait_for_event(s_EventQueue, &event);

		s_StateManager.ProcessEvent(event);

		switch(event.type)
		{
		case ALLEGRO_EVENT_TIMER:
			if (event.timer.source == s_UpdateTimer)
			{
				s_StateManager.Update();
			}
			else if(event.timer.source == s_DrawTimer)
				redraw = true;
			break;
		case ALLEGRO_EVENT_DISPLAY_RESIZE: 
		case ALLEGRO_EVENT_DISPLAY_FOUND: 
		case ALLEGRO_EVENT_DISPLAY_SWITCH_IN:
			CalculateScale();
			break;
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			return;
		default:
			break;
		}

		if (redraw && al_is_event_queue_empty(s_EventQueue))
		{
			redraw = false; 

			// Normal drawing. Temporary
			al_clear_to_color(al_map_rgb(240,240,240));
			s_StateManager.Render();
			al_flip_display();

			// Can't get scaled drawing to work yet. Force resolution for now
			/*al_set_target_bitmap(s_Buffer);
			al_clear_to_color(al_map_rgb(240, 240, 240));

			stateManager.Render();

			al_set_target_backbuffer(s_Display);
			al_clear_to_color(al_map_rgb(240, 240, 240));
			al_draw_scaled_bitmap(s_Buffer, 0, 0, TARGET_SCREEN_WIDTH, TARGET_SCREEN_HEIGHT, scaleX, scaleY, scaleW, scaleH, 0);
			al_flip_display();*/
		}
	}
}

void GFR_AL::EndGame()
{
	s_IsRunning = false;
}

bool GFR_AL::IsRunning()
{
	return s_IsRunning;
}
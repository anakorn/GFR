#include "GFR_AL.h"
#include "Configuration.h"
#include "InputMgr.h"
#include "ContentMgr.h"
#include <stdio.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "MouseButtons.h"

using namespace framework;

ALLEGRO_EVENT_QUEUE*	GFR_AL::s_EventQueue;
ALLEGRO_DISPLAY*		GFR_AL::s_Display;
ALLEGRO_TIMER*			GFR_AL::s_UpdateTimer;
ALLEGRO_TIMER*			GFR_AL::s_DrawTimer;
f32						GFR_AL::s_UpdateRate;
f32						GFR_AL::s_DrawRate;
bool					GFR_AL::s_IsRunning;
u32						GFR_AL::s_WindowWidth, GFR_AL::s_WindowHeight;
f32						GFR_AL::s_ScaleX, GFR_AL::s_ScaleY, GFR_AL::s_ScaleW, GFR_AL::s_ScaleH;
game::gameState::StateManager GFR_AL::s_StateManager;

// Target resolution is what the game will be built around
// Will scale to other resolutions and letterbox if other aspect ratio is used
const u32				TARGET_SCREEN_WIDTH = 1920;
const u32				TARGET_SCREEN_HEIGHT = 1080;

bool GFR_AL::InitSystems()
{
	atexit(EndGame);

	s_Display = NULL;
	s_UpdateTimer = NULL;
	s_DrawTimer = NULL;
	s_EventQueue = NULL;

	/* BEGIN SYSTEMS INIT */
	if (!al_init()) {
		PrintConsole("GFR_AL::Create() call al_init() failed.\n");
		return false;
	}

	if (!al_init_image_addon()) {
		PrintConsole("GFR_AL::Create() call al_init_image_addon() failed.\n");
		return false;
	}

	if (!al_init_primitives_addon()) {
		PrintConsole("GFR_AL::Create() call al_init_primitives_addon() failed.\n");
		return false;
	}
	
	al_init_font_addon();
	if (!al_init_ttf_addon()) {
		PrintConsole("GFR_AL::Create() call al_init_ttf_addon() failed.\n");
		return false;
	}

	if (!al_install_audio()) {
		PrintConsole("GFR_AL::Create() called al_install_audio() failed.\n");
		return false;
	}

	if (!al_init_acodec_addon()) {
		PrintConsole("GFR_AL::Create() called al_init_acodec_addon() failed.\n");
	}

	if (!al_reserve_samples(1)) {
		PrintConsole("GFR_AL::Create() called al_reserve_samples(1) failed.\n");
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
	/* END SYSTEMS INIT */

	// Recreate config file if it doesn't exist or is corrupted
	if (!Configuration::LoadConfigFile("settings.cfg"))
		Configuration::ResetConfigFile("settings.cfg");

	if (Configuration::GetBoolValue("SCREEN", "fullscreen"))
		al_set_new_display_flags(ALLEGRO_FULLSCREEN);

	s_WindowWidth = Configuration::GetIntValue("SCREEN", "width");
	s_WindowHeight = Configuration::GetIntValue("SCREEN", "height");

	CalculateStretchScale();
	s_Display = al_create_display(s_WindowWidth, s_WindowHeight);
	if (!s_Display) {
		PrintConsole("GFR_AL::Create() call al_create_display() failed.\n");
		return false;
	}

	// Initialize all content (must 
	// come after display initialization)
	ContentMgr::Initialize();
	if (!ContentMgr::LoadAllContent())
	{
		PrintConsole("ContentMgr::LoadAllContent() failed!");
		return false;
	}

	// Retrieve max FPS from display refresh rate
	s_DrawRate = (f32) al_get_display_refresh_rate(s_Display);
	s_DrawRate = (s_DrawRate == 0.0f) ? 60.0f : s_DrawRate;
	s_DrawRate = 1.0f / s_DrawRate;

	// Update rate is double the draw rate
	s_UpdateRate = 2.0f * s_DrawRate;

	// Game will be updated @ half of refresh rate
	s_UpdateTimer = al_create_timer(s_UpdateRate);
	// Game will be drawn @ display refresh rate
	s_DrawTimer = al_create_timer(s_DrawRate);

	if (!s_UpdateTimer || !s_DrawTimer) {
		PrintConsole("GFR_AL::Create() call al_create_timer() failed.\n");
		return false;
	}
	
	al_register_event_source(s_EventQueue, al_get_display_event_source(s_Display));
	al_register_event_source(s_EventQueue, al_get_timer_event_source(s_UpdateTimer));
	al_register_event_source(s_EventQueue, al_get_timer_event_source(s_DrawTimer));

	al_start_timer(s_UpdateTimer);
	al_start_timer(s_DrawTimer);

	al_set_window_title(s_Display, "GodFighter");

	return true;
};

void GFR_AL::DestroySystems()
{
	if (s_Display != NULL)
		al_destroy_display(s_Display);
	if (s_EventQueue != NULL)
		al_destroy_event_queue(s_EventQueue);
	if (s_UpdateTimer != NULL)
		al_destroy_timer(s_UpdateTimer);
	if (s_DrawTimer != NULL)
		al_destroy_timer(s_DrawTimer);
};

void GFR_AL::InitGame(game::stateTypes::Type initStateType)
{
	InitializeGUI();
	s_StateManager.SetState(initStateType);
};

void GFR_AL::RunGameLoop()
{
	s_IsRunning = true;
	bool redraw = true;

	while (s_IsRunning)
	{
		// Wait for next frame update or recalculate
		// screen dimensions when a display event occurs
		ALLEGRO_EVENT event;
		al_wait_for_event(s_EventQueue, &event);

		s_StateManager.ProcessEvent(event);

		switch (event.type)
		{
		case ALLEGRO_EVENT_TIMER:
			if (event.timer.source == s_UpdateTimer)
			{
				s_StateManager.Update();
			}
			else if(event.timer.source == s_DrawTimer)
				redraw = true;
			break;
		case ALLEGRO_EVENT_MOUSE_AXES:
			InputMgr::MoveMouse(event.mouse);
			break;
		case ALLEGRO_EVENT_KEY_DOWN:
			InputMgr::PressKey(event.keyboard);
			break;
		case ALLEGRO_EVENT_KEY_UP:
			InputMgr::ReleaseKey(event.keyboard);
			break;
		case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
			InputMgr::MouseDown(event.mouse);
			break;
		case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
			InputMgr::MouseUp(event.mouse);
			break;
		case ALLEGRO_EVENT_DISPLAY_RESIZE: 
		case ALLEGRO_EVENT_DISPLAY_FOUND: 
		case ALLEGRO_EVENT_DISPLAY_SWITCH_IN:
			CalculateScale();
			break;
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			s_IsRunning = false;
			break;
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
};

void GFR_AL::EndGame()
{
	s_IsRunning = false;
};

bool GFR_AL::IsRunning()
{
	return s_IsRunning;
};

void GFR_AL::ResizeWindow(const u32 &width, const u32 &height)
{
	s_WindowWidth = width;
	s_WindowHeight = height;
};

u32 GFR_AL::GetScreenWidth()
{
	return s_WindowWidth;
};

u32 GFR_AL::GetScreenHeight()
{
	return s_WindowHeight;
};

f32 GFR_AL::GetUpdateRate()
{
	return s_UpdateRate;
};

f32 GFR_AL::GetDrawRate()
{
	return s_DrawRate;
};

void GFR_AL::PrintConsole(const char* str)
{
	fprintf(stderr, str);
};

void GFR_AL::CalculateStretchScale()
{
	f32 sx = (f32)s_WindowWidth / (f32)TARGET_SCREEN_WIDTH;
	f32 sy = (f32)s_WindowHeight / (f32)TARGET_SCREEN_HEIGHT;

	ALLEGRO_TRANSFORM trans;
	al_identity_transform(&trans);
	al_scale_transform(&trans, sx, sy);
	al_use_transform(&trans);
};

void GFR_AL::CalculateScale()
{
	f32 sx = (f32)(s_WindowWidth) / (f32)(TARGET_SCREEN_WIDTH);
	f32 sy = (f32)(s_WindowHeight) / (f32)(TARGET_SCREEN_HEIGHT);
	f32 scale = sx < sy ? sx : sy;

	s_ScaleW = TARGET_SCREEN_WIDTH * scale;
	s_ScaleH = TARGET_SCREEN_HEIGHT * scale;
	s_ScaleX = (s_WindowWidth - s_ScaleW) / 2.0f;
	s_ScaleY = (s_WindowHeight - s_ScaleH) / 2.0f;
};

void GFR_AL::InitializeGUI(void)
{
 	agui::Image::setImageLoader(new agui::Allegro5ImageLoader());
	agui::Font::setFontLoader(new agui::Allegro5FontLoader());
	agui::Color::setPremultiplyAlpha(true);

	agui::Font* m_DefaultFont = agui::Font::load("Fonts/PTSans.ttf", 16);
	//Setting a global font is required and failure to do so will crash.
	agui::Widget::setGlobalFont(m_DefaultFont);
};

void GFR_AL::DrawTexture(ALLEGRO_BITMAP* bitmap, Vec2f position, u32 flags)
{
	al_draw_bitmap(bitmap, position.x(), position.y(), flags);
};
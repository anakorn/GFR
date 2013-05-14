#include "GFRAL_Input.h"

using namespace framework;

bool GFRAL_Input::InitializeInputDevices(ALLEGRO_EVENT_QUEUE* queue)
{
	bool keyboardInstalled = al_install_keyboard();
	bool mouseInstalled = al_install_mouse();

	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());

	return keyboardInstalled && mouseInstalled;
};

std::string GFRAL_Input::KeyCodeToString(int keyCode)
{
	return al_keycode_to_name(keyCode);
};
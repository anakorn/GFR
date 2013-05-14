#include "InputMgr.h"
#include "Common.h"
#include "allegro5\allegro.h"
#include "GFRAL_Input.h"

using namespace framework;

InputMgr::KeyFunctionMap* InputMgr::keyDownFunctions = new KeyFunctionMap();
InputMgr::KeyFunctionMap* InputMgr::keyUpFunctions = new KeyFunctionMap();

InputMgr::MouseFunctionMap* InputMgr::mouseDownFunctions = new MouseFunctionMap();
InputMgr::MouseFunctionMap* InputMgr::mouseUpFunctions = new MouseFunctionMap();

std::vector<std::function<void(ALLEGRO_MOUSE_EVENT)>>* InputMgr::moveMouseFunctions = new std::vector<std::function<void(ALLEGRO_MOUSE_EVENT)>>();

bool InputMgr::Initialize(ALLEGRO_EVENT_QUEUE* queue)
{
	return GFRAL_Input::InitializeInputDevices(queue);
};

// Create a map of keys that each contain a vector of function pointers.
void InputMgr::RegisterKeyDownFunction(int key, std::function<void(ALLEGRO_KEYBOARD_EVENT)> function)
{
	RegisterKeyFunction(key, function, keyDownFunctions);
};

void InputMgr::RegisterKeyUpFunction(int key, std::function<void(ALLEGRO_KEYBOARD_EVENT)> function)
{
	RegisterKeyFunction(key, function, keyUpFunctions);
};

void InputMgr::RegisterMouseMoveFunction(std::function<void(ALLEGRO_MOUSE_EVENT)> function)
{
	moveMouseFunctions->push_back(function);
};

void InputMgr::RegisterMouseDownFunction(unsigned int key, std::function<void(ALLEGRO_MOUSE_EVENT)> function)
{
	RegisterMouseFunction(key, function, mouseDownFunctions);
};

void InputMgr::RegisterMouseUpFunction(unsigned int key, std::function<void(ALLEGRO_MOUSE_EVENT)> function)
{
	RegisterMouseFunction(key, function, mouseUpFunctions);
};

void InputMgr::PressKey(ALLEGRO_KEYBOARD_EVENT event)
{
	if (keyDownFunctions->find(event.keycode) != keyDownFunctions->end())
	{
		std::vector<std::function<void(ALLEGRO_KEYBOARD_EVENT)>> functionsToCall = keyDownFunctions->at(event.keycode);

		for (unsigned int i = 0; i < functionsToCall.size(); i++)
		{
			functionsToCall.at(i)(event);
		}
	}
};

void InputMgr::ReleaseKey(ALLEGRO_KEYBOARD_EVENT event)
{
	if (keyUpFunctions->find(event.keycode) != keyUpFunctions->end())
	{
		std::vector<std::function<void(ALLEGRO_KEYBOARD_EVENT)>> functionsToCall = keyUpFunctions->at(event.keycode);

		for (unsigned int i = 0; i < functionsToCall.size(); i++)
		{
			functionsToCall.at(i)(event);
		}
	}
};

void InputMgr::MoveMouse(ALLEGRO_MOUSE_EVENT event)
{
	for (unsigned int i = 0; i < moveMouseFunctions->size(); i++)
	{
		moveMouseFunctions->at(i)(event);
	}
};

void InputMgr::MouseDown(ALLEGRO_MOUSE_EVENT event)
{
	if (mouseDownFunctions->find(event.button) != mouseDownFunctions->end())
	{
		std::vector<std::function<void(ALLEGRO_MOUSE_EVENT)>> functionsToCall = mouseDownFunctions->at(event.button);

		for (unsigned int i = 0; i < functionsToCall.size(); i++)
		{
			functionsToCall.at(i)(event);
		}
	}
};

void InputMgr::MouseUp(ALLEGRO_MOUSE_EVENT event)
{
	if (mouseUpFunctions->find(event.button) != mouseUpFunctions->end())
	{
		std::vector<std::function<void(ALLEGRO_MOUSE_EVENT)>> functionsToCall = mouseUpFunctions->at(event.button);

		for (unsigned int i = 0; i < functionsToCall.size(); i++)
		{
			functionsToCall.at(i)(event);
		}
	}
};

void InputMgr::RegisterKeyFunction(int key, std::function<void(ALLEGRO_KEYBOARD_EVENT)> function, KeyFunctionMap* map)
{
	// If the input functions key-binding doesn't exists in the map...
	if (map->find(key) == map->end())
	{
		// Create a new vector for input functions.
		std::vector<std::function<void(ALLEGRO_KEYBOARD_EVENT)>> boundFunctions = std::vector<std::function<void(ALLEGRO_KEYBOARD_EVENT)>>();
		boundFunctions.push_back(function);

		map->insert(std::pair<int, std::vector<std::function<void(ALLEGRO_KEYBOARD_EVENT)>>>(key, boundFunctions));
	}
	else
	{
		map->at(key).push_back(function);
	}
};

void InputMgr::RegisterMouseFunction(unsigned int key, std::function<void(ALLEGRO_MOUSE_EVENT)> function, MouseFunctionMap* map)
{
	// If the input functions key-binding doesn't exists in the map...
	if (map->find(key) == map->end())
	{
		// Create a new vector for input functions.
		std::vector<std::function<void(ALLEGRO_MOUSE_EVENT)>> boundFunctions = std::vector<std::function<void(ALLEGRO_MOUSE_EVENT)>>();
		boundFunctions.push_back(function);

		map->insert(std::pair<unsigned int, std::vector<std::function<void(ALLEGRO_MOUSE_EVENT)>>>(key, boundFunctions));
	}
	else
	{
		map->at(key).push_back(function);
	}
};
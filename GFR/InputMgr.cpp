#include "InputMgr.h"
#include "Common.h"
#include "allegro5\allegro.h"
#include "GFR_AL.h"

using namespace framework;

InputMgr::KeyFunctionMap* InputMgr::keyDownFunctions = new KeyFunctionMap();
InputMgr::KeyFunctionMap* InputMgr::keyUpFunctions = new KeyFunctionMap();

InputMgr::MouseFunctionMap* InputMgr::mouseDownFunctions = new MouseFunctionMap();
InputMgr::MouseFunctionMap* InputMgr::mouseUpFunctions = new MouseFunctionMap();

std::vector<std::function<void(int, int)>>* InputMgr::moveMouseFunctions = new std::vector<std::function<void(int, int)>>();

bool InputMgr::Initialize(ALLEGRO_EVENT_QUEUE* queue)
{
	return GFR_AL::InitializeInputDevices(queue);
};

// Create a map of keys that each contain a vector of function pointers.
void InputMgr::AddKeyFunction(std::string key, std::function<void()> function, KeyFunctionMap* map)
{
	// If the input functions key-binding doesn't exists in the map...
	if (map->find(key) == map->end())
	{
		// Create a new vector for input functions.
		std::vector<std::function<void()>> boundFunctions = std::vector<std::function<void()>>();
		boundFunctions.push_back(function);

		map->insert(std::pair<std::string, std::vector<std::function<void()>>>(key, boundFunctions));
	}
	else
	{
		map->at(key).push_back(function);
	}
};

void InputMgr::AddMouseMoveFunction(std::function<void(int, int)> function)
{
	moveMouseFunctions->push_back(function);
};

void InputMgr::AddMouseClickFunction(unsigned int key, std::function<void(int, int, int)> function, MouseFunctionMap* map)
{
	// If the input functions key-binding doesn't exists in the map...
	if (map->find(key) == map->end())
	{
		// Create a new vector for input functions.
		std::vector<std::function<void(int, int, int)>> boundFunctions = std::vector<std::function<void(int, int, int)>>();
		boundFunctions.push_back(function);

		map->insert(std::pair<unsigned int, std::vector<std::function<void(int, int, int)>>>(key, boundFunctions));
	}
	else
	{
		map->at(key).push_back(function);
	}
};

void InputMgr::PressKey(int keyCode)
{
	std::string key = GFR_AL::KeyCodeToString(keyCode);

	if (keyDownFunctions->find(key) != keyDownFunctions->end())
	{
		std::vector<std::function<void()>> functionsToCall = keyDownFunctions->at(key);

		for (unsigned int i = 0; i < functionsToCall.size(); i++)
		{
			functionsToCall.at(i)();
		}
	}
};

void InputMgr::ReleaseKey(int keyCode)
{
	std::string key = GFR_AL::KeyCodeToString(keyCode);

	if (keyUpFunctions->find(key) != keyUpFunctions->end())
	{
		std::vector<std::function<void()>> functionsToCall = keyUpFunctions->at(key);

		for (unsigned int i = 0; i < functionsToCall.size(); i++)
		{
			functionsToCall.at(i)();
		}
	}
};

void InputMgr::MoveMouse(int mouseX, int mouseY)
{
	for (unsigned int i = 0; i < moveMouseFunctions->size(); i++)
	{
		moveMouseFunctions->at(i)(mouseX, mouseY);
	}
};

void InputMgr::MouseDown(unsigned int button, int mouseX, int mouseY, int mouseZ)
{
	if (mouseDownFunctions->find(button) != mouseDownFunctions->end())
	{
		std::vector<std::function<void(int, int, int)>> functionsToCall = mouseDownFunctions->at(button);

		for (unsigned int i = 0; i < functionsToCall.size(); i++)
		{
			functionsToCall.at(i)(mouseX, mouseY, mouseZ);
		}
	}
};

void InputMgr::MouseUp(unsigned int button, int mouseX, int mouseY, int mouseZ)
{
	if (mouseUpFunctions->find(button) != mouseUpFunctions->end())
	{
		std::vector<std::function<void(int, int, int)>> functionsToCall = mouseUpFunctions->at(button);

		for (unsigned int i = 0; i < functionsToCall.size(); i++)
		{
			functionsToCall.at(i)(mouseX, mouseY, mouseZ);
		}
	}
};
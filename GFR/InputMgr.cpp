#include "InputMgr.h"
#include "Common.h"
#include "allegro5\allegro.h"
#include "GFR_AL.h"

using namespace framework;

InputMgr::FunctionMap* InputMgr::keyDownFunctions = new FunctionMap();
InputMgr::FunctionMap* InputMgr::keyUpFunctions = new FunctionMap();

bool InputMgr::Initialize(ALLEGRO_EVENT_QUEUE* queue)
{
	return GFR_AL::InitializeInputDevices(queue);
};

// Create a map of keys that each contain a vector of function pointers.
void InputMgr::AddFunction(std::string key, std::function<void()> function, FunctionMap* map)
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
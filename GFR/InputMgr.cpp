#include "InputMgr.h"
#include "Common.h"
#include "allegro5\allegro.h"
#include "GFR_AL.h"

using namespace framework;

InputMgr::FunctionMap* InputMgr::inputFunctions = new FunctionMap();

bool InputMgr::Initialize(ALLEGRO_EVENT_QUEUE* queue)
{
	return GFR_AL::InitializeInputDevices(queue);
};

// Create a map of keys that each contain a vector of function pointers.
void InputMgr::AddFunction(std::string key, std::function<void()> function)
{
	// If the input functions key-binding doesn't exists in the map...
	if (inputFunctions->find(key) == inputFunctions->end())
	{
		// Create a new vector for input functions.
		std::vector<std::function<void()>> boundFunctions = std::vector<std::function<void()>>();
		boundFunctions.push_back(function);

		inputFunctions->insert(std::pair<std::string, std::vector<std::function<void()>>>(key, boundFunctions));
	}
	else
	{
		inputFunctions->at(key).push_back(function);
	}
};

void InputMgr::PressKey(char keyCode)
{
	std::string key = GFR_AL::KeyCodeToString(keyCode);

	if (inputFunctions->find(key) != inputFunctions->end())
	{
		std::vector<std::function<void()>> functionsToCall = inputFunctions->at(key);

		for (unsigned int i = 0; i < functionsToCall.size(); i++)
		{
			functionsToCall.at(i)();
		}
	}
};
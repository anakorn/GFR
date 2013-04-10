#ifndef GFR_FRAMEWORK_MANAGERS_INPUTMGR_INPUTMGR_H
#define GFR_FRAMEWORK_MANAGERS_INPUTMGR_INPUTMGR_H

#include "Common.h"
#include "allegro5\allegro.h"
#include "boost/unordered_map.hpp"
#include <vector>
#include <functional>

namespace framework
{
	/*	Wrapper/manager class for Allegro input events. Also handles
		loading and setting of keybinds.
	*/
	class InputMgr
	{
	public:
		// AL installs moved to InputMgr so that we can write
		// a different InputMgr or initialize function for each control type
		// ex. one for mouse/keyboard, another for controller.
		typedef boost::unordered_map<std::string, std::vector<std::function<void()>>> FunctionMap;

		static bool		Initialize	(ALLEGRO_EVENT_QUEUE* queue);
		static void		AddFunction (std::string key, std::function<void()> function);
		static void		PressKey	(char keyCode);

	private:
		static FunctionMap* inputFunctions;

	};
};

#endif
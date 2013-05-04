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
		typedef boost::unordered_map<int, std::vector<std::function<void(ALLEGRO_KEYBOARD_EVENT)>>> KeyFunctionMap;
		typedef boost::unordered_map<int, std::vector<std::function<void(ALLEGRO_MOUSE_EVENT)>>> MouseFunctionMap;

		static bool		Initialize				(ALLEGRO_EVENT_QUEUE* queue);

		// Event Register Functions
		static void		RegisterKeyDownFunction		(int key, std::function<void(ALLEGRO_KEYBOARD_EVENT)> function);
		static void		RegisterKeyUpFunction		(int key, std::function<void(ALLEGRO_KEYBOARD_EVENT)> function);
		static void		RegisterMouseMoveFunction	(std::function<void(ALLEGRO_MOUSE_EVENT)> function);
		static void		RegisterMouseDownFunction	(unsigned int key, std::function<void(ALLEGRO_MOUSE_EVENT)> function);
		static void		RegisterMouseUpFunction		(unsigned int key, std::function<void(ALLEGRO_MOUSE_EVENT)> function);

		// Event Call Functions
		static void		PressKey				(ALLEGRO_KEYBOARD_EVENT event);
		static void		ReleaseKey				(ALLEGRO_KEYBOARD_EVENT event);			
		static void		MoveMouse				(ALLEGRO_MOUSE_EVENT event);
		static void		MouseDown				(ALLEGRO_MOUSE_EVENT event);
		static void		MouseUp					(ALLEGRO_MOUSE_EVENT event);

	private:
		static void		RegisterKeyFunction			(int key, std::function<void(ALLEGRO_KEYBOARD_EVENT)> function, KeyFunctionMap* map);
		static void		RegisterMouseFunction		(unsigned int key, std::function<void(ALLEGRO_MOUSE_EVENT)> function, MouseFunctionMap* map);

		// External Function Containers
		static KeyFunctionMap* keyDownFunctions;
		static KeyFunctionMap* keyUpFunctions;

		static MouseFunctionMap* mouseDownFunctions;
		static MouseFunctionMap* mouseUpFunctions;

		static std::vector<std::function<void(ALLEGRO_MOUSE_EVENT)>>* moveMouseFunctions;
	};
};

#endif
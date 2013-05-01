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
		typedef boost::unordered_map<std::string, std::vector<std::function<void()>>> KeyFunctionMap;
		typedef boost::unordered_map<unsigned int, std::vector<std::function<void(int, int, int)>>> MouseFunctionMap;

		static bool		Initialize				(ALLEGRO_EVENT_QUEUE* queue);

		// Event Register Functions
		static void		RegisterKeyDownFunction		(std::string key, std::function<void()> function);
		static void		RegisterKeyUpFunction		(std::string key, std::function<void()> function);
		static void		RegisterMouseMoveFunction	(std::function<void(int, int)> function);
		static void		RegisterMouseDownFunction	(unsigned int key, std::function<void(int, int, int)> function);
		static void		RegisterMouseUpFunction		(unsigned int key, std::function<void(int, int, int)> function);

		// Event Call Functions
		static void		PressKey				(int keyCode);
		static void		ReleaseKey				(int keyCode);			
		static void		MoveMouse				(int mouseX, int mouseY);
		static void		MouseDown				(unsigned int button, int mouseX, int mouseY, int mouseZ);
		static void		MouseUp					(unsigned int button, int mouseX, int mouseY, int mouseZ);

	private:
		static void		RegisterKeyFunction			(std::string key, std::function<void()> function, KeyFunctionMap* map);
		static void		RegisterMouseFunction		(unsigned int key, std::function<void(int, int, int)> function, MouseFunctionMap* map);

		// External Function Containers
		static KeyFunctionMap* keyDownFunctions;
		static KeyFunctionMap* keyUpFunctions;

		static MouseFunctionMap* mouseDownFunctions;
		static MouseFunctionMap* mouseUpFunctions;

		static std::vector<std::function<void(int, int)>>* moveMouseFunctions;
	};
};

#endif
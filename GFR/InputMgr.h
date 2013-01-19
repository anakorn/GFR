#ifndef GFR_FRAMEWORK_MANAGERS_INPUTMGR_INPUTMGR_H
#define GFR_FRAMEWORK_MANAGERS_INPUTMGR_INPUTMGR_H

#include "Common.h"
#include "allegro5\allegro.h"

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
		// ex. one for mouse/keyboard, another for controller
		static bool		Initialize	(ALLEGRO_EVENT_QUEUE* queue);
		static void		Update		(void);
		static bool		IsDown		(const u32 keyNum);
		static void		BindKey		(const u32 keyNum, const u32 keyBind);
		
		static const char* GetBoundKeyName	(const u32 keyNum);
		
		static bool		LoadBindings(/*file*/);

	private:


	};
};

#endif
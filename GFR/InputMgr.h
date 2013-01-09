#ifndef GFR_INPUT_MGR_H
#define GFR_INPUT_MGR_H
#include "Common.h"

namespace framework
{
	/*	Wrapper/manager class for Allegro input events. Also handles
		loading and setting of keybinds.
	*/
	class InputMgr
	{
	public:
		static void		Update		(void);
		static bool		IsDown		(const u32 keyNum);
		static void		BindKey		(const u32 keyNum, const u32 keyBind);
		
		static const char* GetBoundKeyName	(const u32 keyNum);
		
		static bool		LoadBindings(/*file*/);

	private:


	};
};

#endif
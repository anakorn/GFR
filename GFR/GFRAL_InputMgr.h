#ifndef GFR_FRAMEWORK_ALLEGRO_MANAGERS_GFRAL_INPUTMGR_H
#define GFR_FRAMEWORK_ALLEGRO_MANAGERS_GFRAL_INPUTMGR_H

#include "allegro5/allegro.h"
#include <string>

namespace framework
{
	class GFRAL_InputMgr
	{
	public:
		static bool					InitializeInputDevices	(ALLEGRO_EVENT_QUEUE* queue);
		static std::string			KeyCodeToString			(int keyCode);
	};
};


#endif
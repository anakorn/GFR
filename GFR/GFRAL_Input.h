#ifndef GFR_FRAMEWORK_ALLEGRO_MANAGERS_GFRAL_INPUT_H
#define GFR_FRAMEWORK_ALLEGRO_MANAGERS_GFRAL_INPUT_H

#include "allegro5/allegro.h"
#include <string>

namespace framework
{
	class GFRAL_Input
	{
	public:
		static bool					InitializeInputDevices	(ALLEGRO_EVENT_QUEUE* queue);
		static std::string			KeyCodeToString			(int keyCode);
	};
};


#endif
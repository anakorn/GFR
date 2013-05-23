#ifndef GFR_GAME_INPUT_CONTROLLER_H
#define GFR_GAME_INPUT_CONTROLLER_H

#include "ComponentBase.h"

namespace game
{
	namespace input
	{
		class Controller : public framework::Component
		{
		public:
			virtual const u64 GetMask() const { return MASK_CONTROLLER; }
		};

		COMPONENT_REGISTER(Controller, "Controller");
	};
};

#endif
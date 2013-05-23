#ifndef GFR_GAME_COMPONENT_CONTROLLERCOMPONENT_H
#define GFR_GAME_COMPONENT_CONTROLLERCOMPONENT_H

#include "ComponentBase.h"

namespace game
{
	namespace input
	{
		class ControllerComponent : public framework::Component
		{
		public:
			virtual const u64 GetMask() const { return MASK_CONTROLLER; }
		};

		COMPONENT_REGISTER(ControllerComponent, "ControllerComponent");
	};
};

#endif
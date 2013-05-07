#ifndef GFR_GAME_INPUT_RUNNERCONTROLLER_H
#define GFR_GAME_INPUT_RUNNERCONTROLLER_H

#include "ComponentBase.h"

namespace game
{
	namespace input
	{
		class RunnerController : public framework::Component
		{
		public:
			virtual const u64 GetMask() const { return MASK_RUNNERCONTROLLER; }
		};

		COMPONENT_REGISTER(RunnerController, "RunnerController");
	};
};

#endif
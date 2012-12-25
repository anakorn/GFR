#ifndef GFR_MOVEMENT_SYSTEM_H
#define GFR_MOVEMENT_SYSTEM_H
#include "SystemBase.h"

namespace framework
{
	class MovementSystem : public System
	{
	public:
		MovementSystem();
		virtual void ProcessEntity(Entity& entity);

		// TODO: ANIMATION state to be set here (anim. based on physics)
	};
};

#endif
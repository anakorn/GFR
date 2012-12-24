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
	};
};

#endif
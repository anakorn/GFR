#ifndef GFR_SYSTEM_DERIVED_H
#define GFR_SYSTEM_DERIVED_H
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
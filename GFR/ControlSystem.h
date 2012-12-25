#ifndef GFR_CONTROL_SYSTEM_H
#define GFR_CONTROL_SYSTEM_H
#include "SystemBase.h"

namespace framework
{
	class ControlSystem : public System
	{
	public:
		ControlSystem();
		virtual void ProcessEntity(Entity& entity);

		// TODO: PHYSICS set from INPUT here
	};
};

#endif
#ifndef GFR_FRAMEWORK_SYSTEM_DERIVATIONS_MOVEMENTSYSTEM_H
#define GFR_FRAMEWORK_SYSTEM_DERIVATIONS_MOVEMENTSYSTEM_H
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
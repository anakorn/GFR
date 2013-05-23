#ifndef GFR_FRAMEWORK_SYSTEM_DERIVATIONS_GODCONTROLSYSTEM_H
#define GFR_FRAMEWORK_SYSTEM_DERIVATIONS_GODCONTROLSYSTEM_H
#include "SystemBase.h"

namespace framework
{
	class GodControlSystem : public System
	{
	public:
		virtual void ProcessEntityImpl(Entity& entity);

	protected:
		
	};
};

#endif
#ifndef GFR_GAME_SYSTEM_CONTROL_GODCONTROLSYSTEM_H
#define GFR_GAME_SYSTEM_CONTROL_GODCONTROLSYSTEM_H
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
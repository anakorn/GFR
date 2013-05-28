#ifndef GFR_GAME_SYSTEM_MOVEMENTSYSTEM_H
#define GFR_GAME_SYSTEM_MOVEMENTSYSTEM_H
#include "SystemBase.h"

namespace framework
{
	class MovementSystem : public System
	{
	public:
		MovementSystem();
		
	private:
		virtual void ProcessEntityImpl(Entity& entity);

	};
};

#endif
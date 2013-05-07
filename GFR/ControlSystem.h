#ifndef GFR_FRAMEWORK_SYSTEM_DERIVATIONS_CONTROLSYSTEM_H
#define GFR_FRAMEWORK_SYSTEM_DERIVATIONS_CONTROLSYSTEM_H
#include "SystemBase.h"

namespace framework
{
	class ControlSystem : public System
	{
	public:
		ControlSystem();
		virtual void ProcessEntity(Entity& entity);

	private:
		void MoveLeft();
		void MoveRight();
		void Jump();

		void CastAbility(u32 index);
	};
};

#endif
#ifndef GFR_GAME_SYSTEM_CONTROL_RUNNERCONTROLSYSTEM_H
#define GFR_GAME_SYSTEM_CONTROL_RUNNERCONTROLSYSTEM_H
#include "SystemBase.h"

namespace framework
{
	class RunnerControlSystem : public System
	{
	public:
		RunnerControlSystem();
		~RunnerControlSystem();
		virtual void ProcessEntityImpl(Entity& entity);

	protected:
		void ChangeHorizontalDirection(const f32 &amount);
		void ChangeVerticalDirection(const f32 &amount);

		void CastAbility(u32 index);

	};
};

#endif
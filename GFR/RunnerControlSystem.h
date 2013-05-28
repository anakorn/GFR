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

	protected:
		void ChangeHorizontalDirection(const f32 &amount);
		void ChangeVerticalDirection(const f32 &amount);

		void CastAbility(u32 index);
		
	private:
		virtual void ProcessEntityImpl(Entity& entity);

	};
};

#endif
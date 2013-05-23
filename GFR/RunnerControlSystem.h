#ifndef GFR_FRAMEWORK_SYSTEM_DERIVATIONS_RUNNERCONTROLSYSTEM_H
#define GFR_FRAMEWORK_SYSTEM_DERIVATIONS_RUNNERCONTROLSYSTEM_H
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
#ifndef GFR_SUBSYSTEM_DERIVED_H
#define GFR_SUBSYSTEM_DERIVED_H
#include "SubsystemBase.h"

namespace framework
{
	class MovementSubsystem : public Subsystem
	{
	public:
		MovementSubsystem();
		
		virtual void ProcessEntity(Entity& entity);
	};
};

#endif
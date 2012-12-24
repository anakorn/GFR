#ifndef GFR_PHYSICS_COMPONENT_H
#define GFR_PHYSICS_COMPONENT_H
#include "ComponentBase.h"

namespace framework
{
	class PhysicsComponent : public Component
	{
	public:
		f32 x, y;

		virtual const u64 GetMask() const { return MASK_PHYSICS_COMPONENT; }
	};
	COMPONENT_REGISTER(PhysicsComponent, "PhysicsComponent")
};

#endif
#ifndef GFR_COMPONENT_DERIVED_H
#define GFR_COMPONENT_DERIVED_H
#include "Component.h"

namespace framework
{
	class PhysicsComponent : public Component
	{
	public:
		f32 x, y;

		virtual const u64 GetMask() const { return MASK_PHYSICS_COMPONENT; }
	};
	COMPONENT_REGISTER(PhysicsComponent, "PhysicsComponent")

	class DrawComponent : public Component
	{
	public:


		virtual const u64 GetMask() const { return MASK_DRAW_COMPONENT; }
	};
	COMPONENT_REGISTER(DrawComponent, "DrawComponent")
};

#endif
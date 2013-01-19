#ifndef GFR_FRAMEWORK_COMPONENT_DERIVATIONS_DRAWCOMPONENT_H
#define GFR_FRAMEWORK_COMPONENT_DERIVATIONS_DRAWCOMPONENT_H
#include "ComponentBase.h"

namespace framework
{
	class DrawComponent : public Component
	{
	public:
		void		SetAnimationState	();

		virtual const u64 GetMask() const { return MASK_DRAW; }

	};
	COMPONENT_REGISTER(DrawComponent, "DrawComponent")
};

#endif
#ifndef GFR_DRAW_COMPONENT_H
#define GFR_DRAW_COMPONENT_H
#include "ComponentBase.h"

namespace framework
{
	class DrawComponent : public Component
	{
	public:
		void		SetAnimationState	();

		virtual const u64 GetMask() const { return MASK_DRAW_COMPONENT; }
	};
	COMPONENT_REGISTER(DrawComponent, "DrawComponent")
};

#endif
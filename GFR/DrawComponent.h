#ifndef GFR_FRAMEWORK_COMPONENT_DERIVATIONS_DRAWCOMPONENT_H
#define GFR_FRAMEWORK_COMPONENT_DERIVATIONS_DRAWCOMPONENT_H
#include "ComponentBase.h"
#include "Texture.h"

namespace framework
{
	class DrawComponent : public Component
	{
	public:
		void				SetAnimationState	();
		void				SetTexture			(Texture& texture);
		const Texture&		GetTexture			();

		virtual const u64	GetMask() const { return MASK_DRAW; }

	private:
		Texture*			m_Texture;

	};
	COMPONENT_REGISTER(DrawComponent, "DrawComponent")
};

#endif
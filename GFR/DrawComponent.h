#ifndef GFR_GAME_COMPONENT_DRAWCOMPONENT_H
#define GFR_GAME_COMPONENT_DRAWCOMPONENT_H
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

		void				SetPosition			(f32 x, f32 y);
		void				SetX				(f32 x);
		f32					GetX				();
		void				SetY				(f32 y);
		f32					GetY				();

		void				SetVisible			(bool visible);
		const bool			IsVisible			();

		virtual const u64	GetMask() const { return MASK_DRAW; }

	private:
		Texture*			m_Texture;
		f32					m_X;
		f32					m_Y;
		bool				m_IsVisible;

	};
	COMPONENT_REGISTER(DrawComponent, "DrawComponent")
};

#endif
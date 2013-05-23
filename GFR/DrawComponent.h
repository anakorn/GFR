#ifndef GFR_GAME_COMPONENT_DRAWCOMPONENT_H
#define GFR_GAME_COMPONENT_DRAWCOMPONENT_H

#include "ComponentBase.h"
#include "Texture.h"
#include "Animation.h"
#include "Vec2.h"
#include <vector>

namespace framework
{
	class DrawComponent : public Component
	{
	public:
		void				Initialize			(Texture* texture);

		void				SetAnimationState	();

		void				SetAnimation		(Animation* animation);
		Animation*			GetAnimation		();						// Returns a pointer so we can check if component contains animation.
		
		void				SetTexture			(Texture* texture);
		const Texture&		GetTexture			();

		void				SetPosition			(const Vec2f& position);
		Vec2f				GetPosition			();
		void				SetX				(f32& x);
		f32					GetX				();
		void				SetY				(f32& y);
		f32					GetY				();

		void				SetVisible			(bool visible);
		const bool			IsVisible			();

		virtual const u64	GetMask() const { return MASK_DRAW; }

	private:
		Animation*			m_Animation;
		Texture*			m_Texture;
		Vec2f				m_Position;
		bool				m_IsVisible;

	};
	COMPONENT_REGISTER(DrawComponent, "DrawComponent")
};

#endif
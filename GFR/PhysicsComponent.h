#ifndef GFR_GAME_COMPONENT_PHYSICSCOMPONENT_H
#define GFR_GAME_COMPONENT_PHYSICSCOMPONENT_H
#include "ComponentBase.h"
#include "Box2D\Box2D.h"
#include "Vec2.h"

namespace framework
{
	class PhysicsComponent : public Component
	{
	public:

		~PhysicsComponent();

		void Initialize(b2Body* body, const f32 &movementSpeed, const f32 &jumpSpeed);

		f32				GetBaseMovementSpeed	();
		f32				GetCurrentMovementSpeed	();

		f32				GetBaseJumpSpeed		();
		f32				GetCurrentJumpSpeed		();

		const Vec2f		GetPosition				();
		const f32		GetX					(void);
		const f32		GetY					(void);

		b2Body* const	GetBody				(void);
		void			SetBody				(b2Body* body);

		const b2Vec2 GetLinearVelocity	(void);
		void		 SetLinearVelocity	(const f32 &x, const f32 &y);

		void		 ApplyImpulse		(const b2Vec2 &force);

		virtual const u64 GetMask() const { return MASK_PHYSICS; }

	private:
		b2Body*		m_Body;

		f32 m_BaseMovementSpeed;
		f32 m_CurrentMovementSpeed;

		f32 m_BaseJumpSpeed;
		f32 m_CurrentJumpSpeed;

	};
	COMPONENT_REGISTER(PhysicsComponent, "PhysicsComponent")
};

#endif
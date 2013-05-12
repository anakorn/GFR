#ifndef GFR_FRAMEWORK_COMPONENT_DERIVATIONS_PHYSICSCOMPONENT_H
#define GFR_FRAMEWORK_COMPONENT_DERIVATIONS_PHYSICSCOMPONENT_H
#include "ComponentBase.h"
#include "Box2D\Box2D.h"

namespace framework
{
	class PhysicsComponent : public Component
	{
	public:
		~PhysicsComponent();

		const f32	 GetX				(void);
		const f32	 GetY				(void);
		void		 SetBody			(b2Body* body) { m_Body = body; }

		const b2Vec2 GetLinearVelocity	(void);
		void		 SetLinearVelocity	(const f32 &x, const f32 &y);

		void		 ApplyImpulse		(const b2Vec2 &force);

		virtual const u64 GetMask() const { return MASK_PHYSICS; }

	private:
		b2Body*		m_Body;

	};
	COMPONENT_REGISTER(PhysicsComponent, "PhysicsComponent")
};

#endif
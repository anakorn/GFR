#ifndef GFR_PHYSICS_COMPONENT_H
#define GFR_PHYSICS_COMPONENT_H
#include "ComponentBase.h"
#include "Box2D\Box2D.h"

namespace framework
{
	class PhysicsComponent : public Component
	{
	public:
		~PhysicsComponent();

		const f32	GetX			(void);
		const f32	GetY			(void);
		void		SetBody			(b2Body* body);

		virtual const u64 GetMask() const { return MASK_PHYSICS; }

	private:
		b2Body*		m_Body;

	};
	COMPONENT_REGISTER(PhysicsComponent, "PhysicsComponent")
};

#endif
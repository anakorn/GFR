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
		void		CreateBody		(bool isStatic, f32 originX, f32 originY, f32 angleRadians, 
										f32 linearDamping, f32 angularDamping, f32 gravityScale, 
										bool allowSleep, bool isAwake, bool isRotationFixed, bool isBullet = false, 
										void* userData = nullptr);

		virtual const u64 GetMask() const { return MASK_PHYSICS; }

	private:
		b2Body* m_Body;

	};
	COMPONENT_REGISTER(PhysicsComponent, "PhysicsComponent")
};

#endif
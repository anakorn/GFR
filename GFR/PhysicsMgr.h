#ifndef GFR_FRAMEWORK_MANAGERS_PHYSICSMGR_PHYSICSMGR_H
#define GFR_FRAMEWORK_MANAGERS_PHYSICSMGR_PHYSICSMGR_H
#include "Common.h"
#include "Box2D\Box2D.h"

namespace framework
{
	/*	Wrapper layer around Box2D library. Handles creation of physics bodies,
		destruction of bodies, and integration of physics.
	*/
	class PhysicsMgr
	{
	public:
		~PhysicsMgr();

		// Parameter descriptions found in Section 7.2 http://box2d.org/manual.pdf
		b2Body*		CreateStaticBody		(f32 originX, f32 originY, f32 angleRadians, 
												f32 linearDamping, f32 angularDamping, f32 gravityScale, 
												bool allowSleep, bool isAwake, bool isRotationFixed, 
												void* userData = nullptr);
		b2Body*		CreateDynamicBody		(f32 originX, f32 originY, f32 angleRadians, 
												f32 linearDamping, f32 angularDamping, f32 gravityScale, 
												bool allowSleep, bool isAwake, bool isRotationFixed, bool isBullet = false, 
												void* userData = nullptr);
		void		DestroyBody				(b2Body* body);

		// Steps through physics World by 'deltaTime' seconds.
		// Last 2 parameters determine # of constraint solver iterations;
		//		higher numbers = lower performance = more accurate physics.
		void		Update					(f32 deltaTime, u32 velocityIterations = 8, u32 positionIterations = 3);
		void		CreateWorld				(f32 gravityX, f32 gravityY, bool allowSleep);

	private:
		b2World*	m_World;

	};
};

#endif

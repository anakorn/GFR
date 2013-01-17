#ifndef GFR_PHYSICS_MGR_H
#define GFR_PHYSICS_MGR_H
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
		// Parameter descriptions found in Section 7.2 http://box2d.org/manual.pdf
		static b2Body*	CreateStaticBody	(b2World &world, f32 originX, f32 originY, f32 angleRadians, 
												f32 linearDamping, f32 angularDamping, f32 gravityScale, 
												bool allowSleep, bool isAwake, bool isRotationFixed, 
												void* userData = nullptr);
		static b2Body*	CreateDynamicBody	(b2World &world, f32 originX, f32 originY, f32 angleRadians, 
												f32 linearDamping, f32 angularDamping, f32 gravityScale, 
												bool allowSleep, bool isAwake, bool isRotationFixed, bool isBullet = false, 
												void* userData = nullptr);
		
		static void		DestroyBody			(b2World &world, b2Body* body);

		// Steps through physics World by 'deltaTime' seconds.
		// Last 2 parameters determine # of constraint solver iterations;
		//		higher numbers = lower performance = more accurate physics.
		void			Update				(f32 deltaTime, u32 velocityIterations = 8, u32 positionIterations = 3);
		void			CreateWorld			(f32 gravityX, f32 gravityY, bool allowSleep);

	private:
		b2World*		m_World;

	};
};

#endif

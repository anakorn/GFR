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

		void			CreateWorld		(f32 gravityX, f32 gravityY, bool allowSleep = true);
		b2World* const	GetWorld		(void);

		// Steps through physics World by 'deltaTime' seconds.
		// Last 2 parameters determine # of constraint solver iterations;
		//		higher numbers = lower performance = more accurate physics.
		void			Update			(f32 deltaTime, u32 velocityIterations = 8, u32 positionIterations = 3);

	private:
		b2World*		m_World;

	};
};

#endif
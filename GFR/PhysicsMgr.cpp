#include "PhysicsMgr.h"

using namespace framework;

PhysicsMgr::~PhysicsMgr()
{
	DELETE_SAFE(m_World);
}

b2World* const PhysicsMgr::GetWorld(void)
{
	return m_World;
};

void PhysicsMgr::Update(f32 deltaTime, u32 velocityIterations, u32 positionIterations)
{
	m_World->Step(deltaTime, velocityIterations, positionIterations);
	m_World->ClearForces();
};

void PhysicsMgr::CreateWorld(f32 gravityX, f32 gravityY, bool allowSleep)
{
	b2Vec2 gravityVec = b2Vec2(gravityX, gravityY);
	m_World = new b2World(gravityVec);
	m_World->SetAllowSleeping(allowSleep);
};
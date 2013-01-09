#include "PhysicsComponent.h"
#include "PhysicsMgr.h"

using namespace framework;

PhysicsComponent::~PhysicsComponent()
{
	delete m_Body;
	m_Body = NULL;
};

void PhysicsComponent::CreateBody(bool isStatic, f32 originX, f32 originY, f32 angleRadians, 
									f32 linearDamping, f32 angularDamping, f32 gravityScale, 
									bool allowSleep, bool isAwake, bool isRotationFixed, bool isBullet, 
									void* userData)
{
	if (m_Body != NULL)
	{
		// TODO: m_Body already defined, ERROR
	}

	if (isStatic)
	{
		m_Body = PhysicsMgr::CreateStaticBody(originX, originY, angleRadians,
			linearDamping, angularDamping, gravityScale, allowSleep, isAwake, isRotationFixed, userData);
	}
	else
	{
		m_Body = PhysicsMgr::CreateDynamicBody(originX, originY, angleRadians,
			linearDamping, angularDamping, gravityScale, allowSleep, isAwake, isRotationFixed, isBullet, userData);
	}
};
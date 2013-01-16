#include "PhysicsComponent.h"
#include "PhysicsMgr.h"

using namespace framework;

PhysicsComponent::~PhysicsComponent()
{
	// TODO: Tag for death. Destruction should be handled elsewhere.
	//m_Body->DeathTag;
};

void PhysicsComponent::SetBody(b2Body* body)
{
	m_Body = body;
};
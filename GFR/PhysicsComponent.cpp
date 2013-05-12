#include "PhysicsComponent.h"

using namespace framework;

PhysicsComponent::~PhysicsComponent()
{
	// TODO: Tag for death. Destruction should be handled elsewhere.
	//m_Body->DeathTag;
};

const f32 PhysicsComponent::GetX(void)
{
	return m_Body->GetPosition().x;
};

const f32 PhysicsComponent::GetY(void)
{
	return m_Body->GetPosition().y;
};

const b2Vec2 PhysicsComponent::GetLinearVelocity(void)
{
	return m_Body->GetLinearVelocity();
}

void PhysicsComponent::SetLinearVelocity(const f32 &x, const f32 &y)
{
	m_Body->SetLinearVelocity(b2Vec2(x, y));
}

void PhysicsComponent::ApplyImpulse(const b2Vec2 &impulse)
{
	m_Body->ApplyLinearImpulse(impulse, m_Body->GetWorldCenter());
}
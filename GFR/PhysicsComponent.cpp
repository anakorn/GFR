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

b2Body* const PhysicsComponent::GetBody(void)
{
	return m_Body;
};

void PhysicsComponent::SetBody(b2Body* body)
{
	m_Body = body;
};

const b2Vec2 PhysicsComponent::GetLinearVelocity(void)
{
	return m_Body->GetLinearVelocity();
};

void PhysicsComponent::SetLinearVelocity(f32 x, f32 y)
{
	m_Body->SetLinearVelocity(b2Vec2(x, y));
};
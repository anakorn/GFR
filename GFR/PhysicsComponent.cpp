#include "PhysicsComponent.h"

using namespace framework;

PhysicsComponent::~PhysicsComponent()
{
	// TODO: Tag for death. Destruction should be handled elsewhere.
	//m_Body->DeathTag;
};

void PhysicsComponent::Initialize(b2Body* body, const f32 &movementSpeed, const f32 &jumpSpeed)
{
	SetBody(body);

	m_BaseMovementSpeed = movementSpeed;
	m_CurrentMovementSpeed = movementSpeed;
	m_BaseJumpSpeed = jumpSpeed;
	m_CurrentJumpSpeed = jumpSpeed;
};

f32 PhysicsComponent::GetBaseMovementSpeed()
{
	return m_BaseMovementSpeed;
};

f32 PhysicsComponent::GetCurrentMovementSpeed()
{
	return m_CurrentMovementSpeed;
};

f32 PhysicsComponent::GetBaseJumpSpeed()
{
	return m_BaseJumpSpeed;
};

f32 PhysicsComponent::GetCurrentJumpSpeed()
{
	return m_CurrentJumpSpeed;
};

const Vec2f PhysicsComponent::GetPosition()
{
	b2Vec2 position = m_Body->GetPosition();
	return Vec2f(position.x, position.y);
};

const f32 PhysicsComponent::GetRotation()
{
	return m_Body->GetAngle();
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

void PhysicsComponent::SetLinearVelocity(const f32 &x, const f32 &y)
{
	m_Body->SetLinearVelocity(b2Vec2(x, y));
};

void PhysicsComponent::ApplyImpulse(const b2Vec2 &impulse)
{
	m_Body->ApplyLinearImpulse(impulse, m_Body->GetWorldCenter());
};
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
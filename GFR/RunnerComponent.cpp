#include "RunnerComponent.h"

using namespace game;
using namespace characters;

void RunnerComponent::Initialize(const std::string &name, const f32 &maxHealth, const f32 &movementSpeed, const f32 &jumpSpeed)
{
	m_MaxHealth = maxHealth;
	m_CurrentHealth = maxHealth;
	m_BaseMovementSpeed = movementSpeed; 
	m_CurrentMovementSpeed = movementSpeed;
	m_BaseJumpSpeed = jumpSpeed;
	m_CurrentJumpSpeed = jumpSpeed;
}

f32 RunnerComponent::GetMaxHealth()
{
	return m_MaxHealth;
}

f32 RunnerComponent::GetCurrentHealth()
{
	return m_CurrentHealth;
}

f32 RunnerComponent::GetBaseMovementSpeed()
{
	return m_BaseMovementSpeed;
}

f32 RunnerComponent::GetCurrentMovementSpeed()
{
	return m_CurrentMovementSpeed;
}

f32 RunnerComponent::GetBaseJumpSpeed()
{
	return m_BaseJumpSpeed;
}

f32 RunnerComponent::GetCurrentJumpSpeed()
{
	return m_CurrentJumpSpeed;
}
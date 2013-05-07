#include "Runner.h"

using namespace game;
using namespace characters;

void Runner::Initialize(const std::string &name, const f32 &maxHealth, const f32 &movementSpeed, const f32 &jumpSpeed)
{
	m_MaxHealth = maxHealth;
	m_CurrentHealth = maxHealth;
	m_BaseMovementSpeed = movementSpeed; 
	m_CurrentMovementSpeed = movementSpeed;
	m_BaseJumpSpeed = jumpSpeed;
	m_CurrentJumpSpeed = jumpSpeed;
}

f32 Runner::GetMaxHealth()
{
	return m_MaxHealth;
}

f32 Runner::GetCurrentHealth()
{
	return m_CurrentHealth;
}

f32 Runner::GetBaseMovementSpeed()
{
	return m_BaseMovementSpeed;
}

f32 Runner::GetCurrentMovementSpeed()
{
	return m_CurrentMovementSpeed;
}

f32 Runner::GetBaseJumpSpeed()
{
	return m_BaseJumpSpeed;
}

f32 Runner::GetCurrentJumpSpeed()
{
	return m_CurrentJumpSpeed;
}
#include "RunnerComponent.h"

using namespace game;
using namespace characters;

void RunnerComponent::Initialize(const std::string &name, const f32 &maxHealth)
{
	m_MaxHealth = maxHealth;
	m_CurrentHealth = maxHealth;
};

f32 RunnerComponent::GetMaxHealth()
{
	return m_MaxHealth;
};

f32 RunnerComponent::GetCurrentHealth()
{
	return m_CurrentHealth;
};
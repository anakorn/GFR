#include "Subsystem.h"
#include "Entity.h"

using namespace framework;

Subsystem::Subsystem(const u64 componentMask)
	: m_ComponentsMask(componentMask)
{ }

bool Subsystem::IsEntityCompatible(const Entity& entity) const
{
	return ((entity.GetComponentsMask() & m_ComponentsMask) == m_ComponentsMask);
}
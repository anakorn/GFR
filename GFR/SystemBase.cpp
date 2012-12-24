#include "SystemBase.h"
#include "Entity.h"

using namespace framework;

System::System(const u64 componentMask)
	: m_ComponentsMask(componentMask)
{ }

bool System::IsEntityCompatible(const Entity& entity) const
{
	return ((entity.GetComponentsMask() & m_ComponentsMask) == m_ComponentsMask);
}
#include "Entity.h"
#include "Component.h"
#include <map>

using namespace framework;

// Private implementation of Entity class (PIMPL idiom)
struct Entity::EntityImpl
{
	u64 m_ComponentsMask;
	std::map<const std::string, Component&> m_ComponentsRegistry;
};

Entity::Entity()
	: m_pimpl(new EntityImpl())
{

}

Entity::~Entity()
{
	delete m_pimpl;
}

void Entity::AttachComponent(const std::string componentName, Component& component)
{
	m_pimpl->m_ComponentsRegistry.insert(std::pair<const std::string, Component&>(componentName, component));
	m_pimpl->m_ComponentsMask |= component.GetMask();
}

const u64 Entity::GetComponentsMask() const
{
	return m_pimpl->m_ComponentsMask;
}
#include "Entity.h"
#include "ComponentBase.h"
#include <map>

using namespace framework;

// Private implementation of Entity class (PIMPL idiom)
struct Entity::EntityImpl
{
public:
	EntityImpl()
	{
		m_ComponentsMask = 0;
	}

	u64 m_ComponentsMask;
	std::map<const std::string, Component*> m_ComponentsRegistry;

};

Entity::Entity()
	: m_pimpl(new EntityImpl())
{

}

Entity::Entity(const u16 &networkID)
	: m_pimpl(new EntityImpl()), m_NetworkID(networkID)
{

}

Entity::~Entity()
{
	delete m_pimpl;
	m_pimpl = NULL;
}

void Entity::AttachComponent(const std::string& componentName)
{
	Component* comp = CreateComponent(componentName);
	if (!comp)
	{
		// TODO: Handle comp == nullptr
		assert(false);
	}

	m_pimpl->m_ComponentsRegistry.insert(std::pair<const std::string, Component*>(componentName, comp));
	m_pimpl->m_ComponentsMask |= comp->GetMask();
}

Component* Entity::GetComponent(const std::string& componentName)
{
	auto componentIter = m_pimpl->m_ComponentsRegistry.find(componentName);
	// TODO: Handle map value (component) not found
	assert(componentIter != m_pimpl->m_ComponentsRegistry.end());
	return componentIter->second;
}

const u64 Entity::GetComponentsMask() const
{
	return m_pimpl->m_ComponentsMask;
}

const u16 Entity::GetNetworkID()
{
	return m_NetworkID;
}
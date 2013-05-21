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
	};

	~EntityImpl()
	{
		// Delete this entity's associated components.
		FOR_EACH (component_it, m_ComponentsRegistry)
		{
			DELETE_SAFE(component_it->second);
		}
	};

	u64 m_ComponentsMask;
	std::map<const std::string, Component*> m_ComponentsRegistry;

};

Entity::Entity()
	: m_pimpl(new EntityImpl())
{

};

Entity::Entity(const u32 &id)
	: m_pimpl(new EntityImpl()), m_ID(id)
{

};

Entity::~Entity()
{
	DELETE_SAFE(m_pimpl);
};

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
};

Component* Entity::GetComponent(const std::string& componentName)
{
	auto componentIter = m_pimpl->m_ComponentsRegistry.find(componentName);
	// TODO: Handle map value (component) not found
	assert(componentIter != m_pimpl->m_ComponentsRegistry.end());
	return componentIter->second;
};

const u64 Entity::GetComponentsMask() const
{
	return m_pimpl->m_ComponentsMask;
};

const u32 Entity::GetID()
{
	return m_ID;
};
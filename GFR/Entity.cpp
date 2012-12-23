#include "Entity.h"
#include "Component.h"

using namespace Framework;

struct Entity::EntityImpl
{
	u64 m_ComponentsID;
	std::vector<Component> m_Components;
};

Entity::Entity()
	: m_pimpl(new EntityImpl())
{

}

Entity::~Entity()
{
	delete m_pimpl;
}

void Entity::AttachComponent(const Component& component)
{

}

bool Entity::ContainsComponents(const u64 componentMask) const
{
	return ((m_pimpl->m_ComponentsID & componentMask) == componentMask);
}
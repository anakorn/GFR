#include "EntityMgr.h"

using namespace framework;

EntityMgr::EntityMgr()
{

}

EntityMgr::~EntityMgr()
{

}

Entity* EntityMgr::CreateLocalEntity()
{
	Entity* ent = new Entity();
	return ent;
}

Entity* EntityMgr::CreateNetworkEntity()
{
	Entity* ent = new Entity();

	m_NetworkEntitiesCreated++;

	return ent;
}

Entity* EntityMgr::GetNetworkEntity(const u16 &networkID)
{
	return NULL;
}
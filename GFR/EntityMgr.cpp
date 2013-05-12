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

}

Entity* EntityMgr::CreateNetworkEntity()
{


	m_NetworkEntitiesCreated++;
}

Entity* EntityMgr::GetNetworkEntity(const u16 &networkID)
{

}
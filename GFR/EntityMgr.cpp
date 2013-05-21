#include "EntityMgr.h"

using namespace framework;

static std::map<u32, Entity*> m_LocalEntities;
static std::vector<u32> m_RemovedLocalIDs;

static std::map<u32, Entity*> m_NetworkEntities;
static std::vector<u32> m_RemovedNetworkIDs;

EntityMgr::~EntityMgr()
{
}

Entity* EntityMgr::CreateLocalEntity()
{
	return CreateEntity(m_LocalEntities, m_RemovedLocalIDs);
}

Entity* EntityMgr::CreateNetworkEntity()
{
	return CreateEntity(m_NetworkEntities, m_RemovedNetworkIDs);
}

Entity* EntityMgr::CreateNetworkEntity(const u32 &networkID)
{
	Entity* entity = new Entity(networkID);
	m_NetworkEntities[networkID] = entity;

	return entity;
}

void EntityMgr::RemoveLocalEntity(const u32 &localID)
{
	RemoveEntity(localID, m_LocalEntities, m_RemovedLocalIDs);
}

void EntityMgr::RemoveNetworkEntity(const u32 &networkID)
{
	RemoveEntity(networkID, m_NetworkEntities, m_RemovedNetworkIDs);
}

Entity* EntityMgr::GetLocalEntity(const u32 &localID)
{
	return m_LocalEntities[localID];
}

Entity* EntityMgr::GetNetworkEntity(const u32 &networkID)
{
	return m_NetworkEntities[networkID];
}

Entity* EntityMgr::CreateEntity(std::map<u32, Entity*> entityMap, std::vector<u32> removedIDList)
{
	u32 id;
	if (removedIDList.size() > 0)
	{
		id = removedIDList.at(0);
		removedIDList.erase(removedIDList.begin());
	}
	else
	{
		if (entityMap.empty())
		{
			id = 1;
		}
		else
		{
			u32 largestID = entityMap.rbegin()->first;
			id = largestID + 1;
		}
	}

	Entity* entity = new Entity(id);
	entityMap[id] = entity;

	return entity;
}

void EntityMgr::RemoveEntity(const u32 &id, std::map<u32, Entity*> entityMap, std::vector<u32> removedIDList)
{
	Entity* toErase = entityMap[id];

	entityMap.erase(id);
	DELETE_SAFE(toErase);

	removedIDList.push_back(id);
}
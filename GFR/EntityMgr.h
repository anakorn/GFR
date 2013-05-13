#ifndef GFR_FRAMEWORK_MANAGERS_ENTITYMGR_H
#define GFR_FRAMEWORK_MANAGERS_ENTITYMGR_H

#include "Entity.h"
#include "boost/unordered_map.hpp"
#include <vector>

namespace framework
{
	class EntityMgr
	{
	public:
		EntityMgr();
		~EntityMgr();

		Entity* CreateLocalEntity();
		Entity* CreateNetworkEntity();

		void RemoveLocalEntity();
		void RemoveNetworkEntity(const u16 &networkID);

		Entity* GetNetworkEntity(const u16 &networkID);

		void Render();

	private:
		std::vector<Entity*> m_LocalEntities;
		boost::unordered_map<u16, Entity*> m_NetworkEntities;

		u16 m_NetworkEntitiesCreated;
	};
};

#endif
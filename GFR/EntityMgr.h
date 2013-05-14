#ifndef GFR_FRAMEWORK_MANAGERS_ENTITYMGR_H
#define GFR_FRAMEWORK_MANAGERS_ENTITYMGR_H

#include <map>
#include <vector>
#include "Entity.h"

namespace framework
{
	class EntityMgr
	{
	public:
		~EntityMgr();

		static Entity* CreateLocalEntity();
		static Entity* CreateNetworkEntity();
		static Entity* CreateNetworkEntity(const u32 &networkID);

		static void RemoveLocalEntity(const u32 &localID);
		static void RemoveNetworkEntity(const u32 &networkID);

		static Entity* GetLocalEntity(const u32 &localID);
		static Entity* GetNetworkEntity(const u32 &networkID);

	private:
		static Entity* CreateEntity(std::map<u32, Entity*> entityMap, std::vector<u32> removedIDList);
		static void RemoveEntity(const u32 &id, std::map<u32, Entity*> entityMap, std::vector<u32> removedIDList);

	};
};

#endif
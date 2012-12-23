#ifndef GFR_SUBSYSTEM_H
#define GFR_SUBSYSTEM_H
#include "Common.h"

namespace Framework
{
	class Entity;

	class Subsystem
	{
	public:
		Subsystem(const u64 componentsMask);
		
		virtual void ProcessEntity(Entity& entity) = 0;

	private:
		// Used to check if an entity contains the right components for this subsystem
		const u64 m_ComponentsMask;

	};

};
#endif
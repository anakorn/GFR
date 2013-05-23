#ifndef GFR_FRAMEWORK_SYSTEM_SYSTEMBASE_H
#define GFR_FRAMEWORK_SYSTEM_SYSTEMBASE_H
#include "Common.h"

namespace framework
{
	class Entity;
	class System
	{
	public:
		System(const u64 componentsMask);
		
		bool			IsEntityCompatible	(const Entity& entity) const;
		void			ProcessEntity		(Entity& entity);

		// Implement this function in subclasses for System-specific behavior.
		virtual void	ProcessEntityImpl	(Entity& entity) = 0;

	private:
		// Used to check if an entity contains the right components for this System.
		const u64 m_ComponentsMask;

	};

};

#endif
#ifndef GFR_ENTITY_H
#define GFR_ENTITY_H
#include "Common.h"
#include <string>

namespace framework
{
	class Component;

	class Entity // : boost::noncopyable()
	{
	public:
		Entity();
		~Entity();

		void		AttachComponent			(const std::string componentName, Component& component);
		bool		ContainsComponents		(const u64 componentsMask) const;
		const u64	GetComponentsMask		() const;

	private:
		struct EntityImpl;
		// Ptr to entity implementation
		EntityImpl* m_pimpl;
		
	};
};


#endif
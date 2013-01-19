#ifndef GFR_FRAMEWORK_ENTITY_ENTITY_H
#define GFR_FRAMEWORK_ENTITY_ENTITY_H
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

		void		AttachComponent			(const std::string& componentName);
		Component*	GetComponent			(const std::string& componentName);
		const u64	GetComponentsMask		() const;

	private:
		struct EntityImpl;
		// Entity implementation
		EntityImpl* m_pimpl;
		
	};
};


#endif
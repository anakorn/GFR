#ifndef GFR_ENTITY_H
#define GFR_ENTITY_H
#include "Common.h"
#include <vector>

namespace Framework
{
	class Component;

	class Entity // : boost::noncopyable()
	{

	public:
		Entity();
		~Entity();

		void AttachComponent(const Component& component);
		bool ContainsComponents(const u64 componentMask) const;

	private:
		struct EntityImpl;
		// Ptr to entity implementation
		EntityImpl* m_pimpl;
		
	};

};


#endif
#ifndef GFR_COMPONENT_H
#define GFR_COMPONENT_H
#include "Common.h"
#include <map>
#include <string>

namespace framework
{
	class Component
	{
	public:
		const u64 GetMask() const;

	protected:


	private:

	};
	
	typedef Component* (*CreateComponentFunc)(void);
	typedef std::map<const std::string, CreateComponentFunc> CreateComponentFuncRegistry;
	static CreateComponentFuncRegistry s_CreateComponentFuncRegistry;

	static Component*	CreateComponent		(const std::string componentName);
	static void			DestroyComponent	(Component* component);
};

#endif
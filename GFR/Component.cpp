#include "Component.h"

using namespace framework;

const u64 Component::GetMask() const
{
	return 0;
}

Component* CreateComponent(const std::string componentName)
{
	CreateComponentFuncRegistry::iterator funcIt;
	funcIt = s_CreateComponentFuncRegistry.find(componentName);

	if (funcIt == s_CreateComponentFuncRegistry.end())
	{
		// No function found that is associated with componentName
		return nullptr;
	}
	//return (*funcIt)();
	return nullptr;
}

void DestroyComponent(Component* component)
{
	delete component;
}
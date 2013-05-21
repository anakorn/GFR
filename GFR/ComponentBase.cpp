#include "ComponentBase.h"
#include "ComponentDetail.h"

using namespace framework;

Component* framework::CreateComponent(const std::string& componentName)
{
	component::detail::CreateComponentFuncRegistry& reg = component::detail::GetComponentRegistry();
	component::detail::CreateComponentFuncRegistry::iterator funcIt = reg.find(componentName);

	//if (funcIt == reg.end())
	//{
	//	// No function found that is associated with componentName
	//	return nullptr;
	//}
	assert(funcIt != reg.end());

	component::detail::CreateComponentFunc func = funcIt->second;
	return func();
};

//void framework::DestroyComponent(const Component* component)
//{
//	DELETE_SAFE(component);
//};
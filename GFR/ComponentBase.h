#ifndef GFR_FRAMEWORK_COMPONENT_COMPONENTBASE_H
#define GFR_FRAMEWORK_COMPONENT_COMPONENTBASE_H
#include "Common.h"
#include "ComponentDetail.h"
#include "ComponentMask.h"
#include <map>
#include <string>

namespace framework
{
	/* Source: http://gamedev.stackexchange.com/a/17759 */
	Component*	CreateComponent		(const std::string& componentName);
	void		DestroyComponent	(const Component* component);

	#define COMPONENT_REGISTER(TYPE, NAME)											\
	namespace component {															\
	namespace detail {																\
	namespace																		\
	{																				\
		template<class T>															\
		class ComponentRegistration;												\
																					\
		template<>																	\
		class ComponentRegistration<TYPE>											\
		{																			\
			static const ::framework::component::detail::RegistryEntry<TYPE>& reg;	\
		};																			\
																					\
		const ::framework::component::detail::RegistryEntry<TYPE>&					\
			ComponentRegistration<TYPE>::reg =										\
				::framework::component::detail::RegistryEntry<TYPE>::Instance(NAME);\
	};};};

	class Component
	{
	public:
		virtual const u64 GetMask() const = 0;

	};

};

#endif
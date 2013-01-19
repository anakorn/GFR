#ifndef GFR_FRAMEWORK_COMPONENT_COMPONENTDETAIL_H
#define GFR_FRAMEWORK_COMPONENT_COMPONENTDETAIL_H

#include "Common.h"
#include <map>
#include <string>
#include <utility>

namespace framework
{
	class Component;

	namespace component
	{
		/* Source: http://gamedev.stackexchange.com/a/17759 */
		namespace detail
		{
			typedef framework::Component* (*CreateComponentFunc)();
			typedef std::map<const std::string, CreateComponentFunc> CreateComponentFuncRegistry;

			inline CreateComponentFuncRegistry& GetComponentRegistry()
			{
				static CreateComponentFuncRegistry reg;
				return reg;
			}

			template<class T>
			framework::Component* CreateComponent()
			{
				return new T;
			}

			template<class T>
			struct RegistryEntry
			{
			public:
				static RegistryEntry<T>& Instance(const std::string& name)
				{
					static RegistryEntry<T> instance(name);
					return instance;
				}

			private:
				RegistryEntry(const std::string& name)
				{
					CreateComponentFuncRegistry& reg = GetComponentRegistry();
					CreateComponentFunc func = CreateComponent<T>;

					std::pair<CreateComponentFuncRegistry::iterator, bool> ret =
						reg.insert(CreateComponentFuncRegistry::value_type(name, func));

					if (!ret.second)
					{
						// TODO: Handle component already registered.
						assert(false);
					}
				}

			};
		};
	};
};

#endif
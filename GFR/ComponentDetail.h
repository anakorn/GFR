#ifndef GFR_COMPONENT_DETAIL_H
#define GFR_COMPONENT_DETAIL_H

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

					// # of bits in mask limits # of possible components
					/*if (s_CurrentComponentMask != (1 << (sizeof(s_CurrentComponentMask) - 1 ) ))
					{*/
						std::pair<CreateComponentFuncRegistry::iterator, bool> ret =
							reg.insert(CreateComponentFuncRegistry::value_type(name, func));

						assert(ret.second);
						//if (!ret.second)
						//{
							// Component already registered.
						//}
					//}
				}

			};
		};
	};
};

#endif
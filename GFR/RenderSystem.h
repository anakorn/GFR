#ifndef GFR_FRAMEWORK_SYSTEM_DERIVATIONS_RENDERSYSTEM_H
#define GFR_FRAMEWORK_SYSTEM_DERIVATIONS_RENDERSYSTEM_H
#include "SystemBase.h"

namespace framework
{
	class RenderSystem : public System
	{
	public:
		RenderSystem();
		virtual void ProcessEntityImpl(Entity& entity);

	};
};

#endif
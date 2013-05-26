#ifndef GFR_GAME_SYSTEM_RENDERSYSTEM_H
#define GFR_GAME_SYSTEM_RENDERSYSTEM_H
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
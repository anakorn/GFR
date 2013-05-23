#ifndef GFR_GAME_COMPONENTS_NPCS_MINIONCOMPONENT_H
#define GFR_GAME_COMPONENTS_NPCS_MINIONCOMPONENT_H

#include "ComponentBase.h"
#include "Common.h"

namespace game
{
	namespace npcs
	{
		class MinionComponent : public framework::Component
		{
		public:

			virtual const u64 GetMask() const { return MASK_MINION; }

		protected:

		};

		COMPONENT_REGISTER(MinionComponent, "MinionComponent");
	};
};

#endif
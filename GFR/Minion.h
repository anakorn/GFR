#ifndef GFR_GAME_NPCS_MINION_H
#define GFR_GAME_NPCS_MINION_H

#include "ComponentBase.h"
#include "Common.h"

namespace game
{
	namespace npcs
	{
		class Minion : public framework::Component
		{
		public:

			virtual const u64 GetMask() const { return MASK_MINION; }

		protected:

		};

		COMPONENT_REGISTER(Minion, "Minion");
	};
};

#endif
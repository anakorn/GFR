#ifndef GFR_GAME_COMPONENTS_CHARACTERS_GODCOMPONENT_H
#define GFR_GAME_COMPONENTS_CHARACTERS_GODCOMPONENT_H

#include "Common.h"
#include "PlayableCharacter.h"

namespace game
{
	namespace characters
	{
		class GodComponent : public PlayableCharacter
		{
		public:
			
			virtual const u64 GetMask() const { return MASK_GOD; }

		protected:
			
		};

		COMPONENT_REGISTER(GodComponent, "GodComponent")
	};
};

#endif
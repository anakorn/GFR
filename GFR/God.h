#ifndef GFR_GAME_CHARACTERS_GOD_H
#define GFR_GAME_CHARACTERS_GOD_H

#include "Common.h"
#include "PlayableCharacter.h"

namespace game
{
	namespace characters
	{
		class God : public PlayableCharacter
		{
		public:
			
			virtual const u64 GetMask() const { return MASK_GOD; }

		protected:
			
		};

		COMPONENT_REGISTER(God, "God")
	};
};

#endif
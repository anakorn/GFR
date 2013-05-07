#ifndef GFR_GAME_CHARACTERS_PLAYABLECHARACTER_H
#define GFR_GAME_CHARACTERS_PLAYABLECHARACTER_H

#include "ComponentBase.h"

namespace game
{
	namespace characters
	{
		enum Class : int
		{
			ENGINEER,
			GOD,
			GUNNER,
			SCOUT
		};

		class PlayableCharacter : public framework::Component
		{
		public:
			std::string GetName();

		protected:
			std::string m_Name;
		};
	};
};

#endif
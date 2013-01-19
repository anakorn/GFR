#ifndef GFR_GAME_GAMESTATE_STATES_SERVERLOBBY_H
#define GFR_GAME_GAMESTATE_STATES_SERVERLOBBY_H

#include "State.h"
#include <string>

namespace game
{
	namespace gameState
	{
		class ServerLobby : public State
		{
		public:
			ServerLobby(const u32 &port, const std::string &gameName);
			~ServerLobby();
		};
	};
};

#endif
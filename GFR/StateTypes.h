#pragma once
#ifndef STATES_H
#define STATES_H

namespace game
{
	namespace stateTypes
	{
		// List all game states(screens) here
		// Used for adding networking listeners for each state
		// and switching between states
		enum Type : unsigned char
		{
			MAIN_MENU,
			SERVER_LOBBY,
			SERVER_LOBBY_SETUP,
			CLIENT_LOBBY,
			CLIENT_LOBBY_SETUP,
			OPTIONS,
			GAMEPLAY,
			PAUSE,
			NONE
		};
	};
};

#endif
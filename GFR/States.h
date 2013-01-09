#pragma once
#ifndef STATES_H
#define STATES_H

namespace StateTypes
{
	// List all game states(screens) here
	// Used for adding networking listeners for each state
	// and switching between states
	enum State : unsigned char
	{
		MAIN_MENU,
		SERVER_LOBBY,
		CLIENT_LOBBY,
		OPTIONS,
		GAMEPLAY,
		PAUSE,
		NONE
	};
}

#endif
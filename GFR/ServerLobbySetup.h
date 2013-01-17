#pragma once
#ifndef SERVERLOBBYSETUP_H
#define SERVERLOBBYSETUP_H

#include "GameState.h"

namespace gamestate
{
	class ServerLobbySetup : public GameState
	{
	public:
		ServerLobbySetup();
		~ServerLobbySetup();
	};
};

#endif
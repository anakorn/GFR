#pragma once
#ifndef SERVERLOBBY_H
#define SERVERLOBBY_H

#include "GameState.h"
#include <string>

namespace gamestate
{
	class ServerLobby : public GameState
	{
	public:
		ServerLobby(const u32 &port, const std::string &gameName);
		~ServerLobby();
	};
};

#endif
#pragma once
#ifndef CLIENTLOBBY_H
#define CLIENTLOBBY_H

#include "GameState.h"

namespace gamestate
{
	class ClientLobby : public GameState
	{
	public:
		// IP and port of server to connect to
		ClientLobby(const char* ip, const u32 &port);
		~ClientLobby();
	};
};

#endif
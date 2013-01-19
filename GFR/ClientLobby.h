#pragma once
#ifndef CLIENTLOBBY_H
#define CLIENTLOBBY_H

#include "State.h"

namespace game
{
	namespace gameState
	{
		class ClientLobby : public State
		{
		public:
			// IP and port of server to connect to
			ClientLobby(const char* ip, const u32 &port);
			~ClientLobby();
		};
	};
};

#endif
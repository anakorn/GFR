#pragma once
#ifndef SERVERLOBBY_H
#define SERVERLOBBY_H

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
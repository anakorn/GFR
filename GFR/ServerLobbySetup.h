#pragma once
#ifndef SERVERLOBBYSETUP_H
#define SERVERLOBBYSETUP_H

#include "State.h"

namespace game
{
	namespace gameState
	{
		class ServerLobbySetup : public State
		{
		public:
			ServerLobbySetup();
			~ServerLobbySetup();
		};
	};
};

#endif
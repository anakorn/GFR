#pragma once
#ifndef CLIENTLOBBYSETUP_H
#define CLIENTLOBBYSETUP_H

#include "State.h"

namespace game
{
	namespace gameState
	{
		class ClientLobbySetup : public State
		{
		public:
			ClientLobbySetup();
			~ClientLobbySetup();
		};
	};
};

#endif
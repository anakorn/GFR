#ifndef GFR_FRAMEWORK_NETWORKING_CONNECTION_H
#define GFR_FRAMEWORK_NETWORKING_CONNECTION_H

#include "enet/enet.h"
#include <string>

namespace networking
{
	// Just placing here for now while 
	// there isn't any actual game code
	enum CharacterType : char
	{
		GOD,
		ENGINEER,
		GUNNER,
		SCOUT,
		NONE
	};

	struct Connection
	{
		std::string PlayerName;
		ENetPeer* Peer;
		CharacterType Character;
	};
};

#endif
#pragma once
#ifndef NETWORKENUMS_H
#define NETWORKENUMS_H

namespace networking
{
	enum NetworkStatus
	{
		CONNECTING,
		CONNECTED,
		CONNECT_FAILURE,
		DISCONNECTED,
		IDLE,
		LISTENING,
		SHUTDOWN
	};

	enum PacketTypes : unsigned char
	{
		CHARACTER_SELECT,
		CLIENT_CONNECT,
		CONNECT_RESPONSE,
		START_GAME
	};
};

#endif
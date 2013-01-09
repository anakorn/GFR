#pragma once
#ifndef PACKETTYPES_H
#define PACKETTYPES_H

namespace networking
{
	enum PacketTypes : unsigned char
	{
		CHARACTER_SELECT,
		CLIENT_CONNECT,
		CONNECT_RESPONSE,
		START_GAME
	};
};

#endif
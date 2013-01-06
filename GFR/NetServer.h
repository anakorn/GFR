#pragma once
#ifndef NETSERVER_H
#define NETSERVER_H

#include "NetPeer.h"

namespace networking
{
	class NetServer : public NetPeer
	{
	public:
		NetServer(const u32 &port, const u32 &maxPlayers);
		~NetServer();
	};
};

#endif
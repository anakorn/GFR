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

	protected:
		virtual void HandleConnect(const ENetPacket &packet, const ENetPeer &peer) override;
		virtual void HandleDisconnect(const ENetPacket &packet, const ENetPeer &peer) override;
	};
};

#endif
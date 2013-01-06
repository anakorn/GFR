#pragma once
#ifndef PACKETHANDLER_H
#define PACKETHANDLER_H

#include "external/enet/include/enet/enet.h"

namespace networking
{
	class PacketHandler
	{
	public:
		PacketHandler();
		virtual ~PacketHandler();

		virtual void HandlePacket(const ENetPacket &packet) = 0;

		// Sends packet to all peers
		void SendPacket(const ENetPacket &packet);
		// Sends packet to specific peers
		void SendPacket(const ENetPacket &packet, const ENetPeer* recipients);
	protected:
		ENetPeer* peers;
	};
};

#endif
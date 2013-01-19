#ifndef GFR_FRAMEWORK_NETWORKING_NETSERVER_H
#define GFR_FRAMEWORK_NETWORKING_NETSERVER_H

#include "NetPeer.h"

namespace networking
{
	class NetServer : public NetPeer
	{
	public:
		NetServer(const u32 &port, const u32 &maxPlayers);
		NetServer();
		~NetServer();

		void Launch();
	protected:
		virtual void HandleConnect(const ENetPacket &packet, const ENetPeer &peer) override;
		virtual void HandleDisconnect(const ENetPacket &packet, const ENetPeer &peer) override;
	};
};

#endif
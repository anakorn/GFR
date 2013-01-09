#pragma once
#ifndef NETCLIENT_H
#define NETCLIENT_H

#include "NetPeer.h"

namespace networking
{
	class NetClient : public NetPeer
	{
	public:
		NetClient(const u32 &port);
		~NetClient();
		
		bool Connect(const char* &ip, const u32 &timeout);
		void Disconnect();

		void ShutDown() override;
	protected:
		virtual void HandleConnect(const ENetPacket &packet, const ENetPeer &peer) override;
		virtual void HandleData(const ENetPacket &packet, const ENetPeer &peer) override;
		virtual void HandleDisconnect(const ENetPacket &packet, const ENetPeer &peer) override;
	private:
		ENetPeer* m_Server;
	};
};

#endif
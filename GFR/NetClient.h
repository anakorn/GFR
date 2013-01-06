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
		
		bool Connect(const char* ip, const u32 &timeout);
		void Disconnect();

		void ShutDown() override;
	private:
		ENetPeer m_Server;
	};
};

#endif
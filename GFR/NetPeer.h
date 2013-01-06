#pragma once
#ifndef NETPEER_H
#define NETPEER_H

#include "Common.h"
#include "States.h"
#include "PacketHandler.h"
#include "external/enet/include/enet/enet.h"
#include <map>

namespace networking
{
	class NetPeer
	{
	public:
		NetPeer();
		virtual ~NetPeer();

		virtual void ShutDown();

		void AddPacketHandler(StateTypes::State state, PacketHandler* handler);
		void RemovePacketHandler(StateTypes::State state);
		void RemoveAllActivePacketHandlers();

		PacketHandler* GetPacketHandler(StateTypes::State state);

		void Update();
	protected:
		ENetHost* m_Net;
		ENetAddress m_Address;
		ENetEvent m_Event;

		std::map<StateTypes::State, PacketHandler*> m_Handlers;

		void Listen();
	};
};

#endif
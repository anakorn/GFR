#ifndef GFR_FRAMEWORK_NETWORKING_NETPEER_H
#define GFR_FRAMEWORK_NETWORKING_NETPEER_H

#include "Common.h"
#include "StateTypes.h"
#include "NetworkEnums.h"
#include "PacketHandler.h"
#include <enet/enet.h>
#include <map>
#include <thread>
#include "GFR_AL.h"

namespace networking
{
	class PacketHandler;

	class NetPeer
	{
	public:
		NetPeer();
		virtual ~NetPeer();

		virtual void ShutDown();

		void AddPacketHandler(game::stateTypes::Type state, PacketHandler* handler);
		void RemovePacketHandler(game::stateTypes::Type state);
		void RemoveAllActivePacketHandlers();

		PacketHandler* GetPacketHandler(game::stateTypes::Type state);
		NetworkStatus GetNetworkStatus();

		ENetPacket* CreatePacket(PacketTypes type, const bool &isReliable = false);
		// Sends packet to all peers
		void SendPacket(ENetPacket* packet, const u32 &channel = 0);
		void SendPacket(ENetPacket* packet, ENetPeer* recipient, const u32 &channel = 0);

		void Update();
	protected:
		ENetHost* m_Net;
		ENetAddress m_Address;
		ENetEvent m_Event;

		NetworkStatus m_Status;

		std::map<game::stateTypes::Type, PacketHandler*> m_Handlers;

		virtual void Listen();
		virtual void ListenFunc();

		virtual void HandleConnect(const ENetPacket &packet, const ENetPeer &peer) = 0;
		virtual void HandleDisconnect(const ENetPacket &packet, const ENetPeer &peer) = 0;
	};
};

#endif
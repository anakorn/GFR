#pragma once
#ifndef PACKETHANDLER_H
#define PACKETHANDLER_H

#include "Common.h"
#include "NetPeer.h"
#include "enet/enet.h"

namespace networking
{
	class NetPeer; 

	class PacketHandler
	{
	public:
		PacketHandler();
		virtual ~PacketHandler();

		void SetNetPeer(NetPeer* net);

		// Apply network inputs at the beginning
		// of each update cycle
		void Update();

		void EnqueuePacket(ENetPacket* packet);
		// Sends packet to all peers
		void SendPacket(ENetPacket* packet, const u32 &channel = 0);
		// Sends packet to specific peers
		void SendPacket(ENetPacket* packet, ENetPeer* recipient, const u32 &channel = 0);
	protected:
		// Pointer to current data being read in packet
		u32 m_PacketPointer;

		virtual void HandlePacket(const ENetPacket &packet) = 0;

		void WriteValue(ENetPacket &packet, void* src);
		void WriteString(ENetPacket &packet, char* src);

		void ReadValue(const ENetPacket &packet, void* dst, u32 size);
		bool ReadBool(const ENetPacket &packet);
		char ReadChar(const ENetPacket &packet);
		int ReadInt(const ENetPacket &packet);
		float ReadFloat(const ENetPacket &packet);
		char* ReadString(const ENetPacket &packet);
	private:
		NetPeer* m_Net;
	};
};

#endif
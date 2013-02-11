#ifndef GFR_FRAMEWORK_NETWORKING_IPACKETHANDLER_H
#define GFR_FRAMEWORK_NETWORKING_IPACKETHANDLER_H

#include "Common.h"
#include "NetPeer.h"
#include <enet/enet.h>
#include <string>
#include <map>
#include <queue>
#include <utility>

#define CALL_MEMBER_FN(object, ptrToMember) ((object).*(ptrToMember))

namespace networking
{
	class NetPeer;

	class PacketHandler
	{
	public:
		PacketHandler();
		virtual ~PacketHandler();

		void Attach(NetPeer* net);

		// Apply network inputs at the beginning
		// of each update cycle
		virtual void Update();

		bool EnqueuePacket(ENetPacket* packet, ENetPeer* sender);
		// Sends packet to all peers
		void SendPacket(ENetPacket* packet, const u32 &channel = 0);
		// Sends packet to specific peers
		void SendPacket(ENetPacket* packet, ENetPeer* recipient, const u32 &channel = 0);
	protected:
		// For callback functions that are associated with packet types
		typedef void (PacketHandler::*PacketCallback)(ENetPacket*, ENetPeer*);

		NetPeer* m_Net;
		// Pointer to current data being read in packet
		u32 m_PacketPointer;

		// Initialize all packet type/function callback pairs here
		// (which functions are called for which packet headers)
		virtual void RegisterPacketTypes() = 0;
		void RegisterPacketType(PacketTypes type, PacketCallback* callbackFunction);

		void WriteBool(ENetPacket &packet, bool value);
		void WriteChar(ENetPacket &packet, char value);
		void WriteShort(ENetPacket &packet, short value);
		void WriteU16(ENetPacket &packet, u16 value);
		void WriteInt(ENetPacket &packet, int value);
		void WriteU32(ENetPacket &packet, u32 value);
		void WriteFloat(ENetPacket &packet, float value);
		void WriteString(ENetPacket &packet, std::string value);

		bool ReadBool(const ENetPacket &packet, const bool &peek = false);
		char ReadChar(const ENetPacket &packet, const bool &peek = false);
		short ReadShort(const ENetPacket &packet, const bool &peek = false);
		u16 ReadU16(const ENetPacket &packet, const bool &peek = false);
		int ReadInt(const ENetPacket &packet, const bool &peek = false);
		u32 ReadU32(const ENetPacket &packet, const bool &peek = false);
		float ReadFloat(const ENetPacket &packet, const bool &peek = false);
		std::string ReadString(const ENetPacket &packet, const bool &peek = false);
	private:
		std::map<PacketTypes, PacketCallback*> m_PacketCallbacks;
		std::queue<std::pair<ENetPacket*, ENetPeer*>> m_PacketQueue;

		void WriteValue(ENetPacket &packet, void* value, const u32 &size);
		void ReadValue(const ENetPacket &packet, void* dst, const u32 &size, const bool &peek);

		void HandlePacket(ENetPacket* packet, ENetPeer* sender);
	};
};

#endif
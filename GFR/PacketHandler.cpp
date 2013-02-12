#include "PacketHandler.h"

using namespace networking;


PacketHandler::PacketHandler()
{
}

PacketHandler::~PacketHandler()
{
}

void PacketHandler::Attach(NetPeer* net)
{
	m_Net = net;
}

void PacketHandler::Update()
{
	while(m_PacketQueue.size() > 0)
	{
		m_PacketPointer = 0;

		std::pair<ENetPacket*, ENetPeer*> pair = m_PacketQueue.front();
		HandlePacket(pair.first, pair.second);
		m_PacketQueue.pop();
	}
}

void PacketHandler::HandlePacket(ENetPacket* packet, ENetPeer* sender)
{
	PacketTypes type = (PacketTypes)ReadChar(*packet);
	m_PacketCallbacks[type] (packet, sender);
}

bool PacketHandler::EnqueuePacket(ENetPacket* packet, ENetPeer* sender)
{
	PacketTypes type = static_cast<PacketTypes>(ReadChar(*packet, true));

	if((m_PacketCallbacks.find(type) == m_PacketCallbacks.end()))
		return false;
	else
	{
		m_PacketQueue.push(std::make_pair(packet, sender));
		return true;
	}
}

void PacketHandler::SendPacket(ENetPacket* packet, const u32 &channel)
{
	m_Net->SendPacket(packet, channel);
}


void PacketHandler::SendPacket(ENetPacket* packet, ENetPeer* recipient, const u32 &channel)
{
	m_Net->SendPacket(packet, recipient, channel);
}

void PacketHandler::RegisterPacketType(PacketTypes type, std::function<void(ENetPacket*, ENetPeer*)> func)
{
	m_PacketCallbacks[type] = func;
}

void PacketHandler::WriteValue(ENetPacket* packet, void* value, const u32 &size)
{
	int packetSize = packet->dataLength;
	enet_packet_resize(packet, packetSize + size);
	memcpy(&packet->data[packetSize], value, size);
}

void PacketHandler::WriteBool(ENetPacket* packet, bool value)
{
	WriteValue(packet, &value, sizeof(bool));
}

void PacketHandler::WriteChar(ENetPacket* packet, char value)
{
	WriteValue(packet, &value, sizeof(char));
}

void PacketHandler::WriteU16(ENetPacket* packet, u16 value)
{
	WriteValue(packet, &value, sizeof(u16));
}

void PacketHandler::WriteInt(ENetPacket* packet, int value)
{
	WriteValue(packet, &value, sizeof(int));
}

void PacketHandler::WriteU32(ENetPacket* packet, u32 value)
{
	WriteValue(packet, &value, sizeof(u32));
}

void PacketHandler::WriteFloat(ENetPacket* packet, float value)
{
	WriteValue(packet, &value, sizeof(float));
}

void PacketHandler::WriteString(ENetPacket* packet, std::string src)
{
	int size = sizeof(&src);
	WriteValue(packet, &size, sizeof(int));
	WriteValue(packet, &src, size);
}

void PacketHandler::ReadValue(const ENetPacket &packet, void* dst, const u32 &size, const bool &peek)
{
	memcpy(dst, &packet.data[m_PacketPointer], size);

	if (!peek)
		m_PacketPointer += size;
}

bool PacketHandler::ReadBool(const ENetPacket &packet, const bool &peek)
{
	bool value;
	ReadValue(packet, &value, sizeof(bool), peek);
	return value;
}

char PacketHandler::ReadChar(const ENetPacket &packet, const bool &peek)
{
	char value;
	ReadValue(packet, &value, sizeof(char), peek);
	return value;
}

short PacketHandler::ReadShort(const ENetPacket &packet, const bool &peek)
{
	short value;
	ReadValue(packet, &value, sizeof(short), peek);
	return value;
}

u16 PacketHandler::ReadU16(const ENetPacket &packet, const bool &peek)
{
	u16 value;
	ReadValue(packet, &value, sizeof(u16), peek);
	return value;
}

float PacketHandler::ReadFloat(const ENetPacket &packet, const bool &peek)
{
	float value;
	ReadValue(packet, &value, sizeof(float), peek);
	return value;
}

int PacketHandler::ReadInt(const ENetPacket &packet, const bool &peek)
{
	int value;
	ReadValue(packet, &value, sizeof(int), peek);
	return value;
}

u32 PacketHandler::ReadU32(const ENetPacket &packet, const bool &peek)
{
	u32 value;
	ReadValue(packet, &value, sizeof(u32), peek);
	return value;
}

std::string PacketHandler::ReadString(const ENetPacket &packet, const bool &peek)
{
	int size = ReadInt(packet, peek);
	std::string value;
	ReadValue(packet, &value, size, peek);
	return value;
}
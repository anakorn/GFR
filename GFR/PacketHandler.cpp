#include "PacketHandler.h"
#include <queue>

using namespace networking;

std::queue<ENetPacket*> m_PacketQueue;

PacketHandler::PacketHandler()
{
}

PacketHandler::~PacketHandler()
{
}

void PacketHandler::SetNetPeer(NetPeer* net)
{
	m_Net = net;
}

void PacketHandler::Update()
{
	while(m_PacketQueue.size() > 0)
	{
		HandlePacket(*m_PacketQueue.front());
		m_PacketQueue.pop();
	}
}

void PacketHandler::EnqueuePacket(ENetPacket* packet)
{
	m_PacketQueue.push(packet);
}

void PacketHandler::SendPacket(ENetPacket* packet, const u32 &channel)
{
	m_Net->SendPacket(packet, channel);
}


void PacketHandler::SendPacket(ENetPacket* packet, ENetPeer* recipient, const u32 &channel)
{
	m_Net->SendPacket(packet, recipient, channel);
}

void PacketHandler::WriteValue(ENetPacket &packet, void* src)
{
	int packetSize = packet.dataLength;
	int valueSize = sizeof(src);
	enet_packet_resize(&packet, packetSize + valueSize);
	memcpy(&packet.data[packetSize], src, valueSize);
}

void PacketHandler::WriteString(ENetPacket &packet, char* src)
{
	int size = sizeof(src);
	WriteValue(packet, &size);
	WriteValue(src);
}

void PacketHandler::ReadValue(const ENetPacket &packet, void* dst, u32 size)
{
	memcpy(dst, &packet.data[m_PacketPointer], size);
	m_PacketPointer += size;
}

bool PacketHandler::ReadBool(const ENetPacket &packet)
{
	bool value;
	ReadValue(packet, &value, sizeof(bool));
	return value;
}

char PacketHandler::ReadChar(const ENetPacket &packet)
{
	char value;
	ReadValue(packet, &value, sizeof(char));
	return value;
}

float PacketHandler::ReadFloat(const ENetPacket &packet)
{
	float value;
	ReadValue(packet, &value, sizeof(float));
	return value;
}

int PacketHandler::ReadInt(const ENetPacket &packet)
{
	int value;
	ReadValue(packet, &value, sizeof(int));
	return value;
}

char* PacketHandler::ReadString(const ENetPacket &packet)
{
	int size = ReadInt(packet);
	char* stringValue;
	ReadValue(packet, stringValue, size);
	return stringValue;
}
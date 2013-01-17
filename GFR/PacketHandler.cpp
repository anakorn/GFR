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

bool PacketHandler::EnqueuePacket(ENetPacket* packet, ENetPeer* sender)
{
	m_PacketQueue.push(packet);
	return true;
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

void PacketHandler::WriteString(ENetPacket &packet, std::string &src)
{
	int size = sizeof(&src);
	WriteValue(packet, &size);
	WriteValue(packet, &src);
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

std::string PacketHandler::ReadString(const ENetPacket &packet)
{
	int size = ReadInt(packet);
	std::string value;
	ReadValue(packet, &value, size);
	return value;
}
#include "PacketHandler.h"

using namespace networking;

PacketHandler::PacketHandler()
{

}

PacketHandler::~PacketHandler()
{
	delete peers;
}

void PacketHandler::SendPacket(const ENetPacket &packet)
{

}

void PacketHandler::SendPacket(const ENetPacket &packet, const ENetPeer* recipients)
{

}
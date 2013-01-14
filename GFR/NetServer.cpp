#include "NetServer.h"

using namespace networking;

NetServer::NetServer(const u32 &port, const u32 &maxPlayers)
	: NetPeer()
{
	m_Address.host = ENET_HOST_ANY;
	m_Address.port = port;

	m_Net = enet_host_create(&m_Address, maxPlayers, 2, 0, 0);
}

NetServer::~NetServer()
{
}

void NetServer::HandleConnect(const ENetPacket &packet, const ENetPeer &peer)
{

}

void NetServer::HandleDisconnect(const ENetPacket &packet, const ENetPeer &peer)
{

}
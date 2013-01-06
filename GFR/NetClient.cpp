#include "NetClient.h"

using namespace networking;

NetClient::NetClient(const u32 &port)
	: NetPeer()
{
	m_Address.port = port;
	m_Net = enet_host_create(NULL, 1, 2, 0, 0);
}

NetClient::~NetClient()
{
}

bool NetClient::Connect(const char* ip, const u32 &timeout)
{
	enet_address_set_host(&m_Address, ip);
	m_Server = *enet_host_connect(m_Net, &m_Address, 2, 0);

	return enet_host_service(m_Net, &m_Event, timeout) > 0;
}

void NetClient::Disconnect()
{
	enet_peer_disconnect(&m_Server, 0);
}

void NetClient::ShutDown()
{
	Disconnect();

	NetPeer::ShutDown();
}
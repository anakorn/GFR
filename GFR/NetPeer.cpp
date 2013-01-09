#include "NetPeer.h"
#include <thread>

using namespace networking;

NetPeer::NetPeer()
{
	enet_initialize();
}

NetPeer::~NetPeer()
{
	ShutDown();
}

void NetPeer::AddPacketHandler(StateTypes::State state, PacketHandler* handler)
{
	handler->SetNetPeer(this);
	m_Handlers.insert(std::make_pair(state, handler));
}

void NetPeer::RemovePacketHandler(StateTypes::State state)
{
	delete m_Handlers.at(state);
	m_Handlers.erase(state);
}

void NetPeer::RemoveAllActivePacketHandlers()
{
	for(auto iter = m_Handlers.begin(); iter != m_Handlers.end();)
	{
		delete iter->second;
		iter = m_Handlers.erase(iter);
	}
}

PacketHandler* NetPeer::GetPacketHandler(StateTypes::State state)
{
	return m_Handlers[state];
}

ENetPacket* NetPeer::CreatePacket(PacketTypes type, const bool &isReliable)
{
	ENetPacket* packet = enet_packet_create(NULL, sizeof(char) + 1, 
		isReliable ? ENET_PACKET_FLAG_RELIABLE : ENET_PACKET_FLAG_UNRELIABLE_FRAGMENT);

	packet->data[0] = type;
	return packet;
}

void NetPeer::SendPacket(ENetPacket* packet, const u32 &channel)
{
	enet_host_broadcast(m_Net, channel, packet);
	enet_host_flush(m_Net);
}

void NetPeer::SendPacket(ENetPacket* packet, ENetPeer* recipient, const u32 &channel)
{
	enet_peer_send(recipient, channel, packet);
	enet_host_flush(m_Net);
}

void NetPeer::Update()
{
	for(auto iter = m_Handlers.begin(); iter != m_Handlers.end(); ++iter)
	{
		iter->second->Update();
	}
}

void NetPeer::BeginListening()
{
}

void NetPeer::Listen()
{
	while(enet_host_service(m_Net, &m_Event, 1000))
	{
		switch(m_Event.type)
		{
		case ENET_EVENT_TYPE_CONNECT:
			this->HandleConnect(*m_Event.packet, *m_Event.peer);
			break;
		case ENET_EVENT_TYPE_RECEIVE:
			this->HandleData(*m_Event.packet, *m_Event.peer);
			break;
		case ENET_EVENT_TYPE_DISCONNECT:
			this->HandleDisconnect(*m_Event.packet, *m_Event.peer);
			break;
		default:
			break;
		}

		enet_packet_destroy(m_Event.packet);
	}
}

void NetPeer::ShutDown()
{
	enet_host_destroy(m_Net);
	enet_deinitialize();
}
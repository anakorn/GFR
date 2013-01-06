#include "NetPeer.h"

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
	m_Handlers.insert(std::make_pair(state, handler));
}

void NetPeer::RemovePacketHandler(StateTypes::State state)
{
	delete m_Handlers.at(state);
	m_Handlers.erase(state);
}

void NetPeer::RemoveAllActivePacketHandlers()
{
	for(std::map<StateTypes::State, PacketHandler*>::iterator iter = m_Handlers.begin(); iter != m_Handlers.end();)
	{
		delete iter->second;
		iter = m_Handlers.erase(iter);
	}
}

PacketHandler* NetPeer::GetPacketHandler(StateTypes::State state)
{
	return m_Handlers[state];
}

void NetPeer::Update()
{

}

void NetPeer::ShutDown()
{
	enet_host_destroy(m_Net);
	enet_deinitialize();
}
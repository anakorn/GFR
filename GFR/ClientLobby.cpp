#include "NetClient.h"
#include "C_LobbyHandler.h"
#include "ClientLobby.h"
#include "ClientLobbyGUI.h"

using namespace game;
using namespace gameState;

networking::NetClient* m_Client;

ClientLobby::ClientLobby(const char* ip, const u32 &port)
	: State(stateTypes::CLIENT_LOBBY)
{
	m_Client = new networking::NetClient(port);
	m_Client->AddPacketHandler(m_StateType, new gfrNetworking::CLobbyHandler());
	m_Client->Connect(ip, 5000);

	m_Gui = new gui::ClientLobbyGUI(*m_Client);
	m_Gui->InitializeGUIComponents();
}

ClientLobby::~ClientLobby()
{
}

void ClientLobby::Update()
{
	m_Client->Update();

	State::Update();
}
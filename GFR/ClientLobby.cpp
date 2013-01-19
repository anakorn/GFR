#include "NetClient.h"
#include "ClientLobby.h"
#include "ClientLobbyGUI.h"

using namespace game;
using namespace gameState;

ClientLobby::ClientLobby(const char* ip, const u32 &port)
	: State(stateTypes::CLIENT_LOBBY)
{
	networking::NetClient* client = new	networking::NetClient(port);
	client->Connect(ip, 5000);

	m_Gui = new gui::ClientLobbyGUI(*client);
	m_Gui->InitializeGUIComponents();
}

ClientLobby::~ClientLobby()
{
}
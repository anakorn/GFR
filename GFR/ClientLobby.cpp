#include "NetClient.h"
#include "ClientLobby.h"
#include "ClientLobbyGUI.h"

using namespace gamestate;

ClientLobby::ClientLobby(const char* ip, const u32 &port)
	: GameState(StateTypes::CLIENT_LOBBY)
{
	networking::NetClient* client = new	networking::NetClient(port);
	client->Connect(ip, 5000);

	m_Gui = new gui::ClientLobbyGUI(*client);
	m_Gui->InitializeGUIComponents();
}

ClientLobby::~ClientLobby()
{
}
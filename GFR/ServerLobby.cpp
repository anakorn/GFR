#include "NetServer.h"
#include "ServerLobby.h"
#include "ServerLobbyGUI.h"

using namespace gamestate;

ServerLobby::ServerLobby(const u32 &port, const std::string &gameName)
	: GameState(StateTypes::SERVER_LOBBY)
{
	networking::NetServer* server = new networking::NetServer(port, 3);
	server->Launch();

	m_Gui = new gui::ServerLobbyGUI(*server);
	m_Gui->InitializeGUIComponents();
}

ServerLobby::~ServerLobby()
{
}
#include "ServerLobbySetup.h"
#include "ServerLobbySetupGUI.h"

using namespace gamestate;

ServerLobbySetup::ServerLobbySetup()
	: GameState(StateTypes::SERVER_LOBBY_SETUP)
{
	m_Gui = new gui::ServerLobbySetupGUI();
	m_Gui->InitializeGUIComponents();
}

ServerLobbySetup::~ServerLobbySetup()
{

}
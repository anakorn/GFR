#include "ServerLobbySetup.h"
#include "ServerLobbySetupGUI.h"

using namespace game;
using namespace gameState;

ServerLobbySetup::ServerLobbySetup()
	: State(stateTypes::SERVER_LOBBY_SETUP)
{
	m_Gui = new gui::ServerLobbySetupGUI();
	m_Gui->InitializeGUIComponents();
}

ServerLobbySetup::~ServerLobbySetup()
{

}
#include "ClientLobbySetup.h"
#include "ClientLobbySetupGUI.h"

using namespace game;
using namespace gameState;

ClientLobbySetup::ClientLobbySetup()
	: State(stateTypes::CLIENT_LOBBY_SETUP)
{
	m_Gui = new gui::ClientLobbySetupGUI();
	m_Gui->InitializeGUIComponents();
}

ClientLobbySetup::~ClientLobbySetup()
{

}
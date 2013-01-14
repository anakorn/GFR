#include "ClientLobbySetup.h"
#include "ClientLobbySetupGUI.h"

using namespace gamestate;

ClientLobbySetup::ClientLobbySetup()
	: GameState(StateTypes::CLIENT_LOBBY_SETUP)
{
	m_Gui = new gui::ClientLobbySetupGUI();
	m_Gui->InitializeGUIComponents();
}

ClientLobbySetup::~ClientLobbySetup()
{

}
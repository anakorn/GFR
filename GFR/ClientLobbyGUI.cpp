#include "ClientLobbyGUI.h"

using namespace game;
using namespace gui;

ClientLobbyGUI::ClientLobbyGUI(networking::NetClient &client)
	: GUIBase()
{
	m_Client = client;
}

ClientLobbyGUI::~ClientLobbyGUI()
{

}

void ClientLobbyGUI::InitializeGUIComponents()
{

}

void ClientLobbyGUI::Update()
{
	GUIBase::Update();
}
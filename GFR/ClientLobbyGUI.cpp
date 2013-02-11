#include "ClientLobbyGUI.h"

using namespace game;
using namespace gui;

ClientLobbyGUI::ClientLobbyGUI(const networking::NetClient &client)
	: GUIBase()
{
	m_Client = client;
}

ClientLobbyGUI::~ClientLobbyGUI()
{

}

void ClientLobbyGUI::InitializeGUIComponents()
{
	m_StatusLabel = agui::Label("Status: ");

	m_GUI->add(&m_StatusLabel);
}

void ClientLobbyGUI::Update()
{
	GUIBase::Update();
}
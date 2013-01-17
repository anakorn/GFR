#include "ClientLobbySetupGUI.h"
#include "GFR_AL.h"
#include "Configuration.h"

using namespace gui;

// Floats (0.0f-1.0f) given as percentages of screen dimensions
const f32 FIRST_COL_X = 0.30f;
const f32 SECOND_COL_X = 0.50f;

const f32 FIRST_ROW_Y = 0.25f;
const f32 ROW_GAP = 0.05f;

ClientLobbySetupGUI::ClientLobbySetupGUI()
	: GUIBase(), m_ButtonListener(this)
{

}

ClientLobbySetupGUI::~ClientLobbySetupGUI()
{

}

void ClientLobbySetupGUI::InitializeGUIComponents()
{
	u32 screenWidth = framework::GFR_AL::GetScreenWidth();
	u32 screenHeight = framework::GFR_AL::GetScreenHeight();

	m_IPLabel.setText("IP");
	m_IPLabel.setLocation(screenWidth * FIRST_COL_X, screenHeight * FIRST_ROW_Y);
	m_GUI->add(&m_IPLabel);

	m_IPField.setText(framework::Configuration::GetStringValue("SAVEDFIELD", "ip"));
	m_IPField.setBackColor(agui::Color(255, 255, 255));
	m_IPField.setReadOnly(false);
	m_IPField.resizeToContents();
	m_IPField.setLocation(screenWidth * SECOND_COL_X, screenHeight * FIRST_ROW_Y);
	m_GUI->add(&m_IPField);

	m_PortLabel.setText("Port");
	m_PortLabel.setLocation(screenWidth * FIRST_COL_X, screenHeight * (FIRST_ROW_Y + ROW_GAP));
	m_GUI->add(&m_PortLabel);

	m_PortField.setText(framework::Configuration::GetStringValue("SAVEDFIELD", "port"));
	m_PortField.setBackColor(agui::Color(255, 255, 255));
	m_PortField.setReadOnly(false);
	m_PortField.setSize(m_IPField.getSize());
	m_PortField.setLocation(screenWidth * SECOND_COL_X, screenHeight * (FIRST_ROW_Y + ROW_GAP));
	m_GUI->add(&m_PortField);

	m_OkButton.setText("Connect");
	m_OkButton.resizeToContents();
	m_OkButton.setLocation(screenWidth * ((FIRST_COL_X + SECOND_COL_X) * 0.5f), screenHeight * (FIRST_ROW_Y + 2 * ROW_GAP));
	m_OkButton.addActionListener(&m_ButtonListener);
	m_GUI->add(&m_OkButton);
}

void ClientLobbySetupGUI::ShowErrorMessage(const std::string &message)
{

}

void ClientLobbySetupGUI::SetupButtonListener::actionPerformed(const agui::ActionEvent &evt)
{
	agui::Widget* source = evt.getSource();
	if (source == &m_Container->m_OkButton)
	{
		std::string ip = m_Container->m_IPField.getText();
		int port = atoi(m_Container->m_PortField.getText().c_str());

		if(ValidateInput(ip, port))
		{
			std::vector<void*> args;
			args.push_back(&ip);
			args.push_back(&port);

			framework::Configuration::SetValue("SAVEDFIELD", "ip", ip.c_str());
			framework::Configuration::SetValue("SAVEDFIELD", "port", std::to_string(port).c_str());
			framework::Configuration::SaveNewValues();

			framework::GFR_AL::PopGameState();
			framework::GFR_AL::PushGameState(StateTypes::State::CLIENT_LOBBY, args);
		}
		else
			m_Container->ShowErrorMessage("Invalid input");
	}
	else if (source == &m_Container->m_BackButton)
		framework::GFR_AL::PopGameState();
}

bool ClientLobbySetupGUI::SetupButtonListener::ValidateInput(const std::string &ip, const int &port)
{
	if(port <= 0)
		return false;

	return true;
}
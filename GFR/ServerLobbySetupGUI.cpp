#include "ServerLobbySetupGUI.h"
#include "Configuration.h"
#include "GFR_AL.h"

using namespace gui;

// Floats (0.0f-1.0f) given as percentages of screen dimensions
const f32 FIRST_COL_X = 0.30f;
const f32 SECOND_COL_X = 0.50f;

const f32 FIRST_ROW_Y = 0.25f;
const f32 ROW_GAP = 0.05f;

ServerLobbySetupGUI::ServerLobbySetupGUI()
	: m_ButtonListener(this)
{

}

ServerLobbySetupGUI::~ServerLobbySetupGUI()
{

}

void ServerLobbySetupGUI::InitializeGUIComponents()
{
	u32 screenWidth = framework::GFR_AL::GetScreenWidth();
	u32 screenHeight = framework::GFR_AL::GetScreenHeight();

	m_GameNameLabel.setText("Game Name");
	m_GameNameLabel.setLocation(screenWidth * FIRST_COL_X, screenHeight * FIRST_ROW_Y);
	m_GUI->add(&m_GameNameLabel);

	m_GameNameField.setText(framework::Configuration::GetStringValue("SAVEDFIELD", "gameName"));
	m_GameNameField.setBackColor(agui::Color(255, 255, 255));
	m_GameNameField.setReadOnly(false);
	m_GameNameField.resizeToContents();
	m_GameNameField.setLocation(screenWidth * SECOND_COL_X, screenHeight * FIRST_ROW_Y);
	m_GUI->add(&m_GameNameField);

	m_PortLabel.setText("Port");
	m_PortLabel.setLocation(screenWidth * FIRST_COL_X, screenHeight * (FIRST_ROW_Y + ROW_GAP));
	m_GUI->add(&m_PortLabel);

	m_PortField.setText(framework::Configuration::GetStringValue("SAVEDFIELD", "port"));
	m_PortField.setBackColor(agui::Color(255, 255, 255));
	m_PortField.setReadOnly(false);
	m_PortField.setSize(m_GameNameField.getSize());
	m_PortField.setLocation(screenWidth * SECOND_COL_X, screenHeight * (FIRST_ROW_Y + ROW_GAP));
	m_GUI->add(&m_PortField);

	m_OkButton.setText("Start");
	m_OkButton.resizeToContents();
	m_OkButton.setLocation(screenWidth * ((FIRST_COL_X + SECOND_COL_X) * 0.5f), screenHeight * (FIRST_ROW_Y + 2 * ROW_GAP));
	m_OkButton.addActionListener(&m_ButtonListener);
	m_GUI->add(&m_OkButton);
}

void ServerLobbySetupGUI::ShowErrorMessage(const std::string &message)
{

}

void ServerLobbySetupGUI::SetupButtonListener::actionPerformed(const agui::ActionEvent &evt)
{
	agui::Widget* source = evt.getSource();
	if (source == &m_Container->m_OkButton)
	{
		std::string gameName = m_Container->m_GameNameField.getText();
		int port = atoi(m_Container->m_PortField.getText().c_str());

		if(ValidateInput(port))
		{
			std::vector<void*> args;
			args.push_back(&port);
			args.push_back(&gameName);

			framework::Configuration::SetValue("SAVEDFIELD", "gameName", gameName.c_str());
			framework::Configuration::SetValue("SAVEDFIELD", "port", std::to_string(port).c_str());
			framework::Configuration::SaveNewValues();

			framework::GFR_AL::PopGameState();
			framework::GFR_AL::PushGameState(StateTypes::State::SERVER_LOBBY, args);
		}
		else
			m_Container->ShowErrorMessage("Invalid input");
	}
	else if (source == &m_Container->m_BackButton)
		framework::GFR_AL::PopGameState();
}

bool ServerLobbySetupGUI::SetupButtonListener::ValidateInput(const int &port)
{
	if(port <= 0)
		return false;

	return true;
}
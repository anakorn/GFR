#include "MainMenuGUI.h"
#include "GFR_AL.h"

using namespace gui;

class MainMenuButtonListener : public agui::ActionListener
{
public:
	virtual void actionPerformed(const agui::ActionEvent &evt) override;
};

agui::Button hostGameButton;
agui::Button joinGameButton;
agui::Button optionsButton;
agui::Button exitButton;
MainMenuButtonListener buttonListener;

MainMenuGUI::MainMenuGUI()
	: GUIBase()
{

}

MainMenuGUI::~MainMenuGUI()
{
}

void MainMenuGUI::InitializeGUIComponents()
{
	m_GUI->add(&layout);

	textField.setText("Textfield testing");
	textField.setBackColor(agui::Color(255, 255, 255));
	textField.setReadOnly(false);
	textField.resizeToContents();
	layout.add(&textField);

	frame.setSize(220,120);
	frame.setLocation(60,60);
	frame.setText("Example Frame");
	layout.add(&frame);

	hostGameButton.setText("Host Game");
	hostGameButton.resizeToContents();
	hostGameButton.addActionListener(&buttonListener);
	layout.add(&hostGameButton);

	joinGameButton.setText("Join Game");
	joinGameButton.resizeToContents();
	joinGameButton.addActionListener(&buttonListener);
	layout.add(&joinGameButton);

	optionsButton.setText("Options");
	optionsButton.resizeToContents();
	optionsButton.addActionListener(&buttonListener);
	layout.add(&optionsButton);

	exitButton.setText("Exit");
	exitButton.resizeToContents();
	exitButton.addActionListener(&buttonListener);
	layout.add(&exitButton);
}

void MainMenuButtonListener::actionPerformed(const agui::ActionEvent &evt)
{
	agui::Widget* source = evt.getSource();

	if (source == &hostGameButton)
		framework::GFR_AL::PushGameState(StateTypes::SERVER_LOBBY_SETUP);
	else if (source == &joinGameButton)
		framework::GFR_AL::PushGameState(StateTypes::CLIENT_LOBBY_SETUP);
	else if (source == &optionsButton)
		framework::GFR_AL::PushGameState(StateTypes::OPTIONS);
	else if (source == &exitButton)
		framework::GFR_AL::EndGame();
}
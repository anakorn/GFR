#include "MainMenuGUI.h"
#include "GFR_AL.h"
#include "GameStateManager.h"

using namespace gui;

class MainMenuButtonListener : public agui::ActionListener
{
public:
	virtual void actionPerformed(const agui::ActionEvent &evt) override;
};

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

	optionsButton.setSize(300, 100);
	optionsButton.setText("Options");
	optionsButton.addActionListener(&buttonListener);
	layout.add(&optionsButton);

	exitButton.setSize(300, 100);
	exitButton.setText("Exit");
	exitButton.addActionListener(&buttonListener);
	layout.add(&exitButton);
}

void MainMenuButtonListener::actionPerformed(const agui::ActionEvent &evt)
{
	agui::Widget* source = evt.getSource();

	if(source == &optionsButton)
		gamestate::GameStateManager::PushGameState(StateTypes::OPTIONS);
	else if(source == &exitButton)
		framework::GFR_AL::EndGame();
}
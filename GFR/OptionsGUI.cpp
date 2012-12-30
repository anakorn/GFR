#include "OptionsGUI.h"
#include "allegro5/allegro5.h"
#include "Configuration.h"
#include "GameStateManager.h"

using namespace gui;

class OptionsButtonListener : public agui::ActionListener
{
public:
	virtual void actionPerformed(const agui::ActionEvent &evt) override;
};

agui::Button backButton;
OptionsButtonListener buttonListener;

OptionsGUI::OptionsGUI()
	: GUIBase()
{

}

OptionsGUI::~OptionsGUI()
{
}

void OptionsGUI::InitializeGUIComponents()
{
	layout.setNumberOfColumns(2);
	layout.setNumberOfRows(0);
	m_GUI->add(&layout);

	fullScreenLabel.setText("Fullscreen");
	layout.add(&fullScreenLabel);

	fullScreenCheckbox.setChecked(framework::Configuration::GetBoolValue("SCREEN", "fullscreen"));
	layout.add(&fullScreenCheckbox);

	resolutionLabel.setText("Resolution");
	layout.add(&resolutionLabel);

	resolutionDropdown.addItem("testing1");
	resolutionDropdown.addItem("testing2");
	layout.add(&resolutionDropdown);

	backButton.setText("Back");
	backButton.addActionListener(&buttonListener);
	layout.add(&backButton);
}

void OptionsGUI::ApplyChanges()
{

}

void OptionsButtonListener::actionPerformed(const agui::ActionEvent &evt)
{
	agui::Widget* source = evt.getSource();

	if(source == &backButton)
		gamestate::GameStateManager::PopGameState();
}
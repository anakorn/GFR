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
agui::Button applyChangesButton;
OptionsButtonListener buttonListener;

// Floats (0.0f-1.0f) given as percentages of screen dimensions
const f32 FIRST_COL_X = 0.30f;
const f32 SECOND_COL_X = 0.50f;

const f32 FIRST_ROW_Y = 0.25f;
const f32 ROW_GAP = 0.05f;

OptionsGUI::OptionsGUI()
	: GUIBase()
{

}

OptionsGUI::~OptionsGUI()
{
}

void OptionsGUI::InitializeGUIComponents()
{
	u32 screenWidth = framework::Configuration::GetIntValue("SCREEN", "width");
	u32 screenHeight = framework::Configuration::GetIntValue("SCREEN", "height");

	fullScreenLabel.setText("Fullscreen");
	fullScreenLabel.setLocation(screenWidth * FIRST_COL_X, screenHeight * FIRST_ROW_Y);
	m_GUI->add(&fullScreenLabel);

	fullScreenCheckbox.setChecked(framework::Configuration::GetBoolValue("SCREEN", "fullscreen"));
	fullScreenCheckbox.setLocation(screenWidth * SECOND_COL_X, screenHeight * FIRST_ROW_Y);
	fullScreenCheckbox.setCheckBoxSize(agui::Dimension(ROW_GAP * 0.5f * screenHeight, ROW_GAP * 0.5f * screenHeight));
	fullScreenCheckbox.setAutosizing(true);
	m_GUI->add(&fullScreenCheckbox);

	resolutionLabel.setText("Resolution");
	resolutionLabel.setLocation(screenWidth * FIRST_COL_X, screenHeight * (FIRST_ROW_Y + ROW_GAP));
	m_GUI->add(&resolutionLabel);

	resolutionDropdown.addItem("testing1");
	resolutionDropdown.addItem("testing2");
	resolutionDropdown.setSize(0.1f * screenWidth, ROW_GAP * 0.5f * screenHeight);
	resolutionDropdown.setLocation(screenWidth * SECOND_COL_X, screenHeight * (FIRST_ROW_Y + ROW_GAP));
	m_GUI->add(&resolutionDropdown);

	backButton.setText("Back");
	backButton.addActionListener(&buttonListener);
	backButton.resizeToContents();
	backButton.setLocation(screenWidth * FIRST_COL_X, screenHeight * (FIRST_ROW_Y + 2 * ROW_GAP));
	m_GUI->add(&backButton);

	applyChangesButton.setText("Apply Changes");
	applyChangesButton.addActionListener(&buttonListener);
	applyChangesButton.resizeToContents();
	applyChangesButton.setLocation(screenWidth * SECOND_COL_X, screenHeight * (FIRST_ROW_Y + 2 * ROW_GAP));
	m_GUI->add(&applyChangesButton);
}

void OptionsGUI::ApplyChanges()
{

}

void OptionsButtonListener::actionPerformed(const agui::ActionEvent &evt)
{
	agui::Widget* source = evt.getSource();

	if(source == &backButton)
		gamestate::GameStateManager::PopGameState();
	else if(source == &applyChangesButton)
	{

	}
}
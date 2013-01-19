#include "OptionsGUI.h"
#include <allegro5/allegro5.h>
#include "Configuration.h"
#include "GFR_AL.h"

using namespace game;
using namespace gui;

// Floats (0.0f-1.0f) given as percentages of screen dimensions
const f32 FIRST_COL_X = 0.30f;
const f32 SECOND_COL_X = 0.50f;

const f32 FIRST_ROW_Y = 0.25f;
const f32 ROW_GAP = 0.05f;

OptionsGUI::OptionsGUI()
	: GUIBase(), m_ButtonListener(this)
{

}

OptionsGUI::~OptionsGUI()
{
}

void OptionsGUI::InitializeGUIComponents()
{
	u32 screenWidth = framework::GFR_AL::GetScreenWidth();
	u32 screenHeight = framework::GFR_AL::GetScreenHeight();

	m_FullScreenLabel.setText("Fullscreen");
	m_FullScreenLabel.setLocation(screenWidth * FIRST_COL_X, screenHeight * FIRST_ROW_Y);
	m_GUI->add(&m_FullScreenLabel);

	m_FullScreenCheckbox.setChecked(framework::Configuration::GetBoolValue("SCREEN", "fullscreen"));
	m_FullScreenCheckbox.setLocation(screenWidth * SECOND_COL_X, screenHeight * FIRST_ROW_Y);
	m_FullScreenCheckbox.setCheckBoxSize(agui::Dimension(ROW_GAP * 0.5f * screenHeight, ROW_GAP * 0.5f * screenHeight));
	m_FullScreenCheckbox.setAutosizing(true);
	m_GUI->add(&m_FullScreenCheckbox);

	m_ResolutionLabel.setText("Resolution");
	m_ResolutionLabel.setLocation(screenWidth * FIRST_COL_X, screenHeight * (FIRST_ROW_Y + ROW_GAP));
	m_GUI->add(&m_ResolutionLabel);

	m_ResolutionDropdown.addItem("testing1");
	m_ResolutionDropdown.addItem("testing2");
	m_ResolutionDropdown.setSize(0.1f * screenWidth, ROW_GAP * 0.5f * screenHeight);
	m_ResolutionDropdown.setLocation(screenWidth * SECOND_COL_X, screenHeight * (FIRST_ROW_Y + ROW_GAP));
	m_GUI->add(&m_ResolutionDropdown);

	m_BackButton.setText("Back");
	m_BackButton.addActionListener(&m_ButtonListener);
	m_BackButton.resizeToContents();
	m_BackButton.setLocation(screenWidth * FIRST_COL_X, screenHeight * (FIRST_ROW_Y + 2 * ROW_GAP));
	m_GUI->add(&m_BackButton);

	m_ApplyChangesButton.setText("Apply Changes");
	m_ApplyChangesButton.addActionListener(&m_ButtonListener);
	m_ApplyChangesButton.resizeToContents();
	m_ApplyChangesButton.setLocation(screenWidth * SECOND_COL_X, screenHeight * (FIRST_ROW_Y + 2 * ROW_GAP));
	m_GUI->add(&m_ApplyChangesButton);
}

void OptionsGUI::OptionsButtonListener::ApplyChanges()
{
}

void OptionsGUI::OptionsButtonListener::actionPerformed(const agui::ActionEvent &evt)
{
	agui::Widget* source = evt.getSource();

	if(source == &m_Container->m_BackButton)
		framework::GFR_AL::s_StateManager.PopState();
	else if(source == &m_Container->m_ApplyChangesButton)
		ApplyChanges();
}
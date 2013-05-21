#include "GameplayDebugGUI.h"

using namespace game;
using namespace gui;

GameplayDebugGUI::GameplayDebugGUI(gameState::Gameplay& gameplay)
	: GUIBase(), m_Gameplay(gameplay)
{
};

GameplayDebugGUI::~GameplayDebugGUI()
{

};

void GameplayDebugGUI::InitializeGUIComponents()
{
	m_GUI->add(&layout);

	frameEntities.setSize(220, 300);
	frameEntities.setLocation(60, 60);
	frameEntities.setText("Entities Frame");
	layout.add(&frameEntities);

	createEntityButton.setText("Test Gameplay");
	createEntityButton.resizeToContents();
	createEntityButton.addActionListener(&m_Gameplay);
	frameEntities.add(&createEntityButton);

	optionsButton.setText("Options");
	optionsButton.resizeToContents();
	optionsButton.addActionListener(&m_Gameplay);
	layout.add(&optionsButton);

	backToMenuButton.setText("Back to Menu");
	backToMenuButton.resizeToContents();
	backToMenuButton.addActionListener(&m_Gameplay);
	layout.add(&backToMenuButton);
};
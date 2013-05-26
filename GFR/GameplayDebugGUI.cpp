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

	InitializeFrameEntities();

	buttonBackToMenu.setText("Back to Menu");
	buttonBackToMenu.resizeToContents();
	buttonBackToMenu.addActionListener(&m_Gameplay);
	layout.add(&buttonBackToMenu);
};

void GameplayDebugGUI::InitializeFrameEntities()
{
	frameEntities.setSize(290, 300);
	frameEntities.setLocation(60, 60);
	frameEntities.setText("Entities");
	layout.add(&frameEntities);

	frameEntitiesLayout.setMargins(5, 5, 5, 5);
	frameEntities.add(&frameEntitiesLayout);
	
	labelPosX.setText("X-Pos:");
	frameEntitiesLayout.add(&labelPosX);

	textFieldCreateEntityPosX.setNumeric(true);
	textFieldCreateEntityPosX.setText("0");
	textFieldCreateEntityPosX.setSize(70, 5);
	textFieldCreateEntityPosX.addActionListener(&m_Gameplay);
	frameEntitiesLayout.add(&textFieldCreateEntityPosX);
	
	labelPosY.setText("Y-Pos:");
	frameEntitiesLayout.add(&labelPosY);

	textFieldCreateEntityPosY.setNumeric(true);
	textFieldCreateEntityPosY.setText("0");
	textFieldCreateEntityPosY.setSize(70, 5);
	textFieldCreateEntityPosY.addActionListener(&m_Gameplay);
	frameEntitiesLayout.add(&textFieldCreateEntityPosY);

	buttonCreateEntity.setText("Create");
	buttonCreateEntity.resizeToContents();
	buttonCreateEntity.addActionListener(&m_Gameplay);
	frameEntitiesLayout.add(&buttonCreateEntity);
};
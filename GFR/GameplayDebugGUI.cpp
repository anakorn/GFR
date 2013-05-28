#include "GameplayDebugGUI.h"

using namespace game;
using namespace gui;

GameplayDebugGUI::GameplayDebugGUI(gameState::Gameplay& gameplay) : 
	GUIBase(), 
	m_Gameplay(gameplay), 
	frame_EntitiesWidth(384), 
	frame_EntitiesHeight(600),
	padding(5)
{
};

GameplayDebugGUI::~GameplayDebugGUI()
{

};

void GameplayDebugGUI::InitializeGUIComponents()
{
	layout_Main.setLeftToRight(false);
	m_GUI->add(&layout_Main);

	button_BackToMenu.setText("Back to Menu");
	button_BackToMenu.resizeToContents();
	button_BackToMenu.addActionListener(&m_Gameplay);
	layout_Main.add(&button_BackToMenu);

	InitializeFrameEntities();
};

void GameplayDebugGUI::InitializeFrameEntities()
{
	frame_Entities.setSize(frame_EntitiesWidth, frame_EntitiesHeight);
	frame_Entities.setLocation(60, 60);
	frame_Entities.setMovable(false);
	frame_Entities.setText("Entities");
	layout_Main.add(&frame_Entities);

	layout_FrameEntities.setMargins(padding, padding, padding, padding);
	frame_Entities.add(&layout_FrameEntities);

	// ENTITY CREATION
	
	frame_CreateEntity.setText("Create");
	frame_CreateEntity.setSize(frame_EntitiesWidth - 20, (frame_EntitiesHeight - 55) / 2);
	frame_CreateEntity.setMovable(false);
	layout_FrameEntities.add(&frame_CreateEntity);

	layout_CreateEntity.setMargins(padding, padding, padding, padding);
	frame_CreateEntity.add(&layout_CreateEntity);

	std::vector<std::string> getComponentNames;
	getComponentNames.push_back("Component1");
	getComponentNames.push_back("Component2");
	getComponentNames.push_back("Component3");
	getComponentNames.push_back("Component3");
	getComponentNames.push_back("Component3");
	getComponentNames.push_back("Component3");
	getComponentNames.push_back("Component3");
	getComponentNames.push_back("Component3");

	listBox_CreateEntityComponents.setMultiselectExtended(true);
	listBox_CreateEntityComponents.setSize(frame_EntitiesWidth - 40, (frame_EntitiesHeight - 43) / 4);
	listBox_CreateEntityComponents.addItems(getComponentNames);
	layout_CreateEntity.add(&listBox_CreateEntityComponents);
	
	label_PosX.setText("X:");
	layout_CreateEntity.add(&label_PosX);

	textField_CreateEntityPosX.setNumeric(true);
	textField_CreateEntityPosX.setText("0");
	textField_CreateEntityPosX.setSize(70, 5);
	textField_CreateEntityPosX.addActionListener(&m_Gameplay);
	layout_CreateEntity.add(&textField_CreateEntityPosX);
	
	label_PosY.setText("Y:");
	layout_CreateEntity.add(&label_PosY);

	textField_CreateEntityPosY.setNumeric(true);
	textField_CreateEntityPosY.setText("0");
	textField_CreateEntityPosY.setSize(70, 5);
	textField_CreateEntityPosY.addActionListener(&m_Gameplay);
	layout_CreateEntity.add(&textField_CreateEntityPosY);

	button_CreateEntity.setText("Create");
	button_CreateEntity.resizeToContents();
	button_CreateEntity.addActionListener(&m_Gameplay);
	layout_CreateEntity.add(&button_CreateEntity);

	button_CreateBox.setText("Box");
	button_CreateBox.resizeToContents();
	button_CreateBox.addActionListener(&m_Gameplay);
	layout_CreateEntity.add(&button_CreateBox);

	// ENTITY EDITING
	frame_EditEntity.setText("View/Edit");
	frame_EditEntity.setSize(frame_EntitiesWidth - 20, (frame_EntitiesHeight - 55) / 2);
	frame_EditEntity.setMovable(false);
	layout_FrameEntities.add(&frame_EditEntity);

	layout_EditEntity.setMargins(padding, padding, padding, padding);
	frame_EditEntity.add(&layout_EditEntity);

};
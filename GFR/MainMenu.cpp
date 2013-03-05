#include "MainMenu.h"
#include "MainMenuGUI.h"

// BEGIN TEMP
#include "Common.h"
#include "GFR_AL.h"
#include "ContentMgr.h"
#include "PhysicsComponent.h"
#include "DrawComponent.h"
// END TEMP

using namespace game;
using namespace gameState;
using namespace framework;

MainMenu::MainMenu()
	: State(stateTypes::MAIN_MENU)
{
	m_Gui = new gui::MainMenuGUI();
	m_Gui->InitializeGUIComponents();

	m_PhysMgr.CreateWorld(0, 9.8f, true);

	Entity* ent = new Entity();
	ent->AttachComponent("PhysicsComponent");
	ent->AttachComponent("DrawComponent");

	static_cast<PhysicsComponent*>(ent->GetComponent("PhysicsComponent"))->SetBody(
		m_PhysMgr.CreateDynamicBody(0, 0, 0, 0, 0, 1.0f, true, true, true));
	static_cast<DrawComponent*>(ent->GetComponent("DrawComponent"))->SetTexture(
		*ContentMgr::LoadContent<Texture>("test.png"));

	m_Entities.push_back(*ent);
};

void MainMenu::Update()
{
	FOR_EACH(it, m_Entities)
	{
		m_ControlSystem.ProcessEntity(*it);
	}

	m_PhysMgr.Update(GFR_AL::GetUpdateRate());
	State::Update();
};

void MainMenu::Render()
{
	
	FOR_EACH(it, m_Entities)
	{
		m_MovementSystem.ProcessEntity(*it);
	}

	State::Render();
};
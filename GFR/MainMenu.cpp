#include "MainMenu.h"
#include "MainMenuGUI.h"

using namespace game;
using namespace gameState;

MainMenu::MainMenu()
	: State(stateTypes::MAIN_MENU)
{
	m_Gui = new gui::MainMenuGUI();
	m_Gui->InitializeGUIComponents();


}

void MainMenu::Update()
{
	

	State::Update();
}

void MainMenu::Render()
{
	

	State::Render();
}
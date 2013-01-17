#include "MainMenu.h"
#include "MainMenuGUI.h"

using namespace gamestate;

MainMenu::MainMenu()
	: GameState(StateTypes::MAIN_MENU)
{
	m_Gui = new gui::MainMenuGUI();
	m_Gui->InitializeGUIComponents();
}
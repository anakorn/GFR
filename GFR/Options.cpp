#include "Options.h"
#include "OptionsGUI.h"

using namespace gamestate;

Options::Options()
	: GameState(StateTypes::OPTIONS)
{
	m_Gui = new gui::OptionsGUI();
	m_Gui->InitializeGUIComponents();
}
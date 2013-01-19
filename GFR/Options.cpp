#include "Options.h"
#include "OptionsGUI.h"

using namespace game;
using namespace gameState;

Options::Options()
	: State(stateTypes::OPTIONS)
{
	m_Gui = new gui::OptionsGUI();
	m_Gui->InitializeGUIComponents();
}
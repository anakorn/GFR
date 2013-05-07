#include "State.h"

using namespace game;
using namespace gameState;

State::State(stateTypes::Type type)
	: m_StateType(type)
{

}

State::~State()
{
	delete m_Gui;
}

stateTypes::Type State::GetStateType()
{
	return m_StateType;
}

void State::ProcessEvent(ALLEGRO_EVENT event)
{
	if (m_Gui)
		m_Gui->ProcessEvent(event);
}

void State::Update()
{
	m_Gui->Update();
}

void State::Render()
{
	m_Gui->Render();
}
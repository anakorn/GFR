#include "GameState.h"

using namespace gamestate;

GameState::GameState(StateTypes::State type)
	: m_StateType(type)
{

}

GameState::~GameState()
{
	delete m_Gui;
}

StateTypes::State GameState::GetStateType()
{
	return m_StateType;
}

void GameState::Update()
{
	m_Gui->Update();
}

void GameState::Render()
{
	m_Gui->Render();
}
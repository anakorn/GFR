#include "GameStateManager.h"
#include "MainMenu.h"
#include <vector>

using namespace gamestate;

std::vector<GameState*> m_ActiveStates;

GameStateManager::GameStateManager()
{

}

GameStateManager::~GameStateManager()
{

}

GameState* GameStateManager::LoadGameState(StateTypes::State type)
{
	GameState* gameState = NULL;

	// Create new game state here
	switch(type)
	{
	case StateTypes::MAIN_MENU:
		gameState = new MainMenu();
		break;
	case StateTypes::LOBBY:
		break;
	case StateTypes::OPTIONS:
		break;
	case StateTypes::GAMEPLAY:
		break;
	case StateTypes::PAUSE:
		break;
	default:
		break;
	}

	return gameState;
}

void GameStateManager::SetGameState(StateTypes::State type)
{
	for (std::vector<GameState*>::iterator it = m_ActiveStates.begin(); it != m_ActiveStates.end(); ++it)
	{
		delete *it;
		m_ActiveStates.erase(it);
	}

	PushGameState(type);
}

void GameStateManager::PushGameState(StateTypes::State type)
{
	GameState* state = LoadGameState(type);
	m_ActiveStates.push_back(state);
}

// Max active states at any given time is probably 2
// so O(n) search to delete is ok(maybe even fastest)
void GameStateManager::RemoveGameState(StateTypes::State type)
{
	for (std::vector<GameState*>::iterator it = m_ActiveStates.begin(); it != m_ActiveStates.end(); ++it)
	{
		if((*it)->GetStateType() == type)
		{
			delete *it;
			m_ActiveStates.erase(it);
			return;
		}
	}
}

void GameStateManager::Update()
{
	for (std::vector<GameState*>::iterator it = m_ActiveStates.begin(); it != m_ActiveStates.end(); ++it)
	{
		(*it)->Update();
	}
}

void GameStateManager::Render()
{
	for (std::vector<GameState*>::iterator it = m_ActiveStates.begin(); it != m_ActiveStates.end(); ++it)
	{
		(*it)->Render();
	}
}
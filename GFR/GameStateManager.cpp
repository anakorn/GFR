#include "GameStateManager.h"
#include "MainMenu.h"
#include "Options.h"
#include <vector>

using namespace gamestate;

static std::vector<GameState*> s_ActiveStates;
static std::queue<StateTypes::State> s_RemovedStates;
static StateTypes::State s_SetState;

GameStateManager::GameStateManager()
{
	s_SetState = StateTypes::NONE;
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
	case StateTypes::SERVER_LOBBY:
		break;
	case StateTypes::CLIENT_LOBBY:
		break;
	case StateTypes::OPTIONS:
		gameState = new Options();
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
	for (auto it = s_ActiveStates.begin(); it != s_ActiveStates.end(); ++it)
	{
		s_RemovedStates.push((*it)->GetStateType());
	}

	s_SetState = type;
}

void GameStateManager::PushGameState(StateTypes::State type)
{
	if(s_SetState != StateTypes::NONE || s_ActiveStates.size() == 0)
	{
		GameState* state = LoadGameState(type);
		s_ActiveStates.push_back(state);
		s_SetState = StateTypes::NONE;
	}
	else
		s_SetState = type;
}

void GameStateManager::PopGameState()
{
	s_RemovedStates.push(s_ActiveStates.back()->GetStateType());
}

void GameStateManager::RemoveGameState(StateTypes::State type)
{
	s_RemovedStates.push(type);
}

// Max active states at any given time is probably 2
// so O(n) search to delete is ok(maybe even fastest)
void GameStateManager::RemoveStateProcess(StateTypes::State type)
{
	std::vector<GameState*>::iterator it = s_ActiveStates.begin();
	while (it != s_ActiveStates.end())
	{
		if((*it)->GetStateType() == type)
		{
			delete *it;
			it = s_ActiveStates.erase(it);
		}
		else
			++it;
	}
}

// Only top active state gets input
void GameStateManager::ProcessEvent(ALLEGRO_EVENT event)
{
	s_ActiveStates.back()->ProcessEvent(event);
}

void GameStateManager::Update()
{
	while(s_RemovedStates.size() > 0)
	{
		RemoveStateProcess(s_RemovedStates.front());
		s_RemovedStates.pop();
	}

	if(s_SetState != StateTypes::NONE)
		PushGameState(s_SetState);

	for (auto it = s_ActiveStates.begin(); it != s_ActiveStates.end(); ++it)
	{
		(*it)->Update();
	}
}

void GameStateManager::Render()
{
	s_ActiveStates.back()->Render();
}
#include "GameStateManager.h"
#include "MainMenu.h"
#include "ClientLobby.h"
#include "ClientLobbySetup.h"
#include "ServerLobby.h"
#include "ServerLobbySetup.h"
#include "Options.h"
#include <vector>

using namespace gamestate;

std::vector<GameState*> m_ActiveStates;
std::queue<StateTypes::State> m_RemovedStates;
std::queue<GameState*> m_StatesToAdd;

GameStateManager::GameStateManager()
{
}

GameStateManager::~GameStateManager()
{

}

GameState* GameStateManager::LoadGameState(StateTypes::State type, std::vector<void*> args)
{
	GameState* gameState = NULL;

	// Create new game state here
	switch (type)
	{
	case StateTypes::MAIN_MENU:
		gameState = new MainMenu();
		break;
	case StateTypes::SERVER_LOBBY:
		{
			u32 port = *static_cast<u32*>(args[0]);
			char* gameName = static_cast<char*>(args[1]);
			gameState = new ServerLobby(port, gameName);
		}
		break;
	case StateTypes::SERVER_LOBBY_SETUP:
		gameState = new ServerLobbySetup();
		break;
	case StateTypes::CLIENT_LOBBY:
		{
			char* ip = static_cast<char*>(args[0]);
			u32 port = *static_cast<u32*>(args[1]);
			gameState = new ClientLobby(ip, port);
		}
		break;
	case StateTypes::CLIENT_LOBBY_SETUP:
		gameState = new ClientLobbySetup();
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

void GameStateManager::SetGameState(StateTypes::State type, std::vector<void*> args)
{
	for (auto it = m_ActiveStates.begin(); it != m_ActiveStates.end(); ++it)
	{
		m_RemovedStates.push((*it)->GetStateType());
	}

	GameState* state = LoadGameState(type, args);
	m_StatesToAdd.push(state);
}

void GameStateManager::PushGameState(StateTypes::State type, std::vector<void*> args)
{
	GameState* state = LoadGameState(type, args);
	if (m_ActiveStates.size())
		m_StatesToAdd.push(state);
	else
		m_ActiveStates.push_back(state);
}

void GameStateManager::PopGameState()
{
	m_RemovedStates.push(m_ActiveStates.back()->GetStateType());
}

void GameStateManager::RemoveGameState(StateTypes::State type)
{
	m_RemovedStates.push(type);
}

// Max active states at any given time is probably 2
// so O(n) search to delete is ok(maybe even fastest)
void GameStateManager::RemoveStateProcess(StateTypes::State type)
{
	auto it = m_ActiveStates.begin();
	while (it != m_ActiveStates.end())
	{
		if ((*it)->GetStateType() == type)
		{
			delete *it;
			it = m_ActiveStates.erase(it);
			return;
		}
		else
			++it;
	}
}

// Only top active state gets input
void GameStateManager::ProcessEvent(ALLEGRO_EVENT event)
{
	m_ActiveStates.back()->ProcessEvent(event);
}

void GameStateManager::Update()
{
	while (m_RemovedStates.size() > 0)
	{
		RemoveStateProcess(m_RemovedStates.front());
		m_RemovedStates.pop();
	}

	while (m_StatesToAdd.size() > 0)
	{
		m_ActiveStates.push_back(m_StatesToAdd.front());
		m_StatesToAdd.pop();
	}

	for (auto it = m_ActiveStates.begin(); it != m_ActiveStates.end(); ++it)
	{
		(*it)->Update();
	}
}

void GameStateManager::Render()
{
	m_ActiveStates.back()->Render();
}
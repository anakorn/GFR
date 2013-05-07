#include "StateManager.h"
#include "MainMenu.h"
#include "ClientLobby.h"
#include "ClientLobbySetup.h"
#include "ServerLobby.h"
#include "ServerLobbySetup.h"
#include "Options.h"
#include "Gameplay.h"
#include "PlayableCharacter.h"
#include <vector>

using namespace game;
using namespace gameState;

std::vector<State*> m_ActiveStates;
std::queue<stateTypes::Type> m_RemovedStates;
std::queue<State*> m_StatesToAdd;

StateManager::StateManager()
{
}

StateManager::~StateManager()
{

}

State* StateManager::LoadState(game::stateTypes::Type type, std::vector<void*> args)
{
	State* State = NULL;

	// Create new game state here
	switch (type)
	{
	case game::stateTypes::MAIN_MENU:
		State = new MainMenu();
		break;
	case game::stateTypes::SERVER_LOBBY:
		{
			u32 port = *static_cast<u32*>(args[0]);
			char* gameName = static_cast<char*>(args[1]);
			State = new ServerLobby(port, gameName);
		}
		break;
	case game::stateTypes::SERVER_LOBBY_SETUP:
		State = new ServerLobbySetup();
		break;
	case game::stateTypes::CLIENT_LOBBY:
		{
			char* ip = static_cast<char*>(args[0]);
			u32 port = *static_cast<u32*>(args[1]);
			State = new ClientLobby(ip, port);
		}
		break;
	case game::stateTypes::CLIENT_LOBBY_SETUP:
		State = new ClientLobbySetup();
		break;
	case game::stateTypes::OPTIONS:
		State = new Options();
		break;
	case game::stateTypes::GAMEPLAY:
		{
			//characters::Class playerClass = *static_cast<characters::Class*>(args[0]);
			State = new Gameplay(characters::Class::ENGINEER);
			break;
		}
	case game::stateTypes::PAUSE:
		break;
	default:
		break;
	}

	return State;
}

void StateManager::SetState(game::stateTypes::Type type, std::vector<void*> args)
{
	for (auto it = m_ActiveStates.begin(); it != m_ActiveStates.end(); ++it)
	{
		m_RemovedStates.push((*it)->GetStateType());
	}

	PushState(type, args);
}

void StateManager::PushState(game::stateTypes::Type type, std::vector<void*> args)
{
	State* state = LoadState(type, args);
	if (!m_ActiveStates.empty())
		m_StatesToAdd.push(state);
	else
		m_ActiveStates.push_back(state);
}

void StateManager::PopState()
{
	m_RemovedStates.push(m_ActiveStates.back()->GetStateType());
}

void StateManager::RemoveState(game::stateTypes::Type type)
{
	m_RemovedStates.push(type);
}

// Max active states at any given time is probably 2
// so O(n) search to delete is ok(maybe even fastest)
void StateManager::RemoveStateProcess(game::stateTypes::Type type)
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
void StateManager::ProcessEvent(ALLEGRO_EVENT event)
{
	if (!m_ActiveStates.empty())
		m_ActiveStates.back()->ProcessEvent(event);
}

void StateManager::Update()
{
	while (!m_RemovedStates.empty())
	{
		RemoveStateProcess(m_RemovedStates.front());
		m_RemovedStates.pop();
	}

	while (!m_StatesToAdd.empty())
	{
		m_ActiveStates.push_back(m_StatesToAdd.front());
		m_StatesToAdd.pop();
	}

	for (auto it = m_ActiveStates.begin(); it != m_ActiveStates.end(); ++it)
	{
		(*it)->Update();
	}
}

void StateManager::Render()
{
	m_ActiveStates.back()->Render();
}
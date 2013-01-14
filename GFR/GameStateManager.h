#pragma once
#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

#include "GameState.h"
#include "States.h"

namespace gamestate
{
	class GameStateManager
	{
	public:
		GameStateManager();
		~GameStateManager();

		// Loads state and removes all other active states
		void SetGameState(StateTypes::State type, std::vector<void*> args);
		// Loads state and places it on top of all other active states
		void PushGameState(StateTypes::State type, std::vector<void*> args);
		// Removes the top-most state
		void PopGameState();
		void RemoveGameState(StateTypes::State type);

		void ProcessEvent(ALLEGRO_EVENT event);
		void Update();
		void Render();
	private:
		GameState* LoadGameState(StateTypes::State type, std::vector<void*> args);
		void RemoveStateProcess(StateTypes::State type);
	};
};

#endif
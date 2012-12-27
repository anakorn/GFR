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
		void SetGameState(StateTypes::State type);
		// Loads state and places it on top of all other active states
		void PushGameState(StateTypes::State type);
		void RemoveGameState(StateTypes::State type);

		void Update();
		void Render();
	private:
		GameState* LoadGameState(StateTypes::State type);
	};
};

#endif
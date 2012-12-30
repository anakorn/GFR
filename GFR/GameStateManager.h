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
		static void SetGameState(StateTypes::State type);
		// Loads state and places it on top of all other active states
		static void PushGameState(StateTypes::State type);
		// Removes the top-most state
		static void PopGameState();
		static void RemoveGameState(StateTypes::State type);

		void ProcessEvent(ALLEGRO_EVENT event);
		void Update();
		void Render();
	private:
		static GameState* LoadGameState(StateTypes::State type);
		static void RemoveStateProcess(StateTypes::State type);
	};
};

#endif
#pragma once
#ifndef GFR_GAME_GAMESTATE_STATEMANAGER_H
#define gameStateMANAGER_H

#include "State.h"
#include "StateTypes.h"

namespace game
{
	namespace gameState
	{
		class StateManager
		{
		public:
			StateManager();
			~StateManager();

			// Loads state and removes all other active states
			void SetState(stateTypes::Type type, std::vector<void*> args = std::vector<void*>());
			// Loads state and places it on top of all other active states
			void PushState(stateTypes::Type type, std::vector<void*> args = std::vector<void*>());
			// Removes the top-most state
			void PopState();
			void RemoveState(stateTypes::Type type);

			void ProcessEvent(ALLEGRO_EVENT event);
			void Update();
			void Render();

		private:
			State* LoadState(stateTypes::Type type, std::vector<void*> args);
			void RemoveStateProcess(stateTypes::Type type);
		};
	};
};

#endif
#ifndef GFR_GAME_GAMESTATE_STATES_MAINMENU_H
#define GFR_GAME_GAMESTATE_STATES_MAINMENU_H

#include "State.h"

// BEGIN TEMP
#include "PhysicsMgr.h"
#include "Entity.h"
#include "PhysicsComponent.h"
// END TEMP

namespace game
{
	namespace gameState
	{
		class MainMenu : public State
		{
		public:
			MainMenu();
			~MainMenu();

			virtual void Update();
			virtual void Render();

		private:
			//Physics

		};
	};
};

#endif
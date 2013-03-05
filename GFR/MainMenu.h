#ifndef GFR_GAME_GAMESTATE_STATES_MAINMENU_H
#define GFR_GAME_GAMESTATE_STATES_MAINMENU_H

#include "State.h"

// BEGIN TEMP
#include "PhysicsMgr.h"
#include "Entity.h"
#include "MovementSystem.h"
#include "ControlSystem.h"
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
			framework::ControlSystem		m_ControlSystem;
			framework::MovementSystem		m_MovementSystem;
			framework::PhysicsMgr			m_PhysMgr;
			std::list <framework::Entity>	m_Entities;

		};
	};
};

#endif
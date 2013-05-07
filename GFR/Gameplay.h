#ifndef GFR_GAME_GAMESTATE_GAMEPLAY_H
#define GFR_GAME_GAMESTATE_GAMEPLAY_H

#include "State.h"
#include "PlayableCharacter.h"
#include "PhysicsMgr.h"
#include "Entity.h"
#include "MovementSystem.h"
#include "ControlSystem.h"
#include "Camera.h"

namespace game
{
	namespace gameState
	{
		class Gameplay : public State
		{
		public:
			Gameplay(characters::Class playerCharacter);
			~Gameplay();

			virtual void Update() override;
			virtual void Render() override;

		private:
			framework::ControlSystem		m_ControlSystem;
			framework::MovementSystem		m_MovementSystem;
			framework::PhysicsMgr			m_PhysMgr;
			std::list <framework::Entity>	m_Entities;
			framework::Camera				m_Camera;
		};
	};
};

#endif
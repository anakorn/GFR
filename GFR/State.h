#pragma once
#ifndef GFR_GAME_GAMESTATE_STATE_H
#define gameState_H

#include "StateTypes.h"
#include "GUIBase.h"

namespace game
{
	namespace gameState
	{
		class State
		{
		public:
			State(stateTypes::Type type);
			~State();

			stateTypes::Type GetStateType();

			void ProcessEvent(ALLEGRO_EVENT event);
			// Make base calls to these functions LAST
			// when overriding so that GUI gets drawn on top
			virtual void Update();
			virtual void Render();

		protected:
			stateTypes::Type m_StateType;
			gui::GUIBase* m_Gui;
		};
	};
};

#endif
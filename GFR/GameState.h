#pragma once
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "States.h"
#include "GUIBase.h"

namespace gamestate
{
	class GameState
	{
	public:
		GameState(StateTypes::State type);
		~GameState();

		StateTypes::State GetStateType();

		void ProcessEvent(ALLEGRO_EVENT event);
		// Make base calls to these functions LAST
		// when overriding so that GUI gets drawn on top
		virtual void Update();
		virtual void Render();
	protected:
		StateTypes::State m_StateType;
		gui::GUIBase* m_Gui;
	};
};

#endif
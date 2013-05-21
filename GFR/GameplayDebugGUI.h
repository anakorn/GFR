#ifndef GFR_GAME_GUI_GUIS_GAMEPLAYDEBUGGUI_H
#define GFR_GAME_GUI_GUIS_GAMEPLAYDEBUGGUI_H

#include "GUIBase.h"
#include <Agui/FlowLayout.hpp>
#include <Agui/Widgets/TextField/TextField.hpp>
#include <Agui/Widgets/Frame/Frame.hpp>
#include <Agui/Widgets/Button/Button.hpp>
#include "Gameplay.h"

namespace game
{
	namespace gui
	{
		class GameplayDebugGUI : public GUIBase
		{
		public:
			GameplayDebugGUI(gameState::Gameplay& gameplay);
			~GameplayDebugGUI();

			void InitializeGUIComponents() override;
			
			agui::FlowLayout layout;

			agui::Frame frameEntities;
			
			agui::Button createEntityButton;
			agui::Button optionsButton;
			agui::Button backToMenuButton;

		private:
			gameState::Gameplay& m_Gameplay;

		};
	};
};

#endif
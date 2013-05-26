#ifndef GFR_GAME_GUI_GUIS_GAMEPLAYDEBUGGUI_H
#define GFR_GAME_GUI_GUIS_GAMEPLAYDEBUGGUI_H

#include "GUIBase.h"
#include <Agui/FlowLayout.hpp>
#include <Agui/Widgets/Frame/Frame.hpp>
#include <Agui/Widgets/TextField/TextField.hpp>
#include <Agui/Widgets/Label/Label.hpp>
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
			void InitializeFrameEntities();
			
			agui::FlowLayout layout;
			
			/* ENTITIES BEGIN */
			agui::Frame frameEntities;
			agui::FlowLayout frameEntitiesLayout;
			agui::Button buttonCreateEntity;
			agui::Label labelPosX;
			agui::TextField textFieldCreateEntityPosX;
			agui::Label labelPosY;
			agui::TextField textFieldCreateEntityPosY;
			/* ENTITIES END */

			/* SELECTION BEGIN */
			agui::Frame frameSelection;
			/* SELECTION END */

			agui::Button buttonBackToMenu;

		private:
			gameState::Gameplay& m_Gameplay;

		};
	};
};

#endif
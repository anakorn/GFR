#ifndef GFR_GAME_GUI_GUIS_GAMEPLAYDEBUGGUI_H
#define GFR_GAME_GUI_GUIS_GAMEPLAYDEBUGGUI_H

#include "GUIBase.h"
#include <Agui/FlowLayout.hpp>
#include <Agui/Widgets/Frame/Frame.hpp>
#include <Agui/Widgets/TextField/TextField.hpp>
#include <Agui/Widgets/ListBox/ListBox.hpp>
#include <Agui/Widgets/ScrollBar/VScrollBar.hpp>
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
			
			agui::FlowLayout layout_Main;
			
			/* ENTITIES BEGIN */
			agui::Frame frame_Entities;
			agui::FlowLayout layout_FrameEntities;

			// ENTITY CREATION
			agui::Frame frame_CreateEntity;
			agui::FlowLayout layout_CreateEntity;

			agui::ListBox listBox_CreateEntityComponents;
			agui::VScrollBar vScrollBar_CreateEntityComponents;

			agui::Label label_PosX;
			agui::TextField textField_CreateEntityPosX;
			agui::Label label_PosY;
			agui::TextField textField_CreateEntityPosY;
			
			agui::Button button_CreateEntity;
			agui::Button button_CreateBox;

			// ENTITY EDITING
			agui::Frame frame_EditEntity;
			agui::FlowLayout layout_EditEntity;

			/* ENTITIES END */

			agui::Button button_BackToMenu;

		private:
			gameState::Gameplay& m_Gameplay;
			
			const u32 frame_EntitiesWidth;
			const u32 frame_EntitiesHeight;
			const u32 padding;

		};
	};
};

#endif
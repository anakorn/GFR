#ifndef GFR_GAME_GUI_GUIS_MAINMENUGUI_H
#define GFR_GAME_GUI_GUIS_MAINMENUGUI_H

#include "GUIBase.h"
#include <Agui/FlowLayout.hpp>
#include <Agui/Widgets/TextField/TextField.hpp>
#include <Agui/Widgets/Frame/Frame.hpp>
#include <Agui/Widgets/Button/Button.hpp>

namespace game
{
	namespace gui
	{
		class MainMenuGUI : public GUIBase
		{
		public:
			MainMenuGUI();
			~MainMenuGUI();

			void InitializeGUIComponents() override;
		private:
			agui::FlowLayout layout;
			agui::TextField textField;
			agui::Frame frame;
		};
	};
};

#endif
#ifndef GFR_GAME_GUI_GUIS_SERVERLOBBYSETUPGUI_H
#define GFR_GAME_GUI_GUIS_SERVERLOBBYSETUPGUI_H

#include "GUIBase.h"
#include <Agui/Widgets/TextField/TextField.hpp>
#include <Agui/Widgets/Label/Label.hpp>
#include <Agui/Widgets/Button/Button.hpp>

namespace game
{
	namespace gui
	{
		class ServerLobbySetupGUI : public GUIBase
		{
		public:
			ServerLobbySetupGUI();
			~ServerLobbySetupGUI();

			void InitializeGUIComponents() override;

			class SetupButtonListener : public agui::ActionListener
			{
			public:
				SetupButtonListener() {}
				SetupButtonListener(ServerLobbySetupGUI* container)
					: m_Container(container) {}
				virtual void actionPerformed(const agui::ActionEvent &evt) override;
				bool ValidateInput(const int &port);
			private:
				ServerLobbySetupGUI* m_Container;
			};

		private:
			ServerLobbySetupGUI::SetupButtonListener m_ButtonListener;

			agui::Label m_GameNameLabel;
			agui::TextField m_GameNameField;
			agui::Label m_PortLabel;
			agui::TextField m_PortField;

			agui::Button m_OkButton;
			agui::Button m_BackButton;

			void ShowErrorMessage(const std::string &message);
		};
	};
};

#endif
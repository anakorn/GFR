#pragma once
#ifndef CLIENTLOBBYSETUPGUI_H
#define CLIENTLOBBYSETUPGUI_H

#include "GUIBase.h"
#include <Agui/Widgets/TextField/TextField.hpp>
#include <Agui/Widgets/Label/Label.hpp>
#include <Agui/Widgets/Button/Button.hpp>

namespace gui
{
	class ClientLobbySetupGUI : public GUIBase
	{
	public:
		ClientLobbySetupGUI();
		~ClientLobbySetupGUI();

		void InitializeGUIComponents() override;

		class SetupButtonListener : public agui::ActionListener
		{
		public:
			SetupButtonListener() {}
			SetupButtonListener(ClientLobbySetupGUI* container)
				: m_Container(container) {}
			virtual void actionPerformed(const agui::ActionEvent &evt) override;
			bool ValidateInput(const std::string &ip, const int &port);
		private:
			ClientLobbySetupGUI* m_Container;
		};
	private:
		ClientLobbySetupGUI::SetupButtonListener m_ButtonListener;
		agui::Label m_IPLabel;
		agui::TextField m_IPField;
		agui::Label m_PortLabel;
		agui::TextField m_PortField;

		agui::Button m_OkButton;
		agui::Button m_BackButton;

		void ShowErrorMessage(const std::string &message);
	};
};

#endif
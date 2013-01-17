#pragma once
#ifndef SERVERLOBBYGUI_H
#define SERVERLOBBYGUI_H

#include "NetServer.h"
#include "GUIBase.h"

namespace gui
{
	class ServerLobbyGUI : public GUIBase
	{
	public:
		ServerLobbyGUI(networking::NetServer &server);
		~ServerLobbyGUI();

		void InitializeGUIComponents() override;
		void Update() override;
	private:
		networking::NetServer m_Server;
	};
};

#endif
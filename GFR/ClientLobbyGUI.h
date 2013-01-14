#pragma once
#ifndef CLIENTLOBBYGUI_H
#define CLIENTLOBBYGUI_H

#include "NetClient.h"
#include "GUIBase.h"

namespace gui
{
	class ClientLobbyGUI : public GUIBase
	{
	public:
		ClientLobbyGUI(networking::NetClient &client);
		~ClientLobbyGUI();

		void InitializeGUIComponents() override;
		void Update() override;
	private:
		networking::NetClient m_Client;
	};
};

#endif
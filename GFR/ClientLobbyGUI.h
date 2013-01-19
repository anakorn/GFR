#ifndef GFR_GAME_GUI_GUIS_CLIENTLOBBYGUI_H
#define GFR_GAME_GUI_GUIS_CLIENTLOBBYGUI_H

#include "NetClient.h"
#include "GUIBase.h"

namespace game
{
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
};

#endif
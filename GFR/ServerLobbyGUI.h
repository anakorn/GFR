#ifndef GFR_GAME_GUI_GUIS_SERVERLOBBYGUI_H
#define GFR_GAME_GUI_GUIS_SERVERLOBBYGUI_H

#include "NetServer.h"
#include "GUIBase.h"

namespace game
{
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
};

#endif
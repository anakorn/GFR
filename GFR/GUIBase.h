/*
*GUIBase:
*Abstract class for all GUI sets.
*Contains and manages all GUI components for a screen.
*Each screen needs its own GUIBase.
*/

#ifndef GFR_GAME_GUI_GUIBASE_H
#define GFR_GAME_GUI_GUIBASE_H

#include "Common.h"
#include <Agui/Agui.hpp>
#include <Agui/Backends/Allegro5/Allegro5.hpp>

namespace game
{
	namespace gui
	{
		class GUIBase
		{
		public:
			GUIBase();
			virtual ~GUIBase();

			// Add all initial components to the GUI here
			virtual void InitializeGUIComponents() = 0;

			void AddWidget(agui::Widget* widget);
			void RemoveWidget(agui::Widget* widget);

			void ProcessEvent(ALLEGRO_EVENT event);
			virtual void Update();
			void Render();
		protected:
			agui::Gui*				m_GUI;
			agui::Allegro5Input*	m_InputHandler;
			agui::Allegro5Graphics* m_GraphicsHandler;
		};
	};
};

#endif
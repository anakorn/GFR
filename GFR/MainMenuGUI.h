#pragma once
#ifndef MAINMENUGUI_H
#define MAINMENUGUI_H

#include "GUIBase.h"

namespace gui
{
	class MainMenuGUI : public GUIBase
	{
	public:
		MainMenuGUI();
		~MainMenuGUI();

		void InitializeGUIComponents() override;
	};

	class GFButtonListener : public agui::ActionListener
	{
	public:
		virtual void actionPerformed(const agui::ActionEvent &evt) override;
	};

};

#endif
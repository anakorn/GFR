#pragma once
#ifndef MAINMENUGUI_H
#define MAINMENUGUI_H

#include "GUIBase.h"
#include <Agui/FlowLayout.hpp>
#include <Agui/Widgets/TextField/TextField.hpp>
#include <Agui/Widgets/Frame/Frame.hpp>
#include <Agui/Widgets/Button/Button.hpp>

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

#endif
#pragma once
#ifndef OPTIONSGUI_H
#define OPTIONSGUI_H

#include "GUIBase.h"
#include "Agui/GridLayout.hpp"
#include "Agui/Widgets/Label/Label.hpp"
#include "Agui/Widgets/CheckBox/CheckBox.hpp"
#include "Agui/Widgets/DropDown/DropDown.hpp"
#include "Agui/Widgets/Button/Button.hpp"

namespace gui
{

	class OptionsGUI : public GUIBase
	{
	public:
		OptionsGUI();
		~OptionsGUI();

		void InitializeGUIComponents() override;
	private:
		agui::GridLayout layout;

		agui::Label fullScreenLabel;
		agui::CheckBox fullScreenCheckbox;

		agui::Label resolutionLabel;
		agui::DropDown resolutionDropdown;

		void ApplyChanges();
	};
};

#endif
#pragma once
#ifndef OPTIONSGUI_H
#define OPTIONSGUI_H

#include "GUIBase.h"
#include <Agui/Widgets/Label/Label.hpp>
#include <Agui/Widgets/CheckBox/CheckBox.hpp>
#include <Agui/Widgets/DropDown/DropDown.hpp>
#include <Agui/Widgets/Button/Button.hpp>

namespace gui
{

	class OptionsGUI : public GUIBase
	{
	public:
		OptionsGUI();
		~OptionsGUI();

		void InitializeGUIComponents() override;

		class OptionsButtonListener : public agui::ActionListener
		{
		public:
			OptionsButtonListener() {}
			OptionsButtonListener(OptionsGUI* container)
				: m_Container(container) {}
			virtual void actionPerformed(const agui::ActionEvent &evt) override;
		private:
			OptionsGUI* m_Container;
			void ApplyChanges();
		};
	private:
		agui::Label m_FullScreenLabel;
		agui::CheckBox m_FullScreenCheckbox;

		agui::Label m_ResolutionLabel;
		agui::DropDown m_ResolutionDropdown;

		agui::Button m_BackButton;
		agui::Button m_ApplyChangesButton;
		OptionsButtonListener m_ButtonListener;
	};
};

#endif
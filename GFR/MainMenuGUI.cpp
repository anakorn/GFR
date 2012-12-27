#include "MainMenuGUI.h"
#include "Agui/FlowLayout.hpp"
#include "Agui/Widgets/TextField/TextField.hpp"
#include "Agui/Widgets/Frame/Frame.hpp"

using namespace gui;

agui::FlowLayout* layout;
agui::TextField* textField;
agui::Frame* frame;

MainMenuGUI::MainMenuGUI()
	: GUIBase()
{

}

MainMenuGUI::~MainMenuGUI()
{
	delete layout;
	delete textField;
	delete frame;
}

void MainMenuGUI::InitializeGUIComponents()
{
	layout = new agui::FlowLayout();
	m_GUI->add(layout);

	textField = new agui::TextField();
	textField->setText("Textfield testing");
	textField->setBackColor(agui::Color(255, 255, 255));
	textField->setReadOnly(false);
	textField->resizeToContents();
	layout->add(textField);

	frame = new agui::Frame();
	frame->setSize(220,120);
	frame->setLocation(60,60);
	frame->setText("Example Frame");
	layout->add(frame);
}
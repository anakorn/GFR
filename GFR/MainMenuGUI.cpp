#include "MainMenuGUI.h"
#include "Agui/FlowLayout.hpp"
#include "Agui/Widgets/TextField/TextField.hpp"
#include "Agui/Widgets/Frame/Frame.hpp"
#include "Agui/Widgets/Button/Button.hpp"

using namespace gui;

agui::FlowLayout* layout;
agui::TextField* textField;
agui::Frame* frame;

agui::Button* optionsButton;
agui::Button* exitButton;

GFButtonListener buttonListener;

MainMenuGUI::MainMenuGUI()
	: GUIBase()
{

}

MainMenuGUI::~MainMenuGUI()
{
	delete layout;
	delete textField;
	delete frame;

	delete optionsButton;
	delete exitButton;
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

	optionsButton = new agui::Button();
	optionsButton->setSize(300, 100);
	optionsButton->setText("Options");
	optionsButton->addActionListener(&buttonListener);
	layout->add(optionsButton);

	exitButton = new agui::Button();
	exitButton->setSize(300, 100);
	exitButton->setText("Exit");
	exitButton->addActionListener(&buttonListener);
	layout->add(exitButton);
}

void GFButtonListener::actionPerformed(const agui::ActionEvent &evt)
{
	agui::Widget* source = evt.getSource();

	if(source == optionsButton)
	{

	}
	else if(source == exitButton)
	{
		exit(0);
	}
}
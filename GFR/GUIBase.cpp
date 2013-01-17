#include "GUIBase.h"

using namespace gui;

GUIBase::GUIBase()
{
	m_InputHandler = new agui::Allegro5Input();
	m_GraphicsHandler = new agui::Allegro5Graphics();

	m_GUI = new agui::Gui();
	m_GUI->setInput(m_InputHandler);
	m_GUI->setGraphics(m_GraphicsHandler);
}

GUIBase::~GUIBase()
{
	m_GUI->getTop()->clear();

	delete m_GraphicsHandler;
	delete m_GUI;
	delete m_InputHandler;
}

void GUIBase::AddWidget(agui::Widget* widget)
{
	m_GUI->add(widget);
}

void GUIBase::RemoveWidget(agui::Widget* widget)
{
	m_GUI->remove(widget);
}

void GUIBase::ProcessEvent(ALLEGRO_EVENT event)
{
	m_InputHandler->processEvent(event);
}

void GUIBase::Update()
{
	m_GUI->logic();
}

void GUIBase::Render()
{
	m_GUI->render();
}
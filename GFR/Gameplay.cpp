#include "Gameplay.h"
#include "Common.h"
#include "GFR_AL.h"
#include "ContentMgr.h"
#include "PhysicsComponent.h"
#include "DrawComponent.h"
#include "Runner.h"
#include "GameplayDebugGUI.h"
#include "EntityMgr.h"

using namespace game;
using namespace gameState;
using namespace framework;

Gameplay::Gameplay(characters::Class playerCharacter)
	: State(stateTypes::GAMEPLAY)
{
	m_Gui = new gui::GameplayDebugGUI(*this);
	m_Gui->InitializeGUIComponents();

	// PHYSICS
	m_PhysMgr.CreateWorld(0, 9.8f);

	CreateTestPlayer();
	CreateTestGround();
};

Gameplay::~Gameplay()
{
};

void Gameplay::Update()
{
	FOR_EACH(it, m_Entities)
	{
		m_ControlSystem.ProcessEntity(*it);
		m_MovementSystem.ProcessEntity(*it);
	}

	m_PhysMgr.Update(GFR_AL::GetUpdateRate());
	m_Camera.Update();
	State::Update();
};

void Gameplay::Render()
{
	FOR_EACH(it, m_Entities)
	{
		m_RenderSystem.ProcessEntity(*it);
	}
	State::Render();
};

void Gameplay::actionPerformed(const agui::ActionEvent &evt)
{
	gui::GameplayDebugGUI* gui = (gui::GameplayDebugGUI*) m_Gui;
	agui::Widget* source = evt.getSource();

	if (source == &gui->backToMenuButton)
	{
		GFR_AL::s_StateManager.SetState(stateTypes::MAIN_MENU);
	}
	else if (source == &gui->createEntityButton)
	{
		CreateTestPlayer();
	}
};

void Gameplay::CreateTestPlayer(void)
{
	Entity* testPlayer = EntityMgr::CreateNetworkEntity();
	testPlayer->AttachComponent("PhysicsComponent");
	testPlayer->AttachComponent("DrawComponent");
	testPlayer->AttachComponent("Runner");
	testPlayer->AttachComponent("Controller");
	
	b2PolygonShape runnerShape;
	runnerShape.SetAsBox(100, 100);

	b2FixtureDef runnerFD;
	runnerFD.shape = &runnerShape;
	runnerFD.density = 1.0f;
	runnerFD.restitution = 0.2f;

	b2BodyDef runnerBD;
	runnerBD.type = b2_dynamicBody;
	runnerBD.position.Set(0, 500.0f);

	b2Body* runnerBody = m_PhysMgr.GetWorld()->CreateBody(&runnerBD);
	runnerBody->CreateFixture(&runnerFD);

	static_cast<PhysicsComponent*>(testPlayer->GetComponent("PhysicsComponent"))->SetBody(
		runnerBody);
	static_cast<DrawComponent*>(testPlayer->GetComponent("DrawComponent"))->SetTexture(
		*ContentMgr::LoadContent<Texture>("test.png"));
	static_cast<characters::Runner*>(testPlayer->GetComponent("Runner"))->Initialize(
		"My Player", 100.0f, 1000000.0f, 1000000.0f);
	m_Entities.push_back(*testPlayer);
};

void Gameplay::CreateTestGround(void)
{
	Entity* testGround = EntityMgr::CreateLocalEntity();
	testGround->AttachComponent("PhysicsComponent");
	testGround->AttachComponent("DrawComponent");
	
	b2EdgeShape groundShape;
	b2Vec2 leftEdgeVec = b2Vec2(0, 0);
	b2Vec2 rightEdgeVec = b2Vec2(1000, 0);
	groundShape.Set(leftEdgeVec, rightEdgeVec);

	b2FixtureDef groundFD;
	groundFD.shape = &groundShape;
	groundFD.friction = 0.2f;

	b2BodyDef groundBD;
	groundBD.type = b2_staticBody;
	groundBD.position = b2Vec2(0, GFR_AL::GetScreenHeight() * 3 / 4);

	b2Body* groundBody = m_PhysMgr.GetWorld()->CreateBody(&groundBD);
	groundBody->CreateFixture(&groundFD);

	static_cast<PhysicsComponent*>(testGround->GetComponent("PhysicsComponent"))->SetBody(
		groundBody);
	static_cast<DrawComponent*>(testGround->GetComponent("DrawComponent"))->SetTexture(
		*ContentMgr::LoadContent<Texture>("test_ground.png"));
	m_Entities.push_back(*testGround);
};
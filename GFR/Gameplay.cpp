#include "Gameplay.h"
#include "Common.h"
#include "GFR_AL.h"
#include "ContentMgr.h"
#include "PhysicsComponent.h"
#include "DrawComponent.h"
#include "RunnerComponent.h"
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
	m_PhysMgr.GetWorld()->SetDebugDraw(this);
	SetFlags(b2Draw::e_shapeBit);
	
	ALLEGRO_TRANSFORM tx;
	al_identity_transform(&tx);
	al_scale_transform(&tx, 1.5f, 1.5f);
	al_use_transform(&tx);

	f32 padd = 0;
	f32 length = 1000;
	CreateTestBoundary(Vec2f(padd, padd), Vec2f(length, padd)); // topleft->topright
	CreateTestBoundary(Vec2f(length, padd), Vec2f(length, length)); // topright->bottomright
	CreateTestBoundary(Vec2f(length, length), Vec2f(padd, length)); // bottomright->bottomleft
	CreateTestBoundary(Vec2f(padd, length), Vec2f(padd, padd)); // bottomleft->topleft
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
	//m_Camera.Update();
	State::Update();
};

void Gameplay::Render()
{
	FOR_EACH(it, m_Entities)
	{
		m_RenderSystem.ProcessEntity(*it);
	}
	
	m_PhysMgr.GetWorld()->DrawDebugData();
	
	ALLEGRO_TRANSFORM tx, tx_orig;
	tx_orig = *al_get_current_transform();
	al_identity_transform(&tx);
	al_use_transform(&tx);

	State::Render();
	
	al_use_transform(&tx_orig);
};

void Gameplay::actionPerformed(const agui::ActionEvent &evt)
{
	gui::GameplayDebugGUI* gui = (gui::GameplayDebugGUI*) m_Gui;
	agui::Widget* source = evt.getSource();

	if (source == &gui->button_BackToMenu)
	{
		GFR_AL::s_StateManager.SetState(stateTypes::MAIN_MENU);
	}
	else if (source == &gui->button_CreateBox)
	{
		f32 x = gui->textField_CreateEntityPosX.parseFloat();
		f32 y = gui->textField_CreateEntityPosY.parseFloat();
		CreateTestBox(Vec2f(x, y));
	}
	else if (source == &gui->button_CreateEntity ||
		source == &gui->textField_CreateEntityPosX ||
		source == &gui->textField_CreateEntityPosY)
	{
		f32 x = gui->textField_CreateEntityPosX.parseFloat();
		f32 y = gui->textField_CreateEntityPosY.parseFloat();
		CreateTestPlayer(Vec2f(x, y));
	}
};

void Gameplay::CreateTestPlayer(Vec2f pos)
{
	Entity* testPlayer = EntityMgr::CreateNetworkEntity();
	testPlayer->AttachComponent("PhysicsComponent");
	testPlayer->AttachComponent("DrawComponent");
	testPlayer->AttachComponent("RunnerComponent");
	testPlayer->AttachComponent("ControllerComponent");
	
	b2PolygonShape runnerShape;
	runnerShape.SetAsBox(36, 75);

	b2FixtureDef runnerFD;
	runnerFD.shape = &runnerShape;
	runnerFD.density = 1.0f;
	runnerFD.restitution = 0.0f;

	b2BodyDef runnerBD;
	runnerBD.type = b2_dynamicBody;
	runnerBD.fixedRotation = true;
	runnerBD.position.Set(pos.x(), pos.y());

	b2Body* runnerBody = m_PhysMgr.GetWorld()->CreateBody(&runnerBD);
	runnerBody->CreateFixture(&runnerFD);

	static_cast<PhysicsComponent*>(testPlayer->GetComponent("PhysicsComponent"))->Initialize(
		runnerBody, 300.0f, 300.0f);
	
	static_cast<DrawComponent*>(testPlayer->GetComponent("DrawComponent"))->Initialize(
		ContentMgr::LoadContent<Texture>("test.png"));
	// Animation test
	static_cast<DrawComponent*>(testPlayer->GetComponent("DrawComponent"))->SetAnimation(
		new Animation(*ContentMgr::LoadContent<Texture>("engineerRun.png"), 8, 36, 75));
	// Animation test end.
	static_cast<characters::RunnerComponent*>(testPlayer->GetComponent("RunnerComponent"))->Initialize("My Player", 100.0f);
	m_Entities.push_back(*testPlayer);
};

void Gameplay::CreateTestBoundary(Vec2f startPos, Vec2f endPos)
{
	Entity* testGround = EntityMgr::CreateLocalEntity();
	testGround->AttachComponent("PhysicsComponent");
	testGround->AttachComponent("DrawComponent");
	
	b2PolygonShape groundShape;
	f32 width = startPos.x() - endPos.x();
	//width = width < 0 ? width * -1: width;
	f32 height = 5;
	// abs value
	b2Vec2 center(width / 2, height / 2);
	groundShape.SetAsBox(width / 2, height / 2, center, 0);

	b2FixtureDef groundFD;
	groundFD.shape = &groundShape;
	groundFD.friction = 0.0f;

	b2BodyDef groundBD;
	groundBD.type = b2_staticBody;
	groundBD.position.Set(startPos.x(), startPos.y());

	b2Body* groundBody = m_PhysMgr.GetWorld()->CreateBody(&groundBD);
	groundBody->CreateFixture(&groundFD);

	static_cast<PhysicsComponent*>(testGround->GetComponent("PhysicsComponent"))->SetBody(
		groundBody);
	static_cast<DrawComponent*>(testGround->GetComponent("DrawComponent"))->Initialize(
		ContentMgr::LoadContent<Texture>("test_ground.png"));
	m_Entities.push_back(*testGround);
};

void Gameplay::CreateTestBox(Vec2f pos)
{
	Entity* testBox = EntityMgr::CreateLocalEntity();
	testBox->AttachComponent("PhysicsComponent");
	testBox->AttachComponent("DrawComponent");
	
	b2PolygonShape boxShape;
	boxShape.SetAsBox(16, 16, b2Vec2(16, 16), 0);

	b2FixtureDef boxFD;
	boxFD.shape = &boxShape;
	boxFD.density = 1.0f;
	boxFD.restitution = 0.2f;

	b2BodyDef boxBD;
	boxBD.type = b2_dynamicBody;
	boxBD.position.Set(pos.x(), pos.y());

	b2Body* boxBody = m_PhysMgr.GetWorld()->CreateBody(&boxBD);
	boxBody->CreateFixture(&boxFD);

	static_cast<PhysicsComponent*>(testBox->GetComponent("PhysicsComponent"))->Initialize(
		boxBody, 1000000.0f, 1000000.0f);
	static_cast<DrawComponent*>(testBox->GetComponent("DrawComponent"))->Initialize(
		ContentMgr::LoadContent<Texture>("test_crate.png"));
	m_Entities.push_back(*testBox);
};

void Gameplay::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{};

void Gameplay::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	//al_draw_rectangle(vertices[0].x, vertices[0].y, vertices[2].x, vertices[2].y, al_map_rgb(255, 0, 255), 1.0f);

	for (int i = 0; i < vertexCount; ++i)
	{
		al_draw_line(vertices[i].x, vertices[i].y, vertices[(i+1) % vertexCount].x, vertices[(i+1) % vertexCount].y,
			al_map_rgb(255, 0, 255), 1.0f);
	}
};

void Gameplay::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color)
{};

void Gameplay::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color)
{};

void Gameplay::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
{};

void Gameplay::DrawTransform(const b2Transform& xf)
{};

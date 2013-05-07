#include "Gameplay.h"
#include "Common.h"
#include "GFR_AL.h"
#include "ContentMgr.h"
#include "PhysicsComponent.h"
#include "DrawComponent.h"
#include "Runner.h"

using namespace game;
using namespace gameState;
using namespace framework;

Gameplay::Gameplay(characters::Class playerCharacter)
	: State(stateTypes::GAMEPLAY)
{
	m_Gui = NULL;

	m_Camera = Camera();

	m_PhysMgr.CreateWorld(0, 9.8f, true);

	Entity* testPlayer = new Entity();
	testPlayer->AttachComponent("PhysicsComponent");
	testPlayer->AttachComponent("DrawComponent");
	testPlayer->AttachComponent("Runner");
	testPlayer->AttachComponent("RunnerController");

	static_cast<PhysicsComponent*>(testPlayer->GetComponent("PhysicsComponent"))->SetBody(
		m_PhysMgr.CreateDynamicBody(0, 500.0f, 0, 0, 0, 0, true, true, true));
	static_cast<DrawComponent*>(testPlayer->GetComponent("DrawComponent"))->SetTexture(
		*ContentMgr::LoadContent<Texture>("test.png"));

	static_cast<characters::Runner*>(testPlayer->GetComponent("Runner"))->Initialize("My Player", 100.0f, 50.0f, 50.0f);

	m_Entities.push_back(*testPlayer);
}

Gameplay::~Gameplay()
{

}

void Gameplay::Update()
{
	FOR_EACH(it, m_Entities)
	{
		m_ControlSystem.ProcessEntity(*it);
	}

	m_PhysMgr.Update(GFR_AL::GetUpdateRate());
	m_Camera.Update();
}

void Gameplay::Render()
{
	FOR_EACH(it, m_Entities)
	{
		m_MovementSystem.ProcessEntity(*it);
	}
}
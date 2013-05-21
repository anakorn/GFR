#include "ControlSystem.h"
#include "ComponentMask.h"
#include "Entity.h"

#include "PhysicsComponent.h"
#include "Runner.h"
#include "InputMgr.h"
//#include "InputComponent.h"

using namespace framework;

game::characters::Runner* m_Pawn;
PhysicsComponent* m_PhysComp;

b2Vec2 m_InputDirection;

ControlSystem::ControlSystem()
	: System( /*MASK_STATE |*/ MASK_RUNNERCONTROLLER )
{
	// Eventually want to get controls from configuration.
	// Hard coded for now
	InputMgr::RegisterKeyDownFunction(ALLEGRO_KEY_A, std::bind(&ControlSystem::ChangeHorizontalDirection, this, -1.0f));
	InputMgr::RegisterKeyDownFunction(ALLEGRO_KEY_D, std::bind(&ControlSystem::ChangeHorizontalDirection, this, 1.0f));
	InputMgr::RegisterKeyDownFunction(ALLEGRO_KEY_W, std::bind(&ControlSystem::ChangeVerticalDirection, this, 1.0f));

	InputMgr::RegisterKeyDownFunction(ALLEGRO_KEY_1, std::bind(&ControlSystem::CastAbility, this, 0));
	InputMgr::RegisterKeyDownFunction(ALLEGRO_KEY_2, std::bind(&ControlSystem::CastAbility, this, 1));

	InputMgr::RegisterKeyUpFunction(ALLEGRO_KEY_A, std::bind(&ControlSystem::ChangeHorizontalDirection, this, 1.0f));
	InputMgr::RegisterKeyUpFunction(ALLEGRO_KEY_D, std::bind(&ControlSystem::ChangeHorizontalDirection, this, -1.0f));
}

ControlSystem::~ControlSystem()
{
	m_Pawn = NULL;
	m_PhysComp = NULL;
};

void ControlSystem::ProcessEntityImpl(Entity& entity)
{
	if (!m_Pawn)
		m_Pawn = static_cast<game::characters::Runner*>(entity.GetComponent("Runner"));
	if (!m_PhysComp)
		m_PhysComp = static_cast<PhysicsComponent*>(entity.GetComponent("PhysicsComponent"));

	// Change y later when isJumping can be determined
	b2Vec2 force(m_InputDirection.x * m_Pawn->GetCurrentMovementSpeed(), -m_InputDirection.y * m_Pawn->GetCurrentJumpSpeed());
	
	m_PhysComp->ApplyImpulse(force);
}

void ControlSystem::ChangeHorizontalDirection(const f32 &amount)
{
	m_InputDirection.x += amount;

	if (m_InputDirection.x > 1.0f)
		m_InputDirection.x = 1.0f;
	else if (m_InputDirection.x < -1.0f)
		m_InputDirection.x = -1.0f;
}

void ControlSystem::ChangeVerticalDirection(const f32 &amount)
{
	m_InputDirection.y += amount;

	if (m_InputDirection.y > 1.0f)
		m_InputDirection.y = 1.0f;
	else if (m_InputDirection.y < -1.0f)
		m_InputDirection.y = -1.0f;
}

void ControlSystem::CastAbility(u32 index)
{

}
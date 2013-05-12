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

ControlSystem::ControlSystem()
	: System( /*MASK_STATE |*/ MASK_RUNNERCONTROLLER )
{
	// Eventually want to get controls from configuration
	// Hard coded for now
	InputMgr::RegisterKeyDownFunction(ALLEGRO_KEY_A, std::bind(&framework::ControlSystem::MoveLeft, this));
	InputMgr::RegisterKeyDownFunction(ALLEGRO_KEY_D, std::bind(&framework::ControlSystem::MoveRight, this));
	InputMgr::RegisterKeyDownFunction(ALLEGRO_KEY_W, std::bind(&framework::ControlSystem::Jump, this));
}

void ControlSystem::ProcessEntity(Entity& entity)
{
	m_PhysComp = static_cast<PhysicsComponent*>(entity.GetComponent("PhysicsComponent"));
	//InputComponent* inputComp = static_cast<InputComponent*>(entity.GetComponent("InputComponent"));

	// Very inefficient and unnecessary but a workaround to get this to work with event-driven input
	m_Pawn = static_cast<game::characters::Runner*>(entity.GetComponent("Runner"));
}

void ControlSystem::MoveLeft()
{
	m_PhysComp->SetLinearVelocity(-m_Pawn->GetCurrentMovementSpeed(), m_PhysComp->GetLinearVelocity().y);
}

void ControlSystem::MoveRight()
{
	m_PhysComp->SetLinearVelocity(m_Pawn->GetCurrentMovementSpeed(), m_PhysComp->GetLinearVelocity().y);
}

void ControlSystem::Jump()
{
	m_PhysComp->SetLinearVelocity(m_PhysComp->GetLinearVelocity().x, -m_Pawn->GetCurrentJumpSpeed());
}

void ControlSystem::CastAbility(u32 index)
{

}
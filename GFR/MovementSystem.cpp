#include "MovementSystem.h"
#include "ComponentMask.h"
#include "Entity.h"
#include "GFR_AL.h"

#include "PhysicsComponent.h"
#include "DrawComponent.h"

using namespace framework;

MovementSystem::MovementSystem()
	: System( MASK_PHYSICS | MASK_DRAW )
{ }

void MovementSystem::ProcessEntityImpl(Entity& entity)
{
	PhysicsComponent* physComp = static_cast<PhysicsComponent*>(entity.GetComponent("PhysicsComponent"));
	DrawComponent* drawComp = static_cast<DrawComponent*>(entity.GetComponent("DrawComponent"));
	
	drawComp->SetPosition(physComp->GetPosition());
	drawComp->SetRotation(physComp->GetRotation());
};
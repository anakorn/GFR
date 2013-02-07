#include "MovementSystem.h"
#include "ComponentMask.h"
#include "Entity.h"

#include "PhysicsComponent.h"
#include "DrawComponent.h"

using namespace framework;

MovementSystem::MovementSystem()
	: System( MASK_PHYSICS | MASK_DRAW )
{ }

void MovementSystem::ProcessEntity(Entity& entity)
{
	PhysicsComponent* physComp = static_cast<PhysicsComponent*>(entity.GetComponent("PhysicsComponent"));
	DrawComponent* drawComp = static_cast<DrawComponent*>(entity.GetComponent("DrawComponent"));

	
}
#include "MovementSystem.h"
#include "ComponentMask.h"
#include "Entity.h"

#include "PhysicsComponent.h"
#include "DrawComponent.h"

#include "Box2D\Box2D.h"

using namespace framework;

MovementSystem::MovementSystem()
	: System( MASK_PHYSICS_COMPONENT | MASK_DRAW_COMPONENT )
{ }

void MovementSystem::ProcessEntity(Entity& entity)
{
	PhysicsComponent* physComp = static_cast<PhysicsComponent*>(entity.GetComponent("PhysicsComponent"));
	DrawComponent* drawComp = static_cast<DrawComponent*>(entity.GetComponent("DrawComponent"));
}
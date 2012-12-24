#include "SystemDerived.h"
#include "ComponentDerived.h"
#include "ComponentMask.h"
#include "Entity.h"

using namespace framework;

MovementSystem::MovementSystem()
	: System(MASK_PHYSICS_COMPONENT | MASK_DRAW_COMPONENT)
{ }

void MovementSystem::ProcessEntity(Entity& entity)
{
	PhysicsComponent* physComp = dynamic_cast<PhysicsComponent*>(entity.GetComponent("PhysicsComponent"));
	DrawComponent* drawComp = dynamic_cast<DrawComponent*>(entity.GetComponent("DrawComponent"));
}
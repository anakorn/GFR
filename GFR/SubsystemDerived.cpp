#include "SubsystemDerived.h"
#include "ComponentDerived.h"
#include "ComponentMasks.h"
#include "Entity.h"

using namespace framework;

MovementSubsystem::MovementSubsystem()
	: Subsystem(MASK_PHYSICS_COMPONENT | MASK_DRAW_COMPONENT)
{ }

void MovementSubsystem::ProcessEntity(Entity& entity)
{
	PhysicsComponent* physComp = dynamic_cast<PhysicsComponent*>(entity.GetComponent("PhysicsComponent"));
	DrawComponent* drawComp = dynamic_cast<DrawComponent*>(entity.GetComponent("DrawComponent"));
}
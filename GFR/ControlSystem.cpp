#include "ControlSystem.h"
#include "ComponentMask.h"
#include "Entity.h"

#include "PhysicsComponent.h"
//#include "InputComponent.h"

#include "Box2D\Box2D.h"

using namespace framework;

ControlSystem::ControlSystem()
	: System( MASK_PHYSICS_COMPONENT | MASK_INPUT_COMPONENT )
{ }

void ControlSystem::ProcessEntity(Entity& entity)
{
	PhysicsComponent* physComp = static_cast<PhysicsComponent*>(entity.GetComponent("PhysicsComponent"));
	//InputComponent* inputComp = static_cast<InputComponent*>(entity.GetComponent("InputComponent"));
}
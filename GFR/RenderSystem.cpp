#include "RenderSystem.h"
#include "ComponentMask.h"
#include "Entity.h"
#include "GFR_AL.h"

#include "DrawComponent.h"

using namespace framework;

RenderSystem::RenderSystem()
	: System( MASK_DRAW )
{ }

void RenderSystem::ProcessEntityImpl(Entity& entity)
{
	DrawComponent* drawComp = static_cast<DrawComponent*>(entity.GetComponent("DrawComponent"));

	GFR_AL::DrawTexture(drawComp->GetTexture().GetBitmap(), drawComp->GetPosition());
};
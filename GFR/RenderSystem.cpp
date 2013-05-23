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

	if (drawComp->IsVisible())
	{
		Animation* animation = drawComp->GetAnimation();

		if (animation == nullptr)
		{
			GFR_AL::DrawTexture(drawComp->GetTexture(), drawComp->GetPosition());
		}
		else
		{
			if (++animation->frameCount >= animation->frameDelay)
			{
				if (++animation->curFrame >= animation->numOfFrames)
					animation->curFrame = 0;

				animation->frameCount = 0;
			}
			
			GFR_AL::DrawTextureRegion(animation->texture, drawComp->GetPosition(),
				animation->curFrame * animation->frameWidth, 0, animation->frameWidth, animation->frameHeight);
		}
		
	}
};
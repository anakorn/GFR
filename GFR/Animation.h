#ifndef GFR_FRAMEWORK_TYPES_ANIMATION_H
#define GFR_FRAMEWORK_TYPES_ANIMATION_H

#include "Common.h"
#include "Texture.h"

namespace framework
{
	class Animation
	{
	public:
		Animation			(Texture& texture, u8 numOfFrames, u32 frameWidth, u32 frameHeight);
		~Animation			();
		
		Texture& texture;
		u8 curFrame;
		u8 frameCount;	// Tracks the number of updates until frame change.
		const u8 numOfFrames;
		const u8 frameDelay;
		const u32 frameWidth;
		const u32 frameHeight;

	};
};

#endif
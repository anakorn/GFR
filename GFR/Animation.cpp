#include "Animation.h"

using namespace framework;

Animation::Animation(Texture& texture, u8 numOfFrames, u32 frameWidth, u32 frameHeight)
	: texture(texture), numOfFrames(numOfFrames), frameDelay(5), frameWidth(frameWidth), frameHeight(frameHeight), curFrame(0), frameCount(0)
{};

Animation::~Animation()
{};
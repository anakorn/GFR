#include "Sound.h"
#include "GFRAL_Content.h"
#include "ContentLoadException.h"

using namespace framework;

Sound::Sound(ALLEGRO_SAMPLE* sample)
	: m_Sample(sample)
{
};

Sound::~Sound()
{
	GFRAL_Content::DestroySample(m_Sample);
};
#include "Sound.h"
#include "GFR_AL.h"
#include "ContentLoadException.h"

using namespace framework;

Sound::Sound(ALLEGRO_SAMPLE* sample)
	: m_Sample(sample)
{
};

Sound::~Sound()
{
	GFR_AL::DestroySample(m_Sample);
};
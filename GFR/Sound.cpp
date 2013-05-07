#include "Sound.h"
#include "GFRAL_ContentMgr.h"
#include "ContentLoadException.h"

using namespace framework;

Sound::Sound(ALLEGRO_SAMPLE* sample)
	: m_Sample(sample)
{
};

Sound::~Sound()
{
	GFRAL_ContentMgr::DestroySample(m_Sample);
};
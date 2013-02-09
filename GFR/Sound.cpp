#include "Sound.h"
#include "ContentLoadException.h"

Sound::Sound(const char* fileName)
	: sound(al_load_sample(fileName))
{
	if (sound == NULL)
	{
		throw ContentLoadException(fileName);
	}
}

Sound::~Sound()
{
	al_destroy_sample(sound);
}